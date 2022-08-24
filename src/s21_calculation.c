#include "s21_calculation.h"

int numLength (double num) {
    char str[500];
    sprintf(str, "%g", num);
    return strlen(str);
}

lexeme readLexeme(char *lexem, int *iter) {
    lexeme result = {0};
    int i = *iter;
    if (lexem[i] == 'x') {
        result.type = X_LEXEME;
        result.priority = 0;
        result.value = 0;
        i++;
    } else if (lexem[i] == '+') {
        result.type = PLUS_LEXEME;
        result.priority = 1;
        result.value = 0;
        i++;
    } else if (lexem[i] == '-') {
        result.type = MINUS_LEXEME;
        result.priority = 1;
        result.value = 0;
        i++;
    } else if (lexem[i] == '/') {
        result.type = DIVIDE_LEXEME;
        result.priority = 2;
        result.value = 0;
        i++;
    } else if (lexem[i] == '*') {
        result.type = MULTIPLY_LEXEME;
        result.priority = 2;
        result.value = 0;
        i++;
    } else if (lexem[i] == '^') {
        result.type = POWER_LEXEME;
        result.priority = 3;
        result.value = 0;
        i++;
    } else if (lexem[i] == 'm' && lexem[i + 1] == 'o' && lexem[i + 2] == 'd') {
        result.type = MODULATE_LEXEME;
        result.priority = 2;
        result.value = 0;
        i += 3;
    } else if (lexem[i] == 'c' && lexem[i + 1] == 'o' && lexem[i + 2] == 's') {
        result.type = COS_LEXEME;
        result.priority = 5;
        result.value = 0;
        i += 3;
    } else if (lexem[i] == 's' && lexem[i + 1] == 'i' && lexem[i + 2] == 'n') {
        result.type = SIN_LEXEME;
        result.priority = 5;
        result.value = 0;
        i += 3;
    } else if (lexem[i] == 't' && lexem[i + 1] == 'a' && lexem[i + 2] == 'n') {
        result.type = TAN_LEXEME;
        result.priority = 5;
        result.value = 0;
        i += 3;
    } else if (lexem[i] == 'a' && lexem[i + 1] == 'c' && lexem[i + 2] == 'o' && lexem[i + 3] == 's') {
        result.type = ACOS_LEXEME;
        result.priority = 5;
        result.value = 0;
        i += 4;
    } else if (lexem[i] == 'a' && lexem[i + 1] == 's' && lexem[i + 2] == 'i' && lexem[i + 3] == 'n') {
        result.type = ASIN_LEXEME;
        result.priority = 5;
        result.value = 0;
        i += 4;
    } else if (lexem[i] == 'a' && lexem[i + 1] == 't' && lexem[i + 2] == 'a' && lexem[i + 3] == 'n') {
        result.type = ATAN_LEXEME;
        result.priority = 5;
        result.value = 0;
        i += 4;
    } else if (lexem[i] == 's' && lexem[i + 1] == 'q' && lexem[i + 2] == 'r' && lexem[i + 3] == 't') {
        result.type = SQRT_LEXEME;
        result.priority = 5;
        result.value = 0;
        i += 4;
    } else if (lexem[i] == 'l' && lexem[i + 1] == 'n') {
        result.type = LN_LEXEME;
        result.priority = 5;
        result.value = 0;
        i += 2;
    } else if (lexem[i] == 'l' && lexem[i + 1] == 'o' && lexem[i + 2] == 'g') {
        result.type = LOG_LEXEME;
        result.priority = 5;
        result.value = 0;
        i += 3;
    } else if (lexem[i] == '(') {
        result.type = LEFT_LEXEME;
        result.priority = -1;
        result.value = 0;
        i++;
    } else if (lexem[i] == ')') {
        result.type = RIGHT_LEXEME;
        result.priority = -1;
        result.value = 0;
        i++;
    }
    *iter = i;
    return result;
}

lexeme calculationSimple(double num1, double num2, int type) {
    lexeme result;
    result.priority = 0;
    result.type = NUMBER_LEXEME;
    if (type == PLUS_LEXEME) {
        result.value = num1 + num2;
    } else if (type == MINUS_LEXEME) {
        result.value = num1 - num2;
    } else if (type == DIVIDE_LEXEME) {
        result.value = num1 / num2;
    } else if (type == MULTIPLY_LEXEME) {
        result.value = num1 * num2;
    } else if (type == POWER_LEXEME) {
        result.value = pow(num1, num2);
    } else if (type == MODULATE_LEXEME) {
        result.value = fmod(num1, num2);
    }
    return result;
}

lexeme calculationHarder(double num, int type) {
    lexeme result;
    result.priority = 0;
    result.type = NUMBER_LEXEME;
    if (type == COS_LEXEME) {
        result.value = cos(num);
    } else if (type == SIN_LEXEME) {
        result.value = sin(num);
    } else if (type == TAN_LEXEME) {
        result.value = tan(num);
    } else if (type == ACOS_LEXEME) {
        result.value = acos(num);
    } else if (type == ASIN_LEXEME) {
        result.value = asin(num);
    } else if (type == ATAN_LEXEME) {
        result.value = atan(num);
    } else if (type == SQRT_LEXEME) {
        result.value = sqrt(num);
    } else if (type == LN_LEXEME) {
        result.value = log(num);
    } else if (type == LOG_LEXEME) {
        result.value = log10(num);
    }
    return result;
}


double readStr(char* str, char* x) {

    char* tempStr;  // for strtod
    double x_digit = 0;
    if (x == NULL) {
        x_digit = 0;
    } else {
        x_digit = strtod(x, &tempStr);  //convert str to double
    }

    double num = 0;
    lexeme *stackNum = NULL;
    lexeme *stackSim = NULL;
    int i = 0;
    if (str[0] == '-' || str[0] == '+') {
        push(&stackNum, 0, NUMBER_LEXEME, 0);  //запуш нолек если унарный минус
    }
    int length = strlen(str);
    while (i < length) {
        if (*(str + i) >= '0' && (*(str + i) <= '9' || *(str + i) == '.')) {
            sscanf(str + i, "%lf", &num);
            int temp = numLength(num);
            i = i + temp;
            push(&stackNum, num, NUMBER_LEXEME, 0); //push num to stack
        } else {
            lexeme tmp = readLexeme(str, &i);
            mainLogic(&stackNum, &stackSim, tmp, x_digit);
        }
    }
    while (stackSim != NULL) {
        vichislenie(&stackNum, &stackSim);
    }
    lexeme result = top(&stackNum);
    printf("%lf", result.value);
    return result.value;
}

void mainLogic(lexeme **stackNum, lexeme **stackSim, lexeme this, double x) {
    lexeme topStack;
    if (*stackSim != NULL) {
        topStack = top(stackSim);
    } else topStack.priority = -1;

    if (topStack.type == LEFT_LEXEME && (this.type == MINUS_LEXEME || this.type == PLUS_LEXEME)) {
        push(stackNum, 0, 0, 1);
        this.priority = 6;
    } 

    if (this.type == X_LEXEME) {
        push(stackNum, x, NUMBER_LEXEME, 1);
    } else if (this.type == LEFT_LEXEME) {
        push(stackSim, 0, LEFT_LEXEME, -1); 
    } else if (this.priority > topStack.priority && this.type != RIGHT_LEXEME) {
        push(stackSim, 0, this.type, this.priority);
    } else if (this.priority <= topStack.priority && this.type != RIGHT_LEXEME) {
        vichislenie(stackNum, stackSim);
        push(stackSim, this.value, this.type, this.priority);
    } else if (this.type == RIGHT_LEXEME) {
        while (stackSim && topSimType(stackSim) !=  LEFT_LEXEME) {
            vichislenie(stackNum, stackSim);
        }
        pop(stackSim);
        if (stackSim && topSimType(stackSim) > 10) {
            vichislenie(stackNum, stackSim);
        }
    }
}

void vichislenie (lexeme **stackNum, lexeme **stackSim) {
    lexeme operator = pop(stackSim);
    lexeme value1;
    lexeme value2;
    if (operator.type > 8) {
        value2 = pop(stackNum);
    } else {
        value1 = pop(stackNum);
        value2 = pop(stackNum);
    }
    lexeme result;
    if (operator.type <= 8) {
        result = calculationSimple(value2.value, value1.value, operator.type);
    } else {
        result = calculationHarder(value2.value, operator.type);
    }
    push(stackNum, result.value, result.type, result.priority);
}

int main() {
    char *str = {"4^acos(x/4)/tan(2*x)"};
    char *x = {"1.2"};
    readStr(str, x);
}