#### Respuestas obligatorias

1. ¿Cuál es el problema exacto asignado?

El problema asignado es el de eliminar el késimo elemento vivo de una lista de n elementos, donde cada eliminación reindexa los elementos restantes. Se deben procesar n eliminaciones y se requiere una solución eficiente que cumpla con las restricciones del problema.

2. ¿Qué recibe la entrada y qué produce la salida?

- La entrada consiste en un número n que indica la cantidad de elementos iniciales, seguido de n números que representan las posiciones k de los elementos a eliminar. 
- La salida es una secuencia de n números que representan los índices reales de los elementos eliminados en el orden en que fueron eliminados.

3. ¿Cuál es la restricción que vuelve insuficiente una solución ingenua?

La restricción de n hasta 10^5 hace que una solución ingenua con un arreglo simple, donde cada eliminación desplaza los elementos siguientes, tenga un costo O(n^2) en el peor caso, lo cual es inaceptable para n tan grande.

4. ¿Cuál sería la solución ingenua y cuál es su complejidad?

La solución ingenua consiste en mantener un arreglo de los elementos vivos y, para cada eliminación, desplazar los elementos siguientes para llenar el espacio del elemento eliminado, esto tiene una complejidad de O(n) por eliminación, resultando en O(n^2) para n eliminaciones.

5. ¿Qué estructura de datos elegiste?

Elegí un Segment Tree donde cada nodo almacena la cantidad de elementos vivos en su rango, esto permite encontrar el késimo elemento vivo en O(log n) y eliminarlo también en O(log n) actualizando los contadores hacia arriba. Lo elegí porque permite manejar eficientemente las eliminaciones y reindexaciones dinámicas sin necesidad de desplazar elementos, a diferencia de un arreglo simple.

6. ¿Qué estructura de la librería cc232 se parece más?

Se parece más a BinaryHeap de la Semana 5, ya que ambos usan una representación implícita en un arreglo para un árbol binario. En el Segment Tree, cada nodo representa un rango de elementos y guarda la cantidad de elementos vivos en ese rango, mientras que en BinaryHeap cada nodo representa un elemento y se conserva la propiedad de heap, los dos usan fórmulas de índice para moverse por el árbol sin punteros.

7. ¿Qué operación domina el tiempo?

La operación que domina el tiempo es la de encontrar y eliminar el késimo elemento vivo, ya que cada eliminación requiere encontrar el índice real del elemento a eliminar y luego actualizar el Segment Tree, ambas operaciones tienen un costo de O(log n).

8. ¿Qué invariante mantiene tu estructura?

Cada nodo del árbol mantiene exactamente la cantidad de elementos que hay disponibles en su rango, después de cada eliminación se actualizan todos los ancestros de la hoja eliminada sumando sus dos hijos, esto es lo que asegura que la operación de encontrar el késimo elemento vivo siempre encuentre el índice real correcto del elemento disponible.

9. ¿Dónde se actualiza ese invariante en el código?

En remove, al volver de la recursión:
```cpp
tree[node] = tree[2*node+1] + tree[2*node+2];
```

10. ¿Cuál es la complejidad temporal por operación?

La complejidad temporal es de O(log n) cada operación (build por nodo, remove, kesimo) recorre la altura del árbol que es log2(n) aproximadamente igual a 17 para n=2·10⁵.

11. ¿Cuál es la complejidad total?

Tiempo total O(n log n) con n operaciones de O(log n). 

12. ¿Cuál es la complejidad espacial?

Espacio O(n) el arreglo tree ocupa 4n posiciones, con n=2*10^5 son 800000 enteros aproximado a 3MB.

13. ¿Qué alternativa de estructura existe y qué perderías con ella?

Una alternativa al Segment Tree podría ser un Balanced Binary Search Tree (AVL o Red-Black Tree por ejemplo) donde cada nodo mantiene el tamaño de su subárbol para encontrar el késimo elemento vivo. Sin embargo, esto sería más difícil de implementar y mantener, y las operaciones podrían ser más lentas debido a que se necesitan rotaciones para mantener el balanceo, lo cual podría incrementar la complejidad temporal a O(log n) amortizado, pero con un costo constante más alto.

14. ¿Qué demuestra que no es una solución de caja negra?

Las tres funciones (build, remove, kesimo) están implementadas desde cero sin librerías externas, tratando de seguir la estructura de árbol implícito en arreglo que BinaryHeap de la Semana 5 trabajada en clase. Cada línea tiene una justificación directa y en el video se muestra que se entiende el código y la lógica detrás de cada función explicandose paso a paso.

#### Preguntas específicas del problema

1. ¿Qué significa remover el k-ésimo vivo?

Cuando decimos que está vivo significa que el elemento aún no ha sido eliminado por lo cual remover el késimo vivo significa eliminar el elemento que es el késimo en orden entre los elementos que aún no han sido eliminados, considerando que después de cada eliminación los elementos restantes se reindexan.

2. ¿Dónde se actualiza size?

No hay un size como tal en la implementación del Segment Tree, el tamaño se maneja implícitamente a través de los contadores en cada nodo del árbol que indican cuántos elementos vivos hay en ese rango, el tamaño total se reflejaría en el nodo raíz tree[1].

3. ¿Por qué una lista o vector directo no basta?

Porque eliminar un elemento del medio o del inicio nos obligaría a desplazar todos los elementos siguientes para llenar el espacio, lo cual tiene un costo de O(n) por eliminación, resultando en O(n^2) para n eliminaciones, lo que es inaceptable para n hasta 10^5. En cambio, con un Segment Tree podemos eliminar y reindexar en O(log n) sin necesidad de desplazar elementos.