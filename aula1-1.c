#include<GL/glut.h>//inclua a biblioteca glut

double x = 1;
void init()
{
 glClearColor(0,0,0,0);
 gluOrtho2D(-5,5,-5,5);//estabeleca a area de visualizacao
}
//a seguir e discriminada a nossa funcao de exibicao chamada display. Temos tres objetos com suas
//respectiva cores.
//Algumas funcoes novas serao apresentadas.
//glPushMatrix(); cria uma nova matrix na pilha de matrizes.
//glPopMatrix(); retira uma matriz da pilha de matrizes.
//glRotatef(ang,x,y,z); rotaciona objetos em torno da origem. O primeiro argumento e o angulo da
//rotacao em radianos. Os outros argumentos estao relacionados aos eixos de rotacao. Se voce usar //
//(90,1,0,0) sera rotacionado 90 graus em torno do eixo X..
//glScalef(sx,sy,sz);
//glTranslatef(tx,ty,tz);
void display()
{
 GLdouble theta = 90;
 glClear(GL_COLOR_BUFFER_BIT);
 glColor3f(1,0,0);//cor vermelha
 glBegin(GL_QUADS);//comeca a desenhar quadrilatros
 glVertex2f(-1*x,-1*x);//primeiro vertice
 glVertex2f(1*x,-1*x);//segundo vertice
 glVertex2f(1*x,1*x);//terceiro vertice
 glVertex2f(-1*x,1*x);//ultimo vertice
 //glScalef(2,2,2);
 glEnd();//termina o desenho
 glFlush();
}
int main(int argc, char ** argv)
{
 scanf("%lf", &x);	
 glutInit(&argc, argv);
 glutInitWindowSize(800,600);
 glutInitWindowPosition(10,50);
 glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
 glutCreateWindow("Transformacoes");
 init();
 glutDisplayFunc(display); glutMainLoop();
}
