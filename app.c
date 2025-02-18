#include <stdio.h>
#include "vector.h"

int main() {
    init("v1", 20);   // Crear un vector de tamaño 20
    set("v1", 5, 8);  // Establecer el valor 8 en la posición 5
    int x;
    get("v1", 5, &x); // Obtener el valor de la posición 5
    printf("El valor en la posición 5 es: %d\n", x);
    return 0;
}



