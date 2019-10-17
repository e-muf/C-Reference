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
int searchNode(Node *, int);
void preorder(Node *);
void inorder(Node *);
void postorder(Node *);

int main() {
	int data, option;
	Node *tree = NULL;

	do {
		printf("\tARBOL BINARIO");

		printf("\nSelecciona una opcion:");
		printf("\n1. Agregar nodo al arbol.");
		printf("\n2. Imprimir arbol.");
		printf("\n3. Buscar un dato en el arbol.");
		printf("\n4. Recorrido el arbol en preorden.");
		printf("\n5. Recorrido el arbol en inorden.");
		printf("\n6. Recorrido el arbol en postorden.");
		printf("\n7. Salir.");
		printf("\n>> ");
		scanf("%d", &option);
		getchar();
		switch (option)
		{
		case 1:
			printf("\nIngrese el dato del nodo: ");
			scanf("%d", &data);
			insertNode(&tree, data);
			printf("\n[+] Se ha ingresado el nodo correctamente");
			getchar(); // Comentar en Windows
			//system("pause"); Descomentar en caso de windows
			break;
		case 2:
			printTree(tree, NULL, 0);
			//system("pause"); Descomentar en caso de windows
			break;
		case 3:
			printf("Ingrese el dato a buscar: ");
			scanf("%d", &data);
			getchar();
			if(searchNode(tree, data))
				printf("\n[+] El dato %d ha sido encontrado en el arbol.", data);
			else
				printf("\n[-] Dato no encontrado.");
			break;
		case 4:
			printf("\nPREORDEN\n");
			preorder(tree);
			break;

		case 5:
			printf("\nINORDEN\n");
			inorder(tree);
			break;

		case 6:
			printf("\nPOSTORDEN\n");
			postorder(tree);
			break;

		default:
			break;
		}
		printf("\nPresione una tecla para continuar... "); // Comentar en Windows
		getchar(); // Comentar en Windows
		system("clear");
	}while(option != 7);

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

void printTree(Node *tree, Trunk *previous, int is_right) {

	// Si el arbol esta vacio
	if(tree == NULL) {	
		return;
	}
	
	char previous_string[5] = "    ";
	Trunk *trunk = (Trunk *)malloc(sizeof(Trunk));
	trunk->previous = previous;
	strcpy(trunk->branch, previous_string);

	printTree(tree->right, trunk, 1);

	if(!previous) {
		strcpy(trunk->branch, "---");
	} 
	else if(is_right) {
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

	printTree(tree->left, trunk, 0);
}

int searchNode(Node *tree, int number) {
	if(tree == NULL) {
		return 0;
	}
	else if(tree->data == number) {
		return 1;
	}
	else if(number < tree->data) {
		return searchNode(tree->left, number);
	}
	else {
		return searchNode(tree->right, number);
	}
}

void preorder(Node *tree) {
	if(tree == NULL) {
		return;
	}

	else {
		printf("%d - ", tree->data);
		preorder(tree->left);
		preorder(tree->right);
	}
}

void inorder(Node *tree) {
	if(tree == NULL) {
		return;
	}
	else {
		inorder(tree->left);
		printf("%d - ", tree->data);
		inorder(tree->right);
	}	
}

void postorder(Node *tree) {
	if(tree == NULL) {
		return;
	}
	else {
		postorder(tree->left);
		postorder(tree->right);
		printf("%d - ", tree->data);
	}
}