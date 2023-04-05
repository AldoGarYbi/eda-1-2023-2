#include <stdio.h>
#include <string.h>

#define MAX 30

void addFront(char *, char , int*, int *);
void addRear(char *, char , int *, int *);
char delFront(char *, int *, int *);
char delRear(char*, int *, int *);
void display(char *);
int count(char *);

void addFront(char *arr, char objeto, int *pfront, int *prear){

    int i, k, c;

    if(*pfront == 0 && *prear == MAX-1){

        printf("\nDeque esta llena.\n");
        return;

    }

    if(*pfront == -1){

        *pfront = *prear = 0;
        arr[*pfront] = objeto;
        return;

    }

    if(*prear != MAX - 1){

        c = count(arr);
        k = *prear + 1;
        
        for(i = 1; i<= c; i++){

            arr[k] = arr[k-1];
            k--;

        }

        arr[k] = objeto;
        *pfront = k;
        (*prear)++;

    }else{

        (*pfront)--;
        arr[*pfront] = objeto;

    }

}

void addRear(char *arr, char objeto, int *pfront, int *prear){

    int i, k;

    if(*pfront == 0 && *prear == MAX - 1){

        printf("\nDeque esta llena\n");
        return;

    }

    if(*pfront == -1){

        *prear = *pfront = 0;
        arr[*prear] = objeto;
        return;

    }

    if(*prear == MAX - 1){

        k = *pfront - 1;

        for(i = *pfront - 1; i < *prear; i++){

            k = i;

            if(k == MAX - 1){

                arr[k] = '0';

            }else{

                arr[k] = arr[i+1];

            }

            (*prear)--;
            (*pfront)--;

        }

    }

    (*prear)++;
    arr[*prear] = objeto;

}

char delFront(char *arr, int *pfront, int *prear){

    char objeto;

    if(*pfront == -1){

        printf("\nDeque esta vacia.\n");
        return '0';

    }

    objeto = arr[*pfront];
    arr[*pfront] = '0';

    if(*pfront == *prear){

        *pfront = *prear = -1;

    }else{

        (*pfront)++;

    }

    return objeto;

}

char delRear(char *arr, int *pfront, int *prear){

    int objeto;

    if(*pfront == -1){

        printf("\nDeque esta vacia.\n");
        return '0';

    }

    objeto = arr[*prear];
    arr[*prear] = '0';
    (*prear)--;
    if(*prear == -1){

        *pfront = -1;

    }

    return objeto;

}

void display(char *arr){

    int i;

    printf("\n frente:  ");
    for(i = 0; i < MAX; i++){

        printf("  %c", arr[i]);

    }

    printf("  :parte trasera\n");

}

int count(char *arr){

    int c = 0, i;

    for(i = 0; i < MAX; i++){

        if(arr[i] != '0'){

            c++;

        }

    }

    return c;

}

int main(){

    char arr[MAX], arru[MAX];
    int front, rear, i, longitud;

    front = rear = -1;

    printf("\nPrograma para verificar si una palabra es palindromo.\n");
    printf("\nEscriba la palabara:  ");
    scanf("%s", arru);

    printf("La palabra es: ");

    longitud = strlen(arru);

    printf("%d", longitud);

    for(i=0; i<MAX; i++){

        arr[i] = '0';

    }

    for(i = 0; i<longitud; i++){

        addRear(arr, arru[i], &front, &rear);

    }

    display(arr);

}
