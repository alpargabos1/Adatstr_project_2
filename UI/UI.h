//
// Created by David on 2021-05-07.
//

#ifndef ADATSTR_PROJECT_2_UI_H
#define ADATSTR_PROJECT_2_UI_H



#include "../BST/bst.h"
#include "../AdminList/admin.h"

#include <stdio.h>
#include <stdlib.h>


void initialMessage(adminType**, Node*);
void endMessage(adminType**);

void adminScreenLog(adminType**, Node*);
void adminScreenOptions(adminType**, Node*);
void addNewAdmin(adminType**, Node*);

void guestScreenOptions(adminType**, Node*);

#endif //ADATSTR_PROJECT_2_UI_H