//
// Created by Alpar on 5/8/2021.
//

#ifndef ADATSTR_PROJECT_2_BST_H
#define ADATSTR_PROJECT_2_BST_H

#include "..\Reservation\reservation.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node {
    int day;
    struct Node *left, *right;
    ReservationArray *reservation;
} Node;

Node *create(int, char *, char *);

Node *insert(Node *, int, char *, char *);

Node *minValueNode(struct Node *);

Node *Delete(Node *, int);

Node *search(Node *, int);

bool Find(Node *, int);

void inorderDates(Node *fa);

bool checkForFreeAppointment(Node *);

void scheduleOnFirstAvaDay(Node **);

bool scheduleOnSelectedDay(Node **);

void deleteDay(Node **);

void test();

#endif //ADATSTR_PROJECT_2_BST_H
