#include <stdio.h>

struct alfil{

    int x,y;

}A1;

struct torre{

    int x,y;

}T1;

struct reina{

    int x,y;

}Q1;

struct rey{

    int x,y;

}R1;

struct caballo{

    int x,y;

}C1;

void inicializar(int tablero[8][8]);
void imprimir(int tablero[8][8], int selec);
void caballo();

int main(){

    int opc;

    while(1){

        printf("\n\nMOVIMIENTOS VALIDOS DE PIEZAS DE AJEDREZ\n");
        printf("\nSeleccione la pieza para ver sus posibles movimientos: ");
        printf("\n1-Caballo");
        printf("\n2-Alfil");
        printf("\n3-Torre");
        printf("\n4-Reina");
        printf("\n5-Rey");
        printf("\n6-Salir\n");
        scanf("%d",&opc);

        switch(opc){

            case 1:

                caballo();

            break;

            case 2:
            break;

            case 3:
            break;

            case 4:
            break;

            case 5:
            break;

            case 6:

                return 0;

            break;

        }

    }

    
    return 0;

}

void inicializar(int tablero[8][8]){

    for(int i = 0; i < 8; i++){

        for(int j = 0; j < 8; j++){

            tablero[i][j] = 0;

        } 

    }

}

void imprimir(int tablero[8][8], int selec){

    for(int i = 0; i < 8; i++){

        for(int j = 0; j < 8; j++){

            if(tablero[i][j] == 0){

                printf("[ ]");

            }else if(tablero[i][j] == 1){

                switch(selec){

                    case 1:

                        printf("[C]");
                    
                    break;

                    case 2:

                        printf("[A]");
                    
                    break;

                    case 3:

                        printf("[T]");
                    
                    break;

                    case 4:

                        printf("[Q]");
                    
                    break;

                    case 5:

                        printf("[R]");
                    
                    break;

                }

            }else if(tablero[i][j] == 2){

                printf("[X]");

            }

        } 

        printf("\n");

    }

}

void caballo(){

    int tab[8][8];

    printf("\nDigite las cordenadas de la pieza:");
    printf("\nPara x: ");
    scanf("%d", &C1.x);
    printf("\nPara y: ");
    scanf("%d", &C1.y);

    inicializar(tab);

    if(C1.x-1 > 1 && C1.y-1 > 0){

        tab[C1.y-2][C1.x-3] = 2;
        
    }

    tab[C1.y-1][C1.x-1] = 1;

    imprimir(tab, 1);

}