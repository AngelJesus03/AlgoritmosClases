### Actividad 5 - CC232

- Duración: 3 horas de clase.
- Modalidad: Trabajo individual.
- Entrega: Un archivo llamado `Actividad5-CC232.md`.

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

Un árbol binario enlazado usa la estructura de listas usando punteros (left right padre) y nodos; sin embargo; un árbol 
binario almacenado en arreglo usa memoria contigua donde la posición de cada elemento en el árbol se determina por medio 
de una fórmula matemática(2i+1,2i-1).

2. Explica qué información guarda un `BinNode`: dato, padre, hijo izquierdo, hijo derecho y altura.

Dato: Guarda el valor que es de tipo genérico
Parent: Dirección de memoria del nodo padre
Hijo izquierdo: Dirección del hijo izquierdo
Hijo derecho: Dirección del hijo derecho , si no existen pueden llegar a ser nullptr
Altura: Entero que indica la altura del subárbol que tiene debajo, puede ser 0 si es hoja

3. Explica por qué el puntero `parent` permite implementar operaciones como `succ()`, `pred()` y actualización ascendente 
de alturas.

Porque gracias a parent podemos subir por el árbol permitiendo así hacer diferentes recorridos, sin parent el árbol solo 
bajaría.

4. Explica qué responsabilidad tiene `BinTree` frente a `BinNode`.

BinTree es el gestor del árbol, controla la raíz, el tamaño y se encarga de donde y cuando se inserta un nodo, BinNode 
solo sabe crear y conectar nodos localmente mientras que BinTree decide si la operación es valida y la actualiza.

Bintree guarda la raiz, el tamaño del árbol, se encarga de actualizar alturas, insertar nodos(attach), eliminar nodos
(removeSubTree), adjuntar subárboles y separar subárboles. BinNode solo sabe crear nodos y conectarlos localmente.

5. Explica qué agrega `BinaryTree` sobre la infraestructura base de `BinTree`.

BinaryTree agrega navegación y consulta sobre la estructura (depth, height, subtreeSize, firstNode, lastNode). Es una 
capa de utilidades encima de BinTree que no modifica el árbol, solo lo consulta.

6. Explica qué propiedad adicional convierte un árbol binario en un `BinarySearchTree`.

BinarySearchTree hereda de BinaryTree y agrega propiedades de orden estableciendo que para cada nodo, todo lo del 
subárbol izquierdo es menor y todo lo de su subárbol derecho es mayor lo que lo convierte en una estructura para busqueda 
eficiente y muy rápida. Sin esa invariante, funciones como succ() y pred() no funcionarían correctamente porque toda su 
lógica asume que izquierda es menor y derecha es mayor.

7. Explica qué propiedad adicional convierte un arreglo en un `BinaryHeap` mínimo.

La propiedad de heap mínimo exige que para todo nodo en índice i, el valor en i sea menor o igual al valor de sus hijos 
en 2i+1 y 2i+2. Esto garantiza que el mínimo global siempre esté en el índice 0, no se exige ningún orden entre los 
elementos de un mismo nivel ni entre subárboles distintos solo importa la relación padre e hijo.

8. Compara la propiedad de orden de un BST con la propiedad de prioridad de un heap.

La propiedad BST es una propiedad de orden total que dice establecer una relación de orden entre izquierda, nodo y 
derecha que permite buscar cualquier valor en O(h) y recorrer todos los valores en orden sin destruir la estructura. 

La propiedad heap es una propiedad de prioridad local que solo garantiza que el padre es menor que sus hijos, lo que 
permite acceder al mínimo en O(1) y extraerlo en O(log n), pero no permite buscar un valor arbitrario sin recorrer casi 
todo el árbol, ni recorrer los elementos en orden sin destruir la estructura.

9. Explica por qué un recorrido inorden de un BST produce una secuencia ordenada.

Porque inorden visita en orden izquierda -> yo -> derecha, y la propiedad del BST garantiza que todo lo de la izquierda 
es menor que yo y todo lo de la derecha es mayor. Entonces al seguir ese orden de visita, primero se procesan todos los 
menores, luego yo, luego todos los mayores y esto se cumple recursivamente en cada nodo del árbol. El resultado es que 
los valores salen de menor a mayor inevitablemente, no por casualidad sino porque el orden de visita coincide exactamente 
con la propiedad de orden del BST.

10. Explica por qué un heap no permite, por sí solo, recorrer los elementos en orden sin destruir o copiar la estructura.

El heap solo garantiza que cada padre es menor que sus hijos, pero no establece ningún orden entre los elementos de un 
mismo nivel ni entre ramas distintas. Para extraer el mínimo se hace remove, que destruye la posición del elemento en la 
estructura y reorganiza el heap. Si se quieren todos los elementos en orden es necesario extraerlos uno por uno, lo que 
vacía el heap, o hacer una copia antes de recorrer, no existe una forma de navegar el heap en orden sin alterar su estado.

#### Bloque 2 - Navegación, altura, profundidad y tamaño

Revisa:

- `Semana5/include/BinNode.h`
- `Semana5/include/BinTree.h`
- `Semana5/include/BinaryTree.h`
- `Semana5/demos/demo_binary_tree.cpp`

Responde:

1. En `BinNode`, explica qué significan `hasLeft()`, `hasRight()`, `isRoot()`, `isLeaf()`, `isLeftChild()` e `isRightChild
()`.

Son métodos de consulta que devuelven un booleano indicando si el nodo tiene hijo izquierdo, derecho, si es la raíz, si 
es hoja, si es hijo izquierdo o derecho respectivamente. Son atajos para evitar escribir condiciones más complejas cada 
vez que se necesite esa información.

2. Explica el caso en que `succ()` baja al subárbol derecho y luego busca el nodo más a la izquierda.

El caso de if (hasRight()) es el caso más común, se baja al hijo derecho y luego se sigue bajando por la izquierda hasta 
llegar a un nodo que no tenga hijo izquierdo. Ese nodo es el sucesor inorden porque es el siguiente nodo en la secuencia 
ordenada del BST después del nodo actual. Es decir, es el menor de los mayores.

3. Explica el caso en que `succ()` sube por los ancestros hasta encontrar el primer giro hacia la izquierda.

El caso de while (isRightChild()) es el caso en que el nodo actual no tiene hijo derecho, entonces el sucesor inorden no 
está en su subárbol derecho sino que está más arriba. Se sube por los ancestros mientras se esté subiendo por la rama 
derecha, porque eso significa que todavía no hemos pasado al siguiente nodo en orden. El primer giro hacia la izquierda 
indica que hemos pasado del lado derecho de un nodo a su padre, lo que significa que ese padre es el siguiente nodo en 
orden después del nodo original.

4. Explica simétricamente cómo debe funcionar `pred()`.

Empieza con if (hasLeft()) y baja al hijo izquierdo y luego sigue bajando por la derecha hasta llegar a un nodo sin hijo 
derecho, ese nodo es el predecesor inorden porque es el mayor de los menores. 

Si no tiene hijo izquierdo, entonces sube por los ancestros mientras se esté subiendo por la rama izquierda, el primer 
giro hacia la derecha indica que hemos pasado del lado izquierdo de un nodo a su padre, lo que significa que ese padre es 
el nodo anterior en orden antes del nodo original.

5. Dibuja un árbol de al menos 7 nodos y marca el sucesor y predecesor inorden de tres nodos distintos.

       20
   10        30
 5    15   25   35

Sucesor de 10: va a su hijo derecho 15, como 15 no tiene hijo izquierdo, el sucesor es 15.

Succesor de 15: 20 como es hijo derecho, sube a 10 y como 10 es hijo izquierdo de 20, se devuelve el padre.

Predecesor de 30: baja al hijo izquierdo 25, como no tiene hijo derecho, el predecesor es 25.

Predecesor de 25: no tiene hijo izquierdo, entonces sube a 30, como 25 es hijo izquierdo de 30, sigue subiendo y como 30 
es hijo derecho de 20, el predecesor es 20.

6. Explica qué calcula `depth(u)` y por qué puede implementarse subiendo por `parent`.

Calcula la profundidad de un nodo. Se implementa con parent porque la profundidad se define como la cantidad de aristas 
desde el nodo hasta la raíz, entonces se puede contar cuántos pasos se necesitan para subir desde el nodo hasta llegar a 
un nodo que sea raíz (que no tenga parent).

7. Explica qué calcula `height(u)` y por qué suele implementarse bajando recursivamente por los hijos.

Mira hacia abajo y calcula el camino más largo desde el nodo hasta una hoja. Se implementa bajando recursivamente porque 
la altura de un nodo depende de la altura de sus hijos, entonces se necesita conocer la altura de los hijos para calcular 
la altura del nodo actual. Es un proceso que naturalmente se resuelve con recursión hacia abajo.

8. Explica qué calcula `subtreeSize(u)`.

subtreeSize(u) cuenta cuántos nodos hay en el subárbol enraizado en u, incluyendo al propio u. Lo hace recursivamente: 1 
(el nodo actual) más subtreeSize(left) más subtreeSize(right), si el nodo es nullptr retorna 0.

9. Demuestra que para todo nodo `u` se cumple `depth(u) + height(u) <= height(T)`.

Sea T el árbol completo y r su raíz, height(T) = height(r) es la longitud del camino más largo desde r hasta alguna hoja. 
depth(u) es la longitud del camino desde r hasta u, height(u) es la longitud del camino más largo desde u hasta alguna 
hoja de su subárbol. El camino desde r hasta u y luego desde u hasta su hoja más lejana tiene longitud depth(u) + height
(u). Ese camino es un camino desde la raíz hasta una hoja del árbol, y height(T) es el máximo de todos esos caminos. Por 
lo tanto depth(u) + height(u) <= height(T).

10. Indica la condición necesaria y suficiente para que se alcance la igualdad anterior.

La igualdad depth(u) + height(u) = height(T) se cumple exactamente cuando u está en el camino más largo del árbol, es 
decir, cuando el camino que pasa por u desde la raíz hasta alguna hoja es precisamente el camino de longitud máxima. Esto 
ocurre cuando u es un nodo en la rama más profunda del árbol.

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

El orden de visita es: hijo izquierdo -> nodo -> hijo derecho

3. ¿Qué significa visitar un nodo en postorden?

Visitar en postorden significa visitar el nodo después de visitar ambos hijos.

El orden de visita es: hijo izquierdo -> hijo derecho -> nodo

4. ¿Qué significa visitar un árbol por niveles?

Significa visitar los nodos del árbol nivel por nivel y dentro de cada nivel de izquierda a derecha (BFS)

5. ¿Por qué los recorridos recursivos tienen tiempo `O(n)`?

Porque se visita cada nodo exactamente una vez, y el trabajo que se hace en cada nodo (imprimir, procesar, etc.) es 
constante. La recursión simplemente organiza la forma en que se visitan los nodos, pero el número total de visitas es 
igual al número de nodos en el árbol, lo que da un tiempo lineal O(n).

6. ¿Por qué las versiones iterativas también tienen tiempo `O(n)`?

Porque cada nodo entra y sale de la pila o cola exactamente una vez. Las operaciones push y pop en una pila, o enqueue y 
dequeue en una cola, son O(1). Como se hacen n veces en total, el costo total es O(n).

7. ¿Cuál es la memoria auxiliar de un recorrido recursivo en un árbol balanceado?

En un árbol balanceado la altura es O(log n), así que la pila de llamadas crece como máximo hasta O(log n).
La memoria auxiliar es O(log n).

8. ¿Cuál es la memoria auxiliar de un recorrido recursivo en un árbol degenerado?

En un árbol degenerado la altura es O(n), así que la pila de llamadas puede acumular hasta O(n) marcos activos. 
La memoria auxiliar es O(n).

9. ¿Qué diferencia hay entre usar una pila explícita y usar la pila de llamadas?

Ambas funcionan como LIFO y producen el mismo resultado, la pila de llamadas es la que administra automáticamente el 
sistema operativo para las funciones recursivas, la pila explícita es un std::stack que el programador controla 
manualmente. La pila explícita permite mayor control sobre el tamaño y no tiene el riesgo de stack overflow en árboles 
muy profundos. 
La pila de llamadas es más simple de escribir.

10. ¿Por qué la cola del recorrido por niveles puede crecer mucho más en un árbol completo que en un árbol degenerado?.

En un árbol completo el ancho máximo (número de nodos en un nivel) puede ser hasta n/2, que ocurre en el último nivel. La 
cola puede llegar a contener O(n) elementos. En un árbol degenerado cada nivel tiene exactamente un nodo, así que la cola 
nunca tiene más de 2 elementos al mismo tiempo (el nodo actual y su único hijo), la diferencia es el ancho máximo del 
árbol.

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

Las secuencias impresas para:
- preorden (7, 3, 1, 5, 4, 6, 10, 8, 12) 
- inorden (1, 3, 4, 5, 6, 7, 8, 10, 12) 
- postorden (1, 4, 6, 5, 3, 8, 12, 10, 7) 
coinciden exactamente con el orden que predicen las definiciones recursivas. Que las versiones iterativas produzcan la 
misma secuencia que las recursivas es la evidencia más fuerte de correctitud.

2. ¿Qué parte de la demo permite defender que `succ()` y `pred()` respetan el orden inorden?

En la demo se imprime el sucesor y el predecesor de varios nodos y se verifica que sean los vecinos inmediatos en la 
secuencia inorden. Por ejemplo, succ(5) debe ser 6 y pred(5) debe ser 4, lo que coincide con la secuencia ordenada.

3. ¿Qué evidencia produce la representación ASCII del árbol?

La representación ASCII muestra la estructura real del árbol con las ramas y niveles visibles. Permite verificar 
visualmente que los nodos están en los lugares correctos, que las relaciones padre e hijo son las esperadas y que el 
árbol tiene la forma que debería según las inserciones realizadas.

4. En `demo_bst.cpp`, ¿qué observable permite defender que el inorden del BST queda ordenado?

La secuencia impresa por inorder() es {1, 3, 4, 5, 6, 7, 8, 10, 12}, que está en orden creciente. Eso demuestra que la 
invariante BST se mantuvo durante todas las inserciones y que el recorrido inorden la aprovecha correctamente.

5. ¿Qué operaciones de búsqueda se distinguen mejor en la demo del BST: `find`, `findEQ`, `lowerBound` o `upperBound`?

lowerBound y upperBound se distinguen mejor porque sus resultados son distintos para valores no presentes en el árbol. 
Por ejemplo, lowerBound(9) retorna 10 (el menor mayor o igual a 9) y upperBound(8) retorna 10 (el primer estrictamente 
mayor que 8), findEQ(9) retorna nullptr porque 9 no está en el árbol, mientras que find(9) retorna 10. Esa diferencia es 
la más ilustrativa para entender qué hace cada función.

6. En `demo_heap.cpp`, ¿qué salida permite defender que el mínimo queda en la raíz?

top() retorna siempre el primer elemento del vector interno, que es data_[0]. Después de heapify() y después de cada add
() y remove(), se puede imprimir top() y verificar que siempre es el menor elemento presente. Eso demuestra que la 
propiedad de minheap se mantiene en todo momento.

7. ¿Qué evidencia permite distinguir entre insertar con `add()` y construir con `heapify()`?

add() inserta un elemento al final y llama bubbleUp(), que lo sube hasta su lugar correcto en O(log n). heapify() toma un 
vector ya lleno y llama trickleDown() sobre todos los nodos internos de derecha a izquierda en O(n). La evidencia es que 
heapify() sobre un vector desordenado produce la misma propiedad isHeap() = true que insertar uno a uno, pero en la demo 
se puede medir que heapify() construye la estructura a partir del vector dado directamente, sin insertar elemento por 
elemento.

8. En `demo_capitulo5_panorama.cpp`, ¿qué comparación resume mejor la semana: árbol enlazado, BST o heap?.

La comparación más clara es la del árbol enlazado base frente al BST y al heap. El árbol enlazado es la infraestructura 
pura sin restricciones adicionales; el BST agrega la invariante de orden y permite búsquedas eficientes; el heap agrega 
la invariante de prioridad y permite acceso al mínimo en O(1). Cada estructura es la anterior más una propiedad adicional 
que habilita operaciones nuevas.

#### Bloque 5 - Pruebas públicas, pruebas internas e invariantes

Revisa:

- `Semana5/pruebas_publicas/test_public_week5.cpp`
- `Semana5/pruebas_internas/test_internal_week5.cpp`

Responde:

1. ¿Qué operaciones del BST valida la prueba pública?

Valida:
add() (inserción de claves nuevas), rechazo de duplicados, inorder() en sus cuatro versiones (recursiva y tres 
iterativas), findEQ(), find() como lowerBound(), lowerBound(), upperBound(), minNode(), maxNode(), isBST(), remove(), 
contains() y checkParentLinks().

2. ¿Qué casos validan que el BST no acepta duplicados?

La prueba ejecuta bst.add(5) después de haber insertado 5 previamente y verifica que retorna false. Eso confirma que 
addChild() detecta la igualdad y no inserta el duplicado.

3. ¿Qué se verifica al comparar el inorden recursivo con las versiones iterativas?

Se verifica que las cuatro versiones producen exactamente la misma secuencia {1, 3, 4, 5, 6, 7, 8, 10, 12}. Eso demuestra 
que todas las implementaciones del recorrido inorden son equivalentes en resultado, aunque difieran en la estructura 
auxiliar que usan.

4. ¿Qué se espera de `findEQ(8)` en la prueba pública?

Se espera que retorne un puntero no nulo cuyo campo data sea exactamente 8, si no la encuentra retorna nullptr.

5. ¿Qué se espera de `lowerBound(9)` y `upperBound(8)`?

lowerBound(9) debe retornar el nodo con valor 10, que es el menor valor mayor o igual a 9 presente en el árbol, upperBound
(8) también debe retornar el nodo con valor 10, que es el primer valor estrictamente mayor que 8, ambas retornan 10 en 
este caso pero por razones distintas.

6. ¿Qué propiedad se valida con `isBST()`?

isBST() verifica que para cada nodo del árbol se cumpla la invariante BST: 
el hijo izquierdo, si existe, tiene un valor menor, 
el hijo derecho, si existe, tiene un valor mayor. 
La implementación recorre el árbol inorden y verifica que la secuencia resultante sea no decreciente.

7. ¿Qué se valida después de eliminar un nodo con `remove()`?

Se valida que el inorden resultante sigue siendo correcto y ordenado (sin el valor eliminado), que contains() retorna 
false para el valor eliminado, y que checkParentLinks() confirma que todos los punteros parent siguen siendo consistentes 
después de la reorganización.

8. ¿Qué valida `checkParentLinks()` después de borrar, separar o adjuntar subárboles?

Verifica que para cada nodo del árbol, su campo parent apunta al nodo que efectivamente lo contiene como hijo. Recorre el 
árbol recursivamente y comprueba que node->parent == parent esperado en cada nivel. 
Detecta inconsistencias que surgirían si alguna operación de modificación olvidara actualizar algún puntero parent.

9. ¿Qué operaciones del heap valida la prueba pública?

Valida heapify() (que produce un heap válido desde un vector), isHeap(), remove() repetido hasta vaciar el heap, y la 
propiedad de que la secuencia extraída de un min-heap es no decreciente. También valida isHeapArray() como función 
estática.

10. ¿Qué demuestra extraer repetidamente de un min-heap hasta vaciarlo?

Demuestra que trickleDown() restaura correctamente la propiedad de heap después de cada extracción, y que el mínimo 
global siempre está en la raíz antes de cada extracción. La secuencia {1, 2, 3, 5, 7, 8, 10} extraída de {7, 3, 10, 1, 5, 
8, 2} confirma ambas cosas.

11. ¿Qué operaciones de `BinTree` se validan con `attachAsRC`, `secede` y `removeSubtree`?

attachAsRC valida que un subárbol completo puede transferirse a otro árbol, que el tamaño del árbol receptor se actualiza 
correctamente y que el árbol donante queda vacío. secede valida que un subárbol puede desprenderse conservando sus nodos 
y tamaño, y que el árbol original se reduce correctamente. removeSubtree valida que los nodos del subárbol se destruyen y 
el tamaño se actualiza.

12. ¿Qué agregan las pruebas internas respecto a rotaciones, `bubbleUp`, `trickleDown`, profundidad, altura, sucesor y predecesor?

Las pruebas internas: 
- Verifican que rotateLeft y rotateRight preservan la propiedad BST y actualizan correctamente los punteros parent. 
- Verifican que bubbleUp sube correctamente un elemento hasta su posición de heap. 
- Verifican trickleDown en casos con uno o dos hijos. 
- Prueban depth() y height() con árboles de formas conocidas, verifican succ() y pred() en casos borde como el nodo más a 
la izquierda o más a la derecha.

13. ¿Qué sí demuestra pasar las pruebas públicas?

Demuestra que las operaciones principales producen los resultados esperados en los casos cubiertos por las pruebas: 
inserción, búsqueda, eliminación, recorridos, heap y operaciones de subárbol. Confirma que las invariantes principales se 
mantienen en esos casos.

14. ¿Qué no demuestra pasar las pruebas públicas?

No demuestra que el código funcione correctamente en todos los casos posibles; solo en los casos que las pruebas cubren. 
No verifica casos borde que las pruebas no incluyen, ni garantiza correctitud en casos con árboles muy grandes, muy 
degenerados, o con secuencias de operaciones que las pruebas no ejercitan. Las pruebas internas cubren más casos pero 
tampoco son exhaustivas.

15. ¿Por qué una defensa correcta debe mencionar invariantes y complejidad además de resultados observables?.

Los resultados observables solo muestran que el código funciona en casos específicos; no explican por qué funciona. 
- Las invariantes son las propiedades que el código mantiene en todo momento (propiedad BST, propiedad heap, consistencia 
de punteros parent) y son la razón por la que el código es correcto en general. 
- La complejidad explica cuántos recursos consume el algoritmo en función del tamaño de entrada, lo que permite comparar 
soluciones y entender los límites del diseño. Una defensa que solo menciona salidas observables no demuestra comprensión 
del algoritmo.

#### Bloque 6 - Lectura cercana: `BinNode`, `BinTree` y `BinaryTree`

Revisa:

- `Semana5/include/BinNode.h`
- `Semana5/include/BinTree.h`
- `Semana5/include/BinaryTree.h`

Responde:

1. En `BinNode`, ¿qué invariantes deben mantenerse entre `parent`, `left` y `right`?

Si node->left != nullptr entonces node->left->parent == node. 
Si node->right != nullptr entonces node->right->parent == node. 
Si node->parent != nullptr entonces o bien node->parent->left == node o bien node->parent->right == node. 
Ningún nodo puede apuntarse a sí mismo. La raíz tiene parent == nullptr.

2. ¿Por qué `insertAsLC` e `insertAsRC` deben rechazar una inserción cuando el hijo correspondiente ya existe?

Si se permite insertar un hijo donde ya existe uno, el puntero al hijo anterior se pierde, lo que produce un memory leak 
porque esos nodos quedan inaccesibles pero siguen ocupando memoria. Además, la estructura del árbol quedaría corrupta. 
Por eso ambas funciones lanzan una excepción si el hijo correspondiente ya existe.

3. Explica cómo `size()` de `BinNode` recorre el subárbol.

size() es recursivo: retorna 1 (el nodo actual) más size() del hijo izquierdo (0 si es nullptr) más size() del hijo 
derecho (0 si es nullptr). Recorre todo el subárbol enraizado en el nodo actual visitando cada nodo exactamente una vez 
en postorden implícito.

4. Explica cómo funcionan `leftmost()` y `rightmost()`.

leftmost() empieza en el nodo actual y baja siempre por left mientras left no sea nullptr; retorna el último nodo al que 
llega, que es el más a la izquierda del subárbol. rightmost() es simétrico: baja siempre por right y retorna el nodo más 
a la derecha. En un BST, leftmost() de la raíz da el mínimo y rightmost() da el máximo.

5. Explica paso a paso cómo funciona `succ()`.

Primero verifica si el nodo tiene hijo derecho. Si lo tiene, baja a él y luego sigue bajando por left hasta llegar a un 
nodo sin hijo izquierdo; ese es el sucesor. Si no tiene hijo derecho, sube por parent mientras el nodo actual sea hijo 
derecho de su padre (isRightChild()); cuando deja de serlo, retorna el parent del último nodo visitado, que es el 
sucesor, si el nodo es el mayor del árbol, succ() retorna nullptr.

6. Explica paso a paso cómo funciona `pred()`.

Es simétrico a succ(), si el nodo tiene hijo izquierdo, baja a él y luego sigue bajando por right hasta llegar a un nodo 
sin hijo derecho; ese es el predecesor. Si no tiene hijo izquierdo, sube por parent mientras el nodo sea hijo izquierdo 
de su padre; cuando deja de serlo, retorna el parent del último nodo visitado, si el nodo es el menor del árbol, pred() 
retorna nullptr.

7. En `BinTree`, ¿qué papel cumplen `root_` y `size_`?

- root_ es el puntero a la raíz del árbol, es el punto de entrada a toda la estructura, sin él no hay forma de acceder a 
ningún nodo. 
- size_ mantiene el conteo de nodos del árbol, permite saber el tamaño en O(1) sin recorrer el árbol. Ambos campos se 
actualizan en cada operación que modifica la estructura.

8. Explica qué hace `updateHeight(Node*)`.

Recalcula la altura del nodo dado como 1 más el máximo entre la altura de su hijo izquierdo y la de su hijo derecho. Si 
el nodo no tiene hijos, su altura queda en 0, usa la función auxiliar stature() que retorna -1 para nullptr, lo que hace 
que una hoja quede con altura 0 correctamente.

9. Explica qué hace `updateHeightAbove(Node*)` y por qué sube hacia la raíz.

updateHeightAbove() llama a updateHeight() sobre el nodo dado y luego sube por parent repitiendo la operación hasta 
llegar a la raíz. Sube porque al modificar un nodo, su altura puede cambiar, lo que cambia la altura de su padre, que 
cambia la del abuelo, y así hasta la raíz, si no se sube, los ancestros quedan con alturas desactualizadas.

10. Explica cómo `attachAsLC` o `attachAsRC` transfieren un subárbol desde un árbol hacia otro.

attachAsRC(parent, subtree) conecta la raíz de subtree como hijo derecho de parent, actualiza el parent de esa raíz para 
que apunte a parent, suma el tamaño de subtree al tamaño del árbol receptor, llama updateHeightAbove(parent), y luego 
vacía subtree poniendo su root_ a nullptr y su size_ a 0. 
El subárbol ahora pertenece al árbol receptor y subtree queda vacío.

11. Explica qué diferencia hay entre `removeSubtree` y `secede`.

- removeSubtree desconecta el subárbol y destruye todos sus nodos liberando la memoria, el árbol original se reduce en el 
tamaño del subárbol eliminado. 
- secede desconecta el subárbol pero no destruye nada; retorna un nuevo BinTree que contiene esos nodos, transfiriendo la 
propiedad.

12. Explica por qué `secede` no debe destruir los nodos desprendidos.

Porque secede transfiere la propiedad de esos nodos al nuevo árbol que retorna. Si los destruyera, el árbol retornado 
estaría vacío o con punteros inválidos. El contrato de secede es separar y entregar, no separar y eliminar.

13. Explica por qué `removeSubtree` sí debe liberar nodos.

Porque nadie más va a ser responsable de esos nodos después de que se desconecten del árbol. Si no se liberan, quedan 
inaccesibles en memoria pero siguen ocupando espacio, produciendo un memory leak.

14. Explica qué verifica `checkParentLinks()`.

Recorre el árbol recursivamente y verifica que para cada nodo, su campo parent apunta exactamente al nodo que lo contiene 
como hijo. Compara node->parent con el parent que se le pasa como argumento en la recursión. Si algún puntero parent es 
incorrecto retorna false.

15. En `BinaryTree`, explica cómo se implementan `firstNode`, `lastNode`, `nextNode` y `prevNode`.

firstNode() retorna root_->leftmost(), que es el nodo con el menor valor en el recorrido inorden. lastNode() retorna 
root_->rightmost(), el mayor. nextNode(u) retorna u->succ(). prevNode(u) retorna u->pred(). Juntos permiten recorrer el 
árbol en orden sin un recorrido explícito.

16. Explica por qué un iterador basado en `succ()` produce recorrido inorden.

Porque succ() encuentra exactamente el siguiente nodo en la secuencia inorden: el menor de los mayores. Empezando en 
firstNode() y avanzando con succ() en cada paso, se visitan todos los nodos en el orden izquierda nodo derecha que define 
el inorden. La propiedad BST garantiza que esa secuencia es ordenada.

17. Explica qué aporta `asciiArt()` para depuración y sustentación.

asciiArt() genera una representación textual del árbol con ramas y jerarquía visible, permite ver de un vistazo si la 
estructura es la esperada, si los nodos están en los niveles correctos, si el arbol esta balanceado o degenerado, y si 
las operaciones de inserción o eliminación dejaron el árbol en el estado correcto. 
En una sustentación es evidencia directa de la forma del árbol sin necesidad de ejecutar el programa.

#### Bloque 7 - Árbol binario de búsqueda: búsqueda, eliminación y rotaciones

Revisa:

- `Semana5/include/BinarySearchTree.h`
- `Semana5/demos/demo_bst.cpp`
- `Semana5/pruebas_publicas/test_public_week5.cpp`
- `Semana5/pruebas_internas/test_internal_week5.cpp`

Responde:

1. Define formalmente la propiedad BST.

Para todo nodo u en el árbol: si v es cualquier nodo en el subárbol izquierdo de u entonces v.data < u.data; si w es 
cualquier nodo en el subárbol derecho de u entonces w.data > u.data. Esta propiedad se cumple recursivamente para cada 
nodo del árbol.

2. Explica por qué el recorrido inorden de un BST debe producir una secuencia no decreciente.

El recorrido inorden visita el subárbol izquierdo, el nodo actual y, finalmente, el subárbol derecho. La propiedad de BST 
garantiza que todo el subárbol izquierdo es menor que el nodo actual y todo el subárbol derecho es mayor. Como esto se 
cumple en cada nodo de forma recursiva, la secuencia de visitas es necesariamente no decreciente.

3. Explica la diferencia entre `find`, `findEQ`, `lowerBound` y `upperBound`.

findEQ(x) devuelve el nodo con valor exactamente igual a x, o nullptr si no existe. lowerBound(x) devuelve el primer nodo 
con valor mayor o igual a x (el menor valor que no es menor que x). upperBound(x) devuelve el primer nodo con valor mayor 
que x; find(x) es un alias de lowerBound(x); devuelve lowerBound aunque x no esté en el árbol.

4. Explica por qué `findEQ(x)` puede fallar aunque `lowerBound(x)` no falle.

findEQ(x) devuelve nullptr si x no se encuentra en el árbol. lowerBound(x) regresa el nodo con el valor mínimo que es 
mayor o igual a x, el cual puede existir aún cuando x no se encuentre. Por ejemplo, si el árbol contiene {1, 5, 10} y se 
busca x=3, findEQ(3) regresa nullptr, pero lowerBound(3) regresa el nodo con valor 5.

5. Construye manualmente el BST que se obtiene al insertar: `7, 3, 10, 1, 5, 8, 12, 4, 6`.

      7
     / \
    3   10
   / \ / \
  1  5 8 12
    / \
   4   6

6. Escribe el inorden, preorden, postorden y recorrido por niveles de ese árbol.

- Inorden: 1, 3, 4, 5, 6, 7, 8, 10, 12.
- Preorden: 7, 3, 1, 5, 4, 6, 10, 8, 12.
- Postorden: 1, 4, 6, 5, 3, 8, 12, 10, 7.
- Por niveles: 7, 3, 10, 1, 5, 8, 12, 4, 6.

7. Simula `lowerBound(9)` y `upperBound(8)` paso a paso.

- lowerBound(9): comienza en raíz 7, 9 > 7, se mueve a la derecha; llega a 10; 9 < 10, guarda candidate = 10, se mueve a 
la izquierda, llega a 8, 9 > 8, se mueve a la derecha, llega a nullptr, devuelve candidate = 10
- upperBound(8): comienza en raíz 7, 8 > 7, no actualiza candidate, se mueve a la derecha, llega a 10, 8 < 10, guarda 
candidate = 10, se mueve a la izquierda, llega a 8, 8 no es menor que 8, se mueve a la derecha, llega a nullptr, devuelve 
candidate = 10

8. Explica qué casos de eliminación existen en un BST: hoja, un hijo, dos hijos.

- Hoja: el nodo no tiene hijos, se desconecta directamente de su padre y se libera. 
- Un hijo: el nodo cuenta con un único hijo, por lo que se hace que el padre del nodo eliminado apunte directamente al 
hijo omitiendo el nodo eliminado. 
- Tiene dos hijos: busque su sucesor inorder (el más pequeño en el subárbol derecho), copie su valor al nodo actual, y 
luego borre el sucesor (que tiene como máximo un hijo derecho).

9. Explica qué papel cumple `splice` durante una eliminación.

splice(u) borra un nodo u que tiene como máximo un hijo. Conecta al padre de u directamente con el único hijo de u (o con 
nullptr si u es hoja), actualizando los punteros parent correspondientes y decrementando el tamaño. Es el caso base de 
eliminación; remove() lo llama directamente si el nodo a borrar tiene 0 o 1 hijo, o lo llama sobre el sucesor si tiene 2 
hijos.

10. Después de eliminar una clave, ¿qué invariantes deben seguir siendo ciertos?

En todo el árbol se debe mantener la propiedad BST. Todos los punteros de padre han de seguir siendo coherentes. size_ se 
debe decrementar en 1. Con updateHeightAbove se deben volver a calcular las alturas de los ancestros del nodo eliminado.

11. Explica por qué `remove(3)` en las pruebas debe conservar el inorden ordenado.

El nodo tres tiene dos hijos, remove() busca el sucesor de 3, que es 4 (el más pequeño del subárbol derecho de 3), copia 
el valor 4 al nodo que tenía 3 y borra el nodo que tenía 4 con splice(). 
Esto da como resultado un árbol con los mismos valores excepto por 3, y la propiedad BST se mantiene porque 4 está 
exactamente en la misma posición que antes ocupaba 3, siendo mayor que 1 y menor que 5.

12. Explica qué hace `rotateLeft`.

rotateLeft(u) toma el hijo derecho w de u y lo lleva a sustituir a u. u pasa a ser hijo izquierdo de w. El hijo izquierdo 
de w, si existía, se hace hijo derecho de u. Se actualizan todos los punteros padre afectados y si u era la raíz, w se 
convierte en la nueva raíz.

13. Explica qué hace `rotateRight`.

rotateRight(u) es simétrica: sube al hijo izquierdo w de u para que tome el lugar de u. u se convierte en hijo derecho de 
w. El hijo mayor de w, si lo tiene, pasa a ser hijo menor de u.

14. Demuestra que una rotación local preserva la propiedad BST.

Una rotación local solo afecta a un nodo u y a su hijo w (izquierdo para rotateRight, derecho para rotateLeft) y a los 
subárboles adyacentes. En rotateLeft(u), w se convierte en el nuevo padre de u, y el hijo izquierdo de w se convierte en 
el hijo derecho de u. Dado que w era el hijo derecho de u, todos los nodos en el subárbol izquierdo de w son mayores que 
u pero menores que w, por lo que al moverlos como hijos de u no se viola la propiedad BST. El mismo razonamiento aplica 
para rotateRight. Por lo tanto, la rotación local no altera el orden relativo de los nodos y preserva la propiedad BST.

15. Explica para qué sirve construir un BST balanceado desde un arreglo ordenado.

Para asegurarse de que la altura del árbol sea O(log n) desde el principio, lo que da búsquedas, inserciones y 
eliminaciones en O(log n) en el peor caso. Se toma el elemento central del arreglo como raíz, y se construyen 
recursivamente los subárboles izquierdo y derecho con las mitades restantes.

16. Compara el costo de búsqueda en un BST balanceado y en un BST degenerado.

En un BST balanceado la altura es O(log n), así que una búsqueda recorre como máximo O(log n) nodos. En un BST degenerado 
(todos los nodos en una sola rama, como una lista enlazada) la altura es O(n) y una búsqueda puede recorrer hasta O(n) 
nodos en el peor de los casos. Para n grande, la diferencia entre log(n) y n es enorme.

#### Bloque 8 - Heap binario y representación implícita

Revisa:

- `Semana5/include/BinaryHeap.h`
- `Semana5/demos/demo_heap.cpp`
- `Semana5/pruebas_publicas/test_public_week5.cpp`
- `Semana5/pruebas_internas/test_internal_week5.cpp`

Responde:

1. Explica por qué un heap binario puede almacenarse en un `std::vector` sin punteros.

Porque un heap es siempre un árbol binario completo es decir todos los niveles están llenos excepto posiblemente el 
último, que se llena de izquierda a derecha. Esa regularidad permite que cada nodo tenga una posición única, ya que se 
puede acceder a él utilizando su índice en el arreglo, sin necesidad de punteros explícitos.

2. Demuestra las fórmulas:

   ```cpp
   left(i) = 2*i + 1
   right(i) = 2*i + 2
   parent(i) = (i - 1) / 2
   ```

En un heap almacenado en un vector, el nodo raíz está en la posición 0. Para cualquier nodo en la posición i:
- El hijo izquierdo de i está en la posición 2*i + 1 porque el primer hijo de la raíz (i=0) está en 1, el segundo hijo de 
la raíz está en 2, el primer hijo del nodo en i=1 está en 3, el segundo hijo de i=1 está en 4, el primer hijo de i=2 está 
en 5, el segundo hijo de i=2 está en 6, y así sucesivamente. 
- El hijo derecho de i está en la posición 2*i + 2 por la misma razón, es el siguiente nodo después del hijo izquierdo.
- El padre de i está en la posición (i - 1) / 2 porque el nodo en i=1 tiene como padre a 0, el nodo en i=2 también tiene 
como padre a 0, el nodo en i=3 tiene como padre a 1, el nodo en i=4 tiene como padre a 1, el nodo en i=5 tiene como padre 
a 2, el nodo en i=6 tiene como padre a 2, y así sucesivamente.

3. Define la propiedad de min-heap.

Un min-heap es una estructura de datos que cumple dos propiedades:
- Propiedad estructural: es un árbol binario completo.
- Propiedad de orden: para cada nodo, su valor es menor o igual que el de sus hijos (si los tiene). Esto implica que el 
valor mínimo del heap siempre está en la raíz.

4. Explica por qué `top()` devuelve el mínimo.

Porque la propiedad de min-heap garantiza que data[0] sea menor o igual que todos sus hijos. Como todo nodo del heap es 
descendiente de la raíz, data[0] es el mínimo global.  top() devuelvo data.front() que es data[0].

5. Explica paso a paso cómo `bubbleUp(i)` restaura la propiedad de heap después de insertar.

add() agrega el nuevo elemento al final del arreglo en la posición i = size - 1. bubbleUp(i) compara entonces data[i] con 
su padre data[parent(i)], si data[i] es menor que su padre, los intercambia y actualiza i al índice del padre. Repite 
hasta que data[i] ya no sea menor que su padre o hasta que llegues a la raíz. Cada intercambio eleva el elemento un 
nivel, y el proceso termina cuando el elemento alcanza su lugar correcto.

6. Explica paso a paso cómo `trickleDown(i)` restaura la propiedad de heap después de eliminar la raíz.

remove() mueve el último elemento a data[0] y elimina el último. Luego trickleDown(0) compara data[i] con sus hijos, si 
algún hijo es menor, intercambia con el menor de ellos y baja a la posición del hijo, repite hasta que data[i] sea menor 
que sus hijos o hasta llegar a una hoja. En cada intercambio el elemento desciende un nivel hasta su posición correcta.

7. Explica por qué `remove()` debe mover el último elemento a la raíz antes de aplicar `trickleDown(0)`.

Porque eliminar la raíz crea un hueco en data[0]. Si se eliminara simplemente data[0] y se reordenara, la estructura del 
arreglo se rompería porque los índices de hijos e hijos de los otros nodos ya no corresponderían a sus posiciones 
calculadas. Al mover el último elemento a data[0] se mantiene la forma de árbol completo y sólo hay que restaurar la 
propiedad de orden, que es exactamente lo que hace trickleDown(0).

8. Explica qué verifica `isHeap()`.

Recorre todos los nodos del arreglo y para cada uno verifica que ninguno de sus hijos sea menor que él, si encuentra 
algún hijo menor que su padre, regresa false. Devuelve true si recorre todo el arreglo y no encuentra violaciones.

9. Compara construir un heap insertando `n` elementos con construirlo usando `heapify()`.

Insertar uno por uno: cada add() llama a bubbleUp(), que en el peor caso sube O(log n) niveles. Para n inserciones el 
costo total es O(n log n). heapify(): toma todos los n elementos ya en el arreglo y llama trickleDown() sobre todos los 
nodos internos de derecha a izquierda. Aunque parece también O(n log n), el análisis amortizado muestra que la mayoría de 
los nodos están en los niveles bajos y trickleDown() baja muy poco desde ahí; el costo total es O(n).

10. Justifica por qué insertar `n` elementos uno por uno cuesta `O(n log n)` en el peor caso.

En el peor caso, cada inserción hace que el nuevo elemento suba desde la hoja hasta la raíz, recorriendo toda la altura 
del heap, que es O(log n). Si insertamos los n elementos en orden creciente, cada inserción burbujea hacia arriba hasta 
la raíz, dando un total de n * O(log n) = O(n log n).

11. Justifica por qué `heapify()` puede ejecutarse en `O(n)`.

heapify() invoca a trickleDown(i) para i desde n/2 - 1 hasta 0. Los nodos en los niveles más bajos tienen pocos niveles 
por bajar. Sumar los costos: n/2 nodos en el último nivel (ya son hojas, costo 0), n/4 en el penúltimo (costo máximo 1), 
n/8 en el anterior (costo máximo 2), etc. La suma: n/2 * 0 + n/4 * 1 + n/8 * 2 + ... converge a O(n) por la serie 
geométrica ponderada.

12. Ejecuta una extracción completa del heap construido con `{7, 3, 10, 1, 5, 8, 2}` y explica por qué la secuencia extraída sale ordenada.

Después de heapify() el arreglo queda en una forma válida de min-heap, por ejemplo {1, 3, 2, 7, 5, 8, 10}.
- Primera extracción: se saca 1; se mueve 10 a la raíz; trickleDown produce {2, 3, 8, 7, 5, 10}; se extrajo 1.
- Segunda extracción: se saca 2; se mueve 10 a la raíz; trickleDown produce {3, 5, 8, 7, 10}; se extrajo 2.
- Tercera extracción: se saca 3; se mueve 10 a la raíz; trickleDown produce {5, 7, 8, 10}; se extrajo 3.
- Cuarta extracción: se saca 5; se mueve 10 a la raíz; trickleDown produce {7, 10, 8}; se extrajo 5.
- Quinta extracción: se saca 7; trickleDown produce {8, 10}; se extrajo 7.
- Sexta extracción: se saca 8; se extrajo 8.
- Séptima extracción: se saca 10; se extrajo 10.
Secuencia extraída: 1, 2, 3, 5, 7, 8, 10. La secuencia sale ordenada porque cada extracción saca el mínimo actual, y la propiedad de min-heap garantiza que ese mínimo siempre está en data[0].

13. Compara el heap con el BST: ¿cuál estructura conviene para consultar mínimo repetidamente y cuál conviene para búsquedas ordenadas?.

- El heap es conveniente para consultar el mínimo repetidamente: top() es O(1) y remove() es O(log n); no hay forma más 
eficiente de mantener acceso al mínimo con inserciones arbitrarias. Para búsquedas ordenadas, recorrido completo en orden 
o buscar un valor arbitrario
- El BST es conveniente: find() es O(h), el inorden produce todos los valores en orden en O(n), y se puede buscar 
cualquier valor eficientemente. El heap no permite buscar eficientemente valores arbitrarios ni recorrerlos en orden sin 
destruir la estructura.

#### Bloque 9 - Cierre comparativo y preparación de sustentación

Responde esta pregunta final:

¿Qué cambia cuando pasamos de estudiar listas, pilas y colas a diseñar árboles binarios, heaps y árboles binarios de búsqueda?

Pasar de listas, pilas y colas a árboles binarios implica abandonar la linealidad para adoptar estructuras con
ramificación, donde cada nodo puede tener hasta dos hijos y un puntero parent que permite subir, esa combinación hace 
posibles los recorridos en múltiples órdenes y el mantenimiento ascendente de alturas con updateHeightAbove(). Cuando la 
estructura es un árbol completo, como el heap, los punteros son innecesarios porque las relaciones padre-hijo se calculan 
con índices, lo que muestra que la representación implícita en arreglo es una alternativa eficiente a la representación 
enlazada. La diferencia clave entre las estructuras de la semana está en sus propiedades adicionales: BinTree solo impone 
forma, el BST agrega una propiedad de orden (izquierda menor, derecha mayor) que permite búsqueda en O(h) y hace que el 
recorrido inorden produzca una secuencia ordenada, y el heap agrega una propiedad de prioridad (padre menor que hijos) 
que permite acceder al mínimo en O(1) y extraerlo en O(log n), aunque no permite recorrido ordenado sin destruir la 
estructura; heapify() construye el heap en O(n) porque la mayoría de los nodos están en niveles bajos donde trickleDown 
hace poco trabajo. Los recorridos son la forma de convertir un árbol en una secuencia; la secuencia que producen depende 
directamente de la propiedad de la estructura, y por eso el inorden de un BST no produce una secuencia ordenada por 
casualidad sino porque el orden de visita coincide exactamente con la invariante. Para defender correctitud se necesita 
combinar pruebas observables, trazados manuales, invariantes verificables y análisis de complejidad, porque ninguno de 
esos elementos por sí solo demuestra que el algoritmo es correcto en general.
