#include "tester_chartviewer.h"

Tester_ChartViewer::Tester_ChartViewer(QObject *parent) : QObject(parent)
{

}

void Tester_ChartViewer::send_data(float x, float y)
{
    float angle = 60;
    emit incoming_Data(angle,x,y);
}

void Tester_ChartViewer::send_1data(float data)
{
    emit incoming_Data1(data);
}

void Tester_ChartViewer::send_3data(float x, float y, float z)
{
    emit incoming_Data3(x,y,z);
}
