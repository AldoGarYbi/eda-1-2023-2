#include <stdio.h>
#include <stdlib.h>

void posicion(int seleccion);

int main (){

    int cicl = 1;

    while(cicl == 1){

        int selec;

        printf("\n\nPOSIBLES MOVIMIENTOS DE REINA Y REY\n\n");
        printf("1- Reina");
        printf("\n2- Rey");
        printf("\n3- Salir\n");
        scanf("%i",&selec);

        switch(selec){

            case 1:

                posicion(selec);
                printf("\nSi desea volver a utilizar el programa digite 1, de lo contrario digite cualquier otro numero.\n");
                scanf("%d",&cicl);

            break;

            case 2:

                posicion(selec);
                printf("\nSi desea volver a utilizar el programa digite 1, de lo contrario digite cualquier otro numero.\n");
                scanf("%d",&cicl);

            break;

            case 3:

                return 0;

            break;



        }

    }

    return 0;

}

void posicion(int seleccion){

    int *tablero, i, j, x, y, ciclo = 1;
    tablero = (int *)malloc(64 * sizeof(int));

    if(tablero != NULL){

        while(ciclo == 1){

            printf("\nElija la posicion de la pieza en el tablero entre 1 y 8: ");
            printf("\nPara x: ");
            scanf("%d", &x);
            printf("\nPara y: ");
            scanf("%d", &y);
            printf("\n");

            if(x >= 1 && y >= 1 && x <= 8 && y <= 8){

                ciclo = 0;

                int auxx = x, auxy = y;

                int *tablero0;

                tablero0 = tablero;

                for(i = 0; i < 64; i++){

                    *(tablero+i) = 0;

                }

                if(seleccion == 1){
                        

                        for(i = 0; i < 8; i++){

                            *(tablero+((y-1)*8)) = 2;
                            tablero++;

                        }

                        tablero = tablero0;

                        for(i = 0; i < 8; i++){
                            
                            *(tablero+(x-1)) = 2;
                            tablero += 8;

                        }

                        tablero = tablero0;

                        while((auxy-1) < 8 && (auxx-1) < 8){

                            *(tablero+(((y-1)*8)+x-1)) = 2;
                            tablero += 9; 
                            auxy++;
                            auxx++;

                        }

                        tablero = tablero0;

                        auxx = x; 
                        auxy = y;

                        while((auxy+8) > 8 && (auxx-1) < 8){

                            *(tablero+(((y-1)*8)+x-1)) = 2;
                            tablero -= 7;
                            auxy--;
                            auxx++;

                        }

                        tablero = tablero0;

                        auxx = x; 
                        auxy = y;

                        while((auxy-1) < 8 && (auxx+8) > 8){

                            *(tablero+(((y-1)*8)+x-1)) = 2;
                            tablero += 7;
                            auxy++;
                            auxx--;

                        }

                        tablero = tablero0;

                        auxx = x; 
                        auxy = y;

                        while((auxy+8) > 8 && (auxx+8) > 8){

                            *(tablero+(((y-1)*8)+x-1)) = 2;
                            tablero -= 9;
                            auxy--;
                            auxx--;

                        }

                        tablero = tablero0;

                        auxx = x; 
                        auxy = y;

                }

                if(seleccion == 2){

                    if(y-1 < 7){

                        tablero += 8;
                        *(tablero+(((y-1)*8)+x-1)) = 2;
                    
                    }

                    tablero = tablero0;

                    if(y-1 > 0){

                        tablero -= 8;
                        *(tablero+(((y-1)*8)+x-1)) = 2;

                    }

                    tablero = tablero0;

                    if(x-1 < 7){

                        tablero++;
                        *(tablero+(((y-1)*8)+x-1)) = 2;

                    }

                    tablero = tablero0;

                    if(x-1 > 0){
                        
                        tablero--;
                        *(tablero+(((y-1)*8)+x-1)) = 2;

                    }

                    tablero = tablero0;

                    if(y-1 < 7 && x-1 < 7){

                        tablero+=9;
                        *(tablero+(((y-1)*8)+x-1)) = 2;

                    }

                    tablero = tablero0;

                    if(y-1 > 0 && x-1 > 0){

                        tablero-=9;
                        *(tablero+(((y-1)*8)+x-1)) = 2;

                    }

                    tablero = tablero0;

                    if(y-1 < 7 && x-1 > 0){

                        tablero+=7;
                        *(tablero+(((y-1)*8)+x-1)) = 2;

                    }

                    tablero = tablero0;

                    if(y-1 > 0 && x-1 < 7){

                        tablero-=7;
                        *(tablero+(((y-1)*8)+x-1)) = 2;

                    }

                    tablero = tablero0;

                }

                *(tablero+(((y-1)*8)+x-1)) = 1;

                tablero = tablero0;

                for(i = 0; i < 64; i++){

                    if(*(tablero+i) == 0){

                            printf("[ ]");

                    }else if(*(tablero+i) == 1){

                            if(seleccion == 1){

                                printf("[Q]");

                            }

                            if(seleccion == 2){

                                printf("[R]");

                            }

                    }else if(*(tablero+i) == 2){

                            printf("[X]");

                    }



                    if((i+1)%8 == 0){

                            printf("\n");

                    }

                }

                free(tablero);

            }else{
                
                printf("\nHa dado valores invalidos, por favor de valores entre 1 y 8.\n");
                ciclo = 1;

            }
        }   

    }else{

        printf("\nNo se ha podido reservar espacio de memoria.\n");

    }

}