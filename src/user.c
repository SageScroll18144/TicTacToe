#include "raylib.h"
#include "user.h"

Vector2 getUserPosition(void){
    return (Vector2){GetMouseX(), GetMouseY()};
}

Vector2 getBoardPosition(void){
    int x, y;
    if(GetMouseY() <= 135) x = 0;
    else if(GetMouseY() >= 255) x = 2;
    else x = 1;

    if(GetMouseX() <= 135) y = 0;
    else if(GetMouseX() >= 255) y = 2;
    else y = 1;

    return (Vector2){x, y};
}

int IsUserPlay(void){
    return IsMouseButtonPressed(MOUSE_BUTTON_LEFT);
}