#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#include <GL/glut.h>
 
double rodar_y = 0;
double rodar_x = 0;
GLsizei winWidth = 400, winHeight = 400;
 
void display(){
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

	// Reinicia transformações
	glLoadIdentity();

	// Rotaciona
	glRotatef(rodar_x, 1.0, 0.0, 0.0);
	glRotatef(rodar_y, 0.0, 1.0, 0.0);

	// Face 1
	glBegin(GL_POLYGON);
  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(0.5, -0.5, -0.5);
  glVertex3f(0.5,  0.5, -0.5);
  glVertex3f(-0.5,  0.5, -0.5);
  glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	// Face 2
	glBegin(GL_POLYGON);
	glColor3f(1.0,  1.0, 1.0);
	glVertex3f(0.5, -0.5, 0.5);
	glVertex3f(0.5,  0.5, 0.5);
	glVertex3f(-0.5,  0.5, 0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glEnd();

	// Face 3
	glBegin(GL_POLYGON);
	glColor3f(0.0,  0.0,  1.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5,  0.5, -0.5);
	glVertex3f(0.5,  0.5,  0.5);
	glVertex3f(0.5, -0.5,  0.5);
	glEnd();

	// Face 4
	glBegin(GL_POLYGON);
	glColor3f(0.0,  1.0,  0.0);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5,  0.5,  0.5);
	glVertex3f(-0.5,  0.5, -0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	// Face 5
	glBegin(GL_POLYGON);
	glColor3f(1.0,  0.0,  1.0);
	glVertex3f(0.5,  0.5,  0.5);
	glVertex3f(0.5,  0.5, -0.5);
	glVertex3f(-0.5,  0.5, -0.5);
	glVertex3f(-0.5,  0.5,  0.5);
	glEnd();

	// Face 6
	glBegin(GL_POLYGON);
	glColor3f(1.0,  1.0,  0.0);
	glVertex3f(0.5, -0.5, -0.5);
	glVertex3f(0.5, -0.5,  0.5);
	glVertex3f(-0.5, -0.5, 0.5);
	glVertex3f(-0.5, -0.5, -0.5);
	glEnd();

	glFlush();
	glutSwapBuffers();
}

void specialKeys(int tecla, int x, int y) {
	// direita
	if (tecla == GLUT_KEY_RIGHT)
		rodar_y += 5;

	// esquerda
	else if (tecla == GLUT_KEY_LEFT)
		rodar_y -= 5;

  // cima
	else if (tecla == GLUT_KEY_UP)
		rodar_x += 5;

  // baixo
	else if (tecla == GLUT_KEY_DOWN)
		rodar_x -= 5;

	// atualiza o display
	glutPostRedisplay();
}

// fazer a animação de rodar sozinho
void animation(void){
	rodar_y += 0.1;
	rodar_x += 0.1;
	display();
}
 
int main(int argc, char* argv[]){
	glutInit(&argc,argv);

  // inicia a janela
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(winWidth,winHeight);
	glutInitWindowPosition(150,150);

	glutCreateWindow("Projeção Ortogonal do cubo");

	// Permite profundidade
	glEnable(GL_DEPTH_TEST);

	// Funções
	glutDisplayFunc(display);
  glutSpecialFunc(specialKeys);

	// Animação
	//glutIdleFunc(animation);
	
	glutMainLoop();

	
	return 0;
}