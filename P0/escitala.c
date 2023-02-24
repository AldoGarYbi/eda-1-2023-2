#include <stdio.h>

void crearMensaje();
void descifrarMensaje();

int main (){

    short opcion = 0;

    while(1){

        printf("\n \t *** ESCITALA ESPARTANA ***\n");
        printf("¿Que desea reaizar?\n");
        printf("1 Crear Mensaje Cifrado. \n");
        printf("2 Descifrar mensaje. \n");
        printf("3 Salir. \n");
        scanf(" %d", &opcion);

        switch (opcion){

                case 1: crearMensaje();
                break;

                case 2: descifrarMensaje();
                break;

                case 3: return 0;
                break;

                default: printf("Opcion invalida.\n");
                break;

        }


    }



}

void crearMensaje(){

    int ren, col, i, j, k = 0;

    printf("Ingresar el tamanio de la escitala: \n");
    printf("Renglones: ");
    scanf(" %i", &ren);
    printf("Columnas: ");
    scanf(" %i", &col);

    char escitala [ren][col];
    char texto [ren*col];

    printf("Escribir el texto a cifrar: \n");
    scanf("%s", texto);

    for (i = 0; i < ren; i++)

}

void descifrarMensaje(){

    int ren, col, i, j, k = 0;

    printf("Ingrresar el tamanio de la escitala: \n");
    printf("\nRenglones");
    scanf(" %i", &ren);
    printf("\nColumnas:");
    scanf("%i", &col);

    char escitala [ren][col];
    char texto [ren*col];

    printf("Escriba el texto a descifrar: \n");
    scanf("%s", texto);

    for(i = 0; i < col; i++){

        for(j=0; i<ren; i++){

            escitala[j][i] = texto[k++];

        }

    }

    printf("El texto descifrado es:\n");

    for(i=0; i = ren);

}