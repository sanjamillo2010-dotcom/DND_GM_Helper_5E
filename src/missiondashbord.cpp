#include "../include/missiondashbord.h"
#include "../include/npcwindow.h"
#include "../include/npc.h"
#include "../include/npccreatordialog.h"
#include "ui_missiondashbord.h"

#include <QAction>
#include <QCheckBox>
#include <QComboBox>
#include <QDateEdit>
#include <QDateTimeEdit>
#include <QDialog>
#include <QDoubleSpinBox>
#include <QGraphicsItem>
#include <QGraphicsProxyWidget>
#include <QGraphicsScene>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QLabel>
#include <QLineEdit>
#include <QMenu>
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QPushButton>
#include <QSpinBox>
#include <QTextEdit>
#include <QTimeEdit>
#include <QToolButton>
#include <QVBoxLayout>
#include <QUuid>

MissionDashbord::MissionDashbord(Campaign* campaign, int missionIndex, QWidget* parent)
    : QMainWindow(parent), ui(new Ui::MissionDashbord), m_campaign(campaign), m_missionIndex(missionIndex),
    m_scene(new QGraphicsScene(this)), m_addNPCAction(nullptr), m_addMapAction(nullptr),
    m_addBattleAction(nullptr), m_addNoteAction(nullptr)
{
    ui->setupUi(this);

    ui->workspaceView->setScene(m_scene);
    m_scene->setSceneRect(-5000, -5000, 10000, 10000);

    QMenu* addMenu = new QMenu(this);
    m_addNPCAction = addMenu->addAction("NPC");
    m_addMapAction = addMenu->addAction("Map");
    m_addBattleAction = addMenu->addAction("Battle");
    m_addNoteAction = addMenu->addAction("Note");

    ui->addObjectButton->setMenu(addMenu);
    ui->addObjectButton->setPopupMode(QToolButton::InstantPopup);

    connect(m_addNPCAction, &QAction::triggered, this, &MissionDashbord::Add_NPC);
    connect(m_addMapAction, &QAction::triggered, this, &MissionDashbord::Add_Map);

    connect(ui->saveMissionButton, &QPushButton::clicked, this, &MissionDashbord::Save_Mission);
    connect(ui->backButton, &QPushButton::clicked, this, &MissionDashbord::Close_Mission);

    Load_Mission();
}

MissionDashbord::~MissionDashbord()
{
    delete ui;
}

void MissionDashbord::Set_Mission_Index(int index)
{
    if (m_campaign == nullptr)
        return;

    if (index < 0 || index >= m_campaign->missions().Get_Mission_Count())
        return;

    Save_Workspace_To_Mission();
    m_missionIndex = index;
    Load_Mission();
}

void MissionDashbord::Add_NPC()
{
    if (m_scene == nullptr)
        return;

    NPCCreatorDialog dialog(this);
    if (dialog.exec() != QDialog::Accepted)
        return;

    const DND_GM_Helper_5E::NPC::NPC npcData = dialog.Get_NPC();

    const QPointF center = ui->workspaceView->mapToScene(
        ui->workspaceView->viewport()->rect().center()
        );

    NPCWindow* npcWindow = new NPCWindow(npcData);

    npcWindow->setProperty("workspaceType", "NPC");
    npcWindow->setProperty("workspaceTitle", npcData.Prenom + " " + npcData.Nom);
    npcWindow->setProperty("workspaceId",
                           QUuid::createUuid().toString(QUuid::WithoutBraces));

    QGraphicsProxyWidget* proxy = m_scene->addWidget(npcWindow);
    proxy->setFlag(QGraphicsItem::ItemIsMovable, true);
    proxy->setFlag(QGraphicsItem::ItemIsSelectable, true);
    proxy->setPos(center);
}

void MissionDashbord::Add_Map()
{
    const QPointF center = ui->workspaceView->mapToScene(
        ui->workspaceView->viewport()->rect().center()
        );

    Create_Workspace_Object("Map", "Map", "Map notes", center);
}

QGraphicsProxyWidget* MissionDashbord::Create_NPC_Widget(
    const QPointF& position,
    const Missions::WorkspaceObject* savedObject)
{
    DND_GM_Helper_5E::NPC::NPC npcData("", "", "", "", "", 0, "", "", 0, "", "", 0, "", "", 0);
    NPCWindow* npcWindow = new NPCWindow(npcData);

    if (savedObject != nullptr)
    {
        const QJsonObject& state = savedObject->WidgetState;

        if (state.contains("npc") && state["npc"].isObject())
            npcWindow->From_Json(state["npc"].toObject());
    }

    npcWindow->setProperty("workspaceType", "NPC");
    npcWindow->setProperty("workspaceTitle",
                           npcWindow->Get_NPC().Prenom + " " + npcWindow->Get_NPC().Nom);

    if (savedObject != nullptr && !savedObject->Id.isEmpty())
        npcWindow->setProperty("workspaceId", savedObject->Id);
    else
        npcWindow->setProperty("workspaceId",
                               QUuid::createUuid().toString(QUuid::WithoutBraces));

    QGraphicsProxyWidget* proxy = m_scene->addWidget(npcWindow);
    proxy->setFlag(QGraphicsItem::ItemIsMovable, true);
    proxy->setFlag(QGraphicsItem::ItemIsSelectable, true);
    proxy->setPos(position);

    if (savedObject != nullptr)
    {
        if (savedObject->Width > 0 && savedObject->Height > 0)
            npcWindow->resize(savedObject->Width, savedObject->Height);

        proxy->setZValue(savedObject->Z);
    }

    return proxy;
}

QGraphicsProxyWidget* Create_Map_Widget(
    const QPointF& position,
    const Missions::WorkspaceObject*
    savedObject = nullptr)
{
    //Add the Create Map Widget code !
}

QGraphicsProxyWidget* MissionDashbord::Create_Workspace_Object(
    const QString& type,
    const QString& title,
    const QString& text,
    const QPointF& position,
    const Missions::WorkspaceObject* savedObject)
{
    QWidget* objectWidget = new QWidget();
    objectWidget->setMinimumSize(220, 140);
    objectWidget->setProperty("workspaceType", type);
    objectWidget->setProperty("workspaceTitle", title);

    if (savedObject != nullptr && !savedObject->Id.isEmpty())
        objectWidget->setProperty("workspaceId", savedObject->Id);
    else
        objectWidget->setProperty("workspaceId",
                                  QUuid::createUuid().toString(QUuid::WithoutBraces));

    QVBoxLayout* layout = new QVBoxLayout(objectWidget);

    QLabel* titleLabel = new QLabel(title);
    titleLabel->setObjectName("titleLabel");
    titleLabel->setStyleSheet("font-weight: bold; font-size: 16px;");

    QTextEdit* editor = new QTextEdit();
    editor->setObjectName("mainEditor");
    editor->setPlainText(text);

    QPushButton* deleteButton = new QPushButton("Delete");
    deleteButton->setObjectName("deleteButton");

    layout->addWidget(titleLabel);
    layout->addWidget(editor);
    layout->addWidget(deleteButton);

    QGraphicsProxyWidget* proxy = m_scene->addWidget(objectWidget);
    proxy->setFlag(QGraphicsItem::ItemIsMovable, true);
    proxy->setFlag(QGraphicsItem::ItemIsSelectable, true);
    proxy->setPos(position);

    connect(deleteButton, &QPushButton::clicked, this, [this, proxy]()
            {
                if (m_scene != nullptr)
                    m_scene->removeItem(proxy);

                delete proxy;
            });

    if (savedObject != nullptr)
    {
        if (savedObject->Width > 0 && savedObject->Height > 0)
            objectWidget->resize(savedObject->Width, savedObject->Height);

        proxy->setZValue(savedObject->Z);
        editor->setPlainText(savedObject->Text);
    }

    return proxy;
}

void MissionDashbord::Ensure_Widget_Names(QWidget* widget) const
{
    if (widget == nullptr)
        return;

    int index = 0;
    const QList<QObject*> children = widget->children();

    for (QObject* childObject : children)
    {
        QWidget* child = qobject_cast<QWidget*>(childObject);
        if (child == nullptr)
            continue;

        if (child->objectName().isEmpty())
        {
            child->setObjectName(
                QString("%1_%2_%3")
                    .arg(widget->objectName())
                    .arg(child->metaObject()->className())
                    .arg(index)
                );
        }

        ++index;
        Ensure_Widget_Names(child);
    }
}

QJsonObject MissionDashbord::Save_Widget_State(QWidget* widget) const
{
    QJsonObject result;

    if (widget == nullptr)
        return result;

    Ensure_Widget_Names(widget);

    QJsonArray widgets;
    const QList<QWidget*> children = widget->findChildren<QWidget*>();

    for (QWidget* child : children)
    {
        if (child == nullptr)
            continue;

        const QString objectName = child->objectName();
        if (objectName.isEmpty())
            continue;

        QJsonObject item;
        item["object_name"] = objectName;

        if (auto* lineEdit = qobject_cast<QLineEdit*>(child))
        {
            item["type"] = "QLineEdit";
            item["text"] = lineEdit->text();
        }
        else if (auto* textEdit = qobject_cast<QTextEdit*>(child))
        {
            item["type"] = "QTextEdit";
            item["text"] = textEdit->toPlainText();
        }
        else if (auto* plainTextEdit = qobject_cast<QPlainTextEdit*>(child))
        {
            item["type"] = "QPlainTextEdit";
            item["text"] = plainTextEdit->toPlainText();
        }
        else if (auto* comboBox = qobject_cast<QComboBox*>(child))
        {
            item["type"] = "QComboBox";
            item["index"] = comboBox->currentIndex();
            item["text"] = comboBox->currentText();
        }
        else if (auto* spinBox = qobject_cast<QSpinBox*>(child))
        {
            item["type"] = "QSpinBox";
            item["value"] = spinBox->value();
        }
        else if (auto* doubleSpinBox = qobject_cast<QDoubleSpinBox*>(child))
        {
            item["type"] = "QDoubleSpinBox";
            item["value"] = doubleSpinBox->value();
        }
        else if (auto* checkBox = qobject_cast<QCheckBox*>(child))
        {
            item["type"] = "QCheckBox";
            item["checked"] = checkBox->isChecked();
        }
        else if (auto* dateEdit = qobject_cast<QDateEdit*>(child))
        {
            item["type"] = "QDateEdit";
            item["value"] = dateEdit->date().toString(Qt::ISODate);
        }
        else if (auto* timeEdit = qobject_cast<QTimeEdit*>(child))
        {
            item["type"] = "QTimeEdit";
            item["value"] = timeEdit->time().toString(Qt::ISODate);
        }
        else if (auto* dateTimeEdit = qobject_cast<QDateTimeEdit*>(child))
        {
            item["type"] = "QDateTimeEdit";
            item["value"] = dateTimeEdit->dateTime().toString(Qt::ISODate);
        }
        else if (auto* label = qobject_cast<QLabel*>(child))
        {
            item["type"] = "QLabel";
            item["text"] = label->text();
        }
        else
        {
            continue;
        }

        widgets.append(item);
    }

    result["widgets"] = widgets;
    return result;
}

void MissionDashbord::Restore_Widget_State(QWidget* widget, const QJsonObject& state)
{
    if (widget == nullptr)
        return;

    if (!state.contains("widgets") || !state["widgets"].isArray())
        return;

    Ensure_Widget_Names(widget);

    const QJsonArray widgets = state["widgets"].toArray();

    for (const QJsonValue& value : widgets)
    {
        if (!value.isObject())
            continue;

        const QJsonObject item = value.toObject();
        const QString objectName = item["object_name"].toString();

        if (objectName.isEmpty())
            continue;

        QWidget* child = widget->findChild<QWidget*>(objectName);
        if (child == nullptr)
            continue;

        const QString type = item["type"].toString();

        if (type == "QLineEdit")
        {
            if (auto* lineEdit = qobject_cast<QLineEdit*>(child))
                lineEdit->setText(item["text"].toString());
        }
        else if (type == "QTextEdit")
        {
            if (auto* textEdit = qobject_cast<QTextEdit*>(child))
                textEdit->setPlainText(item["text"].toString());
        }
        else if (type == "QPlainTextEdit")
        {
            if (auto* plainTextEdit = qobject_cast<QPlainTextEdit*>(child))
                plainTextEdit->setPlainText(item["text"].toString());
        }
        else if (type == "QComboBox")
        {
            if (auto* comboBox = qobject_cast<QComboBox*>(child))
                comboBox->setCurrentIndex(item["index"].toInt());
        }
        else if (type == "QSpinBox")
        {
            if (auto* spinBox = qobject_cast<QSpinBox*>(child))
                spinBox->setValue(item["value"].toInt());
        }
        else if (type == "QDoubleSpinBox")
        {
            if (auto* doubleSpinBox = qobject_cast<QDoubleSpinBox*>(child))
                doubleSpinBox->setValue(item["value"].toDouble());
        }
        else if (type == "QCheckBox")
        {
            if (auto* checkBox = qobject_cast<QCheckBox*>(child))
                checkBox->setChecked(item["checked"].toBool());
        }
        else if (type == "QDateEdit")
        {
            if (auto* dateEdit = qobject_cast<QDateEdit*>(child))
            {
                dateEdit->setDate(
                    QDate::fromString(item["value"].toString(), Qt::ISODate)
                    );
            }
        }
        else if (type == "QTimeEdit")
        {
            if (auto* timeEdit = qobject_cast<QTimeEdit*>(child))
            {
                timeEdit->setTime(
                    QTime::fromString(item["value"].toString(), Qt::ISODate)
                    );
            }
        }
        else if (type == "QDateTimeEdit")
        {
            if (auto* dateTimeEdit = qobject_cast<QDateTimeEdit*>(child))
            {
                dateTimeEdit->setDateTime(
                    QDateTime::fromString(item["value"].toString(), Qt::ISODate)
                    );
            }
        }
        else if (type == "QLabel")
        {
            if (auto* label = qobject_cast<QLabel*>(child))
                label->setText(item["text"].toString());
        }
    }
}

Missions::DashboardInfo MissionDashbord::Capture_Dashboard() const
{
    Missions::DashboardInfo dashboard;

    if (ui == nullptr || ui->workspaceView == nullptr || m_scene == nullptr)
        return dashboard;

    dashboard.Zoom = ui->workspaceView->transform().m11();
    if (dashboard.Zoom <= 0.0)
        dashboard.Zoom = 1.0;

    const QPoint viewportCenter = ui->workspaceView->viewport()->rect().center();
    const QPointF sceneCenter = ui->workspaceView->mapToScene(viewportCenter);

    dashboard.CenterX = sceneCenter.x();
    dashboard.CenterY = sceneCenter.y();

    const QList<QGraphicsItem*> items = m_scene->items();

    for (QGraphicsItem* item : items)
    {
        QGraphicsProxyWidget* proxy = qgraphicsitem_cast<QGraphicsProxyWidget*>(item);
        if (proxy == nullptr)
            continue;

        QWidget* widget = proxy->widget();
        if (widget == nullptr)
            continue;

        const QString type = widget->property("workspaceType").toString();
        if (type.isEmpty())
            continue;

        Missions::WorkspaceObject object;

        object.Id = widget->property("workspaceId").toString();
        if (object.Id.isEmpty())
        {
            object.Id = QUuid::createUuid().toString(QUuid::WithoutBraces);
            widget->setProperty("workspaceId", object.Id);
        }

        object.Type = type;
        object.Title = widget->property("workspaceTitle").toString();
        object.X = proxy->pos().x();
        object.Y = proxy->pos().y();
        object.Width = widget->width();
        object.Height = widget->height();
        object.Z = proxy->zValue();

        if (type == "NPC")
        {
            NPCWindow* npcWindow = qobject_cast<NPCWindow*>(widget);

            if (npcWindow != nullptr)
            {
                object.WidgetState = QJsonObject();
                object.WidgetState["npc"] = npcWindow->To_Json();
            }
        }
        else
        {
            QTextEdit* editor = widget->findChild<QTextEdit*>("mainEditor");

            if (editor != nullptr)
                object.Text = editor->toPlainText();
        }

        dashboard.Objects.append(object);
    }

    return dashboard;
}

void MissionDashbord::Save_Workspace_To_Mission()
{
    if (m_campaign == nullptr)
        return;

    if (m_missionIndex < 0 || m_missionIndex >= m_campaign->missions().Get_Mission_Count())
        return;

    const Missions::DashboardInfo dashboard = Capture_Dashboard();

    m_campaign->missions().Set_Mission_Dashboard(m_missionIndex, dashboard);
}

void MissionDashbord::Save_Mission()
{
    if (m_campaign == nullptr)
        return;

    Save_Workspace_To_Mission();

    if (m_campaign->File_Path.isEmpty())
    {
        QMessageBox::warning(
            this,
            "Save Mission",
            "There is no campaign file associated "
            "with this campaign."
            );
        return;
    }

    if (!m_campaign->Save_To_File(m_campaign->File_Path))
    {
        QMessageBox::critical(
            this,
            "Save Mission",
            "Could not save the campaign file:\n\n" +
                m_campaign->File_Path
            );
        return;
    }
}

void MissionDashbord::Load_Mission()
{
    if (m_campaign == nullptr)
        return;

    if (m_missionIndex < 0 || m_missionIndex >= m_campaign->missions().Get_Mission_Count())
        return;

    const Missions::Entry mission = m_campaign->missions().Get_Mission(m_missionIndex);

    ui->missionTitleLabel->setText(mission.Name);
    ui->missionDescriptionLabel->setText(mission.Description);

    if (m_scene != nullptr)
        m_scene->clear();

    for (const Missions::WorkspaceObject& object : mission.Dashboard.Objects)
    {
        const QPointF position(object.X, object.Y);

        if (object.Type == "NPC")
            Create_NPC_Widget(position, &object);
        else
            Create_Workspace_Object(object.Type, object.Title, object.Text, position, &object);
    }

    qreal zoom = mission.Dashboard.Zoom;
    if (zoom <= 0.0)
        zoom = 1.0;

    ui->workspaceView->resetTransform();
    ui->workspaceView->scale(zoom, zoom);
    ui->workspaceView->centerOn(
        QPointF(mission.Dashboard.CenterX, mission.Dashboard.CenterY)
        );
}

void MissionDashbord::Close_Mission()
{
    Save_Mission();
    close();
}
