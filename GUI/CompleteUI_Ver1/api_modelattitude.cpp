#include "api_modelattitude.h"

API_ModelAttitude::API_ModelAttitude(QObject *parent) : QObject(parent)
{

}

void API_ModelAttitude::receive_Attitude(float roll, float pitch, float yaw)
{
    emit update_UI(roll, pitch, yaw);
}
