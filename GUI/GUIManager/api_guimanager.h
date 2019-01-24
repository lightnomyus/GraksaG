#ifndef API_GUIMANAGER_H
#define API_GUIMANAGER_H

#include <QObject>
#include <QQueue>
#include <QTimer>

class API_GUIManager : public QObject
{
    Q_OBJECT
public:
    explicit API_GUIManager(QObject *parent = nullptr);

signals:
    void update_UIScatter(float xpos, float ypos, float zpos);
    void update_UISpline1(float launch_angle, float range, float alt);
    void update_UILog(float data);
    void update_UILog(double data);
    void update_UIMap(double lon, double lat);
    void update_UIModel3D(float roll, float pitch, float yaw);
    void update_UIApogee(float apogee);

public slots:
    void update_UIAll();
    void receive_Attitude(float roll, float pitch, float yaw);
    void receive_Altitude(float alt);
    void receive_Coordinate(double lon, double lat);
    void receive_Odometry(float xpos, float ypos, float zpos);

private:
    QTimer m_timer;
    QQueue<float> m_roll;
    QQueue<float> m_pitch;
    QQueue<float> m_yaw;
    QQueue<float> m_alt;
    QQueue<float> m_xpos;
    QQueue<float> m_ypos;
    QQueue<float> m_zpos;
    QQueue<double> m_lon;
    QQueue<double> m_lat;
};

#endif // API_GUIMANAGER_H