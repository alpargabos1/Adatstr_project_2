//
// Created by Alpar on 5/8/2021.
//

#include "reservation.h"

RESERVATION createReservation(char *name, char *brand,int day){
    RESERVATION newReserv;

    strcpy(newReserv.name,name);
    strcpy(newReserv.brand,brand);
    return newReserv;
}

ReservationArray *createReservArray(int day) {
    ReservationArray *newRes;
    newRes = (ReservationArray *) malloc(sizeof(ReservationArray));
    if(!newRes){
        return NULL;
    }
    newRes->freeAppointments = 4;

    return newRes;
}
