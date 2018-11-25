//
// Created by cake on 11/24/18.
//

#ifndef LIBCANARY_LIBCANARY_H
#define LIBCANARY_LIBCANARY_H

#include <stdlib.h>
#include <stdio.h>

typedef enum LCCall {
    push,
    pop,
    loadi,
    addi,
    subi,
    debug,
    jump,
    call
} LCCall;

char * LCCallItems[] = {
        "push",
        "pop",
        "loadi",
        "addi",
        "subi",
        "debug",
        "jump",
        "call"
};

typedef enum LCArgType {
    Int,
    Float,
    String,
    Ref,
} LCArgType;

typedef struct LCArg {
    char * content;
    LCArgType type;
} LCArg;

typedef struct LCCmd {
    LCCall command;
    int len;
    LCArg * args;
} LCCmd;

typedef struct LCIR {
    int pos;
    int len;
    LCCmd *commands;
} LCIR;

LCIR * LCPush( LCIR * ir, LCCmd cmd )
{
    if ( ir->pos >= ir->len )
    {
        ir->len++;
    }
    ir->pos++;
    /* It's terrible but it works! */
    ir->commands = realloc(ir->commands, sizeof(ir->commands) + sizeof(cmd) + 100);
    ir->commands[ir->pos] = cmd;
    printf(" %d %d ", ir->commands[ir->pos].command, cmd.command);

    return ir;
}

LCIR LCNewIr( void )
{
    LCIR ir;
    ir.pos = 0;
    ir.len = 0;
    ir.commands = malloc(0);
    return ir;
}

void LCC(LCIR * ir)
{
    for ( int i = 1; i <= ir->len; i++ )
    {
        printf("\n%s", LCCallItems[ir->commands[i].command]);
        for ( int j = 0; j < ir->commands[i].len; j++ )
        {
            printf(" %s", ir->commands[i].args[j].content);
        }
        printf(";\n");
    }
}

#endif //LIBCANARY_LIBCANARY_H
