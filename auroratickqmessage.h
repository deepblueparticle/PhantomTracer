#ifndef AURORATICKQMESSAGE_H
#define AURORATICKQMESSAGE_H

#include <QMetaType>

class AuroraTool  {
public:
    uchar handle;
    float Q0, Qx, Qy, Qz, Tx, Ty, Tz;
    float IndicatorValue;
    uint PortStatus, FrameNumber;
};

class AuroraTickQMessage  {
public:
    AuroraTickQMessage();
    //~AuroraTickQMessage();
    QList<AuroraTool> tools;

};

Q_DECLARE_METATYPE(AuroraTickQMessage);
#endif // AURORATICKQMESSAGE_H
