### Actividad 5 - CC232

- Duración: 3 horas de clase.
- Modalidad: Trabajo individual.
- Entrega: Un archivo llamado `Actividad5-CC232.md`.

#### Objetivo

Consolidar lo trabajado en la Semana 5 a partir de lectura de código, ejecución de demos, revisión de pruebas, trazado manual y defensa escrita breve.

La meta es distinguir con claridad tres niveles de trabajo con árboles:

1. La infraestructura enlazada base: `BinNode` y `BinTree`.
2. La navegación y los recorridos de un árbol binario: `BinaryTree`, sucesor, predecesor, profundidad, altura, tamaño de subárbol e iteración inorden.
3. Las estructuras especializadas de la semana: `BinarySearchTree` y `BinaryHeap`.

Además, se busca conectar la implementación de la semana con las ideas de Morin y Deng: árboles binarios enlazados, mantenimiento de alturas, recorridos recursivos e iterativos, sucesor inorden, recorrido por niveles, representación implícita de heaps, búsqueda en BST, eliminación, `splice`, rotaciones y validación de invariantes.

#### Material de trabajo

##### Código de la semana

- `Semana5/README.md`
- `Semana5/include/BinNode.h`
- `Semana5/include/BinTree.h`
- `Semana5/include/BinaryTree.h`
- `Semana5/include/BinarySearchTree.h`
- `Semana5/include/BinaryHeap.h`
- `Semana5/include/Capitulo5.h`
- `Semana5/demos/demo_binary_tree.cpp`
- `Semana5/demos/demo_bst.cpp`
- `Semana5/demos/demo_heap.cpp`
- `Semana5/demos/demo_capitulo5_panorama.cpp`
- `Semana5/pruebas_publicas/test_public_week5.cpp`
- `Semana5/pruebas_internas/test_internal_week5.cpp`
- `Semana5/lecturas/Notas.md`
- `Semana5/Ejercicios5-CC232.md`

##### Lecturas obligatorias

- Lectura de Deng asociadas a `BinNode`, `BinTree`, mantenimiento de alturas, recorridos, sucesor inorden y recorrido por niveles dado en el repositorio.
- Secciones de Morin asociadas a `BinaryTree`, `BinaryHeap` y `BinarySearchTree` dado en el repositorio.

#### Bloque 1 - Núcleo conceptual de la semana

Revisa:

- `Semana5/README.md`
- `Semana5/lecturas/Notas.md`
- `Semana5/include/BinNode.h`
- `Semana5/include/BinTree.h`
- `Semana5/include/BinaryTree.h`
- `Semana5/include/BinarySearchTree.h`
- `Semana5/include/BinaryHeap.h`

Responde:

1. Explica con tus palabras qué diferencia hay entre un árbol binario enlazado y un árbol binario almacenado implícitamente en un arreglo.

Un árbol binario enlazado usa la estructura de listas usando punteros (left right padre) y nodos; sin embargo; un árbol binario almacenado en arreglo usa memoria contigua donde la posición de cada elemento en el árbol se determina por medio de una fórmula matemática(2i+1,2i-1).

2. Explica qué información guarda un `BinNode`: dato, padre, hijo izquierdo, hijo derecho y altura.

Dato: Guarda el valor que es de tipo genérico
Parent: Dirección de memoria del nodo padre
Hijo izquierdo: Dirección del hijo izquierdo
Hijo derecho: Dirección del hijo derecho , si no existen pueden llegar a ser nullptr
Altura: Entero que indica la altura del subárbol que tiene debajo, puede ser 0 si es hoja

3. Explica por qué el puntero `parent` permite implementar operaciones como `succ()`, `pred()` y actualización ascendente de alturas.

Porque gracias a parent podemos subir por el árbol permitiendo así hacer diferentes recorridos, sin parent el árbol solo bajaría.

4. Explica qué responsabilidad tiene `BinTree` frente a `BinNode`.

BinTree es el gestor del árbol, controla la raíz, el tamaño y se encarga de donde y cuando se inserta un nodo, BinNode solo sabe crear y conectar nodos localmente mientras que BinTree decide si la operación es valida y la actualiza.

Bintree guarda la raiz, el tamaño del árbol, se encarga de actualizar alturas, insertar nodos(attach), eliminar nodos(removeSubTree), adjuntar subárboles y separar subárboles. BinNode solo sabe crear nodos y conectarlos localmente.

5. Explica qué agrega `BinaryTree` sobre la infraestructura base de `BinTree`.

BinaryTree agrega navegación y consulta sobre la estructura (depth, height, subtreeSize, firstNode, lastNode). Es una capa de utilidades encima de BinTree que no modifica el árbol, solo lo consulta.

6. Explica qué propiedad adicional convierte un árbol binario en un `BinarySearchTree`.

BinarySearchTree hereda de BinaryTree y agrega propiedades de orden estableciendo que para cada nodo, todo lo del subárbol izquierdo es menor y todo lo de su subárbol derecho es mayor lo que lo convierte en una estructura para busqueda eficiente y muy rápida. Sin esa invariante, funciones como succ() y pred() no funcionarían correctamente porque toda su lógica asume que izquierda es menor y derecha es mayor.

7. Explica qué propiedad adicional convierte un arreglo en un `BinaryHeap` mínimo.

La propiedad heap agrega la propiedad de que el padre sea menor al hijo.

8. Compara la propiedad de orden de un BST con la propiedad de prioridad de un heap.



9. Explica por qué un recorrido inorden de un BST produce una secuencia ordenada.

Porque inorden visita en orden izquierda -> yo -> derecha, y la propiedad del BST garantiza que todo lo de la izquierda es menor que yo y todo lo de la derecha es mayor. Entonces al seguir ese orden de visita, primero se procesan todos los menores, luego yo, luego todos los mayores y esto se cumple recursivamente en cada nodo del árbol. El resultado es que los valores salen de menor a mayor inevitablemente, no por casualidad sino porque el orden de visita coincide exactamente con la propiedad de orden del BST.

10. Explica por qué un heap no permite, por sí solo, recorrer los elementos en orden sin destruir o copiar la estructura.




#### Bloque 2 - Navegación, altura, profundidad y tamaño

Revisa:

- `Semana5/include/BinNode.h`
- `Semana5/include/BinTree.h`
- `Semana5/include/BinaryTree.h`
- `Semana5/demos/demo_binary_tree.cpp`

Responde:

1. En `BinNode`, explica qué significan `hasLeft()`, `hasRight()`, `isRoot()`, `isLeaf()`, `isLeftChild()` e `isRightChild()`.

Son métodos de consulta que devuelven un booleano indicando si el nodo tiene hijo izquierdo, derecho, si es la raíz, si es hoja, si es hijo izquierdo o derecho respectivamente. Son atajos para evitar escribir condiciones más complejas cada vez que se necesite esa información.

2. Explica el caso en que `succ()` baja al subárbol derecho y luego busca el nodo más a la izquierda.

El caso de if (hasRight()) es el caso más común, se baja al hijo derecho y luego se sigue bajando por la izquierda hasta llegar a un nodo que no tenga hijo izquierdo. Ese nodo es el sucesor inorden porque es el siguiente nodo en la secuencia ordenada del BST después del nodo actual. Es decir, es el menor de los mayores.

3. Explica el caso en que `succ()` sube por los ancestros hasta encontrar el primer giro hacia la izquierda.

El caso de while (isRightChild()) es el caso en que el nodo actual no tiene hijo derecho, entonces el sucesor inorden no está en su subárbol derecho sino que está más arriba. Se sube por los ancestros mientras se esté subiendo por la rama derecha, porque eso significa que todavía no hemos pasado al siguiente nodo en orden. El primer giro hacia la izquierda indica que hemos pasado del lado derecho de un nodo a su padre, lo que significa que ese padre es el siguiente nodo en orden después del nodo original.

4. Explica simétricamente cómo debe funcionar `pred()`.

Empieza con if (hasLeft()) y baja al hijo izquierdo y luego sigue bajando por la derecha hasta llegar a un nodo sin hijo derecho, ese nodo es el predecesor inorden porque es el mayor de los menores. 

Si no tiene hijo izquierdo, entonces sube por los ancestros mientras se esté subiendo por la rama izquierda, el primer giro hacia la derecha indica que hemos pasado del lado izquierdo de un nodo a su padre, lo que significa que ese padre es el nodo anterior en orden antes del nodo original.

5. Dibuja un árbol de al menos 7 nodos y marca el sucesor y predecesor inorden de tres nodos distintos.

       20
   10        30
 5    15   25   35

Sucesor de 10: va a su hijo derecho 15, como 15 no tiene hijo izquierdo, el sucesor es 15.

Succesor de 15: 20 como es hijo derecho, sube a 10 y como 10 es hijo izquierdo de 20, se devuelve el padre.

Predecesor de 30: baja al hijo izquierdo 25, como no tiene hijo derecho, el predecesor es 25.

Predecesor de 25: no tiene hijo izquierdo, entonces sube a 30, como 25 es hijo izquierdo de 30, sigue subiendo y como 30 es hijo derecho de 20, el predecesor es 20.

6. Explica qué calcula `depth(u)` y por qué puede implementarse subiendo por `parent`.

Calcula la profundidad de un nodo. Se implementa con parent porque la profundidad se define como la cantidad de aristas desde el nodo hasta la raíz, entonces se puede contar cuántos pasos se necesitan para subir desde el nodo hasta llegar a un nodo que sea raíz (que no tenga parent).

7. Explica qué calcula `height(u)` y por qué suele implementarse bajando recursivamente por los hijos.

Mira hacia abajo y calcula el camino más largo desde el nodo hasta una hoja. Se implementa bajando recursivamente porque la altura de un nodo depende de la altura de sus hijos, entonces se necesita conocer la altura de los hijos para calcular la altura del nodo actual. Es un proceso que naturalmente se resuelve con recursión hacia abajo.

8. Explica qué calcula `subtreeSize(u)`.



9. Demuestra que para todo nodo `u` se cumple `depth(u) + height(u) <= height(T)`.



10. Indica la condición necesaria y suficiente para que se alcance la igualdad anterior.



#### Bloque 3 - Recorridos y trazado guiado

Revisa:

- `Semana5/include/BinNode.h`
- `Semana5/include/BinTree.h`
- `Semana5/demos/demo_binary_tree.cpp`
- `Semana5/demos/demo_capitulo5_panorama.cpp`

Construye una tabla con cinco columnas:

- Recorrido
- Versión revisada
- Estructura auxiliar usada
- Secuencia producida en el árbol de prueba
- Argumento de correctitud y costo

Incluye en la tabla:

- preorden recursivo,
- preorden iterativo,
- inorden recursivo,
- inorden iterativo `#1`,
- inorden iterativo `#2`,
- inorden iterativo `#3`,
- postorden recursivo,
- postorden iterativo,
- recorrido por niveles.

Luego responde:

1. ¿Qué significa visitar un nodo en preorden?

Un nodo en preorden es un nodo que se visita antes de visitar sus hijos. 

El orden de visita es: Nodo -> Hijo izquierdo -> Hijo derecho

2. ¿Qué significa visitar un nodo en inorden?

Visitar en inorden significa visitar el nodo después de visitar su hijo izquierdo pero antes de visitar su hijo derecho. 
Está en el codigo BinNode::inorder() y se implementa con la lógica de visitar el nodo entre las llamadas recursivas a los hijos en la linea numero 

El orden de visita es: hijo izquierdo -> nodo -> hijo derecho

3. ¿Qué significa visitar un nodo en postorden?

Visitar en postorden significa visitar el nodo después de visitar ambos hijos.

El orden de visita es: hijo izquierdo -> hijo derecho -> nodo

4. ¿Qué significa visitar un árbol por niveles?

Significa visitar los nodos del árbol nivel por nivel, de izquierda a derecha. (BFS)

5. ¿Por qué los recorridos recursivos tienen tiempo `O(n)`?

Porque se visita cada nodo exactamente una vez, y el trabajo que se hace en cada nodo (imprimir, procesar, etc.) es constante. La recursión simplemente organiza la forma en que se visitan los nodos, pero el número total de visitas es igual al número de nodos en el árbol, lo que da un tiempo lineal O(n).

6. ¿Por qué las versiones iterativas también tienen tiempo `O(n)`?



7. ¿Cuál es la memoria auxiliar de un recorrido recursivo en un árbol balanceado?



8. ¿Cuál es la memoria auxiliar de un recorrido recursivo en un árbol degenerado?



9. ¿Qué diferencia hay entre usar una pila explícita y usar la pila de llamadas?



10. ¿Por qué la cola del recorrido por niveles puede crecer mucho más en un árbol completo que en un árbol degenerado?.



#### Bloque 4 - Demostración: evidencia observable

Revisa y ejecuta:

- `Semana5/demos/demo_binary_tree.cpp`
- `Semana5/demos/demo_bst.cpp`
- `Semana5/demos/demo_heap.cpp`
- `Semana5/demos/demo_capitulo5_panorama.cpp`

Construye una tabla con cuatro columnas:

- Archivo
- Salida u observable importante
- Idea estructural
- Argumento de costo, espacio o diseño

Luego responde:

1. En `demo_binary_tree.cpp`, ¿qué salida permite verificar que los recorridos visitan los nodos en el orden esperado?
2. ¿Qué parte de la demo permite defender que `succ()` y `pred()` respetan el orden inorden?
3. ¿Qué evidencia produce la representación ASCII del árbol?
4. En `demo_bst.cpp`, ¿qué observable permite defender que el inorden del BST queda ordenado?
5. ¿Qué operaciones de búsqueda se distinguen mejor en la demo del BST: `find`, `findEQ`, `lowerBound` o `upperBound`?
6. En `demo_heap.cpp`, ¿qué salida permite defender que el mínimo queda en la raíz?
7. ¿Qué evidencia permite distinguir entre insertar con `add()` y construir con `heapify()`?
8. En `demo_capitulo5_panorama.cpp`, ¿qué comparación resume mejor la semana: árbol enlazado, BST o heap?.

#### Bloque 5 - Pruebas públicas, pruebas internas e invariantes

Revisa:

- `Semana5/pruebas_publicas/test_public_week5.cpp`
- `Semana5/pruebas_internas/test_internal_week5.cpp`

Responde:

1. ¿Qué operaciones del BST valida la prueba pública?
2. ¿Qué casos validan que el BST no acepta duplicados?
3. ¿Qué se verifica al comparar el inorden recursivo con las versiones iterativas?
4. ¿Qué se espera de `findEQ(8)` en la prueba pública?
5. ¿Qué se espera de `lowerBound(9)` y `upperBound(8)`?
6. ¿Qué propiedad se valida con `isBST()`?
7. ¿Qué se valida después de eliminar un nodo con `remove()`?
8. ¿Qué valida `checkParentLinks()` después de borrar, separar o adjuntar subárboles?
9. ¿Qué operaciones del heap valida la prueba pública?
10. ¿Qué demuestra extraer repetidamente de un min-heap hasta vaciarlo?
11. ¿Qué operaciones de `BinTree` se validan con `attachAsRC`, `secede` y `removeSubtree`?
12. ¿Qué agregan las pruebas internas respecto a rotaciones, `bubbleUp`, `trickleDown`, profundidad, altura, sucesor y predecesor?
13. ¿Qué sí demuestra pasar las pruebas públicas?
14. ¿Qué no demuestra pasar las pruebas públicas?
15. ¿Por qué una defensa correcta debe mencionar invariantes y complejidad además de resultados observables?.


#### Bloque 6 - Lectura cercana: `BinNode`, `BinTree` y `BinaryTree`

Revisa:

- `Semana5/include/BinNode.h`
- `Semana5/include/BinTree.h`
- `Semana5/include/BinaryTree.h`

Responde:

1. En `BinNode`, ¿qué invariantes deben mantenerse entre `parent`, `left` y `right`?
2. ¿Por qué `insertAsLC` e `insertAsRC` deben rechazar una inserción cuando el hijo correspondiente ya existe?
3. Explica cómo `size()` de `BinNode` recorre el subárbol.
4. Explica cómo funcionan `leftmost()` y `rightmost()`.
5. Explica paso a paso cómo funciona `succ()`.
6. Explica paso a paso cómo funciona `pred()`.
7. En `BinTree`, ¿qué papel cumplen `root_` y `size_`?
8. Explica qué hace `updateHeight(Node*)`.
9. Explica qué hace `updateHeightAbove(Node*)` y por qué sube hacia la raíz.
10. Explica cómo `attachAsLC` o `attachAsRC` transfieren un subárbol desde un árbol hacia otro.
11. Explica qué diferencia hay entre `removeSubtree` y `secede`.
12. Explica por qué `secede` no debe destruir los nodos desprendidos.
13. Explica por qué `removeSubtree` sí debe liberar nodos.
14. Explica qué verifica `checkParentLinks()`.
15. En `BinaryTree`, explica cómo se implementan `firstNode`, `lastNode`, `nextNode` y `prevNode`.
16. Explica por qué un iterador basado en `succ()` produce recorrido inorden.
17. Explica qué aporta `asciiArt()` para depuración y sustentación.


#### Bloque 7 - Árbol binario de búsqueda: búsqueda, eliminación y rotaciones

Revisa:

- `Semana5/include/BinarySearchTree.h`
- `Semana5/demos/demo_bst.cpp`
- `Semana5/pruebas_publicas/test_public_week5.cpp`
- `Semana5/pruebas_internas/test_internal_week5.cpp`

Responde:

1. Define formalmente la propiedad BST.
2. Explica por qué el recorrido inorden de un BST debe producir una secuencia no decreciente.
3. Explica la diferencia entre `find`, `findEQ`, `lowerBound` y `upperBound`.
4. Explica por qué `findEQ(x)` puede fallar aunque `lowerBound(x)` no falle.
5. Construye manualmente el BST que se obtiene al insertar: `7, 3, 10, 1, 5, 8, 12, 4, 6`.
6. Escribe el inorden, preorden, postorden y recorrido por niveles de ese árbol.
7. Simula `lowerBound(9)` y `upperBound(8)` paso a paso.
8. Explica qué casos de eliminación existen en un BST: hoja, un hijo, dos hijos.
9. Explica qué papel cumple `splice` durante una eliminación.
10. Después de eliminar una clave, ¿qué invariantes deben seguir siendo ciertos?
11. Explica por qué `remove(3)` en las pruebas debe conservar el inorden ordenado.
12. Explica qué hace `rotateLeft`.
13. Explica qué hace `rotateRight`.
14. Demuestra que una rotación local preserva la propiedad BST.
15. Explica para qué sirve construir un BST balanceado desde un arreglo ordenado.
16. Compara el costo de búsqueda en un BST balanceado y en un BST degenerado.


#### Bloque 8 - Heap binario y representación implícita

Revisa:

- `Semana5/include/BinaryHeap.h`
- `Semana5/demos/demo_heap.cpp`
- `Semana5/pruebas_publicas/test_public_week5.cpp`
- `Semana5/pruebas_internas/test_internal_week5.cpp`

Responde:

1. Explica por qué un heap binario puede almacenarse en un `std::vector` sin punteros.
2. Demuestra las fórmulas:

   ```cpp
   left(i) = 2*i + 1
   right(i) = 2*i + 2
   parent(i) = (i - 1) / 2
   ```

3. Define la propiedad de min-heap.
4. Explica por qué `top()` devuelve el mínimo.
5. Explica paso a paso cómo `bubbleUp(i)` restaura la propiedad de heap después de insertar.
6. Explica paso a paso cómo `trickleDown(i)` restaura la propiedad de heap después de eliminar la raíz.
7. Explica por qué `remove()` debe mover el último elemento a la raíz antes de aplicar `trickleDown(0)`.
8. Explica qué verifica `isHeap()`.
9. Compara construir un heap insertando `n` elementos con construirlo usando `heapify()`.
10. Justifica por qué insertar `n` elementos uno por uno cuesta `O(n log n)` en el peor caso.
11. Justifica por qué `heapify()` puede ejecutarse en `O(n)`.
12. Ejecuta una extracción completa del heap construido con `{7, 3, 10, 1, 5, 8, 2}` y explica por qué la secuencia extraída sale ordenada.
13. Compara el heap con el BST: ¿cuál estructura conviene para consultar mínimo repetidamente y cuál conviene para búsquedas ordenadas?.


#### Bloque 9 - Cierre comparativo y preparación de sustentación

Responde esta pregunta final:

¿Qué cambia cuando pasamos de estudiar listas, pilas y colas a diseñar árboles binarios, heaps y árboles binarios de búsqueda?

La respuesta debe incluir obligatoriamente:

- Una afirmación sobre representación enlazada con nodos y punteros.
- Una afirmación sobre representación implícita en arreglo.
- Una afirmación sobre la diferencia entre propiedad estructural y propiedad de orden.
- Una afirmación sobre recorridos y por qué son una forma de convertir un árbol en una secuencia.
- Una afirmación sobre mantenimiento de alturas y enlaces `parent`.
- Una afirmación sobre BST, búsqueda ordenada y recorrido inorden.
- Una afirmación sobre heap, prioridad y costo de `add`, `remove` y `heapify`.
- Una afirmación sobre qué evidencia usarías para defender correctitud: pruebas, demos, invariantes, trazados y complejidad.

#### Formato sugerido de entrega

```markdown
## Actividad 5 - CC232

### Estudiante

- Nombre:

### Bloque 1 - Núcleo conceptual

[Respuestas]

### Bloque 2 - Navegación, altura, profundidad y tamaño

[Respuestas y dibujos]

### Bloque 3 - Recorridos y trazado guiado

[Tabla y respuestas]

### Bloque 4 - Demos

[Tabla y respuestas]

### Bloque 5 - Pruebas e invariantes

[Respuestas]

### Bloque 6 - Lectura cercana de código

[Respuestas]

### Bloque 7 - BST

[Respuestas, trazados y argumentos]

### Bloque 8 - Heap

[Respuestas, trazados y argumentos]

### Bloque 9 - Cierre comparativo

[Respuesta final]

### Autoevaluación breve

- Qué puedo defender con seguridad:
- Qué todavía confundo:
- Qué evidencia usaría en una sustentación:
- Qué parte del código me parece más importante para revisar otra vez:
```

#### Criterio general de trabajo

Se espera lectura real de los archivos, respuestas breves pero justificadas, tablas con evidencia observable, trazados manuales y conexión explícita entre código, correctitud, costo, representación e invariantes.

No basta con ejecutar el programa: debes poder explicar por qué funciona, qué punteros se actualizan, qué propiedad mantiene cada estructura, qué costo tiene cada operación y qué evidencia usarías para defenderlo oralmente.
