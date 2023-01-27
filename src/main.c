#include "raylib.h"
#include "board.h"
#include "user.h"
#include "menu.h"
#include "graph.h"
#include <stdio.h>

int main(void){
    // Initialization
    //--------------------------------------------------------------------------------------

    const int screenWidth = 400;
    const int screenHeight = 400;

    InitWindow(screenWidth, screenHeight, "Tic Tac Toe!");

    InitAudioDevice(); 

    initBoard();
    initMenu();
    int turn = 1;
    char winner;

    SetTargetFPS(60); 
    
    // Main game loop
    while (!WindowShouldClose()) {
        if(!canRun()){
            updateMenu();
            // Draw
            BeginDrawing();

                ClearBackground(RAYWHITE);
                drawMenu();
        
            EndDrawing();
        }
        else if(IsPvPorPvM()){
            winner = IsGameOver();

            // Update
            if(IsUserPlay() && !IsMark(getBoardPosition()) && winner=='-' && turn){
                updatePiece(getBoardPosition(), 1);
                turn = !turn;
            }else if(!turn && winner == '-'){
                updatePiece(IAMachine(), 0);
                closeGraph();
                turn = !turn;
            }

            // Draw
            BeginDrawing();

                ClearBackground(RAYWHITE);
                drawBoard();
                drawPiece();
                if(winner!='-') drawWindowWinner(winner);
        
            EndDrawing();
        }else{
            winner = IsGameOver();

            // Update
            if(IsUserPlay() && !IsMark(getBoardPosition()) && winner=='-'){
                updatePiece(getBoardPosition(), turn);
                turn = !turn;
            }

            // Draw
            BeginDrawing();

                ClearBackground(RAYWHITE);
                drawBoard();
                drawPiece();
                if(winner!='-') drawWindowWinner(winner);

            EndDrawing();
        }
    }   
    unLoadBoard();
    unLoadFilesMenu();
    CloseAudioDevice();
    CloseWindow();      

    return 0;
}