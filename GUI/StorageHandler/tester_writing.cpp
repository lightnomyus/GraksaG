#include "tester_writing.h"
#include <QDebug>

Tester_Writing::Tester_Writing(QObject *parent) : QObject(parent)
{

}

void Tester_Writing::command_StartWriting()
{
    emit start_Writing();
}

void Tester_Writing::command_EndWriting()
{
    emit end_Writing();
}

void Tester_Writing::command_NewMission(QString missionName)
{
    emit new_Name(missionName);
}

void Tester_Writing::command_ReplayMission(QString missionName)
{
    QStringList list1 = missionName.split('/');
    QStringList list2 = list1.takeLast().split('.');
    QString fileName = list2[0];
    emit new_Name(fileName);
    command_StartRead();
}

void Tester_Writing::command_StartRead()
{
    emit start_Reading();
}

void Tester_Writing::send_Data(float alt, double lon, double lat, float roll, float pitch, float yaw, float xpos, float ypos, float zpos)
{
    emit incoming_Data(alt,lon,lat,roll,pitch,yaw,xpos,ypos,zpos);
}
