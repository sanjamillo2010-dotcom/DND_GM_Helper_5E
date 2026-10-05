#include "../include/missionworkspaceview.h"

#include <QMouseEvent>
#include <QPainter>
#include <QScrollBar>
#include <QWheelEvent>

MissionWorkspaceView::MissionWorkspaceView(QWidget* parent)
    : QGraphicsView(parent)
    , m_panning(false)
{
    setRenderHint(QPainter::Antialiasing, true);
    setRenderHint(QPainter::SmoothPixmapTransform, true);

    setDragMode(QGraphicsView::NoDrag);

    setTransformationAnchor(QGraphicsView::AnchorUnderMouse);
    setResizeAnchor(QGraphicsView::AnchorUnderMouse);

    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    setSceneRect(-5000, -5000, 10000, 10000);
}

void MissionWorkspaceView::wheelEvent(QWheelEvent* event)
{
    if (event->angleDelta().y() == 0)
        return;

    const qreal factor =
        event->angleDelta().y() > 0 ? 1.15 : 0.87;

    scale(factor, factor);
}

void MissionWorkspaceView::mousePressEvent(QMouseEvent* event)
{
    if (event->button() == Qt::MiddleButton)
    {
        m_panning = true;
        m_lastMousePosition = event->pos();

        setCursor(Qt::ClosedHandCursor);

        event->accept();
        return;
    }

    QGraphicsView::mousePressEvent(event);
}

void MissionWorkspaceView::mouseMoveEvent(QMouseEvent* event)
{
    if (m_panning)
    {
        const QPoint delta =
            event->pos() - m_lastMousePosition;

        horizontalScrollBar()->setValue(
            horizontalScrollBar()->value() - delta.x()
            );

        verticalScrollBar()->setValue(
            verticalScrollBar()->value() - delta.y()
            );

        m_lastMousePosition = event->pos();

        event->accept();
        return;
    }

    QGraphicsView::mouseMoveEvent(event);
}

void MissionWorkspaceView::mouseReleaseEvent(QMouseEvent* event)
{
    if (event->button() == Qt::MiddleButton)
    {
        m_panning = false;
        setCursor(Qt::ArrowCursor);

        event->accept();
        return;
    }

    QGraphicsView::mouseReleaseEvent(event);
}

void MissionWorkspaceView::drawBackground(
    QPainter* painter,
    const QRectF& rect)
{
    painter->fillRect(rect, QColor("#202020"));

    const int gridSize = 50;

    QPen gridPen(QColor("#303030"));
    gridPen.setWidth(1);

    painter->setPen(gridPen);

    const int left =
        static_cast<int>(rect.left()) -
        (static_cast<int>(rect.left()) % gridSize);

    const int top =
        static_cast<int>(rect.top()) -
        (static_cast<int>(rect.top()) % gridSize);

    for (int x = left; x < rect.right(); x += gridSize)
    {
        painter->drawLine(
            x,
            rect.top(),
            x,
            rect.bottom()
            );
    }

    for (int y = top; y < rect.bottom(); y += gridSize)
    {
        painter->drawLine(
            rect.left(),
            y,
            rect.right(),
            y
            );
    }
}
