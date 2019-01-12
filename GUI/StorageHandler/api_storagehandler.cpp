#include "api_storagehandler.h"

API_StorageHandler::API_StorageHandler(QObject *parent) : QObject(parent)
{
    m_missionName = "mission_default";
    m_isRead = false;
    m_isWrite = false;
}

void API_StorageHandler::update_MissionName(QString missionName)
{
    m_missionName = missionName;
}

void API_StorageHandler::start_Read()
{
    m_isRead = true;
    m_isWrite = false;
    m_file.setFileName(m_missionName);
    m_file.open(QIODevice::ReadOnly);
    m_stream.setDevice(&m_file);
}

void API_StorageHandler::start_Write()
{
    m_isWrite = true;
    m_isRead = false;
    m_file.setFileName(m_missionName);
    m_file.open(QIODevice::WriteOnly);
    m_stream.setDevice(&m_file);
    m_stream << "Altitude" << "," << "Longitude" << "," << "Latitude" << ","
             << "Roll" << "," << "Pitch" << "," << "Yaw" << ","
             << "Xpos" << "," << "Ypos" << "," << "Zpos" << "\n";
}

void API_StorageHandler::end_Read()
{

}

void API_StorageHandler::end_Write()
{
    m_isWrite = false;
    m_stream << "EOF";
    m_stream.flush();
    m_file.close();
}

void API_StorageHandler::write_Data(float alt, double lon, double lat,
                                    float roll, float pitch, float yaw,
                                    float xpos, float ypos, float zpos)
{
    if (m_isWrite) {
        m_stream << alt << "," << lon << "," << lat << ","
                 << roll << "," << pitch << "," << yaw << ","
                 << xpos << "," << ypos << "," << zpos << "\n";
    }
}

void API_StorageHandler::read_Data()
{

}
