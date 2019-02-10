#include "api_dataloghandler.h"
//#include <QDebug>

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
    //qDebug()<< m_activeAltitude;
}

void API_DataLogHandler::set_activeAttitude(bool checked)
{
    m_activeAttitude = checked;
    //qDebug()<< m_activeAttitude;
}

void API_DataLogHandler::set_active3DPosition(bool checked)
{
    m_active3DPosition = checked;
    //qDebug()<< m_active3DPosition;
}

void API_DataLogHandler::set_activeCoordinate(bool checked)
{
    m_activeCoordinate = checked;
    //qDebug()<< m_activeCoordinate;
}


// slot

void API_DataLogHandler::receive_DataLog(int id, float data)
{
    // parsing data berdasarkan id
    switch (id) {
    case ALT_LOG_ID:
        if (m_activeAltitude) {
            m_message = "Alt: " + QString::number(static_cast<double>(data));
            emit message_DataLog(m_message);
        }
        break;
    case ROLL_LOG_ID:
        if (m_activeAttitude) {
            m_message = "Roll: " + QString::number(static_cast<double>(data));
            emit message_DataLog(m_message);
        }
        break;
    case PITCH_LOG_ID:
        if (m_activeAttitude) {
            m_message = "Pitch: " + QString::number(static_cast<double>(data));
            emit message_DataLog(m_message);
        }
        break;
    case YAW_LOG_ID:
        if (m_activeAttitude) {
            m_message = "Yaw: " + QString::number(static_cast<double>(data));
            emit message_DataLog(m_message);
        }
        break;
    case XPOS_LOG_ID:
        if (m_active3DPosition) {
            m_message = "XPos: " + QString::number(static_cast<double>(data));
            emit message_DataLog(m_message);
        }
        break;
    case YPOS_LOG_ID:
        if (m_active3DPosition) {
            m_message = "YPos: " + QString::number(static_cast<double>(data));
            emit message_DataLog(m_message);
        }
        break;
    case ZPOS_LOG_ID:
        if (m_active3DPosition) {
            m_message = "ZPos: " + QString::number(static_cast<double>(data));
            emit message_DataLog(m_message);
        }
        break;
    }
}

void API_DataLogHandler::receive_DataLog(int id, double data)
{
    // parsing data berdasarkan id
    switch (id) {
    case LON_LOG_ID:
        if (m_activeCoordinate) {
            m_message = "Lon: " + QString::number(static_cast<double>(data));
            emit message_DataLog(m_message);
        }
        break;
    case LAT_LOG_ID:
        if (m_activeCoordinate) {
            m_message = "Lat: " + QString::number(static_cast<double>(data));
            emit message_DataLog(m_message);
        }
        break;
    }
}

