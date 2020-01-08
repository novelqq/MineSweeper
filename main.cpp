#include <vector>
#include "GL/glut.h"
#include "game.hpp"

int WIDTH, HEIGHT;

Game *game;
void init(int width, int height, int bombs){
    WIDTH = width;
    HEIGHT = height;
    game = new Game(width, height, bombs);
}

void display(){
    glViewport(0, 0, WIDTH, HEIGHT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, 0, HEIGHT);
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            Space current = game->getSpace(x, y);
            if(current.isClicked){

            }
            else{
                //draw unclicked box
                if(current.isFlagged){

                }
            }
        }
    }
}

void reshape(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);

}

void mouseMove(int x, int y){

}

void mouseButton(int button, int state, int x, int y){

}
int main(int argc, char** argv){
    init((int) argv[1], (int) argv[2], (int) argv[3]);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 500);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Minesweeper");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouseButton);
    glutMotionFunc(mouseMove);
    glutMainLoop();

}