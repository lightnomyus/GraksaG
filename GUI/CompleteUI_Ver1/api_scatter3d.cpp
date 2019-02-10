#include "api_scatter3d.h"

API_Scatter3D::API_Scatter3D(QObject *parent) : QObject(parent)
{

}

void API_Scatter3D::receive_Data3DPosition(float xPos, float yPos, float zPos)
{
    emit update_UI(xPos,yPos,zPos);
}
