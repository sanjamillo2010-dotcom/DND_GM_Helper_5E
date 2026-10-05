#include "../include/npccreatordialog.h"

#include <QComboBox>
#include <QDialogButtonBox>
#include <QFormLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QTextEdit>
#include <QVBoxLayout>

NPCCreatorDialog::NPCCreatorDialog(
    QWidget* parent
    )
    : QDialog(parent)
    , m_raceEdit(new QComboBox(this))
    , m_prenomEdit(new QLineEdit(this))
    , m_nomEdit(new QLineEdit(this))
    , m_apparenceEdit(new QLineEdit(this))
    , m_apparenceDescriptionEdit(new QTextEdit(this))
    , m_personnaliteEdit(new QLineEdit(this))
    , m_personnaliteDescriptionEdit(new QTextEdit(this))
    , m_motivationEdit(new QLineEdit(this))
    , m_motivationDescriptionEdit(new QTextEdit(this))
    , m_accrocheEdit(new QLineEdit(this))
    , m_accrocheDescriptionEdit(new QTextEdit(this))
    , m_npc(
          "",
          "",
          "",
          "",
          "",
          0,
          "",
          "",
          0,
          "",
          "",
          0,
          "",
          "",
          0
          )
{
    setWindowTitle("NPC Creator");
    resize(720, 820);

    QVBoxLayout* mainLayout =
        new QVBoxLayout(this);

    QLabel* titleLabel =
        new QLabel(
            "NPC Creator",
            this
            );

    titleLabel->setStyleSheet(
        "font-size: 22px;"
        "font-weight: bold;"
        );

    mainLayout->addWidget(titleLabel);

    /*
     * =========================================================
     * IDENTITY
     * =========================================================
     */

    QGroupBox* identityGroup =
        new QGroupBox(
            "Identity",
            this
            );

    QFormLayout* identityLayout =
        new QFormLayout(
            identityGroup
            );

    m_raceEdit->addItems({
        "Humain",
        "Haut-elfe",
        "Elfe des bois",
        "Elfe noir",
        "Halfelin pied-leger",
        "Halfling robuste",
        "Nain des colline",
        "Nain des montagnes",
        "Demi-elfe",
        "Demi-orc",
        "Drakeide",
        "Gnome des forets",
        "Gnome des rochs",
        "Tieffelin"
    });

    QHBoxLayout* raceLayout =
        new QHBoxLayout();

    raceLayout->addWidget(
        m_raceEdit
        );

    QPushButton* raceReroll =
        new QPushButton(
            "Reroll",
            this
            );

    raceLayout->addWidget(
        raceReroll
        );

    identityLayout->addRow(
        "Race:",
        raceLayout
        );

    QHBoxLayout* prenomLayout =
        new QHBoxLayout();

    prenomLayout->addWidget(
        m_prenomEdit
        );

    QPushButton* prenomReroll =
        new QPushButton(
            "Reroll",
            this
            );

    prenomLayout->addWidget(
        prenomReroll
        );

    identityLayout->addRow(
        "First Name:",
        prenomLayout
        );

    QHBoxLayout* nomLayout =
        new QHBoxLayout();

    nomLayout->addWidget(
        m_nomEdit
        );

    QPushButton* nomReroll =
        new QPushButton(
            "Reroll",
            this
            );

    nomLayout->addWidget(
        nomReroll
        );

    identityLayout->addRow(
        "Last Name:",
        nomLayout
        );

    mainLayout->addWidget(
        identityGroup
        );

    /*
     * =========================================================
     * APPEARANCE
     * =========================================================
     */

    QGroupBox* appearanceGroup =
        new QGroupBox(
            "Appearance",
            this
            );

    QVBoxLayout* appearanceLayout =
        new QVBoxLayout(
            appearanceGroup
            );

    QHBoxLayout* appearanceHeader =
        new QHBoxLayout();

    appearanceHeader->addWidget(
        m_apparenceEdit
        );

    QPushButton* appearanceReroll =
        new QPushButton(
            "Reroll",
            this
            );

    appearanceHeader->addWidget(
        appearanceReroll
        );

    appearanceLayout->addLayout(
        appearanceHeader
        );

    m_apparenceDescriptionEdit
        ->setMaximumHeight(90);

    appearanceLayout->addWidget(
        m_apparenceDescriptionEdit
        );

    mainLayout->addWidget(
        appearanceGroup
        );

    /*
     * =========================================================
     * PERSONALITY
     * =========================================================
     */

    QGroupBox* personalityGroup =
        new QGroupBox(
            "Personality",
            this
            );

    QVBoxLayout* personalityLayout =
        new QVBoxLayout(
            personalityGroup
            );

    QHBoxLayout* personalityHeader =
        new QHBoxLayout();

    personalityHeader->addWidget(
        m_personnaliteEdit
        );

    QPushButton* personalityReroll =
        new QPushButton(
            "Reroll",
            this
            );

    personalityHeader->addWidget(
        personalityReroll
        );

    personalityLayout->addLayout(
        personalityHeader
        );

    m_personnaliteDescriptionEdit
        ->setMaximumHeight(90);

    personalityLayout->addWidget(
        m_personnaliteDescriptionEdit
        );

    mainLayout->addWidget(
        personalityGroup
        );

    /*
     * =========================================================
     * MOTIVATION
     * =========================================================
     */

    QGroupBox* motivationGroup =
        new QGroupBox(
            "Motivation",
            this
            );

    QVBoxLayout* motivationLayout =
        new QVBoxLayout(
            motivationGroup
            );

    QHBoxLayout* motivationHeader =
        new QHBoxLayout();

    motivationHeader->addWidget(
        m_motivationEdit
        );

    QPushButton* motivationReroll =
        new QPushButton(
            "Reroll",
            this
            );

    motivationHeader->addWidget(
        motivationReroll
        );

    motivationLayout->addLayout(
        motivationHeader
        );

    m_motivationDescriptionEdit
        ->setMaximumHeight(90);

    motivationLayout->addWidget(
        m_motivationDescriptionEdit
        );

    mainLayout->addWidget(
        motivationGroup
        );

    /*
     * =========================================================
     * HOOK
     * =========================================================
     */

    QGroupBox* hookGroup =
        new QGroupBox(
            "Hook",
            this
            );

    QVBoxLayout* hookLayout =
        new QVBoxLayout(
            hookGroup
            );

    QHBoxLayout* hookHeader =
        new QHBoxLayout();

    hookHeader->addWidget(
        m_accrocheEdit
        );

    QPushButton* hookReroll =
        new QPushButton(
            "Reroll",
            this
            );

    hookHeader->addWidget(
        hookReroll
        );

    hookLayout->addLayout(
        hookHeader
        );

    m_accrocheDescriptionEdit
        ->setMaximumHeight(90);

    hookLayout->addWidget(
        m_accrocheDescriptionEdit
        );

    mainLayout->addWidget(
        hookGroup
        );

    /*
     * =========================================================
     * BUTTONS
     * =========================================================
     */

    QHBoxLayout* buttonsLayout =
        new QHBoxLayout();

    QPushButton* rerollAllButton =
        new QPushButton(
            "Reroll All",
            this
            );

    QPushButton* cancelButton =
        new QPushButton(
            "Cancel",
            this
            );

    QPushButton* okButton =
        new QPushButton(
            "OK",
            this
            );

    buttonsLayout->addWidget(
        rerollAllButton
        );

    buttonsLayout->addStretch();

    buttonsLayout->addWidget(
        cancelButton
        );

    buttonsLayout->addWidget(
        okButton
        );

    mainLayout->addLayout(
        buttonsLayout
        );

    /*
     * =========================================================
     * CONNECTIONS
     * =========================================================
     */

    connect(
        raceReroll,
        &QPushButton::clicked,
        this,
        &NPCCreatorDialog::Reroll_Race
        );

    connect(
        prenomReroll,
        &QPushButton::clicked,
        this,
        &NPCCreatorDialog::Reroll_Prenom
        );

    connect(
        nomReroll,
        &QPushButton::clicked,
        this,
        &NPCCreatorDialog::Reroll_Nom
        );

    connect(
        appearanceReroll,
        &QPushButton::clicked,
        this,
        &NPCCreatorDialog::Reroll_Apparence
        );

    connect(
        personalityReroll,
        &QPushButton::clicked,
        this,
        &NPCCreatorDialog::Reroll_Personnalite
        );

    connect(
        motivationReroll,
        &QPushButton::clicked,
        this,
        &NPCCreatorDialog::Reroll_Motivation
        );

    connect(
        hookReroll,
        &QPushButton::clicked,
        this,
        &NPCCreatorDialog::Reroll_Accroche
        );

    connect(
        rerollAllButton,
        &QPushButton::clicked,
        this,
        &NPCCreatorDialog::Reroll_All
        );

    connect(
        cancelButton,
        &QPushButton::clicked,
        this,
        &QDialog::reject
        );

    connect(
        okButton,
        &QPushButton::clicked,
        this,
        [this]()
        {
            Update_NPC_From_UI();
            accept();
        }
        );

    /*
     * Race selected manually.
     * Generate a compatible name.
     */

    connect(
        m_raceEdit,
        &QComboBox::currentTextChanged,
        this,
        [this](const QString& race)
        {
            if (race.isEmpty())
                return;

            m_npc.Race = race;

            m_npc.Set_Random_Prenom(
                race
                );

            m_npc.Set_Random_Name(
                race
                );

            Update_UI_From_NPC();
        }
        );

    /*
     * Generate the first NPC immediately.
     */

    Generate_Initial_NPC();
}

void NPCCreatorDialog::Generate_Initial_NPC()
{
    m_npc.Set_Random_Race();

    m_npc.Set_Random_Prenom(
        m_npc.Race
        );

    m_npc.Set_Random_Name(
        m_npc.Race
        );

    m_npc.Set_Random_Apparence();
    m_npc.Set_Random_Personnalite();
    m_npc.Set_Random_Motivation();
    m_npc.Set_Random_Accroche();

    Update_UI_From_NPC();
}

void NPCCreatorDialog::Update_UI_From_NPC()
{
    int raceIndex =
        m_raceEdit->findText(
            m_npc.Race
            );

    if (raceIndex >= 0)
    {
        m_raceEdit->blockSignals(true);

        m_raceEdit->setCurrentIndex(
            raceIndex
            );

        m_raceEdit->blockSignals(false);
    }

    m_prenomEdit->setText(
        m_npc.Prenom
        );

    m_nomEdit->setText(
        m_npc.Nom
        );

    m_apparenceEdit->setText(
        m_npc.Apparence
        );

    m_apparenceDescriptionEdit
        ->setPlainText(
            m_npc.Apparence_Descripion
            );

    m_personnaliteEdit->setText(
        m_npc.Personnalite
        );

    m_personnaliteDescriptionEdit
        ->setPlainText(
            m_npc.Personnalite_Descripion
            );

    m_motivationEdit->setText(
        m_npc.Motivation
        );

    m_motivationDescriptionEdit
        ->setPlainText(
            m_npc.Motivation_Descripion
            );

    m_accrocheEdit->setText(
        m_npc.Accroche
        );

    m_accrocheDescriptionEdit
        ->setPlainText(
            m_npc.Accroche_Descripion
            );
}

void NPCCreatorDialog::Update_NPC_From_UI()
{
    m_npc.Race =
        m_raceEdit->currentText();

    m_npc.Prenom =
        m_prenomEdit->text();

    m_npc.Nom =
        m_nomEdit->text();

    m_npc.Apparence =
        m_apparenceEdit->text();

    m_npc.Apparence_Descripion =
        m_apparenceDescriptionEdit
            ->toPlainText();

    m_npc.Personnalite =
        m_personnaliteEdit->text();

    m_npc.Personnalite_Descripion =
        m_personnaliteDescriptionEdit
            ->toPlainText();

    m_npc.Motivation =
        m_motivationEdit->text();

    m_npc.Motivation_Descripion =
        m_motivationDescriptionEdit
            ->toPlainText();

    m_npc.Accroche =
        m_accrocheEdit->text();

    m_npc.Accroche_Descripion =
        m_accrocheDescriptionEdit
            ->toPlainText();
}

DND_GM_Helper_5E::NPC::NPC
NPCCreatorDialog::Get_NPC() const
{
    return m_npc;
}

void NPCCreatorDialog::Reroll_All()
{
    m_npc.Set_Random_Race();

    m_npc.Set_Random_Prenom(
        m_npc.Race
        );

    m_npc.Set_Random_Name(
        m_npc.Race
        );

    m_npc.Set_Random_Apparence();
    m_npc.Set_Random_Personnalite();
    m_npc.Set_Random_Motivation();
    m_npc.Set_Random_Accroche();

    Update_UI_From_NPC();
}

void NPCCreatorDialog::Reroll_Race()
{
    m_npc.Set_Random_Race();

    m_npc.Set_Random_Prenom(
        m_npc.Race
        );

    m_npc.Set_Random_Name(
        m_npc.Race
        );

    Update_UI_From_NPC();
}

void NPCCreatorDialog::Reroll_Prenom()
{
    m_npc.Set_Random_Prenom(
        m_npc.Race
        );

    Update_UI_From_NPC();
}

void NPCCreatorDialog::Reroll_Nom()
{
    m_npc.Set_Random_Name(
        m_npc.Race
        );

    Update_UI_From_NPC();
}

void NPCCreatorDialog::Reroll_Apparence()
{
    m_npc.Set_Random_Apparence();

    Update_UI_From_NPC();
}

void NPCCreatorDialog::Reroll_Personnalite()
{
    m_npc.Set_Random_Personnalite();

    Update_UI_From_NPC();
}

void NPCCreatorDialog::Reroll_Motivation()
{
    m_npc.Set_Random_Motivation();

    Update_UI_From_NPC();
}

void NPCCreatorDialog::Reroll_Accroche()
{
    m_npc.Set_Random_Accroche();

    Update_UI_From_NPC();
}
