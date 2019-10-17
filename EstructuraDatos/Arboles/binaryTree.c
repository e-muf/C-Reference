#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura Nodo
typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
} Node;

// Estructura Tronco, servira para imprimir el arbol
typedef struct Trunk {
	struct Trunk *previous;
	char branch[5];
} Trunk;

// Prototipos
Node *createNode(int);
void insertNode(Node **, int);
void printTree(Node *, Trunk *, int); 

int main() {
	int data, option;
	Node *tree = NULL;

	do {
		printf("\tARBOL BINARIO");

		printf("\nSelecciona una opcion:");
		printf("\n1. Agregar nodo al arbol.");
		printf("\n2. Imprimir arbol.");
		printf("\n3. Salir.");
		printf("\n>> ");
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			printf("\nIngrese el dato del nodo: ");
			scanf("%d", &data);
			insertNode(&tree, data);
			printf("\n[+] Se ha ingresado el nodo correctamente\n\n");
			system("pause");
			break;
		case 2:
			printTree(tree, NULL, 0);
			system("pause");
			break;

		default:
			break;
		}
		printf("%d\n", tree->data);
		system("cls");
	}while(option != 3);

	return 0;
}

// Codigo para crear nodos
Node *createNode(int number) {
	Node *new_node = (Node *)malloc(sizeof(Node));
    
	new_node->data = number;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
} 

// Insertar nodos en el arbol
void insertNode(Node **tree, int number) {
	// Si el arbol esta vacio...
	if(*tree == NULL) {
		Node *new_node = createNode(number);
		*tree = new_node;
	}
	// Si el arbol tiene 1 o mas nodos
	else {
		int rootValue = (*tree)->data;
		
		// Si el numero es menor al valor de la raiz, se inserta en la izquierda
		if(number < rootValue) {
			insertNode(&(*tree)->left, number);
		}
		// Si el numero es mayor al valor de la raiz, se inserta en la derecha
		else {
			insertNode(&(*tree)->right, number);
		}
	}
}

void showTrunks(Trunk *p) {
	if(p == NULL) {
		return;
	}

	showTrunks(p->previous);

	printf("%s", p->branch);
}

void printTree(Node *tree, Trunk *previous, int is_left) {

	// Si el arbol esta vacio
	if(tree == NULL) {	
		return;
	}
	
	char previous_string[5] = "    ";
	Trunk *trunk = (Trunk *)malloc(sizeof(Trunk));
	trunk->previous = previous;
	strcpy(trunk->branch, previous_string);

	printTree(tree->left, trunk, 1);

	if(!previous) {
		strcpy(trunk->branch, " ---");
	} 
	else if(is_left) {
		strcpy(trunk->branch, ".---");
		strcpy(previous_string, "   |");
	}
	else {
		strcpy(trunk->branch, "`---");
		strcpy(previous->branch, previous_string);
	}

	showTrunks(trunk);
	printf("%d\n", tree->data);

	if(previous) {
		strcpy(previous->branch, previous_string);
	}
	strcpy(trunk->branch, "   |");

	printTree(tree->right, trunk, 0);
}



