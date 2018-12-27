#include "api_serialhandler.h"

API_SerialHandler::API_SerialHandler(QObject *parent) : QObject(parent)
{
    m_isActive = false;
    m_infos = QSerialPortInfo::availablePorts();
    connect(this,SIGNAL(changed_list()),this,SLOT(update_list()));
    connect(&m_serial,SIGNAL(readyRead()),this,SLOT(read_DataBytes()));
    emit changed_list();

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
        m_infos = QSerialPortInfo::availablePorts();
        m_message = "SUCCED: Scanning serial port selesai.";
        emit message_SerialHandler(m_message);
    } else {
        m_message = "FAILED: Scanning bisa dimulai ketika semua koneksi serikal dimatikan.";
        emit message_SerialHandler(m_message);
    }
}

// SLOT

void API_SerialHandler::update_list()
{
    for (int i=0 ; i<m_infos.count() ; i++)
    {
        m_list[i] = m_infos[i].portName();
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
