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
void alfil();
void torre();
void reina();
void rey();

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

                alfil();

            break;

            case 3:

                torre();

            break;

            case 4:

                reina();

            break;

            case 5:

                rey();

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

    printf("\nLos movimientos validos para la pieza son: \n\n");

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

    int tab[8][8], cond = 1;

    while (cond == 1){

        printf("\nDigite las cordenadas de la pieza entre 1 y 8:");
        printf("\nPara x: ");
        scanf("%d", &C1.x);
        printf("\nPara y: ");
        scanf("%d", &C1.y);

        if(C1.x > 0 && C1.x <= 8 && C1.y > 0 && C1.y <= 8){

            cond = 2;

        }else{

            printf("\nPorfavor digite un valor entre 1 y 8 para ambas coordenadas.\n");

        }
    }

    
    inicializar(tab);

    if(C1.x-1 > 1 && C1.y-1 > 0){

        tab[C1.y-2][C1.x-3] = 2;
        
    }

    if(C1.x-1 > 0 && C1.y-1 > 1){

        tab[C1.y-3][C1.x-2] = 2;
        
    }

    if(C1.x-1 < 7 && C1.y-1 > 1){

        tab[C1.y-3][C1.x] = 2;
        
    }

    if(C1.x-1 < 6 && C1.y-1 > 0){

        tab[C1.y-2][C1.x+1] = 2;
        
    }

    if(C1.x-1 > 1 && C1.y-1 < 7){

        tab[C1.y][C1.x-3] = 2;
        
    }

    if(C1.x-1 > 0 && C1.y-1 < 6){

        tab[C1.y+1][C1.x-2] = 2;
        
    }

    if(C1.x-1 < 7 && C1.y-1 < 6){

        tab[C1.y+1][C1.x] = 2;
        
    }

    if(C1.x-1 < 6 && C1.y-1 < 7){

        tab[C1.y][C1.x+1] = 2;
        
    }

    tab[C1.y-1][C1.x-1] = 1;

    imprimir(tab, 1);

}

void alfil(){

    int tab[8][8], cond = 1;

    while (cond == 1){

        printf("\nDigite las cordenadas de la pieza entre 1 y 8:");
        printf("\nPara x: ");
        scanf("%d", &A1.x);
        printf("\nPara y: ");
        scanf("%d", &A1.y);

        if(A1.x > 0 && A1.x <= 8 && A1.y > 0 && A1.y <= 8){

            cond = 2;

        }else{

            printf("\nPorfavor digite un valor entre 1 y 8 para ambas coordenadas.\n");

        }
    }

    inicializar(tab);

    int contx = 0;
    int conty = 0;

    for(int i = 0; i < 8; i++){

        for(int j = 0; j < 8; j++){

            if(i == A1.x-1){
                
                if(i+contx >= 0 && i+contx<8 && j+A1.y-1 < 8 && j+A1.y-1 >= 0){

                    tab[j+A1.y-1][i+contx] = 2;
                    
                }

                if(j+A1.y-1 < 8 && j+A1.y-1 >= 0 && i-contx >= 0 && i-contx<8){

                    tab[j+A1.y-1][i-contx]= 2;
                    
                }

                if(i+contx >= 0 && i+contx<8 && j+A1.y-1-conty >= 0 && j+A1.y-1-conty < 8){

                    tab[j+A1.y-1-conty][i+contx] = 2;

                }

                if(j+A1.y-1-conty >= 0 && j+A1.y-1-conty < 8 && i-contx >= 0 && i-contx<8){

                    tab[j+A1.y-1-conty][i-contx]= 2;

                }


                contx++;
                conty += 2;

            }

        }

    }

    tab[A1.y-1][A1.x-1] = 1;

    imprimir(tab, 2);

}

void torre(){

    int tab[8][8], cond = 1;

    while (cond == 1){

        printf("\nDigite las cordenadas de la pieza entre 1 y 8:");
        printf("\nPara x: ");
        scanf("%d", &T1.x);
        printf("\nPara y: ");
        scanf("%d", &T1.y);

        if(T1.x > 0 && T1.x <= 8 && T1.y > 0 && T1.y <= 8){

            cond = 2;

        }else{

            printf("\nPorfavor digite un valor entre 1 y 8 para ambas coordenadas.\n");

        }
    }

    inicializar(tab);

    for(int i = 0; i < 8; i++){

        for(int j = 0; j < 8; j++){

            if(i == T1.x-1){

                tab[j][i] = 2;

            }

            if(j == T1.y-1){

                tab[j][i] = 2;

            }

        }

    }

    tab[T1.y-1][T1.x-1] = 1;

    imprimir(tab, 3);

}

void reina(){

    int tab[8][8], cond = 1;

    while (cond == 1){

        printf("\nDigite las cordenadas de la pieza entre 1 y 8:");
        printf("\nPara x: ");
        scanf("%d", &Q1.x);
        printf("\nPara y: ");
        scanf("%d", &Q1.y);

        if(Q1.x > 0 && Q1.x <= 8 && Q1.y > 0 && Q1.y <= 8){

            cond = 2;

        }else{

            printf("\nPorfavor digite un valor entre 1 y 8 para ambas coordenadas.\n");

        }
    }

    inicializar(tab);

    int contx = 0;
    int conty = 0;

    for(int i = 0; i < 8; i++){

        for(int j = 0; j < 8; j++){

            if(i == Q1.x-1){
                
                if(i+contx >= 0 && i+contx<8 && j+Q1.y-1 < 8 && j+Q1.y-1 >= 0){

                    tab[j+Q1.y-1][i+contx] = 2;
                    
                }

                if(j+Q1.y-1 < 8 && j+Q1.y-1 >= 0 && i-contx >= 0 && i-contx<8){

                    tab[j+Q1.y-1][i-contx]= 2;
                    
                }

                if(i+contx >= 0 && i+contx<8 && j+Q1.y-1-conty >= 0 && j+Q1.y-1-conty < 8){

                    tab[j+Q1.y-1-conty][i+contx] = 2;

                }

                if(j+Q1.y-1-conty >= 0 && j+Q1.y-1-conty < 8 && i-contx >= 0 && i-contx<8){

                    tab[j+Q1.y-1-conty][i-contx]= 2;

                }


                contx++;
                conty += 2;

                tab[j][i] = 2;

            }

            if(j == Q1.y-1){

                tab[j][i] = 2;

            }

        }

    }

    tab[Q1.y-1][Q1.x-1] = 1;

    imprimir(tab, 4);

}

void rey(){

    int tab[8][8], cond = 1;

    while (cond == 1){

        printf("\nDigite las cordenadas de la pieza entre 1 y 8:");
        printf("\nPara x: ");
        scanf("%d", &R1.x);
        printf("\nPara y: ");
        scanf("%d", &R1.y);

        if(R1.x > 0 && R1.x <= 8 && R1.y > 0 && R1.y <= 8){

            cond = 2;

        }else{

            printf("\nPorfavor digite un valor entre 1 y 8 para ambas coordenadas.\n");

        }
    }

    inicializar(tab);

    if(R1.x-1 > 0){

        tab[R1.y-1][R1.x-2] = 2;

    }

    if(R1.x-1 < 7){

        tab[R1.y-1][R1.x] = 2;

    }

    if(R1.y-1 > 0){

        tab[R1.y-2][R1.x-1] = 2;

    }

    if(R1.y-1 < 7){

        tab[R1.y][R1.x-1] = 2;

    }

    if(R1.x-1 > 0 && R1.y-1 > 0){

        tab[R1.y-2][R1.x-2] = 2;

    }

    if(R1.x-1 < 7 && R1.y-1 > 0){

        tab[R1.y-2][R1.x] = 2;

    }

    if(R1.x-1 > 0 && R1.y-1 < 7){

        tab[R1.y][R1.x-2] = 2;

    }

     if(R1.x-1 < 7 && R1.y-1 < 7){

        tab[R1.y][R1.x] = 2;

    }

    tab[R1.y-1][R1.x-1] = 1;

    imprimir(tab, 5);

}