#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define true 1 == 1
#define false 1 != 1
typedef int boolean;

#define SIZE 50

//1. Написать функцию проверяющую является ли переданное в неё бинарное дерево сбалансированным и написать программу, которая:
//создаст[50] деревьев по[10000] узлов и заполнит узлы случайными целочисленными значениями;
//рассчитает, какой процент из созданных деревьев является сбалансированными.

int count = 0;

typedef struct Node {
	int key;
	struct Node* left;
	struct Node* right;
} BinTreeIntNode;

BinTreeIntNode* binTreesArray[SIZE];

BinTreeIntNode* treeInsert(BinTreeIntNode* t, int data) {

	BinTreeIntNode* newNode;
	newNode = (BinTreeIntNode*)malloc(sizeof(BinTreeIntNode));
	newNode->key = data;
	newNode->left = NULL;
	newNode->right = NULL;
	BinTreeIntNode* current = t;
	BinTreeIntNode* parent = t;
	if (t == NULL) {
		t = newNode;
	}
	else {
		while (current->key != data) {
			parent = current;
			if (current->key > data) {
				current = current->left;
				if (current == NULL) {
					parent->left = newNode;
					count++;
					return t;
				}
			}
			else {
				current = current->right;
				if (current == NULL) {
					parent->right = newNode;
					count++;
					return t;
				}
			}
		}
	}
	++count;
	return t;
}


BinTreeIntNode* balancedTree(int n) {
	BinTreeIntNode* newNode;
	newNode = (BinTreeIntNode*)malloc(sizeof(BinTreeIntNode));
	int x;
	int nL;
	int nR;

	if (n == 0) {
		return NULL;
	}
	else {
		x = rand() % 100;
		nL = n / 2;
		nR = n - nL - 1;
		newNode->key = x;
		newNode->left = balancedTree(nL);
		newNode->right = balancedTree(nR);
	}
	// вернуть корень сбалансированного дерева
	return newNode;
}

void printBinTree(BinTreeIntNode* root) {
	if (root) {
		printf("%d", root->key);
		if (root->left || root->right) {
			printf("(");
			if (root->left)
				printBinTree(root->left);
			else
				printf("NULL");
			printf(",");
			if (root->right)
				printBinTree(root->right);
			else
				printf("NULL");
			printf(")");
		}
	}
}

void generateNodes(BinTreeIntNode* tree) {
	for (int i = 1; i < 10000; i++) {
		tree = treeInsert(tree, rand() % 100);
	}
}


// проверка сбалансированности
int max(int x, int y) {
	return (x >= y) ? x : y;
}

int height(BinTreeIntNode* node) {
	if (node == NULL) return 0;
	return 1 + max(height(node->left), height(node->right));
}

// Функция проверки сбалансированности дерева
int AVL(BinTreeIntNode* root) {
	if (root == NULL)
		return 1;
	int lh = height(root->left);
	int rh = height(root->right);
	if (abs(lh - rh) <= 1 && AVL(root->left) && AVL(root->right)) return 1;
	return 0;
}

//	2. Написать рекурсивную функцию бинарного поиска в дереве хранящемся в узлах, а не в массиве.
boolean binSearch(BinTreeIntNode* root, int value) {
	if (root == NULL)
		return false;
	if (root->key == value)
		return true;

	BinTreeIntNode* current = root;
	while (current->key != value)
	{
		if (value < current->key)
			current = current->left;
		else
			current = current->right;

		if (current == NULL)
			return false;
	}
}



int main() {
	printf("\n---------------------------------------------------\n\n");
	//1.Написать функцию проверяющую является ли переданное в неё бинарное дерево сбалансированным и написать программу, которая:
	//создаст[50] деревьев по[10000] узлов и заполнит узлы случайными целочисленными значениями;
	//рассчитает, какой процент из созданных деревьев является сбалансированными.

	srand(time(NULL));
	//    создаем одно дерево
	BinTreeIntNode* newTree{};
	newTree  = treeInsert(newTree, rand() % 100);;
	generateNodes(newTree);

	printf("Tree ganerated, Nodes count: %d", count);
	printf("\nTree is %sbalanced\n", AVL(newTree) ? "" : "NOT ");

	// создаем деревья в количестве SIZE
	int balanced = 0;


	//    printf("\nBalanced tree check: ");
	//for (int i = 0; i < SIZE; i++) {
	//    if (AVL(balancedTree(10000))) {
	//        balanced++;
	//    }
	//}

	//printf("\n%d trees generated.\n", SIZE);
	//printf("%d of them are balanced\n", balanced);
	//printf("%d of them are not balanced\n", SIZE - balanced);
	//printf("%% of balanced trees are: %d\n", (balanced * 100) / SIZE);

	//balanced = 0;

	for (int i = 0; i < SIZE; i++) {
		binTreesArray[i] = treeInsert(newTree, rand() % 100);
		if (AVL(newTree)) {
			balanced++;
		}
	}

	printf("\n%d trees generated.\n", SIZE);
	printf("%d of them are balanced\n", balanced);
	printf("%d of them are not balanced\n", SIZE - balanced);
	printf("%% of balanced trees are: %d\n", (balanced * 100) / SIZE);
	//    printf("\nTree is %sbalanced", AVL(balancedTree(10000))? "" : "NOT ");
	printf("\n---------------------------------------------------\n\n");

	//	2. Написать рекурсивную функцию бинарного поиска в дереве хранящемся в узлах, а не в массиве.
	newTree = balancedTree(100);
	printBinTree(newTree);
	int number = 0;
	printf("\n");
	printf("%d in tree: %s \n", number, binSearch(newTree, number += 11) ? "true" : "false");
	printf("%d in tree: %s \n", number, binSearch(newTree, number += 11) ? "true" : "false");
	printf("%d in tree: %s \n", number, binSearch(newTree, number += 11) ? "true" : "false");
	printf("%d in tree: %s \n", number, binSearch(newTree, number += 11) ? "true" : "false");
	printf("%d in tree: %s \n", number, binSearch(newTree, number += 11) ? "true" : "false");
	printf("%d in tree: %s \n", number, binSearch(newTree, number += 11) ? "true" : "false");
	printf("\n\n---------------------------------------------------\n\n");

	return 0;
}
