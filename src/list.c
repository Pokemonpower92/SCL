#include "list.h"
#include <stdlib.h>
#include <stdio.h>

// Front and back access. 
 list_node *next(list_node *n) {
    return n->front;
}

 list_node *prev(list_node *n) {
    return n->back;
}

/* API */
/* Creation */
 list *new_list() {
     list  *l = malloc(sizeof(list));

    l->size = 0;
    l->sentinel = malloc(sizeof(list_node));
    l->sentinel->front = l->sentinel;
    l->sentinel->back = l->sentinel;

    return l;
}

 list *copy_list(list *l) {
     list *new_l = new_list();
     list_node *curr;

    for(curr = next(l->sentinel); curr != l->sentinel; curr = next(curr)) {
        push_front(new_l, curr->value);
    }

    return new_l;
}

/* Deletion */
void free_list(list *l) {
    clear(l);
    free(l->sentinel);
}

void clear(list *l) {
     list_node *curr;

    for(curr = next(l->sentinel); curr != l->sentinel; curr = next(curr)) {
        erase(l, curr);
    }
}

/* Insertion */
void insert_before(list_node *n, void *item) {
    list_node *new_node = malloc(sizeof(list_node));

    new_node->front = n;
    new_node->back = n->back;
    new_node->value = item;

    new_node->back->front = new_node;
    n->back = new_node; 
}

void insert_after(list_node *n, void *item) {
    list_node *new_node = malloc(sizeof(list_node));

    new_node->back = n;
    new_node->front = n->front;
    new_node->value = item;

    new_node->back->front = new_node;
    n->back = new_node;
}

void push_front(list *l, void *item) {
    insert_after(l->sentinel, item);
    l->size++;
}

void push_back(list *l, void *item) {
    insert_before(l->sentinel, item);
    l->size++;
}

/* Removal */
void *pop_back(list *l) {
    if(l->size == 0) return NULL;

    void *item = l->sentinel->back->value;
    erase(l, l->sentinel->back);

    return item;
}

void *pop_front(list *l) {
    if(l->size == 0) return NULL;

    void *item = l->sentinel->front->value;
    erase(l, l->sentinel->front);

    return item;
}

void erase(list *l, list_node *n) {

    n->back->front = n->front;
    n->front->back = n->back;
    l->size--;

    free(n);
}