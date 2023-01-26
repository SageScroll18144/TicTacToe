#ifndef GRAPH_H
#define GRAPH_H

#include "raylib.h"
#include "board.h"
#include <stdint.h>
#include <stdlib.h>

typedef struct{
    Board *graph[10010];//10010
    int len_node[10010];
    int set_w[10010];
    int mark[10010];
    int fathers[10010];
    int how_many_nodes;
}Graph;

void initGraph(void);
void createSon(Board tmp, int father, int turn);
void addSubSetGraph(int turn);
void printImageBoard(void);
void closeGraph(void);

#endif