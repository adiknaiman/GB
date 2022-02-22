#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// HW_09_01 Описать очередь с приоритетным исключением
#define SIZE 10
typedef int boolean;

typedef struct {
    int dat;
    int pr;
} Node;

Node* arr[SIZE];
int tail;
int items;

void init() {
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = NULL;
    }
    tail = 0;
    items = 0;
}

void printQueue() {
    printf("[ ");
    for (int i = 0; i < SIZE; ++i) {
        if (arr[i] == NULL)
            printf("[*, *] ");
        else
            printf("[%d, %d] ", arr[i]->pr, arr[i]->dat);
    }
    printf(" ]\n");
}

boolean isFull()
{
    // Полон?
    return items == SIZE;
}

boolean isEmpty()
{
    // Пуст?
    return items == 0;
}



void queueAdd(int pr, int dat)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->pr = pr; node->dat = dat;
    if (!isFull()) {
        arr[tail++] = node;
        items++;
        printf("item added: [%d, %d]  \n", node->pr, node->dat);
    }
    else {
        printf("Queue is full \n");
    }
}

Node* queueExtract()
{
    if (!isEmpty()) {

        int maxPri = arr[0]->pr;
        int idxMaxPri = 0;

        //ищем приоритет
        for (int i = 1; i < items; ++i) {
            if (maxPri < arr[i]->pr) {
                maxPri = arr[i]->pr;
                idxMaxPri = i;
            }
        }
            //смещаем очередь
            Node* temp = arr[idxMaxPri];
            while (idxMaxPri < items) {
                arr[idxMaxPri] = arr[idxMaxPri + 1];
                idxMaxPri++;
            }
            items--;
            tail--;
            printf("item extracted: [%d, %d]  \n", temp->pr, temp->dat);
            return temp;
    }
    else {
        printf("Queue is empty");
        return NULL;
    }
}

// HW_09_02 Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.

#define T char
#define SIZE2 1000
#define true 1 == 1
#define false 1 != 1

typedef int boolean;

int cursor = -1;
T Stack[SIZE2];

boolean push(T data) {
    if (cursor < SIZE2){
        Stack[++cursor] = data;
        return true;
    } else{
        printf ("%s \n", "Stack overflow");
        return false;
    };
}

T pop(){
    if (cursor != -1){
        return  Stack[cursor--];
    } else {
        printf("%s \n", "Stack is empty");
        return -1;
    }
}

void decToBin(int a) {
    while (a >= 1) {
        push(a % 2);
        a /= 2;
    }
}

void dtbAdd(int number)
{
    printf("number %d in binary: ", number);
    decToBin(number);
    int count = cursor;
    for (int i = 0; i <= count; ++i){
        printf("%d", pop());
    }
    printf("\n");
}


int main()
{
    // HW_09_01 Описать очередь с приоритетным исключением
    srand(time(0));
    //Инициализация
    init();
    printf("------------------------------------------------------------ \n");
    printf("HomeWork #09_01: \n");
    //заполнение части элементов
    for (int i = 0; i < 5; i++) {

        // значения от 0 до 99 (включительно)
        // и приоритет от 0 до 11 (включительно)
        queueAdd(rand() % 10, rand() % 100);
    }

    //показ очереди
    printQueue();

    queueAdd(rand() % 10, rand() % 100);
    printQueue();
    //извлечение элемента
    queueExtract();
    printQueue();
    queueExtract();
    printQueue();
    queueExtract();
    printQueue();
    queueAdd(rand() % 10, rand() % 100);
    printQueue();
    queueExtract();
    printQueue();
    queueAdd(rand() % 10, rand() % 100);
    printQueue();
    queueExtract();
    printQueue();


    // HW_09_02 Реализовать перевод из десятичной в двоичную систему счисления с использованием стека.
    printf("------------------------------------------------------------ \n");
    printf("HomeWork #09_02: \n");
    dtbAdd(rand() % 10);
    dtbAdd(rand() % 10);
    dtbAdd(rand() % 25);
    dtbAdd(rand() % 100);

    return 0;
}