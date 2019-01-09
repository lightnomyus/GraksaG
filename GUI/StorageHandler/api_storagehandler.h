#ifndef API_STORAGEHANDLER_H
#define API_STORAGEHANDLER_H

#include <QObject>

class API_StorageHandler : public QObject
{
    Q_OBJECT
public:
    explicit API_StorageHandler(QObject *parent = nullptr);

signals:

public slots:
    void write_MissionLog(QString message);
    void write_Altitude(float alt);
    void write_RelativeRange(float range);
    void write_MapPosition(double langitude, double latitude);
    void write_Gyro(float gx, float gy, float gz);
    void write_Accel(float ax, float ay, float az);
    void write_Attitude(float roll, float pitch, float yaw);
};

#endif // API_STORAGEHANDLER_H
