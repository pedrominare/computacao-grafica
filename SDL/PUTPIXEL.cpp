/*
 * Desc: O programa desenha pixels em posições e cores aleatórias
 *       usando a função putpixel, que pode ser encontrada na
 *       documentação da SDL, na parte de exemplos.
 */
#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>
 
// Set the pixel
void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel);
 
// Variavel que representa a tela
SDL_Surface *screen = NULL;
 
// Ponto inicial da aplicação
int main(int argc, char *argv[])
{
    // Coordenadas do pixel
    int x, y;
    // Cor do pixel
    Uint32 pixel;
    // Flag de encerramento
    int bExit = 0;
     
    // Inicia o gerador de números aleatórios
    srand(time(NULL));
     
    // Inicializa a SDL com o Video e Audio
    if((SDL_Init(SDL_INIT_VIDEO) == -1))
        return 1;
     
    // Define a resolução 640x480 e 16 bits com "Double Buffer"
    screen = SDL_SetVideoMode(640, 480, 16, SDL_SWSURFACE | SDL_DOUBLEBUF);
    if (screen == NULL)
        return 2;
         
    // Muda o titulo da janela
    SDL_WM_SetCaption("Pixels Aleatórios - SDL", NULL);
     
    // Pinta a tela de azul
    SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 255));
     
    // Laço principal do programa
    while (!bExit)
    {
        SDL_Event  evento;
 
        // Verifica os eventos pendentes
        while (SDL_PollEvent(&evento))
        {
            switch (evento.type)
            {
                case SDL_KEYDOWN:
                    // Verifica se foi pressionado uma tecla
                    switch(evento.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            // Se a tecla foi ESC então sai
                            bExit = 1;
                            break;
                    }
                    break;
                     
                case SDL_QUIT:
                    // Se foi selecionador para fechar a janela
                    bExit = 1;
                    break;
            }
        }
         
        // Gera posições e uma cor aleatória
        x = rand() % 640;
        y = rand() % 480;
        pixel = SDL_MapRGB(screen->format, rand() % 256, rand() % 256, rand() % 256);
         
        // Pinta o pixel na tela
        putpixel(screen, x, y, pixel);
         
        // Executa o Flip (vira o "Double Buffer")
        SDL_Flip(screen);
    }
     
    // Libera a memória alocada para a tela
    SDL_FreeSurface(screen);
 
    // Finaliza a biblioteca SDL e a aplicação
    SDL_Quit();
     
    return 0;
}
 
/*
 * Set the pixel at (x, y) to the given value
 * NOTE: The surface must be locked before calling this!
 */
void putpixel(SDL_Surface *surface, int x, int y, Uint32 pixel)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to set */
    Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
 
    switch(bpp) {
    case 1:
        *p = pixel;
        break;
 
    case 2:
        *(Uint16 *)p = pixel;
        break;
 
    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN) {
            p[0] = (pixel >> 16) & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = pixel & 0xff;
        } else {
            p[0] = pixel & 0xff;
            p[1] = (pixel >> 8) & 0xff;
            p[2] = (pixel >> 16) & 0xff;
        }
        break;
 
    case 4:
        *(Uint32 *)p = pixel;
        break;
    }
}