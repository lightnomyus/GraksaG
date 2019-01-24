#include "tester_modelattitude.h"

Tester_ModelAttitude::Tester_ModelAttitude(QObject *parent) : QObject(parent)
{

}

void Tester_ModelAttitude::send_Data(float roll, float pitch, float yaw)
{
    emit incoming_Data(roll, pitch, yaw);
}
