#include "tester_writing.h"

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

void Tester_Writing::send_Data(float alt, double lon, double lat, float roll, float pitch, float yaw, float xpos, float ypos, float zpos)
{
    emit incoming_Data(alt,lon,lat,roll,pitch,yaw,xpos,ypos,zpos);
}
