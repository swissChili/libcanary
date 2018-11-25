//
// Created by cake on 11/24/18.
//
#include "libcanary/libcanary.h"
#include <stdio.h>

int main ()
{
    LCIR demo = LCNewIr();
    LCArg arg = {"foo", String};
    LCCmd cmd = {pop, 1, &arg};
    LCCmd cmd1 = {debug, 0};
    LCPush( &demo, cmd );
    LCPush( &demo, cmd1 );

    LCC(&demo);

    return 0;
}
