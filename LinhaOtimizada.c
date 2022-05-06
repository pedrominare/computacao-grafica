//Tarefa 2 - Linha Otimizada - Álan Bechaira, Amanda Miranda, Kamila Martins, Pedro Minare, Thuanny Cardeal
#include <math.h>
#include <stdio.h>
#include <GL/glut.h>

typedef struct a { // estrutura que descreve um ponto x,y
    int x,y;
} Ponto;

void desenhaLinha(Ponto p1, Ponto p2){
    int dx, dy, incE, incNE, d;
    GLint x,y;

    dx = p2.x - p1.x;
    dy = p2.y - p1.y;
    d = 2*dy-dx;
    incE = 2*dy; //Incremento de E
    incNE = 2*(dy-dx); //Incremento de NE
    x = p1.x;
    y = p1.y;

    glBegin(GL_POINTS);
        glVertex2i(x, y);
    glEnd();

    while(x<p2.x){
            /*Escolhe E*/
        if(d <= 0){
            d = d + incE;
            x = x + 1;
        }else{
            /*Escolhe NE*/
            d = d + incNE;
            x = x + 1;
            y = y + 1;
        }
        glBegin(GL_POINTS);
            glVertex2i(x, y);
        glEnd();
    }

}

void displayFcn(void){
    //Cria e configura o ponto inicial da linha (p1) e o ponto final da linha (p2)
    Ponto p1, p2;
    p1.x = 10;
    p1.y = 10;
    p2.x = 500;
    p2.y = 500;

    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0,0.0,0.0);

    //Chama a função pra desenhar a linha
    desenhaLinha (p1,p2);

    //Atualiza a tela
    glFlush();

}

main(int argc, char** argv){
    //Inicializa
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (100, 100);
    glutInitWindowSize (500, 500);
    glutCreateWindow ("Algoritmo Linha Otimizada");
    glClearColor (1.0,1.0,1.0,0.0);
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D (0.0, 200.0, 0.0, 150.0);

    glutDisplayFunc(displayFcn);//Define a função de display
    glutMainLoop();
}
