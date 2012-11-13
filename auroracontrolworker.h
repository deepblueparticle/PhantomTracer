#ifndef AURORACONTROLWORKER_H
#define AURORACONTROLWORKER_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>

#include <QObject>

#include <qextserialport.h>

#include "auroratickqmessage.h"
#include "auroracommandparser.h"
#include "SerialCommunication.h"

class AuroraControlWorker : public QObject
{
    Q_OBJECT
public:
    explicit AuroraControlWorker(QObject *parent = 0);
    
signals:
    void NewFrame(AuroraTickQMessage& msg);
    void finished();

public slots:
    void process();
};

#endif // AURORACONTROLWORKER_H
