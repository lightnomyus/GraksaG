#include "api_dataloghandler.h"

API_DataLogHandler::API_DataLogHandler(QObject *parent) : QObject(parent)
{
    m_activeAltitude = false;
    m_activeAttitude = false;
    m_active3DPosition = false;
    m_activeCoordinate = false;
}

void API_DataLogHandler::set_activeAltitude(bool checked)
{
    m_activeAltitude = checked;
}

void API_DataLogHandler::set_activeAttitude(bool checked)
{
    m_activeAttitude = checked;
}

void API_DataLogHandler::set_active3DPosition(bool checked)
{
    m_active3DPosition = checked;
}

void API_DataLogHandler::set_activeCoordinate(bool checked)
{
    m_activeCoordinate = checked;
}


// slot

void API_DataLogHandler::receive_DataLog(int id, float data)
{
    // parsing data berdasarkan id
}

void API_DataLogHandler::receive_DataLog(int id, double data)
{
    // parsing data berdasarkan id
}

