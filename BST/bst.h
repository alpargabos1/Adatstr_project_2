//
// Created by Alpar on 5/8/2021.
//

#ifndef ADATSTR_PROJECT_2_BST_H
#define ADATSTR_PROJECT_2_BST_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../Reservation/reservation.h"

typedef struct Node {
    int day;
    struct Node *left, *right;
    ReservationArray *reservation;
} Node;

Node *create(int);

Node *insert(Node *, int);

Node *minValueNode(struct Node *);

Node *Delete(Node *, int);

bool Find(Node *, int);

void inorder(Node *fa);

void test();

#endif //ADATSTR_PROJECT_2_BST_H
