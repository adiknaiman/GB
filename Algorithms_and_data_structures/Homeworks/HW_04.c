#include <stdio.h>

void print_int(int x)
{
    printf("%d\n", x);
}

//ДЗ_04_01 Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.
void decToBin(int n) {
    if (n >= 2) {
        decToBin(n / 2);
    }
    printf("%d", n % 2);
}

//ДЗ_04_02a Реализовать функцию возведения числа [a] в степень [b]:
//- Рекурсивно.
int power(int a, int b)
{
if (b > 0) {
        a *= power(a, b - 1);
    }
    else {
        return 1;
    }
    return a;
}

//ДЗ_04_02b Реализовать функцию возведения числа [a] в степень [b]:
//- Рекурсивно, используя свойство чётности степени
int power1(int a, int b)
{
    if (b == 0)
        return 1;
    if (b % 2 == 1)
        return power1(a, b - 1) * a;
    else {
        int c = power1(a, b / 2);
        return c * c;
    }
}

int main()
{
    //ДЗ_04_01
    int n;
    printf("Enter a decimal number to convert to binary code:\n");
    scanf_s("%d", &n);
    printf("Your number in binary code: \n");
    decToBin(n);
    printf("\n\n");

    //ДЗ_04_02a

    int a, b;
    printf("Enter a number: \n");
    scanf_s("%d", &a);
    printf("Enter its exponent: \n");
    scanf_s("%d", &b);
    power(a, b);
    printf("Recursive: %d to the power of %d is: ", a, b );
    print_int(power(a, b));
    printf("Recursive(even, odd powers): %d to the power of %d is: ", a, b );
    print_int(power1(a, b));

    return 0;
}