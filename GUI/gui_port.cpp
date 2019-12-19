#include "gui_port.h"

#include <QPainter>
#include <QDebug>

#include "gui_effect.h"
#include "ports/port.h"

GUI_port::GUI_port(QPointF basePoint, Port* port, GUI_effect *parent) : QGraphicsItem(parent)
  , hoverBox(new QRectF(basePoint - QPointF(30,30), QSize(60,60)))
  , portBox(new QRectF(basePoint - QPointF(10,10), QSize(20,20)))
{
    setData(0,"port");
    this->parent = parent;
    this->port = port;
    setAcceptHoverEvents(true);
}

void GUI_port::setHoverBoxVisible(bool vis)
{
    hoverBoxVisible = vis;
    update();
}

void GUI_port::setBasePoint(QPointF basePoint)
{
    hoverBox->~QRectF();
    portBox->~QRectF();
    hoverBox = new QRectF(basePoint - QPointF(30,30), QSize(60,60));
    portBox = new  QRectF(basePoint - QPointF(10,10), QSize(20,20));
}

QPointF GUI_port::center()
{
    return portBox->center() + parent->scenePos();
}

Port *GUI_port::getPort() const
{
    return port;
}

void GUI_port::setPort(Port *value)
{
    port = value;
}

GUI_line *GUI_port::getConnection()
{
    return connection;
}

void GUI_port::setConnection(GUI_line *line)
{
    connection = line;
}

QRectF GUI_port::boundingRect() const
{
    return *hoverBox;
}

void GUI_port::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QColor color_blue = QColor(100,100,255,150);
    QColor color_black = QColor(0,0,0);
    QPen pen = QPen(color_blue, 2);
    painter->setPen(pen);

    if (hoverBoxVisible){
        painter->drawRect(*hoverBox);
    }
    pen.setColor(color_black);
    painter->setPen(pen);
    painter->drawRect(*portBox);
}

bool GUI_port::contains(const QPointF &point) const
{

    qDebug() << "HoverBox TopLeft: " << hoverBox->topLeft();
    qDebug() << "HoverBox BottomRight" << hoverBox->bottomRight();
    qDebug() << "Point Contained? : " << point;
    qDebug() << "Scenepos: " << scenePos();
    bool b = hoverBox->contains(point);
    qDebug() << b;
    return b;
}

void GUI_port::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
    setHoverBoxVisible(true);
}

void GUI_port::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    setHoverBoxVisible(false);
}




