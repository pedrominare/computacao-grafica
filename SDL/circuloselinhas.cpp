/*
O codigo consiste em desenhar linhas e circulos em posicoes aleatorias usando 2 funcoes,
sendo para desenhar as linhas a funcao linhaDDA e para desenhar circulos a funcao
circBrasenham (no caso o nome correto seria Bresenham...).
O usuario deve gerar linhas pressionando a tecla 2 e circulos pressionando a tecla 1.

Para compilar o codigo: g++ circuloselinhas.cpp -o circ -lSDL2
*/
#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

//desenha um circulo preenchido utilizando o algoritmo de Bresenham em diferentes posicoes no plano
void circBrasenham(SDL_Renderer *renderer, int xc, int yc, int radius, SDL_Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w;
            int dy = radius - h;
            if ((dx*dx + dy*dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(renderer, xc + dx, yc + dy);
            }
        }
    }
}
//desenha uma linha com pontos selecionados aleatoriamente em diferentes posicoes no plano
void linhaDDA(SDL_Renderer *renderer, int xi,int yi,int xf,int yf, SDL_Color color) {

  int cx = xi;
  int cy = yi;
  int dx = xf - cx;
  int dy = yf - cy;
  if(dx<0) dx = 0-dx;
  if(dy<0) dy = 0-dy;

  int sx=0; int sy=0;
  if(cx < xf) sx = 1; else sx = -1;
  if(cy < yf) sy = 1; else sy = -1;
  int err = dx-dy;

  for(int n=0;n<1000;n++) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawPoint(renderer, cx, cy);

    if((cx==xf) && (cy==yf)) return;
    int e2 = 2*err;
    if(e2 > (0-dy)) { err = err - dy; cx = cx + sx; }
    if(e2 < dx) { err = err + dx; cy = cy + sy; }
  }
}

int main(int argc, char *argv[]){

    bool working = true;
    int x = 350;
    int y = 250;

    if (SDL_Init( SDL_INIT_EVERYTHING) < 0){
        std::cout << "SDL couldn't initialize correctly ! " << SDL_GetError() << std::endl;
    }

    SDL_Window * window = SDL_CreateWindow("Circles and Lines", 100, 100, 700, 500, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Color color;

    while(working)
    {

      SDL_Event event;

      while(SDL_PollEvent(&event))
      {
      if(event.type == SDL_QUIT){
                working = false;
            }
            // fechar com a tecla ESC, quando ela for solta.
            if(event.type == SDL_KEYUP && event.key.keysym.sym == SDLK_ESCAPE){
                working = false;
            }
            // criacao dos objetos reta ou circulo
            if (event.type == SDL_KEYDOWN) // tecla pressionada, e nao solta...
            {
                if (event.key.keysym.sym == SDLK_1){ // cria circulo
					//seleciona aleatoriamente uma cor para o circulo utilizando RGBA
                    color.a = rand() % 256;
                    color.b = rand() % 256;
                    color.g = rand() % 256;
                    color.r = rand() % 256;
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                    SDL_RenderClear(renderer);
					//Bresenham fazendo circulo e preenchendo
                    circBrasenham(renderer, rand() % 500, rand() % 500, rand() % 100 + 100, color);
                    SDL_RenderPresent(renderer);
                }
                else if (event.key.keysym.sym == SDLK_2){ //cria linha
					//seleciona aleatoriamente uma cor para a linha utilizando RGBA
                    color.a = rand() % 256;
                    color.b = rand() % 256;
                    color.g = rand() % 256;
                    color.r = rand() % 256;
                    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
                    SDL_RenderClear(renderer);
                    linhaDDA(renderer, rand() % 500, rand() % 500, rand() % 500, rand() % 500, color);
                    SDL_RenderPresent(renderer);
                }
            }
      }
    }
    return 0;
}
