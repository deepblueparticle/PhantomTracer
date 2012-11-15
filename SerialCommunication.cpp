#include "SerialCommunication.h"

FILE *f_usb_comm_log;

QextSerialPort* openPort(char *ppath)  {
    QextSerialPort* port;
    port = new QextSerialPort(ppath);

    port->open(QIODevice::ReadWrite);// | QIODevice::Unbuffered);
    //port->setFlowControl(FLOW_OFF);
    port->setParity(PAR_NONE);
    port->setDataBits(DATA_8);
    port->setStopBits(STOP_1);
    //port->setTextModeEnabled();
    port->setTimeout(200);
//    port->setBaudRate(BAUD9600);//921600);
    //Comment prev and uncomment following
    SetCorrectBaudRate(port);

//    std::cerr<<"\nBOUD RATE1 "<<port->baudRate()<<"\n";
  //  std::cerr<<"\nPort tune "<<SetCorrectBaudRate(port);
    /*QByteArray rep;
    rep = readCommand(port);
    printCmd(rep);
    std::cerr<<"\nBOUD RATE2 "<<port->baudRate()<<"\n";

    sleep(2);
    std::cerr<<"\nBOUD RATE3 "<<port->baudRate()<<"\n";
    port->setBaudRate(BAUD921600);
    std::cerr<<"\nBOUD RATE4 "<<port->baudRate()<<"\n";*/
    return port;
}


int SetCorrectBaudRate(QextSerialPort *port)  {
    QByteArray data;
    int baud9600 = 0;
    QElapsedTimer timer;

    port->setBaudRate(BAUD9600);//921600);
    writeCommand(port, "test\r");
    timer.start();
    while ( timer.elapsed() < 200 )  {
        data = port->readAll();
        for ( int i = 0; i < data.length(); ++i )  {
            if (data[i] == '\r')
                baud9600 = 1;
        }
    }

    if (baud9600)  {
        writeCommand(port, "COMM 60001\r");
        sleep(1);
    }

    port->setBaudRate(BAUD921600);
    writeCommand(port, "test\r");
    timer.start();
    while ( timer.elapsed() < 300 )  {
        data = port->readAll();
        for ( int i = 0; i < data.length(); ++i )  {
            if (data[i] == '\r')
                return 2;
        }
    }
    return 0;
}


QByteArray readCommand(QextSerialPort* port)  {
    bool noCR = true;
    QByteArray cmd;
    cmd.clear();
    while (noCR)  {
        QByteArray data = port->readAll();
        cmd.append(data);
        for (int i = 0; i < data.length(); ++i) {
                //std::cerr<<"_"<<(int)data[i];
                if (data[i] == '\r') {
                    if (i != data.length() - 1)
                        std::cerr<<"Something is wrong with serial reader. CRITICAL!";
                    noCR = false; //recieved CR -- quit
                }
        }
    }
    //fprintf(f_usb_comm_log, "<<%s\n", cmd.data()); //LOG
    return cmd;
}


QByteArray readCommandBX(QextSerialPort* port)  {
    unsigned int cbyte = 0;
    unsigned int length = 0;
    bool noEND = true;
    QByteArray cmd;
    cmd.clear();
    fprintf(f_usb_comm_log, "<<"); //LOG
    while (noEND)  {
        QByteArray data = port->readAll();
        cmd.append(data);
        for (int i = 0; i < data.length(); i++) {
            cbyte++;
            fprintf(f_usb_comm_log, "%.2X", (uchar)data[i]); //LOG
            //printf("\nR: %X %d", (uchar)data[i], cbyte );
            if (cbyte == 2) {
                if ( ((uchar)cmd[1] != 0xA5) ||
                     ((uchar)cmd[0] != 0xC4) ) {
                    std::cerr<<"\nCRITICAL: NOT BX start sequence";
                    noEND = false;
                }
            }
            if (cbyte == 4) {
                length = cmd[3];
                length = (length<<2) | ((uchar)cmd[2]);
                //std::cerr<<"\nBX LENGTH "<<length;
            }
            if (length && (length + 2 + 2 + 2 + 2 < cbyte + 1)) {
                    noEND = false;
            }
        }
    }

    fprintf(f_usb_comm_log, "\n"); //LOG
    return cmd;
}


void writeCommand(QextSerialPort* port, char *cmd)  {
    int slen = strlen(cmd);
    char* pr = new char[slen];
    int ret;
    strncpy(pr, cmd, slen - 1);
    pr[slen - 1] = '\0';
    //std::cerr<<">>"<<cmd<<std::flush;
    ret = port->write(cmd, strlen(cmd));
    //fprintf(f_usb_comm_log, ">>%s<CR>\n", pr); //LOG
    //fflush(f_usb_comm_log); //LOG
}


void PurgeOutput(QextSerialPort *port)  {
    QElapsedTimer timer;
    QByteArray data;
    timer.start();
    while ( timer.elapsed() < read_max_wait )
        data = port->readAll();
}



