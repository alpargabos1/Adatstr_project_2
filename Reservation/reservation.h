//
// Created by Alpar on 5/8/2021.
//

#ifndef ADATSTR_PROJECT_2_RESERVATION_H
#define ADATSTR_PROJECT_2_RESERVATION_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>


typedef struct RESERVATION {
    char name[30];
    char brand[20];
    char securityCode[4];
} RESERVATION;

typedef struct ReservationArray {
    int freeAppointments;
    RESERVATION reservations[4];

} ReservationArray;

RESERVATION createReservation(char *, char *,int);

ReservationArray *createReservArray(int);


#endif //ADATSTR_PROJECT_2_RESERVATION_H
