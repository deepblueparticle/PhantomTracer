#ifndef AURORACOMMANDPARSER_H
#define AURORACOMMANDPARSER_H

#include <stdio.h>

#include <QtGlobal>
#include <QByteArray>
#include <QList>
#include <iostream>

struct PortHandle  {
    uchar HandleHexCharString[2]; //Without \0 !!!
    uchar HandleBytes[2];

    /*Bool values:*/
    uchar Occupied;
    uchar GPIO_1_closed;
    uchar GPIO_2_closed;
    uchar GPIO_3_closed;
    uchar Initialized;
    uchar Enabled;
};


struct HandleReply  {
    uchar HandleHexCharString[3]; //With \0 !!!
    uchar HandleBytes[2];

    uchar HandleStatus; // 01-Valid, 02-Missing, 04-Disabled
    float Q0, Qx, Qy, Qz;
    float Tx, Ty, Tz;
    float IndicatorValue;
    uint FrameNumber;
    uint PortStatus;

    /*Bool values:*/
    uchar Occupied;
    uchar GPIO_1_closed;
    uchar GPIO_2_closed;
    uchar GPIO_3_closed;
    uchar Initialized;
    uchar Enabled;
    uchar OutOfVolume;
    uchar PartitiallyOutOfVolume;
    uchar SensorCoilBroken;
    uchar ProcessingException;
};


struct SystemStatus  {
    uchar CommSyncError;
    uchar CRCError;
    uchar RecoverableSysProcError;
    uchar HardwareFailure;
    uchar HardwareChange;
    uchar SomeHandleOccupied;
    uchar SomePortHandleUnoccupied;
};


union bfloat {
    float f;
    uchar c[4];
};

union buint {
    uint f;
    uchar c[4];
};


QByteArray sliceByteArray(const QByteArray& a, int iL, int iR, bool addZ = true);
float Slice4FloatFormQBytes(const QByteArray& arr, uint idx);
uint Slice4UintFormQBytes(const QByteArray& arr, uint idx);
uint Slice2UintFormQBytes(const QByteArray& arr, uint idx);


int isReplyOK(const QByteArray& cmd);
int ParsePHSR(const QByteArray& cmd, int &nHandles, QList<PortHandle> &handles);
int ParseBX(const QByteArray& cmd, int &nHandles, QList<HandleReply> &handles,
            SystemStatus &system_status);

void printCmd(QByteArray data);

#endif // AURORACOMMANDPARSER_H
