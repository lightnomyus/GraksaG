#include "api_serialhandler.h"

API_SerialHandler::API_SerialHandler(QObject *parent) : QObject(parent)
{
    m_isActive = false;
    m_infos = QSerialPortInfo::availablePorts();
}


