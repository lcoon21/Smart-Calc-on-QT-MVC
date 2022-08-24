#include "s21_stack.h"

void push(lexeme **head, double value, int type, int priority) {
    lexeme *tmp = (lexeme *)malloc(sizeof(lexeme));
    tmp->value = value;
    tmp->type = type;
    tmp->priority = priority;
    tmp->next = (*head);
    (*head) = tmp;
}

lexeme pop(lexeme **head) {
    lexeme *prev = NULL;
    lexeme tmp = {0};
    prev = (*head);
    tmp.value = prev->value;
    tmp.type = prev->type;
    tmp.priority = prev->priority;
    (*head) = (*head)->next;
    free(prev);
    return tmp;
}

lexeme top(lexeme **head) { ///////// хз чо здесь
    // if (*head != NULL) {
        lexeme *tmp = (*head);
        // if (choose == 'n'){
            // return (tmp->value);
        // } else if (choose == 's') {
            return *tmp;
        // }
    // }
}

int topSimType(lexeme **head) {
    return (*head)->type;
}

void deleteList(lexeme **head) {
    lexeme *prev = NULL;
    while ((*head)->next) {
        prev = (*head);
        (*head) = (*head)->next;
        free(prev);
    }
    free(*head);
}

// void printLinkedList(const lexeme *head) {
//     if (head == NULL) {
//         printf("NULL2\n");
//         return;
//     }
//     int count = 0;
//     while (head) {
//         printf("%d:", count);
//         printf("VALUE: %lf ", head->value);
//         printf("TYPE: %d ", head->type);
//         printf("PRIORITY: %d \n", head->priority);
//         head = head->next;
//         count++;
//     }
//     printf("\n");
// }