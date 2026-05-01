Alumno: Angel Navarro Ruiz 20231506A

### Actividad 3 - Semana 3

- Duración: 3 horas de clase.
- Modalidad: Trabajo en parejas.
- Tiempo de instalación: 15 minutos al inicio.
- Entrega: Un archivo llamado `actividad3-CC232.md`.

#### Objetivo

Consolidar lo trabajado en la Semana 3 a partir de código, demos, pruebas y una defensa escrita breve.

La meta es distinguir con claridad qué cambia cuando pasamos de representaciones contiguas a representaciones enlazadas, por qué en una lista enlazada el acceso importante deja de ser por rango y pasa a ser por posición o enlace, cómo una `SLList` implementa muy bien operaciones de `Stack` y `Queue`, cómo una `DLList` con nodo centinela simplifica inserciones y eliminaciones, y por qué una `SEList` ofrece un trade-off entre acceso, actualización local y uso de espacio.

Además, se busca conectar las implementaciones enlazadas de Morin con la interfaz y operaciones de lista reforzadas por Deng, incluyendo el uso de `DengList` y `MorinDengBridge` para reutilizar operaciones como ordenamiento, eliminación de duplicados y reversa sin reescribir toda la lógica estructural.

#### Material de trabajo

##### Código de la semana
- `Semana3/README.md`
- `Semana3/include/SLList.h`
- `Semana3/include/DLList.h`
- `Semana3/include/SEList.h`
- `Semana3/include/ArrayDeque.h`
- `Semana3/include/array.h`
- `Semana3/include/LinkedStack.h`
- `Semana3/include/LinkedQueue.h`
- `Semana3/include/LinkedDeque.h`
- `Semana3/include/MinStack.h`
- `Semana3/include/MinQueue.h`
- `Semana3/include/MinDeque.h`
- `Semana3/include/XorList.h`
- `Semana3/include/CleanList.h`
- `Semana3/include/DengList.h`
- `Semana3/include/MorinDengBridge.h`
- `Semana3/include/Capitulo3.h`
- `Semana3/demos/demo_sllist.cpp`
- `Semana3/demos/demo_dllist.cpp`
- `Semana3/demos/demo_selist.cpp`
- `Semana3/demos/demo_deng_list.cpp`
- `Semana3/demos/demo_morin_deng_bridge.cpp`
- `Semana3/demos/demo_capitulo3_panorama.cpp`
- `Semana3/demos/demo_min_structures.cpp`
- `Semana3/demos/demo_xor_list.cpp`
- `Semana3/demos/demo_linked_adapters.cpp`
- `Semana3/demos/demo_contiguous_vs_linked.cpp`
- `Semana3/pruebas_publicas/README.md`
- `Semana3/pruebas_publicas/test_public_week3.cpp`
- `Semana3/pruebas_publicas/test_public_deng_bridge.cpp`
- `Semana3/pruebas_publicas/test_public_extras.cpp`
- `Semana3/pruebas_publicas/test_public_linked_adapters.cpp`
- `Semana3/pruebas_publicas/test_public_contiguous_vs_linked.cpp`
- `Semana3/pruebas_internas/test_internal_week3.cpp`
- `Semana3/pruebas_internas/test_internal_deng_algorithms.cpp`
- `Semana3/pruebas_internas/test_internal_extras.cpp`
- `Semana3/pruebas_internas/stress_selist_week3.cpp`
- `Semana3/sustentacion/preguntas_semana3.md`
- `Semana3/sustentacion/rubrica_semana3.md`
- `Semana3/benchmarks/benchmark_semana3.cpp`

#### Lecturas obligatorias

- `Parte3-Deng.pdf`
- `Parte3-Morin.pdf`

#### Bloque 0 - Instalación y preparación

1. Dejen lista su carpeta de trabajo.
2. Verifiquen que pueden abrir `Semana3`, las lecturas y el archivo de entrega.
3. Creen el archivo `Actividad3-CC232.md`.
4. Anoten los nombres de los integrantes.
5. Compilen y ejecuten al menos una demo y una prueba pública de Semana 3.

#### Bloque 1 - Núcleo conceptual de la semana

Revisen:

- `Semana3/README.md`
- `Parte3-Deng.pdf`
- `Parte3-Morin.pdf`
- `Semana3/include/SLList.h`
- `Semana3/include/DLList.h`
- `Semana3/include/SEList.h`
- `Semana3/include/DengList.h`
- `Semana3/include/MorinDengBridge.h`

Respondan:

1. Expliquen con sus palabras qué cambia cuando una estructura pasa de almacenamiento contiguo a almacenamiento dinámico.

Lo que cambia de almacenamiento contiguo y almacenamiento dinámico es el cómo se almacenan los datos, en el almacenamiento contiguo los datos están todos juntos por lo cual si se quiere agregar un elemento se hace muy costoso sin embargo al querer acceder se hace de manera rápida, por otro lado, el almacenamiento dinámico es todo lo contrario ya que el almacenamiento de sus elementos están separados.

2. Expliquen la diferencia entre acceso por rango y acceso por posición o enlace.

El acceso por rango es más beneficioso ya que al estar todos los datos juntos puedes acceder al elemento mediante una simple operación O(1), sin embargo, el acceso por posición tienes que recorrer toda la estructura, nodo por nodo siguiendo los punteros lo que hace que tenga una complejidad O(n).

3. Expliquen por qué una lista enlazada mejora inserciones y eliminaciones locales, pero empeora el acceso por índice.

Una lista enlazada es muy superior al insertar y eliminar elementos ya que solo es cuestión de cambiar los punteros, es decir actualizar el pred o succ lo que nos llegaría a costar O(1), por otro lado el acceso por índice .

4. Expliquen por qué `SLList` implementa bien operaciones de `Stack` y `Queue`.

SLList implementa bien Stack y Queue porque en ambas estructuras se puede insetar y eliminar los elementos en los extremos con una complejidad O(1). Para Stack (LIFO) push agregar al inicio (head) y remove elimina el inicio. Para Queue (FIFO) add agrega al final y remove elimina el inicio.

5. Expliquen por qué `SLList` no implementa naturalmente todas las operaciones de un `Deque` con el mismo costo.

Un Deque necesita insertar y eliminar en ambos extremos en O(1). SLList puede hacer push y add en O(1) (front y back), pero removeLast requiere recorrer toda la lista para encontrar el penúltimo nodo antes de eliminar el último, porque los punteros solo van hacia adelante. Sin un puntero prev, eliminar del final cuesta O(n).


6. Expliquen qué aporta el nodo centinela `dummy` en `DLList`.

El nodo dummy es un nodo "falso" que siempre existe y conecta el inicio con el final de la lista formando un ciclo. Esto elimina los casos especiales: ya no hay que preguntar "¿la lista está vacía?" o "¿es el primer o último nodo?" al insertar o eliminar, porque el dummy siempre está ahí y los punteros nunca quedan nulos. Todo el código de inserción y eliminación queda igual para cualquier posición.


7. Expliquen por qué `DLList` permite justificar `get(i)`, `set(i,x)`, `add(i,x)` y `remove(i)` con costo `O(1 + min(i, n-i))`.

Porque getNode(i) elige inteligentemente desde qué extremo empezar: si i < n/2 parte desde el dummy.next (inicio), y si i >= n/2 parte desde dummy.prev (final). Así nunca recorre más de la mitad de la lista. Una vez ubicado el nodo, las operaciones de enlace son O(1). Por eso el costo es proporcional a la distancia al extremo más cercano.


8. Expliquen cuál es la idea espacial central de `SEList`.

En lugar de tener un nodo por elemento (como SLList o DLList), agrupa los elementos en pequeños bloques (BDeque) de tamaño aproximado b. Cada bloque es un nodo de la lista enlazada. Así se reduce el overhead de punteros: en vez de un puntero por elemento, hay un puntero por bloque. Es un punto intermedio entre arreglo (un bloque grande) y lista enlazada clásica (bloques de tamaño 1).


9. Expliquen por qué `SEList` reutiliza una `BDeque` basada en `ArrayDeque`.

Porque dentro de cada bloque se necesita poder insertar y eliminar eficientemente por los dos extremos (para los casos de spread y gather). Un ArrayDeque implementado con un buffer circular hace exactamente eso en O(1). La BDeque simplemente hereda de ArrayDeque pero deshabilita el resize automático, porque el tamaño máximo del bloque es fijo (b+1).


10. Expliquen qué papel cumple `DengList` dentro de esta semana y por qué no reemplaza a las estructuras de Morin.

DengList es una lista con operaciones adicionales de alto nivel: ordenar, eliminar duplicados, revertir, buscar. Su valor es que ofrece una interfaz más rica para algoritmos. Pero no reemplaza a SLList, DLList o SEList porque estas tienen propiedades estructurales específicas (localidad, costo de acceso vs. actualización, uso de memoria) que se estudian en sí mismas. DengList es una herramienta algorítmica, no una estructura de datos con el mismo propósito.

#### Bloque 2 - Demostración y trazado guiado

Revisen:

- `Semana3/demos/demo_sllist.cpp`
- `Semana3/demos/demo_dllist.cpp`
- `Semana3/demos/demo_selist.cpp`
- `Semana3/demos/demo_deng_list.cpp`
- `Semana3/demos/demo_morin_deng_bridge.cpp`
- `Semana3/demos/demo_capitulo3_panorama.cpp`
- `Semana3/demos/demo_min_structures.cpp`
- `Semana3/demos/demo_xor_list.cpp`
- `Semana3/demos/demo_linked_adapters.cpp`
- `Semana3/demos/demo_contiguous_vs_linked.cpp`

Construyan una tabla con cuatro columnas:

- Archivo
- Salida u observable importante
- Idea estructural
- Argumento de costo, espacio o diseño

demo_dllist.cpp -- 

Luego respondan:

1. En `demo_sllist.cpp`, ¿qué secuencia deja más clara la coexistencia de comportamiento tipo pila y tipo cola dentro de `SLList`?

La secuencia que deja clara la coexistencia es: q.add(10) , q.add(20) , q.push(5)
- Comportamiento de queue con add(10) y add(20) agregarndo al final.
- Comportamiento de stack con push(5) agregando al inicio.

2. En `demo_dllist.cpp`, ¿qué operación muestra mejor la inserción en una posición intermedia?

La operación que muestra mejor la posición intermedia es d.add(1,20).

3. En `demo_selist.cpp`, ¿qué observable permite defender que la lista mantiene orden lógico aunque internamente trabaje por bloques?

El observable es recorrer la lista con s.get(i).

4. En `demo_deng_list.cpp`, ¿qué evidencia muestra que la lista reforzada por Deng ofrece operaciones más cercanas a un ADT de lista completo?

La evidencias como push_back, push_front, size(), front() lo cual muestra que no es solo una lista básica, ofrece operaciones de inserción, acceso a extremos, tamaño y método de ordenamiento.

5. En `demo_morin_deng_bridge.cpp`, ¿qué parte de la salida permite justificar que se reutilizan algoritmos sin reescribir la estructura base?

Lo que justifica la reutilización en demo_morin_deng_bridge.cpp es que la DLList original nunca se modifica estructuralmente: solo se convierte a DengList, se opera, y se vuelve a cargar. El algoritmo de ordenamiento o dedup no sabe ni necesita saber que la estructura base es una DLList.

6. En `demo_min_structures.cpp`, ¿qué diferencia conceptual observan entre almacenar valores y almacenar información adicional para responder `min()`?

La diferencia conceptual en demo_min_structures.cpp es que almacenar solo el valor no da información sobre el contexto acumulado, mientras que almacenar también el mínimo hasta ese punto permite responder min() sin recorrer nada, a costa de memoria adicional.

7. En `demo_linked_adapters.cpp`, ¿qué adaptador representa mejor la idea de reutilizar una estructura existente para ofrecer una interfaz nueva?

El adaptador que mejor representa reutilización es LinkedDeque sobre DLList, porque DLList ya soporta operaciones en ambos extremos y LinkedDeque simplemente les da una interfaz con nombres semánticos (addFirst, removeLast, etc.) sin agregar ninguna lógica nueva.

8. En `demo_contiguous_vs_linked.cpp`, ¿qué contraste se observa entre acceso por índice, inserción local y localidad de memoria?

El contraste más claro en demo_contiguous_vs_linked.cpp es que el acceso aleatorio (get por índice) es casi inmediato en ArrayDeque y lento en DLList, mientras que la inserción en el medio es costosa en ArrayDeque (desplaza elementos) y barata en DLList (solo reencadena punteros). La localidad de memoria hace que ArrayDeque sea más amigable para el caché del procesador.

#### Bloque 3 - Pruebas públicas, stress y correctitud

Revisen:

- `Semana3/pruebas_publicas/README.md`
- `Semana3/pruebas_publicas/test_public_week3.cpp`
- `Semana3/pruebas_publicas/test_public_deng_bridge.cpp`
- `Semana3/pruebas_publicas/test_public_extras.cpp`
- `Semana3/pruebas_publicas/test_public_linked_adapters.cpp`
- `Semana3/pruebas_publicas/test_public_contiguous_vs_linked.cpp`
- `Semana3/pruebas_internas/test_internal_week3.cpp`
- `Semana3/pruebas_internas/test_internal_deng_algorithms.cpp`
- `Semana3/pruebas_internas/test_internal_extras.cpp`
- `Semana3/pruebas_internas/stress_selist_week3.cpp`

Respondan:

1. ¿Qué operaciones mínimas valida la prueba pública para `SLList`?

Las operaciones que valida son add para agregar al final, push para agregar al inicio, size para obtener tamaño, peek y remove.

2. ¿Qué operaciones mínimas valida la prueba pública para `DLList`?

Las operaciones que valida son add(i,x) para agregar en posiciones específicas, size, get y remove por indice.

3. ¿Qué operaciones mínimas valida la prueba pública para `SEList`?

Valida las mismas que en la pregunta numero 2 más set(i,x) lo cual es modificacion por índice.

4. ¿Qué operaciones nuevas quedan cubiertas por `test_public_extras.cpp`?

test_public_extras.cpp agrega cobertura para: secondLast() y reverse() en SLList, rotate(), isPalindrome() y checkSize() en DLList, y las estructuras MinStack, MinQueue, MinDeque y XorList.

5. ¿Qué valida específicamente `test_public_linked_adapters.cpp` sobre `LinkedStack`, `LinkedQueue` y `LinkedDeque`?

test_public_linked_adapters.cpp valida que LinkedStack tenga semántica LIFO correcta (push/pop/top), que LinkedQueue tenga semántica FIFO (add/remove/front), y que LinkedDeque soporte inserciones y eliminaciones correctas en ambos extremos.

6. ¿Qué demuestra `test_public_deng_bridge.cpp` sobre integración y reutilización?

test_public_deng_bridge.cpp demuestra que DengList funciona como ADT completo (push_front, push_back, add, get, contains, find_index), y que el puente stable_sort_with_deng, dedup_with_deng y reverse_with_deng transforma correctamente tanto DLList como SEList sin perder sus datos.

7. En `stress_selist_week3.cpp`, ¿qué comportamiento intenta estresar sobre crecimiento, borrado y mantenimiento del tamaño lógico?

stress_selist_week3.cpp intenta estresar el crecimiento continuo de la SEList (muchos add), luego borrado masivo, verificando que el tamaño lógico n sea siempre consistente con los elementos reales y que los bloques internos se mantengan dentro del rango [b/2, b+1] según la invariante.

8. ¿Qué sí demuestra una prueba pública sobre una estructura enlazada?

Una prueba pública sí demuestra que la interfaz externa funciona correctamente para los casos probados: que los valores se guardan, se recuperan, se modifican y se eliminan como se espera.

9. ¿Qué no demuestra una prueba pública por sí sola?

Una prueba pública no demuestra que los punteros internos estén bien encadenados en todos los casos, que la complejidad sea la esperada, que no haya memory leaks, ni que las invariantes estructurales se mantengan bajo combinaciones arbitrarias de operaciones.

10. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes, punteros y complejidad?

Pasar pruebas no reemplaza la explicación porque las pruebas solo verifican comportamiento observable en casos específicos. Invariantes como "el tail siempre apunta al último nodo", "los punteros prev y next son siempre consistentes", o "cada bloque tiene entre b/2 y b+1 elementos" no se pueden observar directamente desde afuera: hay que razonar sobre el código y justificarlas.

#### Bloque 4 - SLList, DLList y SEList: lectura cercana del código

Revisen:

- `Semana3/include/SLList.h`
- `Semana3/include/DLList.h`
- `Semana3/include/SEList.h`
- `Parte3-Morin.pdf`
- `Parte3-Deng.pdf`

Respondan:

1. En `SLList`, ¿qué papel cumplen `head`, `tail` y `n`?

En SLList: head apunta al primer nodo (desde donde se hace push/pop), tail apunta al último (donde se hace add), y n guarda el contador de elementos para que size() sea O(1) sin recorrer la lista.

2. En `SLList::push`, `pop`, `add` y `remove`, ¿qué punteros cambian exactamente?

En push: se crea un nodo nuevo, su next apunta al head actual, y head pasa a ser ese nuevo nodo (si era vacía, tail también apunta ahí). En pop/remove: head avanza al siguiente nodo y el nodo anterior se libera; si queda vacía, tail se pone a nullptr. En add al fondo: el next del tail actual apunta al nuevo nodo y tail se actualiza. En removeAt(i): se llega al nodo anterior (i-1), se reconecta su next al nodo que sigue al eliminado, y si era el tail se actualiza tail.

3. Expliquen cómo funciona `secondLast()` y por qué no puede resolverse directamente con solo mirar `tail`.

secondLast() no puede resolverse con solo mirar tail porque tail apunta al último, pero no hay puntero hacia atrás. Para saber quién es el penúltimo hay que recorrer desde head hasta encontrar el nodo cuyo next es tail. Es O(n) inevitablemente en una lista simplemente enlazada.

4. Expliquen paso a paso cómo funciona `reverse()` y por qué no necesita estructura auxiliar.

reverse() funciona así: se inicializa prev = nullptr y curr = head. En cada paso se guarda curr->next en next, luego curr->next se pone a apuntar a prev (invirtiendo el enlace), luego prev = curr y curr = next. Al terminar, prev es el nuevo head. El viejo head se convierte en el nuevo tail (por eso al inicio se hace tail = head). No necesita estructura auxiliar porque solo redirige punteros existentes.

5. Expliquen qué verifica `checkSize()` y por qué esta función ayuda a defender correctitud.

checkSize() recorre la lista contando cuántos nodos hay realmente y verifica que ese conteo coincida con n. También verifica que tail apunte al último nodo real, y que si n == 0 entonces head y tail sean nullptr. Ayuda a defender correctitud porque puede detectar inconsistencias entre el contador y la estructura real.

6. En `DLList`, expliquen por qué `getNode(i)` puede empezar desde el inicio o desde el final.

getNode(i) empieza desde dummy.next (inicio) si i < n/2, y desde dummy.prev (final) si i >= n/2. Así nunca recorre más de n/2 nodos. La razón es que la lista es circular con dummy, entonces desde el final se llega yendo hacia atrás con prev.

7. En `DLList::addBefore`, ¿qué enlaces se actualizan y por qué el nodo centinela elimina casos borde?

En addBefore(w, x): se crea un nodo u con u->prev = w->prev y u->next = w. Luego u->prev->next = u (el nodo antes de w ahora apunta a u), y u->next->prev = u (w ahora apunta hacia atrás a u). Son exactamente 4 asignaciones de punteros, siempre. El dummy elimina casos borde porque nunca hay nodo cuyo prev o next sea nullptr: dummy.next y dummy.prev siempre existen, así que insertar al inicio o al final es el mismo código que insertar en el medio.

8. Expliquen cómo funciona `rotate(r)` sin mover los datos elemento por elemento.

rotate(r) funciona sin mover datos: localiza el nodo que quedará primero (índice n-r), lo llama newFirst, y su predecesor newLast. Luego conecta el viejo último nodo con el viejo primero (formando el ciclo), y reconecta el dummy para que apunte a newFirst y newLast. Solo cambia 4 punteros, sin importar el tamaño de la lista (una vez que se ubica newFirst).

9. Expliquen cómo `isPalindrome()` aprovecha la naturaleza doblemente enlazada de la estructura.

isPalindrome() usa dos punteros: left comienza en dummy.next y avanza con next; right comienza en dummy.prev y avanza con prev. Se comparan n/2 pares. Esto es natural en una lista doble porque puedes avanzar hacia adelante y hacia atrás simultáneamente sin copiar los datos a un arreglo.

10. En `SEList`, expliquen qué representa `Location`.

Location en SEList representa la posición lógica de un elemento dentro de la estructura de bloques: tiene u (el nodo/bloque donde está el elemento) y j (el índice dentro de la BDeque de ese bloque). Es la forma de traducir un índice global i a su ubicación física real.

11. Expliquen qué hacen `spread()` y `gather()` y en qué situaciones aparecen.

spread(u) toma b+1 bloques consecutivos a partir de u, inserta un bloque vacío al final, y redistribuye los elementos moviendo uno de cada bloque al siguiente hasta que todos queden con exactamente b elementos. Aparece cuando un bloque está lleno (b+1 elementos) y necesita hacer espacio para insertar. gather(u) hace lo contrario: toma b bloques consecutivos, junta todos sus elementos en los primeros b-1 bloques, y elimina el último que queda vacío. Aparece cuando se elimina un elemento y un bloque queda con menos de b/2 elementos.

12. Expliquen cómo el tamaño de bloque `b` afecta el trade-off entre acceso, actualización y uso de espacio.

Con b grande: menos nodos (menos overhead de punteros), pero recorrer dentro de cada bloque para insertar/eliminar cuesta más. Con b pequeño: más nodos (más punteros), pero las operaciones locales son más baratas. El trade-off es: acceso O(b + n/b), actualización local O(b), y espacio desperdiciado O(b·n/b) = O(n) pero con constante relacionada a b. El valor óptimo teórico es b = √n.

#### Bloque 5 - Adaptadores y estructuras derivadas

Revisen:

- `Semana3/include/LinkedStack.h`
- `Semana3/include/LinkedQueue.h`
- `Semana3/include/LinkedDeque.h`
- `Semana3/include/MinStack.h`
- `Semana3/include/MinQueue.h`
- `Semana3/include/MinDeque.h`
- `Semana3/demos/demo_linked_adapters.cpp`
- `Semana3/demos/demo_min_structures.cpp`

Respondan:

1. ¿Cómo reutiliza `LinkedStack` a `SLList`?

LinkedStack tiene una SLList interna. push(x) llama list.push(x) (agrega al frente), pop() llama list.pop() (elimina del frente), y top() llama list.peek(). La pila vive sobre la cabeza de la lista.

2. ¿Cómo reutiliza `LinkedQueue` a `SLList`?

LinkedQueue también tiene una SLList interna. add(x) llama list.add(x) (agrega al fondo/tail), y remove() llama list.remove() (elimina del frente/head). La semántica FIFO se logra porque la inserción y el borrado están en extremos opuestos.

3. ¿Por qué `LinkedDeque` se construye naturalmente sobre `DLList` y no sobre `SLList`?

LinkedDeque necesita eliminar eficientemente en ambos extremos. SLList no puede eliminar del final en O(1) porque no tiene puntero prev. DLList sí puede: remove(0) usa dummy.next y remove(n-1) usa dummy.prev, ambos en O(1).

4. En `MinStack`, ¿por qué cada entrada guarda el valor y el mínimo acumulado?

Cada entrada de MinStack guarda un par (valor, mínimo_hasta_aquí). Al hacer push, el nuevo mínimo acumulado es min(x, tope_anterior.min). Así min() siempre consulta el tope en O(1), sin recorrer nada. Al hacer pop, el par se descarta y el tope del siguiente ya tiene su propio mínimo correcto.

5. En `MinQueue`, ¿por qué usar dos pilas permite mantener semántica FIFO y consulta de mínimo?

MinQueue usa dos pilas: back_ donde se agregan elementos y front_ desde donde se eliminan. Cuando front_ se vacía, todos los elementos de back_ se pasan a front_ (invirtiéndolos), que restaura el orden FIFO. El mínimo global es min(front_.min(), back_.min()), ambas consultas en O(1). El vaciado de back_ en front_ es O(n) en el peor caso, pero amortizado O(1) por operación.

6. En `MinDeque`, ¿qué problema resuelve el rebalanceo entre `front_` y `back_`?

MinDeque necesita mínimo tanto al sacar del frente como del fondo. El problema aparece cuando uno de los dos lados se vacía: hay que rebalancear moviendo la mitad de los elementos del otro lado. Esto mantiene la invariante de que ningún lado esté vacío mientras la estructura tenga elementos, permitiendo que ambos lados mantengan su propio mínimo. El rebalanceo es O(n) pero amortizado.

7. Comparen "implementar una estructura" y "adaptar una estructura existente" usando ejemplos de este bloque.

"Implementar una estructura" es hacer la lógica desde cero (como DLList con sus nodos y punteros). "Adaptar una estructura" es envolver una existente para cambiar su interfaz sin reescribir la lógica (como LinkedStack sobre SLList). En este bloque: LinkedStack, LinkedQueue y LinkedDeque son adaptadores; MinStack es una implementación que agrega lógica nueva sobre la idea de pila.

8. ¿Qué operaciones pueden defender como constantes y cuáles deben defender como amortizadas?

Son O(1) constantes: push/pop/top en LinkedStack, add/remove/front en LinkedQueue, addFirst/addLast/removeFirst/removeLast en LinkedDeque, y push/pop/min en MinStack. Son amortizadas O(1): add/remove/min en MinQueue (el vaciado de back_ a front_ se amortiza), y las operaciones de MinDeque cuando hay rebalanceo.

#### Bloque 6 - Deng como refuerzo algorítmico y puente de integración

Revisen:

- `Semana3/include/CleanList.h`
- `Semana3/include/DengList.h`
- `Semana3/include/MorinDengBridge.h`
- `Semana3/demos/demo_deng_list.cpp`
- `Semana3/demos/demo_morin_deng_bridge.cpp`
- `Semana3/pruebas_publicas/test_public_deng_bridge.cpp`
- `Semana3/pruebas_internas/test_internal_deng_algorithms.cpp`
- `Parte3-Deng.pdf`

Respondan:

1. ¿Qué operaciones del ADT de lista aparecen reforzadas en `DengList`?

DengList refuerza: push_front, push_back, add(index, x), get, set, remove, front, back, contains, find_index, sort, dedup, uniquify y reverse. Es un ADT de lista más completo que las estructuras base de Morin.

2. ¿Qué ventaja tiene encapsular una lista más rica sin cambiar el resto de estructuras de Semana 3?

La ventaja de encapsular DengList aparte es que el código de SLList, DLList y SEList no se toca. Se puede agregar capacidad algorítmica sin complicar la implementación de cada estructura base ni mezclar responsabilidades.

3. Expliquen qué hacen `to_deng` y `assign_from_deng`.

to_deng(src) recorre la estructura de Morin (DLList o SEList) de principio a fin con get(i) y construye una DengList con los mismos valores en el mismo orden. assign_from_deng(dst, src) hace lo inverso: limpia la estructura de Morin con clear() y la llena de nuevo usando add con los valores del vector de la DengList.

4. Expliquen por qué `stable_sort_with_deng` no obliga a reimplementar ordenamiento dentro de `DLList` o `SEList`.

stable_sort_with_deng convierte la estructura a DengList, llama sort() ahí, y devuelve el resultado. Así el ordenamiento vive en un solo lugar (dentro de DengList/CleanList) y se reutiliza para cualquier estructura que tenga conversión compatible. No hay que reimplementar un sort dentro de DLList ni SEList.

5. Expliquen qué hace `dedup_with_deng` y qué relación guarda con `deduplicate()` o `uniquify()` de la teoría.

dedup_with_deng convierte a DengList, llama dedup() que elimina duplicados consecutivos (por eso generalmente se usa después de ordenar), devuelve cuántos se eliminaron y recarga la estructura. Es la versión "por puente" de lo que Deng llama deduplicate (para listas no ordenadas) o uniquify (para listas ya ordenadas): funciona sobre elementos consecutivos repetidos.

6. Expliquen por qué `reverse_with_deng` es un ejemplo de reutilización de algoritmos sobre una interfaz común.

reverse_with_deng convierte a DengList, llama reverse() que ya sabe invertir la lista internamente, y devuelve el resultado a la estructura original. La DLList podría invertirse sola con rotate o recorrido, pero esta forma muestra que el algoritmo de reversa no necesita conocer si la estructura base es enlazada simple, doble o por bloques: opera sobre la interfaz común.

7. ¿Qué costo adicional introduce la conversión entre estructuras y cuándo vale la pena aceptarlo?

La conversión to_deng y assign_from_deng cuesta O(n) cada una (recorrer todos los elementos). Vale la pena cuando la operación que se gana (sort, dedup, reverse) es suficientemente costosa o compleja como para no querer reimplementarla, o cuando se necesita compartir ese algoritmo entre varias estructuras distintas. Si la operación es trivial, la conversión doble sería innecesaria.

#### Bloque 7 - Comparación enlazado vs contiguo, variantes y evidencia experimental

Revisen:

- `Semana3/include/ArrayDeque.h`
- `Semana3/include/XorList.h`
- `Semana3/demos/demo_contiguous_vs_linked.cpp`
- `Semana3/demos/demo_xor_list.cpp`
- `Semana3/benchmarks/benchmark_semana3.cpp`
- `Parte3-Morin.pdf`

Respondan:

1. Comparen `ArrayDeque` y `LinkedDeque`: ¿qué cambia en representación y qué cambia en costo observable?

ArrayDeque guarda los elementos en un arreglo circular: acceso por índice en O(1) directo, pero las inserciones en el medio desplazan elementos. LinkedDeque usa DLList: acceso por índice en O(min(i,n-i)), pero inserciones y eliminaciones en los extremos siempre en O(1). En los extremos los dos tienen costo O(1), pero en el medio la ventaja es de LinkedDeque para actualizar y de ArrayDeque para acceder.

2. ¿Qué significa que una representación contigua tenga mejor localidad de memoria?

Localidad de memoria significa que los elementos de un arreglo están contiguos en RAM, así que el procesador los carga juntos en caché. Cuando accedes a arr[i] probablemente arr[i+1] ya está en caché. En una lista enlazada, cada nodo puede estar en cualquier lugar de la RAM, causando más "cache misses".

3. ¿Qué tipo de operaciones favorecen más a la representación enlazada?

Las operaciones que favorecen más a la representación enlazada son las inserciones y eliminaciones en posiciones arbitrarias del medio (no necesitan desplazar elementos), y la inserción/eliminación frecuente en cualquier extremo con tamaño variable.

4. En el benchmark, ¿qué comparación sirve mejor para discutir acceso aleatorio y cuál sirve mejor para discutir operaciones en extremos?

Para discutir acceso aleatorio sirve mejor comparar get(i) con índice aleatorio: ArrayDeque gana claramente. Para discutir operaciones en extremos sirve mejor comparar push_front / push_back en listas grandes, donde la diferencia de localidad de caché se nota más que la diferencia algorítmica (ambas son O(1)).

5. ¿Por qué el benchmark no debe leerse como prueba absoluta de superioridad de una estructura sobre otra?

El benchmark depende del hardware, del tamaño de los datos, del patrón de acceso y del compilador. Una estructura puede ganar en acceso aleatorio pero perder en inserciones frecuentes. Los resultados son orientativos para un escenario específico, no una prueba de superioridad general.

6. ¿Qué idea intenta mostrar `XorList` respecto al ahorro de punteros?

XorList guarda en cada nodo un solo campo npx que es el XOR de la dirección del nodo anterior y la del siguiente. Para recorrer hacia adelante o atrás solo necesitas saber el nodo actual y el anterior, y calculas el siguiente con un XOR. Ahorra un puntero por nodo comparado con DLList.

7. ¿Qué desventaja práctica introduce una estructura como `XorList` aunque sea interesante desde el punto de vista del espacio?.

La desventaja práctica de XorList es que no puedes acceder a ningún nodo sin conocer su predecesor. No puedes guardar un puntero a un nodo y usarlo directamente después. Tampoco funciona bien con recolectores de basura (porque las direcciones no son visibles como referencias normales). Es una curiosidad de diseño de bajo nivel más que una estructura práctica en código moderno.

#### Bloque 8 - Cierre comparativo y preparación de sustentación

Respondan esta pregunta final:

¿Qué cambia cuando pasamos de "usar arreglos dinámicos" a "diseñar estructuras enlazadas y adaptadores sobre nodos"?

La respuesta debe incluir obligatoriamente:

- Una afirmación sobre representación
- Una afirmación sobre acceso por rango frente a acceso por posición
- Una afirmación sobre inserciones y eliminaciones locales
- Una afirmación sobre complejidad de `SLList`, `DLList` y `SEList`
- Una afirmación sobre reutilización mediante adaptadores o puentes
- Una comparación entre representación contigua y enlazada.

Respuesta:

- Sobre representación: dejamos de tener un bloque contiguo de memoria y pasamos a tener nodos independientes conectados por punteros. Esto significa que la memoria se asigna y libera de forma individual por cada elemento.

- Sobre acceso por rango frente a acceso por posición: en arreglos el acceso a cualquier índice es O(1) porque la dirección se calcula directamente. En estructuras enlazadas el acceso a la posición i requiere recorrer i nodos desde un extremo, lo que cuesta O(i) o O(min(i,n-i)) según la estructura.

- Sobre inserciones y eliminaciones locales: en arreglos dinámicos insertar o eliminar en el medio desplaza todos los elementos que siguen, costando O(n). En estructuras enlazadas, una vez ubicado el nodo, la inserción o eliminación es solo cambiar punteros, costando O(1) localmente.

- Sobre complejidad de SLList, DLList y SEList: SLList tiene O(1) en los extremos pero O(n) para acceder a posiciones intermedias. DLList mejora el acceso a O(min(i,n-i)) y permite operaciones simétricas en ambos extremos en O(1). SEList busca un equilibrio: agrupa elementos en bloques de tamaño b, logrando acceso O(b + n/b) y actualización local O(b), reduciendo el overhead de punteros respecto a una lista nodo a nodo.

- Sobre reutilización mediante adaptadores o puentes: LinkedStack y LinkedQueue muestran que una misma estructura base (SLList) puede servir para dos abstracciones distintas simplemente cambiando qué operaciones se exponen. El puente MorinDengBridge muestra que los algoritmos de DengList (sort, dedup, reverse) pueden aplicarse a cualquier estructura de Morin sin reescribirlos, convirtiendo y devolviendo los datos.

- Sobre representación contigua vs. enlazada: la representación contigua favorece el acceso aleatorio y la localidad de caché, pero tiene costo alto al modificar el medio. La representación enlazada favorece las modificaciones locales y el crecimiento dinámico sin copiar, pero paga el precio en acceso y en overhead de punteros por nodo. SEList es un punto intermedio que intenta capturar lo mejor de ambos.



#### Formato sugerido de entrega

    ## Actividad 3-CC232

    ### Integrantes
    - Nombre 1
    - Nombre 2

    #### Bloque 1
    (respuestas)

    #### Bloque 2
    (tabla y respuestas)

    #### Bloque 3
    (respuestas)

    #### Bloque 4
    (respuestas)

    #### Bloque 5
    (respuestas)

    #### Bloque 6
    (respuestas)

    #### Bloque 7
    (respuestas)

    #### Bloque 8
    (respuesta final)

    #### Autoevaluación breve
    - Qué podemos defender con seguridad:
    - Qué todavía confundimos:
    - Qué evidencia usaríamos en una sustentación:

#### Criterio general de trabajo

Se espera lectura real de los archivos, respuestas breves pero justificadas, y conexión explícita entre código, correctitud, costo, representación, punteros, invariantes y reutilización.

No basta con ejecutar el programa: deben poder explicar por qué funciona, qué punteros se actualizan, qué invariante mantiene cada estructura y qué costo justifica su diseño.
