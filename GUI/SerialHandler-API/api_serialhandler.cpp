#include "api_serialhandler.h"
#include <QtDebug>

API_SerialHandler::API_SerialHandler(QObject *parent) : QObject(parent)
{
    m_isActive = false;
    connect(this,SIGNAL(changed_list()),this,SLOT(update_list()));
    connect(&m_serial,SIGNAL(readyRead()),this,SLOT(read_DataBytes()));

}

void API_SerialHandler::open_serial()
{
    if (!m_isActive) {
        m_serial.open(QIODevice::ReadWrite);
        m_message = "SUCCED: Koneksi serial baru berhasil dibuat.";
        emit message_SerialHandler(m_message);
    } else {
        m_message = "FAILED: Putuskan koneksi serial terlebih dahulu sebelum membuat koneksi serial baru.";
        emit message_SerialHandler(m_message);
    }
}

void API_SerialHandler::close_serial()
{
    if (m_isActive) {
        m_serial.close();
        m_message = "SUCCED: Koneksi serial berhasil diputuskan.";
        emit message_SerialHandler(m_message);
    } else {
        m_message = "FAILED: Tidak ada koneksi serial untuk diputuskan.";
        emit message_SerialHandler(m_message);
    }
}

void API_SerialHandler::scan_serial()
{
    if (!m_isActive) {
        m_infos.clear();
        auto infos = QSerialPortInfo::availablePorts();
        for (int i = 0; i < infos.count(); i++) {
            m_infos.append(infos[i]);
        }
        emit changed_list();
        m_message = "SUCCED: Scanning serial port selesai.";
        emit message_SerialHandler(m_message);
    } else {
        m_message = "FAILED: Scanning bisa dimulai ketika semua koneksi serikal dimatikan.";
        emit message_SerialHandler(m_message);
    }
}

void API_SerialHandler::set_serial(QString selected)
{
    if (!m_isActive) {
        int i = 0;
        while (selected != m_infos[i].portName()) {
            i++;
        }
        m_serial.setPort(m_infos[i]);
    } else {
        m_message = "FAILED: Putuskan koneksi saat ini terlebih dahulu.";
        emit message_SerialHandler(m_message);
    }
}

void API_SerialHandler::set_baud(qint32 baud)
{
    if (!m_isActive) {
        m_serial.setBaudRate(baud);
    } else {
        m_message = "FAILED: Putuskan koneksi saat ini terlebih dahulu.";
        emit message_SerialHandler(m_message);
    }
}

void API_SerialHandler::set_databits(int databits)
{
    if (!m_isActive) {
        switch (databits) {
        case 5: m_serial.setDataBits(QSerialPort::Data5);break;
        case 6: m_serial.setDataBits(QSerialPort::Data6);break;
        case 7: m_serial.setDataBits(QSerialPort::Data7);break;
        case 8: m_serial.setDataBits(QSerialPort::Data8);break;
        }
    } else {
        m_message = "FAILED: Putuskan koneksi saat ini terlebih dahulu.";
        emit message_SerialHandler(m_message);
    }
}

void API_SerialHandler::set_parity(int parity)
{
    if (!m_isActive) {
        switch (parity) {
        case 0: m_serial.setParity(QSerialPort::NoParity);break;
        case 1: m_serial.setParity(QSerialPort::OddParity);break;
        case 2: m_serial.setParity(QSerialPort::EvenParity);break;
        }
    } else {
        m_message = "FAILED: Putuskan koneksi saat ini terlebih dahulu.";
        emit message_SerialHandler(m_message);
    }
}

void API_SerialHandler::set_stopbits(int stopbits)
{
    if (!m_isActive) {
        switch (stopbits) {
        case 1: m_serial.setStopBits(QSerialPort::OneStop);break;
        case 2: m_serial.setStopBits(QSerialPort::TwoStop);break;
        }
    } else {
        m_message = "FAILED: Putuskan koneksi saat ini terlebih dahulu.";
        emit message_SerialHandler(m_message);
    }
}

// SLOT

void API_SerialHandler::update_list()
{
    m_list.clear();
    for (int i= 0 ; i<m_infos.count() ; i++) {
        m_list.append(m_infos[i].portName());
    }
    emit update_UI(m_list);
}

void API_SerialHandler::read_DataBytes()
{
    m_data = m_serial.readAll();
    emit send_DataByte(m_data);
}

void API_SerialHandler::write_DataBytes(QByteArray data)
{
    m_serial.write(data);
}
