#include "game.hpp"
#include <time.h>
#include <stdlib.h>
#include <iostream>

Game::Game(int height, int width, int bombs):
 height(height), width(width), bombs(bombs) {
    board.resize(width);
    for(int k = 0; k<width; k++){
        board[k].resize(height);
    }

    //set default params for board
    gameover = false;
    won = false;
    for(int y = 0; y<height; y++){
        for (int x = 0; x < width; x++){
            board[x][y].isClicked = false;
            board[x][y].isBomb = false;
            board[x][y].adj_bombs = 0;
            board[x][y].isFlagged = false;
        }
    }

    //distribute bombs on board
    srand(time(0));
    int bombs_remaining = bombs;
    while(bombs_remaining != 0){
        int rand_x = rand() % 10;
        int rand_y = rand() % 20;
        std::cout << rand_x << " , " << rand_y << std::endl;
        if(!(board[rand_x][rand_y].isBomb)){
            board[rand_x][rand_y].isBomb = true;
            bombs_remaining--;
        }
    }
    
    //calculate adj bombs for each space
    for(int y = 0; y<height; y++){
        for (int x = 0; x < width; x++){
            int adjbombs = 0;
            if(x < 9 && y < 19){
                if(board[x+1][y].isBomb){ adjbombs++; }
                if(board[x+1][y+1].isBomb){ adjbombs++; }
                if(board[x][y+1].isBomb){ adjbombs++; }
            }
            if(x < 9 && y > 0){
                if(board[x+1][y-1].isBomb){ adjbombs++; }
                if(board[x+1][y].isBomb){ adjbombs++; }
                if(board[x][y-1].isBomb){ adjbombs++; }
            }
            if(x > 0 && y > 0){
                if(board[x-1][y-1].isBomb){ adjbombs++; }
            }
            if(x > 0 && y < 19){
                if(board[x-1][y+1].isBomb){ adjbombs++; }
                if(board[x-1][y].isBomb){ adjbombs++; }
            }
            board[x][y].adj_bombs = adjbombs; 
        }
    }
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
            if(board[x][y].isFlagged && board[x][y].isBomb){
                found_bombs++;
            }
        }
    }

    if(found_bombs == bombs && !gameover){
        gameover = true;
        won = true;
    }
}

Space Game::getSpace(int x, int y){
    return board[x][y]; 
}

void Game::reveal(int x, int y, int width, int height){
    if(board[x][y].isBomb){
        return;
    }
    else{
        traverse(x, y, width, height);
    }
}

void Game::traverse(int x, int y, int width, int height){
    if(!(board[x][y].isBomb) && !(board[x][y].isClicked)){
        board[x][y].isClicked = true;
        if(board[x][y].adj_bombs > 0){
            return;
        }
        if(x < width - 1){
            std::cout << "Traverse right" << std::endl;
            traverse(x+1, y, width, height);
        }
        if(x > 0){
            std::cout << "Traverse left" << std::endl;
            traverse(x-1, y, width, height);
        }
        if(y < height - 1){
            std::cout << "Traverse down" << std::endl;
            traverse(x, y+1, width, height);
        }
        if(y > 0){
            std::cout << "Traverse up" << std::endl;
            traverse(x, y-1, width, height);
        }
        return;
    }
}