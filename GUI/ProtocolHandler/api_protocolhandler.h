#ifndef API_PROTOCOLHANDLER_H
#define API_PROTOCOLHANDLER_H

#include <QObject>
#include <QByteArray>

extern "C"{
    #include "graksalink.h"
}

class API_ProtocolHandler : public QObject
{
    Q_OBJECT
public:
    explicit API_ProtocolHandler(QObject *parent = nullptr);

signals:
    void send_DataAccel();
    void send_DataGyro();
    void send_DataCoordinate();

public slots:
    void receive_DataBytes();
};

#endif // API_PROTOCOLHANDLER_H
