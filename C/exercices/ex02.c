/*
** EPITECH PROJECT, 2019
** ex02
** File description:
** workshop unit test
*/

#include <stdlib.h>
#include <string.h>
#include "ex.h"

config_t config;

void init()
{
    config.val = 1;
    if ((config.msg = malloc(sizeof(char) * 10)) == NULL)
        exit(84);
    strcpy(config.msg, "Hey bro !");
}

char *myGetMsg()
{
    return (config.msg);
}

void switchMode()
{
    config.val = 2;
}

int myConditionnal()
{
    if (config.val == 1)
        return (3);
    else
        return (0);
}