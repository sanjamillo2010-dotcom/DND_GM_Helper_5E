#ifndef MISSIONDASHBORD_H
#define MISSIONDASHBORD_H

#include <QJsonObject>
#include <QMainWindow>

#include "campaign.h"
#include "missionworkspaceview.h"

    QT_BEGIN_NAMESPACE

namespace Ui
{
class MissionDashbord;
}

QT_END_NAMESPACE

class QGraphicsScene;
class QGraphicsProxyWidget;
class QAction;
class QWidget;

class MissionDashbord : public QMainWindow
{
    Q_OBJECT

public:
    explicit MissionDashbord(
        Campaign* campaign,
        int missionIndex,
        QWidget* parent = nullptr
        );

    ~MissionDashbord();

    void Set_Mission_Index(int index);

private slots:
    void Add_NPC();
    void Add_Map();
    void Add_Battle();
    void Add_Note();

    void Save_Mission();
    void Close_Mission();

private:
    void Load_Mission();

    void Save_Workspace_To_Mission();

    Missions::DashboardInfo
    Capture_Dashboard() const;

    QGraphicsProxyWidget*
    Create_NPC_Widget(
        const QPointF& position,
        const Missions::WorkspaceObject* savedObject = nullptr
        );

    QGraphicsProxyWidget*
    Create_Workspace_Object(
        const QString& type,
        const QString& title,
        const QString& text,
        const QPointF& position,
        const Missions::WorkspaceObject* savedObject = nullptr
        );

    void Ensure_Widget_Names(
        QWidget* widget
        ) const;

    QJsonObject Save_Widget_State(
        QWidget* widget
        ) const;

    void Restore_Widget_State(
        QWidget* widget,
        const QJsonObject& state
        );

private:
    Ui::MissionDashbord* ui;

    Campaign* m_campaign;

    int m_missionIndex;

    QGraphicsScene* m_scene;

    QAction* m_addNPCAction;
    QAction* m_addMapAction;
    QAction* m_addBattleAction;
    QAction* m_addNoteAction;
};

#endif // MISSIONDASHBORD_H
