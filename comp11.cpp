#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

void comentario(void);
void frase(void);
void opr(void);
void id(void);

//Funções de números

void q6(void);
void q7(void);
void q8(void);
void q9(void);
void q10(void);
void q11(void);

//Estrutura para a Tabela de Símbolos
/*typedef struct TabSimbolos{

    char token[5];
    char lexema[100];
    char valor[10];

}TabSimbolos; */

FILE *file;
int aux = 0, pos = 0;
char letra, caracter[1000], palavraReservada[100];

void comentario(){

    while( (caracter[aux] = fgetc(file)) != '}'){

        printf("%c", caracter[aux]);
        aux++;

    }
    printf("\nFim de comentário\n");

}

void frase(){

    while( (caracter[aux] = fgetc(file)) != '"'){

        printf("%c", caracter[aux]);
        aux++;
    }
    printf("\nFim de frase\n");

}

void opr(){

    aux ++;
    caracter[aux] = fgetc(file);
    if(caracter[aux] == '=' && caracter[aux - 1] == '>'){
        printf("OPR >=\n");
    }
    else if(caracter[aux] == '=' && caracter[aux - 1] == '<'){
        printf("OPR <= \n");
    }
    else if(caracter[aux] == '-'){
        printf("OPR <- \n");
    }
    else if(caracter[aux] == '>'){
        printf("OPR <> \n");
    }
    else{

        printf("OPR %c\n", caracter[aux - 1]);
    }

}

void id(){

    aux++;
    pos++;
    caracter[aux] = fgetc(file);
    palavraReservada[pos] = caracter[aux];
    if(caracter[aux] == '_'){
        id();
    }
    else if(caracter[aux] == 'a'  || caracter[aux] == 'b' || caracter[aux] == 'c' || caracter[aux] == 'd' || caracter[aux] == 'e' || caracter[aux] == 'f' || caracter[aux] == 'g' || caracter[aux] == 'h' || caracter[aux] == 'i' || caracter[aux] == 'j' || caracter[aux] == 'k' || caracter[aux] == 'l'
            || caracter[aux] == 'm' || caracter[aux] == 'n' || caracter[aux] == 'o' || caracter[aux] == 'p' || caracter[aux] == 'q' || caracter[aux] == 'r' || caracter[aux] == 's' || caracter[aux] == 't' || caracter[aux] == 'u' || caracter[aux] == 'v' || caracter[aux] == 'w' || caracter[aux] == 'x' || caracter[aux] == 'y' || caracter[aux] == 'z'
            || caracter[aux] == 'A'  || caracter[aux] == 'B' || caracter[aux] == 'C' || caracter[aux] == 'D' || caracter[aux] == 'E' || caracter[aux] == 'F' || caracter[aux] == 'G' || caracter[aux] == 'H' || caracter[aux] == 'I' || caracter[aux] == 'J' || caracter[aux] == 'K' || caracter[aux] == 'L'
            || caracter[aux] == 'M' || caracter[aux] == 'N' || caracter[aux] == 'O' || caracter[aux] == 'P' || caracter[aux] == 'Q' || caracter[aux] == 'R' || caracter[aux] == 'S' || caracter[aux] == 'T' || caracter[aux] == 'U' || caracter[aux] == 'V' || caracter[aux] == 'W' || caracter[aux] == 'X' || caracter[aux] == 'Y' || caracter[aux] == 'Z'){

        id();
    }
    else if(caracter[aux] == '0' || caracter[aux] == '1' || caracter[aux] == '2' || caracter[aux] == '3' || caracter[aux] == '4' || caracter[aux] == '5' ||
            caracter[aux] == '6' || caracter[aux] == '7' || caracter[aux] == '8' || caracter[aux] == '9'){

        id();
    }

    else{

        printf("ID reconhecido\n");
    }

}

void q6(){

    aux++;
    caracter[aux] = fgetc(file);
    if(caracter[aux] == '0' || caracter[aux] == '1' || caracter[aux] == '2' || caracter[aux] == '3' || caracter[aux] == '4' || caracter[aux] == '5' ||
       caracter[aux] == '6' || caracter[aux] == '7' || caracter[aux] == '8' || caracter[aux] == '9'){

        q6();
    }
    else if(caracter[aux] == '.'){

        q7();
    }
    else if(caracter[aux] == 'E'){

        q9();
    }
    else{

        printf("Número reconhecido\n");
    }

}

void q7(){

    aux++;
    caracter[aux] = fgetc(file);
    if(caracter[aux] == '0' || caracter[aux] == '1' || caracter[aux] == '2' || caracter[aux] == '3' || caracter[aux] == '4' || caracter[aux] == '5' ||
       caracter[aux] == '6' || caracter[aux] == '7' || caracter[aux] == '8' || caracter[aux] == '9'){

        q8();
    }
    else{

        printf("Número não reconhecido\n");
    }

}

void q8(){

    aux++;
    caracter[aux] = fgetc(file);
    if(caracter[aux] == '0' || caracter[aux] == '1' || caracter[aux] == '2' || caracter[aux] == '3' || caracter[aux] == '4' || caracter[aux] == '5' ||
       caracter[aux] == '6' || caracter[aux] == '7' || caracter[aux] == '8' || caracter[aux] == '9'){

        q8();
    }
    else if(caracter[aux] == 'E'){

        q9();
    }
    else{

        printf("Número reconhecido\n");
    }

}

void q9(){

    aux++;
    caracter[aux] = fgetc(file);
    if(caracter[aux] == '+' || caracter[aux] == '-'){

        q10();
    }
    else{

        printf("Número não reconhecido\n");
    }

}

void q10(){

    aux++;
    caracter[aux] = fgetc(file);
    if(caracter[aux] == '0' || caracter[aux] == '1' || caracter[aux] == '2' || caracter[aux] == '3' || caracter[aux] == '4' || caracter[aux] == '5' ||
       caracter[aux] == '6' || caracter[aux] == '7' || caracter[aux] == '8' || caracter[aux] == '9'){

        q11();
    }
    else{

        printf("Número não reconhecido\n");
    }

}

void q11(){

    aux++;
    caracter[aux] = fgetc(file);
    if(caracter[aux] == '0' || caracter[aux] == '1' || caracter[aux] == '2' || caracter[aux] == '3' || caracter[aux] == '4' || caracter[aux] == '5' ||
       caracter[aux] == '6' || caracter[aux] == '7' || caracter[aux] == '8' || caracter[aux] == '9'){


        q11();
    }
    else{

        printf("Número reconhecido\n");
    }

}

int main(){

    setlocale(LC_ALL, "Portuguese");
    file = fopen("fonte.txt", "rt");
    printf("---------------FASE LÉXICA DO COMPILADOR---------------\n");

    while( (letra = fgetc(file)) != EOF){
        caracter[aux] = letra;

        if(caracter[aux] == '{'){

            printf("Começo de comentário\n");
            comentario();
        }
        else if(caracter[aux] == '"'){
            printf("Começo de frase\n");
            frase();
        }
        else if(caracter[aux] == '	'){

            printf("Tab\n");
        }
        else if(caracter[aux] == '('){

            printf("Abre Parêntese\n");

        }
        else if(caracter[aux] == ')'){

            printf("Fecha Parêntese\n");
        }
        else if(caracter[aux] == ' '){

            printf("Espaço\n");
        }
        else if(caracter[aux] == '+' || caracter[aux] == '-' || caracter[aux] == '*' || caracter[aux] == '/'){
            printf("OPM %c\n", caracter[aux]);
        }
        else if(caracter[aux] == '='){

            printf("OPR = \n");
        }
        else if(caracter[aux] == '>'){

            opr();
        }
        else if(caracter[aux] == '<'){

            opr();
        }
        else if(caracter[aux] == '\n'){

            printf("Pula-linha\n");
        }
        else if(caracter[aux] == '0' || caracter[aux] == '1' || caracter[aux] == '2' || caracter[aux] == '3' || caracter[aux] == '4' || caracter[aux] == '5' ||
                caracter[aux] == '6' || caracter[aux] == '7' || caracter[aux] == '8' || caracter[aux] == '9'){

            q6();
        }
        else if(caracter[aux] == 'a'  || caracter[aux] == 'b' || caracter[aux] == 'c' || caracter[aux] == 'd' || caracter[aux] == 'e' || caracter[aux] == 'f' || caracter[aux] == 'g' || caracter[aux] == 'h' || caracter[aux] == 'i' || caracter[aux] == 'j' || caracter[aux] == 'k' || caracter[aux] == 'l'
                || caracter[aux] == 'm' || caracter[aux] == 'n' || caracter[aux] == 'o' || caracter[aux] == 'p' || caracter[aux] == 'q' || caracter[aux] == 'r' || caracter[aux] == 's' || caracter[aux] == 't' || caracter[aux] == 'u' || caracter[aux] == 'v' || caracter[aux] == 'w' || caracter[aux] == 'x' || caracter[aux] == 'y' || caracter[aux] == 'z'
                || caracter[aux] == 'A'  || caracter[aux] == 'B' || caracter[aux] == 'C' || caracter[aux] == 'D' || caracter[aux] == 'E' || caracter[aux] == 'F' || caracter[aux] == 'G' || caracter[aux] == 'H' || caracter[aux] == 'I' || caracter[aux] == 'J' || caracter[aux] == 'K' || caracter[aux] == 'L'
                || caracter[aux] == 'M' || caracter[aux] == 'N' || caracter[aux] == 'O' || caracter[aux] == 'P' || caracter[aux] == 'Q' || caracter[aux] == 'R' || caracter[aux] == 'S' || caracter[aux] == 'T' || caracter[aux] == 'U' || caracter[aux] == 'V' || caracter[aux] == 'W' || caracter[aux] == 'X' || caracter[aux] == 'Y' || caracter[aux] == 'Z'){

            palavraReservada[pos] = caracter[aux];
            id();
            printf("%s\n", palavraReservada);

        }
        /*if( strcmp(palavraReservada, "inicio") == 0 || strcmp(palavraReservada, "varinicio") == 0 || strcmp(palavraReservada, "varfim") == 0 || strcmp(palavraReservada, "escreva") == 0 || strcmp(palavraReservada, "leia") == 0 || strcmp(palavraReservada, "se") == 0
            ||strcmp(palavraReservada, "entao") == 0 || strcmp(palavraReservada, "fimse") == 0 || strcmp(palavraReservada, "fim") == 0 || strcmp(palavraReservada, "inteiro") == 0 || strcmp(palavraReservada, "lit") == 0 || strcmp(palavraReservada, "real") == 0){

            printf("Palavra Reservada");
        }*/
        aux++;
        int i;
        for(i = 1; i < pos; i++){

            palavraReservada[i] = NULL;
        }
        pos = 0;
    }

    fclose(file);
    printf("-------------------------------------------------------");
}
