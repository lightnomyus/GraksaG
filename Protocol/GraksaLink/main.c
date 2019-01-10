#include <stdio.h>
#include "graksalink.h"

int main()
{
    float x = 1234;
    float y;
    message_t tester;
    char string[3] = {'I','T','B'};
    construct_Header(&tester,0xd,(uint8_t*)string);
    construct_MSG_AX(&tester,&x);
    printf("SOF: %x\nTeam ID: %s \n",tester.header.SOF,tester.header.Team_ID);
    deconstruct_MSG_AX(&tester,&y);
    printf("%.1f\n",(double)y);
    return 0;
}
