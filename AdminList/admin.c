//
// Created by David on 2021-05-08.
//

#include "admin.h"


adminType *initializeAdmin() {
    adminType *stack;
    stack = (adminType *) malloc(1 * sizeof(adminType));

    if (stack == NULL) {
        printf("err: all");
        return false;
    }
    stack->username = (char *) calloc(20, sizeof(char));
    stack->password = (char *) calloc(20, sizeof(char));

    stack->next = NULL;

    return stack;
}
void endAdmin(adminType** stack){
    while ((*stack)->next != NULL) {
        free((*stack)->username);
        free((*stack)->password);
        (*stack) = (*stack)->next;
    }
    (*stack)->next = NULL;
}

bool defaultSetup(adminType **adm) {
    adminType *temp;
    temp = (adminType *) malloc(sizeof(adminType));
    if (temp == NULL) {
        printf("err: all");
        return false;
    }
    temp->username = (char *) calloc(20, sizeof(char));
    temp->password = (char *) calloc(20, sizeof(char));


    strcpy(temp->username, "adminexample");
    strcpy(temp->password, "12345");


    temp->next = (*adm);
    (*adm) = temp;

    return true;
}

bool push(adminType **adm, char *un, char *pw) {
    adminType *temp;
    temp = (adminType *) malloc(sizeof(adminType));

    if (temp == NULL) {
        printf("err: all");
        return false;
    }
    temp->username = (char *) calloc(20, sizeof(char));
    temp->password = (char *) calloc(20, sizeof(char));



    strcpy(temp->username, un);
    strcpy(temp->password, pw);

    temp->next = (*adm);
    (*adm) = temp;

    return true;
}

void printAdmins(adminType **adm) {
    adminType *p = (*adm);
    while (p->next != NULL) {
        printf("\n|\t\t%s", p->username);
        p = p->next;
    }
}

bool stackNameSearch(adminType **adm, char *un) {
    adminType *p = (*adm);
    while (p->next != NULL) {
        if (!strcmp(p->username, un)) {
            return true;
        }
        p = p->next;
    }
    return false;
}

bool stackPwSearch(adminType **adm, char *pw, char *un) {
    adminType *p = (*adm);
    while (p->next != NULL) {
        if (!strcmp(p->username, un)) {
            if (!strcmp(p->password, pw)) {
                return true;
            }
        }
        p = p->next;
    }
    return false;
}