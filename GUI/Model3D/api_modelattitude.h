#ifndef API_MODELATTITUDE_H
#define API_MODELATTITUDE_H

#include <QObject>

class API_ModelAttitude : public QObject
{
    Q_OBJECT
public:
    explicit API_ModelAttitude(QObject *parent = nullptr);

signals:
    void update_UI(float roll, float pitch, float yaw);

public slots:
    void receive_Attitude(float roll, float pitch, float yaw);
};

#endif // API_MODELATTITUDE_H
