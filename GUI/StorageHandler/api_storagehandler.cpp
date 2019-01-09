#include "api_storagehandler.h"

API_StorageHandler::API_StorageHandler(QObject *parent) : QObject(parent)
{

}

void API_StorageHandler::update_MissionName(QString missionName)
{
    m_missionName = missionName;
}
