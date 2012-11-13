#ifndef SERIALCOMMUNICATION_H
#define SERIALCOMMUNICATION_H

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <unistd.h>

#include <QtGlobal>
#include <QElapsedTimer>

#include <qextserialport.h>

#include "SerialCommunication.h"

const uint read_max_wait = 100; //100 ms

/* Opens serial port and sets BAUD to 921600 */
QextSerialPort* openPort(char *ppath);

/*Helper for openport. Tests the BAUD rate*/
int SetCorrectBaudRate(QextSerialPort *port);


/*Reads text output from port into QByteArray. Expects <CR> as end of command*/
QByteArray readCommand(QextSerialPort* port);

/*Reads binary output(from BX) int QByteArray. Extracts "Reply Length" to know
when to finish*/
QByteArray readCommandBX(QextSerialPort* port);

/*Writes text command to serial port. Expects to have <CR> in the end(as well
as \0*/
void writeCommand(QextSerialPort* port, char *cmd);

/*Purges all data from port for read_max_wait msec*/
void PurgeOutput(QextSerialPort *port);

#endif // SERIALCOMMUNICATION_H
