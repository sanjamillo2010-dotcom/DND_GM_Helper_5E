/********************************************************************************
** Form generated from reading UI file 'dashbord.ui'
**
** Created by: Qt User Interface Compiler version 6.10.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DASHBORD_H
#define UI_DASHBORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Dashbord
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QLabel *titleLabel;
    QSplitter *missionsSplitter;
    QWidget *missionsPanel;
    QVBoxLayout *missionsPanelLayout;
    QLabel *missionsTitleLabel;
    QListWidget *missionList;
    QHBoxLayout *missionButtonsLayout;
    QPushButton *addMissionButton;
    QPushButton *removeMissionButton;
    QPushButton *saveMissionButton;
    QWidget *missionDashboardPanel;
    QVBoxLayout *missionDashboardLayout;
    QLabel *missionDashboardTitleLabel;
    QGroupBox *missionDetailsGroupBox;
    QFormLayout *missionDetailsFormLayout;
    QLabel *missionNameLabel;
    QLineEdit *missionNameEdit;
    QLabel *missionStatusLabel;
    QComboBox *missionStatusCombo;
    QLabel *missionDescriptionLabel;
    QTextEdit *missionDescriptionEdit;
    QSpacerItem *missionDashboardSpacer;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Dashbord)
    {
        if (Dashbord->objectName().isEmpty())
            Dashbord->setObjectName("Dashbord");
        Dashbord->resize(1200, 515);
        centralwidget = new QWidget(Dashbord);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setObjectName("mainLayout");
        titleLabel = new QLabel(centralwidget);
        titleLabel->setObjectName("titleLabel");
        titleLabel->setStyleSheet(QString::fromUtf8("\n"
"font-size: 26px;\n"
"font-weight: bold;\n"
"padding: 12px;\n"
"       "));
        titleLabel->setAlignment(Qt::AlignCenter);

        mainLayout->addWidget(titleLabel);

        missionsSplitter = new QSplitter(centralwidget);
        missionsSplitter->setObjectName("missionsSplitter");
        missionsSplitter->setOrientation(Qt::Horizontal);
        missionsPanel = new QWidget(missionsSplitter);
        missionsPanel->setObjectName("missionsPanel");
        missionsPanelLayout = new QVBoxLayout(missionsPanel);
        missionsPanelLayout->setObjectName("missionsPanelLayout");
        missionsPanelLayout->setContentsMargins(0, 0, 0, 0);
        missionsTitleLabel = new QLabel(missionsPanel);
        missionsTitleLabel->setObjectName("missionsTitleLabel");
        missionsTitleLabel->setStyleSheet(QString::fromUtf8("\n"
"font-size: 18px;\n"
"font-weight: bold;\n"
"padding: 6px;\n"
"           "));

        missionsPanelLayout->addWidget(missionsTitleLabel);

        missionList = new QListWidget(missionsPanel);
        missionList->setObjectName("missionList");

        missionsPanelLayout->addWidget(missionList);

        missionButtonsLayout = new QHBoxLayout();
        missionButtonsLayout->setObjectName("missionButtonsLayout");
        addMissionButton = new QPushButton(missionsPanel);
        addMissionButton->setObjectName("addMissionButton");

        missionButtonsLayout->addWidget(addMissionButton);

        removeMissionButton = new QPushButton(missionsPanel);
        removeMissionButton->setObjectName("removeMissionButton");

        missionButtonsLayout->addWidget(removeMissionButton);

        saveMissionButton = new QPushButton(missionsPanel);
        saveMissionButton->setObjectName("saveMissionButton");

        missionButtonsLayout->addWidget(saveMissionButton);


        missionsPanelLayout->addLayout(missionButtonsLayout);

        missionsSplitter->addWidget(missionsPanel);
        missionDashboardPanel = new QWidget(missionsSplitter);
        missionDashboardPanel->setObjectName("missionDashboardPanel");
        missionDashboardLayout = new QVBoxLayout(missionDashboardPanel);
        missionDashboardLayout->setObjectName("missionDashboardLayout");
        missionDashboardLayout->setContentsMargins(0, 0, 0, 0);
        missionDashboardTitleLabel = new QLabel(missionDashboardPanel);
        missionDashboardTitleLabel->setObjectName("missionDashboardTitleLabel");
        missionDashboardTitleLabel->setStyleSheet(QString::fromUtf8("\n"
"font-size: 18px;\n"
"font-weight: bold;\n"
"padding: 6px;\n"
"           "));

        missionDashboardLayout->addWidget(missionDashboardTitleLabel);

        missionDetailsGroupBox = new QGroupBox(missionDashboardPanel);
        missionDetailsGroupBox->setObjectName("missionDetailsGroupBox");
        missionDetailsFormLayout = new QFormLayout(missionDetailsGroupBox);
        missionDetailsFormLayout->setObjectName("missionDetailsFormLayout");
        missionNameLabel = new QLabel(missionDetailsGroupBox);
        missionNameLabel->setObjectName("missionNameLabel");

        missionDetailsFormLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, missionNameLabel);

        missionNameEdit = new QLineEdit(missionDetailsGroupBox);
        missionNameEdit->setObjectName("missionNameEdit");

        missionDetailsFormLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, missionNameEdit);

        missionStatusLabel = new QLabel(missionDetailsGroupBox);
        missionStatusLabel->setObjectName("missionStatusLabel");

        missionDetailsFormLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, missionStatusLabel);

        missionStatusCombo = new QComboBox(missionDetailsGroupBox);
        missionStatusCombo->addItem(QString());
        missionStatusCombo->addItem(QString());
        missionStatusCombo->addItem(QString());
        missionStatusCombo->addItem(QString());
        missionStatusCombo->addItem(QString());
        missionStatusCombo->setObjectName("missionStatusCombo");

        missionDetailsFormLayout->setWidget(1, QFormLayout::ItemRole::FieldRole, missionStatusCombo);

        missionDescriptionLabel = new QLabel(missionDetailsGroupBox);
        missionDescriptionLabel->setObjectName("missionDescriptionLabel");

        missionDetailsFormLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, missionDescriptionLabel);

        missionDescriptionEdit = new QTextEdit(missionDetailsGroupBox);
        missionDescriptionEdit->setObjectName("missionDescriptionEdit");
        missionDescriptionEdit->setMinimumSize(QSize(0, 180));

        missionDetailsFormLayout->setWidget(2, QFormLayout::ItemRole::FieldRole, missionDescriptionEdit);


        missionDashboardLayout->addWidget(missionDetailsGroupBox);

        missionDashboardSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        missionDashboardLayout->addItem(missionDashboardSpacer);

        missionsSplitter->addWidget(missionDashboardPanel);

        mainLayout->addWidget(missionsSplitter);

        Dashbord->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Dashbord);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1200, 23));
        Dashbord->setMenuBar(menubar);
        statusbar = new QStatusBar(Dashbord);
        statusbar->setObjectName("statusbar");
        Dashbord->setStatusBar(statusbar);

        retranslateUi(Dashbord);

        QMetaObject::connectSlotsByName(Dashbord);
    } // setupUi

    void retranslateUi(QMainWindow *Dashbord)
    {
        Dashbord->setWindowTitle(QCoreApplication::translate("Dashbord", "D&D GM Helper 5E", nullptr));
        titleLabel->setText(QCoreApplication::translate("Dashbord", "D&D GM HELPER 5E", nullptr));
        missionsTitleLabel->setText(QCoreApplication::translate("Dashbord", "MISSIONS", nullptr));
        addMissionButton->setText(QCoreApplication::translate("Dashbord", "+ Add Mission", nullptr));
        removeMissionButton->setText(QCoreApplication::translate("Dashbord", "- Remove Mission", nullptr));
        saveMissionButton->setText(QCoreApplication::translate("Dashbord", "Save Mission", nullptr));
        missionDashboardTitleLabel->setText(QCoreApplication::translate("Dashbord", "MISSION DASHBOARD", nullptr));
        missionDetailsGroupBox->setTitle(QCoreApplication::translate("Dashbord", "Mission Details", nullptr));
        missionNameLabel->setText(QCoreApplication::translate("Dashbord", "Name:", nullptr));
        missionNameEdit->setPlaceholderText(QCoreApplication::translate("Dashbord", "Mission name...", nullptr));
        missionStatusLabel->setText(QCoreApplication::translate("Dashbord", "Status:", nullptr));
        missionStatusCombo->setItemText(0, QCoreApplication::translate("Dashbord", "Planned", nullptr));
        missionStatusCombo->setItemText(1, QCoreApplication::translate("Dashbord", "Active", nullptr));
        missionStatusCombo->setItemText(2, QCoreApplication::translate("Dashbord", "Completed", nullptr));
        missionStatusCombo->setItemText(3, QCoreApplication::translate("Dashbord", "Failed", nullptr));
        missionStatusCombo->setItemText(4, QCoreApplication::translate("Dashbord", "Archived", nullptr));

        missionDescriptionLabel->setText(QCoreApplication::translate("Dashbord", "Description:", nullptr));
        missionDescriptionEdit->setPlaceholderText(QCoreApplication::translate("Dashbord", "Mission description...", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dashbord: public Ui_Dashbord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DASHBORD_H
