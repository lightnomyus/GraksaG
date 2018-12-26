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
    Q_INVOKABLE void set_serial(QSerialPort selected);
    Q_INVOKABLE void set_baud(qint32 baud);
    Q_INVOKABLE void set_databits(int databits);
    Q_INVOKABLE void set_parity(int parity);
    Q_INVOKABLE void set_stopbits(int stopbits);

signals:
    void message_SerialHandler(QString message);
    void send_DataByte(QByteArray data);

public slots:
    void read_DataBytes();
    void write_DataBytes(QByteArray data);

private:
    QString m_message;
    bool m_isActive;
    QSerialPort m_serial;
    QList<QSerialPortInfo> m_infos;
};

#endif // API_SERIALHANDLER_H
