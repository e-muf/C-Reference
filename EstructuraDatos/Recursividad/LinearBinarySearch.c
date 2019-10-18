#include <stdio.h>

#define LENGTH 10
#define NUM 3
#define NUM2 40

int linearSearch(int *array, int key);
int binarySearch(int *array, int key);
int recursiveBinarySearch(int *array, int, int, int);
void bubbleSort(int *array); // Con fines académicos, es mejor no usar

int main() {

    int numbers[LENGTH] = {3,4,2,1,6,7,9,0,8,5};

    printf("\nBusqueda Lineal[%d]: %d", NUM, linearSearch(numbers, NUM));
    printf("\nBusqueda Lineal[%d]: %d\n", NUM2, linearSearch(numbers, NUM2));

    bubbleSort(numbers);

    printf("\nBusqueda Binaria[%d]: %d", NUM, binarySearch(numbers, NUM));
    printf("\nBusqueda Binaria[%d]: %d\n", NUM2, binarySearch(numbers, NUM2));

    printf("\nBusqueda Binaria Recursiva[%d]: %d", NUM, recursiveBinarySearch(numbers, 0, LENGTH, NUM));
    printf("\nBusqueda Binaria Recursiva[%d]: %d\n", NUM2, recursiveBinarySearch(numbers, 0, LENGTH, NUM2));

    printf("\n");

    return 0;
}

void bubbleSort(int *array) {
    int i, j, aux;
    
    for(i = 0; i < LENGTH; i++) {
        for(j = 0; j < LENGTH-i-1; j++) {
            if(*(array+j) > *(array+j+1)) {
                aux = *(array+j);
                *(array+j) = *(array+j+1);
                *(array+j+1) = aux;
            }
        }
    }
}

int linearSearch(int *array, int key) {
    int i = 0;

    for(; i < LENGTH; i++) {
        if(array[i] == key) {
            return 1;
        }
    }

    return -1;
}

// Busqueda Binaria Normal
int binarySearch(int *array, int key) {
    int root, min = 0, max = LENGTH-1;

    while(min <= max) {
        root = (min + max)/2;
        if(array[root] == key) {
            return 1;
        }
        if(key < array[root]) {
            max = root;
        }
        if(key > array[root]) {
            min = root+1;
        }
    }

    return -1;
}

// Busqueda Binaria Recursiva
int recursiveBinarySearch(int* array, int min, int max, int key) {
    int mid;

    if(min <= max) {
        mid = (max + min) / 2;
        if(key == array[mid]) {
            return 1;
        }
        else if(key < array[mid]) {
            return recursiveBinarySearch(array, min, mid-1, key);
        }
        else {
            return recursiveBinarySearch(array, mid+1, max, key);
        }
    }

    return -1;
}