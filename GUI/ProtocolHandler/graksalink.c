#include "graksalink.h"

/* Construct Header */
void construct_Header(message_t *output, uint8_t SOF, uint8_t Team_ID[3])
{
    output->header.SOF = SOF;
    for (int i=0; i<3; i++) {
        output->header.Team_ID[i] = Team_ID[i];
    }
}

/* Construct Message */
void construct_MSG_AX(message_t *output, float *ax)
{
    output->header.Message_ID = GRAKSA_MSG_ID_AX;
    size_t size = sizeof (*ax);
    output->payload = (uint8_t*) malloc(size);
    memcpy(output->payload, ax, size);
}

void construct_MSG_AY(message_t *output, float *ay)
{
    output->header.Message_ID = GRAKSA_MSG_ID_AY;
    size_t size = sizeof (*ay);
    output->payload = (uint8_t*) malloc(size);
    memcpy(output->payload, ay, size);
}

void construct_MSG_AZ(message_t *output, float *az)
{
    output->header.Message_ID = GRAKSA_MSG_ID_AZ;
    size_t size = sizeof (*az);
    output->payload = (uint8_t*) malloc(size);
    memcpy(output->payload, az, size);
}

void construct_MSG_GX(message_t *output, float *gx)
{
    output->header.Message_ID = GRAKSA_MSG_ID_GX;
    size_t size = sizeof (*gx);
    output->payload = (uint8_t*) malloc(size);
    memcpy(output->payload, gx, size);
}

void construct_MSG_GY(message_t *output, float *gy)
{
    output->header.Message_ID = GRAKSA_MSG_ID_GY;
    size_t size = sizeof (*gy);
    output->payload = (uint8_t*) malloc(size);
    memcpy(output->payload, gy, size);
}

void construct_MSG_GZ(message_t *output, float *gz)
{
    output->header.Message_ID = GRAKSA_MSG_ID_GZ;
    size_t size = sizeof (*gz);
    output->payload = (uint8_t*) malloc(size);
    memcpy(output->payload, gz, size);
}

void construct_MSG_ALT(message_t *output, float *alt)
{
    output->header.Message_ID = GRAKSA_MSG_ID_ALT;
    size_t size = sizeof (*alt);
    output->payload = (uint8_t*) malloc(size);
    memcpy(output->payload, alt, size);
}

void construct_MSG_LON(message_t *output, double *lon)
{
    output->header.Message_ID = GRAKSA_MSG_ID_LON;
    size_t size = sizeof (*lon);
    output->payload = (uint8_t*) malloc(size);
    memcpy(output->payload, lon, size);
}

void construct_MSG_LAT(message_t *output, double *lat)
{
    output->header.Message_ID = GRAKSA_MSG_ID_LAT;
    size_t size = sizeof (*lat);
    output->payload = (uint8_t*) malloc(size);
    memcpy(output->payload, lat, size);
}

/* Deconstruct Message */
void deconstruct_MSG_AX(message_t *input, float *ax)
{
    memcpy(ax,input->payload,sizeof (*ax));
}

void deconstruct_MSG_AY(message_t *input, float *ay)
{
    memcpy(ay,input->payload,sizeof (*ay));
}

void deconstruct_MSG_AZ(message_t *input, float *az)
{
    memcpy(az,input->payload,sizeof (*az));
}

void deconstruct_MSG_GX(message_t *input, float *gx)
{
    memcpy(gx,input->payload,sizeof (*gx));
}

void deconstruct_MSG_GY(message_t *input, float *gy)
{
    memcpy(gy,input->payload,sizeof (*gy));
}

void deconstruct_MSG_GZ(message_t *input, float *gz)
{
    memcpy(gz,input->payload,sizeof (*gz));
}

void deconstruct_MSG_ALT(message_t *input, float *alt)
{
    memcpy(alt,input->payload,sizeof (*alt));
}

void deconstruct_MSG_LON(message_t *input, double *lon)
{
    memcpy(lon,input->payload,sizeof (*lon));
}

void deconstruct_MSG_LAT(message_t *input, double *lat)
{
    memcpy(lat,input->payload,sizeof (*lat));
}
