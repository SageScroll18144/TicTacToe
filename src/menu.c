#include "raylib.h"
#include "menu.h"
#include <stdio.h>

int operation;

void runMenu(void){
    operation = -1;
    printf("-> Select one of the option:\n\t1) PvP.\n\t2) PvM.\n.: ");
    while(operation!=1 && operation!=2) scanf("%d", &operation);
}
int IsPvPorPvM(void){
    return (operation == 1) ? 0 : 1;//0 para jogar contra outra pessoa, 1 para jogar contra à máquina;
}