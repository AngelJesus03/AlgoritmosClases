### PC3 - CC232

#### Estudiante

- Nombre: Angel Jesus Navarro Ruiz
- Código: 20231506A
- Problema asignado: CSES - List Removals
- Enlace oficial: https://cses.fi/problemset/task/1749

#### Referencia oficial

- CSV oficial:
  https://github.com/kapumota/CC-232/blob/main/Practicas/Practica3_CC232/Problemas-Evaluacion3.csv

#### Relación con Semanas 4-6

- Semana principal: Semana 5 y 6
- Estructura usada: Segment Tree (árbol implícito en arreglo)
- Estructura de la librería `cc232` relacionada: BinaryHeap (Semana 5) - comparte la misma idea de árbol binario representado implícitamente en un arreglo con fórmulas de índice 2*i, 2*i+1, 2*i+2

#### Resumen de la solución

El problema consiste en eliminar elementos de una lista en posiciones dinámicas, cada vez que se elimina un elemento, las posiciones se reindexan. La solución intuitiva con un arreglo simple tiene costo O(n^2) porque cada eliminación desplaza todos los elementos siguientes.

La solución eficiente usa un Segment Tree donde cada nodo guarda cuántos elementos siguen disponibles en su rango. Para encontrar el k ésimo elemento disponible se baja por el árbol comparando ese contador, si el subárbol izquierdo tiene k o más elementos, se busca ahí; si no, se descuenta y se busca en el derecho. Una vez encontrado el índice real, se elimina marcando su hoja como 0 y actualizando los contadores hacia arriba.

Esta estructura es adecuada porque comparte la misma representación implícita en arreglo que BinaryHeap de Semana 5 donde el árbol se guarda en un vector con fórmulas de índice sin punteros. Cada eliminación cuesta O(log n), haciendo el total O(n log n) lo cual essuficiente para las restricciones del problema.

#### Invariante principal

Después de cada operación el Segment Tree mantiene que cada nodo guarda exactamente la cantidad de elementos disponibles en su rango. 
- Al insertar, todos los nodos que cubren esa posición tienen su contador en 1. 
- Al eliminar, la hoja correspondiente pasa a 0 y todos sus ancestros se actualizan sumando sus dos hijos. 
Esto garantiza que kesimo(k) siempre encuentra el índice real correcto del késimo elemento disponible.

#### Complejidad

- Tiempo por operación: O(log n) cada operación recorre la altura del árbol
- Tiempo total: O(n log n) n operaciones de O(log n)
- Espacio: O(n) el arreglo del Segment Tree ocupa 4n posiciones

#### Archivos relevantes

Indica qué contiene cada carpeta o archivo importante.

- `include/` :Header que contiene ladeclaración de SegmentTree y ListaIngenua
- `src/`: Implementación de SegmentTree y ListaIngenua donde econtramos build, remove, kesimo y solución ingenua
- `tests/` :Pruebas con assert para la solución eficiente
- `demos/` :Ejemplos de uso y pruebas manuales para una comprensión mejor
- `docs/respuestas_obligatorias.md` :Respuestas a las preguntas comunes obligatorias y específicas del problema
- `docs/bitacora.md` :Resumen del proceso real de desarrollo.
- `resultados/` :Resultados de pruebas y comparaciones de tiempos entre la solución eficiente e ingenua

#### Limpieza del repositorio

El repositorio no debe versionar builds, ejecutables ni archivos generados.

No deben aparecer archivos como:

- `build/`
- `cmake-build-*`
- `.exe`
- `.out`
- `.o`
- `.obj`
- `CMakeCache.txt`
- `CMakeFiles/`
- `__pycache__/`

Comando sugerido para verificar archivos generados versionados:

```bash
git ls-files | grep -E "(^build/|cmake-build|\.exe$|\.out$|\.o$|\.obj$|CMakeCache.txt|CMakeFiles|__pycache__)"
```

Si el comando muestra resultados, el estudiante debe explicar por qué existen.  
En general, estos archivos deben eliminarse del repositorio y agregarse al `.gitignore`.

#### Compilación

El proyecto debe compilar desde una copia limpia del repositorio.

```bash
cmake -S . -B build
cmake --build build
```

#### Ejecución

Indica el comando exacto para ejecutar el programa principal.

```bash
./build/nombre_del_programa
```

#### Pruebas

Describe al menos 5 pruebas, incluyendo casos borde.

Cada prueba debe indicar:

- entrada usada;
- salida esperada;
- salida obtenida;
- qué aspecto valida.

Ejemplo de lista mínima:

1. Caso mínimo.
2. Caso con estructura vacía, frontera o ausencia de respuesta.
3. Caso con duplicados o empates.
4. Caso extremo pequeño verificable manualmente.
5. Caso comparado contra una solución ingenua, si aplica.

#### Evidencia Git

El video debe iniciar mostrando el historial de commits, fechas, archivos modificados y explicación del proceso real de desarrollo.

Comandos obligatorios:

```bash
git status
git log --date=short --pretty=format:"%ad - %h - %an - %s"
git log --date=short --pretty=format:"%ad" | sort | uniq -c
git log --graph --oneline --decorate --all
git log --date=short --name-status --pretty=format:"%ad - %h - %s" -- Semana4 Semana5 Semana6 Practicas practica-calificada3
git log --date=short --stat --pretty=format:"%ad - %h - %s"
```

El estudiante debe explicar:

- qué commits corresponden a actividades de clase;
- qué commits corresponden a la práctica calificada;
- qué archivos cambiaron;
- qué pruebas se agregaron;
- qué errores se corrigieron;
- por qué el historial demuestra trabajo progresivo.

#### Bitácora obligatoria

Debe existir el archivo:

```text
docs/bitacora.md
```

La bitácora debe resumir el proceso real de desarrollo:

- día de avance;
- problema trabajado;
- estructura implementada;
- errores encontrados;
- pruebas agregadas;
- cambios importantes;
- relación con commits.

#### Benchmark

Comparación de tiempos promedio entre ambas soluciones (10 repeticiones por tamaño):

| Tamaño | ListaIngenua O(n²) ms | SegmentTree O(n log n) ms |
|--------|----------------------|--------------------------|
| 100    | 0.7284               | 2.6942                   |
| 1000   | 1.3166               | 2.3942                   |
| 10000  | 78.2384              | 5.1627                   |
| 100000 | 8403.4452            | 38.0833                  |

## Observaciones:
- Para n pequeño la ListaIngenua es más rápida por el overhead de construcción del Segment Tree.
- A partir de n=10000 el Segment Tree es notablemente más eficiente.
- Para n=100000 el Segment Tree es aproximadamente 220x más rápido.
- La diferencia seguirá creciendo conforme n se acerque al límite del constraint (2·10⁵).

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

#### Declaración de autoría

Declaro que entiendo el código entregado, que puedo explicarlo, compilarlo, ejecutarlo y modificarlo sin ayuda externa durante la grabación.  
También declaro que el repositorio entregado corresponde al trabajo mostrado en el video y que no contiene builds, ejecutables ni archivos generados usados para aparentar funcionamiento.