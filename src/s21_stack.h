#ifndef SRC_S21_STACK_H_
#define SRC_S21_STACK_H_

#include "stdio.h"
#include "string.h"
#include <stdlib.h>
#include <math.h>

typedef enum {
    NUMBER_LEXEME = 1,
    X_LEXEME = 2,
    PLUS_LEXEME = 3,
    MINUS_LEXEME = 4,
    DIVIDE_LEXEME = 5,
    MULTIPLY_LEXEME = 6,
    POWER_LEXEME = 7,
    MODULATE_LEXEME = 8,
    COS_LEXEME = 11,
    SIN_LEXEME = 12,
    TAN_LEXEME = 13,
    ACOS_LEXEME = 14,
    ASIN_LEXEME = 15,
    ATAN_LEXEME = 16,
    SQRT_LEXEME = 17,
    LN_LEXEME = 18,
    LOG_LEXEME = 19,
    LEFT_LEXEME = 20,
    RIGHT_LEXEME = 21
} lexeme_type;

typedef struct Node {
    double value;
    int priority;
    struct Node *next;
    lexeme_type type;
} lexeme;

void push(lexeme **head, double value, int type, int priority);
lexeme pop(lexeme **head);
lexeme top(lexeme **head);
int topSimType(lexeme **head);
void deleteList(lexeme **head);
void printLinkedList(const lexeme *head);

#endif  // SRC_S21_STACK_H_