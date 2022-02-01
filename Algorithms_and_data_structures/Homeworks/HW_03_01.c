#include <stdio.h>
int is_prime(int n) {
    if (n <= 1)
        return 0;
    if (n == 2)
        return 1;
    if (n%2==0)
        return 0;
    for (int j = 3; j * j <= n; j+=2)
        if (n % j == 0) return 0;
    return 1;
}

int main() {
    int number;
    printf("Enter a number: \n");
    scanf("%d", &number);
    if (is_prime(number) == 1){
        printf("Your number is prime.");
    } else {
        printf("Your number is NOT prime.");
    }
    return 0;
}
