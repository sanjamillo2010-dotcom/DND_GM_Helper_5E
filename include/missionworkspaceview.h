#ifndef MISSIONWORKSPACEVIEW_H
#define MISSIONWORKSPACEVIEW_H

#include <QGraphicsView>

class MissionWorkspaceView : public QGraphicsView
{
public:
    explicit MissionWorkspaceView(QWidget* parent = nullptr);

protected:
    void wheelEvent(QWheelEvent* event) override;
    void mousePressEvent(QMouseEvent* event) override;
    void mouseMoveEvent(QMouseEvent* event) override;
    void mouseReleaseEvent(QMouseEvent* event) override;
    void drawBackground(QPainter* painter, const QRectF& rect) override;

private:
    bool m_panning;
    QPoint m_lastMousePosition;
};

#endif // MISSIONWORKSPACEVIEW_H
