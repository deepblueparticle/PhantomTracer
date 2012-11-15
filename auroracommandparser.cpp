#include "auroracommandparser.h"

int isReplyOK(const QByteArray& cmd)  {
    if (cmd[0] == 'O' && cmd[0] == 'K' && cmd[0] == 'A' && cmd[0] == 'Y')
        return 1;
    return 0;
}


int ParsePHSR(const QByteArray& cmd, int &nHandles, QList<PortHandle> &handles)  {
    QByteArray tmp = sliceByteArray(cmd, 0, 1);
    nHandles = strtol(tmp.data(), NULL, 16);
    for ( int i = 0; i < nHandles; i++ )  {
        QByteArray qb_handle = sliceByteArray(cmd, 2 + 5 * i, 2 + 5 * i + 1);
        PortHandle port_handle;
        port_handle.HandleHexCharString[0] = qb_handle[0];
        port_handle.HandleHexCharString[1] = qb_handle[1];

        union buint uni_handle;
        uni_handle.f = (uint)strtol(qb_handle.data(), 0, 16);
        port_handle.HandleBytes[0] = uni_handle.c[0];
        port_handle.HandleBytes[1] = uni_handle.c[1];

        QByteArray qb_status = sliceByteArray(cmd, 4 + 5 * i, 4 + 5 * i + 2);
        uint status;
        status = (uint)strtol(qb_status.data(), NULL, 16);
        port_handle.Occupied =      status & 0x001;
        port_handle.GPIO_1_closed = status & 0x002;
        port_handle.GPIO_2_closed = status & 0x004;
        port_handle.GPIO_3_closed = status & 0x008;
        port_handle.Initialized =   status & 0x010;
        port_handle.Enabled =       status & 0x020;

        handles.append(port_handle);
    }
    return 0;
}


int ParseBX(const QByteArray& cmd, int &nHandles,
            QList<HandleReply> &handle_replys, SystemStatus &system_status)  {
        const uint offsetB = 7;
        const uint handleB = 42;
        uint status;

        nHandles = (int)cmd[6];

        for (int i = 0; i < nHandles; ++i)  {
            HandleReply hreply;
            char str[3];
            QByteArray qb_handle = sliceByteArray(cmd, offsetB + i * handleB,
                                                  offsetB + i * handleB + 1);
            //sprintf(str, "%.1X%.1X", (uchar)qb_handle[0], (uchar)qb_handle[1]);
            hreply.HandleHexCharString[0] = qb_handle[0];
            hreply.HandleHexCharString[1] = qb_handle[1];
            hreply.HandleStatus = (uchar) cmd[offsetB + 1];

            hreply.Q0 = Slice4FloatFormQBytes(cmd, offsetB + handleB * i + 2);
            hreply.Qx = Slice4FloatFormQBytes(cmd, offsetB + handleB * i + 2 + 4);
            hreply.Qy = Slice4FloatFormQBytes(cmd, offsetB + handleB * i + 2 + 8);
            hreply.Qz = Slice4FloatFormQBytes(cmd, offsetB + handleB * i + 2 + 12);

            hreply.Tx = Slice4FloatFormQBytes(cmd, offsetB + handleB * i + 2 + 16);
            hreply.Ty = Slice4FloatFormQBytes(cmd, offsetB + handleB * i + 2 + 20);
            hreply.Tz = Slice4FloatFormQBytes(cmd, offsetB + handleB * i + 2 + 24);

            hreply.IndicatorValue = Slice4FloatFormQBytes(cmd, offsetB + handleB * i + 2 + 28);
            hreply.PortStatus = Slice4UintFormQBytes(cmd, offsetB + handleB * i + 2 + 32);
            hreply.FrameNumber = Slice4UintFormQBytes(cmd, offsetB + handleB * i + 2 + 36);

            status = hreply.PortStatus;
            hreply.Occupied =      status & 0x001;
            hreply.GPIO_1_closed = status & 0x002;
            hreply.GPIO_2_closed = status & 0x004;
            hreply.GPIO_3_closed = status & 0x008;
            hreply.Initialized =   status & 0x010;
            hreply.Enabled =       status & 0x020;
            hreply.OutOfVolume =   status & 0x040;
            hreply.PartitiallyOutOfVolume =   status & 0x080;
            hreply.SensorCoilBroken =         status & 0x100;
            hreply.ProcessingException =      status & 0x200;

            handle_replys.append(hreply);
        }
        return 0;
}



float Slice4FloatFormQBytes(const QByteArray& arr, uint idx) {
    union bfloat x;
    x.c[0] = arr[idx];
    x.c[1] = arr[idx + 1];
    x.c[2] = arr[idx + 2];
    x.c[3] = arr[idx + 3];
    return x.f;
}


uint Slice4UintFormQBytes(const QByteArray& arr, uint idx) {
    union buint x;
    x.c[0] = arr[idx];
    x.c[1] = arr[idx + 1];
    x.c[2] = arr[idx + 2];
    x.c[3] = arr[idx + 3];
    return x.f;
}


uint Slice2UintFormQBytes(const QByteArray& arr, uint idx) {
    union buint x;
    x.c[0] = arr[idx];
    x.c[1] = arr[idx + 1];
    return x.f;
}


QByteArray sliceByteArray(const QByteArray& a, int iL, int iR, bool addZ) {// = true)  {
    QByteArray slice(iR - iL + 1, '*');
    if (addZ)  {
        slice.resize(iR - iL + 2);
        slice[iR - iL + 1] = '\0';
    }
    for (int i = iL,  j = 0; i < iR + 1; ++i, ++j)
        slice[j] = a[i];
    return slice;
}


void printCmd(QByteArray data)  {
    std::cerr<<"\n<<";
    for (int i = 0; i < data.length(); ++i) {
        if (data[i]=='\r') std::cerr<<"+CR";
        else std::cerr<<data[i];
        //std::cerr<<"("<<int(data[i])<<")";
    }
    std::cerr<<"\n";
}
