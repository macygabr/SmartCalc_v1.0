#ifndef SRC_S21_SMARTCALC_H_
#define SRC_S21_SMARTCALC_H_
#include <stdio.h>

double calc(char* content, double x);
double arithmetic(char* content, double x, int* error);
int mass(char sign);
int polish(char* content);
int checker(char* content);
int add_space(char content);
int conv(char* content, char* str);
int operat(char content);
int operation(char content);
int add_steck(char* steck, char content, int* last);
double makeNum(char* content, int* i, double x, int* error);
double sel(double x, double y, char operation);
int zeroAdd(char* content, char* string);
#endif