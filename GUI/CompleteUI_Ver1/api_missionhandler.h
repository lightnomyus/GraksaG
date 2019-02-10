#ifndef API_MISSIONHANDLER_H
#define API_MISSIONHANDLER_H

#include <QObject>
#include <QTime>

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
    Q_INVOKABLE void start_datAcq();
    Q_INVOKABLE void stop_dataAcq();
    Q_INVOKABLE void take_picture();

signals:
    void send_MissionName(QString missionName);
    void command_StartMission();
    void command_StopMission();
    void command_ReplayMission();
    void command_StartDataAcq();
    void command_StopDataAcq();
    void command_TakePicture();
    void notif_Log(QString message);

public slots:
    void notif_EndReplay();

private:
    QTime m_time;
    QString m_message;
};

#endif // API_MISSIONHANDLER_H
