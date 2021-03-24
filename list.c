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

List * createList() {
  List *ay;

  ay=(List*)malloc(sizeof(List));

     return ay;
}

void * firstList(List * list) {

  if(list->head->data==NULL){

    return NULL;

  }

  list->current=list->head;

    return (void*)list->current->data;

}

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

void * lastList(List * list) {

  if(list->tail==NULL){

    return NULL;

  }
  list->current=list->tail;

    return (void*)list->current->data;

}

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

void pushFront(List * list, const void * data) {
  Node *ay;
  ay=createNode(data);
  if(list->current!=list->head){
    list->current=list->head;
  }
  if(list==NULL){
    list->current=ay;
    list->tail=ay;
    list->head=ay;
    list->current->next=NULL;
    list->current->prev=NULL;
  }else{
    list->current->next=ay;
    list->current->next->data=data;
    list->current->next->prev=list->current;
    list->current->next->next=NULL;

  }
}

void pushBack(List * list, const void * data) {
    list->current = list->tail;
    pushCurrent(list,data);
}

void pushCurrent(List * list, const void * data) {
}

void * popFront(List * list) {
    list->current = list->head;
    return popCurrent(list);
}

void * popBack(List * list) {
    list->current = list->tail;
    return popCurrent(list);
}

void * popCurrent(List * list) {
    return NULL;
}

void cleanList(List * list) {
    while (list->head != NULL) {
        popFront(list);
    }
}