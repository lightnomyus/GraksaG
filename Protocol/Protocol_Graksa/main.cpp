#include <iostream>
#include <cstdio>
#include "protocol_graksa.h"

using namespace std;

int main()
{
    Protocol_Graksa protocol;
    int ax = 1231324;
    printf("%x\n",ax);
    protocol_message_t message;
    protocol.construct_MSG_AX(&message,(float*)&ax);
    int axx;
    protocol.deconstruct_MSG_AX(&message,(float*)&axx);
    printf("%x\n",axx);
    return 0;
}
