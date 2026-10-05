#ifndef NPCCREATORDIALOG_H
#define NPCCREATORDIALOG_H

#include <QDialog>

#include "npc.h"

class QComboBox;
class QLineEdit;
class QTextEdit;

class NPCCreatorDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NPCCreatorDialog(
        QWidget* parent = nullptr
        );

    DND_GM_Helper_5E::NPC::NPC Get_NPC() const;

private slots:
    void Reroll_All();
    void Reroll_Race();
    void Reroll_Prenom();
    void Reroll_Nom();
    void Reroll_Apparence();
    void Reroll_Personnalite();
    void Reroll_Motivation();
    void Reroll_Accroche();

private:
    void Generate_Initial_NPC();
    void Update_UI_From_NPC();
    void Update_NPC_From_UI();

private:
    QComboBox* m_raceEdit;

    QLineEdit* m_prenomEdit;
    QLineEdit* m_nomEdit;

    QLineEdit* m_apparenceEdit;
    QTextEdit* m_apparenceDescriptionEdit;

    QLineEdit* m_personnaliteEdit;
    QTextEdit* m_personnaliteDescriptionEdit;

    QLineEdit* m_motivationEdit;
    QTextEdit* m_motivationDescriptionEdit;

    QLineEdit* m_accrocheEdit;
    QTextEdit* m_accrocheDescriptionEdit;

    DND_GM_Helper_5E::NPC::NPC m_npc;
};

#endif // NPCCREATORDIALOG_H
