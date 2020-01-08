#include "game.hpp"

Game::Game(int height, int width, int bombs):
 height(height), width(width), bombs(bombs) {
    board.resize(width);
    for(int k = 0; k<width; k++){
        board[k].resize(height);
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
    won = false;
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
    won = false;
}

void Game::check(){
    int found_bombs = 0;
    for(int y = 0; y<height; y++){
        for (int x = 0; x < width; x++){
            if(board[x][y].isClicked && board[x][y].isBomb){
                gameover = true;
                won = false;
            }
            if(board[x][y].isClicked && board[x][y].isBomb){
                found_bombs++;
            }
        }
    }

    if(found_bombs == bombs && !gameover){
        gameover = true;
        won = true;
    }
}