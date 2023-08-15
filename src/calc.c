#include "calc.h"

#include <math.h>
#include <stdlib.h>
#include <string.h>

double calc(char* content) {
  double res = 0.0;
  char input[256];
  char string[256];
  int i = 0;

  zeroAdd(content, string);
  convert(string, input);
  for (i = 0; input[i] != '\0'; i++) content[i] = input[i];
  content[i] = '\0';
  polish(content);
  res = arithmetic(content);
  return res;
}

int polish(char* content) {
  char steck[256];
  char res[256];
  int j = 0;
  int last = 0;
  steck[0] = 'N';

  for (int i = 0; content[i] != '\0'; i++) {
    if ((content[i] <= '9' && content[i] >= '0') || content[i] == '.') {
      res[j++] = content[i];
      if (add_space(content[i + 1])) res[j++] = ' ';
    }

    if (content[i] == '(' || operation(content[i]))
      add_steck(steck, content[i], &last);

    if (operator(content[i])) {
      while (last > 0 && mass(steck[last - 1]) >= mass(content[i])) {
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
  double arr[255] = {0};
  int last = 0;
  for (int i = 0; content[i] != '\0'; i++) {
    if (content[i] != ' ' && content[i] != '.') {
      if (content[i] <= '9' && content[i] >= '0')
        arr[last++] = makeNum(content, &i);

      else {
        if (operation(content[i])) {
          arr[last - 1] = sel(arr[last - 1], arr[last - 1], content[i]);
        }
        if (operator(content[i])) {
          arr[last - 2] = sel(arr[last - 2], arr[last - 1], content[i]);
          last--;
        }
      }
    }
    // printf("%f %f %f %f %f\n", arr[0], arr[1], arr[2], arr[3], arr[4]);
  }
  return arr[0];
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
  steck[(*last)] = content;
  (*last)++;
  steck[(*last)] = '\0';
  return 0;
}

int add_space(char content) {
  if (content == '.' || (content <= '9' && content >= '0'))
    return 0;
  else
    return 1;
}

double makeNum(char* content, int* i) {
  double res = 0.0;
  int j = 0;
  int flag = 0;

  for (; content[(*i)] != ' '; (*i)++) {
    if (content[(*i)] == '.') {
      flag = j;
      (*i)++;
    }
    res += (double)(content[(*i)] - '0') / ((int)pow(10, j++));
  }

  res *= pow(10, (j - flag - 1));
  return res;
}

double sel(double x, double y, char operation) {
  double res = 0;
  switch (operation) {
    case '+':
      res = x + y;
      break;
    case '-':
      res = x - y;
      break;
    case '/':
      res = x / y;
      break;
    case '*':
      res = x * y;
      break;
    case '^':
      res = pow(x, y);
      break;
    case 'm':
      res = fmod(x, y);
      break;
    case 'c':
      res = cos(y);
      break;
    case 's':
      res = sin(y);
      break;
    case 't':
      res = tan(y);
      break;
    case 'C':
      res = acos(y);
      break;
    case 'S':
      res = asin(y);
      break;
    case 'T':
      res = atan(y);
      break;
    case 'q':
      res = sqrt(y);
      break;
    case 'l':
      res = log(y);
      break;
    case 'L':
      res = log10(y);
      break;
    default:
      break;
  }
  return res;
}

int zeroAdd(char* content, char* string) {
  int j = 0;
  int lon = strlen(content);
  for (int i = 0; i < lon; i++) {
    if (content[i] == '-' || content[i] == '+') {
      if (i > 0 && (content[i - 1] >= '9' || content[i - 1] <= '0') &&
          content[i - 1] != ')') {
        string[j++] = '0';
        string[j] = content[i];
        lon++;
      }
      if (i == 0) {
        string[j++] = '0';
        string[j] = content[i];
        lon++;
      }
    }
    string[j++] = content[i];
  }
  string[j] = '\0';
  return 0;
}