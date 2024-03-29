#include "raylib.h"
#include "board.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include "graph.h"

Board board;
Font font;
Sound click;

void initBoard(void){
    board.image = LoadTexture("assets/tictactoe_board.png");

    board.recSrc = (Rectangle){0, 0, board.image.width, board.image.height};
    board.recDest = (Rectangle){0, 0, 400, 400};
    board.vecOrigin = (Vector2){0, 0};

    board.len_board_image=0;
    for(int i=0;i<3;i++) for(int j=0;j<3;j++) board.state[i][j]=0;

    for(int i=0;i<3;i++) for(int j=0;j<3;j++) board.game[i][j]='-';
    board.winner = '-';

    font = LoadFont("fonts/setback.png");
    
    click = LoadSound("sounds/click.mp3");
    SetSoundVolume(click, 0.5f);   
}

void drawBoard(void){
    DrawTexturePro(board.image, board.recSrc, board.recDest, board.vecOrigin, 0, WHITE);
}

void updatePiece(Vector2 positionOnBoard, int turn){
    int x = (int)positionOnBoard.x;
    int y = (int)positionOnBoard.y;

    int real_pos_x, real_pos_y;

    if(x == 0) real_pos_x = 50;
    else if(x == 1) real_pos_x = 170;
    else real_pos_x = 290;
    
    if(y == 0) real_pos_y = 60;
    else if(y == 1) real_pos_y = 182;
    else real_pos_y = 300;

    if(turn) {
        board.board_image[board.len_board_image++] = (Object_pair){real_pos_y, real_pos_x, "X"};
    }
    else board.board_image[board.len_board_image++] = (Object_pair){real_pos_y, real_pos_x, "O"};

    board.state[x][y] = 1;
    board.game[x][y] = (turn) ? 'X' : 'O';

    PlaySound(click);
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
        DrawTextEx(font, "Tie!",(Vector2){170, 200}, 40, 1, GREEN);
    }else{
        char ans[110];
        sprintf(ans, "%s%c%s", "The '", winner, "' winner!");
        DrawTextEx(font, ans,(Vector2){60, 200}, 40, 1, GREEN);
    }
}

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

void buildGraph(int depth){
    Board tmp = board;
    initGraph();
    createSon(tmp, 0, 0);
    
    depth--;

    int turn = 1;
    while(depth--){
        addSubSetGraph(turn);
        turn = !turn;
    }

    setWeightFinalNodes();
}

int algorithm(int node, int depth, int isMaximizing){
    if(depth == 0) return getNodeWeight(node);
    if(isMaximizing){
        int child, value = INT32_MIN;
        for(int i = 0; i < howManyChildHasSubSet(node);i++){
            child = getSon(node, i);
            value = MAX(value, algorithm(child, (depth-1), 0));
        }
        setNodeWeight(node, value);
        return value;
    }else{
        int child, value = INT32_MAX;
        for(int i = 0; i < howManyChildHasSubSet(node);i++){
            child = getSon(node, i);
            value = MIN(value, algorithm(child, (depth-1), 1));
        }
        setNodeWeight(node, value);
        return value;
    }
}

Vector2 IAMachine(void){
    buildGraph(3);

    int ans = algorithm(0, 3, 1);
    int son, how_nodes = INT32_MAX;

    Board ans_board;
    for(int i = 0; i < howManyChildHasSubSet(0);i++){
        if(ans == getNodeWeight(getSon(0, i))){
            son = heightNode(getIdxOfNode(0, i));
            //printf("-> %d\n", son);
            if(son < how_nodes){
                how_nodes = son;
                ans_board = getBoard(0, i); 
            } 
        }
    }
    
    for(int i=0;i<3;i++) for(int j=0;j<3;j++){
        if(ans_board.game[i][j] != board.game[i][j]) return (Vector2){i,j};
    }
 
}

void printBackendGameImage(void){
    for(int i=0;i<3;i++) {
        for(int j=0;j<3;j++){
            printf("%c", board.game[i][j]);
        }
        printf("\n");
    }
}

void unLoadBoard(void){
    UnloadTexture(board.image);
    UnloadSound(click);
}