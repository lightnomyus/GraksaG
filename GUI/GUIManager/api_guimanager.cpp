#include "api_guimanager.h"

API_GUIManager::API_GUIManager(QObject *parent) : QObject(parent)
{
    QObject::connect(&m_timer,&QTimer::timeout,this,&API_GUIManager::update_UIAll);
    m_timer.start(50);
}

void API_GUIManager::receive_Altitude(float alt)
{
    m_alt.enqueue(alt);
}

void API_GUIManager::receive_Attitude(float roll, float pitch, float yaw)
{
    m_roll.enqueue(roll);
    m_pitch.enqueue(pitch);
    m_yaw.enqueue(yaw);
}

void API_GUIManager::receive_Odometry(float xpos, float ypos, float zpos)
{
    m_xpos.enqueue(xpos);
    m_ypos.enqueue(ypos);
    m_zpos.enqueue(zpos);
}

void API_GUIManager::receive_Coordinate(double lon, double lat)
{
    m_lon.enqueue(lon);
    m_lat.enqueue(lat);
}

void API_GUIManager::update_UIAll()
{
    // Log
    if (!m_alt.isEmpty()){
        emit update_UILog(m_alt.head());
    }
    // MAP
    if (!m_lon.isEmpty() && !m_lat.isEmpty()){
        emit update_UILog(m_lon.dequeue());
        emit update_UILog(m_lat.dequeue());
        emit update_UIMap(m_lon.dequeue(),m_lat.dequeue());
    }
    // Scatter
    if (!m_xpos.isEmpty() && !m_ypos.isEmpty() && !m_zpos.isEmpty()){
        emit update_UILog(m_xpos.head());
        emit update_UILog(m_ypos.head());
        emit update_UILog(m_zpos.head());
        emit update_UIScatter(m_xpos.dequeue(),m_ypos.dequeue(),m_zpos.dequeue());
    }
    // Model3d
    if (!m_roll.isEmpty() && !m_pitch.isEmpty() && !m_yaw.isEmpty()){
        emit update_UILog(m_roll.head());
        emit update_UILog(m_pitch.head());
        emit update_UILog(m_yaw.head());
        emit update_UIModel3D(m_roll.dequeue(),m_pitch.dequeue(),m_yaw.dequeue());
    }
}
