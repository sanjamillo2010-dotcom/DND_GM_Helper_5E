#include "../include/npcwindow.h"

#include <QFormLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QJsonObject>
#include <QSignalBlocker>
#include <QSizePolicy>
#include <QVBoxLayout>


NPCWindow::NPCWindow(
    const DND_GM_Helper_5E::NPC::NPC& npc,
    QWidget* parent
    )
    : QWidget(parent)
    , npc(npc)
{
    setWindowFlags(
        Qt::FramelessWindowHint
        );

    setAttribute(
        Qt::WA_DeleteOnClose
        );

    setMinimumWidth(320);
    setMaximumWidth(420);

    setStyleSheet(
        "QWidget {"
        "    background-color: #252525;"
        "    color: white;"
        "}"

        "QLabel {"
        "    color: white;"
        "}"

        "QGroupBox {"
        "    color: white;"
        "    border: 1px solid #444;"
        "    border-radius: 4px;"
        "    margin-top: 8px;"
        "    padding-top: 6px;"
        "}"

        "QGroupBox::title {"
        "    subcontrol-origin: margin;"
        "    left: 8px;"
        "    padding: 0 4px;"
        "}"

        "QLineEdit {"
        "    background-color: #333333;"
        "    color: white;"
        "    border: 1px solid #4a4a4a;"
        "    border-radius: 3px;"
        "    padding: 3px;"
        "    min-height: 20px;"
        "}"

        "QTextEdit {"
        "    background-color: #333333;"
        "    color: white;"
        "    border: 1px solid #4a4a4a;"
        "    border-radius: 3px;"
        "    padding: 3px;"
        "}"

        "QComboBox {"
        "    background-color: #333333;"
        "    color: white;"
        "    border: 1px solid #4a4a4a;"
        "    border-radius: 3px;"
        "    padding: 3px;"
        "    min-height: 20px;"
        "}"

        "QComboBox QAbstractItemView {"
        "    background-color: #333333;"
        "    color: white;"
        "    selection-background-color: #555555;"
        "}"

        "QScrollArea {"
        "    border: none;"
        "    background-color: #252525;"
        "}"

        "QPushButton {"
        "    background-color: transparent;"
        "    color: white;"
        "    border: none;"
        "    border-radius: 3px;"
        "    font-size: 16px;"
        "}"

        "QPushButton:hover {"
        "    background-color: #444444;"
        "}"

        "QPushButton:pressed {"
        "    background-color: #555555;"
        "}"
        );

    /*
     * =========================================================
     * MAIN LAYOUT
     * =========================================================
     */

    QVBoxLayout* mainLayout =
        new QVBoxLayout(this);

    mainLayout->setContentsMargins(
        5,
        5,
        5,
        5
        );

    mainLayout->setSpacing(4);


    /*
     * =========================================================
     * TITLE BAR
     * =========================================================
     */

    QWidget* titleBar =
        new QWidget(this);

    titleBar->setFixedHeight(30);

    QHBoxLayout* titleLayout =
        new QHBoxLayout(titleBar);

    titleLayout->setContentsMargins(
        6,
        0,
        2,
        0
        );

    titleLayout->setSpacing(2);


    titleLabel =
        new QLabel(this);

    titleLabel->setSizePolicy(
        QSizePolicy::Expanding,
        QSizePolicy::Preferred
        );

    titleLabel->setStyleSheet(
        "font-weight: bold;"
        "font-size: 13px;"
        );


    minimizeButton =
        new QPushButton("—");

    minimizeButton->setFixedSize(
        25,
        25
        );

    minimizeButton->setToolTip(
        "Réduire"
        );


    closeButton =
        new QPushButton("×");

    closeButton->setFixedSize(
        25,
        25
        );

    closeButton->setToolTip(
        "Fermer"
        );


    titleLayout->addWidget(
        titleLabel
        );

    titleLayout->addWidget(
        minimizeButton
        );

    titleLayout->addWidget(
        closeButton
        );

    mainLayout->addWidget(
        titleBar
        );


    /*
     * =========================================================
     * CONTENT
     * =========================================================
     */

    contentWidget =
        new QWidget(this);

    QVBoxLayout* contentLayout =
        new QVBoxLayout(
            contentWidget
            );

    contentLayout->setContentsMargins(
        2,
        2,
        2,
        2
        );

    contentLayout->setSpacing(5);


    /*
     * =========================================================
     * IDENTITY
     * =========================================================
     */

    QGroupBox* identityGroup =
        new QGroupBox(
            "Identité"
            );

    QFormLayout* identityLayout =
        new QFormLayout(
            identityGroup
            );

    identityLayout->setContentsMargins(
        6,
        8,
        6,
        6
        );

    identityLayout->setSpacing(4);


    prenomEdit =
        new QLineEdit();

    prenomEdit->setObjectName(
        "prenomEdit"
        );


    nomEdit =
        new QLineEdit();

    nomEdit->setObjectName(
        "nomEdit"
        );


    raceEdit =
        new QComboBox();

    raceEdit->setObjectName(
        "raceEdit"
        );

    raceEdit->addItems({
        "Humain",

        "Haut-elfe",
        "Elfe des bois",
        "Elfe noir",

        "Halfelin pied-leger",
        "Halfling robuste",

        "Nain des colline",
        "Nain des montagnes",

        "Demi-elfe",
        "Demi-orc",

        "Drakeide",

        "Gnome des forets",
        "Gnome des rochs",

        "Tieffelin"
    });


    identityLayout->addRow(
        "Prénom",
        prenomEdit
        );

    identityLayout->addRow(
        "Nom",
        nomEdit
        );

    identityLayout->addRow(
        "Race",
        raceEdit
        );


    contentLayout->addWidget(
        identityGroup
        );


    /*
     * =========================================================
     * APPEARANCE
     * =========================================================
     */

    QGroupBox* appearanceGroup =
        new QGroupBox(
            "Apparence"
            );

    QVBoxLayout* appearanceLayout =
        new QVBoxLayout(
            appearanceGroup
            );

    appearanceLayout->setContentsMargins(
        6,
        8,
        6,
        6
        );

    appearanceLayout->setSpacing(3);


    apparenceEdit =
        new QLineEdit();

    apparenceEdit->setObjectName(
        "apparenceEdit"
        );


    apparenceDescriptionEdit =
        new QTextEdit();

    apparenceDescriptionEdit->setObjectName(
        "apparenceDescriptionEdit"
        );

    apparenceDescriptionEdit->setFixedHeight(
        45
        );


    appearanceLayout->addWidget(
        apparenceEdit
        );

    appearanceLayout->addWidget(
        apparenceDescriptionEdit
        );


    contentLayout->addWidget(
        appearanceGroup
        );


    /*
     * =========================================================
     * PERSONNALITE
     * =========================================================
     */

    QGroupBox* personalityGroup =
        new QGroupBox(
            "Personnalité"
            );

    QVBoxLayout* personalityLayout =
        new QVBoxLayout(
            personalityGroup
            );

    personalityLayout->setContentsMargins(
        6,
        8,
        6,
        6
        );

    personalityLayout->setSpacing(3);


    personnaliteEdit =
        new QLineEdit();

    personnaliteEdit->setObjectName(
        "personnaliteEdit"
        );


    personnaliteDescriptionEdit =
        new QTextEdit();

    personnaliteDescriptionEdit->setObjectName(
        "personnaliteDescriptionEdit"
        );

    personnaliteDescriptionEdit->setFixedHeight(
        45
        );


    personalityLayout->addWidget(
        personnaliteEdit
        );

    personalityLayout->addWidget(
        personnaliteDescriptionEdit
        );


    contentLayout->addWidget(
        personalityGroup
        );


    /*
     * =========================================================
     * MOTIVATION
     * =========================================================
     */

    QGroupBox* motivationGroup =
        new QGroupBox(
            "Motivation"
            );

    QVBoxLayout* motivationLayout =
        new QVBoxLayout(
            motivationGroup
            );

    motivationLayout->setContentsMargins(
        6,
        8,
        6,
        6
        );

    motivationLayout->setSpacing(3);


    motivationEdit =
        new QLineEdit();

    motivationEdit->setObjectName(
        "motivationEdit"
        );


    motivationDescriptionEdit =
        new QTextEdit();

    motivationDescriptionEdit->setObjectName(
        "motivationDescriptionEdit"
        );

    motivationDescriptionEdit->setFixedHeight(
        45
        );


    motivationLayout->addWidget(
        motivationEdit
        );

    motivationLayout->addWidget(
        motivationDescriptionEdit
        );


    contentLayout->addWidget(
        motivationGroup
        );


    /*
     * =========================================================
     * ACCROCHE
     * =========================================================
     */

    QGroupBox* hookGroup =
        new QGroupBox(
            "Accroche"
            );

    QVBoxLayout* hookLayout =
        new QVBoxLayout(
            hookGroup
            );

    hookLayout->setContentsMargins(
        6,
        8,
        6,
        6
        );

    hookLayout->setSpacing(3);


    accrocheEdit =
        new QLineEdit();

    accrocheEdit->setObjectName(
        "accrocheEdit"
        );


    accrocheDescriptionEdit =
        new QTextEdit();

    accrocheDescriptionEdit->setObjectName(
        "accrocheDescriptionEdit"
        );

    accrocheDescriptionEdit->setFixedHeight(
        45
        );


    hookLayout->addWidget(
        accrocheEdit
        );

    hookLayout->addWidget(
        accrocheDescriptionEdit
        );


    contentLayout->addWidget(
        hookGroup
        );


    /*
     * =========================================================
     * SCROLL AREA
     * =========================================================
     */

    scrollArea =
        new QScrollArea(this);

    scrollArea->setWidget(
        contentWidget
        );

    scrollArea->setWidgetResizable(
        true
        );

    scrollArea->setHorizontalScrollBarPolicy(
        Qt::ScrollBarAlwaysOff
        );

    scrollArea->setVerticalScrollBarPolicy(
        Qt::ScrollBarAsNeeded
        );

    mainLayout->addWidget(
        scrollArea
        );


    /*
     * =========================================================
     * PRENOM
     * =========================================================
     */

    connect(
        prenomEdit,
        &QLineEdit::textChanged,
        this,
        [this](const QString& text)
        {
            this->npc.Prenom =
                text;

            Update_Title();

            emit npcUpdated(
                this->npc
                );
        }
        );


    /*
     * =========================================================
     * NOM
     * =========================================================
     */

    connect(
        nomEdit,
        &QLineEdit::textChanged,
        this,
        [this](const QString& text)
        {
            this->npc.Nom =
                text;

            Update_Title();

            emit npcUpdated(
                this->npc
                );
        }
        );


    /*
     * =========================================================
     * RACE
     * =========================================================
     */

    connect(
        raceEdit,
        &QComboBox::currentTextChanged,
        this,
        [this](const QString& race)
        {
            if (race.isEmpty())
                return;

            this->npc.Race =
                race;

            this->npc.Set_Random_Prenom(
                race
                );

            this->npc.Set_Random_Name(
                race
                );

            {
                QSignalBlocker blockerPrenom(
                    prenomEdit
                    );

                QSignalBlocker blockerNom(
                    nomEdit
                    );

                prenomEdit->setText(
                    this->npc.Prenom
                    );

                nomEdit->setText(
                    this->npc.Nom
                    );
            }

            Update_Title();

            emit npcUpdated(
                this->npc
                );
        }
        );


    /*
     * =========================================================
     * APPARENCE
     * =========================================================
     */

    connect(
        apparenceEdit,
        &QLineEdit::textChanged,
        this,
        [this](const QString& text)
        {
            this->npc.Apparence =
                text;

            emit npcUpdated(
                this->npc
                );
        }
        );


    connect(
        apparenceDescriptionEdit,
        &QTextEdit::textChanged,
        this,
        [this]()
        {
            this->npc.Apparence_Descripion =
                apparenceDescriptionEdit
                    ->toPlainText();

            emit npcUpdated(
                this->npc
                );
        }
        );


    /*
     * =========================================================
     * PERSONNALITE
     * =========================================================
     */

    connect(
        personnaliteEdit,
        &QLineEdit::textChanged,
        this,
        [this](const QString& text)
        {
            this->npc.Personnalite =
                text;

            emit npcUpdated(
                this->npc
                );
        }
        );


    connect(
        personnaliteDescriptionEdit,
        &QTextEdit::textChanged,
        this,
        [this]()
        {
            this->npc.Personnalite_Descripion =
                personnaliteDescriptionEdit
                    ->toPlainText();

            emit npcUpdated(
                this->npc
                );
        }
        );


    /*
     * =========================================================
     * MOTIVATION
     * =========================================================
     */

    connect(
        motivationEdit,
        &QLineEdit::textChanged,
        this,
        [this](const QString& text)
        {
            this->npc.Motivation =
                text;

            emit npcUpdated(
                this->npc
                );
        }
        );


    connect(
        motivationDescriptionEdit,
        &QTextEdit::textChanged,
        this,
        [this]()
        {
            this->npc.Motivation_Descripion =
                motivationDescriptionEdit
                    ->toPlainText();

            emit npcUpdated(
                this->npc
                );
        }
        );


    /*
     * =========================================================
     * ACCROCHE
     * =========================================================
     */

    connect(
        accrocheEdit,
        &QLineEdit::textChanged,
        this,
        [this](const QString& text)
        {
            this->npc.Accroche =
                text;

            emit npcUpdated(
                this->npc
                );
        }
        );


    connect(
        accrocheDescriptionEdit,
        &QTextEdit::textChanged,
        this,
        [this]()
        {
            this->npc.Accroche_Descripion =
                accrocheDescriptionEdit
                    ->toPlainText();

            emit npcUpdated(
                this->npc
                );
        }
        );


    /*
     * =========================================================
     * MINIMIZE
     * =========================================================
     */

    connect(
        minimizeButton,
        &QPushButton::clicked,
        this,
        [this]()
        {
            minimized =
                !minimized;

            scrollArea->setVisible(
                !minimized
                );

            minimizeButton->setText(
                minimized
                    ? "+"
                    : "—"
                );

            minimizeButton->setToolTip(
                minimized
                    ? "Agrandir"
                    : "Réduire"
                );

            adjustSize();
        }
        );


    /*
     * =========================================================
     * CLOSE
     * =========================================================
     */

    connect(
        closeButton,
        &QPushButton::clicked,
        this,
        [this]()
        {
            close();
        }
        );


    /*
     * =========================================================
     * INITIAL DATA
     * =========================================================
     */

    Update_UI_From_NPC();

    resize(
        370,
        480
        );
}


/*
 * ============================================================
 * GET NPC
 * ============================================================
 */

const DND_GM_Helper_5E::NPC::NPC&
NPCWindow::Get_NPC() const
{
    return this->npc;
}


/*
 * ============================================================
 * SET NPC
 * ============================================================
 */

void NPCWindow::Set_NPC(
    const DND_GM_Helper_5E::NPC::NPC& value)
{
    this->npc =
        value;

    Update_UI_From_NPC();
}


/*
 * ============================================================
 * UPDATE TITLE
 * ============================================================
 */

void NPCWindow::Update_Title()
{
    QString fullName =
        this->npc.Prenom.trimmed();

    if (!this->npc.Nom.trimmed().isEmpty())
    {
        if (!fullName.isEmpty())
            fullName += " ";

        fullName +=
            this->npc.Nom.trimmed();
    }

    if (fullName.isEmpty())
        fullName = "NPC";

    titleLabel->setText(
        fullName
        );
}


/*
 * ============================================================
 * UPDATE UI FROM NPC
 * ============================================================
 */

void NPCWindow::Update_UI_From_NPC()
{
    QSignalBlocker blocker1(
        prenomEdit
        );

    QSignalBlocker blocker2(
        nomEdit
        );

    QSignalBlocker blocker3(
        raceEdit
        );

    QSignalBlocker blocker4(
        apparenceEdit
        );

    QSignalBlocker blocker5(
        apparenceDescriptionEdit
        );

    QSignalBlocker blocker6(
        personnaliteEdit
        );

    QSignalBlocker blocker7(
        personnaliteDescriptionEdit
        );

    QSignalBlocker blocker8(
        motivationEdit
        );

    QSignalBlocker blocker9(
        motivationDescriptionEdit
        );

    QSignalBlocker blocker10(
        accrocheEdit
        );

    QSignalBlocker blocker11(
        accrocheDescriptionEdit
        );


    prenomEdit->setText(
        this->npc.Prenom
        );

    nomEdit->setText(
        this->npc.Nom
        );


    const int raceIndex =
        raceEdit->findText(
            this->npc.Race
            );

    if (raceIndex >= 0)
    {
        raceEdit->setCurrentIndex(
            raceIndex
            );
    }


    apparenceEdit->setText(
        this->npc.Apparence
        );

    apparenceDescriptionEdit
        ->setPlainText(
            this->npc.Apparence_Descripion
            );


    personnaliteEdit->setText(
        this->npc.Personnalite
        );

    personnaliteDescriptionEdit
        ->setPlainText(
            this->npc.Personnalite_Descripion
            );


    motivationEdit->setText(
        this->npc.Motivation
        );

    motivationDescriptionEdit
        ->setPlainText(
            this->npc.Motivation_Descripion
            );


    accrocheEdit->setText(
        this->npc.Accroche
        );

    accrocheDescriptionEdit
        ->setPlainText(
            this->npc.Accroche_Descripion
            );


    Update_Title();
}


/*
 * ============================================================
 * UPDATE NPC FROM UI
 * ============================================================
 */

void NPCWindow::Update_NPC_From_UI()
{
    this->npc.Prenom =
        prenomEdit->text();

    this->npc.Nom =
        nomEdit->text();

    this->npc.Race =
        raceEdit->currentText();

    this->npc.Apparence =
        apparenceEdit->text();

    this->npc.Apparence_Descripion =
        apparenceDescriptionEdit
            ->toPlainText();

    this->npc.Personnalite =
        personnaliteEdit->text();

    this->npc.Personnalite_Descripion =
        personnaliteDescriptionEdit
            ->toPlainText();

    this->npc.Motivation =
        motivationEdit->text();

    this->npc.Motivation_Descripion =
        motivationDescriptionEdit
            ->toPlainText();

    this->npc.Accroche =
        accrocheEdit->text();

    this->npc.Accroche_Descripion =
        accrocheDescriptionEdit
            ->toPlainText();
}


/*
 * ============================================================
 * SAVE NPC TO JSON
 * ============================================================
 */

QJsonObject NPCWindow::To_Json() const
{
    QJsonObject object;

    object["prenom"] =
        this->npc.Prenom;

    object["nom"] =
        this->npc.Nom;

    object["race"] =
        this->npc.Race;


    object["apparence"] =
        this->npc.Apparence;

    object["apparence_description"] =
        this->npc.Apparence_Descripion;

    object["apparence_index"] =
        this->npc.Apparence_Index;


    object["personnalite"] =
        this->npc.Personnalite;

    object["personnalite_description"] =
        this->npc.Personnalite_Descripion;

    object["personnalite_index"] =
        this->npc.Personnalite_Index;


    object["motivation"] =
        this->npc.Motivation;

    object["motivation_description"] =
        this->npc.Motivation_Descripion;

    object["motivation_index"] =
        this->npc.Motivation_Index;


    object["accroche"] =
        this->npc.Accroche;

    object["accroche_description"] =
        this->npc.Accroche_Descripion;

    object["accroche_index"] =
        this->npc.Accroche_Index;


    return object;
}


/*
 * ============================================================
 * LOAD NPC FROM JSON
 * ============================================================
 */

void NPCWindow::From_Json(
    const QJsonObject& object)
{
    this->npc.Prenom =
        object["prenom"]
            .toString();

    this->npc.Nom =
        object["nom"]
            .toString();

    this->npc.Race =
        object["race"]
            .toString();


    this->npc.Apparence =
        object["apparence"]
            .toString();

    this->npc.Apparence_Descripion =
        object[
            "apparence_description"
    ].toString();

    this->npc.Apparence_Index =
        object[
            "apparence_index"
    ].toInt();


    this->npc.Personnalite =
        object["personnalite"]
            .toString();

    this->npc.Personnalite_Descripion =
        object[
            "personnalite_description"
    ].toString();

    this->npc.Personnalite_Index =
        object[
            "personnalite_index"
    ].toInt();


    this->npc.Motivation =
        object["motivation"]
            .toString();

    this->npc.Motivation_Descripion =
        object[
            "motivation_description"
    ].toString();

    this->npc.Motivation_Index =
        object[
            "motivation_index"
    ].toInt();


    this->npc.Accroche =
        object["accroche"]
            .toString();

    this->npc.Accroche_Descripion =
        object[
            "accroche_description"
    ].toString();

    this->npc.Accroche_Index =
        object[
            "accroche_index"
    ].toInt();


    Update_UI_From_NPC();

    emit npcUpdated(
        this->npc
        );
}


/*
 * ============================================================
 * MOUSE DRAG
 * ============================================================
 */

void NPCWindow::mousePressEvent(
    QMouseEvent* event)
{
    if (event->button() ==
            Qt::LeftButton &&
        event->position().y() <= 35)
    {
        dragging = true;

        dragPosition =
            event->globalPosition()
                .toPoint() -
            frameGeometry()
                .topLeft();

        event->accept();

        return;
    }

    QWidget::mousePressEvent(
        event
        );
}


void NPCWindow::mouseMoveEvent(
    QMouseEvent* event)
{
    if (dragging &&
        (event->buttons() &
         Qt::LeftButton))
    {
        move(
            event->globalPosition()
                .toPoint() -
            dragPosition
            );

        event->accept();

        return;
    }

    QWidget::mouseMoveEvent(
        event
        );
}


void NPCWindow::mouseReleaseEvent(
    QMouseEvent* event)
{
    if (event->button() ==
        Qt::LeftButton)
    {
        dragging = false;

        event->accept();

        return;
    }

    QWidget::mouseReleaseEvent(
        event
        );
}
