### Actividad 7 - CC232

#### Datos generales

Duración: 3 horas de clase.

Modalidad: Trabajo individual.

Entrega: Un archivo llamado `Actividad7-CC232.md`.

#### Material de trabajo

#### Código de la semana

Revisa como mínimo:

* `Semana7/README.md`
* `Semana7/lecturas/Notas.md`
* `Semana7/include/Entry.h`
* `Semana7/include/BinNode.h`
* `Semana7/include/BinTree.h`
* `Semana7/include/BST.h`
* `Semana7/include/AVL.h`
* `Semana7/include/BinaryTree.h`
* `Semana7/include/BinarySearchTree.h`
* `Semana7/include/RedBlackTree.h`
* `Semana7/include/AVLTreeCompact.h`
* `Semana7/include/RedBlackTreeLLRB.h`
* `Semana7/include/Capitulo7.h`

#### Código reutilizado conceptualmente

Revisa también:

* `Semana5/include/BinarySearchTree.h`
* `Semana6/include/Treap.h`
* `Semana6/demos/demo_bst_rotations.cpp`
* `Semana6/demos/demo_treap_basico.cpp`

#### Demostraciones y pruebas

Revisa y ejecuta:

* `Semana7/demos/demo_avl_deng_core.cpp`
* `Semana7/demos/demo_avl_compact_rotations.cpp`
* `Semana7/demos/demo_bst_deng_vs_avl.cpp`
* `Semana7/demos/demo_redblack_morin.cpp`
* `Semana7/demos/demo_redblack_llrb.cpp`
* `Semana7/demos/demo_compare_avl_vs_redblack.cpp`
* `Semana7/demos/demo_compare_with_semana5.cpp`
* `Semana7/demos/demo_capitulo7_panorama.cpp`
* `Semana7/pruebas_publicas/test_public_week7.cpp`
* `Semana7/pruebas_internas/test_internal_week7.cpp`

#### Reglas de trabajo

1. No reemplaces AVL o Red-Black Tree por `std::set`, `std::map` u otra estructura estándar que oculte el algoritmo.
2. No cambies la interfaz principal de la librería salvo que una pregunta lo pida explícitamente.
3. Toda explicación debe mencionar invariante, operación, evidencia y costo.
4. Si modificas una demostración o agregas una prueba, marca el cambio con un comentario breve.

```cpp
// MOD-A7-B4: caso de comparacion de altura
```

5. No basta con ejecutar el programa. Debes poder explicar por qué la estructura sigue siendo un BST y por qué su altura se mantiene controlada.

#### Bloque 1 - Diagnóstico inicial de la Semana 7

Revisa:

* `Semana7/README.md`
* `Semana7/CMakeLists.txt`
* `Semana7/include/Capitulo7.h`

Ejecuta desde la raíz de la librería:

```bash
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug
ctest --test-dir build-debug -R semana7 --output-on-failure
```

Responde:

1. ¿Qué targets de demostración aparecen para Semana 7?

Los targets de demostración para Semana 7 son:
- demo_avl_deng_core
- demo_avl_compact_rotations
- demo_bst_deng_vs_avl
- demo_redblack_morin
- demo_redblack_llrb
- demo_compare_avl_vs_redblack
- demo_compare_with_semana5
- demo_capitulo7_panorama

2. ¿Qué pruebas públicas e internas aparecen?

Las pruebas públicas e internas para Semana 7 son:
- Pruebas públicas: test_public_week7.cpp
- Pruebas internas: test_internal_week7.cpp

3. ¿Qué archivos incluye `Capitulo7.h`?

Capitulo7.h incluye los siguientes archivos:
- AVL.h
- BinarySearchTree.h
- BinaryTree.h
- RedBlackTree.h
- AVLTreeCompact.h
- RedBlackTreeLLRB.h

4. ¿Qué relación conceptual hay entre Semana 5, Semana 6 y Semana 7?

Se relacionan conceptualmente en que todas tratan sobre árboles binarios de búsqueda (BST) y sus variantes. 
- Semana 5 se enfoca en la implementación básica de un BST, 
- Mientras que Semana 6 introduce el Treap, una estructura que combina propiedades de un BST con prioridades. 
- Semana 7 continúa esta evolución presentando estructuras balanceadas como AVL y Red-Black Tree, que mantienen la eficiencia de búsqueda mediante invariantes adicionales para evitar la degeneración lineal del BST.

5. ¿Por qué no es correcto decir que una carpeta "hereda" de otra carpeta?

Porque la herencia es un concepto específico de la programación orientada a objetos, donde una clase puede derivar de otra para reutilizar código y extender funcionalidades, sin embargo, las carpetas en un sistema de archivos no tienen esta relación jerárquica de herencia, simplemente organizan archivos y subcarpetas sin implicar una relación de dependencia o extensión entre ellas.

6. ¿Qué clases sí usan herencia dentro del código?

Dentro de el código, las clases que usan herencia son:
- AVL hereda de BST<T, Compare>
- RedBlackTree hereda de BinarySearchTree<T, Compare>

7. ¿Qué evidencia inicial obtuviste al ejecutar las pruebas sin modificar nada?.

La evidencia inicial al ejecutar las pruebas sin modificar nada es que todas las pruebas públicas e internas pasaron correctamente, lo que indica que las implementaciones de AVL y Red-Black Tree cumplen. También las demostraciones ejecutadas muestran el comportamiento esperado de las estructuras balanceadas.

Entrega en este bloque:

* Una tabla con comando ejecutado, resultado, error si hubo e interpretación.

| Comando ejecutado | Resultado | Error | Interpretación |
|---|---|---|---|
| `cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug` | Configuración generada correctamente, detectó GNU 13.3.0 como compilador | Ninguno | El proyecto quedó listo para compilar en modo Debug, no hubo problemas de configuración ni dependencias faltantes |
| `cmake --build build-debug` | Se compilaron los diez targets, ocho demos y las dos pruebas, todo al 100% | Ninguno | Todo el código de la semana 7 compila limpio con C++17, sin warnings ni errores de enlazado |
| `ctest --test-dir build-debug -R semana7 --output-on-failure` | Los dos tests semana7_public y semana7_internal pasaron, 100% exitoso | Ninguno | Tanto la prueba pública como la interna validan que AVL y Red-Black Tree, en sus distintas variantes, mantienen sus invariantes después de insertar y eliminar |

* Una lista breve de los archivos que revisaste primero.

README.md 
CMakeLists.txt
include/Capitulo7.h

#### Bloque 2 - BST como punto de partida

Revisa:

* `Semana7/include/BST.h`
* `Semana7/include/BinarySearchTree.h`
* `Semana7/demos/demo_compare_with_semana5.cpp`
* `Semana7/demos/demo_bst_deng_vs_avl.cpp`

Responde:

1. Define formalmente la propiedad BST.

Un arbol binario al buscar cumple que para cada nodo t, todos sus valores a su izquierda cumpliran que sea menor que el propio nodo t y sus valores a la derecha cumpliran que sea estrictamente mayor.

2. Explica por qué el recorrido inorder de un BST produce una secuencia ordenada.

El recorrido inorder visita primero el subárbol izquierdo, luego la raíz y luego el subárbol derecho, como por la propiedad BST todo lo que está a la izquierda es menor y todo lo que está a la derecha es mayor, al seguir ese orden de visita los valores van saliendo de menor a mayor. 
Por ejemplo, en un árbol con raíz 5, hijo izquierdo 3 e hijo derecho 8, el inorder produce 3, 5, 8, que es la secuencia ordenada.

3. Explica por qué insertar claves ordenadas puede producir un BST degenerado.

Cuando las claves llegan en orden creciente, cada nueva clave es mayor que todas las anteriores, entonces siempre se inserta como hijo derecho del nodo más profundo. El árbol crece solo hacia la derecha, como una lista enlazada. Lo mismo pasa en sentido contrario con claves decrecientes. No hay ramas izquierdas que balanceen la estructura.

4. Construye manualmente el BST resultante de insertar:

```cpp
10, 20, 30, 40, 50, 60, 70
```

```
10
 \
  20
   \
    30
     \
      40
       \
        50
         \
          60
           \
            70
```

5. Indica la altura del árbol anterior si no hay balanceo.

El arbol se encuentra desbalanceado, graficamente se puede llegar a observar que pasaría de ser una estructura jerarquica (arbol) a una estructura totalmente lineal.

6. Explica por qué una búsqueda en ese árbol puede costar `O(n)`.

Al ser un arbol desbalanceado tiene como altura n-1 por lo que buscar un elemento que está en las hojas o uno que no existe nos exige bajar nodo por nodo lo cual seria practicamente lo mismo que usar una lista enlazada con una complejidad O(n).

7. Explica qué problema intenta resolver AVL.

AVL resuelve el problema de la degradación en altura. Mantiene un invariante que garantiza que la diferencia de alturas entre el subárbol izquierdo y el derecho de cualquier nodo nunca supera 1. Eso asegura que la altura total del árbol sea siempre O(log n), lo que mantiene búsqueda, inserción y eliminación en O(log n) en el peor caso.

8. Explica qué problema intenta resolver Red-Black Tree.

Un red black tree busca resolver el problema de que un arbol binario de busqueda normal se puede desbalancear mucho si insertas datos en cierto orden, por ejemplo ya ordenados, y eso hace que las operaciones de busqueda insercion y eliminacion se vuelvan lentas porque terminan pareciendose a una lista enlazada con costo O(n) en vez de O(log n)

Entrega en este bloque:

* Dibujo del BST degenerado.
* Explicación breve de costo.
* Relación con Semana 5.

#### Bloque 3 - AVL: balance por altura

Revisa:

* `Semana7/include/AVL.h`
* `Semana7/include/BST.h`
* `Semana7/include/BinNode.h`
* `Semana7/demos/demo_avl_deng_core.cpp`

Responde:

1. ¿Qué significa que un nodo esté balanceado en un AVL?

Un nodo balanceado significa que la diferencia entre las alturas de sus subarboles izquierdos y derechos sea como maximo 1, para corroborar ello se tiene avlBalanced.

2. ¿Cómo se calcula el factor de balance?

El factor de balance se calcula con la diferencia de alturas entre el hijo izquierdo y el hijo derecho.

   B (altura =1)
   /\
   A C

balanceFactor(B) = stature(A) - stature(C) = 0 - 0 = 0 -> balanceado

     C (altura =2)
    /
   B
  /
 A

balanceFactor(C) = stature(B) − stature(null) = 1 − (−1) = 2 -> desbalanceado por lo cual tiene que haacer una rotación.

3. ¿Qué información de altura debe mantenerse después de insertar o eliminar?

Se debe mantener actualizado el campo height de todos los ancestros del nodo afectado.

4. ¿Qué representa `_hot` dentro de la implementación estilo Deng?

Después de insert o remove, _hot sirve como punto de partida para subir por los ancestros y rebalancear, no siempre es el padre del nodo insertado en general.

5. ¿Por qué AVL puede heredar de `BST<T, Compare>`?

AVL puede heredar de BST porque en el fondo sigue siendo un arbol binario de busqueda, solo que le agrega la condicion extra de balance, entonces reutiliza toda la logica de busqueda insercion y estructura de nodos que ya tiene BST y solo añade lo necesario para mantenerse balanceado despues de cada operacion

6. ¿Qué operación restaura localmente la forma del árbol?

La operacion que restaura localmente la forma del arbol es la rotacion, ya sea simple o doble esta se aplica sobre el nodo mas desbalanceado y reacomoda unos pocos nodos sin tocar el resto del arbol

7. ¿Por qué una rotación no destruye la propiedad BST?

Una rotacion no destruye la propiedad BST porque solo reordena los punteros entre un nodo y sus hijos manteniendo el orden relativo de las claves es decir sigue respetando que todo lo que esta a la izquierda es menor y lo que esta a la derecha es mayor, solo cambia quien es padre y quien es hijo pero el recorrido inorden del arbol sigue dando la misma secuencia ordenada

8. Después de insertar, ¿por qué suele bastar reparar el primer ancestro desbalanceado?

Despues de insertar solo se agrega un nodo entonces el desbalance que se genera es local y ocurre en el primer ancestro que deja de cumplir la condicion de altura, al reparar ese nodo con una rotacion la altura de ese subarbol vuelve a quedar igual que antes de insertar entonces ya no afecta a los ancestros de mas arriba y no hace falta seguir revisando

9. Después de eliminar, ¿por qué puede ser necesario seguir revisando hacia la raíz?.

Despues de eliminar la rotacion que se hace en un nodo puede reducir la altura de ese subarbol en uno, y eso si puede desbalancear a un ancestro mas arriba, por eso hay que seguir subiendo y revisando cada ancestro hasta llegar a la raiz lo que a diferencia de insertar donde con una sola rotacion ya queda resuelto todo

Entrega en este bloque:

* Una explicación de los invariantes AVL.
* Un trazado de inserción con al menos una rotación.
```
10           20
 \           / \
 20   ->   10   30
 \
 30
```
* Evidencia de salida de `demo_avl_deng_core.cpp`.

```
AVL inorder: 10 20 22 25 27 30 40 50 
AVL level-order: 30 20 40 10 25 50 22 27 
Valido AVL: si
Tras borrar 20 y 40: 10 22 25 27 30 50 
Valido AVL: si
```

./build/sem7_demo_avl_compact_rotations

insert(30) -> root=30, height=0
insert(20) -> root=30, height=1
insert(10) -> root=20, height=1
insert(25) -> root=20, height=2
insert(28) -> root=20, height=2
insert(27) -> root=25, height=2
inorder: 10 20 25 27 28 30 
level: 25 20 28 10 27 30 
AVLTreeCompact(size=6, height=2)
isAVL = true

#### Bloque 4 - Rotaciones AVL: casos LL, RR, LR y RL

Revisa:

* `Semana7/include/AVLTreeCompact.h`
* `Semana7/demos/demo_avl_compact_rotations.cpp`
* `Semana7/include/AVL.h`

Ejecuta las demostraciones de rotaciones y construye una tabla con estas columnas:

* Caso
* Secuencia insertada
* Nodo desbalanceado
* Rotación aplicada
* Inorder antes
* Inorder después
* Altura final

Incluye los cuatro casos:

1. LL
2. RR
3. LR
4. RL

Responde:

1. ¿Qué diferencia hay entre una rotación simple y una rotación doble?

La diferencia es que la rotacion simple mueve un solo nodo para reacomodar el subarbol, mientras que la doble es en realidad dos rotaciones simples aplicadas seguidas, primero sobre el hijo y despues sobre el nodo desbalanceado porque con una sola no alcanza para corregir el desbalance

2. ¿Por qué LL y RR se corrigen con una sola rotación?

LL y RR se corrigen con una sola rotacion porque el desbalance esta en linea recta, o sea el nieto problematico esta del mismo lado que su padre, entonces basta con girar una vez el nodo desbalanceado hacia el lado contrario para enderezar todo

3. ¿Por qué LR y RL requieren dos pasos?

LR y RL requieren dos pasos porque el nieto problematico esta en zigzag respecto al abuelo, primero va para un lado y despues para el otro, entonces una sola rotacion no endereza la forma, hace falta primero enderezar el zigzag con una rotacion sobre el hijo y despues rotar el nodo desbalanceado como en el caso simple

4. ¿Qué parte del árbol cambia y qué parte permanece igual?

Lo que cambia son los punteros locales entre el nodo desbalanceado, su hijo y su nieto, junto con las alturas de esos nodos, lo que permanece igual es el resto del arbol que no participa en la rotacion y tambien el orden de las claves, ningun dato se pierde ni se mueve de lugar en el sentido logico

5. ¿Por qué el inorder debe ser el mismo antes y después de reestructurar?.

El inorder debe ser el mismo antes y despues porque la rotacion es solo un reacomodo estructural de punteros, no cambia que valores son menores o mayores que otros, entonces el recorrido inorden que refleja el orden de las claves tiene que mantenerse igual, si cambiara significaria que se rompio la propiedad de arbol binario de busqueda

Entrega en este bloque:

* Tabla de rotaciones.

| Caso | Secuencia insertada | Nodo desbalanceado | Rotación aplicada | Inorder antes | Inorder después | Altura final |
|------|---------------------|---------------------|--------------------|----------------|-------------------|----------------|
| LL | 30, 20, 10 | 30 | Simple derecha | 20, 30 | 10, 20, 30 | 1 |
| RR | 10, 20, 30 | 10 | Simple izquierda | 10, 20 | 10, 20, 30 | 1 |
| LR | 30, 10, 20 | 30 | Doble izquierda derecha | 10, 30 | 10, 20, 30 | 1 |
| RL | 10, 30, 20 | 10 | Doble derecha izquierda | 10, 30 | 10, 20, 30 | 1 |

* Cuatro dibujos pequeños.

**Caso LL**
```
   30               20
   /        ->       /  \
 20               10   30
/
10
```
 
**Caso RR**
```
10                  20
   \        ->       /  \
   20              10   30
      \
      30
```
 
**Caso LR**
```
  30                20
 /        ->       /  \
10                10   30
   \ 
   20
```
 
**Caso RL**
```
10                  20
 \        ->      /  \
   30              10   30
   /
 20
```

* Argumento de preservación del orden BST.

La rotación nunca cambia qué claves son menores o mayores entre si, solo cambia cual nodo actua como padre y cual como hijo, los tres nodos involucrados en la rotacion, y sus subarboles se reacomodan de forma que se sigue respetando que todo lo que esta a la izquierda de un nodo es menor y todo lo que esta a la derecha es mayor.


#### Bloque 5 - Red-Black Tree: balance por colores

Revisa:

* `Semana7/include/RedBlackTree.h`
* `Semana7/include/BinarySearchTree.h`
* `Semana7/include/BinaryTree.h`
* `Semana7/demos/demo_redblack_morin.cpp`

Responde:

1. ¿Qué propiedad BST mantiene Red-Black Tree?

Mantiene la propiedad de que para cada nodo, los valores en el subárbol izquierdo son menores y los valores en el subárbol derecho son mayores, asegurando así que el árbol sigue siendo un Binary Search Tree (BST) a pesar de las restricciones adicionales de color y balance notando así que estas son reglas adicionales y no alteran el orden.

2. ¿Qué propiedades de color debe cumplir un Red-Black Tree?

Las propiedades de color que debe cumplir un Red-Black Tree son:
- ⁠Cada nodo es rojo o negro.
- ⁠La raíz es siempre negra.
- Los nodos rojos solo pueden tener hijos negros.
- ⁠Todas las rutas desde un nodo a sus hojas nulas tienen la misma cantidad de nodos negros.

3. ¿Por qué la raíz debe terminar negra?

Si la raíz fuese roja, cualquier rotación o recoloreo que suba un nodo rojo a la raíz crearía ambigüedad en el conteo de altura negra por lo que pintarla negra garantiza consistencia sin costo alguno.

4. ¿Qué significa que no pueda haber dos nodos rojos consecutivos?

Significa que en cualquier camino desde la raíz hasta una hoja, nunca van a aparecen dos nodos rojos juntos, si un nodo fuese rojo, sus hijos deben ser negros por lo que esto limita cuánto puede crecer el árbol por la parte roja: entre cualquier par de nodos negros consecutivos en un camino puede haber a lo sumo un nodo rojo, lo que evita que un camino sea mucho más largo que otro.

5. ¿Qué representa la altura negra?

La altura negra es la cantidad de nodos negros que hay en cualquier camino desde un nodo hasta las hojas nulas sin contar el nodo de partida, esta cantidad tiene que ser igual en todos los caminos que salen de un mismo nodo y es justamente esa regla la que garantiza que el arbol no se desbalancee demasiado

6. ¿Por qué Red-Black Tree permite un balance menos estricto que AVL?

Permite un balance menos estricto porque en vez de exigir que las alturas de los subarboles sean casi iguales como hace AVL, solo exige que el camino mas largo no sea mas del doble que el mas corto, eso se logra con las reglas de color en vez de comparar alturas exactas entonces se hacen menos rotaciones al insertar o eliminar aunque el arbol quede un poco menos balanceado que un AVL

7. ¿Qué correcciones pueden aparecer después de insertar?

Despues de insertar puede aparecer el caso de que un nodo rojo tenga un padre rojo, eso se corrige de dos formas dependiendo del color del tio, si el tio es rojo se hace un recoloreo subiendo el problema hacia el abuelo y si el tio es negro o nulo se hace una rotacion simple o doble junto con un recoloreo para arreglarlo localmente

8. ¿Qué correcciones pueden aparecer después de eliminar?

Despues de eliminar puede aparecer un nodo con doble negro, que es cuando falta un nodo negro en un camino, eso se corrige revisando al hermano del nodo problematico, si el hermano es rojo se rota y si el hermano es negro se recolorea o se rota dependiendo de si los hijos del hermano son rojos o negros y esto puede repetirse subiendo por el arbol hasta la raiz

9. ¿Qué papel cumplen las rotaciones en Red-Black Tree?

Las rotaciones cumplen el papel de reacomodar la estructura del arbol cuando el recoloreo solo no alcanza para resolver el desbalance, sirven para reducir la altura de un lado o redistribuir nodos negros entre subarboles igual que en AVL mantienen el orden BST y solo cambian localmente quien es padre y quien es hijo

10. ¿Qué papel cumple el cambio de colores?.

El cambio de colores cumple el papel de resolver la mayoria de los desbalances sin tener que tocar la estructura del arbol, es una operacion mas barata que una rotacion porque no mueve nodos, solo cambia una etiqueta y muchas veces basta con recolorear y seguir subiendo por los ancestros para que el arbol vuelva a cumplir las reglas de red black tree

Entrega en este bloque:

* Lista de invariantes Red-Black.
* Explicación de una inserción que requiera recoloreo.
* Evidencia de salida de `demo_redblack_morin.cpp`.
```
RB inorder: 2 3 6 7 8 10 11 13 18 22 26 
Valido RedBlack: si
Tras borrar 18 y 11: 2 3 6 7 8 10 13 22 26 
Valido RedBlack: si
```

#### Bloque 6 - Comparación: BST, Treap, AVL y Red-Black Tree

Revisa:

* `Semana6/include/Treap.h`
* `Semana7/demos/demo_compare_avl_vs_redblack.cpp`
* `Semana7/demos/demo_compare_with_semana5.cpp`
* `Semana7/demos/demo_capitulo7_panorama.cpp`

Construye una tabla con estas columnas:

* Estructura
* Propiedad de orden
* Propiedad adicional
* Operación de reparación
* Altura esperada o garantizada
* Caso donde conviene usarla

Incluye:

1. BST común
2. Treap
3. AVL
4. Red-Black Tree

Responde:

1. ¿Qué tienen en común BST, Treap, AVL y Red-Black Tree?

Todos son arboles binarios de busqueda, es decir mantienen el orden de que lo menor va a la izquierda y lo mayor a la derecha y todos usan ese orden para buscar insertar y eliminar en tiempo proporcional a la altura del arbol, la diferencia entre ellos esta en como controlan esa altura para que no crezca demasiado

2. ¿Qué diferencia hay entre prioridad en Treap, altura en AVL y color en Red-Black Tree?

La prioridad en Treap es un valor aleatorio que se le asigna a cada nodo y que se usa para mantener una forma de heap ademas del orden BST, la altura en AVL es un dato que se calcula exactamente en cada nodo y que se usa para comparar los dos hijos y decidir si hace falta rotar y el color en RedBlack Tree es solo una etiqueta rojo o negro que sirve para aplicar reglas simples sin necesitar el valor exacto de la altura

3. ¿Por qué Treap depende de prioridades?

Treap depende de prioridades porque son las que determinan la forma del arbol mediante las reglas de heap, al ser asignadas aleatoriamente hacen que en promedio el arbol quede balanceado sin necesidad de reglas explicitas de balance como en AVL o Red Black, es un balance que se logra por probabilidad y no por una condicion garantizada siempre

4. ¿Por qué AVL suele ser más estricto en altura?

AVL suele ser mas estricto porque exige que la diferencia de alturas entre los dos subarboles de cualquier nodo sea como maximo uno eso obliga a rotar mas seguido para mantener esa condicion tan ajustada, a cambio se logra que las busquedas sean lo mas rapidas posibles porque el arbol se mantiene casi perfectamente balanceado

5. ¿Por qué Red-Black Tree puede ser preferible cuando hay muchas inserciones y eliminaciones?

RedBlack Tree puede ser preferible ahi porque al tener una regla de balance menos estricta necesita menos rotaciones en promedio para mantenerse valido, entonces insertar y eliminar resulta mas barato en la practica aunque las busquedas sean un poco mas lentas que en AVL, por eso se usa mucho en escenarios con muchas modificaciones como en estructuras de librerias estandar

6. ¿Qué estructura elegirías para defender búsqueda ordenada con balance fuerte?

Para defender busqueda ordenada con balance fuerte elegiria AVL porque su condicion de balance es la mas estricta de todas y eso garantiza la menor altura posible lo que se traduce en las busquedas mas rapidas y consistentes

7. ¿Qué estructura elegirías para explicar balance probabilístico?.

Para explicar balance probabilistico elegiria Treap, porque es la unica de estas estructuras que logra el balance a traves de la aleatoriedad de las prioridades y no mediante reglas deterministas como las rotaciones por altura o por color

Entrega en este bloque:

* Tabla comparativa.

## Tabla comparativa

| Estructura | Propiedad de orden | Propiedad adicional | Operación de reparación | Altura esperada o garantizada | Caso donde conviene usarla |
|---|---|---|---|---|---|
| BST común | Cumple orden BST, izquierda menor derecha mayor | Ninguna | No tiene, no se autocorrige | Puede degenerar a O(n) si se inserta en orden | Cuando los datos llegan ya desordenados y no hay riesgo de secuencias adversas |
| Treap | Cumple orden BST | Prioridad aleatoria con forma de heap | Rotaciones guiadas por prioridad | O(log n) esperado, en promedio, por la aleatoriedad | Cuando se quiere balance simple de programar y no importa una garantía estricta, solo una esperanza estadística |
| AVL | Cumple orden BST | Factor de balance por altura, máximo 1 de diferencia | Rotación simple o doble tras insertar o eliminar | O(log n) garantizado siempre, balance muy ajustado | Cuando hay muchas búsquedas y pocas modificaciones, se prioriza velocidad de lectura |
| Red-Black Tree | Cumple orden BST | Reglas de color, altura negra igual en todos los caminos | Recoloreo y rotaciones tras insertar o eliminar | O(log n) garantizado, balance menos ajustado que AVL | Cuando hay muchas inserciones y eliminaciones, se prioriza que las modificaciones sean baratas |

* Respuesta breve de decisión técnica.

Si la prioridad es que las busquedas sean lo mas rapidas posible eligiria AVL y si la prioridad es que las inserciones y eliminaciones sean baratas eligiria Red-Black Tree, el Treap lo usaria mas para fines didacticos por su simplicidad y el BST comun solo si tengo certeza de que los datos no van a llegar en un orden que lo degenere.

* Conexión explícita con Semana 5 y Semana 6.

De Semana 5 se retoma la base del arbol binario de busqueda, sus recorridos y las operaciones basicas de insertar buscar y eliminar. 
De Semana 6 se retoma la idea de Treap como estructura que combina orden BST con una propiedad extra, en este caso prioridad aleatoria, y esa misma logica de agregar una propiedad adicional sobre el BST base es la que despues se usa en Semana 7 con AVL usando altura y Red-Black Tree usando color, las demos demo_compare_avl_vs_redblack.cpp y demo_capitulo7_panorama.cpp muestran justamente eso, distintas formas de resolver el mismo problema de mantener balance sobre la misma base BST.

#### Bloque 7 - Pruebas, invariantes y defensa oral

Revisa:

* `Semana7/pruebas_publicas/test_public_week7.cpp`
* `Semana7/pruebas_internas/test_internal_week7.cpp`

Responde:

1. ¿Qué operaciones valida la prueba pública para AVL?

La prueba publica para AVL valida que al insertar una secuencia que genera desbalance el arbol termine con la altura correcta y el inorder ordenado tambien valida que al eliminar un nodo el arbol siga siendo un AVL valido y el inorder quede correcto ademas prueba la version compacta verificando que la raiz quede en el nodo esperado despues de una rotacion

2. ¿Qué operaciones valida la prueba pública para Red-Black Tree?

La prueba publica para Red-Black Tree valida que al insertar una secuencia de valores el arbol cumpla las reglas de red black con verifyRB, que no se pueda insertar un valor duplicado, y que despues de eliminar un nodo el arbol se siga verificando como valido, esto se prueba tanto en la version normal como en la version LLRB, y en esta ultima ademas se revisa que el inorder quede correcto despues de eliminar

3. ¿Qué casos adicionales cubre la prueba interna?

La prueba interna cubre casos adicionales como validar el BST base por separado, probar otra implementacion de BST con contains y busquedas de cota inferior y superior, y sobre todo hace una prueba masiva con datos aleatorios insertando 250 valores y eliminando 120 en las cuatro estructuras a la vez, comparando siempre contra un set de referencia para asegurar que todas queden balanceadas y ordenadas igual

4. ¿Qué significa que una prueba valide el inorder?

Que una prueba valide el inorder significa que compara el recorrido en orden del arbol contra la secuencia esperada de valores ordenados, si coinciden confirma que la propiedad BST se mantiene intacta y que ninguna rotacion o recoloreo desordeno las claves

5. ¿Qué significa que una prueba valide alturas o factores de balance?

Que una prueba valide alturas o factores de balance significa que revisa que en cada nodo la diferencia entre la altura del subarbol izquierdo y el derecho este dentro del limite permitido y que el valor de altura guardado en cada nodo coincida con el que realmente le corresponde segun sus hijos

6. ¿Qué significa que una prueba valide colores?

Que una prueba valide colores significa que revisa que se cumplan las reglas de red black, como que la raiz sea negra, que ningun nodo rojo tenga un hijo rojo y que la altura negra sea igual en todos los caminos desde un nodo hasta las hojas

7. ¿Qué no demuestra pasar solo las pruebas públicas?

Pasar solo las pruebas publicas no demuestra que la implementacion funcione bien en general porque son pocos casos armados a mano con secuencias especificas, no prueban con muchos datos aleatorios ni casos limite entonces puede que la estructura falle en escenarios que esas pruebas puntuales no llegan a cubrir

8. ¿Qué evidencia usarías en una sustentación: demostración, prueba, trazado o argumento de complejidad?

En una sustentacion usaria una combinacion de trazado y argumento de complejidad, el trazado sirve para mostrar paso a paso como se comporta la estructura en un caso concreto y que se entienda visualmente, y el argumento de complejidad sirve para justificar por que esa estructura garantiza cierto tiempo de ejecucion en el caso general, la prueba automatizada respalda que la implementacion es correcta pero no reemplaza la explicacion conceptual

9. ¿Qué invariante revisarías primero si falla AVL?

Si falla AVL lo primero que revisaria es el factor de balance de cada nodo, o sea que la diferencia de alturas entre hijos izquierdo y derecho no pase de uno porque esa es la invariante central de AVL y cualquier fallo ahi indica que una rotacion no se aplico bien o que la altura no se actualizo correctamente

10. ¿Qué invariante revisarías primero si falla Red-Black Tree?.

Si falla RedBlack Tree lo primero que revisaria es la altura negra, es decir que todos los caminos desde un nodo hasta las hojas tengan la misma cantidad de nodos negros porque esa es la invariante mas importante y sus fallos suelen venir de un recoloreo o una rotacion que no se aplico como correspondia

Entrega en este bloque:

* Tabla de pruebas revisadas.

## Tabla de pruebas revisadas

| Archivo | Estructuras probadas | Qué valida | Assert clave |
|---|---|---|---|
| `test_public_week7.cpp` | AVL (Deng) | Inorder y altura tras insertar 30,20,10 | `inorder == {10,20,30}`, `isAVLValid()`, `height() == 1` |
| `test_public_week7.cpp` | AVL (Deng) | Inorder valido tras eliminar un nodo | `remove(20)`, `isAVLValid()`, inorder ordenado |
| `test_public_week7.cpp` | Red-Black Tree (Morin) | Reglas de color, rechazo de duplicados, eliminación | `verifyRB()`, `!add(22)` porque ya existe, `remove(18)`, `verifyRB()` de nuevo |
| `test_public_week7.cpp` | AVL compacto | Raíz correcta tras rotación LR | `root()->data == 20`, `isAVL()` |
| `test_public_week7.cpp` | Red-Black LLRB | Validez tras insertar y eliminar, inorder final | `isRedBlackTree()`, `remove(20)`, inorder esperado |
| `test_internal_week7.cpp` | BST base (Deng) | Validez BST tras eliminar | `isBSTValid()`, inorder tras `remove(5)` |
| `test_internal_week7.cpp` | BinarySearchTree1 (Morin) | Búsqueda y cotas | `contains(30)`, `lowerBound(25)`, `upperBound(30)` |
| `test_internal_week7.cpp` | AVL, RB Morin, AVL compacto, RB LLRB juntas | Inserción masiva aleatoria (250 valores) contra un `set` de referencia | Cada estructura valida sus invariantes y su inorder coincide con el oráculo |
| `test_internal_week7.cpp` | Las mismas cuatro estructuras | Eliminación masiva aleatoria (120 valores) manteniendo invariantes | Cada estructura sigue válida y ordenada después de cada `remove` |

* Lista de invariantes que defenderías.

- Propiedad BST, todo nodo izquierdo menor y todo nodo derecho mayor, verificado con el inorder ordenado en todas las estructuras
- Factor de balance en AVL, la diferencia de alturas entre hijos no pasa de uno, verificado con isAVLValid() e isAVL()
- Altura guardada en cada nodo coincide con la altura real calculada desde sus hijos
- Altura negra igual en todos los caminos desde un nodo hasta las hojas

* Evidencia de ejecución de `ctest`.

#### Bloque 8 - Ejercicios de codificación

En este bloque debes modificar o extender la Semana 7 sin romper la interfaz principal de la librería. El objetivo es comprobar que entiendes los invariantes de AVL y Red-Black Tree no solo de forma teórica, sino también mediante código, pruebas y evidencia de ejecución.

#### Ejercicio 1 - Validador de propiedad BST

Crea un archivo:

```bash
Semana7/demos/demo_validate_bst_property.cpp
```

Implementa una función auxiliar que valide si un árbol cumple la propiedad BST usando límites inferiores y superiores.

Firma sugerida:

```cpp
template <typename Node, typename T>
bool validateBST(Node* node, const T* minValue, const T* maxValue);
```

Reglas:

* Si `node == nullptr`, retorna `true`.
* Si existe `minValue`, entonces `node->data` debe ser mayor que `*minValue`.
* Si existe `maxValue`, entonces `node->data` debe ser menor que `*maxValue`.
* Valida recursivamente el subárbol izquierdo y derecho.
* No uses recorrido inorder como única validación.

Incluye comentarios en español:

```cpp
// Valida que cada nodo respete los limites heredados desde sus ancestros.
template <typename Node, typename T>
bool validateBST(Node* node, const T* minValue, const T* maxValue) {
  if (node == nullptr) return true;

  // Si hay un limite inferior heredado, el dato debe ser estrictamente mayor.
  if (minValue && !(node->data > *minValue)) return false;

  // Si hay un limite superior heredado, el dato debe ser estrictamente menor.
  if (maxValue && !(node->data < *maxValue)) return false;

  // El hijo izquierdo hereda el mismo minValue, pero su nuevo maxValue
  // pasa a ser el dato del nodo actual.
  if (!validateBST(node->left, minValue, &node->data)) return false;

  // El hijo derecho hereda el mismo maxValue, pero su nuevo minValue
  // pasa a ser el dato del nodo actual.
  if (!validateBST(node->right, &node->data, maxValue)) return false;

  return true;
}
```

Entrega:

* Código fuente.
* Salida de la demostración.
* Explicación de por qué validar solo padre-hijo no es suficiente.

Validar solo padre-hijo no alcanza porque esa comparacion es local, no arrastra los limites de los ancestros mas arriba. Por ejemplo, un nieto puede ser mayor que su padre pero terminar colgando del lado izquierdo de la raiz sin ser menor que ella, ese caso pasa el chequeo padre-hijo pero ya no es un BST valido. Por eso hace falta ir heredando un limite minimo y maximo en cada nivel, asi cada nodo se compara contra todos sus ancestros y no solo contra el de arriba.

#### Ejercicio 2 - Contador de rotaciones AVL

Extiende una demostración o crea una nueva:

```bash
Semana7/demos/demo_avl_rotation_counter.cpp
```

El programa debe insertar varias secuencias y contar cuántas rotaciones aparecen en cada caso.

Secuencias mínimas:

```cpp
{30, 20, 10} // LL
{10, 20, 30} // RR
{30, 10, 20} // LR
{10, 30, 20} // RL
{10, 20, 30, 40, 50, 60, 70}
```

Salida esperada en formato similar:

```text
Caso LL
Rotaciones simples: 1
Rotaciones dobles: 0
Altura final: 1

Caso LR
Rotaciones simples: 0
Rotaciones dobles: 1
Altura final: 1
```

Entrega:

* Código fuente.
* Tabla con cada caso, secuencia, tipo de rotación y altura final.
* Explicación de por qué LR y RL no se resuelven con una sola rotación directa.

#### Ejercicio 3 - Verificador de balance AVL

Crea un archivo:

```bash
Semana7/demos/demo_validate_avl_balance.cpp
```

Implementa una función que verifique que todo nodo cumpla:

```text
|height(left) - height(right)| <= 1
```

Firma sugerida:

```cpp
template <typename Node>
bool validateAVLBalance(Node* node);
```

También implementa una función auxiliar:

```cpp
template <typename Node>
int computeHeight(Node* node);
```

Reglas:

* La altura de un árbol vacío debe ser `-1`.
* La altura de una hoja debe ser `0`.
* Debes validar todos los nodos, no solo la raíz.
* El programa debe imprimir si el árbol está balanceado o no.

Salida esperada:

```text
Validacion AVL despues de inserciones
Estado: balanceado
Altura calculada: 3
```

Entrega:

* Código fuente.
* Evidencia de ejecución.
* Explicación de la diferencia entre altura almacenada y altura calculada.

#### Ejercicio 4 - Comparación experimental BST vs AVL

Crea una demostración:

```bash
Semana7/demos/demo_compare_bst_avl_height.cpp
```

Inserta las mismas claves en un BST común y en un AVL.

Casos mínimos:

```cpp
std::vector<int> sortedKeys = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
std::vector<int> mixedKeys = {5, 2, 8, 1, 3, 7, 9, 4, 6, 10};
```

El programa debe imprimir:

```text
Caso: claves ordenadas
Altura BST: 9
Altura AVL: 3

Caso: claves mezcladas
Altura BST: ...
Altura AVL: ...
```

Responde:

1. ¿Qué ocurre con el BST cuando las claves llegan ordenadas?
2. ¿Qué ocurre con AVL ante la misma entrada?
3. ¿Por qué ambas estructuras conservan el mismo inorder?
4. ¿Por qué la altura es la evidencia central en esta comparación?.

Entrega:

* Código fuente.
* Salida.
* Tabla comparativa.
* Interpretación.

#### Ejercicio 5 - Validador básico Red-Black Tree

Crea una demostración:

```bash
Semana7/demos/demo_validate_redblack_basic.cpp
```

Implementa validaciones básicas para Red-Black Tree:

1. La raíz debe ser negra.
2. No debe existir un nodo rojo con hijo rojo.
3. Todos los caminos desde un nodo hasta hojas nulas deben tener la misma altura negra.

Firmas sugeridas:

```cpp
template <typename Node>
bool validateNoRedRed(Node* node);

template <typename Node>
int computeBlackHeight(Node* node);

template <typename Node>
bool validateBlackHeight(Node* node);
```

Reglas:

* Considera las hojas nulas como negras.
* Si detectas violación, imprime un mensaje en español.
* No basta con imprimir el inorder.
* La validación debe revisar estructura y colores.

Salida esperada:

```text
Validacion Red-Black Tree
Raiz negra: correcto
Sin rojo-rojo: correcto
Altura negra uniforme: correcto
Estado final: valido
```

Entrega:

* Código fuente.
* Evidencia de ejecución.
* Explicación de por qué Red-Black Tree permite mayor flexibilidad que AVL.

#### Ejercicio 6 - Prueba pública adicional

Agrega una prueba pública en:

```bash
Semana7/pruebas_publicas/test_public_week7_extra.cpp
```

La prueba debe cubrir al menos:

1. Inserción ordenada en AVL.
2. Validación de inorder.
3. Validación de altura máxima razonable.
4. Inserción en Red-Black Tree.
5. Validación de búsqueda después de varias inserciones.

Ejemplo de intención:

```cpp
// Verifica que AVL no se degrade cuando recibe claves ordenadas.
```

No copies exactamente este pseudocódigo. Adáptalo a la interfaz real de la librería.

Entrega:

* Código de prueba.
* Comando usado para compilar.
* Comando usado para ejecutar.
* Resultado de `ctest`.
* Explicación de qué bug detectaría esta prueba.

#### Ejercicio 7 - Mini benchmark de búsqueda

Crea una demostración:

```bash
Semana7/demos/demo_search_benchmark_week7.cpp
```

Inserta `n` claves en:

1. BST común
2. AVL
3. Red-Black Tree

Usa al menos:

```cpp
n = 1000
n = 5000
n = 10000
```

Mide búsquedas exitosas y fallidas.

Reglas:

* Usa `std::chrono`.
* No imprimas cada búsqueda individual.
* Imprime tiempo total por estructura.
* Usa las mismas claves para todas las estructuras.
* Separa el caso ordenado del caso aleatorio.

Salida sugerida:

```text
n = 10000
Caso ordenado
BST search time: ...
AVL search time: ...
RedBlack search time: ...

Caso aleatorio
BST search time: ...
AVL search time: ...
RedBlack search time: ...
```

Entrega:

* Código fuente.
* Tabla de resultados.
* Interpretación.
* Conclusión sobre altura y costo de búsqueda.

#### Ejercicio 8 - Integración al CMake

Agrega tus demostraciones al `CMakeLists.txt` de Semana 7.

Debes poder compilar con:

```bash
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug
ctest --test-dir build-debug -R semana7 --output-on-failure
```

Entrega:

* Fragmento modificado de `CMakeLists.txt`.
* Evidencia de compilación.
* Evidencia de pruebas.
* Explicación de por qué una demostración no necesariamente es una prueba automatizada.

#### Entrega mínima de codificación

Para considerar completo este bloque, debes entregar como mínimo:

1. Dos demostraciones nuevas.
2. Una prueba pública adicional.
3. Una tabla de resultados.
4. Una explicación de invariantes.
5. Evidencia de compilación.
6. Evidencia de ejecución.
7. Evidencia de `ctest`.

#### Pregunta final del bloque

Después de implementar los ejercicios, responde:

¿Por qué en estructuras balanceadas no basta con probar que el inorder está ordenado?

Tu respuesta debe mencionar:

* Propiedad BST.
* Altura.
* Rotaciones.
* Invariante AVL.
* Invariante Red-Black.
* Diferencia entre correctitud funcional y correctitud estructural.

#### Bloque 9 - Cierre comparativo

Responde esta pregunta final:

¿Qué cambia cuando pasamos de un BST común a estructuras balanceadas como AVL y Red-Black Tree?

La respuesta debe incluir obligatoriamente:

* Una afirmación sobre degeneración lineal del BST.
* Una afirmación sobre rotaciones y preservación del inorder.
* Una afirmación sobre balance por altura en AVL.
* Una afirmación sobre balance por colores en Red-Black Tree.
* Una afirmación sobre la diferencia entre balance estricto y balance flexible.
* Una afirmación sobre el costo esperado o garantizado de búsqueda, inserción y eliminación.
* Una afirmación sobre cómo esta semana continúa Semana 5 y Semana 6.
* Una afirmación sobre qué evidencia usarías para defender correctitud: pruebas, demostraciones, invariantes, trazados y complejidad.

Un BST comun puede degenerar a una forma casi lineal si se insertan los datos ya ordenados, por ejemplo insertar 1,2,3,4,5 en orden hace que cada nodo solo tenga hijo derecho y el arbol termine pareciendose a una lista enlazada con busquedas de costo O(n) en vez de O(log n), y eso es justo lo que cambia cuando pasamos a AVL y RedBlack Tree porque ambas usan rotaciones para reacomodar la estructura sin romper el orden, una rotacion solo cambia quien es padre y quien es hijo entre pocos nodos pero el recorrido inorder sigue dando la misma secuencia ordenada antes y despues, como vimos en el caso LL con 30,20,10 que termina con 20 de raiz pero el inorder sigue siendo 10,20,30. 
AVL logra su balance exigiendo que la diferencia de alturas entre los dos hijos de cualquier nodo sea como maximo uno, entonces rota apenas se rompe esa condicion, mientras que Red-Black Tree logra un balance mas relajado usando reglas de color, como que la raiz sea negra y que ningun nodo rojo tenga hijo rojo, y que la altura negra sea igual en todos los caminos hasta las hojas, por eso se dice que AVL tiene un balance estricto que prioriza busquedas muy rapidas a costa de rotar mas seguido, y RedBlack Tree tiene un balance flexible que tolera un poco mas de desnivel a cambio de necesitar menos rotaciones al insertar o eliminar. En cualquiera de los dos, a diferencia del BST comun, se garantiza que buscar insertar y eliminar cuesta O(log n) sin importar el orden en que lleguen los datos, ya no depende de la suerte como en un BST sin balance. Esta semana continua directamente lo que se vio en Semana 5 con el BST basico y sus recorridos, y lo que se vio en Semana 6 con Treap, que ya mostraba la idea de agregar una propiedad extra sobre el BST para lograr balance, solo que ahi era con prioridad aleatoria y aca es con altura o con color. Para defender que todo esto es correcto usaria una combinacion de pruebas automatizadas como las que corrimos con ctest que validan invariantes con datos aleatorios, trazados paso a paso de una insercion con rotacion para mostrar visualmente que pasa, y un argumento de complejidad que explique por que la altura queda acotada logaritmicamente, esa combinacion es mas solida que confiar en una sola de esas evidencias por separado.

#### Formato sugerido de entrega

```markdown
### Actividad 7 - CC232

#### Estudiante

- Nombre:

#### Bloque 1 - Diagnóstico inicial

[Tabla de comandos, resultados e interpretación]

#### Bloque 2 - BST como punto de partida

[Respuestas, dibujo y complejidad]

#### Bloque 3 - AVL

[Invariantes, trazado y evidencia]

#### Bloque 4 - Rotaciones AVL

[Tabla LL, RR, LR, RL y dibujos]

#### Bloque 5 - Red-Black Tree

[Invariantes, recoloreo, rotaciones y evidencia]

#### Bloque 6 - Comparación

[Tabla BST, Treap, AVL y Red-Black Tree]

#### Bloque 7 - Pruebas e invariantes

[Tabla de pruebas y defensa]

#### Bloque 8 - Ejercicios de codificación

[Código, evidencias, pruebas e interpretación]

#### Bloque 9 - Cierre comparativo

[Respuesta final]

#### Autoevaluación breve

- Qué puedo defender con seguridad:
- Qué todavía confundo:
- Qué evidencia usaría en una sustentación:
- Qué parte del código debo revisar otra vez:
```