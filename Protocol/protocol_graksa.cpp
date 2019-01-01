#include "protocol_graksa.h"

Protocol_Graksa::Protocol_Graksa()
{

}

uint8_t Protocol_Graksa::construct_MSG_AX(protocol_message_t *output, float *ax)
{
    output->header.Message_ID = GRAKSA_MSG_ID_AX;
    int size = sizeof (*ax);
    output->payload = malloc(size);
    memcpy(output->payload, ax, size);
    return 1;
}

uint8_t Protocol_Graksa::construct_MSG_AY(protocol_message_t *output, float *ay)
{
    output->header.Message_ID = GRAKSA_MSG_ID_AY;
    int size = sizeof (*ay);
    output->payload = malloc(size);
    memcpy(output->payload, ay, size);
    return 1;
}

uint8_t Protocol_Graksa::construct_MSG_AZ(protocol_message_t *output, float *az)
{
    output->header.Message_ID = GRAKSA_MSG_ID_AZ;
    int size = sizeof (*az);
    output->payload = malloc(size);
    memcpy(output->payload, az, size);
    return 1;
}

uint8_t Protocol_Graksa::construct_MSG_GX(protocol_message_t *output, float *gx)
{
    output->header.Message_ID = GRAKSA_MSG_ID_GX;
    int size = sizeof (*gx);
    output->payload = malloc(size);
    memcpy(output->payload, gx, size);
    return 1;
}
