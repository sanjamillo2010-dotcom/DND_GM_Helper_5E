#ifndef DASHBORD_H
#define DASHBORD_H

#include <QMainWindow>

#include "../include/campaign.h"

    QT_BEGIN_NAMESPACE
namespace Ui
{
class Dashbord;
}
QT_END_NAMESPACE

class MissionDashbord;

class Dashbord : public QMainWindow
{
    Q_OBJECT

public:
    explicit Dashbord(
        Campaign* campaign,
        QWidget* parent = nullptr
        );

    ~Dashbord();

private slots:
    void Add_Mission();
    void Remove_Mission();
    void Update_Mission();
    void Mission_Selected(int row);
    void Open_Mission();

private:
    void Refresh_Mission_List();
    void Load_Mission(int index);

    void Save_Campaign_To_File();

private:
    Ui::Dashbord* ui;

    Campaign* m_campaign;

    MissionDashbord* m_missionDashboard;
};

#endif // DASHBORD_H
