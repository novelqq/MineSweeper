#include "game.hpp"

Game::Game(int height, int width, int bombs):
 height(height), width(width), bombs(bombs) {
    board.resize(10);
    for(int k = 0; k<10; k++){
        board[k].resize(10);
    }

    for(int y = 0; y<10; y++){
        for (int x = 0; x < 10; x++){
            board[x][y].isClicked = false;
            board[x][y].isBomb = false;
            board[x][y].adj_bombs = 0;
            board[x][y].isFlagged = false;
        }
    }
    gameover = false;
}

Game::~Game(){
    board.clear();
}

void Game::restart(){
    for(int y = 0; y<10; y++){
        for (int x = 0; x < 10; x++){
            board[x][y].isClicked = false;
            board[x][y].isBomb = false;
            board[x][y].adj_bombs = 0;
            board[x][y].isFlagged = false;
        }
    }
    gameover = false;
}

void Game::check(){
    int found_bombs = 0;
    for(int y = 0; y<10; y++){
        for (int x = 0; x < 10; x++){
            if(board[x][y].isClicked && board[x][y].isBomb){
                gameover = true;
            }
            if(board[x][y].isClicked && board[x][y].isBomb){
                found_bombs++;
            }
        }
    }

    if(found_bombs == 10)
}