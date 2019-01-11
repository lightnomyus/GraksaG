#include "api_protocolhandler.h"

API_ProtocolHandler::API_ProtocolHandler(QObject *parent) : QObject(parent)
{
    m_byteCounter = 0;
    m_maxCounter = 999;
}

void API_ProtocolHandler::receive_DataByte(QByteArray data)
{
    if (m_byteCounter >= m_maxCounter) {
        m_maxCounter = 999;
        m_byteCounter = 0;
        m_data.clear();
    }
    m_data.append(data[0]);
    m_byteCounter += 1;
    switch (m_byteCounter) {
    case 1:
        if (static_cast<uint8_t>(m_data[m_byteCounter-1]) == m_comparison.header.SOF) {
            break;
        } else {
            m_byteCounter = 0;
            m_data.clear();
            break;
        }
    case 2:
        if (static_cast<uint8_t>(m_data[m_byteCounter-1]) == m_comparison.header.Team_ID[0]) {
            break;
        } else {
            m_byteCounter = 0;
            m_data.clear();
            break;
        }
    case 3:
        if (static_cast<uint8_t>(m_data[m_byteCounter-1]) == m_comparison.header.Team_ID[1]) {
            break;
        } else {
            m_byteCounter = 0;
            m_data.clear();
            break;
        }
    case 4:
        if (static_cast<uint8_t>(m_data[m_byteCounter-1]) == m_comparison.header.Team_ID[2]) {
            break;
        } else {
            m_byteCounter = 0;
            m_data.clear();
            break;
        }
    case 5:
        if (static_cast<uint8_t>(m_data[m_byteCounter-1]) <= 15) {
            m_comparison.header.Message_ID = static_cast<uint8_t>(m_data[m_byteCounter-1]);
            if (m_comparison.header.Message_ID == GRAKSA_MSG_ID_LAT || m_comparison.header.Message_ID == GRAKSA_MSG_ID_LON) {
                m_maxCounter = m_byteCounter + 8;
            } else {
                m_maxCounter = m_byteCounter + 4;
            }
            break;
        } else {
            m_byteCounter = 0;
            m_data.clear();
            break;
        }
    default:
        if (m_byteCounter >= m_maxCounter) {
            m_messageReceived = static_cast<message>(m_data);
            break;
        } else {
            break;
        }

    }

}

void API_ProtocolHandler::set_TeamId(QString id)
{
    QByteArray convertion = id.toLocal8Bit();
    for (int i=0; i<3; i++){
        m_teamId[i] = static_cast <uint8_t> (convertion[i]);
    }
    construct_Header(&m_comparison,0xd,m_teamId);

}
