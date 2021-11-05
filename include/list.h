#ifndef LIST_H
#define LIST_H


// These are the types that lists hold.
typedef struct list_node {
    void *value;                 // Object the list node holds.
    struct list_node *front;      // Pointer to next node
    struct list_node *back;       // Pointer to previous node. 
} list_node;

// Front and back access. 
list_node *next(list_node *n);
list_node *prev(list_node *n);

// list type. 
// It's implemented as a sentinelized, 
// doubly-linked list. 
typedef struct list{
    int size;
    list_node *sentinel;
} list;

/* API */
/* Creation */
list *new_list();
list *copy_list(list *list);

/* Deletion */
void free_list(list *list);
void clear(list *list);

/* Insertion */
void insert_before(list_node *n, void *item);
void insert_after(list_node *n, void *item);
void push_front(list *l, void *item);
void push_back(list *l, void *item);

/* Removal */
void *pop_back(list *l);
void *pop_front(list *l);
void erase(list *l, list_node *n);

#endif