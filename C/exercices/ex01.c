/*
** EPITECH PROJECT, 2019
** ex01
** File description:
** workshop unit test
*/

#include <stdlib.h>
#include "ex.h"

int myGetTwo()
{
    return (2);
}

void mySegv()
{
    __attribute__((unused))char *ptr = NULL;
    ptr = "It will crash !";
}