#include "UI/UI.h"

int main() {
    adminType* adminStack;
    adminStack=initializeAdmin();

    if(defaultSetup(&adminStack)==false){
        printf("err: all");
        return 0;
    }
    Node *database = NULL;
    initialMessage(&adminStack, database);
    database = NULL;
    return 0;
}
