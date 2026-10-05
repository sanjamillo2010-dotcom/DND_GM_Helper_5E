/********************************************************************************
** Form generated from reading UI file 'campaigndashbord.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CAMPAIGNDASHBORD_H
#define UI_CAMPAIGNDASHBORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CampaignDashbord
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QLabel *titleLabel;
    QFormLayout *campaignInfoLayout;
    QLabel *campaignNameLabel;
    QLineEdit *campaignNameEdit;
    QLabel *gmInformationLabel;
    QLineEdit *gmInformationEdit;
    QLabel *fileLabel;
    QLabel *campaignFileLocationLabel;
    QLabel *createdDateLabel;
    QLineEdit *createdDateEdit;
    QLabel *descriptionLabel;
    QPlainTextEdit *campaignDescriptionEdit;
    QSpacerItem *mainSpacer;
    QHBoxLayout *campaignButtonsLayout;
    QSpacerItem *leftButtonSpacer;
    QPushButton *newCampaignButton;
    QPushButton *openCampaignButton;
    QPushButton *openMissionsButton;
    QSpacerItem *rightButtonSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *CampaignDashbord)
    {
        if (CampaignDashbord->objectName().isEmpty())
            CampaignDashbord->setObjectName("CampaignDashbord");
        CampaignDashbord->resize(1000, 700);
        centralwidget = new QWidget(CampaignDashbord);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setObjectName("mainLayout");
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("font-size: 24px;\n"
"font-weight: bold;\n"
"padding: 10px;"));

        mainLayout->addWidget(titleLabel);

        campaignInfoLayout = new QFormLayout();
        campaignInfoLayout->setObjectName("campaignInfoLayout");
        campaignNameLabel = new QLabel(centralwidget);
        campaignNameLabel->setObjectName("campaignNameLabel");

        campaignInfoLayout->setWidget(0, QFormLayout::LabelRole, campaignNameLabel);

        campaignNameEdit = new QLineEdit(centralwidget);
        campaignNameEdit->setObjectName("campaignNameEdit");

        campaignInfoLayout->setWidget(0, QFormLayout::FieldRole, campaignNameEdit);

        gmInformationLabel = new QLabel(centralwidget);
        gmInformationLabel->setObjectName("gmInformationLabel");

        campaignInfoLayout->setWidget(1, QFormLayout::LabelRole, gmInformationLabel);

        gmInformationEdit = new QLineEdit(centralwidget);
        gmInformationEdit->setObjectName("gmInformationEdit");

        campaignInfoLayout->setWidget(1, QFormLayout::FieldRole, gmInformationEdit);

        fileLabel = new QLabel(centralwidget);
        fileLabel->setObjectName("fileLabel");

        campaignInfoLayout->setWidget(2, QFormLayout::LabelRole, fileLabel);

        campaignFileLocationLabel = new QLabel(centralwidget);
        campaignFileLocationLabel->setObjectName("campaignFileLocationLabel");
        campaignFileLocationLabel->setStyleSheet(QString::fromUtf8("color: gray;\n"
"font-size: 11px;"));
        campaignFileLocationLabel->setWordWrap(true);

        campaignInfoLayout->setWidget(2, QFormLayout::FieldRole, campaignFileLocationLabel);

        createdDateLabel = new QLabel(centralwidget);
        createdDateLabel->setObjectName("createdDateLabel");

        campaignInfoLayout->setWidget(3, QFormLayout::LabelRole, createdDateLabel);

        createdDateEdit = new QLineEdit(centralwidget);
        createdDateEdit->setObjectName("createdDateEdit");

        campaignInfoLayout->setWidget(3, QFormLayout::FieldRole, createdDateEdit);


        mainLayout->addLayout(campaignInfoLayout);

        descriptionLabel = new QLabel(centralwidget);
        descriptionLabel->setObjectName("descriptionLabel");

        mainLayout->addWidget(descriptionLabel);

        campaignDescriptionEdit = new QPlainTextEdit(centralwidget);
        campaignDescriptionEdit->setObjectName("campaignDescriptionEdit");

        mainLayout->addWidget(campaignDescriptionEdit);

        mainSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        mainLayout->addItem(mainSpacer);

        campaignButtonsLayout = new QHBoxLayout();
        campaignButtonsLayout->setObjectName("campaignButtonsLayout");
        leftButtonSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        campaignButtonsLayout->addItem(leftButtonSpacer);

        newCampaignButton = new QPushButton(centralwidget);
        newCampaignButton->setObjectName("newCampaignButton");
        newCampaignButton->setMinimumSize(QSize(180, 55));

        campaignButtonsLayout->addWidget(newCampaignButton);

        openCampaignButton = new QPushButton(centralwidget);
        openCampaignButton->setObjectName("openCampaignButton");
        openCampaignButton->setMinimumSize(QSize(180, 55));

        campaignButtonsLayout->addWidget(openCampaignButton);

        openMissionsButton = new QPushButton(centralwidget);
        openMissionsButton->setObjectName("openMissionsButton");
        openMissionsButton->setMinimumSize(QSize(180, 55));

        campaignButtonsLayout->addWidget(openMissionsButton);

        rightButtonSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        campaignButtonsLayout->addItem(rightButtonSpacer);


        mainLayout->addLayout(campaignButtonsLayout);

        CampaignDashbord->setCentralWidget(centralwidget);
        menubar = new QMenuBar(CampaignDashbord);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1000, 22));
        CampaignDashbord->setMenuBar(menubar);
        statusbar = new QStatusBar(CampaignDashbord);
        statusbar->setObjectName("statusbar");
        CampaignDashbord->setStatusBar(statusbar);

        retranslateUi(CampaignDashbord);

        QMetaObject::connectSlotsByName(CampaignDashbord);
    } // setupUi

    void retranslateUi(QMainWindow *CampaignDashbord)
    {
        CampaignDashbord->setWindowTitle(QCoreApplication::translate("CampaignDashbord", "Campaign Dashboard", nullptr));
        titleLabel->setText(QCoreApplication::translate("CampaignDashbord", "Campaign Dashboard", nullptr));
        campaignNameLabel->setText(QCoreApplication::translate("CampaignDashbord", "Campaign Name:", nullptr));
        campaignNameEdit->setPlaceholderText(QCoreApplication::translate("CampaignDashbord", "Campaign name", nullptr));
        gmInformationLabel->setText(QCoreApplication::translate("CampaignDashbord", "DM:", nullptr));
        gmInformationEdit->setPlaceholderText(QCoreApplication::translate("CampaignDashbord", "Dungeon Master", nullptr));
        fileLabel->setText(QCoreApplication::translate("CampaignDashbord", "File:", nullptr));
        campaignFileLocationLabel->setText(QCoreApplication::translate("CampaignDashbord", "Not saved", nullptr));
        createdDateLabel->setText(QCoreApplication::translate("CampaignDashbord", "Created Date:", nullptr));
        createdDateEdit->setPlaceholderText(QCoreApplication::translate("CampaignDashbord", "YYYY-MM-DD", nullptr));
        descriptionLabel->setText(QCoreApplication::translate("CampaignDashbord", "Description:", nullptr));
        campaignDescriptionEdit->setPlaceholderText(QCoreApplication::translate("CampaignDashbord", "Campaign description...", nullptr));
        newCampaignButton->setText(QCoreApplication::translate("CampaignDashbord", "New Campaign", nullptr));
        openCampaignButton->setText(QCoreApplication::translate("CampaignDashbord", "Open Campaign", nullptr));
        openMissionsButton->setText(QCoreApplication::translate("CampaignDashbord", "Open Missions", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CampaignDashbord: public Ui_CampaignDashbord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CAMPAIGNDASHBORD_H
