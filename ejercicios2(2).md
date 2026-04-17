#### Ejercicio 2. Copia profunda y seguridad de `copyFrom()`

La clase `DengVector` encapsula un arreglo dinámico y debe evitar aliasing accidental entre dos vectores distintos.

##### Se pide

1. Revisar la implementación de copia en `Semana2/include/DengVector.h`.
2. Explicar por qué el arreglo destino debe ser físicamente independiente del arreglo fuente.

El arreglo destino debe ser físicamente independiente del arreglo fuente porque cada DengVector es dueño de su propio búfer. Si dos vectores compartieran el mismo _elem, entonces:

- Una modificación en un vector afectaría al otro de forma inesperada,
- El destructor de cada objeto intentaría hacer delete[] sobre la misma memoria dos veces,
- Se perdería la garantía de que la copia es independiente.

Por eso la implementación correcta reserva memoria nueva y copia los valores, en lugar de simplemente copiar el puntero.

3. Diseñar una prueba corta en C++ que muestre que la copia realizada es profunda y no superficial.

#include <iostream>
#include "DengVector.h"

int main() {
    ods::DengVector<int> original;
    original.insert(original.size(), 10);
    original.insert(original.size(), 20);
    original.insert(original.size(), 30);

    // Copia profunda por constructor de copia
    ods::DengVector<int> copia(original);

    // Modificar el vector original
    original[1] = 99;

    // Verificar que la copia no cambió
    std::cout << "original: "
              << original[0] << " "
              << original[1] << " "
              << original[2] << "\n";

    std::cout << "copia: "
              << copia[0] << " "
              << copia[1] << " "
              << copia[2] << "\n";

    return 0;
}

4. Ejecutar la prueba modificando un vector original y verificando que la copia no cambie.



5. Explicar qué problema aparecería si ambos objetos compartieran el mismo arreglo interno.

