#include <stdio.h>
#define WIDTH 6
#define HEIGHT 6

//вычисление количества ходов
int routes(int x, int y) {
    if (x == 0 && y == 0){
        return 0;
    }
    else if (x == 0 ^ y == 0) {
        return 1;
    }
    else {
        return routes(x, y - 1) + routes(x - 1, y);
        }
    }


int main()
{
    //считаем количество ходов
printf("\n");
    for(int y = 0; y < WIDTH; ++y){
        for (int x = 0; x< HEIGHT; ++x) {
            printf("%5d", routes(x, y));
        }
        printf("\n");
    }
    return 0;
}