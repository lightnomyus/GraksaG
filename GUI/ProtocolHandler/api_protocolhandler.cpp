#include "api_protocolhandler.h"
#include <QtDebug>

API_ProtocolHandler::API_ProtocolHandler(QObject *parent) : QObject(parent)
{
    m_teamId[0]='I';
    m_teamId[1]='T';
    m_teamId[2]='B';
    m_msgId = 99;
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
        if (static_cast<uint8_t>(m_data[m_byteCounter-1]) == 0xd) {
            break;
        } else {
            m_byteCounter = 0;
            m_data.clear();
            break;
        }
    case 2:
        if (static_cast<uint8_t>(m_data[m_byteCounter-1]) == m_teamId[0]) {
            break;
        } else {
            m_byteCounter = 0;
            m_data.clear();
            break;
        }
    case 3:
        if (static_cast<uint8_t>(m_data[m_byteCounter-1]) == m_teamId[1]) {
            break;
        } else {
            m_byteCounter = 0;
            m_data.clear();
            break;
        }
    case 4:
        if (static_cast<uint8_t>(m_data[m_byteCounter-1]) == m_teamId[2]) {
            break;
        } else {
            m_byteCounter = 0;
            m_data.clear();
            break;
        }
    case 5:
        if ((m_msgId = static_cast<uint8_t>(m_data[m_byteCounter-1])) <= 15) {
            if (m_msgId == GRAKSA_MSG_ID_LAT || m_msgId == GRAKSA_MSG_ID_LON) {
                m_maxCounter = m_byteCounter + 8; // double
            } else {
                m_maxCounter = m_byteCounter + 4; // float
            }
            break;
        } else {
            m_byteCounter = 0;
            m_data.clear();
            break;
        }
    default:
        if (m_byteCounter == m_maxCounter) {
            float container_float;
            double container_double;
            char *p_payload;
            p_payload = m_data.data();
            switch (m_msgId) {
            case GRAKSA_MSG_ID_AX:
                memcpy(&container_float, &(p_payload[5]), sizeof (float));
                qDebug()<<"AX: "<<container_float;
                m_ax.enqueue(container_float);
                break;
            case GRAKSA_MSG_ID_AY:
                memcpy(&container_float, &(p_payload[5]), sizeof (float));
                qDebug()<<"AY: "<<container_float;
                m_ay.enqueue(container_float);
                break;
            case GRAKSA_MSG_ID_AZ:
                memcpy(&container_float, &(p_payload[5]), sizeof (float));
                qDebug()<<"AZ: "<<container_float;
                m_az.enqueue(container_float);
                break;
            case GRAKSA_MSG_ID_GX:
                memcpy(&container_float, &(p_payload[5]), sizeof (float));
                qDebug()<<"GX: "<<container_float;
                m_gx.enqueue(container_float);
                break;
            case GRAKSA_MSG_ID_GY:
                memcpy(&container_float, &(p_payload[5]), sizeof (float));
                qDebug()<<"GY: "<<container_float;
                m_gy.enqueue(container_float);
                break;
            case GRAKSA_MSG_ID_GZ:
                memcpy(&container_float, &(p_payload[5]), sizeof (float));
                qDebug()<<"GZ: "<<container_float;
                m_gz.enqueue(container_float);
                break;
            case GRAKSA_MSG_ID_ALT:
                memcpy(&container_float, &(p_payload[5]), sizeof (float));
                qDebug()<<"ALT: "<<container_float;
                m_alt.enqueue(container_float);
                break;
            case GRAKSA_MSG_ID_LON:
                memcpy(&container_double, &(p_payload[5]), sizeof (double));
                qDebug()<<"LON: "<<container_double;
                m_lon.enqueue(container_double);
                break;
            case GRAKSA_MSG_ID_LAT:
                memcpy(&container_double, &(p_payload[5]), sizeof (double));
                qDebug()<<"LAT: "<<container_double;
                m_lat.enqueue(container_double);
                break;
            case GRAKSA_MSG_ID_PHOTO:
                // masih gatau
                break;
            case GRAKSA_MSG_ID_XPOS:
                memcpy(&container_float, &(p_payload[5]), sizeof (float));
                m_xpos.enqueue(container_float);
                break;
            case GRAKSA_MSG_ID_YPOS:
                memcpy(&container_float, &(p_payload[5]), sizeof (float));
                m_ypos.enqueue(container_float);
                break;
            case GRAKSA_MSG_ID_ZPOS:
                memcpy(&container_float, &(p_payload[5]), sizeof (float));
                m_zpos.enqueue(container_float);
                break;
            case GRAKSA_MSG_ID_ROLL:
                memcpy(&container_float, &(p_payload[5]), sizeof (float));
                m_roll.enqueue(container_float);
                break;
            case GRAKSA_MSG_ID_PITCH:
                memcpy(&container_float, &(p_payload[5]), sizeof (float));
                m_pitch.enqueue(container_float);
                break;
            case GRAKSA_MSG_ID_YAW:
                memcpy(&container_float, &(p_payload[5]), sizeof (float));
                m_yaw.enqueue(container_float);
                break;
            default:
                // should never be here
                break;
            }
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
}
