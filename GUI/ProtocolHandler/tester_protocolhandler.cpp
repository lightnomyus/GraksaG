#include "tester_protocolhandler.h"
#include <QtDebug>

Tester_ProtocolHandler::Tester_ProtocolHandler(QObject *parent) : QObject(parent)
{
    m_teamId[0] = 'I';
    m_teamId[1] = 'T';
    m_teamId[2] = 'B';
    m_timer = new QTimer(this);
    QObject::connect(m_timer,&QTimer::timeout,this,&Tester_ProtocolHandler::generate_Data);
    m_timer->start(3000);
}

float Tester_ProtocolHandler::generate_float()
{
    float random = QRandomGenerator::global()->generate();
    return  random;
}

double Tester_ProtocolHandler::generate_double()
{
    double random = QRandomGenerator::global()->generate64();
    return  random;
}

void Tester_ProtocolHandler::send_float(uint8_t *data)
{
    QByteArray container;
    for (int i=0;i<9;i++) {
        container.append(static_cast<char>(data[i]));
        emit incoming_Data(container);
        container.clear();
    }
}

void Tester_ProtocolHandler::send_double(uint8_t *data)
{
    QByteArray container;
    for (int i=0;i<13;i++) {
        container.append(static_cast<char>(data[i]));
        emit incoming_Data(container);
        container.clear();
    }
}

void Tester_ProtocolHandler::generate_Data()
{
    // AX
    float randomfloat = generate_float();
    uint8_t *message;
    construct_MSG_AX(&message,0xd,m_teamId,randomfloat);
    qDebug()<<"AX_t: "<<randomfloat;
    send_float(message);
    free(message);
    // AY
    randomfloat = generate_float();
    construct_MSG_AY(&message,0xd,m_teamId,randomfloat);
    qDebug()<<"AY_t: "<<randomfloat;
    send_float(message);
    free(message);
    // AZ
    randomfloat = generate_float();
    construct_MSG_AZ(&message,0xd,m_teamId,randomfloat);
    qDebug()<<"AZ_t: "<<randomfloat;
    send_float(message);
    free(message);
    // GX
    randomfloat = generate_float();
    construct_MSG_GX(&message,0xd,m_teamId,randomfloat);
    qDebug()<<"GX_t: "<<randomfloat;
    send_float(message);
    free(message);
    // GY
    randomfloat = generate_float();
    construct_MSG_GY(&message,0xd,m_teamId,randomfloat);
    qDebug()<<"GY_t: "<<randomfloat;
    send_float(message);
    free(message);
    // GZ
    randomfloat = generate_float();
    construct_MSG_GZ(&message,0xd,m_teamId,randomfloat);
    qDebug()<<"GZ_t: "<<randomfloat;
    send_float(message);
    free(message);
    // ALT
    randomfloat = generate_float();
    construct_MSG_ALT(&message,0xd,m_teamId,randomfloat);
    qDebug()<<"ALT_t: "<<randomfloat;
    send_float(message);
    free(message);
    // LON
    double randomdouble = generate_double();
    construct_MSG_LON(&message,0xd,m_teamId,randomdouble);
    qDebug()<<"LON_t: "<<randomdouble;
    send_double(message);
    free(message);
    // LAT
    randomdouble = generate_double();
    construct_MSG_LAT(&message,0xd,m_teamId,randomdouble);
    qDebug()<<"LAT_t: "<<randomdouble;
    send_double(message);
    free(message);

}
