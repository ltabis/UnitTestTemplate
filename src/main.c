/*
** EPITECH PROJECT, 2019
** main.c
** File description:
** testing 
*/

#include <stdlib.h>
#include <stdio.h>
#include "my.h"

int main(int ac, char **av)
{
    if (ac != 2)
        return (1);
    printf("number is %s\n", !isneg(atoi(av[1])) ? "negative" : "positive");
    return (0);
}
