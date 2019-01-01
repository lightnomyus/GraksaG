#include "api_chartviewer.h"

API_ChartViewer::API_ChartViewer(QObject *parent) : QObject(parent)
{

}

void API_ChartViewer::receive_DataSpline(float x, float y)
{
    emit update_UI(x,y);
}
