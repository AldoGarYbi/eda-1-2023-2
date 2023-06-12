#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
  struct Node* prev;
};

struct Node* addToEmpty(struct Node* last, int data) {
  if (last != NULL) return last;

  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  newNode->data = data;

  last = newNode;

  last->next = last;

  last->prev = last;

  return last;
}

struct Node* addFront(struct Node* last, int data) {

  if (last == NULL) return addToEmpty(last, data);

  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  newNode->data = data;

  newNode->next = last->next;

  newNode->prev = last;

  last->next->prev = newNode;

  last->next = newNode;

  return last;
}

struct Node* addEnd(struct Node* last, int data) {

  if (last == NULL) return addToEmpty(last, data);

  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  newNode->data = data;

  newNode->next = last->next;

  last->next->prev = newNode;

  newNode->prev = last;

  last->next = newNode;

  last = newNode;

  return last;
}

struct Node* addAfter(struct Node* last, int data, int key) {

  if (last == NULL) return NULL;

  struct Node *newNode, *p;

  p = last->next;
  do {

    if (p->data == key) {

      newNode = (struct Node*)malloc(sizeof(struct Node));

      newNode->data = data;

      p->next->prev = newNode;

      newNode->next = p->next;

      newNode->prev = p;

      p->next = newNode;

      if (p == last) last = newNode;
      return last;
    }

    p = p->next;

  } while (p != last->next);

  printf("\nEl nodo dado no esta presente en la lista");
  return last;
  
}

void deleteNode(struct Node** last, int key) {

  if (*last == NULL) return;

  if ((*last)->data == key && (*last)->next == *last) {
    free(*last);
    *last = NULL;
    return;
  }

  struct Node *temp = *last, *d;


  if ((*last)->data == key) {

    while (temp->next != *last) temp = temp->next;

    temp->next = (*last)->next;
    temp->next->prev = temp;

    free(*last);
    *last = temp;
  }


  while (temp->next != *last && temp->next->data != key) {
    temp = temp->next;
  }

  if (temp->next->data == key) {
    d = temp->next;
    d->next->prev = temp;
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

void inverse(struct Node* last){

  struct Node* p;

   if (last == NULL) {
    printf("La lista esta vacia");
    return;
  }

  p = last;

  do {

  if(p != last->next){
  
    printf("%d ---> ", p->data);

  }else if(p == last->next){

    printf("%d ", p->data);

  }

  p = p->prev;

  } while (p != last);

}


int main() {

  struct Node* list = NULL;
  int elec, valor, key = 0, ciclo = 1;

  while(ciclo == 1){

    printf("\n\nPrograma de lista doble ligada circular.\n");
    printf("\nSeleccione la operacion a realizar: \n");
    printf("\n1- Insertar por enfrente. ");
    printf("\n2- Insertar por atras. ");
    printf("\n3- Insertar despues de un nodo. ");
    printf("\n4- Insertar a una lista vacia. ");
    printf("\n5-Borrar un elemento. ");
    printf("\n6-Salir.\n");
    scanf("%d", &elec);

    switch (elec)
    {
    case 1:

      printf("\nDigite el valor a insertar: ");
      scanf("%d", &valor);

      list = addFront(list, valor);

      printf("\nLa lista actual es: ");
      printf("\n");
      traverse(list);

      printf("\nSi desea volver a utilizar el programa digite 1, de lo contrario digite cualquier otro numero: ");
      scanf("%d", &ciclo);

    break;

    case 2:

      printf("\nDigite el valor a insertar: ");
      scanf("%d", &valor);

      list = addEnd(list, valor);

      printf("\nLa lista actual es: ");
      printf("\n");
      traverse(list);

      printf("\nSi desea volver a utilizar el programa digite 1, de lo contrario digite cualquier otro numero: ");
      scanf("%d", &ciclo);

    break;

    case 3:

      printf("\nDigite el valor a insertar: ");
      scanf("%d", &valor);
      printf("\nDigite el valor del dato del Nodo del cual se insertara despues el nuevo Nodo: ");
      scanf("%d", &key);

      list = addAfter(list, valor, key);

      printf("\nLa lista actual es: ");
      printf("\n");
      traverse(list);

      printf("\nSi desea volver a utilizar el programa digite 1, de lo contrario digite cualquier otro numero: ");
      scanf("%d", &ciclo);

    break;

    case 4:

      printf("\nDigite el valor a insertar: ");
      scanf("%d", &valor);

      list = addToEmpty(list, valor);

      printf("\nLa lista actual es: ");
      printf("\n");
      traverse(list);

      printf("\nSi desea volver a utilizar el programa digite 1, de lo contrario digite cualquier otro numero: ");
      scanf("%d", &ciclo);

    break;

    case 5:

      printf("\nDigite el dato del Nodo que desea borrar: ");
      scanf("%d", &key);

      deleteNode(&list, key);

      printf("\nLa lista actual es: ");
      printf("\n");
      traverse(list);

      printf("\nSi desea volver a utilizar el programa digite 1, de lo contrario digite cualquier otro numero: ");
      scanf("%d", &ciclo);

    break;

    case 6:

      return 0;

    break;

    default:

      printf("\nNo ha digitado un valor valido, por favor digite un valor valido.\n");

    break;

    }

  }

  return 0;

}
