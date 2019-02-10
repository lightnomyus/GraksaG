#include "api_chartviewer.h"
#include <QtDebug>

API_ChartViewer::API_ChartViewer(QObject *parent) : QObject(parent)
{
    m_timeCounter1 = 0;
    m_timeCounter2 = 0;
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

void API_ChartViewer::clear_time1()
{
    m_timeCounter1 = 0;
    //qDebug()<<"counter1 clear";
}

void API_ChartViewer::clear_time2()
{
    m_timeCounter2 = 0;
    //qDebug()<<"counter2 clear";
}

void API_ChartViewer::receive_DataSpline_Time(float data)
{
    //qDebug()<<m_timeCounter1;
    m_timeCounter1+=1;
    emit update_UI(m_timeCounter1,data);
}

void API_ChartViewer::receive_DataSpline_3Data(float x, float y, float z)
{
    //qDebug()<<m_timeCounter2;
    m_timeCounter2+=1;
    emit update_UI_3Data(x,y,z,m_timeCounter2);
}
