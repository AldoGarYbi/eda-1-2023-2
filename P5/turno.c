#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Cola {

    int front, rear, size;
    unsigned capacidad;
    int *arr;

};

struct Cola* crearCola(unsigned capacidad){

    struct Cola* cola = (struct Cola*)malloc(sizeof(struct Cola));
    cola->capacidad = capacidad;
    cola->front = cola->size = 0;
    cola->rear = capacidad-1;
    cola->arr = (int*)malloc(cola->capacidad*sizeof(int));
    return cola;

}

int isFullC(struct Cola* cola){

    return (cola->size == cola->capacidad);

}

int isEmptyC(struct Cola* cola){

    return (cola->size == 0);

}

void enqueue(struct Cola* cola, int objeto){

    if(isFullC(cola)){

        return;

    }

    cola->rear = (cola->rear+1) % cola->capacidad;
    cola->arr[cola->rear] = objeto;
    cola->size = cola->size+1;

}

int dequeue(struct Cola* cola){

    if (isEmptyC(cola)){

        return INT_MIN;

    }

    int objeto = cola->arr[cola->front];
    cola->front = (cola->front+1) % cola->capacidad;
    cola->size = cola->size-1;

    return objeto;

}

int front(struct Cola* cola){

	if (isEmptyC(cola)){

        return INT_MIN;

    }
		
	return cola->arr[cola->front];
}

int rear(struct Cola* cola){

	if (isEmptyC(cola)){

        return INT_MIN;

    }
		
	return cola->arr[cola->rear];
}

struct Pila {

    int tope;
    unsigned capacidad;
    int *arr;

};

struct Pila* crearPila(unsigned capacidad){

    struct Pila* pila = (struct Pila*)malloc(sizeof(struct Pila));
    pila->capacidad = capacidad;
    pila->tope = -1;
    pila->arr = (int*)malloc(pila->capacidad*sizeof(int)); 

    return pila;

}

int isFullP(struct Pila* pila){

    return pila->tope == pila->capacidad-1;

}

int isEmptyP(struct Pila* pila){

    return pila->tope == -1;

}

void push(struct Pila* pila, int objeto){

    if(isFullP(pila)){

        return;

    }   

    pila->arr[++pila->tope] = objeto;

}

int pop(struct Pila* pila){

    if(isEmptyP(pila)){

        return INT_MIN;

    }

    return pila->arr[pila->tope--];

}

int peek(struct Pila* pila){

    if(isEmptyP(pila)){

        return INT_MIN;

    }

    return pila->arr[pila->tope];

}

int main(){

    int opc, condi=1;

    struct Pila* pila = crearPila(10);
    struct Cola* cola = crearCola(10);

    for(int i = 10; i > 0; i--){

        push(pila, i);

    }

    while(condi == 1){

        printf("\n\nBienvenido al siste de turnos.\n\n");
        printf("Seleccione una opcion: \n\n");
        printf("1- Formarse.\n");
        printf("2- Salir.\n");
        scanf("%d", &opc);

        if(opc == 1){

            if(isEmptyP(pila)){

                printf("\nYa no quedan mas turnos.");
                printf("\nUltimo elemento en el tope de la pila: Ninguno");
                printf("\nUltimo elemento formado en la cola: %d\n", rear(cola));

                condi = 2;


            }else{

                enqueue(cola, peek(pila));
                printf("\nEl elemento se encuentra formado en la cola con turno %d", rear(cola));
                pop(pila);

            }

        }else if(opc == 2){

            if(isEmptyP(pila)){

                printf("\nUltimo elemento en el tope de la pila: Ninguno");

            }else{

                printf("\nUltimo elemento en el tope de la pila: %d", peek(pila));

            }

            printf("\nUltimo elemento formado en la cola: %d\n", rear(cola));

            condi = 2;

        }else{

            printf("\nPor favor elija una opcion valida.\n");

        }

    }
    
    return 0;

}