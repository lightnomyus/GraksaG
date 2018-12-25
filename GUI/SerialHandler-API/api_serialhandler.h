#ifndef API_SERIALHANDLER_H
#define API_SERIALHANDLER_H

#include <QObject>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QList>

class API_SerialHandler : public QObject
{
    Q_OBJECT
public:
    explicit API_SerialHandler(QObject *parent = nullptr);
    Q_INVOKABLE void open_serial();
    Q_INVOKABLE void close_serial();
    Q_INVOKABLE void scan_serial();

signals:

public slots:

private:
    bool m_isActive;
    QSerialPort m_serial;
    QList<QSerialPortInfo> m_infos;
};

#endif // API_SERIALHANDLER_H
