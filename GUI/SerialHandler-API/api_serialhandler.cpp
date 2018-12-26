#include "api_serialhandler.h"

API_SerialHandler::API_SerialHandler(QObject *parent) : QObject(parent)
{
    m_isActive = false;
    m_infos = QSerialPortInfo::availablePorts();
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


