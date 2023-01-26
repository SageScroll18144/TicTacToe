#include "raylib.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

int operation;

void runMenu(void){
    operation = -1;
    printf("-> Select one of the option:\n\t1) PvP.\n\t2) PvM.\n\t3) Exit.\n.: ");
    while(operation!=1 && operation!=2 && operation!=3) {
        scanf("%d", &operation);
        printf(".: ");
    }
}
int IsPvPorPvM(void){
    if(operation == 3) exit(0);
    return (operation == 1) ? 0 : (operation == 2) ? 1 : -1;//0 para jogar contra outra pessoa, 1 para jogar contra à máquina;
}