#ifndef NPCWINDOW_H
#define NPCWINDOW_H

#include <QComboBox>
#include <QJsonObject>
#include <QLabel>
#include <QLineEdit>
#include <QMouseEvent>
#include <QPoint>
#include <QPushButton>
#include <QScrollArea>
#include <QTextEdit>
#include <QWidget>

#include "../include/npc.h"

class NPCWindow : public QWidget
{
    Q_OBJECT

public:
    explicit NPCWindow(
        const DND_GM_Helper_5E::NPC::NPC& npc,
        QWidget* parent = nullptr
        );

    const DND_GM_Helper_5E::NPC::NPC&
    Get_NPC() const;

    void Set_NPC(
        const DND_GM_Helper_5E::NPC::NPC& npc
        );

    QJsonObject To_Json() const;

    void From_Json(
        const QJsonObject& object
        );

signals:
    void npcUpdated(
        const DND_GM_Helper_5E::NPC::NPC& npc
        );

protected:
    void mousePressEvent(
        QMouseEvent* event
        ) override;

    void mouseMoveEvent(
        QMouseEvent* event
        ) override;

    void mouseReleaseEvent(
        QMouseEvent* event
        ) override;

private:
    void Update_UI_From_NPC();
    void Update_NPC_From_UI();
    void Update_Title();

private:
    QPoint dragPosition;
    bool dragging = false;
    bool minimized = false;

    DND_GM_Helper_5E::NPC::NPC npc;

    // Title bar
    QLabel* titleLabel;
    QPushButton* minimizeButton;
    QPushButton* closeButton;

    // Main content
    QWidget* contentWidget;
    QScrollArea* scrollArea;

    // Identity
    QLineEdit* prenomEdit;
    QLineEdit* nomEdit;
    QComboBox* raceEdit;

    // Appearance
    QLineEdit* apparenceEdit;
    QTextEdit* apparenceDescriptionEdit;

    // Personality
    QLineEdit* personnaliteEdit;
    QTextEdit* personnaliteDescriptionEdit;

    // Motivation
    QLineEdit* motivationEdit;
    QTextEdit* motivationDescriptionEdit;

    // Hook
    QLineEdit* accrocheEdit;
    QTextEdit* accrocheDescriptionEdit;
};

#endif // NPCWINDOW_H
