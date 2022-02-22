#include <stdio.h>
#include <stdlib.h>
#include "geek.h"
// 1. Написать программу, которая определяет, является ли введенная скобочная последовательность
// правильной. Примеры правильных скобочных выражений: (), ([])(), {}(), ([{}]),
// неправильных — )(, ())({), (, ])}), ([(]) для скобок [,(,{. Например: (2+(2*2))
// или [2/{5*(4+7)}]

#define T char
#define true 1 == 1
#define false 1 != 1
typedef int boolean;

typedef struct OneLinkNode {
    int dat;
    struct OneLinkNode *next;
} OneLinkNode;

typedef struct {
    OneLinkNode *head;
    int size;
} OneLinkList;

void initOneLinkList(OneLinkList *lst) {
    lst->head = NULL;
    lst->size = 0;
}

boolean pushOneLinkStack(OneLinkList *stack, T value) {
    OneLinkNode *tmp = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    if (tmp == NULL) {
        printf("Stack overflow \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
}
T popOneLinkStack(OneLinkList *stack) {
    if (stack->size == 0) {
        printf("Stack is empty \n");
        return -1;
    }
    OneLinkNode *tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;
}

void printOneLinkIntNode(OneLinkNode *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%d]", n->dat);
}

void printOneLinkIntList(OneLinkList *lst) {
    OneLinkNode *current = lst->head;
    if (current == NULL) {
        printOneLinkIntNode(current);
    } else {
        do {
            printOneLinkIntNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", lst->size);
}

int bracesCheck(char* expression) {
    const int TYPES = 3;
    char braces[][2] = {{'(', ')'},
                        {'{', '}'},
                        {'[', ']'}};

    OneLinkList *st = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(st);
    int countIndex = 0;
    while (*expression != '\0') {
        for (int i = 0; i < TYPES; ++i){
            if (*expression == braces[i][0])
                pushOneLinkStack(st, i);
        }
        for (int i = 0; i < TYPES; ++i){
            if (*expression == braces[i][1]) {
                if (st->size == 0)
                    return countIndex;
                if (i == st->head->dat)
                    popOneLinkStack(st);
                else
                    return countIndex;
            }
        }
        expression++;
        countIndex++;
    }
    if (st->size != 0)
        return 0;
    return -1;
}

// 2. Создать функцию, копирующую односвязный список (без удаления первого списка).

void copyList(OneLinkList* from, OneLinkList* to){
    int size = from->size;
    OneLinkNode *current = from->head;
    while (size != 0) {
        for (int i = 0; i <size - 1; ++i) {
            current = current->next;
        }
        pushOneLinkStack(to, current->dat);
        size--;
        current = from->head;
    }
}
// 3. Реализуйте алгоритм, который определяет, отсортирован ли связный список.
boolean isSorted(OneLinkList *list){
    OneLinkNode *current = list->head;
    while (current->next != NULL){
        if (current->dat > current->next->dat)
            return false;
        current = current->next;
    }
    return true;
}

int main()
{
    // 1.
    printf("(): %d \n", bracesCheck("()"));
    printf("([])(): %d \n", bracesCheck("([])()"));
    printf("{}(): %d \n", bracesCheck("{}()"));
    printf("([{}]): %d \n", bracesCheck("([{}])"));
    printf("(2+(2*2)): %d \n", bracesCheck("(2+(2*2))"));
    printf("[2/{5*(4+7)}]: %d \n", bracesCheck("[2/{5*(4+7)}]"));

    // 2. Создать функцию, копирующую односвязный список (без удаления первого списка).
    OneLinkList *firstList = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(firstList);
    OneLinkList *secondList = (OneLinkList*) malloc(sizeof(OneLinkList));
    initOneLinkList(secondList);
    for (int i = 9; i > 1; --i){
        pushOneLinkStack(firstList, i);
    }
    printOneLinkIntList(firstList);
    copyList(firstList,secondList);
    printOneLinkIntList(secondList);
    printf("List is sorted = %s \n", isSorted(firstList) ? "true" : "false");


    return 0;
}