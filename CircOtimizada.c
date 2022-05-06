//Tarefa 3 - Circunferencia Otimizada - Álan Bechaira, Amanda Miranda, Kamila Martins, Pedro Minare, Thuanny Cardeal
#include <math.h>
#include <stdio.h>
#include <GL/glut.h>

GLsizei winWidth = 600,    winHeight = 600;
GLfloat xwcMin   = -255.0, xwcMax = 255.0;
GLfloat ywcMin   = -255.0, ywcMax = 255.0;

/* Pinta o pixel na tela */
void write_pixel(GLfloat x, GLfloat y){

	glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

}

void CirclePoints(int x, int y){
	write_pixel( x, y);
	write_pixel( x,-y);
	write_pixel(-x, y);
	write_pixel(-x,-y);
	write_pixel( y, x);
	write_pixel( y,-x);
	write_pixel(-y, x);
	write_pixel(-y,-x);
}


// Substituir 'd' por 'h'
void MidPointCircle(int r){
	int x, y;
	float d;

	/* valores iniciais */
	x = 0;
	y = r;
	d = 5/4 - r;

	CirclePoints(x, y);
	while(y > x){
		if(d < 0){
			/* Seleciona E */
			d = d + 2 * x + 3;
		}else{
			/* Seleciona SE */
			d = d + 2 * (x - y) + 5;
			y--;
		}
		x++;
		CirclePoints(x, y);
	}
}

void displayFcn(void){

    int raio = 200;

    //raio = 200;

    glClear (GL_COLOR_BUFFER_BIT);
    glColor3f (0.0,0.0,0.0);

    //Chama a função pra desenhar a circunferencia
    MidPointCircle(raio);

    //Atualiza a tela
    glFlush();

}

void winReshapeFcn (GLint newWidth, GLint newHeight)
{
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D (xwcMin, xwcMax,ywcMin, ywcMax);
	glClear (GL_COLOR_BUFFER_BIT);
}

main(int argc, char** argv){
    //Inicializa
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (100, 100);
    glutInitWindowSize (500, 500);
    glutCreateWindow ("Algoritmo Circunferencia Otimizada");
    glClearColor (1.0,1.0,1.0,0.0);
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D (0.0, 200.0, 0.0, 150.0);

    glutDisplayFunc(displayFcn);//Define a função de display
    glutReshapeFunc(winReshapeFcn);
    glutMainLoop();
}
