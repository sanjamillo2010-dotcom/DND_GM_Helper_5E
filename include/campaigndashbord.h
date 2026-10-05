#ifndef CAMPAIGNDASHBORD_H
#define CAMPAIGNDASHBORD_H

#include <QMainWindow>
#include <QString>

#include "../include/campaign.h"

    QT_BEGIN_NAMESPACE
namespace Ui
{
class CampaignDashbord;
}
QT_END_NAMESPACE

class Dashbord;

class CampaignDashbord : public QMainWindow
{
    Q_OBJECT

public:
    explicit CampaignDashbord(QWidget* parent = nullptr);
    ~CampaignDashbord();

private slots:
    void New_Campaign();
    void Open_Campaign();
    void Open_Missions();
    void Save_Campaign();

private:
    void Update_Campaign_From_UI();
    void Update_UI_From_Campaign();
    void Update_File_Location();

private:
    Ui::CampaignDashbord* ui;

    Campaign m_campaign;

    Dashbord* m_missionsDashboard;

    QString m_campaignFilePath;
};

#endif // CAMPAIGNDASHBORD_H
