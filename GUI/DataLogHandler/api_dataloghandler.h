#ifndef API_DATALOGHANDLER_H
#define API_DATALOGHANDLER_H

#include <QObject>

class API_DataLogHandler : public QObject
{
    Q_OBJECT
public:
    explicit API_DataLogHandler(QObject *parent = nullptr);
    Q_INVOKABLE void set_activeAltitude(bool checked);
    Q_INVOKABLE void set_activeAttitude(bool checked);
    Q_INVOKABLE void set_active3DPosition(bool checked);
    Q_INVOKABLE void set_activeCoordinate(bool checked);

signals:
    void message_DataLog(QString m_message);

public slots:
    void receive_DataLog(int id, float data);
    void receive_DataLog(int id, double data);

private:
    bool m_activeAltitude;
    bool m_activeAttitude;
    bool m_active3DPosition;
    bool m_activeCoordinate;

};

#endif // API_DATALOGHANDLER_H
