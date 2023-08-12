#include"calc.h"
#include <string.h>
#include <stdlib.h>

int calc(char* content){
    DblLinkedList* list =  createDblLinkedList();
    convert(content, list);

    return 0;
}

DblLinkedList* createDblLinkedList() {
    DblLinkedList *tmp = (DblLinkedList*) malloc(sizeof(DblLinkedList));
    tmp->size = 0;
    tmp->head = tmp->tail = NULL;
    return tmp;
}

Node* pushBack(DblLinkedList *list, char value) {
    Node *tmp = (Node*) malloc(sizeof(Node));
    tmp->value = value;
    tmp->mass = mass(value);
    tmp->next = NULL;
    tmp->prev = list->tail;
    list->size++;
    return tmp;
}   

Node* popBack(DblLinkedList *list) {
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
    return next;
}

int mass(char sign) {
  int res = 0;
  switch (sign) {
    case '(':
      res = 1;
      break;
    case '-':
    case '+':
      res = 2;
      break;
    case '*':
    case '/':
      res = 3;
      break;
    default:
      res = 4;
      break;
  }
  return res;
}

int operation(char content){
    return content == '*' || content == '/' ||content == '+'||content == '-' ? 1:0;
}
int convert(char* content, DblLinkedList* list){
    int j=0;
    Node* tmp;
        tmp = malloc(sizeof(DblLinkedList));
    for(int i=0; i< strlen(content); i++) {
        // Число - добавляем в строку вывода.
        if(content[i] <= '9' && content[i] >= '0') content[j++] = content[i];
        // Функция или открывающая скобка - помещаем в стек.
        if(content[i] == '(') pushBack(list, content[i]);
        // Оператор (O1):
        
        if(operation(content[i])){
            while (tmp->mass > mass(content[i])){
                content[j++] = tmp->value;
                popBack(list);
            }
            
           pushBack(list, content[i]);
           list->tail = tmp;
        }
    }

// tmp = tmp->next;

tmp = list->tail;
printf("[%c]\n", tmp->value);

while(list->size){
    // content[j++] = tmp->value;
    // popBack(list);
    list->size--;
}
content[j] = '\0';
return 0;
}