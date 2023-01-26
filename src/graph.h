#ifndef GRAPH_H
#define GRAPH_H

#include "raylib.h"
#include "board.h"
#include <stdint.h>
#include <stdlib.h>

typedef struct{
    Board *graph[110];//10010
    int len_node[110];
    int set_w[110];
    int mark[110];
    int how_many_nodes;
}Graph;

void initGraph(void);
void createSon(Board tmp, int father);
void printImageBoard(void);
void closeGraph(void);

#endif