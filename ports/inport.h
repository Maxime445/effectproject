#ifndef INPORT_H
#define INPORT_H

#include <QObject>
#include "port.h"

QT_BEGIN_NAMESPACE
class OutPort;
class QComboBox;
QT_END_NAMESPACE

class InPort : public Port
{
    Q_OBJECT
public:
    InPort(QString name, Effect* parent);

    int getConnectPortType() override {return 2;}
    char* getData();

private:
    Effect* parentEffect;
    static QList<InPort*>* inportList;

//public slots:
    void updateConnectionSelect();

};


#endif // INPORT_H
