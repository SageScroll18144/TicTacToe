#include "raylib.h"
#include "board.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "graph.h"

Board board;
Font font;

void initBoard(void){
    board.image = LoadTexture("assets/tictactoe_board.png");

    board.recSrc = (Rectangle){0, 0, board.image.width, board.image.height};
    board.recDest = (Rectangle){0, 0, 400, 400};
    board.vecOrigin = (Vector2){0, 0};

    board.len_board_image=0;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) board.state[i][j]=0;

    for(int i=0;i<3;i++) for(int j=0;j<3;j++) board.game[i][j]='-';
    board.winner = '-';

    font = LoadFont("fonts/jupiter_crash.png");

    
}

void drawBoard(void){
    DrawTexturePro(board.image, board.recSrc, board.recDest, board.vecOrigin, 0, WHITE);
}

void updatePiece(Vector2 positionOnBoard, int turn){
    int x = (int)positionOnBoard.x;
    int y = (int)positionOnBoard.y;

    int real_pos_x, real_pos_y;

    if(x == 0) real_pos_x = 50;
    else if(x == 1) real_pos_x = 180;
    else real_pos_x = 290;
    
    if(y == 0) real_pos_y = 60;
    else if(y == 1) real_pos_y = 190;
    else real_pos_y = 300;

    if(turn) {
        board.board_image[board.len_board_image++] = (Object_pair){real_pos_y, real_pos_x, "X"};
    }
    else board.board_image[board.len_board_image++] = (Object_pair){real_pos_y, real_pos_x, "O"};

    board.state[x][y] = 1;
    board.game[x][y] = (turn) ? 'X' : 'O';
}

void drawPiece(void){
    for(int i=0;i<board.len_board_image;i++){
        DrawTextEx(font, board.board_image[i].piece, board.board_image[i].pos, 60, 1, DARKGRAY);
    }
}

int IsMark(Vector2 positionOnBoard){
    return board.state[(int)positionOnBoard.x][(int)positionOnBoard.y];
}

char IsGameOver(void){
    char winner='-';

    if(board.game[0][0]!='-'&&board.game[0][0]==board.game[1][1]&&board.game[0][0]==board.game[2][2]){
        winner = board.game[0][0];
    }
    else if(board.game[0][0]!='-'&&board.game[0][0]==board.game[1][0]&&board.game[0][0]==board.game[2][0]){
        winner = board.game[0][0];
    }
    else if(board.game[0][0]!='-'&&board.game[0][0]==board.game[0][1]&&board.game[0][0]==board.game[0][2]){
        winner = board.game[0][0];
    }
    else if(board.game[0][0]!='-'&&board.game[0][0]==board.game[0][1]&&board.game[0][0]==board.game[0][2]){
        winner = board.game[0][0];
    }
    else if(board.game[1][0]!='-'&&board.game[1][0]==board.game[1][1]&&board.game[1][0]==board.game[1][2]){
        winner = board.game[1][0];
    }
    else if(board.game[2][0]!='-'&&board.game[2][0]==board.game[1][1]&&board.game[2][0]==board.game[0][2]){
        winner = board.game[2][0];
    }
    else if(board.game[0][2]!='-'&&board.game[0][2]==board.game[1][2]&&board.game[0][2]==board.game[2][2]){
        winner = board.game[0][2];
    }
    else if(board.game[2][0]!='-'&&board.game[2][0]==board.game[2][1]&&board.game[2][0]==board.game[2][2]){
        winner = board.game[2][0];
    }
    else if(board.game[0][1]!='-'&&board.game[0][1]==board.game[1][1]&&board.game[0][1]==board.game[2][1]){
        winner = board.game[0][1];
    }else{
        int flag=1;
        for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(board.game[i][j]=='-') flag = 0;
        if(flag) winner = 'E';
    }
    return winner;
}

void drawWindowWinner(char winner){
    if(winner == 'E'){
        DrawTextEx(font, "Tie!",(Vector2){190, 200}, 40, 1, GREEN);
    }else{
        char ans[110];
        sprintf(ans, "%s%c%s", "The '", winner, "' winner!");
        DrawTextEx(font, ans,(Vector2){120, 200}, 40, 1, GREEN);
    }
}

// void putNodeOnGraphBoard(Board new_node, int idx){
//     graph[idx] = (Board *) realloc(graph[idx], (len_node[idx] + 1) * sizeof(Board));
//     graph[idx][len_node[idx]++] = new_node;
// }
// void removeLastNodeOnGraphBoard(int which_board){
//     if(len_node > 0){
//         graph[which_board] = (Board *) realloc(graph[which_board], (len_node[which_board] - 1) * sizeof(Board));
//         len_node[which_board]--;
//     }
// }

int Evaluate(Board this_board){
    char winner='-';

    if(this_board.game[0][0]!='-'&&this_board.game[0][0]==this_board.game[1][1]&&this_board.game[0][0]==this_board.game[2][2]){
        winner = this_board.game[0][0];
    }
    else if(this_board.game[0][0]!='-'&&this_board.game[0][0]==this_board.game[1][0]&&this_board.game[0][0]==this_board.game[2][0]){
        winner = this_board.game[0][0];
    }
    else if(this_board.game[0][0]!='-'&&this_board.game[0][0]==this_board.game[0][1]&&this_board.game[0][0]==this_board.game[0][2]){
        winner = this_board.game[0][0];
    }
    else if(this_board.game[0][0]!='-'&&this_board.game[0][0]==this_board.game[0][1]&&this_board.game[0][0]==this_board.game[0][2]){
        winner = this_board.game[0][0];
    }
    else if(this_board.game[1][0]!='-'&&this_board.game[1][0]==this_board.game[1][1]&&this_board.game[1][0]==this_board.game[1][2]){
        winner = this_board.game[1][0];
    }
    else if(this_board.game[2][0]!='-'&&this_board.game[2][0]==this_board.game[1][1]&&this_board.game[2][0]==this_board.game[0][2]){
        winner = this_board.game[2][0];
    }
    else if(this_board.game[0][2]!='-'&&this_board.game[0][2]==this_board.game[1][2]&&this_board.game[0][2]==this_board.game[2][2]){
        winner = this_board.game[0][2];
    }
    else if(this_board.game[2][0]!='-'&&this_board.game[2][0]==this_board.game[2][1]&&this_board.game[2][0]==this_board.game[2][2]){
        winner = this_board.game[2][0];
    }
    else if(this_board.game[0][1]!='-'&&this_board.game[0][1]==this_board.game[1][1]&&this_board.game[0][1]==this_board.game[2][1]){
        winner = this_board.game[0][1];
    }else{
        int flag=1;
        for(int i=0;i<3;i++) for(int j=0;j<3;j++) if(this_board.game[i][j]=='-') flag = 0;
        if(flag) winner = 'E';
    }
    return (winner == 'O') ? INT32_MAX : (winner == 'E') ? 1 : (winner == '-') ? 0 : INT32_MIN;
}

double algorithm(int node, int depth, double a, double b, int isMaximizing){
    return 0;
}

// void createSon(Board **graph, int **len, int father){
//     Board tmp = grap;
    
//     for(int i=0;i<3;i++) for(int j=0;j<3;j++){
//         if(tmp.game[i][j] == '-'){
//             tmp.game[i][j] = 'O';
            
//             graph[0] = (Board *)realloc(graph[0], (len_node[0] + 1) * sizeof(Board));
//             graph[0][len_node[0]] = tmp;
//             len_node[0]++;

//             tmp.game[i][j] = '-';
//         }
//     }
// }

Vector2 IAMachine(void){
    //criar a geração de movimentos
    //criar o min_max
    //criar a pontuação

    Board *graph[110];//10010
    int len_node[110];
    int set_w[110];
    int fathers[110];
    for(int i=0;i<110;i++) {
        graph[i] = NULL;
        len_node[i] = 0;
    }

    Board tmp = board;
    // int pointer_left_node = 0, pointer_right_node = 0;
    // for(int i=0;i<3;i++) for(int j=0;j<3;j++){
    //     if(tmp.game[i][j] == '-'){
    //         tmp.game[i][j] = 'O';

    //         graph[0] = (Board *)realloc(graph[0], (len_node[0] + 1) * sizeof(Board));
    //         graph[0][len_node[0]] = tmp;
    //         len_node[0]++;

    //         tmp.game[i][j] = '-';

    //         fathers[pointer_right_node++] = 0;
    //     }
    // }
    // pointer_left_node++;
    // int depth = 3, turn = 1, node;
    // printf("LOWER_BOUND: %d \t UPPER_BOUND: %d\n", pointer_left_node, pointer_right_node);
    // while(depth--){
    //     node=0;
    //     for(int k=pointer_left_node;k<pointer_right_node;k++){

    //         tmp = graph[fathers[k]][node];

    //         for(int i=0;i<3;i++) for(int j=0;j<3;j++){
    //             if(tmp.game[i][j] == '-'){
    //                 tmp.game[i][j] = (turn) ? 'X' : 'O';

    //                 graph[k] = (Board *)realloc(graph[k], (len_node[k] + 1) * sizeof(Board));
    //                 graph[k][len_node[k]] = tmp;
    //                 len_node[k]++;

    //                 tmp.game[i][j] = '-';
    //                 fathers[pointer_right_node + node] = fathers[k];
    //                 node++;
    //             }
    //         }
    //     }
    //     pointer_left_node = pointer_right_node;
    //     pointer_right_node = node;
    //     turn = !turn;
    // }
    
    // for(int i=0;i<110;i++){
    //     for(int j=0;j<len_node[i];j++){
    //         for(int k=0;k<3;k++) {
    //             for(int z=0;z<3;z++){
    //                 printf("%c", graph[i][j].game[k][z]);
    //             }
    //             printf("\n");
    //         }
    //         printf("\n");
    //     }
    // }

    // for(int i=0;i<110;i++) free(graph[i]);

    initGraph();
    createSon(tmp, 0, 0);
    addSubSetGraph();
    printImageBoard();
    closeGraph();


    //retorna um Vector2 Como a jogada
    return (Vector2){0,0};
}

// void createGraph()

void unLoadBoard(void){
    UnloadTexture(board.image);
}