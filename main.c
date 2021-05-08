#include "UI/UI.h"

int main() {
    adminType* adminStack;
    adminStack=initializeAdmin();

    if(defaultSetup(&adminStack)==false){
        printf("err: all");
        return 0;
    }
    initialMessage(&adminStack);
    return 0;
}
