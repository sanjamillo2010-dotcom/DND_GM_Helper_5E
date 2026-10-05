#ifndef CAMPAIGN_H
#define CAMPAIGN_H

#include "missions.h"

#include <QString>
#include <QJsonObject>

class Campaign
{
public:
    Campaign();

    QString Name;
    QString Description;
    QString GM_information;
    QString Created_date;

    // Path of the active .dndcampaign file.
    QString File_Path;

    Missions& missions();
    const Missions& missions() const;

    QJsonObject To_Json() const;
    bool From_Json(const QJsonObject& object);

    bool Save_To_File(const QString& filePath);
    bool Load_From_File(const QString& filePath);

private:
    Missions m_missions;
};

#endif // CAMPAIGN_H
