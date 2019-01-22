#include "tester_chartviewer.h"

Tester_ChartViewer::Tester_ChartViewer(QObject *parent) : QObject(parent)
{

}

void Tester_ChartViewer::send_data(float x, float y)
{
    float angle = 60;
    emit incoming_Data(angle,x,y);
}
