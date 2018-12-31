#include "tester_mapviewer.h"

Tester_MapViewer::Tester_MapViewer(QObject *parent) : QObject(parent)
{

}

void Tester_MapViewer::send_Data(double longitude, double latitude)
{
    emit incoming_Data(longitude,latitude);
}
