#include "api_dataloghandler.h"
//#include <QDebug>

API_DataLogHandler::API_DataLogHandler(QObject *parent) : QObject(parent)
{
    m_activeAltitude = false;
    m_activeAttitude = false;
    m_active3DPosition = false;
    m_activeCoordinate = false;
    m_activeAccel = false;
    m_activeGyro = false;
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

void API_DataLogHandler::set_activeGyro(bool checked)
{
    m_activeGyro = checked;
}

void API_DataLogHandler::set_activeAccel(bool checked)
{
    m_activeAccel = checked;
}

// slot

void API_DataLogHandler::receive_DataLogF(int id, float data)
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
    case AX_LOG_ID:
        //qDebug()<<"case ax detected";
        if (m_activeAccel) {
            m_message = "Ax: " + QString::number(static_cast<double>(data));
            //qDebug()<<"send message ax";
            emit message_DataLog(m_message);
        }
        break;
    case AY_LOG_ID:
        if (m_activeAccel) {
            m_message = "Ay: " + QString::number(static_cast<double>(data));
            emit message_DataLog(m_message);
        }
        break;
    case AZ_LOG_ID:
        if (m_activeAccel) {
            m_message = "Az: " + QString::number(static_cast<double>(data));
            emit message_DataLog(m_message);
        }
        break;
    case GX_LOG_ID:
        if (m_activeGyro) {
            m_message = "Gx: " + QString::number(static_cast<double>(data));
            emit message_DataLog(m_message);
        }
        break;
    case GY_LOG_ID:
        if (m_activeGyro) {
            m_message = "Gy: " + QString::number(static_cast<double>(data));
            emit message_DataLog(m_message);
        }
        break;
    case GZ_LOG_ID:
        if (m_activeGyro) {
            m_message = "Gz: " + QString::number(static_cast<double>(data));
            emit message_DataLog(m_message);
        }
        break;
    }
}

void API_DataLogHandler::receive_DataLogD(int id, double data)
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

