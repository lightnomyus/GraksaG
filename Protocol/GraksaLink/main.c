#include <stdio.h>
#include "graksalink.h"

int main()
{
    float x = 12834;
    uint8_t* p = (uint8_t*) &x;
    printf("%x\n",p[0]);
    printf("%x\n",p[1]);
    printf("%x\n",p[2]);
    printf("%x\n",p[3]);
    float pp;
    memcpy(&pp,p,4);
    printf("%f\n",(double)pp);
//    float y;
    uint8_t* message;
    char team_id[3] = {'I','T','B'};
    construct_MSG_ALT(&message,0xd,(uint8_t*)team_id,x);
    for (unsigned int i=0; i<sizeof(char)*9;i++) {
        printf("%x ",message[i]);
    }
    printf("\n");

//    message_t tester;
//    uint8_t* p = (uint8_t*) &tester;
//    for (unsigned int i=0; i<sizeof(tester);i++) {
//        printf("%x ",p[i]);
//    }
//    printf("\n\n");
//    //printf("%d\n",sizeof (*tester.payload));
//    char string[3] = {'I','T','B'};
//    construct_Header(&tester,0xd,(uint8_t*)string);
//    for (unsigned int i=0; i<sizeof(tester);i++) {
//        printf("%x ",p[i]);
//    }
//    printf("\n\n");
//    construct_MSG_AY(&tester,&x);
//    for (unsigned int i=0; i<sizeof(tester);i++) {
//        printf("%x ",p[i]);
//    }
//    printf("\n\n");
//    printf("SOF: %x\nTeam ID: %s \n",tester.header.SOF,tester.header.Team_ID);
//    deconstruct_MSG_AX(&tester,&y);
//    printf("%.1f\n",(double)y);
    return 0;
}
