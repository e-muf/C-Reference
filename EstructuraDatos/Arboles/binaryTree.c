#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura Nodo
typedef struct Node {
	int data;
	struct Node *left;
	struct Node *right;
} Node;

// Estructura Tronco, servirá para imprimir el árbol
typedef struct Trunk {
	struct Trunk *previous;
	char branch[5];
} Trunk;

// Prototipos
Node *createNode(int);
void insertNode(Node *, int);
void printTree(Node *, Trunk *, int); 

int main() {
	int data, option;
	Node *tree = NULL;

	do {
		printf("\tÁRBOL BINARIO");

		printf("\nSelecciona una opción:");
		printf("\n1. Agregar nodo al árbol.");
		printf("\n2. Imprimir árbol.");
		printf("\n3. Salir.");
		printf("\n>> ");
		scanf("%d", &option);

		switch (option)
		{
		case 1:
			printf("\nIngrese el dato del nodo: ");
			scanf("%d", &data);
			insertNode(tree, data);
			printf("\n[+] Se ha ingresado el nodo correctamente\n\n");
			break;
		case 2:
			printTree(tree, NULL, 0);
			getchar();
			break;

		default:
			break;
		}
		printf("%d\n", tree->data);
		getchar();
		system("clear");
	}while(option != 3);

	return 0;
}

// Código para crear nodos
Node *createNode(int number) {
	Node *new_node = (Node *)malloc(sizeof(Node));
    
	new_node->data = number;
	new_node->left = NULL;
	new_node->right = NULL;

	return new_node;
} 

// Insertar nodos en el árbol
void insertNode(Node *tree, int number) {
	// Si el árbol esta vacío...
	if(tree == NULL) {
		Node *new_node = createNode(number);
		tree = new_node;
	}
	// Si el arbol tiene 1 o más nodos
	else {
		int rootValue = tree->data;
		printf("%d", tree->data);
		// Si el número es menor al valor de la raíz, se inserta en la izquierda
		if(number < rootValue) {
			insertNode(tree->left, number);
		}
		// Si el número es mayor al valor de la raíz, se inserta en la derecha
		else {
			insertNode(tree->right, number);
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
	
	printf("%d", tree->data);

	// Si el arbol está vacío
	if(tree == NULL) {	
		return;
	}

	printf("Llegue aqui");

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



