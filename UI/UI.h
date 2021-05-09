//
// Created by David on 2021-05-07.
//

#ifndef ADATSTR_PROJECT_2_UI_H
#define ADATSTR_PROJECT_2_UI_H

#endif //ADATSTR_PROJECT_2_UI_H

#include "..\BST\bst.h"
#include "..\AdminList\admin.h"

#include <stdio.h>
#include <stdlib.h>


void initialMessage(adminType**);
void endMessage(adminType**);

void adminScreenLog(adminType**);
void adminScreenOptions(adminType**);
void addNewAdmin(adminType**);

void guestScreenOptions(adminType**);