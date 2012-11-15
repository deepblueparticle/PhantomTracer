#include "auroracontrolworker.h"

AuroraControlWorker::AuroraControlWorker(QObject *parent) :
    QObject(parent)
{
}


void AuroraControlWorker::process()  {
    QextSerialPort* port;
    QByteArray rep;
    QList<PortHandle> port_handles;
    int nHandles;
    char cmd[256];

    port = openPort("/dev/ttyUSB0");
    sleep(1);

    writeCommand(port, "TSTOP \r");
    rep = readCommand(port);
    printCmd(rep);

   /* writeCommand(port, "PHF OA\r");
    rep = readCommand(port);
    printCmd(rep);

    writeCommand(port, "PHF 0B\r");
    rep = readCommand(port);
    printCmd(rep);*/

    writeCommand(port, "INIT \r");
    sleep(1);
    rep = readCommand(port);
    printCmd(rep);

    writeCommand(port, "PHSR 00\r");
    sleep(1);
    rep = readCommand(port);
    ParsePHSR(rep, nHandles, port_handles);

    //Init all ports
    for (int i = 0; i < nHandles; i++)  {
        sprintf(cmd, "PINIT %c%c\r", port_handles.at(i).HandleHexCharString[0],
                port_handles.at(i).HandleHexCharString[1]);
        writeCommand(port, cmd);
        rep = readCommand(port);
        printCmd(rep);
    }

    //Enable handles
    for (int i = 0; i < nHandles; i++)  {
        sprintf(cmd, "PENA %c%c\r", port_handles.at(i).HandleHexCharString[0],
                port_handles.at(i).HandleHexCharString[1]);
        writeCommand(port, cmd);
        rep = readCommand(port);
        printCmd(rep);
    }

    //GO TRACK
    writeCommand(port, "TSTART \r");
    rep = readCommand(port);
    printCmd(rep);

    //GETBX
    QElapsedTimer timer;
    timer.start();
    while(!stopped) {
        SystemStatus system_status;
        QList<HandleReply> handle_replys;
        int bx_nHandles;

        writeCommand(port, "BX 0801\r");
        rep = readCommandBX(port);
        ParseBX(rep, bx_nHandles, handle_replys, system_status);
        //printCmdHex(rep);
        /*
            fprintf(f_coord_log, "%f, %f, %f, %f, %f, %f, %f, %f, %u, %u\n",
                    Q0, Qx, Qy, Qz, Tx, Ty, Tz, IndicatorValue, PortStatus,
                    FrameNumber);
            msg.tools.append(tool);*/
/*
       AuroraTickQMessage msg;
       for ( int i = 0; i < bx_nHandles; i++ )  {
            AuroraTool tool;
            tool.Q0 = handle_replys[i].Q0;
            tool.Qx = handle_replys[i].Qx;
            tool.Qy = handle_replys[i].Qy;
            tool.Qz = handle_replys[i].Qz;
            tool.Tx = handle_replys[i].Tx;
            tool.Ty = handle_replys[i].Ty;
            tool.Tz = handle_replys[i].Tz;
            tool.IndicatorValue = handle_replys[i].IndicatorValue;
            tool.PortStatus = handle_replys[i].PortStatus;
            tool.FrameNumber = handle_replys[i].FrameNumber;
            msg.tools.append(tool);

       }
       qint64 te = timer.elapsed();
       if (te < 70)//25
            this->msleep(70 - te);
       emit newFrame(msg);
       timer.start();

   }
    std::cout<<"\nI am done here\n";
    //Release all ports
    writeCommand(port, "PHF 0A\r");
    rep = readCommand(port);
    printCmd(rep);

    writeCommand(port, "PHF 0B\r");
    rep = readCommand(port);
    printCmd(rep);
*/
    emit finished();
}
