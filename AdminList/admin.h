//
// Created by David on 2021-05-08.
//

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifndef ADATSTR_PROJECT_2_ADMIN_H
#define ADATSTR_PROJECT_2_ADMIN_H



typedef struct{
    char *username;
    char *password;
    struct adminType *next;
}adminType;

///primary
adminType* initializeAdmin();
bool defaultSetup(adminType**);
bool push(adminType**,char*,char*);

///secondary
bool stackNameSearch(adminType**,char*);
bool stackPwSearch(adminType**,char*,char*);
void printAdmins(adminType**);

#endif //ADATSTR_PROJECT_2_ADMIN_H