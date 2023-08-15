#ifndef SRC_S21_SMARTCALC_H_
#define SRC_S21_SMARTCALC_H_
#include <stdio.h>

double calc(char* content);
double arithmetic(char* content);
int mass(char sign);
int polish(char* content);
int add_space(char content);
int convert(char* content, char* str);
int operator(char content);
int operation(char content);
int add_steck(char* steck, char content, int* last);
double makeNum(char* content, int* i);
double sel(double x, double y, char operation);
int zeroAdd(char* content, char* string);
#endif