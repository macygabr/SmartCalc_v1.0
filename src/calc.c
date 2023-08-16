#include "calc.h"
#include <math.h>
#include <string.h>

double calc(char* content, double x) {
  double res = NAN;
  char input[256];
  char string[256];
  int error = 0;
  int i = 0;
  if(checker(content))return res;

  zeroAdd(content, string);
  conv(string, input);
  for (i = 0; input[i] != '\0'; i++) content[i] = input[i];
  content[i] = '\0';

  if(!polish(content)) res = arithmetic(content,x, &error);
  // printf("content = %s | %f\n", content, res);
  if(error) res = NAN;
  return res;
}

int polish(char* content) {
  int error =0;
  char steck[256];
  char res[256];
  int j = 0;
  int last = 0;
  int open =0;
  int oper =0;
  int close =0;
  int num =0;
  // steck[0] = 'N';

  for (int i = 0; content[i] != '\0'; i++) {
    if ((content[i] <= '9' && content[i] >= '0') || content[i] == '.') {
      res[j++] = content[i];
      if (add_space(content[i + 1])) res[j++] = ' ';
    }

    if (content[i] == '(' || operation(content[i])){
      add_steck(steck, content[i], &last);
      if(content[i] == '(') open++;
      if(operation(content[i])) if((content[i-1] <= '9' && content[i-1] >= '0')) error=1;
    }

    if (operat(content[i])) {
      if(i>0 && operat(content[i-1])) error =1;
      while (last > 0 && mass(steck[last - 1]) >= mass(content[i])) {
        last--;
        res[j++] = steck[last];
        res[j++] = ' ';
      }
      add_steck(steck, content[i], &last);
    }
    if (content[i] == ')') {
      while (steck[last - 1] != '(' && last >=0) {
        if(last == 0) error =1;
        last--;
        res[j++] = steck[last];
        res[j++] = ' ';
      }
      close++;
      steck[last--] = '\0';
    }
     if (content[i] == 'x') res[j++] = content[i];
  }

  while (last > 0) {
    last--;
    res[j++] = steck[last];
    res[j++] = ' ';
  }
  if(j>1)res[j - 1] = '\0';

  // if(oper != num) error =1;
//printf("%s\n", res);
  if(steck[last] == ')') error =1;
  if(open != close) error =1;
  int k = 0;
  for (k = 0; res[k] != '\0'; k++) content[k] = res[k];
  content[k] = '\0';

  // if(operat(content[k-1]) && operat(content[k-3])) error =1;
  // printf("str = [%s] [%c] = [%c]\n", content, content[k-1], content[k-3]);
  return error;
}

double arithmetic(char* content, double x, int* error) {
  double arr[255] = {0};
  int last = 0;
  int flag = 0;
  int num=0;
  int number=0;

  for (int i = 0; content[i] != '\0'; i++) {
    if (content[i] != ' ' && content[i] != '.') {
      if ((content[i] <= '9' && content[i] >= '0') || content[i] == 'x') {
        arr[last++] = makeNum(content, &i, x, error);
        num++;
        }
      
      else {
        if (operation(content[i])) {
          if(last>0) arr[last - 1] = sel(arr[last - 1], arr[last - 1], content[i]);
          flag++;
        }
        if (operat(content[i]) && last>1) {
          if(last>1) arr[last - 2] = sel(arr[last - 2], arr[last - 1], content[i]);
          last--;
          flag++;
        }
      }
    }
  }
  return arr[0];
}
// _______________________________________support_______________________________________
int conv(char* content, char* str) {
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

int operat(char content) {
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

double makeNum(char* content, int* i, double x, int* error) {
  double res = 0.0;
  int j = 0;
  int flag = 0;
  int dot =0;
    // printf("{%s}\n",content);
  if (content[(*i)] == 'x') res = x;
  
  else{
  for (; content[(*i)] != ' ' && content[(*i)] != '\0'; (*i)++) {
    if (content[(*i)] == '.') {
      flag = j;
      dot++;
    } else {
      j++;
      res += (double)(content[(*i)] - '0') / ((int)pow(10, j));
    }
    // printf("[%.6f = %c = %d = %d]\n",res, content[(*i)], (j), flag);
  }
  if(!flag) flag = j;
  res *= pow(10, (flag));
  } 
  if(dot > 1) (*error) = 1;
  // printf("res = %f\n", res);
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

int checker(char* content){
  int res =0;
  int i=0;
  int open =0;
  int close =0;

  for (i =0; content[i] != '\0'; i++){
     if (content[i] == '(' ) open++;
     if (content[i] == ')' ) close++;
     if(content[i] == 'm' && (i == 0 || (content[i-1] >= '9' && content[i-1] <= '0'))) res =1;
     if(content[i] == 'x' && i>0 && (content[i-1] == ')' || (content[i-1] <= '9' && content[i-1] >= '0'))) res =1;
  }
    if(open != close) res =1; 
    if (operat(content[i-1])) res =1; 
  return res;
}