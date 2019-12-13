#include "gui_effect.h"

#include <QDebug>
#include <QPainter>
#include <QGraphicsScene>

#include "gui_port.h"
#include "ports/port.h"

GUI_effect::GUI_effect(QString name, QGraphicsItem* parent) : QGraphicsItem(parent)
{
    baseRect = QRectF(-200,-200,200,200);
    title = name;


}

GUI_port* GUI_effect::addPort(Port *port, int portType)
{
    int dy;
    int dx;

    //TODO worth adding a check of port type.

    QPointF* point = new QPointF();
    GUI_port* new_port = new GUI_port(*point, this);

    //Add port to GUI
    switch (portType){
    case 1:
        //InPort
        InPorts.append(new_port);
        dy = 30 + 30 * InPorts.length();
        dx = 30;
        break;
    case 2:
        //OutPort
        OutPorts.append(new_port);
        dy = 30 + 30 * OutPorts.length();
        dx = 150;
        break;
    default:
        //unregistered type
        dx = 10;
        dy = 10;
    }

    point->setX(boundingRect().x()+dx);
    point->setY(boundingRect().y()+dy);
    new_port->setBasePoint(*point);
    return new_port;
}

QList<GUI_port*> GUI_effect::addPort(QList<Port*> portList, int portType)
{
    QList<GUI_port*> list = QList<GUI_port*>();
    for (Port* p : portList){
        list.append(addPort(p, portType));
    }
    return list;
}

QList<GUI_port *> GUI_effect::getPorts()
{
    QList<GUI_port*> list = QList<GUI_port*>();
    list.append(InPorts);
    list.append(OutPorts);
    return list;
}


QRectF GUI_effect::boundingRect() const
{
    return baseRect;
}

void GUI_effect::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QColor(0,0,0));

    //Set up title properly with boundingrect and font
    QFont font = painter->font();
    font.setPixelSize(20);
    painter->setFont(font);
    
    //painter->drawPath()

    /*
    for (GUI_port* p : InPorts){
        p->update();
    }
    for (GUI_port* p : OutPorts){
        p->update();
    }
    */

    painter->drawRect(baseRect);
    //painter->drawRoundedRect(-10,-10,20,20,5,5);
    painter->drawText(QPoint(baseRect.topLeft().x()+10, baseRect.topLeft().y()+10), title);
}

