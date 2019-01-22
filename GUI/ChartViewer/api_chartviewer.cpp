#include "api_chartviewer.h"

API_ChartViewer::API_ChartViewer(QObject *parent) : QObject(parent)
{

}

void API_ChartViewer::receive_DataSpline(float angle, float x, float y)
{
    emit update_UI(x,y);
    m_launchAngle = angle;
}

float API_ChartViewer::get_launcAngle()
{
    return m_launchAngle;
}
