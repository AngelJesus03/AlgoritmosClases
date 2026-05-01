Integrante
- Angel Navarro Ruiz (20231506A)

# Reverse Nodes in k-Group

> **Problema:** LeetCode 25 — [Reverse Nodes in k-Group](https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/)

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
You may not alter the values in the list's nodes, only nodes themselves may be changed.

Example 1:
Input: head = [1,2,3,4,5], k = 2
Output: [2,1,4,3,5]

Example 2:
Input: head = [1,2,3,4,5], k = 3
Output: [3,2,1,4,5]

Constraints:
- The number of nodes in the list is n.
- 1 <= k <= n <= 5000
- 0 <= Node.val <= 1000

### Tema principal
- Semana: 2 y 3
- Estructura o técnica principal: LList y Lista enlazada simple

## Entrada y salida

Las entradas del problema son dos cosas: 
- Primero, la cabeza de una lista enlazada (head), que representa una secuencia de nodos como [1,2,3,4,5].
- Segundo, un número entero positivo k, que indica el tamaño de los grupos en los que se deben invertir los nodos. Es importante que no trabajas con arrays directamente, sino con nodos enlazados (cada nodo apunta al siguiente).

La salida es la misma lista enlazada pero modificada: debes invertir los nodos en bloques de tamaño k. 
Por ejemplo, si k = 2, tomas pares de nodos y los inviertes: [1,2,3,4,5] → [2,1,4,3,5]. Si al final sobran nodos que no completan un grupo de tamaño k, esos se quedan igual.

## Tamaño de entrada relevante

El tamaño de entrada relevante es principalmente n, que es la cantidad de nodos en la lista enlazada, ya que determina cuántos elementos tienes que recorrer y manipular. Aunque también se da el valor k, este actúa más como un parámetro que define cómo agrupar los nodos, pero no cambia el tamaño de los datos en sí. Por eso, en términos de complejidad, lo más importante es n, porque cualquier solución tendrá que procesar, en el peor caso, todos los nodos de la lista.

## Descripción de la solución

# Solución

## Solución A — Intercambio de valores
 
Recorre la lista de grupo en grupo usando índices. Para cada grupo de `k` elementos, intercambia los valores desde los extremos hacia el centro usando `get` y `set`.
 
 
```
función reverseKGroupValues(list, k):
    n = list.tamaño()
    para i desde 0 hasta n con saltos de k:
        si i + k > n: detener
        left  = i
        right = i + k - 1
        mientras left < right:
            intercambiar valores en posiciones left y right
            left++
            right--
```
 
---
 
## Solución B — Inversión de nodos (correcta)
 
Verifica si hay al menos `k` nodos disponibles. Si los hay, invierte esos `k` nodos redirigiendo sus punteros. Luego conecta el grupo invertido con el resultado de aplicar recursivamente la misma operación al resto de la lista.
  
```
función reverseKGroupNodes(head, k):
    contar k nodos desde head
    si hay menos de k nodos:
        retornar head tal como está
 
    prev = nulo
    curr = head
    para i desde 0 hasta k:
        next       = curr->siguiente
        curr->siguiente = prev
        prev       = curr
        curr       = next
 
    head->siguiente = reverseKGroupNodes(curr, k)
    retornar prev
```
 
---

# Análisis de Soluciones
 
## Solución B
 
**Justificación de determinismo y factibilidad**

La Solución es determinista porque para la misma entrada siempre produce la misma salida, la inversión de punteros sigue un orden fijo y predecible sin ninguna aleatoriedad. 

Es factible porque solo usa unos pocos punteros auxiliares (prev, curr, next, check), cada nodo se toca exactamente una vez, y los constraints del problema garantizan que n <= 5000, por lo que los recursos necesarios siempre son manejables.

**Argumento de finitud**

La Solución B es finita porque cada llamada recursiva avanza exactamente k nodos hacia adelante, reduciendo el tamaño de la lista restante en k en cada paso. Como la lista tiene n nodos finitos y k >= 1, la recursión hace a lo sumo n/k llamadas antes de llegar al caso base, que es cuando quedan menos de k nodos y se retorna inmediatamente sin hacer más llamadas.

**Argumento de correctitud**

Es correcta porque garantiza dos cosas: que cada grupo de exactamente k nodos queda invertido, y que los nodos sobrantes quedan intactos. Al terminar el for, prev apunta al nuevo head del grupo invertido y head (el nodo que era la cabeza) queda como la cola, conectándose correctamente con el resultado del siguiente grupo via head->next = reverseKGroupNodes(curr, k).

**Invariante**

Al finalizar el ciclo `for`, los primeros `k` nodos están invertidos y `prev` apunta al nuevo `head` del grupo. `curr` apunta al primer nodo no procesado.
 
**Monotonicidad**

En cada llamada recursiva, el tamaño de la lista restante se reduce estrictamente en k nodos. Como k >= 1 y n es finito, esta reducción garantiza que el algoritmo converge hacia el caso base — cuando quedan menos de k nodos — de forma estrictamente decreciente, sin posibilidad de estancarse.
 
---

# Complejidad Temporal

### Análisis por caso
 
| Caso | Solución A | Solución B |
|---|---|---|
| Mejor caso | O(n) con k=1 | O(n) con k=1 |
| Caso promedio | O(n²) | O(n) |
| Peor caso | O(n²) con k=n/2 | O(n) |
 
### Notación asintótica
 
| | Solución A | Solución B |
|---|---|---|
| **Tiempo** | O(n²) | O(n) |
| **Espacio** | O(1) | O(n/k) |
 
### Justificación
 
- **Solución A:** `get` y `set` recorren la lista desde `head` cada vez que se llaman, acumulando O(n) por cada uno de los n intercambios → O(n²) en total.
- **Solución B:** Cada nodo es visitado exactamente una vez para redirigir su puntero → O(n). El espacio O(n/k) corresponde a la pila de recursión, que tiene una llamada por cada grupo.
---

## Discusión de robustez, degeneración y reutilización

### Robustez
 
Maneja correctamente todos los casos posibles sin romperse. Si k=1 la lista no se modifica porque cada grupo de un solo nodo invertido es él mismo. Si k=n la lista se invierte completamente en una sola llamada. Si la lista tiene un solo nodo, la verificación count < k lo detecta y retorna inmediatamente. Si los nodos sobrantes no completan un grupo, también los detecta y los deja intactos. En ningún caso el algoritmo accede a memoria inválida o produce comportamiento inesperado.

### Degeneración
 
La solución no es degenerada en tiempo ya que siempre es O(n) independientemente de los valores de k o de los datos. Sin embargo, con listas muy largas y k=1, la pila de recursión crece hasta O(n) porque se hace una llamada recursiva por cada nodo, lo que para valores de n cercanos a 5000 podría causar un stack overflow. En ese caso específico, una versión iterativa sería más segura.

### Reutilización
 
- `SLList` con sus métodos `add`, `get`, `set` y `size` puede reutilizarse en otros problemas que requieran una lista enlazada simple.
- `reverseKGroupNodes` puede adaptarse fácilmente para invertir segmentos de cualquier lista enlazada, no necesariamente de k en k.
---

## Instrucciones para compilar

### Requisitos previos

- g++ con soporte C++17
- CMake 3.20 o superior
- Sistema Linux o WSL

### Compilación con CMake (recomendado)

Desde la raíz del proyecto:

```bash
# Configura el proyecto y genera los archivos de compilación
cmake -B build

# Compila todos los ejecutables
cmake --build build
```

Esto genera tres ejecutables dentro de `build/`:
- `build/demo` — ejecutable principal
- `build/tests` — suite de pruebas
- `build/benchmark` — experimento de rendimiento


### Correr el benchmark

```bash
./build/benchmark
```

Salida esperada:

```
Tamaño     Opcion A O(n^2) ms       Opcion B O(n) ms         
------------------------------------------------------------
100         0.0215                   0.0083                   
1000        2.0501                   0.0758                   
10000       157.5813                 0.7322 

```
## Benchmark realizado
 
Se implementó un benchmark en `benchmark/benchmark.cpp` que compara las dos soluciones (intercambio de valores y manipulación de punteros) para tamaños de entrada de 100 a 10,000 nodos. Cada medición promedia 10 repeticiones usando `std::chrono::high_resolution_clock`. Las listas de prueba se generan con `buildListSeq(n)` y `buildSLListSeq(n)`, que construyen listas secuenciales de 1 a `n`. En ambos casos se usa `k = n/2` para maximizar el trabajo del algoritmo y hacer la comparativa más representativa.



