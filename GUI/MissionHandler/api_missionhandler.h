#ifndef API_MISSIONHANDLER_H
#define API_MISSIONHANDLER_H

#include <QObject>

class API_MissionHandler : public QObject
{
    Q_OBJECT
public:
    explicit API_MissionHandler(QObject *parent = nullptr);
    Q_INVOKABLE void new_mission(QString missionName);
    Q_INVOKABLE void get_fileName(QString path);
    Q_INVOKABLE void start_mission();
    Q_INVOKABLE void stop_mission();
    Q_INVOKABLE void replay_mission();
    Q_INVOKABLE void start_dataAqc();
    Q_INVOKABLE void stop_dataAqc();
    Q_INVOKABLE void take_picture();

signals:
    void send_MissionName(QString missionName);
    void command_StartMission();
    void command_StopMission();
    void command_ReplayMission();
    void command_StartDataAqc();
    void command_StopDataAqc();
    void command_TakePicture();

public slots:
};

#endif // API_MISSIONHANDLER_H
