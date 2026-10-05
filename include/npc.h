#ifndef NPC_H
#define NPC_H

#include <QString>
#include <QStringList>

#include "../include/utils.h"

namespace DND_GM_Helper_5E {
namespace NPC {

class NPC
{
public:
    QString Prenom;
    QString Nom;

    QString Race;

    QString Apparence;
    QString Apparence_Descripion;
    int Apparence_Index;

    QString Personnalite;
    QString Personnalite_Descripion;
    int Personnalite_Index;

    QString Motivation;
    QString Motivation_Descripion;
    int Motivation_Index;

    QString Accroche;
    QString Accroche_Descripion;
    int Accroche_Index;

    NPC(QString iPrenom , QString iNom , QString iRace ,
        QString iApparence, QString iApparence_Descripion, int iApparence_Index,
        QString iPersonnalite, QString iPersonnalite_Descripion, int iPersonnalite_Index,
        QString iMotivation, QString iMotivation_Descripion, int iMotivation_Index,
        QString iAccroche, QString iAccroche_Descripion, int iAccroche_Index);

    void Set_Random_Race();
    void Set_Random_Prenom(QString Race);
    void Set_Random_Name(QString Race);
    void Set_Random_Apparence();
    void Set_Random_Personnalite();
    void Set_Random_Motivation();
    void Set_Random_Accroche();
    void Print_NPC_Debug();
};

} // namespace NPC
} // namespace DND_GM_Helper_5E

#endif // NPC_H
