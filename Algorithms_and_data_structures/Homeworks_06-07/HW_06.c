#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//ДЗ_06_01 Реализовать пузырьковую сортировку двумерного массива

void fillRandom(int* arr,int len, int border) {
    for (int i = 0; i < len; ++i){
        *(arr+i) = rand() % border;
    }
}

void swap(int *a, int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void printIntArray(int* array, int size) {
        for (int j = 0; j < size; ++j) {
            printf("%3d", array[j]);
            if (j > 0 && (j+1) % (int)sqrt(size) == 0){
                printf("\n");
            }
            else if (j != size - 1) {
                printf(", ");
            }
    }
    printf("\n");
}

void bubblesort(int* arr, int len){
    for (int i = 0; i < len; ++i){
        for (int j = 0; j < len - 1; ++j){
            if (arr[j] > arr[j + 1]){
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

//ДЗ_06_03 Реализовать алгоритм Трабба-Прадо-Кнута в коде на языке С
//f(x) = sqrt(|x|) + 5*x**3
double f (double x)
{
    return (sqrt(fabs(x)) + 5.0 * pow(x, 3.0));
}


int main(){

//ДЗ_06_01 Реализовать пузырьковую сортировку двумерного массива
    const int SIZE = 100;
    int arr[SIZE];
    fillRandom(arr, SIZE, 100);
    printf ("Unsorted array:\n");
    printIntArray(arr, SIZE);
    bubblesort(arr, SIZE);
    printf ("Sorted array:\n");
    printIntArray(arr, SIZE);

//ДЗ_06_03 Реализовать алгоритм Трабба-Прадо-Кнута в коде на языке С
    double y;
    int i;

    //Запросить у пользователя 11 чисел
    //double dblArr[11];
    //for(int i = 0; i < 11; i++){
    //    scanf("%lf", &dblArr[i]);}

    //double dblArr[11] = {4.9, 5.8, 40.3, 25.0, 105.0, 9.0, 21.6, 39.0, 51.7, 6.9, 3.6};
    double dblArr[11] = {1.9, 0.3, 2.9, 3.0, 3.8, 4.1, 10.9, 40.0, 100.7, 150.2, 300.1};

    // инвертировать последовательность и вывести на экран
    for (i = 10; i >= 0; i--)
    {
        y = f (dblArr[i]);
        if (y > 400.0)
        {
            printf ("%d Number is more than 400\n", i + 1);
        }
        else
        {
            printf ("%d %f\n", i + 1, y);
        }
    }

    return 0;
}
