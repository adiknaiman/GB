#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// HW_07_01 Описать в коде улучшенный алгоритм быстрой сортировки

void fillRandom(int *arr, int len, int border) {
    for (int i = 0; i < len; ++i) {
        *(arr + i) = rand() % border;
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void printIntArray(int *array, int size) {
    for (int j = 0; j < size; ++j) {
        printf("%3d", array[j]);
        if (j > 0 && (j + 1) % (int) sqrt(size) == 0) {
            printf("\n");
        } else if (j != size - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

//Сортировка методом вставки
void sortInserts(int *arr, int len) {
    int temp, pos;
    for (int i = 1; i < len; i++) {
        temp = arr[i];
        pos = i - 1;
        while (pos >= 0 && arr[pos] > temp) {
            arr[pos + 1] = arr[pos];
            pos--;
        }
        arr[pos + 1] = temp;
    }
}

int findMedian(int* arr, int a, int b){
    int c = arr[(a + b) / 2];
    return (a > b) ? ((c < b) ? b : ((c < a) ? c : a)) : ((a > c) ? a : (b > c) ? c : b);
}

void improvedQS(int *s_arr, int first, int last) {
    if (last - first > 10) // Минимальное количество элементов для быстрой сортировки
        // если количество элементов больше -> else -> сортировать методом вставки
    {
        int median = findMedian(s_arr, first, last);
        int left = first;
        int right = last;
        int middle = s_arr[(first + last) / 2];
        do {
//        Детальная проверка работы алгоритма TODO перепроверить
//        printf("Left IQS value: %d\n", s_arr[left]);
//        printf("Middle: %d\n", middle);
//        printf("Right IQS value: %d\n", s_arr[right]);
//        printf("Median: %d\n", median);
//        printf("\n");
//        printf("Left IQS position: %d\n", left);
//        printf("Right IQS position: %d\n", right);
//        printf("\n");

            while (s_arr[left] < middle) left++;
            while (s_arr[right] > middle) right--;
            if (left <= right) {
                swap(&s_arr[left], &s_arr[right]);
                left++;
                right--;
            }
        } while (left <= right);
        improvedQS(s_arr, left, last);
        improvedQS(s_arr, first, right);
//        Детальная проверка работы алгоритма TODO перепроверить
//        printIntArray(s_arr, last + 1);
    }
    else {
        sortInserts(s_arr, last + 1);
    }
}


// HW_07_02 Сортировать в массиве целых положительных чисел только чётные числа,
// нечётные оставив на своих местах при помощи алгоритма блочной сортировки,
// то есть массив вида [0 2 8 3 4 6 5 9 8 2 7 3] превратить в [0 2 2 3 4 6 5 9 8 8 7 3]

void bucketSort(int* arr, const int len) {
    const int b = 10;
    int buckets[b][len +1];
    for (int i = 0; i < b; ++i) {
        buckets[i][len] = 0;
    }
    for (int digit = 1; digit < 1000000000; digit *= 10) {
        for (int i = 0; i < len; ++i) {
            if (arr[i] % 2 == 0) {
                int d = (arr[i] / digit) % b;
                buckets[d][buckets[d][len]] = arr[i];
                buckets[d][len]++;
            }
        }
        int idx = 0;
        for (int i = 0; i < b; ++i) {
            for (int j = 0; j < buckets[i][len]; ++j) {

                if (buckets[i][j] % 2 == 0) {
                    while (arr[idx] % 2 != 0) {
                        idx++;
                    }
                    arr[idx++] = buckets[i][j];
                }
            }
            buckets[i][len] = 0;
        }
    }
}


int main() {
    printf("Hello, World!\n");

    const int SIZE = 25;
    int arr[SIZE];
    int arr2[SIZE];
    fillRandom(arr, SIZE, 100);
    printf("Unsorted array:\n");
    printIntArray(arr, SIZE);

//    qs(arr, 0, SIZE-1);
//    printf ("Sorted array:\n");
//    printIntArray(arr, SIZE);

    printf("Improved quicksort:\n");
    improvedQS(arr, 0, SIZE - 1);
    printIntArray(arr, SIZE);

    fillRandom(arr2, SIZE, 100);
    printf("Unsorted array:\n");
    printIntArray(arr2, SIZE);
    printf("bucket sort:\n");
    bucketSort(arr2, SIZE);
    printIntArray(arr2, SIZE);

    return 0;
}
