#include "protocol_graksa.h"

Protocol_Graksa::Protocol_Graksa()
{

}

int8_t Protocol_Graksa::construct_MSG_AX(protocol_message_t *output, float *ax)
{
    output->header.Message_ID = GRAKSA_MSG_ID_AX;
    size_t size = sizeof (*ax);
    output->payload = (uint8_t*) malloc(size);
    memcpy(output->payload, ax, size);
    return 1;
}

int8_t Protocol_Graksa::construct_MSG_AY(protocol_message_t *output, float *ay)
{
    output->header.Message_ID = GRAKSA_MSG_ID_AY;
    size_t size = sizeof (*ay);
    output->payload = (uint8_t*) malloc(size);
    memcpy(output->payload, ay, size);
    return 1;
}

int8_t Protocol_Graksa::construct_MSG_AZ(protocol_message_t *output, float *az)
{
    output->header.Message_ID = GRAKSA_MSG_ID_AZ;
    size_t size = sizeof (*az);
    output->payload = (uint8_t*) malloc(size);
    memcpy(output->payload, az, size);
    return 1;
}

int8_t Protocol_Graksa::construct_MSG_GX(protocol_message_t *output, float *gx)
{
    output->header.Message_ID = GRAKSA_MSG_ID_GX;
    size_t size = sizeof (*gx);
    output->payload = (uint8_t*) malloc(size);
    memcpy(output->payload, gx, size);
    return 1;
}

int8_t Protocol_Graksa::construct_MSG_GY(protocol_message_t *output, float *gy)
{
    output->header.Message_ID = GRAKSA_MSG_ID_GY;
    size_t size = sizeof (*gy);
    output->payload = (uint8_t*) malloc(size);
    memcpy(output->payload, gy, size);
    return 1;
}

int8_t Protocol_Graksa::construct_MSG_GZ(protocol_message_t *output, float *gz)
{
    output->header.Message_ID = GRAKSA_MSG_ID_GZ;
    size_t size = sizeof (*gz);
    output->payload = (uint8_t*) malloc(size);
    memcpy(output->payload, gz, size);
    return 1;
}

int8_t Protocol_Graksa::construct_MSG_ALT(protocol_message_t *output, float *alt)
{
    output->header.Message_ID = GRAKSA_MSG_ID_ALT;
    size_t size = sizeof (*alt);
    output->payload = (uint8_t*) malloc(size);
    memcpy(output->payload, alt, size);
    return 1;
}

int8_t Protocol_Graksa::construct_MSG_LAT(protocol_message_t *output, double *lat)
{
    output->header.Message_ID = GRAKSA_MSG_ID_LAT;
    size_t size = sizeof (*lat);
    output->payload = (uint8_t*) malloc(size);
    memcpy(output->payload, lat, size);
    return 1;
}

int8_t Protocol_Graksa::construct_MSG_LON(protocol_message_t *output, double *lon)
{
    output->header.Message_ID = GRAKSA_MSG_ID_LON;
    size_t size = sizeof (*lon);
    output->payload = (uint8_t*) malloc(size);
    memcpy(output->payload, lon, size);
    return 1;
}

int8_t Protocol_Graksa::deconstruct_MSG_AX(protocol_message_t *input, float *ax)
{
    memcpy(ax,input->payload,sizeof (*ax));
    return 1;
}

int8_t Protocol_Graksa::deconstruct_MSG_AY(protocol_message_t *input, float *ay)
{
    memcpy(ay,input->payload,sizeof (*ay));
    return 1;
}

int8_t Protocol_Graksa::deconstruct_MSG_AZ(protocol_message_t *input, float *az)
{
    memcpy(az,input->payload,sizeof (*az));
    return 1;
}

int8_t Protocol_Graksa::deconstruct_MSG_GX(protocol_message_t *input, float *gx)
{
    memcpy(gx,input->payload,sizeof (*gx));
    return 1;
}

int8_t Protocol_Graksa::deconstruct_MSG_GY(protocol_message_t *input, float *gy)
{
    memcpy(gy,input->payload,sizeof (*gy));
    return 1;
}

int8_t Protocol_Graksa::deconstruct_MSG_GZ(protocol_message_t *input, float *gz)
{
    memcpy(gz,input->payload,sizeof (*gz));
    return 1;
}

int8_t Protocol_Graksa::deconstruct_MSG_ALT(protocol_message_t *input, float *alt)
{
    memcpy(alt,input->payload,sizeof (*alt));
    return 1;
}

int8_t Protocol_Graksa::deconstruct_MSG_LAT(protocol_message_t *input, double *lat)
{
    memcpy(lat,input->payload,sizeof (*lat));
    return 1;
}

int8_t Protocol_Graksa::deconstruct_MSG_LON(protocol_message_t *input, double *lon)
{
    memcpy(lon,input->payload,sizeof (*lon));
    return 1;
}
