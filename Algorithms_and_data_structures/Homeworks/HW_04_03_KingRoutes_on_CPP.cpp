#include <iostream>
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


//ДЗ_04_03 Реализовать нахождение количества маршрутов шахматного короля с препятствиями
//(где единица - это наличие препятствия, а ноль - свободная для хода клетка)(король начинает путь с клетки 0, 0)

const int width = 6;
const int height = 6;

void initMap(int newField[width][height]) {
	for (int i = 0; i < width; i++) {
		for (int j = 0; j < height; j++) {
			newField[i][j] = 0;
		}
	}
};

void setWalls(int newField[width][height], int x, int y) {
	bool setNewWall = true;
	while (setNewWall == true) {
		//    std::cout << "set wall coordinates X:" << std::endl;
		//    std::cin >> x;
		//    std::cout << "set wall coordinates Y:" << std::endl;
		//    std::cin >> y;
		//    char needNewWalls;
		//    std::cout << "set new wall? y/n:" << std::endl;
		//    std::cin >> needNewWalls;
		//    if (needNewWalls == "y"){
		//    setNewWall = true;
		//    else {setNewWall = false};

		newField[0][2] = 1;
		newField[2][1] = 1;
		newField[2][2] = 1;
		//newField[0][1] = 1;
		//newField[2][3] = 1;
		//newField[0][1] = 1;
		//newField[2][3] = 1;

		setNewWall = false;
	}
}

int routes(int x, int y, int newField[width][height]) {
	if (newField[x][y] == 1) {
		return 0;
	}
	else if (x == 0 && y == 0) {
		return 0;
	}
	else if (x == 0) {
		if (routes(x, y - 1, newField) == 0 && y != 1){
		return 0;
}
		else {
			return 1;
		}
	}
	else if (y == 0) {
		if (routes(x - 1, y, newField) == 0 && x != 1) {
			return 0;
		}
		else { 
			return 1; 
		}
	}
	else {
		return routes(x, y - 1, newField) + routes(x - 1, y, newField);
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
	printf("Recursive: %d to the power of %d is: ", a, b);
	print_int(power(a, b));
	printf("Recursive(even, odd powers): %d to the power of %d is: ", a, b);
	print_int(power1(a, b));


	//ДЗ_04_03

	int field[width][height];
	initMap(field);
	setWalls(field, width, height);
	for (int y = 0; y < width; ++y) {
		for (int x = 0; x < height; ++x) {
			printf("%5d", field[y][x]);
		}
		printf("\n");
	}
	printf("\n");

	for (int x = 0; x < width; ++x) {
		for (int y = 0; y < height; ++y) {
			printf("%5d", routes(x, y, field));
		}
		printf("\n");
	}


	return 0;
}
