//
// Created by cake on 11/24/18.
//
#include "libcanary/libcanary.h"
#include <stdio.h>

int main ()
{
    LCIR demo = LCNewIr();
    LCArg foo = {"foo", String};
    LCArg bar = {"1", Int};
    LCArg baz = {"baz", String};
    LCArg args[] = {foo, bar, baz};

    LCCmd qux = {push, 3, args};
    LCPush(&demo, qux);

    LCC(&demo);

    return 0;
}
