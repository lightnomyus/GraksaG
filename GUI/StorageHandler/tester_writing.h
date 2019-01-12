#ifndef TESTER_WRITING_H
#define TESTER_WRITING_H

#include <QObject>

class Tester_Writing : public QObject
{
    Q_OBJECT
public:
    explicit Tester_Writing(QObject *parent = nullptr);
    Q_INVOKABLE void command_StartWriting();
    Q_INVOKABLE void command_EndWriting();
    Q_INVOKABLE void command_NewMission(QString missionName);
    Q_INVOKABLE void send_Data(float alt, double lon, double lat,
                               float roll, float pitch, float yaw,
                               float xpos, float ypos, float zpos);

signals:
    void incoming_Data(float alt, double lon, double lat,
                       float roll, float pitch, float yaw,
                       float xpos, float ypos, float zpos);
    void start_Writing();
    void end_Writing();
    void new_Name(QString missionName);

public slots:
};

#endif // TESTER_WRITING_H
