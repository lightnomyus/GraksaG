#ifndef API_DATALOGHANDLER_H
#define API_DATALOGHANDLER_H

#include <QObject>
#include "define_gui.h"

class API_DataLogHandler : public QObject
{
    Q_OBJECT
public:
    explicit API_DataLogHandler(QObject *parent = nullptr);
    Q_INVOKABLE void set_activeAltitude(bool checked);
    Q_INVOKABLE void set_activeAttitude(bool checked);
    Q_INVOKABLE void set_active3DPosition(bool checked);
    Q_INVOKABLE void set_activeCoordinate(bool checked);
    Q_INVOKABLE void set_activeAccel(bool checked);
    Q_INVOKABLE void set_activeGyro(bool checked);

signals:
    void message_DataLog(QString m_message);

public slots:
    void receive_DataLogF(int id, float data);
    void receive_DataLogD(int id, double data);

private:
    QString m_message;
    bool m_activeAltitude;
    bool m_activeAttitude;
    bool m_active3DPosition;
    bool m_activeCoordinate;
    bool m_activeAccel;
    bool m_activeGyro;

};

#endif // API_DATALOGHANDLER_H
