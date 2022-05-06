#include <iostream>
#include <SDL2/SDL.h>

using namespace std;

void draw(int x, int y, SDL_Renderer *renderer){
    SDL_Rect rect = {x, y, 8, 8};
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);
}

int main(int argc, char *argv[]){

    bool running = true;
    int x = 350;
    int y = 250;

    //if (SDL_Init( SDL_INIT_EVERYTHING) < 0){
    //    std::cout << "SDL nao inicalizou " << SDL_GetError() << std::endl;
    //}

    SDL_Window * window = SDL_CreateWindow("Quadrado!", 100, 100, 800, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 127, 0, 127, 255);
    SDL_Rect rect = {x, y, 8, 8};
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer);

    while(running)
    {

      SDL_Event event;
      while(SDL_PollEvent(&event))
      {
        switch(event.type)
        {
        case SDL_QUIT:
            running = false;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym)
            {
            	//Esquerda
                case SDLK_4:
                case SDLK_KP_4:
                case SDLK_a:
                    x-=8;
                    draw(x, y, renderer);
                    break;
                //Direita
                case SDLK_6:
                case SDLK_KP_6:
                case SDLK_d:
                    x+=8;
                    draw(x, y, renderer);
                    break;
                //Cima
                case SDLK_8:
                case SDLK_KP_8:
                case SDLK_w:
                    y-=8;
                    draw(x, y, renderer);
                    break;
                //Baixo
                case SDLK_2:
                case SDLK_KP_2:
                case SDLK_x:
                    y+=8;
                    draw(x, y, renderer);
                    break;
                //Limpar tela + resetar quadrado
                case SDLK_5:
                case SDLK_KP_5:
                case SDLK_s:
                    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                    SDL_RenderClear(renderer);

					//Reseta o lugar do quadrado para o centro, mudando o valor de x e y para o centro
                    SDL_SetRenderDrawColor(renderer, 127, 0, 127, 255);
                    x = 350;
                    y = 250;
                    rect = {x, y, 8, 8};
                    SDL_RenderFillRect(renderer, &rect);

                    SDL_RenderPresent(renderer);
                    break;
                //Fechar a aplicacao
                case SDLK_ESCAPE:
                    running = false;
                    break;
            }
            break;

        }
      }
    }
    return 0;
}