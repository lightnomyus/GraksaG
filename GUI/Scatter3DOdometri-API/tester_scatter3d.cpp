#include "tester_scatter3d.h"

Tester_Scatter3D::Tester_Scatter3D(QObject *parent) : QObject(parent)
{

}

void Tester_Scatter3D::send_Data(float xPos, float yPos, float zPos)
{
    emit incoming_Data(xPos,yPos,zPos);

}
