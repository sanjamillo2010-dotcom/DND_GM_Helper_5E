#include "../include/dashbord.h"
#include "../include/missiondashbord.h"

#include "ui_dashbord.h"

#include <QMessageBox>
#include <QPushButton>

Dashbord::Dashbord(
    Campaign* campaign,
    QWidget* parent
    )
    : QMainWindow(parent)
    , ui(new Ui::Dashbord)
    , m_campaign(campaign)
    , m_missionDashboard(nullptr)
{
    ui->setupUi(this);

    connect(
        ui->addMissionButton,
        &QPushButton::clicked,
        this,
        &Dashbord::Add_Mission
        );

    connect(
        ui->removeMissionButton,
        &QPushButton::clicked,
        this,
        &Dashbord::Remove_Mission
        );

    connect(
        ui->saveMissionButton,
        &QPushButton::clicked,
        this,
        &Dashbord::Update_Mission
        );

    connect(
        ui->missionList,
        &QListWidget::currentRowChanged,
        this,
        &Dashbord::Mission_Selected
        );

    connect(
        ui->missionList,
        &QListWidget::itemDoubleClicked,
        this,
        [this](QListWidgetItem*)
        {
            Open_Mission();
        }
        );

    QPushButton* backButton =
        new QPushButton(
            "Back to Campaign",
            this
            );

    ui->missionButtonsLayout->addWidget(
        backButton
        );

    connect(
        backButton,
        &QPushButton::clicked,
        this,
        [this]()
        {
            /*
             * Save any metadata currently in the
             * Mission Dashboard before leaving.
             */
            Update_Mission();

            close();
        }
        );

    Refresh_Mission_List();
}

Dashbord::~Dashbord()
{
    delete ui;
}

void Dashbord::Save_Campaign_To_File()
{
    if (m_campaign == nullptr)
        return;

    if (m_campaign->File_Path.isEmpty())
        return;

    if (!m_campaign->Save_To_File(
            m_campaign->File_Path))
    {
        QMessageBox::warning(
            this,
            "Save Campaign",
            "The campaign could not be saved:\n\n" +
                m_campaign->File_Path
            );
    }
}

void Dashbord::Add_Mission()
{
    if (m_campaign == nullptr)
        return;

    m_campaign->missions().Add_Mission(
        "New Mission",
        "",
        "Planned"
        );

    Refresh_Mission_List();

    const int index =
        m_campaign->missions()
            .Get_Mission_Count() - 1;

    ui->missionList->setCurrentRow(index);

    /*
     * Immediately persist the new mission.
     */
    Save_Campaign_To_File();
}

void Dashbord::Remove_Mission()
{
    if (m_campaign == nullptr)
        return;

    const int row =
        ui->missionList->currentRow();

    if (row < 0)
        return;

    m_campaign->missions().Remove_Mission(row);

    Refresh_Mission_List();

    ui->missionNameEdit->clear();
    ui->missionDescriptionEdit->clear();

    ui->missionStatusCombo->setCurrentIndex(0);

    Save_Campaign_To_File();
}

void Dashbord::Update_Mission()
{
    if (m_campaign == nullptr)
        return;

    const int row =
        ui->missionList->currentRow();

    if (row < 0)
        return;

    const QString name =
        ui->missionNameEdit
            ->text()
            .trimmed();

    const QString description =
        ui->missionDescriptionEdit
            ->toPlainText()
            .trimmed();

    const QString status =
        ui->missionStatusCombo
            ->currentText();

    if (name.isEmpty())
        return;

    /*
     * Update the in-memory Mission.
     */
    m_campaign->missions().Update_Mission(
        row,
        name,
        description,
        status
        );

    Refresh_Mission_List();

    ui->missionList->setCurrentRow(row);

    /*
     * IMPORTANT:
     * Write the modified Campaign to the
     * .dndcampaign file immediately.
     */
    Save_Campaign_To_File();
}

void Dashbord::Mission_Selected(int row)
{
    if (row < 0)
        return;

    Load_Mission(row);
}

void Dashbord::Load_Mission(int index)
{
    if (m_campaign == nullptr)
        return;

    if (index < 0 ||
        index >=
            m_campaign->missions()
                .Get_Mission_Count())
    {
        return;
    }

    const Missions::Entry mission =
        m_campaign->missions()
            .Get_Mission(index);

    ui->missionNameEdit->setText(
        mission.Name
        );

    ui->missionDescriptionEdit->setPlainText(
        mission.Description
        );

    const int statusIndex =
        ui->missionStatusCombo->findText(
            mission.Status
            );

    if (statusIndex >= 0)
    {
        ui->missionStatusCombo->setCurrentIndex(
            statusIndex
            );
    }
}

void Dashbord::Open_Mission()
{
    if (m_campaign == nullptr)
        return;

    const int row =
        ui->missionList->currentRow();

    if (row < 0)
        return;

    /*
     * Save the mission metadata currently shown
     * in the editor before opening the Mission Dashboard.
     */
    Update_Mission();

    if (m_missionDashboard != nullptr)
    {
        m_missionDashboard->Set_Mission_Index(
            row
            );

        m_missionDashboard->show();
        m_missionDashboard->raise();
        m_missionDashboard->activateWindow();

        hide();

        return;
    }

    m_missionDashboard =
        new MissionDashbord(
            m_campaign,
            row,
            this
            );

    m_missionDashboard->setAttribute(
        Qt::WA_DeleteOnClose
        );

    connect(
        m_missionDashboard,
        &QObject::destroyed,
        this,
        [this]()
        {
            m_missionDashboard = nullptr;

            Refresh_Mission_List();

            show();
            raise();
            activateWindow();
        }
        );

    m_missionDashboard->show();

    hide();
}

void Dashbord::Refresh_Mission_List()
{
    if (m_campaign == nullptr)
        return;

    const int currentRow =
        ui->missionList->currentRow();

    ui->missionList->clear();

    const QList<Missions::Entry> missions =
        m_campaign->missions()
            .Get_Missions();

    for (const Missions::Entry& mission :
         missions)
    {
        ui->missionList->addItem(
            mission.Name +
            " [" +
            mission.Status +
            "]"
            );
    }

    if (missions.isEmpty())
    {
        ui->missionNameEdit->clear();
        ui->missionDescriptionEdit->clear();
        ui->missionStatusCombo->setCurrentIndex(0);
        return;
    }

    int row = currentRow;

    if (row < 0)
        row = 0;

    if (row >= missions.size())
        row = missions.size() - 1;

    ui->missionList->setCurrentRow(row);
}
