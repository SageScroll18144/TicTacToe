#include "raylib.h"
#include "menu.h"
#include <stdio.h>
#include <stdlib.h>

char title[] = "Tic Tac Toe #";
char msg1[] = "PvP";
char msg2[] = "PvM";

Font font_;
Vector2 position;

int operation, menu_pos, flag_click = 0;

void initMenu(void){
    font_ = LoadFont("fonts/jupiter_crash.png");

    position.x = 80;
    position.y = 100;

    menu_pos = 0;
}

void updateMenu(void){
    if (IsKeyPressed (KEY_DOWN)) {
        menu_pos++;
        if (menu_pos > 1) menu_pos = 1;
    }
    else if (IsKeyPressed (KEY_UP)){
        menu_pos--; 
        if (menu_pos < 0) menu_pos = 1;
    }
    
    if(IsKeyPressed(KEY_ENTER)){
        operation = !menu_pos;
        flag_click = 1;
    }
}

void drawMenu(void){
    DrawTextEx(font_, title, position, font_.baseSize*3.0f , 1.0f, BLACK);
    if (menu_pos == 0){

        DrawRectangle(80, 170, 250, 40, BLACK);
        DrawRectangle(80, 240, 250, 40, WHITE);
            
        DrawText(msg1 , 190, 180, 20, WHITE);
        DrawText(msg2 , 190, 250, 20, BLACK);
    }
    else if (menu_pos == 1){
        DrawRectangle(80, 170, 250, 40, WHITE);
        DrawRectangle(80, 240, 250, 40, BLACK);
            
        DrawText(msg1 , 190, 180, 20, BLACK);
        DrawText(msg2 , 190, 250, 20, WHITE);
    }
    
}

int getMenuPos(void){
    return menu_pos;
}

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
int canRun(void){
    return flag_click;
}