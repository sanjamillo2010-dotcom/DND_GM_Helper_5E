#include "../include/missions.h"

#include <QJsonObject>
#include <QJsonValue>

Missions::Missions()
{
}

void Missions::Add_Mission(
    const QString& name,
    const QString& description,
    const QString& status)
{
    if (name.trimmed().isEmpty())
        return;

    Entry mission;

    mission.Name = name;
    mission.Description = description;
    mission.Status = status;

    mission.Dashboard.Zoom = 1.0;
    mission.Dashboard.CenterX = 0.0;
    mission.Dashboard.CenterY = 0.0;

    m_missions.append(mission);
}

void Missions::Remove_Mission(int index)
{
    if (index < 0 || index >= m_missions.size())
        return;

    m_missions.removeAt(index);
}

void Missions::Update_Mission(
    int index,
    const QString& name,
    const QString& description,
    const QString& status)
{
    if (index < 0 || index >= m_missions.size())
        return;

    m_missions[index].Name = name;
    m_missions[index].Description = description;
    m_missions[index].Status = status;
}

void Missions::Set_Mission_Dashboard(
    int index,
    const DashboardInfo& dashboard)
{
    if (index < 0 || index >= m_missions.size())
        return;

    m_missions[index].Dashboard = dashboard;
}

int Missions::Get_Mission_Count() const
{
    return m_missions.size();
}

Missions::Entry Missions::Get_Mission(int index) const
{
    if (index < 0 || index >= m_missions.size())
        return Entry();

    return m_missions.at(index);
}

QList<Missions::Entry> Missions::Get_Missions() const
{
    return m_missions;
}

void Missions::Clear()
{
    m_missions.clear();
}

QJsonArray Missions::To_Json() const
{
    QJsonArray missionsArray;

    for (const Entry& mission : m_missions)
    {
        QJsonObject missionObject;

        missionObject["name"] = mission.Name;
        missionObject["description"] = mission.Description;
        missionObject["status"] = mission.Status;

        QJsonObject dashboardObject;

        dashboardObject["zoom"] =
            mission.Dashboard.Zoom;

        dashboardObject["center_x"] =
            mission.Dashboard.CenterX;

        dashboardObject["center_y"] =
            mission.Dashboard.CenterY;

        QJsonArray objectsArray;

        for (const WorkspaceObject& object :
             mission.Dashboard.Objects)
        {
            QJsonObject objectJson;

            objectJson["id"] = object.Id;
            objectJson["type"] = object.Type;
            objectJson["title"] = object.Title;
            objectJson["text"] = object.Text;

            objectJson["x"] = object.X;
            objectJson["y"] = object.Y;

            objectJson["width"] = object.Width;
            objectJson["height"] = object.Height;

            objectJson["z"] = object.Z;

            objectJson["widget_state"] =
                object.WidgetState;

            objectsArray.append(objectJson);
        }

        dashboardObject["objects"] = objectsArray;

        missionObject["dashboard"] = dashboardObject;

        missionsArray.append(missionObject);
    }

    return missionsArray;
}

bool Missions::From_Json(const QJsonArray& array)
{
    m_missions.clear();

    for (const QJsonValue& value : array)
    {
        if (!value.isObject())
            continue;

        const QJsonObject missionObject =
            value.toObject();

        Entry mission;

        mission.Name =
            missionObject["name"].toString();

        mission.Description =
            missionObject["description"].toString();

        mission.Status =
            missionObject["status"].toString("Planned");

        if (missionObject.contains("dashboard") &&
            missionObject["dashboard"].isObject())
        {
            const QJsonObject dashboardObject =
                missionObject["dashboard"].toObject();

            mission.Dashboard.Zoom =
                dashboardObject["zoom"].toDouble(1.0);

            mission.Dashboard.CenterX =
                dashboardObject["center_x"].toDouble(0.0);

            mission.Dashboard.CenterY =
                dashboardObject["center_y"].toDouble(0.0);

            if (dashboardObject.contains("objects") &&
                dashboardObject["objects"].isArray())
            {
                const QJsonArray objectsArray =
                    dashboardObject["objects"].toArray();

                for (const QJsonValue& objectValue :
                     objectsArray)
                {
                    if (!objectValue.isObject())
                        continue;

                    const QJsonObject objectJson =
                        objectValue.toObject();

                    WorkspaceObject object;

                    object.Id =
                        objectJson["id"].toString();

                    object.Type =
                        objectJson["type"].toString();

                    object.Title =
                        objectJson["title"].toString();

                    object.Text =
                        objectJson["text"].toString();

                    object.X =
                        objectJson["x"].toDouble();

                    object.Y =
                        objectJson["y"].toDouble();

                    object.Width =
                        objectJson["width"].toInt(300);

                    object.Height =
                        objectJson["height"].toInt(200);

                    object.Z =
                        objectJson["z"].toDouble();

                    if (objectJson.contains("widget_state") &&
                        objectJson["widget_state"].isObject())
                    {
                        object.WidgetState =
                            objectJson["widget_state"].toObject();
                    }

                    if (object.Type.isEmpty())
                        continue;

                    mission.Dashboard.Objects.append(object);
                }
            }
        }

        if (!mission.Name.isEmpty())
            m_missions.append(mission);
    }

    return true;
}
