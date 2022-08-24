#ifndef SRC_S21_CALCULATION_H_
#define SRC_S21_CALCULATION_H_

#include "s21_stack.h"

int numLength (double num);
lexeme readLexeme(char *lexem, int *iter);

lexeme calculationSimple(double num1, double num2, int type);
lexeme calculationHarder(double num, int type);

double readStr(char* str, char* x);
// double readStr(char* str);
void mainLogic(lexeme **stackNum, lexeme **stackSim, lexeme this, double x);
// int mainLogic(lexeme **stackNum, lexeme **stackSim, lexeme this);
void vichislenie (lexeme **stackNum, lexeme **stackSim);

#ifdef DEBUG
void printformula(entity *input);
#endif

#endif  // SRC_S21_CALCULATION_H_
