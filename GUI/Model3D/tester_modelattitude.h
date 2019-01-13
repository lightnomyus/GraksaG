#ifndef TESTER_MODELATTITUDE_H
#define TESTER_MODELATTITUDE_H

#include <QObject>

class Tester_ModelAttitude : public QObject
{
    Q_OBJECT
public:
    explicit Tester_ModelAttitude(QObject *parent = nullptr);
    Q_INVOKABLE void send_Data(float roll, float pitch, float yaw);

signals:
    void incoming_Data(float roll, float pitch, float yaw);

public slots:
};

#endif // TESTER_MODELATTITUDE_H
