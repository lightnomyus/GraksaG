#ifndef PROTOCOL_GRAKSA_H
#define PROTOCOL_GRAKSA_H

/*
 * STRUKTUR MESSAGE
 * BYTE 1           Start of Frame
 * BYTE 2-4         Team Identifiacion
 * BYTE 5           Message Identification
 * BYTE 6-n         Payload
*/

/* Library used */
#include <cstdint>
#include <cstring>
#include <cstdlib>

/* Message ID Detail */
#define GRAKSA_MSG_ID_AX 0
#define GRAKSA_MSG_ID_AY 1
#define GRAKSA_MSG_ID_AZ 2
#define GRAKSA_MSG_ID_GX 3
#define GRAKSA_MSG_ID_GY 4
#define GRAKSA_MSG_ID_GZ 5
#define GRAKSA_MSG_ID_ALT 6
#define GRAKSA_MSG_ID_LON 7
#define GRAKSA_MSG_ID_LAT 8
#define GRAKSA_MSG_ID_PHOTO 9
#define GRAKSA_MSG_ID_XPOS 10
#define GRAKSA_MSG_ID_YPOS 11
#define GRAKSA_MSG_ID_ZPOS 12
#define GRAKSA_MSG_ID_ROLL 13
#define GRAKSA_MSG_ID_PITCH 14
#define GRAKSA_MSG_ID_YAW 15

typedef struct protocol_header {
    uint8_t SOF = 0xd;
    char Team_ID[3] = {'I','T','B'};
    uint8_t Message_ID;
} protocol_header_t;

typedef struct protocol_message {
    protocol_header_t header;
    uint8_t *payload;
} protocol_message_t;

class Protocol_Graksa
{
public:
    Protocol_Graksa();
    /* Construct Message */
    int8_t construct_MSG_AX(protocol_message_t *output, float *ax);
    int8_t construct_MSG_AY(protocol_message_t *output, float *ay);
    int8_t construct_MSG_AZ(protocol_message_t *output, float *az);
    int8_t construct_MSG_GX(protocol_message_t *output, float *gx);
    int8_t construct_MSG_GY(protocol_message_t *output, float *gy);
    int8_t construct_MSG_GZ(protocol_message_t *output, float *gz);
    int8_t construct_MSG_ALT(protocol_message_t *output, float *alt);
    int8_t construct_MSG_LON(protocol_message_t *output, double *lon);
    int8_t construct_MSG_LAT(protocol_message_t *output, double *lat);

    /* Deconstruct Message */
    int8_t deconstruct_MSG_AX(protocol_message_t *input, float *ax);
    int8_t deconstruct_MSG_AY(protocol_message_t *input, float *ay);
    int8_t deconstruct_MSG_AZ(protocol_message_t *input, float *az);
    int8_t deconstruct_MSG_GX(protocol_message_t *input, float *gx);
    int8_t deconstruct_MSG_GY(protocol_message_t *input, float *gy);
    int8_t deconstruct_MSG_GZ(protocol_message_t *input, float *gz);
    int8_t deconstruct_MSG_ALT(protocol_message_t *input, float *alt);
    int8_t deconstruct_MSG_LON(protocol_message_t *input, double *lon);
    int8_t deconstruct_MSG_LAT(protocol_message_t *input, double *lat);

};

#endif // PROTOCOL_GRAKSA_H
