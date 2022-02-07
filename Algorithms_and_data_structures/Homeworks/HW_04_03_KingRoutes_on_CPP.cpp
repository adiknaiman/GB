#include <iostream>

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
	std::cout << "Hello World!\n";

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