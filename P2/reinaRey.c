#include <stdio.h>

void posicion();

int main (){

    while(1){

        int selec;

        printf("\n\nPOSIBLES MOVIMIENTOS DE REINA Y REY\n\n");
        printf("1- Reina");
        printf("\n2- Rey");
        printf("\n3- Salir\n");
        scanf("%i",&selec);

        switch(selec){

            case 1:

                posicion();

            break;

            case 2:

                posicion();

            break;

            case 3:

                return 0;

            break;



        }

    }

    return 0;

}

void posicion(){

    int tablero[8][8], i, j;
    int *apptab;

    apptab = &tablero[0][0];

    for(i = 0; i < 64; i++){

        *apptab = 0;
        *apptab++;

    }

    for(i = 0; i < 64; i++){

        printf("%i ", *(apptab+i));

        if(i%8 == 0 && i != 0){

            printf("\n");

        }

    }

}