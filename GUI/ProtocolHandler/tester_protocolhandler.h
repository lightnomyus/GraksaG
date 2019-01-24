#ifndef TESTER_PROTOCOLHANDLER_H
#define TESTER_PROTOCOLHANDLER_H

#include <QObject>
#include <QRandomGenerator>
#include <QTimer>
extern "C"{
    #include "graksalink.h"
}

class Tester_ProtocolHandler : public QObject
{
    Q_OBJECT
public:
    explicit Tester_ProtocolHandler(QObject *parent = nullptr);
    float generate_float();
    double generate_double();
    void send_float(uint8_t *data);
    void send_double(uint8_t *data);

signals:
    void incoming_Data(QByteArray data);

public slots:
    void generate_Data();

private:
    QTimer *m_timer;
    quint8 m_teamId[3];
};

#endif // TESTER_PROTOCOLHANDLER_H
