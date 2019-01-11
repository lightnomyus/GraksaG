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
    void receive_DataByte(QByteArray data);
    void set_TeamId (QString id);

private:
    int m_byteCounter;
    int m_maxCounter;
    message_t m_messageReceived;
    message_t m_comparison;
    QByteArray m_data;
    uint8_t m_teamId[3];
};

#endif // API_PROTOCOLHANDLER_H
