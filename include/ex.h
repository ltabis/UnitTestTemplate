/*
** EPITECH PROJECT, 2019
** ex.h
** File description:
** prototypes
*/

#pragma once

typedef struct config_s {
    int val;
    char *msg;
} config_t;

char *myGetMsg();
int myGetTwo();
int myConditionnal();
void init();
void mySegv();
void switchMode();
