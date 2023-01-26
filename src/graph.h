#ifndef GRAPH_H
#define GRAPH_H

#include "raylib.h"
#include "board.h"
#include <stdint.h>
#include <stdlib.h>

typedef struct{
    Board *graph[100010];//10010
    int len_node[100010];
    int set_w[100010];
    int mark[100010];
    int fathers[100010];
    int how_many_nodes;
}Graph;

void initGraph(void);
void createSon(Board tmp, int father, int turn);
void addSubSetGraph(int turn);
void setWeightFinalNodes(void);
int getNodeWeight(int idx);
int howManyChildHasSubSet(int node);
int getSon(int father, int idx);
void setNodeWeight(int node, int value);
Board getBoard(int father, int son);
void printImageBoard(void);
void closeGraph(void);

#endif