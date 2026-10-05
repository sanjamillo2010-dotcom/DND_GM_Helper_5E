#include "../include/campaign.h"

#include <QFile>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonParseError>

Campaign::Campaign()
{
}

Missions& Campaign::missions()
{
    return m_missions;
}

const Missions& Campaign::missions() const
{
    return m_missions;
}

QJsonObject Campaign::To_Json() const
{
    QJsonObject object;

    object["name"] = Name;

    object["description"] = Description;

    object["gm_information"] = GM_information;

    object["created_date"] = Created_date;

    object["missions"] = m_missions.To_Json();

    return object;
}

bool Campaign::From_Json(
    const QJsonObject& object)
{
    Name = object["name"].toString();

    Description = object["description"].toString();

    GM_information = object["gm_information"].toString();

    Created_date = object["created_date"].toString();

    m_missions.Clear();

    if (object.contains("missions") &&
        object["missions"].isArray())
    {
        return m_missions.From_Json(object["missions"].toArray());
    }

    return true;
}

bool Campaign::Save_To_File(
    const QString& filePath)
{
    if (filePath.isEmpty())
        return false;

    const QJsonDocument document(To_Json());

    QFile file(filePath);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        return false;
    }

    const QByteArray data = document.toJson(QJsonDocument::Indented);

    const qint64 written = file.write(data);

    file.close();

    if (written != data.size())
        return false;

    File_Path = filePath;

    return true;
}

bool Campaign::Load_From_File(
    const QString& filePath)
{
    if (filePath.isEmpty())
        return false;

    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly))
    {
        return false;
    }

    const QByteArray data = file.readAll();

    file.close();

    QJsonParseError parseError;

    const QJsonDocument document = QJsonDocument::fromJson(data, &parseError);

    if (parseError.error != QJsonParseError::NoError)
    {
        return false;
    }

    if (!document.isObject())
        return false;

    if (!From_Json(document.object()))
    {
        return false;
    }

    File_Path = filePath;

    return true;
}
