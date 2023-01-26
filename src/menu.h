#ifndef MENU_H
#define MENU_H

#include "raylib.h"

void initMenu(void);
void updateMenu(void);
void drawMenu(void);
int getMenuPos(void);
void runMenu(void);
int IsPvPorPvM(void);
int canRun(void);

#endif