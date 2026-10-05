/********************************************************************************
** Form generated from reading UI file 'missiondashbord.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MISSIONDASHBORD_H
#define UI_MISSIONDASHBORD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "../include/missiondashbord.h"

QT_BEGIN_NAMESPACE

class Ui_MissionDashbord
{
public:
    QWidget *centralwidget;
    QVBoxLayout *mainLayout;
    QHBoxLayout *toolbarLayout;
    QLabel *missionTitleLabel;
    QToolButton *addObjectButton;
    QSpacerItem *toolbarSpacer;
    QPushButton *saveMissionButton;
    QPushButton *backButton;
    QLabel *missionDescriptionLabel;
    MissionWorkspaceView *workspaceView;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MissionDashbord)
    {
        if (MissionDashbord->objectName().isEmpty())
            MissionDashbord->setObjectName("MissionDashbord");
        MissionDashbord->resize(1400, 900);
        centralwidget = new QWidget(MissionDashbord);
        centralwidget->setObjectName("centralwidget");
        mainLayout = new QVBoxLayout(centralwidget);
        mainLayout->setObjectName("mainLayout");
        toolbarLayout = new QHBoxLayout();
        toolbarLayout->setObjectName("toolbarLayout");
        missionTitleLabel = new QLabel(centralwidget);
        missionTitleLabel->setObjectName("missionTitleLabel");
        missionTitleLabel->setStyleSheet(QString::fromUtf8("font-size: 22px;\n"
"font-weight: bold;\n"
"padding: 6px;"));

        toolbarLayout->addWidget(missionTitleLabel);

        addObjectButton = new QToolButton(centralwidget);
        addObjectButton->setObjectName("addObjectButton");
        addObjectButton->setToolButtonStyle(Qt::ToolButtonTextOnly);
        addObjectButton->setPopupMode(QToolButton::InstantPopup);

        toolbarLayout->addWidget(addObjectButton);

        toolbarSpacer = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);

        toolbarLayout->addItem(toolbarSpacer);

        saveMissionButton = new QPushButton(centralwidget);
        saveMissionButton->setObjectName("saveMissionButton");

        toolbarLayout->addWidget(saveMissionButton);

        backButton = new QPushButton(centralwidget);
        backButton->setObjectName("backButton");

        toolbarLayout->addWidget(backButton);


        mainLayout->addLayout(toolbarLayout);

        missionDescriptionLabel = new QLabel(centralwidget);
        missionDescriptionLabel->setObjectName("missionDescriptionLabel");
        missionDescriptionLabel->setWordWrap(true);

        mainLayout->addWidget(missionDescriptionLabel);

        workspaceView = new MissionWorkspaceView(centralwidget);
        workspaceView->setObjectName("workspaceView");
        workspaceView->setMinimumSize(QSize(0, 650));

        mainLayout->addWidget(workspaceView);

        MissionDashbord->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MissionDashbord);
        statusbar->setObjectName("statusbar");
        MissionDashbord->setStatusBar(statusbar);

        retranslateUi(MissionDashbord);

        QMetaObject::connectSlotsByName(MissionDashbord);
    } // setupUi

    void retranslateUi(QMainWindow *MissionDashbord)
    {
        MissionDashbord->setWindowTitle(QCoreApplication::translate("MissionDashbord", "Mission Dashboard", nullptr));
        missionTitleLabel->setText(QCoreApplication::translate("MissionDashbord", "Mission", nullptr));
        addObjectButton->setText(QCoreApplication::translate("MissionDashbord", "Add Object", nullptr));
        saveMissionButton->setText(QCoreApplication::translate("MissionDashbord", "Save", nullptr));
        backButton->setText(QCoreApplication::translate("MissionDashbord", "Back", nullptr));
        missionDescriptionLabel->setText(QCoreApplication::translate("MissionDashbord", "Mission description", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MissionDashbord: public Ui_MissionDashbord {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MISSIONDASHBORD_H
