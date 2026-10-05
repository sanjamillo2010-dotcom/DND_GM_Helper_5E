#include "../include/campaigndashbord.h"
#include "../include/dashbord.h"

#include "ui_campaigndashbord.h"

#include <QAction>
#include <QDate>
#include <QDir>
#include <QFile>
#include <QFileDialog>
#include <QFileInfo>
#include <QJsonDocument>
#include <QMenu>
#include <QMessageBox>
#include <QPushButton>

static QString Sanitize_File_Name(
    const QString& fileName)
{
    QString result =
        fileName.trimmed();

    // Replace whitespace with underscores.
    for (QChar& character : result)
    {
        if (character.isSpace())
            character = '_';
    }

    // Replace invalid filename characters.
    const QString invalidCharacters =
        R"(\/:*?"<>|)";

    for (QChar& character : result)
    {
        if (invalidCharacters.contains(
                character))
        {
            character = '_';
        }
    }

    // Replace control characters.
    for (QChar& character : result)
    {
        if (character.unicode() < 32)
            character = '_';
    }

    // Collapse repeated underscores.
    while (result.contains("__"))
        result.replace("__", "_");

    // Remove trailing dots.
    while (result.endsWith('.'))
        result.chop(1);

    if (result.isEmpty())
        result = "New_Campaign";

    return result;
}

CampaignDashbord::CampaignDashbord(
    QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::CampaignDashbord)
    , m_missionsDashboard(nullptr)
{
    ui->setupUi(this);

    setWindowTitle(
        "Campaign Dashboard"
        );

    // New Campaign.
    connect(
        ui->newCampaignButton,
        &QPushButton::clicked,
        this,
        &CampaignDashbord::New_Campaign
        );

    // Open Campaign.
    connect(
        ui->openCampaignButton,
        &QPushButton::clicked,
        this,
        &CampaignDashbord::Open_Campaign
        );

    // Open Missions.
    connect(
        ui->openMissionsButton,
        &QPushButton::clicked,
        this,
        &CampaignDashbord::Open_Missions
        );

    // File menu.
    QMenu* fileMenu =
        menuBar()->addMenu("File");

    QAction* saveCampaignAction =
        fileMenu->addAction(
            "Save Campaign"
            );

    fileMenu->addSeparator();

    QAction* quitAction =
        fileMenu->addAction(
            "Quit"
            );

    connect(
        saveCampaignAction,
        &QAction::triggered,
        this,
        &CampaignDashbord::Save_Campaign
        );

    connect(
        quitAction,
        &QAction::triggered,
        this,
        &QWidget::close
        );

    // Default created date.
    ui->createdDateEdit->setText(
        QDate::currentDate()
            .toString(Qt::ISODate)
        );

    Update_File_Location();
}

CampaignDashbord::~CampaignDashbord()
{
    delete ui;
}

void CampaignDashbord::Update_Campaign_From_UI()
{
    m_campaign.Name =
        ui->campaignNameEdit
            ->text()
            .trimmed();

    m_campaign.GM_information =
        ui->gmInformationEdit
            ->text()
            .trimmed();

    m_campaign.Created_date =
        ui->createdDateEdit
            ->text()
            .trimmed();

    m_campaign.Description =
        ui->campaignDescriptionEdit
            ->toPlainText()
            .trimmed();
}

void CampaignDashbord::Update_UI_From_Campaign()
{
    ui->campaignNameEdit->setText(
        m_campaign.Name
        );

    ui->gmInformationEdit->setText(
        m_campaign.GM_information
        );

    ui->createdDateEdit->setText(
        m_campaign.Created_date
        );

    ui->campaignDescriptionEdit
        ->setPlainText(
            m_campaign.Description
            );

    Update_File_Location();
}

void CampaignDashbord::Update_File_Location()
{
    if (m_campaignFilePath.isEmpty())
    {
        ui->campaignFileLocationLabel->setText(
            "Not saved"
            );

        return;
    }

    ui->campaignFileLocationLabel->setText(
        m_campaignFilePath
        );
}

void CampaignDashbord::New_Campaign()
{
    const QString campaignName =
        ui->campaignNameEdit
            ->text()
            .trimmed();

    QString defaultFileName;

    if (campaignName.isEmpty())
    {
        defaultFileName =
            "New_Campaign.dndcampaign";
    }
    else
    {
        defaultFileName =
            Sanitize_File_Name(
                campaignName
                ) +
            ".dndcampaign";
    }

    const QString startPath =
        QDir::homePath() +
        QDir::separator() +
        defaultFileName;

    const QString selectedFile =
        QFileDialog::getSaveFileName(
            this,
            "Create New Campaign",
            startPath,
            "D&D Campaign (*.dndcampaign)"
            );

    if (selectedFile.isEmpty())
        return;

    const QFileInfo selectedInfo(
        selectedFile
        );

    QString cleanFileName =
        Sanitize_File_Name(
            selectedInfo.completeBaseName()
            );

    if (cleanFileName.isEmpty())
        cleanFileName =
            "New_Campaign";

    m_campaignFilePath =
        selectedInfo.absolutePath() +
        QDir::separator() +
        cleanFileName +
        ".dndcampaign";

    // Start a completely new campaign.
    m_campaign =
        Campaign();

    m_campaign.File_Path =
        m_campaignFilePath;

    m_campaign.Name =
        campaignName;

    m_campaign.GM_information =
        ui->gmInformationEdit
            ->text()
            .trimmed();

    m_campaign.Created_date =
        ui->createdDateEdit
            ->text()
            .trimmed();

    if (m_campaign.Created_date.isEmpty())
    {
        m_campaign.Created_date =
            QDate::currentDate()
                .toString(Qt::ISODate);
    }

    m_campaign.Description =
        ui->campaignDescriptionEdit
            ->toPlainText()
            .trimmed();

    if (!m_campaign.Save_To_File(
            m_campaignFilePath))
    {
        QMessageBox::critical(
            this,
            "Create Campaign",
            "Could not create the campaign file:\n\n" +
                m_campaignFilePath
            );

        m_campaignFilePath.clear();

        m_campaign.File_Path.clear();

        Update_File_Location();

        return;
    }

    Update_UI_From_Campaign();
}

void CampaignDashbord::Open_Campaign()
{
    const QString fileName =
        QFileDialog::getOpenFileName(
            this,
            "Open Campaign",
            QString(),
            "D&D Campaign (*.dndcampaign)"
            );

    if (fileName.isEmpty())
        return;

    if (!m_campaign.Load_From_File(
            fileName))
    {
        QMessageBox::critical(
            this,
            "Open Campaign",
            "Could not load the campaign file:\n\n" +
                fileName
            );

        return;
    }

    m_campaignFilePath =
        fileName;

    m_campaign.File_Path =
        fileName;

    Update_UI_From_Campaign();

    if (m_missionsDashboard != nullptr)
    {
        m_missionsDashboard->close();
        m_missionsDashboard = nullptr;
    }
}

void CampaignDashbord::Open_Missions()
{
    if (m_campaignFilePath.isEmpty())
    {
        QMessageBox::information(
            this,
            "Open Missions",
            "Create or open a campaign first."
            );

        return;
    }

    Update_Campaign_From_UI();

    if (m_missionsDashboard != nullptr)
    {
        m_missionsDashboard->show();
        m_missionsDashboard->raise();
        m_missionsDashboard->activateWindow();

        hide();

        return;
    }

    m_missionsDashboard =
        new Dashbord(
            &m_campaign,
            this
            );

    m_missionsDashboard->setAttribute(
        Qt::WA_DeleteOnClose
        );

    connect(
        m_missionsDashboard,
        &QObject::destroyed,
        this,
        [this]()
        {
            m_missionsDashboard = nullptr;

            Update_UI_From_Campaign();

            show();
            raise();
            activateWindow();
        }
        );

    m_missionsDashboard->show();

    hide();
}

void CampaignDashbord::Save_Campaign()
{
    Update_Campaign_From_UI();

    if (m_campaignFilePath.isEmpty())
    {
        QString defaultFileName;

        if (m_campaign.Name
                .trimmed()
                .isEmpty())
        {
            defaultFileName =
                "New_Campaign.dndcampaign";
        }
        else
        {
            defaultFileName =
                Sanitize_File_Name(
                    m_campaign.Name
                    ) +
                ".dndcampaign";
        }

        const QString selectedFile =
            QFileDialog::getSaveFileName(
                this,
                "Save Campaign",
                QDir::homePath() +
                    QDir::separator() +
                    defaultFileName,
                "D&D Campaign (*.dndcampaign)"
                );

        if (selectedFile.isEmpty())
            return;

        const QFileInfo selectedInfo(
            selectedFile
            );

        QString cleanFileName =
            Sanitize_File_Name(
                selectedInfo.completeBaseName()
                );

        if (cleanFileName.isEmpty())
            cleanFileName =
                "New_Campaign";

        m_campaignFilePath =
            selectedInfo.absolutePath() +
            QDir::separator() +
            cleanFileName +
            ".dndcampaign";
    }

    m_campaign.File_Path =
        m_campaignFilePath;

    if (!m_campaign.Save_To_File(
            m_campaignFilePath))
    {
        QMessageBox::critical(
            this,
            "Save Campaign",
            "Could not save the campaign file:\n\n" +
                m_campaignFilePath
            );

        return;
    }

    Update_File_Location();
}
