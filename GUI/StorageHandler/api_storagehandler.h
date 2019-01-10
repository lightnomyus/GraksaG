#ifndef API_STORAGEHANDLER_H
#define API_STORAGEHANDLER_H

#include <QObject>
#include <QDir>
#include <QFile>
#include <QTextStream>

class API_StorageHandler : public QObject
{
    Q_OBJECT
public:
    explicit API_StorageHandler(QObject *parent = nullptr);

signals:
    void update_UI_MissionLog(QString message);
    void update_UI_Altitude(QString message);
    void update_UI_RelativeRange(QString message);
    void update_UI_MapPosition(QString message);
    void update_UI_Gyro(QString message);
    void update_UI_Accel(QString message);
    void update_UI_Attitude(QString message);

public slots:
    void update_MissionName(QString missionName);
    void write_MissionLog(QString message);
    void write_Altitude(float alt);
    void write_RelativeRange(float range);
    void write_MapPosition(double langitude, double latitude);
    void write_Gyro(float gx, float gy, float gz);
    void write_Accel(float ax, float ay, float az);
    void write_Attitude(float roll, float pitch, float yaw);
    void read_MissionLog();
    void read_Altitude();
    void read_RelativeRange();
    void read_MapPosition();
    void read_Gyro();
    void read_Accel();
    void read_Attitude();

private:
    QString m_missionName;
    bool m_isWrite;
    QFile m_file;
};

#endif // API_STORAGEHANDLER_H
