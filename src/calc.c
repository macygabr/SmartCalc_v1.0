#include"calc.h"
#include <string.h>
#include <stdlib.h>

int calc(char* content){
    char elem = '\0';
    int index_num=0;
    int error =0;
    DblLinkedList* list =  createDblLinkedList();
    Node* tmp= malloc(sizeof(DblLinkedList));
    
// Пока в исходной строке есть необработанные лексемы, считываем очередную:
 for(int i=0; i<256 && content[i] != '\0'; i++){}
    pushBack(list, 'N');
    printf("[%c]\n", tmp->value);
    free(tmp);
    return 0;
}

// int mass(char sign){
//     int res =1;
//     if(sign == '*' || sign == '/') res =2;
//     return res;
// }


DblLinkedList* createDblLinkedList() {
    DblLinkedList *tmp = (DblLinkedList*) malloc(sizeof(DblLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    return tmp;
}

// void deleteDblLinkedList(DblLinkedList **list) {
//     Node *tmp = (*list)->head;
//     Node *next = NULL;
//     while (tmp) {
//         next = tmp->next;
//         free(tmp);
//         tmp = next;
//     }
//     free(*list);
//     (*list) = NULL;
// }

// void pushFront(DblLinkedList *list, void *data) {
//     Node *tmp = (Node*) malloc(sizeof(Node));
//     if (tmp == NULL) {
//         exit(1);
//     }
//     tmp->value = data;
//     tmp->next = list->head;
//     tmp->prev = NULL;
//     if (list->head) {
//         list->head->prev = tmp;
//     }
//     list->head = tmp;
 
//     if (list->tail == NULL) {
//         list->tail = tmp;
//     }
//     list->size++;
// }

// void* popFront(DblLinkedList *list) {
//     Node *prev;
//     void *tmp;
 
//     prev = list->head;
//     list->head = list->head->next;
//     if (list->head) {
//         list->head->prev = NULL;
//     }
//     if (prev == list->tail) {
//         list->tail = NULL;
//     }
//     tmp = prev->value;
//     free(prev);
 
//     list->size--;
//     return tmp;
// }

void pushBack(DblLinkedList *list, char value) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = value;
    tmp->next = NULL;
    tmp->prev = list->tail;
    if (list->tail) {
        list->tail->next = tmp;
    }
    list->tail = tmp;
 
    if (list->head == NULL) {
        list->head = tmp;
    }
    list->size++;
}   

char popBack(DblLinkedList *list) {
    Node *next;
    char tmp;
 
    next = list->tail;
    list->tail = list->tail->prev;
    if (list->tail) {
        list->tail->next = NULL;
    }
    if (next == list->head) {
        list->head = NULL;
    }
    tmp = next->value;
    free(next);
    list->size--;
    return tmp;
}

char convert(char* content, int* i){
char res = content[(*i)];
if(content[(*i)] == 'o' || content[(*i)++] == 'o' && content[(*i)++] == 's') res = 'c';
return res;
}