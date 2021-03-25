#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "list.h"

typedef struct Node Node;

struct Node {
    const void * data;
    Node * next;
    Node * prev;
};

struct List {
    Node * head;
    Node * tail;
    Node * current;
};

typedef List List;

Node * createNode(const void * data) {
    Node * new = (Node *)malloc(sizeof(Node));
    assert(new != NULL);
    new->data = data;
    new->prev = NULL;
    new->next = NULL;
    return new;
}
///En esta función se inicializa la lista y se retorna///
List * createList() {
  List *ay;

  ay=(List*)malloc(sizeof(List));

     return ay;
}

///En esta función se mueve current al primer elemento de la lista///
void * firstList(List * list) {

  if(list->head==NULL){

    return NULL;

  }

  list->current=list->head;

    return (void*)list->current->data;

}

///En esta función, current se mueve al valor que sigue después de el///
void * nextList(List * list) {
  if(list->current==NULL){

     return NULL;
  }
  if(list->current->next==NULL){

      return NULL;
  }
  list->current=list->current->next;

    return (void*)list->current->data;

}
///En esta función currrent se mueve hacia el último dato de la lista///
void * lastList(List * list) {

  if(list->tail==NULL){

    return NULL;

  }
  list->current=list->tail;

    return (void*)list->current->data;

}
///Current se mueve al nodo anterior a el///
void * prevList(List * list) {
  if(list->current==NULL){

    return NULL;

  }
  if(list->current->prev==NULL){

    return NULL;

  }
  list->current=list->current->prev;

    return (void*)list->current->data;

}
///Se ingresa un nuevo nodo en la cabecera de la lista///
void pushFront(List * list, const void * data) {
  Node *ay;

  ay=createNode(data);
///Se revisa si current esta en head///
  if(list->current!=list->head){

    list->current=list->head;

  }
///Se toman acciones en caso de que current no esté inicializado///
  if(list->current==NULL){

    list->current=ay;

    list->tail=ay;

    list->head=ay;

  }else{///Se procede a ingresar el nodo en la lista///

    list->current->prev=ay;

    list->current->prev->next=list->current;

    list->current=list->current->prev;

    list->head=list->current;

    list->head->prev=list->tail;

  }
}

void pushBack(List * list, const void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, const void * data) {
  Node *ay;

  ay=createNode(data);
///Se revisa si current esta en tail///
  if(list->current!=list->tail){

    list->current=list->tail;

  }
///Se toman acciones en caso de que current no esté inicializado///
  if(list->current==NULL){

    list->current=ay;

    list->tail=ay;

    list->head=ay;

  }else{///Se procede a ingresar el nodo en la lista///

    list->current->next=ay;

    list->current->next->prev=list->current;

    list->current=list->current->next;

    list->tail=list->current;

    list->head->next=list->tail;

  }
}
///Borra el dato de adelante
void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
  list->current->next->prev=list->current->prev;
  list->current->prev->next=list->current->next;
  free(list->current);
  firstList(list);
  return list;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}