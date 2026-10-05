#include "include/campaigndashbord.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QTranslator translator;

    const QStringList uiLanguages =
        QLocale::system().uiLanguages();

    for (const QString& locale : uiLanguages)
    {
        const QString baseName =
            "DND_GM_Helper_5E_" +
            QLocale(locale).name();

        if (translator.load(
                ":/i18n/" + baseName))
        {
            a.installTranslator(&translator);
            break;
        }
    }

    CampaignDashbord w;
    w.show();

    return a.exec();
}
