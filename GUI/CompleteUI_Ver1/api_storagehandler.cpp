#include "api_storagehandler.h"
#include <QtDebug>

API_StorageHandler::API_StorageHandler(QObject *parent) : QObject(parent)
{
    QObject::connect(this,&API_StorageHandler::notif_ReadData,this,&API_StorageHandler::read_Data);
    QObject::connect(this,&API_StorageHandler::notif_EndRead,this,&API_StorageHandler::end_Read);
    m_missionName = "mission_default";
    m_isRead = false;
    m_isWrite = false;
}

void API_StorageHandler::process_line()
{
    QStringList list = m_readLine.split(',');
    float alt, roll, pitch, yaw, xpos, ypos, zpos;
    float ax, ay, az, gx, gy, gz;
    double lon, lat;
    alt = list[0].toFloat();
    lon = list[1].toDouble();
    lat = list[2].toDouble();
    roll = list[3].toFloat();
    pitch = list[4].toFloat();
    yaw = list[5].toFloat();
    xpos = list[6].toFloat();
    ypos = list[7].toFloat();
    zpos = list[8].toFloat();
    ax = list[9].toFloat();
    ay = list[10].toFloat();
    az = list[11].toFloat();
    gx = list[12].toFloat();
    gy = list[13].toFloat();
    gz = list[14].toFloat();
    emit send_Altitude(alt);
    //qDebug()<<"Altitude: "<<alt;
    emit send_Attitude(roll, pitch, yaw);
    //qDebug()<<"Attitude: "<<roll<<" , "<<pitch<<" , "<<yaw;
    emit send_Coordinate(lon,lat);
    //qDebug()<<"Coordinate: "<<lon<<" , "<<lat;
    emit send_Odometry(xpos,ypos,zpos);
    //qDebug()<<"Odometry: "<<xpos<<" , "<<ypos<<" , "<<zpos;
    emit send_DataAccel(ax,ay,az);
    emit send_DataGyro(gx,gy,gz);
}

void API_StorageHandler::update_MissionName(QString missionName)
{
    m_missionName = missionName;
}

void API_StorageHandler::start_Read()
{
    QString fileName = m_missionName + ".csv";
    m_isRead = true;
    m_isWrite = false;
    m_file.setFileName(fileName);
    m_file.open(QIODevice::ReadOnly);
    m_stream.setDevice(&m_file);
    m_readLine = m_stream.readLine();
    //qDebug()<<m_readLine;
    emit notif_ReadData();
}

void API_StorageHandler::start_Write()
{
    QString fileName = m_missionName + ".csv";
    m_isWrite = true;
    m_isRead = false;
    m_file.setFileName(fileName);
    m_file.open(QIODevice::WriteOnly);
    m_stream.setDevice(&m_file);
    m_stream << "Altitude" << "," << "Longitude" << "," << "Latitude" << ","
             << "Roll" << "," << "Pitch" << "," << "Yaw" << ","
             << "Xpos" << "," << "Ypos" << "," << "Zpos" << ","
             << "AX" << "," << "AY" << "," << "AZ" << ","
             << "GX" << "," << "GY" << "," << "GZ" << "\n";
}

void API_StorageHandler::end_Read()
{
    m_isRead = false;
    m_file.close();
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
                                    float xpos, float ypos, float zpos,
                                    float ax, float ay, float az,
                                    float gx, float gy, float gz)
{
    if (m_isWrite) {
        m_stream << alt << "," << lon << "," << lat << ","
                 << roll << "," << pitch << "," << yaw << ","
                 << xpos << "," << ypos << "," << zpos << ","
                 << ax << "," << ay << "," << az << ","
                 << gx << "," << gy << "," << gz << "\n";
    }
}

void API_StorageHandler::read_Data()
{
    if (m_isRead) {
        m_readLine = m_stream.readLine();
        while(m_readLine!="EOF") {
            process_line();
            m_readLine = m_stream.readLine();
            //qDebug()<<m_readLine;
        }
        qDebug()<<"replay end";
        emit notif_EndRead();
    }
}
