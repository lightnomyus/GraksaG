#include "api_missionhandler.h"
//#include <QtDebug>

API_MissionHandler::API_MissionHandler(QObject *parent) : QObject(parent)
{

}

void API_MissionHandler::new_mission(QString missionName)
{
    //qDebug()<<missionName;
    emit send_MissionName(missionName);
}

void API_MissionHandler::get_fileName(QString path)
{
    QString fileName = path.split('/').takeLast().split('.')[0];
    //qDebug()<<fileName;
    emit send_MissionName(fileName);
}

void API_MissionHandler::start_mission()
{
    emit command_StartDataAqc();
}

void API_MissionHandler::replay_mission()
{
    emit command_ReplayMission();
}

void API_MissionHandler::stop_mission()
{
    emit command_StopMission();
}

void API_MissionHandler::start_dataAqc()
{
    emit command_StartDataAqc();
}

void API_MissionHandler::stop_dataAqc()
{
    emit command_StopDataAqc();
}

void API_MissionHandler::take_picture()
{
    emit command_TakePicture();
}
