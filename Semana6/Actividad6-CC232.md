### Actividad 6 - CC232 

- Duración: 3 horas de clase.
- Modalidad: Trabajo individual.
- Entrega: Un archivo llamado `Actividad6-CC232.md` y los archivos modificados solicitados.

#### Bloque 1 - Diagnóstico inicial de la Semana 6

Revisa:

- `Semana6/README.md`
- `Semana6/CMakeLists.txt`
- `Semana6/include/Capitulo6.h`
- `Semana6/include/Capitulo10.h`

Ejecuta desde la raíz de la librería o desde el entorno de compilación que uses:

```bash
cmake -S . -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

Responde:

1. ¿Qué targets de demostraciones o pruebas aparecen para Semana 6?

Las demostraciones son:
- demo_pq_complheap_basico
- demo_heapify_floyd
- demo_heapsort
- demo_left_heap_merge
- demo_huffman
- demo_compare_with_semana5
- demo_bst_rotations
- demo_treap_basico
- demo_capitulo6_panorama

2. ¿Qué archivos se incluyen desde `Capitulo6.h`?

Los archivos incluidos desde `Capitulo6.h` son:
- Capitulo 10.h
- Huffman_PQ_generateTree.h
- Huffman_PQ.h
- MeldableHeap.h
- PQ_ComplHeap_delMax.h
- PQ_ComplHeap_getMax.h
- PQ_ComplHeap_heapifyFloyd.h
- PQ_ComplHeap_insert.h
- PQ_ComplHeap_macro.h
- PQ_ComplHeap_percolateDown.h
- PQ_ComplHeap_percolateUp.h
- PQ_ComplHeap.h
- PQ_LeftHeap_delMax.h
- PQ_LeftHeap_insert.h
- PQ_LeftHeap_merge.h
- PQ_LeftHeap.h
- PQ.h
- Treap.h
- vector_heapSort.h

3. ¿Qué diferencia práctica hay entre `Capitulo6.h` y `Capitulo10.h`?

- Capitulo10.h (alias de compatibilidad) no añade funcionalidades adicionales, sino que incluye al Capitulo6.h como un envoltorio, por lo cual tiene acceso a todas sus funcionalidades. 
- En cambio, Capitulo6.h  incluye las funcionalidades del capítulo 6 como colas de prioridad, heaps y treaps.

4. ¿Qué partes de Semana 6 dependen conceptualmente de Semana 5?

- PQ_ComplHeap se apoya en BinaryHeap de Semana 5 para entender la representación implícita en vector y las relaciones    
padre-hijo por índice. 
- Treap extiende BinarySearchTree de Semana 5 añadiendo prioridades y rotaciones. 
- Los demos de rotaciones BST (demo_bst_rotations.cpp) reutilizan directamente el código de Semana 5.
- demo_compare_with_semana5.cpp construye comparaciones entre BinaryHeap, PQ_ComplHeap, BinarySearchTree y Treap.

5. ¿Qué estructura se usa para prioridad pura?

PQ_ComplHeap (o PQ_LeftHeap) implementan cola de prioridad pura: solo importa extraer el máximo, no recorrer las claves en orden.

6. ¿Qué estructura se usa para búsqueda ordenada?

BinarySearchTree de Semana 5 permite recorrido inorden y operaciones como lowerBound y upperBound basadas en el orden de las claves.

7. ¿Qué estructura mezcla búsqueda ordenada con prioridad?

Treap mantiene simultáneamente la propiedad BST sobre key y la propiedad heap sobre priority, esto permite búsqueda ordenada, inserción y eliminación con balance esperado logarítmico gracias a las prioridades.

8. ¿Qué evidencia inicial obtuviste al ejecutar las pruebas sin modificar nada?.

| Comando ejecutado | Resultado | Error | Interpretación |
|----------|--------:|------:|----------------|
| cmake -S . -B build   | Exitoso   | Ninguno    | Los archivos de configuración están bien formados |
| cmake --build build    | Exitoso   | Ninguno    | Todo el código compila sin errores ni advertencias |
| ctest --test-dir build --output-on-failure  | 2/2 tests passed | Ninguno    | Las pruebas públicas e internas pasan sin modificación |

Lista a modificar:
- `Semana6/include/PQ_ComplHeap_macro.h`
- `Semana6/include/PQ_ComplHeap_percolateDown.h`
- `Semana6/include/PQ_ComplHeap_percolateUp.h`
- `Semana6/include/PQ_ComplHeap_heapifyFloyd.h`
- `Semana6/include/vector_heapSort.h`
- `Semana6/include/PQ_LeftHeap_merge.h`
- `Semana6/include/PQ_LeftHeap_insert.h`
- `Semana6/include/PQ_LeftHeap_delMax.h`
- `Semana6/include/Huffman_PQ.h`

#### Bloque 2 - Modificación de utilidades de heap completo

Revisa:

- `Semana6/include/PQ_ComplHeap_macro.h`
- `Semana6/include/PQ_ComplHeap_percolateUp.h`
- `Semana6/include/PQ_ComplHeap_percolateDown.h`

Modifica `PQ_ComplHeap_macro.h` para agregar funciones auxiliares `constexpr` adicionales, sin usar macros:

```cpp
pqHasLeftChild(i, n)
pqHasRightChild(i, n)
pqIsLeaf(i, n)
pqIsInternal(i, n)
```

Luego modifica `PQ_ComplHeap_percolateDown.h` para usar esas funciones auxiliares donde corresponda.

## Modificado:

```cpp
inline constexpr bool pqHasLeftChild(std::size_t i, std::size_t n) noexcept {
    return pqLeftChild(i) < n;
}

inline constexpr bool pqHasRightChild(std::size_t i, std::size_t n) noexcept {
    return pqRightChild(i) < n;
}

inline constexpr bool pqIsLeaf(std::size_t i, std::size_t n) noexcept {
    return !pqHasLeftChild(i, n);
}

inline constexpr bool pqIsInternal(std::size_t i, std::size_t n) noexcept {
    return pqHasLeftChild(i, n);
}
```

Responde:

1. ¿Por qué conviene expresar `parent`, `left`, `right` y pruebas de frontera como funciones pequeñas?

Conviene expresar estas operaciones como funciones pequeñas porque mejora la legibilidad del código, reduce la posibilidad de errores al escribir las fórmulas repetidamente y facilita el mantenimiento. Además, al ser `constexpr`, el compilador puede optimizar estas funciones en tiempo de compilación, eliminando cualquier sobrecarga adicional.

2. ¿Qué ventaja tiene `constexpr` frente a macros?

constexpr ofrece varias ventajas sobre los macros:

- Tipo seguro: Las funciones constexpr tienen tipos de retorno y parámetros definidos, lo que permite al compilador detectar errores de tipo, mientras que los macros simplemente realizan sustituciones de texto sin ningún tipo de verificación.

- Mejor depuración: Las funciones constexpr pueden ser depuradas como cualquier otra función, mientras que los macros pueden dificultar la depuración debido a su naturaleza de sustitución de texto.

- Alcance limitado: Las funciones constexpr respetan el alcance de las variables, mientras que los macros pueden afectar a cualquier parte del código donde se utilicen, lo que puede llevar a efectos secundarios no deseados.

- Mejor legibilidad: Las funciones constexpr suelen ser más fáciles de leer y entender que los macros, especialmente para operaciones complejas.

3. ¿Qué caso borde aparece cuando el nodo tiene solo hijo izquierdo?

El caso borde que aparece es cuando el nodo tiene solo un hijo izquierdo, en este caso `pqHasRightChild(i, n)` sería falso, y el código debe manejar correctamente esta situación para evitar acceder a un índice fuera de los límites del arreglo.

4. ¿Qué condición identifica una hoja en la representación implícita?

Una hoja en la representación implícita se identifica cuando el índice del nodo no tiene hijos, es decir, cuando 

5. ¿Qué cambió en `percolateDown` después de usar las funciones auxiliares?

Cambió la forma de expresar las condiciones, no el algoritmo. Antes se escribía while (existe el hijo izquierdo pqInHeap(pqLeftChild(i), n)), donde había que calcular el índice del hijo izquierdo para verificar si existe. Ahora se escribe while (pqIsInternal(i, n)), lo que comunica directamente la intención: el nodo baja mientras sea interno. Lo mismo para el hijo derecho: antes comparaba directamente índices, ahora se usa pqHasRightChild(i, n).


#### Bloque 3 - Modificación de `percolateUp`: conteo de intercambios

Revisa:

- `Semana6/include/PQ_ComplHeap_percolateUp.h`
- `Semana6/include/PQ_ComplHeap_insert.h`
- `Semana6/demos/demo_pq_complheap_basico.cpp`

Agrega una función nueva, sin romper la función existente:

```cpp
template<class T, class Compare>
std::size_t complHeapPercolateUpCount(std::vector<T>& a, std::size_t i, Compare comp);
```

La función debe hacer lo mismo que `complHeapPercolateUp`, pero además debe retornar cuántos intercambios realizó.

Luego modifica o crea una demostración para insertar la secuencia:

```cpp
{ 40, 10, 70, 30, 90, 20, 80, 60 }
```

y mostrar por cada inserción:

- elemento insertado,
- cantidad de intercambios,
- arreglo interno resultante,
- si la propiedad heap se mantiene.

## Solución:

```cpp
template <class T, class Compare>
std::size_t complHeapPercolateUpCount(std::vector<T>& a, std::size_t i, Compare comp) {
    std::size_t swaps = 0;
    while (pqHasParent(i)) {
        const std::size_t p = pqParent(i);
        if (!comp(a[p], a[i])) {
            break;
        }
        std::swap(a[p], a[i]);
        i = p;
        ++swaps;
    }
    return swaps;
}
```

## Salida de la demostración:

```
insertado=40 | intercambios=0 | heap=[40] | propiedad_heap=verdadero
insertado=10 | intercambios=0 | heap=[40, 10] | propiedad_heap=verdadero
insertado=70 | intercambios=1 | heap=[70, 10, 40] | propiedad_heap=verdadero
insertado=30 | intercambios=1 | heap=[70, 30, 40, 10] | propiedad_heap=verdadero
insertado=90 | intercambios=2 | heap=[90, 70, 40, 10, 30] | propiedad_heap=verdadero
insertado=20 | intercambios=0 | heap=[90, 70, 40, 10, 30, 20] | propiedad_heap=verdadero
insertado=80 | intercambios=1 | heap=[90, 70, 80, 10, 30, 20, 40] | propiedad_heap=verdadero
insertado=60 | intercambios=1 | heap=[90, 70, 80, 60, 30, 20, 40, 10] | propiedad_heap=verdadero
```

Responde:

1. ¿En qué casos `percolateUp` hace cero intercambios?

Cuando el elemento insertado no tiene padre (es el primer elemento), o cuando su padre ya tiene prioridad mayor o igual. Por ejemplo, al insertar 10 detrás de 40, no se intercambia porque 40 >= 10 en un max-heap.

2. ¿En qué casos puede hacer `O(log n)` intercambios?

Cuando el elemento insertado tenga mayor prioridad que todos sus ancestros y suba desde una hoja hasta la raíz. En la traza al insertar 90: entra al final, sube sobre 30 y luego sobre 70, haciendo 2 intercambios en un heap de 5 elementos.

3. ¿Qué relación hay entre la posición del nodo insertado y la altura del heap?

El elemento nuevo siempre entra al final del arreglo, que corresponde a la hoja disponible siguiente. A partir de esa hoja, percolateUp solo puede subir por el camino hacia la raíz. El número máximo de intercambios está limitado por la altura del heap: O(log n), no puede ir por ramas laterales.

4. ¿Por qué el arreglo interno no necesariamente queda ordenado?

El heap sólo mantiene una relación local entre padre e hijos, no un orden total. En un max-heap se garantiza que cada padre sea mayor o igual que sus hijos, pero no se garantiza que el arreglo esté ordenado de forma descendente. Por ejemplo, [90, 70, 80, 60, 30, 20, 40, 10] es un max-heap válido incluso si 80 está después de 70 y 40 está después de 20.

5. ¿Qué propiedad sí queda garantizada?.

Propiedad heap garantizada: para todo nodo i, a[i] tiene prioridad mayor o igual que a[left(i)] y a[right(i)], cuando esos hijos existen.

#### Bloque 4 - Modificación de `percolateDown`: elección del hijo dominante

Revisa:

- `Semana6/include/PQ_ComplHeap_percolateDown.h`
- `Semana6/include/PQ_ComplHeap_delMax.h`
- `Semana6/demos/demo_pq_complheap_basico.cpp`

Agrega una función auxiliar o versión instrumentada que permita observar qué hijo se elige durante la bajada:

```cpp
template<class T, class Compare>
std::size_t complHeapPercolateDownCount(std::vector<T>& a, std::size_t n, std::size_t i, Compare comp);
```

La función debe retornar la cantidad de intercambios realizados.

Crea una demostración pequeña donde elimines repetidamente el máximo de un heap y registres:

- máximo eliminado,
- arreglo antes de reparar,
- número de intercambios,
- arreglo después de reparar.

## Función auxiliar:

```cpp
template <class T, class Compare>
std::size_t complHeapPercolateDownCount(std::vector<T>& a, std::size_t n, std::size_t i, Compare comp) {
    std::size_t swaps = 0;
    while (pqIsInternal(i, n)) {
        std::size_t c = pqLeftChild(i);

        //se elige el hijo dominante.
        if (pqHasRightChild(i, n)) {
            const std::size_t r = pqRightChild(i);
            if (comp(a[c], a[r])) {
                c = r;
            }
        }

        if (!comp(a[i], a[c])) {
            break;
        }

        std::swap(a[i], a[c]);
        i = c;
        ++swaps;
    }
    return swaps;
}
```

## Salida de la demostración:

```
heap inicial=[90, 70, 80, 60, 30, 20, 40, 10] | propiedad_heap=verdadero

maximo_eliminado=90 | antes_reparar=[10, 70, 80, 60, 30, 20, 40] | intercambios=2 | despues_reparar=[80, 70, 40, 60, 30, 20, 10] | propiedad_heap=verdadero
maximo_eliminado=80 | antes_reparar=[10, 70, 40, 60, 30, 20] | intercambios=2 | despues_reparar=[70, 60, 40, 10, 30, 20] | propiedad_heap=verdadero
maximo_eliminado=70 | antes_reparar=[20, 60, 40, 10, 30] | intercambios=2 | despues_reparar=[60, 30, 40, 10, 20] | propiedad_heap=verdadero
maximo_eliminado=60 | antes_reparar=[20, 30, 40, 10] | intercambios=1 | despues_reparar=[40, 30, 20, 10] | propiedad_heap=verdadero
maximo_eliminado=40 | antes_reparar=[10, 30, 20] | intercambios=1 | despues_reparar=[30, 10, 20] | propiedad_heap=verdadero
maximo_eliminado=30 | antes_reparar=[20, 10] | intercambios=0 | despues_reparar=[20, 10] | propiedad_heap=verdadero
maximo_eliminado=20 | antes_reparar=[10] | intercambios=0 | despues_reparar=[10] | propiedad_heap=verdadero
maximo_eliminado=10 | antes_reparar=[] | intercambios=0 | despues_reparar=[] | propiedad_heap=verdadero
```


Responde:

1. ¿Por qué después de `delMax` se mueve el último elemento a la raíz?

Porque al eliminar la raíz queda un espacio vacío por lo que el último elemento se mueve allí para mantener el arreglo contiguo sin dejar espacios vacíos el heap implícito depende de que no haya huecos para que las fórmulas de índice funcionen correctamente.

2. ¿Por qué la reparación baja y no sube?

Porque el proceso de reparación busca restaurar la propiedad de heap, y después de colocar el último elemento en la raíz, es probable que este elemento sea menor que sus hijos, lo que viola la propiedad de heap. Por lo tanto, se necesita bajar el elemento para encontrar su posición correcta en el heap.

3. ¿Cómo se decide entre hijo izquierdo e hijo derecho?

Se elige el hijo que tenga mayor prioridad (en un max-heap, el hijo con el valor más grande) para intercambiar con el nodo actual. Esto asegura que la propiedad de heap se restaure correctamente.

4. ¿Qué pasa si el nodo actual tiene un solo hijo?

Solo puede tener hijo izquierdo porque en un heap completo el hijo derecho nunca existe sin el izquierdo. En ese caso se compara directamente con ese único hijo y se intercambia si corresponde.

5. ¿Por qué `delMax` tiene costo `O(log n)`?.

Porque percolateDown baja como máximo un nivel por iteración y la altura del heap es log n. En el peor caso el elemento recorre todo el camino desde la raíz hasta una hoja, exactamente log n pasos.

#### Bloque 5 - Validación explícita de la propiedad heap

Revisa:

- `Semana6/include/PQ_ComplHeap.h`
- `Semana6/pruebas_publicas/test_public_week6.cpp`
- `Semana6/pruebas_internas/test_internal_week6.cpp`

Agrega una función de validación, ya sea como método de `PQ_ComplHeap` o como función auxiliar:

```cpp
bool isValidHeap() const;
```

o, si se implementa como función libre:

```cpp
template<class T, class Compare>
bool complHeapIsValid(const std::vector<T>& a, Compare comp);
```

Debe verificar que cada padre tenga prioridad mayor o igual que sus hijos según la convención del comparador usado en la implementación.

Agrega pruebas para:

1. heap vacío,
2. heap con un elemento,
3. heap con elementos repetidos,
4. heap construido por inserciones,
5. heap construido por `heapify`,
6. heap después de varias llamadas a `delMax`.

Responde:

1. ¿Qué invariante verifica la función?

Comprobación de propiedad heap: para cada nodo i, su padre tiene prioridad mayor o igual que sus hijos según el comparador, con std::less<int> eso es equivalente a a[i] >= a[left(i)] y a[i] >= a[right(i)].

2. ¿Por qué basta revisar relaciones padre-hijo?

Porque la propiedad heap es propia. Si cada padre controla a sus hijos, por transitividad también controla a todos sus descendientes en el subárbol correspondiente. No hace falta comparar cada nodo con todos los descendientes.

3. ¿Por qué no es necesario comparar cada nodo con todos sus descendientes?

Porque si padre domina a hijo y el hijo domina al nieto, entonces por transitividad, el padre domina al nieto. Con sólo comprobar las relaciones padre-hijo directas se cubre toda la estructura haciendo exactamente n - 1 comparaciones.

4. ¿Cuál es el costo de validar todo el heap?

El costo es O(n) ya que se recorre el arreglo una vez y se hacen como máximo dos comparaciones por índice.

5. ¿Por qué esta función es útil en pruebas pero no necesariamente en producción?

En pruebas encuentra fallos en insert, delMax, heapify y percolateDown, esto en producción le agregaría un costo de O(n) a operaciones que normalmente son O(log n) o O(1). Se emplea para comprobaciones en modo diagnóstico y no en cada operación del flujo normal.

#### Bloque 6 - Construcción de heap: inserciones sucesivas vs Floyd

Revisa:

- `Semana6/include/PQ_ComplHeap_heapifyFloyd.h`
- `Semana6/include/PQ_ComplHeap_insert.h`
- `Semana6/demos/demo_heapify_floyd.cpp`

Modifica la demostración de `heapify` para comparar dos formas de construir un heap con la misma entrada:

```cpp
{ 4, 17, 3, 90, 55, 21, 8, 13, 34, 2, 1, 89 }
```

Construcción A:

- insertar elementos uno por uno usando `insert`.

Construcción B:

- copiar el vector y aplicar `heapify` de Floyd.

La demostración debe mostrar:

- arreglo inicial,
- arreglo final por inserciones,
- arreglo final por Floyd,
- cantidad aproximada o exacta de intercambios si agregaste contadores,
- validación con `isValidHeap`.

Responde:

1. ¿Por qué ambos resultados pueden ser heaps válidos aunque sus arreglos finales no sean idénticos?

Porque un heap solo requiere relación local entre padre e hijos, no un orden total. Hay muchas permutaciones de un conjunto de claves que cumplen la propiedad heap. Los dos métodos construyen el árbol en distinto orden y pueden llegar a formas internas diferentes, pero ambas son correctas.

2. ¿Por qué insertar `n` elementos puede costar `O(n log n)`?

Cada inserción puede hacer subir el nuevo elemento hasta la raíz. El costo es O(log k) para el k-ésimo elemento. 
O(log 1) + O(log 2) + ... + O(log n) es menor que O(n log n).

3. ¿Por qué Floyd puede construir el heap en `O(n)`?

Floyd no lo hace uno por uno. Parte del arreglo completo y llama a percolateDown únicamente en nodos internos, la clave es que la mayoría de los nodos están cerca de las hojas y descienden poco, los nodos del último nivel no tienen que bajar nada, el análisis amortizado muestra que la cantidad total de trabajo es lineal.

4. ¿Qué nodos procesa Floyd primero?

Procesa primero el último nodo interno, que está en el índice n/2 - 1, y avanza hacia atrás hasta la raíz. 
Para n = 12, procesa los índices 5, 4, 3, 2, 1, 0 en ese orden.

5. ¿Por qué Floyd no necesita llamar a `percolateDown` desde las hojas?.

Porque una hoja ya es un subárbol heap válido de tamaño 1 y no tiene hijos. Llamar a percolateDown desde una hoja no cambiaría nada. Por ello, Floyd empieza desde el último nodo interno y va subiendo; cuando trata un nodo, sus hijos ya han sido reparados o son hojas.

#### Bloque 7 - Modificación de `heapSort`

Revisa:

- `Semana6/include/vector_heapSort.h`
- `Semana6/demos/demo_heapsort.cpp`

Agrega una versión de `heapSort` que permita elegir el sentido del resultado:

```cpp
template<class T, class Compare>
void heapSort(std::vector<T>& a, Compare comp, bool ascending);
```

La función debe mantener la idea de heapsort in situ. No uses `std::sort`.

Prueba con:

```cpp
{ 5, 1, 5, 3, 8, 2, 8, 0 }
```

y muestra:

- resultado ascendente,
- resultado descendente,
- comportamiento con repetidos.

## Versión de heapSort modificada:

```cpp
template <class T, class Compare = std::less<T>>
void heapSort(std::vector<T>& a, Compare comp = Compare{}, bool ascending = true) {
    if (a.size() < 2) return;

    if (ascending) {
        //con std::less se construye max-heap y queda ascendente.
        complHeapHeapifyFloyd(a, comp);
        for (std::size_t n = a.size(); n > 1; --n) {
            std::swap(a[0], a[n - 1]);
            complHeapPercolateDown(a, n - 1, 0, comp);
        }
        return;
    }

    //para descendente se invierte el comparador.
    auto reversedComp = [comp](const T& l, const T& r) mutable -> bool {
        return comp(r, l);
    };
    complHeapHeapifyFloyd(a, reversedComp);
    for (std::size_t n = a.size(); n > 1; --n) {
        std::swap(a[0], a[n - 1]);
        complHeapPercolateDown(a, n - 1, 0, reversedComp);
    }
}
```

## Salida de la demostración con {5, 1, 5, 3, 8, 2, 8, 0}:

```
entrada:           [5, 1, 5, 3, 8, 2, 8, 0]
salida ascendente: [0, 1, 2, 3, 5, 5, 8, 8]
salida descendente:[8, 8, 5, 5, 3, 2, 1, 0]

conteo entrada:     {0->1, 1->1, 2->1, 3->1, 5->2, 8->2}
conteo ascendente:  {0->1, 1->1, 2->1, 3->1, 5->2, 8->2}
conteo descendente: {0->1, 1->1, 2->1, 3->1, 5->2, 8->2}
```

Responde:

1. ¿Por qué heapsort puede ordenar in situ?

Porque utiliza el mismo vector como dos zonas: [heap activo | zona ya ordenada]. Después de construir el heap, cada paso intercambia la raíz con la última posición del heap activo y reduce el tamaño lógico del heap. No hace falta un arreglo auxiliar de n tamaño.

2. ¿Qué parte del algoritmo destruye gradualmente el heap?

La parte del algoritmo que intercambia la raíz con la última posición del heap activo y reduce el tamaño lógico del heap destruye gradualmente el heap.

3. ¿Por qué heapsort cuesta `O(n log n)`?

Tiene dos fases: heapify de Floyd en O(n), y n-1 extracciones implícitas, cada una con un percolateDown de O(log n). Domina la segunda fase: O(n) + O(n log n) = O(n log n)

4. ¿Es heapsort estable? Justifica con un ejemplo.

No es estable, si se insertan (5, A) y (5, B) en ese orden y se ordena por el número, heapsort puede producir (5, B), (5, A) ya que los intercambios de larga distancia entre la raíz y el final del rango activo alteran el orden relativo de elementos iguales.

5. ¿Qué diferencia hay entre usar `heapSort` y extraer todos los elementos con `delMax`?

heapSort trabaja directamente sobre el vector, sin necesidad de crear una estructura auxiliar. delMax con extracción implica construir un PQ_ComplHeap, llamar a delMax repetidamente y guardar el resultado en otro contenedor. Ambos son O(n log n), pero heapSort es preferible cuando se desea dejar el arreglo ordenado sin consumo extra de memoria; delMax es más natural cuando la prioridad se usa dinámicamente con inserciones y extracciones intercaladas.

#### Bloque 8 - Heap izquierdista: validación de `merge`

Revisa:

- `Semana6/include/PQ_LeftHeap.h`
- `Semana6/include/PQ_LeftHeap_merge.h`
- `Semana6/include/PQ_LeftHeap_insert.h`
- `Semana6/include/PQ_LeftHeap_delMax.h`
- `Semana6/demos/demo_left_heap_merge.cpp`

Agrega una función de validación para el heap izquierdista:

```cpp
bool isValidLeftHeap() const;
```

Debe verificar al menos:

1. propiedad de heap,
2. propiedad izquierdista,
3. consistencia de tamaño,
4. consistencia de `npl` o distancia nula, si el código la almacena.

Luego modifica la demostración de `merge` para construir dos heaps, mezclarlos y validar el resultado.

Responde:

1. ¿Por qué `merge` es la operación central del heap izquierdista?

Pues insert y delMax se reducen a mezclar heaps. insert(x) une el heap actual con un heap formado por un único nodo {x}. delMax elimina la raíz y combina sus dos subárboles. El diseño del heap izquierdista está pensado para que merge sea eficiente, por eso se mantiene el camino derecho corto.

2. ¿Cómo se implementa `insert` usando `merge`?

Se crea un nodo nuevo que por sí solo ya es un heap válido, y se fusiona con la raíz actual. El costo depende del largo del camino derecho.

3. ¿Cómo se implementa `delMax` usando `merge`?

Se guarda el valor de la raíz, se separan sus subárboles izquierdo y derecho, se elimina la raíz y se fusionan los dos subárboles.

4. ¿Qué propiedad adicional diferencia un heap izquierdista de un heap binario completo?

Propiedad izquierdista: npl(left) >= npl(right). En un heap binario completo, todos los niveles, excepto quizá el último, deben estar llenos, y emplea un vector para la representación implícita. 
El heap izquierdista no necesita ser completo, sino que obliga al camino de la derecha a ser el más corto, haciendo que merge siga por la rama más pequeña del árbol.

5. ¿Qué ventaja conceptual tiene un heap izquierdista frente a un heap binario completo?.

La ventaja es que merge es una operación natural y eficiente, con un coste de O(log n). En un heap binario completo, la operación de fusionar dos heaps no es directa, pues se requeriría copiar los elementos y aplicar heapify, lo que tiene un costo de O(n). El heap izquierdista es una estructura natural cuando se necesitan heaps mezclables.

#### Bloque 9 - Huffman: modificación de desempate y caso de un símbolo

Revisa:

- `Semana6/include/Huffman_PQ.h`
- `Semana6/include/Huffman_PQ_generateTree.h`
- `Semana6/demos/demo_huffman.cpp`

Modifica el código de Huffman para documentar y probar explícitamente el desempate entre símbolos de igual frecuencia.

Usa este alfabeto:

```cpp
{ {'A', 5}, {'B', 5}, {'C', 10}, {'D', 10}, {'E', 20} }
```

Además, agrega una prueba para el caso extremo de un solo símbolo:

```cpp
{ {'X', 100} }
```

La implementación debe producir un código válido para el único símbolo, por ejemplo `"0"`.

Responde:

1. ¿Por qué Huffman necesita una cola de prioridad?

Porque en cada paso del algoritmo se requiere sacar del bosque los dos nodos de menor frecuencia. Con una cola de prioridad esa extracción se puede hacer en O(log n) en vez de buscar de forma lineal.

2. ¿Qué elementos se extraen repetidamente?

Los dos nodos menos disponibles en la cola de prioridad. En un principio son símbolos individuales; después de la primera fusión también pueden ser nodos internos que representan subárboles.

3. ¿Qué nodo se vuelve a insertar?

El nodo combinado resultante de la fusión de los dos nodos extraídos, su frecuencia es la suma de las dos frecuencias, y sus hijos los dos nodos extraídos.

4. ¿Por qué el caso de un solo símbolo requiere cuidado especial?

Porque si solo hay un símbolo, el algoritmo nunca intercambia nodos y el árbol resultante es una sola hoja. El recorrido para obtener los códigos llegaría a esa hoja con prefijo vacío, que no es un código válido para descifrar. La solución es asignar “0” cuando el prefijo llega a una hoja y es vacío.

5. ¿Qué significa que el conjunto de códigos sea libre de prefijos?

Es decir, ningún código es prefijo de ningún otro. Por ejemplo, si el código de E es 0, ningún otro código puede comenzar con 0. 
Esto asegura que, al llegar a una hoja del árbol durante la fase de descodificación, se sabe a ciencia cierta que se ha leído el código entero del símbolo, y no se requieren separadores.

6. ¿Cómo afecta el desempate a la forma del árbol?

Cuando haya empates en frecuencia, cambie qué nodos se fusionan antes. Con el criterio por minSymbol, los subárboles que contienen el símbolo de letra más baja se unen antes que los que contienen letras posteriores, esto produce un árbol determinista, pero no es el único árbol óptimo que se puede obtener.

7. ¿El desempate cambia necesariamente la longitud total ponderada? Justifica.

No, todos los árboles de Huffman para el mismo conjunto de frecuencias tienen la misma longitud total ponderada mínima. El desempate sólo decide entre árbol igualmente óptimos. En el ejemplo el costo siempre es 110, sin importar cual sea el criterio de desempate entre empates.

#### Bloque 10 - Treap: modificación de código, rotaciones e invariantes

Revisa:

- `Semana6/include/Treap.h`
- `Semana6/demos/demo_treap_basico.cpp`
- `Semana6/pruebas_publicas/test_public_week6.cpp`
- `Semana6/pruebas_internas/test_internal_week6.cpp`

Este bloque es obligatorio. Su objetivo es que no uses `Treap` solo como estructura decorativa, sino que entiendas cómo combina dos invariantes simultáneos:

1. propiedad de árbol binario de búsqueda sobre `key`,
2. propiedad de heap sobre `priority`.

En la implementación de Semana 6, una prioridad menor sube más cerca de la raíz. Por eso `bubbleUp` rota mientras el padre tiene prioridad mayor que el nodo insertado.

##### Parte A - Construcción determinística con prioridades fijas

Crea o modifica `demo_treap_basico.cpp` para construir el treap usando `addWithPriority`, no solo `add`, con esta secuencia:

```cpp
{ {50, 50}, {30, 30}, {70, 70}, {20, 20}, {40, 40}, {60, 60}, {80, 80} }
```

Cada par representa:

```cpp
{ clave, prioridad }
```

Después de cada inserción, imprime:

- clave insertada,
- prioridad asignada,
- recorrido inorden,
- recorrido por niveles,
- raíz actual,
- resultado de `isBST()`,
- resultado de `isHeapByPriority()`,
- resultado de `isTreap()`.

Responde:

1. ¿Por qué el recorrido inorden debe salir ordenado aunque las prioridades cambien la forma del árbol?

Porque las rotaciones que realiza bubbleUp mantienen la propiedad BST sobre las claves. Una rotación solo cambia relaciones padre-hijo locales pero mantiene los rangos de claves en cada subárbol correctamente a la izquierda o derecha.

2. ¿Por qué la raíz no necesariamente es la primera clave insertada?

Porque bubbleUp puede subir cualquier nodo cuya prioridad es menor que la de sus ancestros. En este ejemplo el nodo {20,20} fue insertado de cuarto pero terminó como raíz por que su prioridad 20 es la menor de todas.

3. ¿Qué nodo debe subir cuando se inserta una clave con prioridad menor que la de sus ancestros?

Porque en esta implementación la prioridad menor tiene mayor jerarquía, el nodo que acabamos de insertar tiene que subir. bubbleUp sube el nodo con su padre mientras el padre tenga prioridad mayor.

4. ¿Qué propiedad conserva una rotación local sobre las claves?

La propiedad de BST. En una rotación a la derecha en un nodo u, su hijo izquierdo w sube y u desciende a la derecha de w. El subárbol derecho de w se convierte en el subárbol izquierdo de u. Como esas claves eran mayores que w y menores que u, el orden relativo se conserva. 

5. ¿Qué propiedad intenta restaurar `bubbleUp` sobre las prioridades?.

La propiedad heap sobre las prioridades: un padre debe tener prioridad menor o igual a sus hijos. Si el nodo insertado tiene prioridad menor que la del padre, entonces se viola esa propiedad y se rota mediante bubbleUp para corregir esa violación.

##### Parte B - Instrumentación de `bubbleUp`

Agrega una versión instrumentada sin eliminar la función existente:

```cpp
template<class T, class Compare>
std::size_t bubbleUpCount(typename Treap<T, Compare>::Node* u);
```

Si prefieres mantenerla como método interno de la clase, puedes llamarla:

```cpp
std::size_t bubbleUpCount(Node* u);
```

La función debe realizar el mismo proceso que `bubbleUp`, pero retornando cuántas rotaciones se hicieron.

Luego agrega una forma controlada de usarla desde una inserción, por ejemplo:

```cpp
std::size_t addWithPriorityCount(const T& x, std::uint64_t priority);
```

No cambies el comportamiento público de `add` ni de `addWithPriority`.

Prueba con una secuencia que fuerce varias rotaciones:

```cpp
{ {100, 100}, {90, 90}, {80, 80}, {70, 70}, {60, 60} }
```

## Solucion:

```cpp
std::size_t bubbleUpCount(Node* u) {
    std::size_t rotations = 0;
    while (u->parent != nullptr && u->parent->priority > u->priority) {
        if (u->isRightChild()) {
            rotateLeft(u->parent);
        } else {
            rotateRight(u->parent);
        }
        ++rotations;
    }
    return rotations;
}

std::size_t addWithPriorityCount(const T& x, std::uint64_t priority) {
    Node* u = new Node(x, priority);
    if (!addNode(u)) { delete u; return 0; }
    return bubbleUpCount(u);
}
```

## Tabla para {100,100}, {90,90}, {80,80}, {70,70}, {60,60}:

Clave insertada | Prioridad asignada | Rotaciones realizadas | Raíz actual
----------------|--------------------|-----------------------|-------------
100             | 100                | 0                     | 100
90              | 90                 | 1                     | 90
80              | 80                 | 2                     | 80 
70              | 70                 | 3                     | 70
60              | 60                 | 4                     | 60

Responde:

1. ¿Por qué esta secuencia tiende a producir rotaciones repetidas?

Como cada nodo nuevo tiene prioridad menor que el que era raíz. Eso rompe la propiedad de heap por prioridad y hace que bubbleUp tenga que rotar al nuevo nodo hasta la raíz.

2. ¿Cuándo `bubbleUpCount` retorna cero?

Cuando el nodo insertado es la primera clave, o cuando su padre tiene prioridad menor o igual que la suya.

3. ¿Cuál es el peor caso de rotaciones durante una inserción?

En un árbol de altura h el peor caso es h rotaciones: el nodo insertado en la hoja más profunda tiene que subir hasta la raíz. En un treap con prioridades aleatorias, la altura esperada es O(log n).

4. ¿Por qué una rotación no rompe la propiedad BST?

Porque solo cambian relaciones locales padre-hijo manteniendo el rango de claves: el subárbol intermedio a mover siempre tiene claves en el rango correcto luego de la rotación.

5. ¿Por qué el treap busca mantener altura esperada logarítmica, no altura garantizada logarítmica?

Porque su equilibrio está sujeto a las prioridades. Con prioridades aleatorias, la estructura esperada es buena (como un BST aleatorio). Con prioridades antagónicas, puede degenerar a una altura de O(n). 
AVL y Red-Black garantizan un balance determinista.

##### Parte C - Instrumentación de `trickleDown` y eliminación

Agrega una versión instrumentada sin eliminar la función existente:

```cpp
std::size_t trickleDownCount(Node* u);
```

y una eliminación controlada:

```cpp
std::size_t removeCount(const T& x);
```

La eliminación debe rotar el nodo hacia abajo hasta que tenga a lo más un hijo, luego aplicar la lógica equivalente a `splice`.

Usa el treap construido en la Parte A y elimina:

```cpp
50, 20, 70
```

Después de cada eliminación, imprime:

- clave eliminada,
- cantidad de rotaciones,
- recorrido inorden,
- recorrido por niveles,
- `isBST()`,
- `isHeapByPriority()`,
- `isTreap()`.

## Version de `trickleDownCount`:

```cpp
std::size_t trickleDownCount(Node* u) {
    std::size_t rotations = 0;
    while (u->left != nullptr || u->right != nullptr) {
        Node* child = nullptr;
        if (u->left == nullptr) child = u->right;
        else if (u->right == nullptr) child = u->left;
        else child = (u->left->priority < u->right->priority) ? u->left : u->right;

        if (child->isRightChild()) rotateLeft(u);
        else rotateRight(u);
        ++rotations;
    }
    return rotations;
}

std::size_t removeCount(const T& x) {
    Node* u = findEQ(x);
    if (!u) return 0;
    std::size_t rotations = trickleDownCount(u);
    splice(u);
    delete u;
    return rotations;
}
```

## Tabla eliminando 50, 20, 70 del treap

Clave eliminada | Rotaciones realizadas | Raíz actual | isBST() | isHeapByPriority() | isTreap()
----------------|-----------------------|-------------|---------|--------------------|---------
50              | 1                     | 20          | true    | true               | true
20              | 1                     | 40          | true    | true               | true
70              | 1                     | 40          | true    | true               | true

Responde:

1. ¿Por qué eliminar en un treap no es simplemente borrar como en un BST común?

Porque además de mantener el orden por clave, se debe conservar la propiedad de heap por prioridad. Borrar directamente un nodo con dos hijos puede dejar prioridades incorrectas entre los nodos que quedan.

2. ¿Por qué `trickleDown` elige rotar con el hijo de menor prioridad?

Porque en esta implementación sube más la prioridad menor. Para bajar el nodo a eliminar se debe subir el hijo con menor prioridad para que quede en su sitio.

3. ¿Qué ocurre si el nodo tiene solo hijo izquierdo?

Se aplica una rotación a la derecha: el hijo izquierdo sube y el nodo a eliminar desciende hacia la derecha.

4. ¿Qué ocurre si el nodo tiene solo hijo derecho?

Se realiza una rotación izquierda: el hijo derecho sube y el nodo a eliminar baja a la izquierda.

5. ¿Qué invariantes deben seguir siendo verdaderos después de `splice`?

La propiedad BST, la propiedad de heap por prioridad, los enlaces parent correctos, la raíz correcta y size() decreciendo en exactamente 1.

##### Parte D - Búsqueda ordenada en Treap

Extiende la demostración para probar:

```cpp
findEQ(40)
findEQ(35)
lowerBound(35)
lowerBound(40)
upperBound(40)
upperBound(75)
```

Compara los resultados con lo que produciría `BinarySearchTree` usando las mismas claves.

## Usando las claves {20, 30, 40, 50, 60, 70, 80}:

Operación       | Treap Result | BST Result
----------------|--------------|-----------
findEQ(40)      | 40           | 40
findEQ(35)      | nullptr      | nullptr
lowerBound(35)  | 40           | 40
lowerBound(40)  | 40           | 40
upperBound(40)  | 50           | 50
upperBound(75)  | 80           | 80

## Comparación Treap vs BinarySearchTree:

Propiedad mantenida | Treap | BinarySearchTree
-------------------|-------|-----------------
BST por clave      | Sí    | Sí
Heap por prioridad | Sí    | No
Operación eficiente | Búsqueda ordenada, inserción, eliminación con balanceo probabilístico | Búsqueda ordenada, inserción y eliminación sin balanceo
Operación que no conviene | Búsqueda ordenada sin balanceo garantizado | Búsqueda ordenada sin balanceo garantizado
Evidencia         | Mantiene orden inorden, pero estructura puede variar según prioridades | Mantiene orden inorden, estructura depende solo del orden de inserción

Responde:

1. ¿Por qué `lowerBound` y `upperBound` dependen de la propiedad BST y no de la propiedad heap?

Pues que buscan sucesores por llave. La prioridad sólo decide la forma vertical del árbol, pero no el orden semántico de las claves. El código de lowerBound va a la izquierda o a la derecha comparando claves, tal como en un BST.

2. ¿Qué parte del treap se comporta igual que un BST?

findEQ, lowerBound, upperBound y el recorrido inorden.

3. ¿Qué parte del treap se comporta como heap?

Relación padre-hijo sobre priority: cada padre debe tener prioridad menor o igual a sus hijos.

4. ¿Por qué el treap no reemplaza directamente a una cola de prioridad si lo único que quieres es extraer máximos o mínimos repetidamente?

Una cola de prioridad pura como PQ_ComplHeap está optimizada para getMax en O(1) y delMax en O(log n), por eso. El Treap guarda dos invariantes a la vez y tiene mayor overhead. Las prioridades además controlan la estructura del Treap, pero no se utilizan directamente para extraer el máximo por prioridad.

5. ¿En qué situación sí conviene usar una estructura tipo treap?.

Cuando requiere búsqueda ordenada (lowerBound, upperBound), inserción, eliminación y balance esperado sin implementar invariantes deterministas como AVL o Red-Black. Cuando el balance probabilístico es suficiente es adecuado.

##### Parte E - Pruebas específicas para Treap

Agrega o extiende pruebas para cubrir:

1. treap vacío: `empty()`, `size()`, `isBST()`, `isHeapByPriority()`, `isTreap()`,
2. inserción con prioridades fijas,
3. rechazo de duplicados,
4. inorden ordenado después de insertar,
5. propiedad heap por prioridad después de insertar,
6. `lowerBound` y `upperBound`,
7. eliminación de hoja,
8. eliminación de nodo con un hijo,
9. eliminación de nodo con dos hijos,
10. eliminación de raíz,
11. conservación de enlaces `parent`, si agregas una función pública de validación,
12. consistencia de `size()` después de operaciones mixtas,
13. estabilidad de invariantes después de una secuencia larga de inserciones y eliminaciones.

## Pruebas especificas para Treap:

```cpp
static void testBloque10TreapCompleto() {
    //treap vacio
    ods::Treap<int> empty;
    assert(empty.empty() && empty.size() == 0);
    assert(empty.isBST() && empty.isHeapByPriority() && empty.isTreap());

    //insercion con prioridades fijas
    ods::Treap<int> t(232);
    for (const auto& [k, p] : std::vector<std::pair<int,uint64_t>>{
            {50,50},{30,30},{70,70},{20,20},{40,40},{60,60},{80,80}})
        assert(t.addWithPriority(k, p));
    assert(t.size() == 7 && t.root()->key == 20);
    assert(t.isBST() && t.isHeapByPriority() && t.isTreap());

    //rechazo de duplicados
    assert(!t.addWithPriority(40, 5));
    assert(t.size() == 7);

    //inorden ordenado
    assert((t.inorderKeys() == std::vector<int>{20,30,40,50,60,70,80}));

    //eliminaciones
    assert(t.remove(80) && t.size() == 6 && t.isTreap());
    assert(t.remove(70) && t.size() == 5 && t.isTreap());
    assert(t.remove(t.root()->key) && t.size() == 4 && t.isTreap());
}
```

Responde:

1. ¿Qué bug atraparía una prueba de enlaces `parent`?

Rotaciones que actualizan left y right pero olvidan corregir el puntero parent del nodo que ascendió o descendió.

2. ¿Qué bug atraparía una prueba de `size()`?

Aumento de dos unidades al insertar duplicados (que deberían rechazarse) o falta de decremento al eliminar.

3. ¿Qué bug atraparía una prueba de inorden ordenado?

Errores en la lógica de inserción del BST, o en las rotaciones que mueven sub-árboles al lado equivocado.

4. ¿Qué bug atraparía una prueba de prioridad padre-hijo?

Fallos en bubbleUp, fallos en la elección del hijo en trickleDown, o rotaciones incompletas que dejan un hijo con prioridad menor que su padre.

5. ¿Por qué conviene usar prioridades fijas en pruebas unitarias?

Pues hacen que el árbol final sea determinista. Es posible determinar con exactitud cuál es la raíz, el inorden, cuántas rotaciones se harán y el resultado de cada operación, de forma independiente del generador aleatorio.

#### Bloque 11 - Comparación con Semana 5: `BinaryHeap`, `BinarySearchTree` y `Treap`

Revisa:

- `Semana5/include/BinaryHeap.h`
- `Semana5/include/BinarySearchTree.h`
- `Semana6/include/PQ_ComplHeap.h`
- `Semana6/include/Treap.h`
- `Semana6/demos/demo_compare_with_semana5.cpp`
- `Semana6/demos/demo_treap_basico.cpp`

Modifica `demo_compare_with_semana5.cpp` para construir una comparación observable entre:

1. `BinaryHeap` de Semana 5,
2. `PQ_ComplHeap` de Semana 6,
3. `BinarySearchTree` de Semana 5,
4. `Treap` de Semana 6.

La demostración debe mostrar una tabla con columnas:

- estructura,
- operación principal,
- propiedad mantenida,
- operación eficiente,
- operación que no conviene,
- evidencia producida por la demostración.

## Tabla de comparación:
Estructura         | Operación principal | Propiedad mantenida | Operación eficiente | Operación que no conviene | Evidencia
-------------------|---------------------|---------------------|---------------------|---------------------------|---------
BinaryHeap         | delMax              | Propiedad heap      | getMax O(1), delMax O(log n) | Búsqueda ordenada O(n) | Árbol completo, no ordenado
PQ_ComplHeap       | delMax              | Propiedad heap      | getMax O(1), delMax O(log n) | Búsqueda ordenada O(n) | Árbol completo, no ordenado
BinarySearchTree   | lowerBound/upperBound | Propiedad BST       | lowerBound/upperBound O(log n) | delMax O(n) | Árbol ordenado, no balanceado
Treap              | lowerBound/upperBound | Propiedad BST + heap por prioridad | lowerBound/upperBound O(log n) con balance probabilístico | delMax O(n) en peor caso | Árbol ordenado, balance probabilístico

Responde:

1. ¿Qué diferencia hay entre un heap de prioridad y un árbol de búsqueda?

Un heap de prioridad garantiza que la raíz sea el máximo (o mínimo), pero no permite recorrido ordenado ni búsqueda eficiente por clave arbitraria. 
Un árbol de búsqueda permite encontrar cualquier clave en O(h) y recorrer todas las claves en orden, pero no garantiza que la raíz sea el máximo.

2. ¿Por qué un BST permite recorrido ordenado y un heap no?

Porque en un BST las claves del subárbol izquierdo son siempre menores y las del derecho siempre mayores. El recorrido inorden visita las claves de forma ascendente. En un heap, lo único que se garantiza es que el padre domina a sus hijos, no hay ninguna relación entre el subárbol izquierdo y el derecho que permita un recorrido ordenado directo.

3. ¿Qué agrega `PQ_ComplHeap` frente a un `BinaryHeap` educativo?

PQ_ComplHeap tiene un comparador genérico (no sólo int), implementa la interfaz abstracta PQ<T>, separa las operaciones en archivos por responsabilidad, incluye heapify de Floyd eficiente y tiene funciones auxiliares constexpr en vez de aritmética repetida directamente en el código.

4. ¿Qué combina un `Treap`?

Junta la propiedad BST en claves (permite búsqueda ordenada) con la propiedad heap en prioridades (prioridades aleatorias dan equilibrio esperado logarítmico).

5. ¿Qué estructura usarías para extraer máximos repetidamente?

PQ_ComplHeap o PQ_LeftHeap. Están optimizadas exactamente para ese caso.

6. ¿Qué estructura usarías para responder `lowerBound` o `upperBound`?

BinarySearchTree o Treap, ambas dependen de la propiedad BST para esas operaciones.

7. ¿Qué estructura usarías si quieres búsqueda ordenada con balanceo probabilístico?.

Treap ya que ofrece búsqueda ordenada como un BST y balance esperado por las prioridades aleatorias, evitando la complejidad de implementar AVL o Red-Black.

#### Bloque 12 - Pruebas obligatorias después de modificar código

Debes agregar o extender pruebas en:

- `Semana6/pruebas_publicas/test_public_week6.cpp`
- `Semana6/pruebas_internas/test_internal_week6.cpp`

Incluye al menos las siguientes pruebas:

1. `PQ_ComplHeap` conserva la propiedad heap después de cada inserción.
2. `PQ_ComplHeap` conserva la propiedad heap después de cada eliminación.
3. `getMax` no cambia el tamaño.
4. `delMax` sí cambia el tamaño.
5. `heapifyFloyd` produce un heap válido.
6. `heapSort` ordena con repetidos.
7. `PQ_LeftHeap` conserva su propiedad después de `merge`.
8. `PQ_LeftHeap` conserva su propiedad después de `insert`.
9. `PQ_LeftHeap` conserva su propiedad después de `delMax`.
10. Huffman produce códigos para todos los símbolos con frecuencia positiva.
11. Huffman produce códigos libres de prefijos.
12. Huffman maneja correctamente el caso de un solo símbolo.
13. `Treap` conserva propiedad BST después de insertar.
14. `Treap` conserva propiedad de heap por prioridad después de insertar.
15. `Treap` conserva ambas propiedades después de eliminar.

Entrega en este bloque:

- Lista de pruebas agregadas.
- Resultado completo de `ctest --output-on-failure`.
- Explicación de qué bug atraparía cada prueba.

## Lista de pruebas agregadas:
1. testPQComplHeapInsertPreservesHeap
2. testPQComplHeapDelMaxPreservesHeap
3. testPQComplHeapGetMaxDoesNotChangeSize
4. testPQComplHeapDelMaxChangesSize
5. testHeapifyFloydProducesValidHeap
6. testHeapSortWithDuplicates
7. testPQLeftHeapMergePreservesProperty
8. testPQLeftHeapInsertPreservesProperty
9. testPQLeftHeapDelMaxPreservesProperty
10. testHuffmanCodesForPositiveFrequency
11. testHuffmanCodesArePrefixFree
12. testHuffmanSingleSymbol
13. testTreapPreservesBSTAfterInsert
14. testTreapPreservesHeapAfterInsert

#### Bloque 13 - Defensa escrita de modificaciones

Responde en no más de 900 palabras:

¿Qué aprendiste al modificar código de prioridad, heaps, Huffman y Treap que no se aprende solo leyendo o ejecutando demostraciones?

Modificar el código enseña cosas que leer o ejecutar demos no demuestra. La interfaz PQ separa qué hace una cola de prioridad de cómo lo hace, lo que permite que PQ_ComplHeap y PQ_LeftHeap sean intercambiables dentro de Huffman sin tener que cambiar la lógica del algoritmo. Usar un vector para almacenar el heap implícitamente elimina los punteros, pero introduce silenciosos errores de índice: un acceso fuera de rango no devuelve null, sino un valor erróneo que pasa desapercibido sin función de verificación explícita.

Al implementar percolateUp y percolateDown se comprueba algo que no resulta obvio en el papel: la mayoría de operaciones hacen uno o dos intercambios, no O(log n). El peor caso existe, pero es raro. Floyd es más eficiente que insertar uno por uno no por una mejor constante, sino porque la suma de trabajo de nodos cerca de las hojas es pequeña en términos absolutos, dando O(n) frente a O(n log n). heapSort se vale de esto y ordena destruyendo el heap de forma controlada: cada extracción fija el máximo al final del rango activo, sin espacio auxiliar pero tampoco estabilidad.

En el heap izquierdista, reducir insert y delMax a casos de merge no es elegancia vacía: un error en mergeNodes rompe todo al mismo tiempo. La propiedad izquierdista existe para mantener el camino derecho corto y hacer merge eficiente. En Huffman, el desempate entre símbolos de igual frecuencia no cambia el costo óptimo pero sí hace el árbol determinístico; el caso de un solo símbolo es el único donde se debe asignar un código manualmente porque el árbol no tiene ramas. El Treap combina BST y heap en la misma estructura con la ayuda de las rotaciones: ellas mueven el balance vertical, sin romper el orden horizontal de las claves. Escribir bubbleUpCount y trickleDownCount confirma que las rotaciones por operación son pocas en la práctica. 

Por último, BinaryHeap y BinarySearchTree de Semana 5 resuelven problemas distintos y no se reemplazan entre sí. PQ_ComplHeap extiende BinaryHeap con interfaz genérica, Treap extiende BinarySearchTree con balance probabilístico. Las pruebas con invariantes completos son lo que convierte esta diferencia conceptual en algo verificable: una prueba que falle después de delMax captura el error antes de que se propague a una operación posterior donde la fuente ya no es rastreable.
