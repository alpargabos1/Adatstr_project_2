//
// Created by Alpar on 5/8/2021.
//

#include "reservation.h"

RESERVATION createReservation(char *name, char *brand,int day){
    RESERVATION newReserv;
/*
    char secu[4];
    itoa(day,secu,10);
    */

    strcpy(newReserv.name,name);
    strcpy(newReserv.brand,brand);
    return newReserv;
}

ReservationArray *createReservArray() {
    ReservationArray *newRes;
    newRes = (ReservationArray *) malloc(sizeof(ReservationArray));
    if(!newRes){
        return NULL;
    }
    newRes->freeAppointments = 4;

    return newRes;
}
