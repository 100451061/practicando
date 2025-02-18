#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vector.h"

// número máximo de vectores que se pueden crear
#define MAX_VECTORES 10
// tamaño máximo de un vector
#define MAX_TAMANO 100

// Estructura que representa un vector
typedef struct {
    // Nombre del vector
    char nombre[50];
    // Datos del vector
    int datos[MAX_TAMANO];
    // tamaño del vector
    int tamano;
} Vector;

// Vectores creados
Vector vectores[MAX_VECTORES];
// número de vectores creados
int num_vectores = 0;

// Inicializa un vector
int init(char *nombre, int N) {
    // Comprueba si ya se han creado demasiados vectores
    if (num_vectores >= MAX_VECTORES) return -1;
    // Copia el nombre del vector
    strcpy(vectores[num_vectores].nombre, nombre);
    // Establece el tamaño del vector
    vectores[num_vectores].tamano = N;
    // Inicializa los datos del vector a 0
    memset(vectores[num_vectores].datos, 0, N * sizeof(int));
    // Incrementa el número de vectores creados
    num_vectores++;
    return 0;
}

// Asigna un valor en una posición del vector
int set(char *nombre, int i, int v) {
    // Comprueba si el vector existe
    for (int j = 0; j < num_vectores; j++) {
        if (strcmp(vectores[j].nombre, nombre) == 0) {
            // Comprueba si la posición est  dentro del rango del vector
            if (i >= 0 && i < vectores[j].tamano) {
                // Asigna el valor en la posición
                vectores[j].datos[i] = v;
                return 0;
            }
        }
    }
    return -1;
}

// Obtiene el valor en una posición del vector
int get(char *nombre, int i, int *x) {
    // Comprueba si el vector existe
    for (int j = 0; j < num_vectores; j++) {
        if (strcmp(vectores[j].nombre, nombre) == 0) {
            // Comprueba si la posición est  dentro del rango del vector
            if (i >= 0 && i < vectores[j].tamano) {
                // Obtiene el valor en la posición
                *x = vectores[j].datos[i];
                return 0;
            }
        }
    }
    return -1;
}

