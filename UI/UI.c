//
// Created by Golden on 2021-05-07.
//

#include "UI.h"


void initialMessage(){
    int logInChoice;

    printf("\n=========================================================================\n");
    printf("|\t\t\t\tWELCOME!\t\t\t\t|");
    printf("\n=========================================================================\n");
    printf("|\tWelcome to our motor vehicle service scheduling application!\t|\n");
    printf("|\tThrough this, you are able to schedule the servicing of your\t|\n");
    printf("|\tpersonal vehicle or modify the entire program as an admin.\t|");
    printf("\n=========================================================================\n");
    printf("|\tLog in as: \t(1)Admin\t\t\t\t\t|\n");
    printf("|\t\t\t(2)Guest User\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t(0)Exit\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t|");
    printf("\n=========================================================================\n");
    printf("\tAnswer:");
    scanf("%i",&logInChoice);

    switch(logInChoice){
        case 1:
            adminScreenLog();
            break;
        case 2:
            guestScreenOptions();
            break;
        case 0:
            endMessage();
            break;
    }
}

void endMessage(){
    printf("\n=========================================================================\n");
    printf("|\t\tTHANK YOU FOR USING OUR APPLICATION!\t\t\t|\n|\t\t\tSee you soon.\t\t\t\t\t|");
    printf("\n=========================================================================\n");
}

void adminScreenLog(){
    char *username,*password;
    int choice;

    username=(char*)calloc(10,sizeof(char));
    password=(char*)calloc(10,sizeof(char));
    if(username==NULL || password==NULL){
        printf("err: all");
    }

    printf("\n=========================================================================\n");
    printf("|\tIn order to log in as an admin,\t\t\t\t\t|\n|\ta USERNAME and a PASSWORD (All found in the README.md file)\t|\n|\tis required.\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t(0)Back\t\t\t\t\t\t\t\t|\n");
    printf("|\t(1)Proceed\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t|");
    printf("\n=========================================================================\n");
    printf("\tAnswer:");
    scanf("%i",&choice);

    switch(choice) {
        case 0:
            initialMessage();
            break;
        case 1:
            printf("\n\tUsername:");
            scanf("%s", username);
            printf("\n\tPassword:");
            scanf("%s", password);

            adminScreenOptions();
            break;
    }
}

void adminScreenOptions(){
    int choice;

    printf("\n=========================================================================\n");
    printf("|\tYou have logged in as an admin.\t\t\t\t\t|\n|\tYour options are as follows:\t\t\t\t\t|\n");
    printf("|\t\t(1)List all scheduled dates.\t\t\t\t|\n");
    printf("|\t\t(2)Modify or delete a specific scheduled date.\t\t|\n");
    printf("|\t\t(3)Add a new admin account.\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t(0)Back\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t|");
    printf("\n=========================================================================\n");
    printf("\tAnswer:");
    scanf("%i",&choice);

    switch(choice) {
        case 0:
            initialMessage();
            break;
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
    }
}

void guestScreenOptions(){
    int choice;

    printf("\n=========================================================================\n");
    printf("|\tYou have logged in as a guest user.\t\t\t\t|\n|\tWe have 4 total spaces for any day,\t\t\t\t|\n|\tyour options are as follows:\t\t\t\t\t|\n");
    printf("|\t\t(1)Schedule on the first available date.\t\t|\n");
    printf("|\t\t(2)Schedule on a selected date.\t\t\t\t|\n");
    printf("|\t\t(3)Cancel a scheduled date (Requires safety code).\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t|\n");
    printf("|\t(0)Back\t\t\t\t\t\t\t\t|\n");
    printf("|\t\t\t\t\t\t\t\t\t|");
    printf("\n=========================================================================\n");
    printf("\tAnswer:");
    scanf("%i",&choice);

    switch(choice) {
        case 0:
            initialMessage();
            break;
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
    }
}