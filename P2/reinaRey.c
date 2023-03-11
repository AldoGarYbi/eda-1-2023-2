#include <stdio.h>

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

    int tablero[8][8], i, j, x, y, ciclo = 1;
    int *apptab;

    while(ciclo == 1){

        apptab = &tablero[0][0];

        printf("\nElija la posicion de la pieza en el tablero entre 1 y 8: ");
        printf("\nPara x: ");
        scanf("%d", &x);
        printf("\nPara y: ");
        scanf("%d", &y);
        printf("\n");

        if(x >= 1 && y >= 1 && x <= 8 && y <= 8){

            ciclo = 0;

            int auxx = x, auxy = y;

            for(i = 0; i < 64; i++){

                *apptab = 0;
                apptab++;

            }

            apptab = &tablero[0][0];

            if(seleccion == 1){
                    
                    for(i = 0; i < 8; i++){

                        *(apptab+((y-1)*8)) = 2;
                        apptab++;

                    }

                    apptab = &tablero[0][0];

                    for(i = 0; i < 8; i++){
                        
                        *(apptab+(x-1)) = 2;
                        apptab += 8;

                    }

                    apptab = &tablero[0][0];

                    while((auxy-1) < 8 && (auxx-1) < 8){

                        *(apptab+(((y-1)*8)+x-1)) = 2;
                        apptab += 9; 
                        auxy++;
                        auxx++;

                    }

                    auxx = x; 
                    auxy = y;

                    apptab = &tablero[0][0];

                    while((auxy+8) > 8 && (auxx-1) < 8){

                        *(apptab+(((y-1)*8)+x-1)) = 2;
                        apptab -= 7;
                        auxy--;
                        auxx++;

                    }

                    auxx = x; 
                    auxy = y;

                    apptab = &tablero[0][0];

                    while((auxy-1) < 8 && (auxx+8) > 8){

                        *(apptab+(((y-1)*8)+x-1)) = 2;
                        apptab += 7;
                        auxy++;
                        auxx--;

                    }

                    auxx = x; 
                    auxy = y;

                    apptab = &tablero[0][0];

                    while((auxy+8) > 8 && (auxx+8) > 8){

                        *(apptab+(((y-1)*8)+x-1)) = 2;
                        apptab -= 9;
                        auxy--;
                        auxx--;

                    }

                    auxx = x; 
                    auxy = y;

                    apptab = &tablero[0][0];

            }

            if(seleccion == 2){

                if(y-1 < 7){

                    apptab += 8;
                    *(apptab+(((y-1)*8)+x-1)) = 2;
                
                }

                apptab = &tablero[0][0];

                if(y-1 > 0){

                    apptab -= 8;
                    *(apptab+(((y-1)*8)+x-1)) = 2;

                }

                apptab = &tablero[0][0];

                if(x-1 < 7){

                    apptab++;
                    *(apptab+(((y-1)*8)+x-1)) = 2;

                }

                apptab = &tablero[0][0];

                if(x-1 > 0){
                    
                    apptab--;
                    *(apptab+(((y-1)*8)+x-1)) = 2;

                }

                apptab = &tablero[0][0];

                if(y-1 < 7 && x-1 < 7){

                    apptab+=9;
                    *(apptab+(((y-1)*8)+x-1)) = 2;

                }

                apptab = &tablero[0][0];

                if(y-1 > 0 && x-1 > 0){

                    apptab-=9;
                    *(apptab+(((y-1)*8)+x-1)) = 2;

                }

                apptab = &tablero[0][0];

                if(y-1 < 7 && x-1 > 0){

                    apptab+=7;
                    *(apptab+(((y-1)*8)+x-1)) = 2;

                }

                apptab = &tablero[0][0];

                if(y-1 > 0 && x-1 < 7){

                    apptab-=7;
                    *(apptab+(((y-1)*8)+x-1)) = 2;

                }

                apptab = &tablero[0][0];

            }

            *(apptab+(((y-1)*8)+x-1)) = 1;

            for(i = 0; i < 64; i++){

                if(*(apptab+i) == 0){

                        printf("[ ]");

                }else if(*(apptab+i) == 1){

                        if(seleccion == 1){

                            printf("[Q]");

                        }

                        if(seleccion == 2){

                            printf("[R]");

                        }

                }else if(*(apptab+i) == 2){

                        printf("[X]");

                }



                if((i+1)%8 == 0){

                        printf("\n");

                }

            }
        }else{
            
            printf("\nHa dado valores invalidos, por favor de valores entre 1 y 8.\n");
            ciclo = 1;

        }
    }    

}