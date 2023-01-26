#include "raylib.h"
#include "graph.h"
#include "board.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

Graph tree;
Board nodes[100010];

void initGraph(void){
    for(int i=0;i<100010;i++) {
        tree.graph[i] = NULL;
        tree.len_node[i] = 0;
    }
    tree.how_many_nodes = 0;
    tree.mark[0]=1;
}

void createSon(Board tmp, int father, int turn){
    for(int i=0;i<3;i++) for(int j=0;j<3;j++){
        if(tmp.game[i][j] == '-'){
            tmp.game[i][j] = (turn) ? 'X' : 'O';
            
            tree.how_many_nodes++;
            tmp.idx_board = tree.how_many_nodes;
        
            nodes[tmp.idx_board] = tmp;

            tree.graph[father] = (Board *)realloc(tree.graph[father], (tree.len_node[father] + 1) * sizeof(Board));
            tree.graph[father][tree.len_node[father]] = tmp;
            tree.len_node[father]++;

            tmp.game[i][j] = '-';

        }
    }

}

void addSubSetGraph(int turn){
    int current_nodes = tree.how_many_nodes, weight;
    for(int i=0;i<=current_nodes;i++){
        if(!tree.mark[i]){
            weight = Evaluate(nodes[i]);

            if(weight == 0) createSon(nodes[i], i, turn);
            else tree.set_w[i] = weight;

            tree.mark[i] = 1;
        }
    }
}

void setWeightFinalNodes(void){
    for(int i=0;i<100010;i++){
        if(tree.len_node[i] == 0) {
            tree.set_w[i] = Evaluate(nodes[i]);
        }
    }
}

int getNodeWeight(int idx){
    return tree.set_w[idx];
}

int howManyChildHasSubSet(int node){
    return tree.len_node[node];
}
int getSon(int father, int idx){
    return tree.graph[father][idx].idx_board;
}

void setNodeWeight(int node, int value){
    tree.set_w[node] = value;
}

Board getBoard(int father, int son){
    return tree.graph[father][son];
}

void printImageBoard(void){
    for(int i=0;i<=tree.how_many_nodes;i++){
        for(int j=0;j<tree.len_node[i];j++){
            printf("index of board: %d\n", tree.graph[i][j].idx_board);
            for(int k=0;k<3;k++) {
                for(int z=0;z<3;z++){
                    printf("%c", tree.graph[i][j].game[k][z]);
                }
                printf("\n");
            }
            printf("\n");
        }
    }

}

void closeGraph(void){
    for(int i=0;i<100010;i++) {
        free(tree.graph[i]);
        tree.len_node[i] = 0;
        tree.mark[i] = 0;
    }
    tree.how_many_nodes = 0;
}