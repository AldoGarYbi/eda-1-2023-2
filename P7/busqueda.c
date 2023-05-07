// Codigo para implementar operaciones en una lista ligada circular

#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* addToEmpty(struct Node* last, int data) {
  if (last != NULL) return last;

  // asigna memoria al nuevo nodo
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  // se asigna dato al nuevo nodo
  newNode->data = data;

  // se asigna como last al nuevo nodo
  last = newNode;

  // se crea enlace a si mismo
  last->next = last;

  return last;
}

// agregar nodo por el frente
struct Node* addFront(struct Node* last, int data) {
  // se revisa si la lista está vacía
  if (last == NULL) return addToEmpty(last, data);

  // se asigna memoria al nuevo nodo
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  // se agrega dato al nuevo nodo
  newNode->data = data;

  // se guarda la direccion del primer nodo actual en el nuevo nodo
  newNode->next = last->next;

  // se hace al nuevo nodo como la cabeza
  last->next = newNode;

  return last;
}

// agregar nodo al final
struct Node* addEnd(struct Node* last, int data) {
  // se revisa si el nodo está vacío
  if (last == NULL) return addToEmpty(last, data);

  // se asigna memoria al nuevo nodo
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  // se agrega dato al nuevo nodo
  newNode->data = data;

  // se almacena la dirección del nodo cabeza al siguiente del nuevo nodo
  newNode->next = last->next;

  // se apunta el actual último nodo al nuevo nodo
  last->next = newNode;

  // se hace al nuevo nodo como el último nodo
  last = newNode;

  return last;
}

// insertar nodo después de un nodo específico
struct Node* addAfter(struct Node* last, int data, int item) {
  // se revisa si la lista está vacía
  if (last == NULL) return NULL;

  struct Node *newNode, *p;

  p = last->next;
  do {
  // si se encontró el elemento, se coloca el nuevo nodo después de él
    if (p->data == item) {
      // se asigna memoria al nuevo nodo
      newNode = (struct Node*)malloc(sizeof(struct Node));

      // se agrega dato al nodo
      newNode->data = data;

      // se hace como siguiente el nodo actual siguiente del nuevo nodo
      newNode->next = p->next;

      // se pone al nuevo nodo como el siguiente de p
      p->next = newNode;

      // si p es el último nodo, se hace al nuevo nodo como el último nodo
      if (p == last) last = newNode;
      return last;
    }

  p = p->next;
  } while (p != last->next);

  printf("\nEl nodo dado no esta presente en la lista");
  return last;
}

// borrar un nodo
void deleteNode(struct Node** last, int key) {
  // si la lista ligada está vacía
  if (*last == NULL) return;

  // si la lista contiene solo un nodo
  if ((*last)->data == key && (*last)->next == *last) {
    free(*last);
    *last = NULL;
    return;
  }

  struct Node *temp = *last, *d;

  // si se va a eliminar el último
  if ((*last)->data == key) {
    // encontrar el nodo antes del último nodo
    while (temp->next != *last) temp = temp->next;

    // apuntar un nodo temporal al siguiente del último es decir el primer nodo
    temp->next = (*last)->next;
    free(*last);
    *last = temp;
  }

  // recorrido al nodo que va a ser eliminado
  while (temp->next != *last && temp->next->data != key) {
    temp = temp->next;
  }

  // si el nodo a eliminar se encuentra
  if (temp->next->data == key) {
    d = temp->next;
    temp->next = d->next;
    free(d);
  }
}

void traverse(struct Node* last) {
  struct Node* p;

  if (last == NULL) {
    printf("La lista esta vacia");
    return;
  }

  p = last->next;

  do {

  if(p != last){
  
    printf("%d ---> ", p->data);

  }else if(p == last){

    printf("%d ", p->data);

  }

  p = p->next;

  } while (p != last->next);
}

void search(struct Node* last, int key){

  struct Node* s;
  int cont = 0;

  if (last == NULL) {
    printf("La lista esta vacia");
    return;
  }

  s = last->next;

  while (s->next != last->next && s->data != key)
  {
    s = s->next;
    cont++;
  }

if(s->data == key){

  printf("\nEl elemento %d se encuentra en la posicion %d de la lista. (La primer posicion es la 0)\n", key ,cont);

}else{

  printf("\nEl elemento %d no se encuentra en la lista.\n", key);

}
  

}

int main() {

  struct Node* last = NULL;
  int buscar, ciclo = 1;

  last = addToEmpty(last, 6);
  last = addEnd(last, 8);
  last = addFront(last, 2);
  last = addAfter(last, 10, 2);
  last = addFront(last, 17);
  last = addEnd(last, 11);
  last = addAfter(last, 4, 17);
  last = addFront(last, 15);
  last = addAfter(last, 1, 10);

  while (ciclo == 1)
  {

  printf("\nPrograma para buscar un elemento en una lista.\n");
  printf("\nDigite el numero que quiere buscar en la lista: ");
  scanf("%d", &buscar);

  search(last, buscar);

  printf("\n");
  traverse(last);

  printf("\nSi desea volver a utilizar el programa digite 1, de lo contrario digite cualquier otro numero: ");
  scanf("%d", &ciclo);

  }

  return 0;
}