#include "raylib.h"
#include "graph.h"
#include "board.h"
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

Graph tree;

void initGraph(void){
    for(int i=0;i<110;i++) {
        tree.graph[i] = NULL;
        tree.len_node[i] = 0;
    }
    tree.how_many_nodes = 0;
}

void createSon(Board tmp, int father){
    tree.mark[father] = 1;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++){
        if(tmp.game[i][j] == '-'){
            tmp.game[i][j] = 'O';
            
            tree.how_many_nodes++;
            tmp.idx_board = tree.how_many_nodes;
            
            tree.fathers[tmp.idx_board] = father;

            tree.graph[father] = (Board *)realloc(tree.graph[father], (tree.len_node[father] + 1) * sizeof(Board));
            tree.graph[father][tree.len_node[father]] = tmp;
            tree.len_node[father]++;

            tmp.game[i][j] = '-';

        }
    }

}

void addSubSetGraph(void){
    for(int i=0;i<=tree.how_many_nodes;i++){
        if(!tree.mark[i]){
            for(int j=0;j<tree.len_node[i];j++) createSon(tree.graph[tree.fathers[i]][j], tree.fathers[j]);
        }
    }
}

void printImageBoard(void){
    for(int i=0;i<110;i++){
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
    for(int i=0;i<110;i++) {
        free(tree.graph[i]);
        tree.len_node[i] = 0;
        tree.mark[i] = 0;
    }
    tree.how_many_nodes = 0;
}