#include "api_missionhandler.h"
#include <QtDebug>

API_MissionHandler::API_MissionHandler(QObject *parent) : QObject(parent)
{

}

void API_MissionHandler::new_mission(QString missionName)
{
    //qDebug()<<missionName;
    emit send_MissionName(missionName);
    m_message = m_time.currentTime().toString() + " : Create new mission";
    emit notif_Log(m_message);
}

void API_MissionHandler::get_fileName(QString path)
{
    QString fileName = path.split('/').takeLast().split('.')[0];
    //qDebug()<<fileName;
    emit send_MissionName(fileName);
    replay_mission();
}

void API_MissionHandler::start_mission()
{
    emit command_StartDataAcq();
    m_message = m_time.currentTime().toString() + " : Mission started";
    emit notif_Log(m_message);
}

void API_MissionHandler::replay_mission()
{
    emit command_ReplayMission();
    m_message = m_time.currentTime().toString() + " : Replay old mission";
    emit notif_Log(m_message);
}

void API_MissionHandler::stop_mission()
{
    emit command_StopMission();
    m_message = m_time.currentTime().toString() + " : Mission stopped";
    emit notif_Log(m_message);
}

void API_MissionHandler::start_datAcq()
{
    emit command_StartDataAcq();
    m_message = m_time.currentTime().toString() + " : Start Data Acquisition";
    emit notif_Log(m_message);
}

void API_MissionHandler::stop_dataAcq()
{
    emit command_StopDataAcq();
    m_message = m_time.currentTime().toString() + " : Stop Data Acquisition";
    emit notif_Log(m_message);
}

void API_MissionHandler::take_picture()
{
    m_message = m_time.currentTime().toString() + " : Take Picture";
    emit notif_Log(m_message);
    emit command_TakePicture();
}

void API_MissionHandler::notif_EndReplay()
{
    m_message = m_time.currentTime().toString() + " : Finished Replay";
    emit notif_Log(m_message);
}
