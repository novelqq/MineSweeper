#include <vector>
#include "GL/glut.h"
#include "game.hpp"
const int WIDTH = 400, HEIGHT = 400; 

void init(){

}

void display(){

}

void reshape(int w, int h){
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, w, 0, h);

}

int main(int argc, char** argv){
    init();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(100, 500);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Minesweeper");
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();

}