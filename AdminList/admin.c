//
// Created by David on 2021-05-08.
//

#include "admin.h"


adminType* initializeAdmin(){
    adminType* stack;
    stack=(adminType*)malloc(1*sizeof(adminType));

    if(stack==NULL){
        printf("err: all");
        return false;
    }
    stack->username=(char*)calloc(20,sizeof(char));
    stack->password=(char*)calloc(20,sizeof(char));

    stack->next=NULL;

    return stack;
}

bool defaultSetup(adminType** adm){
    adminType* temp;
    temp=(adminType*)malloc(sizeof(adminType));
    temp->username=(char*)calloc(20,sizeof(char));
    temp->password=(char*)calloc(20,sizeof(char));

    if(temp==NULL){
        printf("err: all");
        return false;
    }

    strcpy(temp->username,"adminexample");
    strcpy(temp->password,"12345");


    temp->next = (*adm);
    (*adm)=temp;

    return true;
}

bool push(adminType** adm,char* un,char* pw){
    adminType* temp;
    temp=(adminType*)malloc(sizeof(adminType));
    temp->username=(char*)calloc(20,sizeof(char));
    temp->password=(char*)calloc(20,sizeof(char));

    if(temp==NULL){
        printf("err: all");
        return false;
    }

    strcpy(temp->username,un);
    strcpy(temp->password,pw);

    temp->next =  (*adm);
    (*adm)=temp;

    return true;
}

void printAdmins(adminType** adm){
    while((*adm)->next!=NULL){
        printf("\n|\t%s",(*adm)->username);
        (*adm) =  (*adm)->next;
    }
}

bool stackNameSearch(adminType** adm,char* un){
    while((*adm)->next!=NULL){
        if(!strcmp((*adm)->username,un)){
            return true;
        }
        (*adm) =  (*adm)->next;
    }
    return false;
}
bool stackPwSearch(adminType** adm,char* pw,char* un){
    while((*adm)->next!=NULL){
        if(!strcmp((*adm)->username,un)){
            if(!strcmp((*adm)->password,pw)){
                return true;
            }
        }
        (*adm) =  (*adm)->next;
    }
    return false;
}