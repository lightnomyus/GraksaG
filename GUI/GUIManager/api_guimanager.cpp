#include "api_guimanager.h"

API_GUIManager::API_GUIManager(QObject *parent) : QObject(parent)
{
    m_timer = new QTimer(this);
    QObject::connect(m_timer,&QTimer::timeout,this,&API_GUIManager::update_UIAll);
    m_timer->start(50);
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
    float temp_alt, temp_roll, temp_pitch, temp_yaw, temp_xpos, temp_ypos, temp_zpos;
    double temp_lon, temp_lat;
    float temp_apogee = -1;
    // Pengecekan isEmpty dari queue
    if (!m_alt.isEmpty()){
        temp_alt = m_alt.dequeue();
    } else {
        temp_alt = EMPTY_NUMBER;
    }
    if (!m_lon.isEmpty() && !m_lat.isEmpty()){
        temp_lon = m_lon.dequeue();
        temp_lat = m_lat.dequeue();
    } else {
        temp_lon = EMPTY_NUMBER;
        temp_lat = EMPTY_NUMBER;
    }
    if (!m_xpos.isEmpty() && !m_ypos.isEmpty() && !m_zpos.isEmpty()){
        temp_xpos = m_xpos.dequeue();
        temp_ypos = m_ypos.dequeue();
        temp_zpos = m_zpos.dequeue();
    } else {
        temp_xpos = EMPTY_NUMBER;
        temp_ypos = EMPTY_NUMBER;
        temp_zpos = EMPTY_NUMBER;
    }
    if (!m_roll.isEmpty() && !m_pitch.isEmpty() && !m_yaw.isEmpty()){
        temp_roll = m_roll.dequeue();
        temp_pitch = m_pitch.dequeue();
        temp_yaw = m_yaw.dequeue();
    } else {
        temp_roll = EMPTY_NUMBER;
        temp_pitch = EMPTY_NUMBER;
        temp_yaw = EMPTY_NUMBER;
    }

    // Storage
    emit update_Storage(temp_alt, temp_lon, temp_lat,
                        temp_roll, temp_pitch, temp_yaw,
                        temp_xpos, temp_ypos, temp_zpos);
    // Apogee
    if (static_cast<int>(temp_alt) != EMPTY_NUMBER){
        if (temp_alt > temp_apogee) {
            temp_apogee = temp_alt;
            emit update_UIApogee(temp_apogee);
        }
        emit update_UILog(ALT_LOG_ID, temp_alt);
    }
    // MAP
    if ((static_cast<int>(temp_lon) != EMPTY_NUMBER)
            && (static_cast<int>(temp_lat) != EMPTY_NUMBER)){
        emit update_UILog(LON_LOG_ID, temp_lon);
        emit update_UILog(LAT_LOG_ID, temp_lat);
        emit update_UIMap(temp_lon, temp_lat);
    }
    // Scatter
    if ((static_cast<int>(temp_xpos) != EMPTY_NUMBER)
            && (static_cast<int>(temp_ypos) != EMPTY_NUMBER)
            && (static_cast<int>(temp_zpos) != EMPTY_NUMBER)){
        emit update_UILog(XPOS_LOG_ID, temp_xpos);
        emit update_UILog(YPOS_LOG_ID, temp_ypos);
        emit update_UILog(ZPOS_LOG_ID, temp_zpos);
        emit update_UIScatter(temp_xpos, temp_ypos, temp_zpos);
    }
    // Model3d
    if ((static_cast<int>(temp_roll) != EMPTY_NUMBER)
            && (static_cast<int>(temp_pitch) != EMPTY_NUMBER)
            && (static_cast<int>(temp_yaw) != EMPTY_NUMBER)){
        emit update_UILog(ROLL_LOG_ID, temp_roll);
        emit update_UILog(PITCH_LOG_ID, temp_pitch);
        emit update_UILog(YAW_LOG_ID, temp_yaw);
        emit update_UIModel3D(temp_roll, temp_pitch, temp_yaw);
    }
    // Spline
    if ((static_cast<int>(temp_pitch) != EMPTY_NUMBER)
            && (static_cast<int>(temp_xpos) != EMPTY_NUMBER)
            && (static_cast<int>(temp_ypos) != EMPTY_NUMBER)
            && (static_cast<int>(temp_zpos) != EMPTY_NUMBER)){
        emit update_UISpline1(temp_pitch,static_cast<float>(qSqrt(qPow(static_cast<double>(temp_xpos),2) +
                                               qPow(static_cast<double>(temp_ypos),2))),temp_alt);
    }
}
