#include "calc.h"

#include <stdlib.h>
#include <string.h>

double calc(char* content) {
  double res = 0.0;
  char input[256];
  convert(content, input);
  for (int i = 0; i < (int)strlen(content); i++) content[i] = input[i];
  polish(content);
  res = arithmetic(content);
  return res;
}
int polish(char* content) {
  char steck[256];
  char res[256];
  int j = 0;
  int last = 0;

  for (int i = 0; content[i] != '\0'; i++) {
    if ((content[i] <= '9' && content[i] >= '0') || content[i] == '.') {
      res[j++] = content[i];
      if (add_space(content[i + 1])) res[j++] = ' ';
    }
    if (content[i] == '(' || operation(content[i]))
      add_steck(steck, content[i], &last);
    if (operator(content[i])) {
      while (mass(steck[last - 1]) >= mass(content[i])) {
        last--;
        res[j++] = steck[last];
        res[j++] = ' ';
      }
      add_steck(steck, content[i], &last);
    }
    if (content[i] == ')') {
      while (steck[last - 1] != '(') {
        last--;
        res[j++] = steck[last];
        res[j++] = ' ';
      }
      steck[last--] = '\0';
    }
  }

  while (last > 0) {
    last--;
    res[j++] = steck[last];
    res[j++] = ' ';
  }
  res[j - 1] = '\0';

  int k = 0;
  for (k = 0; res[k] != '\0'; k++) content[k] = res[k];
  content[k] = '\0';
  return 0;
}

double arithmetic(char* content) {
  for(int i=0; content[i] != ' ' ;i++){
    
  }
  double res = 0.0;
  return res;
}
// _______________________________________support_______________________________________
int convert(char* content, char* str) {
  int j = 0;
  for (int i = 0; i < (int)strlen(content); i++, j++) {
    if (content[i] == 'c' && content[i + 1] == 'o' && content[i + 2] == 's') {
      str[j] = 'c';
      i += 2;
    } else if (content[i] == 's' && content[i + 1] == 'i' &&
               content[i + 2] == 'n') {
      str[j] = 's';
      i += 2;
    } else if (content[i] == 't' && content[i + 1] == 'a' &&
               content[i + 2] == 'n') {
      str[j] = 't';
      i += 2;
    } else if (content[i] == 'l' && content[i + 1] == 'o' &&
               content[i + 2] == 'g') {
      str[j] = 'L';
      i += 2;
    } else if (content[i] == 'm' && content[i + 1] == 'o' &&
               content[i + 2] == 'd') {
      str[j] = 'm';
      i += 2;
    } else if (content[i] == 'a' && content[i + 1] == 'c' &&
               content[i + 2] == 'o' && content[i + 3] == 's') {
      str[j] = 'C';
      i += 3;
    } else if (content[i] == 'a' && content[i + 1] == 's' &&
               content[i + 2] == 'i' && content[i + 3] == 'n') {
      str[j] = 'S';
      i += 3;
    } else if (content[i] == 'a' && content[i + 1] == 't' &&
               content[i + 2] == 'a' && content[i + 3] == 'n') {
      str[j] = 'T';
      i += 3;
    } else if (content[i] == 's' && content[i + 1] == 'q' &&
               content[i + 2] == 'r' && content[i + 3] == 't') {
      str[j] = 'q';
      i += 3;
    } else if (content[i] == 'l' && content[i + 1] == 'n') {
      str[j] = 'l';
      i++;
    } else
      str[j] = content[i];
  }
  str[j] = '\0';
  return 0;
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
    case 'm':
      res = 3;
      break;
    case 's':
    case 'c':
    case 't':
    case 'S':
    case 'C':
    case 'T':
    case 'q':
    case 'l':
    case 'L':
      res = 3;
      break;
    case '^':
      res = 4;
      break;
    default:
      res = 0;
      break;
  }
  return res;
}

int operator(char content) {
  return content == '^' || content == '*' || content == '/' || content == '+' ||
                 content == '-' || content == 'm'
             ? 1
             : 0;
}

int operation(char content) {
  return content == 's' || content == 'c' || content == 't' || content == 'S' ||
                 content == 'C' || content == 'T' || content == 'q' ||
                 content == 'l' || content == 'L'
             ? 1
             : 0;
}
int add_steck(char* steck, char content, int* last) {
  steck[(*last)++] = content;
  steck[(*last)] = '\0';
  // printf("steck = [%s]\n", steck);
  return 0;
}

int add_space(char content) {
  if (content == '.' || (content <= '9' && content >= '0'))
    return 0;
  else
    return 1;
}