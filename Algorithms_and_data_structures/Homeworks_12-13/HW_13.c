#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define T char
#define true 1 == 1
#define false 1 != 1
typedef int boolean;
#define SIZE 14

typedef struct OneLinkNode {
    int dat;
    struct OneLinkNode* next;
} OneLinkNode;

typedef struct {
    OneLinkNode* head;
    int size;
} OneLinkList;

//1. Реализовать обход в глубину с использованием стека
void initOneLinkList(OneLinkList* lst) {
    lst->head = NULL;
    lst->size = 0;
}

boolean pushOneLinkStack(OneLinkList* stack, T value) {
    OneLinkNode* tmp = (OneLinkNode*)malloc(sizeof(OneLinkNode));
    if (tmp == NULL) {
        printf("Stack overflow \n");
        return false;
    }
    tmp->dat = value;
    tmp->next = stack->head;

    stack->head = tmp;
    stack->size++;
    return true;
};
T popOneLinkStack(OneLinkList* stack) {
    if (stack->size == 0) {
        printf("Stack is empty \n");
        return -1;
    }
    OneLinkNode* tmp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    free(tmp);
    stack->size--;
    return data;
}


int possibleNumber(){
    int i = rand() % 100;
    if (i < 75){
        return 0;
    } else {
        return 1;
    }
}


void fill2dIntArray(int** array, const int row, const int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            array[i][j] = possibleNumber();
        }
    }
}

void print2dIntArray(int** array, const int row, const int col) {
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            printf(" %d " , array[i][j]);
        }
        printf("\n");
    }
}

/*int matrix[SIZE][SIZE] = {
        {0, 1, 1, 0, 0, 0},
        {0, 0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0},
};*/

int visited[SIZE] = { 0 };

void depthTraversStack(OneLinkList* Stack, int** array, int st) {
    printf("%3d", st);
    pushOneLinkStack(Stack,st);
    visited[st] = 1;
        for (int j = 0; j < SIZE; j++)
        {
            if (array[st][j] == 1 && visited[j] != 1)
            {
                depthTraversStack(Stack, array,j);
            }
        }
    popOneLinkStack(Stack);
}
void resetArr() {
    for (int i = 0; i < SIZE; ++i) {
        visited[i] = 0;
    }
}

//2. Моделируем робот поисковой системы. Дан готовый простой граф с циклическими связями.
//   Нужно обойти этот граф двумя способами и подсчитать количество ссылок на каждый из узлов графа (полустепень захода).
//   обход графа рекурсивной функцией(с подсчётом только смежных со стартовой вершин)
//   обход графа по матрице смежности(с подсчётом всех вершин графа) В конце обхода вывести два получившихся списка всех узлов
//   в порядке уменьшения количества ссылок на них.

int** init2dIntArray(int** array, const int row, const int col) {
    array = (int**) calloc(sizeof(int*), row);
    for (int i = 0; i < row; ++i) {
        *(array + i) = (int*) calloc(sizeof(int), col);
    }
    return array;
}
void printIntArray(int* array, int size) {
    for (int i = 0; i < size; ++i) {
        printf("%3d", array[i]);
    }
    printf("\n");
}
void depthTravers(int** array, int st) {
    int r;
    printf("%3d", st);
    int adj = 0;
    visited[st] = 1;
    for (r = 0; r < SIZE; ++r) {
        if (array[st][r] == 1 && !visited[r]) {
            depthTravers(array, r);
        }
    }
}
int adjLinks[SIZE] = {0};
void adjCount (int** matrix, const int size){
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (matrix[j][i] == 1) {
                if (i != j) {
                    adjLinks[i]++;
                };
            }
        }
    }
}

int main() {
    srand(time(NULL));
    printf("\n---------------------------------------------------\n");
    //1. Реализовать обход в глубину с использованием стека
    printf("\n matrix: \n");
    int** matrix = init2dIntArray(matrix, SIZE, SIZE);
    fill2dIntArray(matrix, SIZE, SIZE);
    print2dIntArray(matrix,SIZE, SIZE);
    printf("\n");


    OneLinkList* newStack;
    newStack = (OneLinkList*)malloc(sizeof(OneLinkList));
    initOneLinkList(newStack);
    printf("depthTraversStack:\n");
    depthTraversStack(newStack, matrix,0);
    resetArr();
    printf("\n");
    initOneLinkList(newStack);
    depthTraversStack(newStack, matrix, 2);
    resetArr();
    printf("\n");
    initOneLinkList(newStack);
    depthTraversStack(newStack, matrix,1);
    resetArr();
    printf("\n");

    printf("depthTravers:\n");
    depthTravers(matrix,0);
    printf("\n");
    resetArr();
    depthTravers(matrix,2);
    printf("\n");
    resetArr();
    depthTravers(matrix,1);
    printf("\n");
    resetArr();

    printf("---------------------------------------------------\n\n");

    //2. Моделируем робот поисковой системы. Дан готовый простой граф с циклическими связями.
    //   Нужно обойти этот граф двумя способами и подсчитать количество ссылок на каждый из узлов графа (полустепень захода).
    //   обход графа рекурсивной функцией(с подсчётом только смежных со стартовой вершин)
    //   обход графа по матрице смежности(с подсчётом всех вершин графа) В конце обхода вывести два получившихся списка всех узлов
    //   в порядке уменьшения количества ссылок на них.


    printf("HW_13_02_1:\n");
    for( int i = 0; i < SIZE; i++){
        printf("%3c", i + 65);
    }
    printf("\n");
    adjCount(matrix, SIZE);
    printIntArray(adjLinks, SIZE);



    printf("\n---------------------------------------------------\n\n");

    return 0;
}
