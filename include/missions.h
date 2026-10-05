#ifndef MISSIONS_H
#define MISSIONS_H

#include <QString>
#include <QList>
#include <QJsonArray>
#include <QJsonObject>
#include <QPointF>

class Missions
{
public:
    struct WorkspaceObject
    {
        QString Id;
        QString Type;
        QString Title;
        QString Text;

        qreal X = 0.0;
        qreal Y = 0.0;

        int Width = 300;
        int Height = 200;

        qreal Z = 0.0;

        QJsonObject WidgetState;
    };

    struct DashboardInfo
    {
        QList<WorkspaceObject> Objects;

        qreal Zoom = 1.0;
        qreal CenterX = 0.0;
        qreal CenterY = 0.0;
    };

    struct Entry
    {
        QString Name;
        QString Description;
        QString Status;

        DashboardInfo Dashboard;
    };

    Missions();

    void Add_Mission(
        const QString& name,
        const QString& description,
        const QString& status = "Planned"
        );

    void Remove_Mission(int index);

    void Update_Mission(
        int index,
        const QString& name,
        const QString& description,
        const QString& status
        );

    void Set_Mission_Dashboard(
        int index,
        const DashboardInfo& dashboard
        );

    int Get_Mission_Count() const;

    Entry Get_Mission(int index) const;

    QList<Entry> Get_Missions() const;

    void Clear();

    QJsonArray To_Json() const;
    bool From_Json(const QJsonArray& array);

private:
    QList<Entry> m_missions;
};

#endif // MISSIONS_H
