#ifndef SRC_S21_SMARTCALC_H_
#define SRC_S21_SMARTCALC_H_
#include <stdio.h>

typedef struct _Node {
	char value;
   int mass;
	struct _Node *next;
	struct _Node *prev;
} Node;


typedef struct _DblLinkedList {
    size_t size;
    Node *head;
    Node *tail;
} DblLinkedList;


int calc(char* content);
int mass(char sign);
DblLinkedList* createDblLinkedList() ;
void deleteDblLinkedList(DblLinkedList **list);
void pushFront(DblLinkedList *list, void *data);
void* popFront(DblLinkedList *list);
void pushBack(DblLinkedList *list, char value);
char popBack(DblLinkedList *list);
char convert(char* content, int* i);
#endif