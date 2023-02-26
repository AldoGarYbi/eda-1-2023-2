#include <stdio.h>

void posicion (int eleccion);

int main (){

    while (1){

        int elec;

        printf("\nMOVIMIENTOS VALIDOS EN PIEZAS DE AJEDREZ\n");
        printf("\n1- Alfil. ");
        printf("\n2- Torre. ");
        printf("\n3- Salir. \n");
        scanf("%i", &elec);

        switch(elec){

            case 1:
                posicion(elec);
            break;

            case 2:
                posicion(elec);
            break;

            case 3:

                return 0;

            break;    

        }


    }

    return 0;

}

void posicion(int eleccion){

    int x, y, condi = 0;

    while(condi == 0){

        printf("\nSeleccione la posicion de la pieza, entre 0 y 8: ");
        printf("\nPara x: ");
        scanf("%i", &x);
        printf("\nPara y: ");
        scanf("%i", &y);
        printf("\n");

        if(x <= 8 && x >= 0 && y <= 8 && y >= 0){

            int tablero[8][8];

            for(int i = 0; i < 8; i++){

                for(int j = 0; j < 8; j++){

                    tablero[i][j] = 0;

                }

            }

            if(eleccion == 1){
                
                int contx = 0;
                int conty = 0;

                for(int i = 0; i < 8; i++){

                    for(int j = 0; j < 8; j++){

                        if(i == x-1){
                            
                            if(i+contx >= 0 && i+contx<8 && j+y-1 < 8 && j+y-1 >= 0){

                                tablero[i+contx][j+y-1] = 2;
                                
                            }

                            if(j+y-1 < 8 && j+y-1 >= 0 && i-contx >= 0 && i-contx<8){

                                tablero[i-contx][j+y-1]= 2;
                                
                            }

                            if(i+contx >= 0 && i+contx<8 && j+y-1-conty >= 0 && j+y-1-conty < 8){

                                tablero[i+contx][j+y-1-conty] = 2;

                            }

                            if(j+y-1-conty >= 0 && j+y-1-conty < 8 && i-contx >= 0 && i-contx<8){

                                tablero[i-contx][j+y-1-conty]= 2;

                            }


                            contx++;
                            conty += 2;

                        }

                    }

                }

            }

            if(eleccion == 2){

                for(int i = 0; i < 8; i++){

                    for(int j = 0; j < 8; j++){

                        if(i == x-1){

                            tablero[i][j] = 2;

                        }

                        if(j == y-1){

                            tablero[i][j] = 2;

                        }

                    }

                }

            }

            tablero[x-1][y-1] = 1;

            printf("Los posibles movimientos para la pieza son: \n\n");

            for(int i = 0; i < 8; i++){

                for(int j = 0; j < 8; j++){

                    if(tablero [i][j] == 0){

                        printf("[ ] ");

                    } else if(tablero [i][j] == 1){

                        if(eleccion == 1){

                            printf("[A] ");

                        }else if(eleccion == 2){

                            printf("[T] ");

                        }

                    }else if(tablero [i][j] == 2){

                        printf("[X] ");

                    }

                }

                printf("\n");
                condi = 1;

            }

        }else{

            printf("\nPor favor digite un valor valido para x & y.\n");
            condi = 0;

        }

    }

}
