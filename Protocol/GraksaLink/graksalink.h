#ifndef GRAKSALINK_H
#define GRAKSALINK_H
/*
 * STRUKTUR MESSAGE
 * BYTE 1           Start of Frame
 * BYTE 2-4         Team Identifiacion
 * BYTE 5           Message Identification
 * BYTE 6-n         Payload
 * */

/*
 * HOW TO CONSTRUCT MESSAGE
 * 1. Intansiasi Objek message_t
 * 2. Gunakan fungsi construct_Header
 * 3. Gunakan fungsi construct_Message
 * */

/* Library used */
#include <stdint.h>
#include <string.h>
#include <stdlib.h>

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

typedef struct header {
    uint8_t SOF;
    uint8_t Team_ID[3];
    uint8_t Message_ID;
} header_t;

typedef struct message {
    header_t header;
    uint8_t *payload;
} message_t;

/* Construct Header */
void construct_Header(message_t *output, uint8_t SOF, uint8_t Team_ID[3]);

/* Construct Message */
void construct_MSG_AX(message_t *output, float *ax);
void construct_MSG_AY(message_t *output, float *ay);
void construct_MSG_AZ(message_t *output, float *az);
void construct_MSG_GX(message_t *output, float *gx);
void construct_MSG_GY(message_t *output, float *gy);
void construct_MSG_GZ(message_t *output, float *gz);
void construct_MSG_ALT(message_t *output, float *alt);
void construct_MSG_LON(message_t *output, double *lon);
void construct_MSG_LAT(message_t *output, double *lat);

/* Deconstruct Message */
void deconstruct_MSG_AX(message_t *input, float *ax);
void deconstruct_MSG_AY(message_t *input, float *ay);
void deconstruct_MSG_AZ(message_t *input, float *az);
void deconstruct_MSG_GX(message_t *input, float *gx);
void deconstruct_MSG_GY(message_t *input, float *gy);
void deconstruct_MSG_GZ(message_t *input, float *gz);
void deconstruct_MSG_ALT(message_t *input, float *alt);
void deconstruct_MSG_LON(message_t *input, double *lon);
void deconstruct_MSG_LAT(message_t *input, double *lat);

#endif // GRAKSALINK_H
