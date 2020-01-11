#include <vector>
#include "GL/glut.h"
#include "game.hpp"
#include <iostream>

int WIDTH = 20, HEIGHT = 10, BOMB = 10;
Game *game;

void init(int width, int height, int bombs){
    WIDTH = width;
    HEIGHT = height;
    game = new Game(height, width, bombs);
    glClearColor(0.9, 0.9, 0.9, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    std::cout << "hello" << std::endl;
}

void display(){
    glViewport(0, 0, WIDTH*30, HEIGHT*30);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WIDTH, HEIGHT, 0);

    //draw grid
    // glColor3f(1, 1, 1);
    // glBegin(GL_LINES);
    // for(int i = 0; i < HEIGHT; i++){
    //     glVertex2f(i, 0.0);
    //     glVertex2f(i, HEIGHT);
    //     glVertex2f(0.0, i);
    //     glVertex2f(HEIGHT, i);
    // }
    // glEnd();
    for(int y = 0; y < HEIGHT; y++){
        for(int x = 0; x < WIDTH; x++){
            glColor3f(0.4, 0.4, 0.4);
            glRectd(x+0.1, y+0.1, x+0.9, y+0.9);
            Space current = game->getSpace(x, y);
            if(current.isClicked){
                //draw clicked box
                glColor3f(0.2, 0.2, 0.2);
                glRectd(x+0.1, y+0.1, x+0.9, y+0.9);
                if(current.adj_bombs > 0){
                    //draw adjacent bombs digit
                    switch(current.adj_bombs){
                        case 1:
                            glColor3f(0.0,0.0,1.0);
                            (GLUT_STROKE_ROMAN, 49);
                            break;
                        case 2:
                            glColor3f(0.0,1.0,0.0);
                            glutStrokeCharacter(GLUT_STROKE_ROMAN, 50);
                            break;
                        case 3:
                            glColor3f(1.0,0.0,0.0);
                            glutStrokeCharacter(GLUT_STROKE_ROMAN, 51);
                            break;
                    }
                }
            }
            else{
                //draw unclicked box
                if(current.isFlagged){
                    //draw flag
                }
            }
        }
    }
    glutSwapBuffers();
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
    if(button == GLUT_LEFT_BUTTON){
        if(state == GLUT_UP){
            float xpos, ypos;
            xpos = (float) x/(WIDTH*30)*WIDTH;
            ypos = (float) y/(HEIGHT*30)*HEIGHT;
            std::cout << (int) xpos << " , " << (int) ypos << std::endl;
            Space current = game->getSpace((int) xpos, (int) ypos);
            std::cout << current.adj_bombs << ", " << current.isClicked << ", " << current.isBomb << std::endl;
            game->reveal((int) xpos, (int) ypos, WIDTH, HEIGHT);
            glutPostRedisplay();

        }
    }
}
int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 500);
    glutInitWindowSize(WIDTH*30, HEIGHT*30);
    glutCreateWindow("Minesweeper");
    
    init(WIDTH, HEIGHT, BOMB);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMouseFunc(mouseButton);
    //glutMotionFunc(mouseMove);
    glutMainLoop();

}