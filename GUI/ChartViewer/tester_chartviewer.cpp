#include "tester_chartviewer.h"

Tester_ChartViewer::Tester_ChartViewer(QObject *parent) : QObject(parent)
{

}

void Tester_ChartViewer::send_data(float x, float y)
{
    emit incoming_Data(x,y);
}
