### Actividad 8 - CC232

#### Datos generales

Duración: 3 horas de clase.

Modalidad: Trabajo individual.

Entrega: Un archivo llamado `Actividad8-CC232.md` y los archivos modificados solicitados.

#### Material de trabajo

#### Código de la semana

Revisa como mínimo:

* `Semana8/README.md`
* `Semana8/lecturas/Notas.md`
* `Semana8/lecturas/GuiaHashing.md`
* `Semana8/lecturas/PreguntasOrales.md`
* `Semana8/include/Dictionary.h`
* `Semana8/include/Entry.h`
* `Semana8/include/ArrayStack.h`
* `Semana8/include/Bitmap.h`
* `Semana8/include/PrimeUtils.h`
* `Semana8/include/HashCode.h`
* `Semana8/include/HashStats.h`
* `Semana8/include/RehashPolicy.h`
* `Semana8/include/UniversalHash.h`
* `Semana8/include/ChainedHashTable.h`
* `Semana8/include/LinearHashTable.h`
* `Semana8/include/HashtableOA.h`
* `Semana8/include/QuadraticHashTable.h`
* `Semana8/include/DoubleHashTable.h`
* `Semana8/include/RobinHoodHashTable.h`
* `Semana8/include/Applications.h`
* `Semana8/include/Capitulo9.h`

#### Código reutilizado conceptualmente

Revisa también:

* `Semana5/include/BinarySearchTree.h`
* `Semana6/include/Treap.h`
* `Semana7/include/AVL.h`
* `Semana7/include/RedBlackTree.h`
* `Semana7/demos/demo_compare_avl_vs_redblack.cpp`
* `Semana7/demos/demo_capitulo7_panorama.cpp`

#### Demostraciones y pruebas

Revisa y ejecuta:

* `Semana8/demos/demo_chained.cpp`
* `Semana8/demos/demo_linear.cpp`
* `Semana8/demos/demo_hashtable_oa.cpp`
* `Semana8/demos/demo_aplicaciones.cpp`
* `Semana8/demos/demo_collision_strategies.cpp`
* `Semana8/demos/demo_hash_functions.cpp`
* `Semana8/demos/demo_tombstones.cpp`
* `Semana8/demos/demo_benchmark_load_factor.cpp`
* `Semana8/pruebas_publicas/test_public_week8.cpp`
* `Semana8/pruebas_internas/test_internal_week8.cpp`
* `Semana8/pruebas_internas/test_tombstones.cpp`
* `Semana8/pruebas_internas/test_collision_patterns.cpp`
* `Semana8/pruebas_internas/test_rehashing.cpp`
* `Semana8/pruebas_internas/test_randomized_against_stl.cpp`
* `Semana8/CMakeLists.txt`

#### Reglas de trabajo

1. No reemplaces las estructuras principales por `std::unordered_map`, `std::unordered_set`, `std::map`, `std::set` u otra estructura estándar que oculte el algoritmo central.
2. Puedes usar estructuras estándar solo como referencia externa de comparación cuando una prueba o pregunta lo indique explícitamente.
3. No cambies la interfaz principal de la librería salvo que una pregunta lo pida explícitamente.
4. Toda explicación debe mencionar invariante, operación, evidencia y costo.
5. Si modificas una demostración, una prueba o una función auxiliar, marca el cambio con un comentario breve.

```cpp
// MOD-A8-B4: medicion de tombstones despues de eliminaciones
```

6. No basta con ejecutar el programa. Debes poder explicar por qué una operación conserva la tabla en estado válido y por qué su costo es esperado, amortizado o de peor caso.
7. Cuando fuerces colisiones, no asumas que las claves `0, 8, 16, 24` colisionan si la función hash no es identidad. Si el código usa mezcla hash, debes verificar la cubeta real o construir claves colisionantes mediante un pequeño experimento.

#### Bloque 1 - Diagnóstico inicial de la Semana 8

Revisa:

* `Semana8/README.md`
* `Semana8/CMakeLists.txt`
* `Semana8/include/Capitulo9.h`

Ejecuta desde la raíz de la librería:

```bash
cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug
cmake --build build-debug
ctest --test-dir build-debug -R semana8 --output-on-failure
```

Responde:

1. ¿Qué targets de demostración aparecen para Semana 8?

Los targets son:
- demo_chained 
- demo_linear 
- demo_hashtable_oa
- demo_aplicaciones
- demo_collision_strategies
- demo_hash_functions
- demo_tombstones
- demo_benchmark_load_factor

2. ¿Qué pruebas públicas e internas aparecen?

Pruebas públicas:
- test_public_week8.cpp

Pruebas internas:
- test_internal
- test_tombstones
- test_collision_patterns
- test_rehashing
- test_randomized_against_stl

3. ¿Qué archivos incluye `Capitulo9.h`?

- "Applications.h"
- "ArrayStack.h"
- "Bitmap.h"
- "ChainedHashTable.h"
- "Dictionary.h"
- "DoubleHashTable.h"
- "Entry.h"
- "HashCode.h"
- "HashStats.h"
- "HashtableOA.h"
- "LinearHashTable.h"
- "PrimeUtils.h"
- "QuadraticHashTable.h"
- "RehashPolicy.h"
- "RobinHoodHashTable.h"
- "UniversalHash.h"
- "array.h"

4. ¿Qué relación conceptual hay entre Semana 5, Semana 6, Semana 7 y Semana 8?

Semana 5: BST, orden y costo por altura
Semana 6: prioridad, heaps y comparación experimental
Semana 7: AVL y RedBlack Tree
Semana 8: tablas hash, diccionarios no ordenados con costo esperado O(1) si la función hash, colisión, carga y rehashing están bien diseñados. 
Es una progresión de "orden garantizado" hacia "eficiencia esperada sin orden".

5. ¿Por qué no es correcto decir que una tabla hash siempre tiene costo `O(1)` garantizado?

Porque su estructura no garantiza que los elementos queden distribuidos uniformemente ya que pueden darse colisiones lo que conllevaria a que varias claves compartan la misma posicion lo que nos traeria una complejidad O(n)

6. ¿Qué evidencia inicial obtuviste al ejecutar las pruebas sin modificar nada?

La evidencia inicial es que todas las pruebas pasaron correctamente, lo que nos indica que la implementación de las tablas hash y sus operaciones están funcionando según lo esperado y que el código base es estable y cumple con los requisitos especificados

7. ¿Qué diferencia práctica hay entre compilar todo el proyecto y compilar solo los targets de Semana 8?.

La diferencia práctica es que al compilar todo el proyecto reconstruye las semanas anteriores y sus dependencias lo que toma mas tiempo pero verificando integración global mientras que compilar solo los targets de la semana 8 es mas rapido y aisla errores propios

Entrega en este bloque:

* Una tabla con comando ejecutado, resultado, error si hubo e interpretación.

## Tabla de comandos

| Comando | Resultado | Error | Interpretación |
|---|---|---|---|
| `cmake -S . -B build-debug -DCMAKE_BUILD_TYPE=Debug` | Configuró correctamente, generó `build-debug/` con GNU 13.3.0 como compilador | Ninguno | El `CMakeLists.txt` de la semana está bien definido, no requiere pasos manuales extra |
| `cmake --build build-debug` | Compiló los 8 demos y los 6 targets de test (`sem8_test_public`, `sem8_test_internal`, `sem8_test_tombstones`, `sem8_test_collision_patterns`, `sem8_test_rehashing`, `sem8_test_randomized_against_stl`) | Ninguno | Todo el código de la semana, tanto headers como demos y tests, compila limpio sin warnings que rompan el build |
| `ctest --test-dir build-debug -R semana8 --output-on-failure` | 6/6 tests pasaron, filtrando solo los que empiezan con `semana8` | Ninguno | La implementación entera de la semana pasa la suite pública e interna sin haber tocado nada del código |

* Una lista breve de los archivos que revisaste primero.
* Una conclusión inicial de máximo 8 líneas sobre el estado de la semana.

#### Bloque 2 - Núcleo conceptual de hashing y diccionarios

Revisa:

* `Semana8/lecturas/Notas.md`
* `Semana8/lecturas/GuiaHashing.md`
* `Semana8/include/Dictionary.h`
* `Semana8/include/Entry.h`
* `Semana8/include/HashCode.h`
* `Semana8/include/HashStats.h`
* `Semana8/include/RehashPolicy.h`

Responde:

1. Define con precisión qué es un diccionario abstracto.

Un diccionario abstracto es una estructura de datos que almacena pares de elementos donde cada uno consiste en una clave y valor que son unicos y permite realizar operaciones de inserción, búsqueda y eliminacion de manera eficiente, su objetivo principal es asociar claves con valores, permitiendo acceder a los valores mediante sus claves de forma rápida.

2. Explica la diferencia entre diccionario, mapa, conjunto y tabla hash.

La diferencia principal radica en la forma en que se almacenan y acceden a los datos ya que un diccionario es una estructura abstracta que asocia claves con valores mientras que un mapa es una implementación concreta de un diccionario. por otro lado un conjunto es una colección de elementos únicos sin valores asociados y una tabla hash es una estructura de datos que implementa un diccionario o conjunto utilizando una función hash para distribuir los elementos en un arreglo permitiendo así un acceso rápido

3. Explica qué representa un `Entry<K,V>`.

Representa un par de elementos donde K es la clave y V es el valor asociado a esa clave permitiendo que se puedan almacenar, recuperar y manipular dentro de un diccionario o tabla hash.

4. Explica qué hace una función hash.

Una función hash toma la clave y la transforma en un valor numérico el cual representa la posicion en la que se almacenara el elemento dentro de una estructura de datos como una tabla hash

5. Explica por qué pueden existir colisiones aunque la función hash sea razonable.

Las colisiones pueden existir porque la función hash mapea un conjunto potencialmente grande de claves a un conjunto finito de posiciones en la tabla hash, lo que significa que diferentes claves pueden producir el mismo valor hash y por lo tanto ocupar la misma posición en la tabla

6. Explica qué significa factor de carga.

El factor de carga es la división entre el número de elementos almacenados en la tabla hash y la capacidad total de la tabla indicando qué tan llena está la tabla y afectando el rendimiento de las operaciones de inserción y búsqueda

7. Explica qué significa rehashing.

El rehashing es el proceso de crear una nueva tabla hash con mayor capacidad y volver a insertar todos los elementos existentes en la nueva tabla utilizando una función hash actualizada para reducir colisiones y mejorar el rendimiento

8. Explica qué mide `HashStats`.

HashStats mide métricas relacionadas con el rendimiento de la tabla hash como el número de colisiones, el número de sondeos realizados, el máximo de sondeos en una operación, el número de rehashings realizados y la cantidad de tombstones presentes en la tabla

9. Explica qué decide `RehashPolicy`.

RehashPolicy decide cuándo y cómo se debe realizar el rehashing de la tabla hash basándose en condiciones como el factor de carga y otras métricas que afectan el rendimiento de la tabla

10. Compara el costo esperado de una tabla hash con el costo garantizado de AVL y Red-Black Tree.

El costo esperado de una tabla hash es O(1) para operaciones de insercion, búsqueda y eliminación bajo condiciones ideales de distribución de claves y baja carga, mientras que el costo garantizado de AVL y RedBlack Tree es O(log n) para las mismas operaciones debido a su estructura balanceada que asegura una altura logarítmica en el peor caso

Entrega en este bloque:

* Una tabla conceptual con las columnas: concepto, definición, archivo relacionado y ejemplo.

| Concepto | Definición | Archivo relacionado | Ejemplo |
|---|---|---|---|
| Diccionario abstracto | Estructura de datos que almacena pares clave-valor y permite operaciones de inserción, búsqueda y eliminación | Dictionary.h | Un diccionario que asocia nombres de estudiantes con sus calificaciones |
| Mapa | Implementación concreta de un diccionario que asocia claves con valores | Dictionary.h | Un mapa que asocia códigos de producto con sus precios |
| Conjunto | Colección de elementos únicos sin valores asociados | Dictionary.h | Un conjunto que almacena identificadores únicos de usuarios |
| Tabla hash | Estructura de datos que implementa un diccionario o conjunto utilizando una función hash para distribuir los elementos en un arreglo | ChainedHashTable.h | Una tabla hash que almacena pares clave-valor de nombres de ciudades y sus coordenadas |
| Entry<K,V> | Representa un par de elementos donde K es la clave y V es el valor asociado a esa clave | Entry.h | Un Entry que asocia la clave "nombre" con el valor "Juan" |
| Función hash | Toma una clave y la transforma en un valor numérico que representa la posición en la que se almacenará el elemento dentro de una estructura de datos como una tabla hash | HashCode.h | Una función hash que convierte la clave "abc" en el valor 42 |
| Colisión | Ocurre cuando diferentes claves producen el mismo valor hash y ocupan la misma posición en la tabla | HashStats.h | Dos claves "abc" y "xyz" que producen el mismo valor hash 42 |
| Factor de carga | División entre el número de elementos almacenados en la tabla hash y la capacidad total de la tabla, indicando qué tan llena está la tabla | HashStats.h | Una tabla hash con 50 elementos y una capacidad de 100 tiene un factor de carga de 0.5 |

* Una explicación de máximo 12 líneas sobre por qué hashing no reemplaza completamente a los árboles balanceados.

El hashing no reemplaza completamente a los árboles balanceados porque aunque ofrece un costo esperado O(1) para operaciones de inserción, búsqueda y eliminación, no mantiene el orden de los elementos, lo que limita su uso en aplicaciones que requieren consultas por rango o recorrido ordenado. Además, el rendimiento de las tablas hash puede degradarse significativamente en presencia de colisiones o factores de carga altos, mientras que los árboles balanceados garantizan un rendimiento logarítmico en el peor caso. Por lo tanto, la elección entre hashing y árboles balanceados depende del tipo de operaciones requeridas y las características de los datos.

#### Bloque 3 - Chaining: cubetas, colisiones y longitud máxima

Revisa:

* `Semana8/include/ChainedHashTable.h`
* `Semana8/include/ArrayStack.h`
* `Semana8/include/HashCode.h`
* `Semana8/demos/demo_chained.cpp`

Ejecuta:

```bash
./build-debug/Semana8/sem8_demo_chained
```

Construye una tabla con estas columnas:

* Operación
* Clave
* Cubeta calculada
* Tamaño de la cubeta antes
* Tamaño de la cubeta después
* Colisión observada
* `loadFactor()`
* `longestBucket()`

Responde:

1. ¿Qué diferencia hay entre el arreglo principal y las cubetas?

El arreglo principal es la tabla de tamaño fijo (capacidad) indexada por el hash de la clave, cada posición no guarda directamente el elemento, sino una cubeta (una lista) que puede contener cero, uno o varios elementos que colisionaron en ese índice

2. ¿Por qué chaining puede almacenar más elementos que la cantidad de posiciones del arreglo principal?

Porque cada posición del arreglo no almacena un solo elemento sino una cubeta con capacidad dinámica, varias claves distintas que colisionan en el mismo índice se acumulan en la misma cubeta así que el número de elementos no esta limitado por la capacidad del arreglo

3. ¿Qué significa que una cubeta crezca demasiado?

Significa que muchas claves distintas están mapeando al mismo índice (muchas colisiones concentradas) por lo que esa cubeta deja de comportarse como una lista corta y empieza a requerir recorridos largos degradando el rendimiento de esa posición hacia búsqueda lineal

4. ¿Por qué `longestBucket()` es una métrica importante?

Porque revela el peor caso real de la tabla en ese momento: si longestBucket es grande, indica mala dispersión o concentración de colisiones, aunque el loadFactor promedio se vea bajo o razonable.

5. ¿En qué caso la búsqueda en chaining deja de parecerse a `O(1)` esperado?

Cuando la distribución de claves es mala o adversarial y varias claves colisionan sistemáticamente en pocas cubetas, ahí la búsqueda se aproxima al costo de recorrer una lista de tamaño k, es decir O(k), en vez de O(1).

6. ¿Qué costo tiene recorrer una cubeta de longitud `k`?

O(k) ya que hay que comparar la clave contra cada elemento de la cubeta hasta encontrarla o llegar al final

7. ¿Qué parte del costo depende de la función hash y qué parte depende de la distribución de claves?.

La función hash determina a qué índice se mapea cada clave (calidad de dispersión "en abstracto"), la distribución real de las claves de entrada determina si, en la práctica, muchas de ellas terminan cayendo en los mismos índices. Una buena función hash puede seguir dando cubetas largas si el conjunto de claves es adversarial o muy repetitivo respecto a esa función

Entrega en este bloque:

* Salida relevante de `demo_chained.cpp`.

Salida:
```
ChainedHashTable
size=6 capacity=17 load=0.352941 longestBucket=2
contains(26)=1 contains(99)=0
insertions=6, successfulSearches=1, failedSearches=1, removals=0, collisions=4, totalProbes=14, maxProbeLength=3, averageProbeLength=1.75, rehashes=1, tombstones=0
```

* Tabla de operaciones.
* Dibujo de una tabla hash con al menos 8 cubetas y 10 claves.
* Explicación breve de costo esperado y peor caso.

#### Bloque 4 - Colisiones controladas sin asumir hash de identidad

Revisa:

* `Semana8/include/HashCode.h`
* `Semana8/demos/demo_hash_functions.cpp`
* `Semana8/demos/demo_collision_strategies.cpp`

Modifica o crea una demostración auxiliar que busque claves enteras que caigan en la misma cubeta para una capacidad fija `m`. No asumas que `x % m` es la cubeta final si antes se aplica una mezcla hash.

Puedes usar una función auxiliar con esta idea:

```cpp
std::vector<int> findCollidingKeys(std::size_t capacity,
                                   std::size_t targetBucket,
                                   std::size_t needed);
```

La función debe probar claves enteras desde `0` hacia adelante y quedarse con las que cumplan:

```cpp
hashCode(x) % capacity == targetBucket
```

Responde:

1. ¿Por qué `0, 8, 16, 24` solo garantiza colisión si la función hash efectiva es `h(x) = x mod m`?

Porque esos números son todos múltiplos de 8, entonces si la tabla tiene una capacidad múltiplo de 8 todos caen en la misma posición, eso pasa solo por la aritmética del módulo no porque las claves sean especiales en sí mismas

2. ¿Qué ocurre si antes se aplica una mezcla como `hashCode(x)`?

La colisión desaparece porque hashCode(x) pasa el número por mix64 que revuelve los bits con multiplicaciones y desplazamientos antes de aplicar el módulo, entonces claves que antes eran múltiplos exactos de 8 terminan repartidas en índices distintos y ya no colisionan entre si

3. ¿Qué claves encontraste para una misma cubeta con capacidad `8` o `16`?

Cualquier grupo de numeros que sean congruentes entre si respecto a la capacidad sirve por ejemplo con capacidad 8 las claves 0 8 16 y 24 caen en la misma cubeta y con capacidad 16 pasa lo mismo con 0 16 32 y 48

4. ¿Cómo cambia el experimento si usas cadenas en lugar de enteros?

Con cadenas ya no se puede forzar la colision con una simple cuenta de multiplos porque el hash de un string se calcula recorriendo cada caracter y mezclandolo antes de pasar todo por mix64 entonces hay que buscar palabras distintas que por casualidad den el mismo resultado y eso es bastante mas dificil de armar a mano

5. ¿Por qué este bloque es importante para defender evidencia experimental honesta?.

Este bloque importa porque muestra que encontrar una colision no significa que la tabla este mal hecha sino que depende de que funcion hash se esta usando en realidad entonces al reportar resultados hay que aclarar si la colision viene de una funcion debil como el modulo puro o si se mantiene incluso despues de aplicar una mezcla buena como hashCode

Entrega en este bloque:

* Código de la función auxiliar.
* Lista de claves encontradas.
* Tabla con clave, valor hash normalizado y cubeta.
* Evidencia de que esas claves sí producen colisiones en tu ejecución.

#### Bloque 5 - Linear probing: estados, sondeo y tombstones

Revisa:

* `Semana8/include/LinearHashTable.h`
* `Semana8/include/Bitmap.h`
* `Semana8/include/HashStats.h`
* `Semana8/demos/demo_linear.cpp`
* `Semana8/demos/demo_tombstones.cpp`

Ejecuta:

```bash
./build-debug/Semana8/sem8_demo_linear
./build-debug/Semana8/sem8_demo_tombstones
```

Construye una tabla con estas columnas:

* Operación
* Clave
* Posición hash inicial
* Secuencia de sondeo
* Estado final de la celda
* `size`
* `occupied`
* `loadFactor()`
* `occupiedFactor()`
* `tombstoneCount()`

Responde:

1. ¿Qué representan los estados `Empty`, `Filled` y `Deleted`?

Empty es una celda que nunca fue usada, Filled es una celda que tiene un elemento activo ahora mismo, y Deleted es una celda que tuvo algo pero se elimino como una especie de tumba que queda marcada

2. ¿Por qué `Deleted` no puede tratarse igual que `Empty`?

Porque si Deleted se tratara igual que Empty se rompería la busqueda por sondeo, ya que el algoritmo se detiene cuando encuentra una celda Empty, entonces si una clave paso por encima de una tumba para llegar a otra posicion y esa tumba se trata como Empty la busqueda se corta antes de tiempo y da falso negativo aunque la clave si este mas adelante

3. ¿Qué diferencia hay entre `size` y `occupied`?

Size cuenta solo las celdas Filled o sea los elementos activos que realmente estan ahi, occupied cuenta Filled mas Deleted, es decir todas las celdas que ya no estan disponibles para una insercion directa aunque no todas tengan un valor real

4. ¿Por qué `loadFactor()` y `occupiedFactor()` pueden divergir después de muchas eliminaciones?

Porque loadFactor solo mira los activos dividido la capacidad, mientras que occupiedFactor mete tambien las tumbas, entonces si eliminas muchos elementos el loadFactor baja pero occupiedFactor se mantiene alto porque las tumbas siguen ocupando espacio aunque ya no cuenten como elementos

5. ¿Qué problema aparece si se acumulan demasiados tombstones?

Si se acumulan muchas tumbas el sondeo se vuelve mas lento porque cada busqueda tiene que atravesar esas celdas Deleted igual que si estuvieran llenas, entonces aunque size sea chico el rendimiento se degrada como si la tabla estuviera casi llena

6. ¿Cuándo debe hacerse rehashing por carga ocupada aunque haya pocos elementos activos?

Debe rehashearse por carga ocupada cuando occupiedFactor se dispara aunque size sea bajo, ahi aunque haya pocos elementos activos las tumbas estan saturando la tabla y hay que limpiar o crecer para que el sondeo vuelva a ser rapido

7. ¿Qué costo tiene una búsqueda fallida cuando hay clustering?

Cuando hay clustering una busqueda fallida cuesta bastante mas porque el sondeo tiene que recorrer todo el bloque contiguo de celdas ocupadas o tumbas hasta encontrar un Empty real, en el peor caso eso se acerca a O(n) en vez de acercarse a O(1)

Entrega en este bloque:

* Salida relevante de `demo_linear.cpp` y `demo_tombstones.cpp`.
* Trazado manual de al menos una búsqueda exitosa y una búsqueda fallida.
* Explicación de por qué open addressing necesita una política cuidadosa de eliminación.

#### Bloque 6 - HashtableOA como diccionario `key value`

Revisa:

* `Semana8/include/Dictionary.h`
* `Semana8/include/Entry.h`
* `Semana8/include/HashtableOA.h`
* `Semana8/demos/demo_hashtable_oa.cpp`
* `Semana8/include/Applications.h`

Ejecuta:

```bash
./build-debug/Semana8/sem8_demo_hashtable_oa
```

Responde:

1. ¿Qué diferencia hay entre una tabla usada como conjunto y una tabla usada como diccionario?

Una tabla usada como conjunto solo guarda las claves para saber si algo existe o no, mientras que una tabla usada como diccionario guarda pares clave valor, entonces ademas de saber si existe tambien puedes recuperar la informacion asociada

2. ¿Qué representa una clave?

La clave es el dato que identifica de forma unica a cada elemento dentro de la estructura, es lo que se usa para calcular el hash y ubicar donde va el elemento

3. ¿Qué representa un valor?

El valor es la informacion asociada a esa clave, es el dato que realmente te interesa recuperar cuando buscas por la clave

4. ¿Qué debe devolver `get(k)` si la clave existe?

Si la clave existe get(k) debe devolver el valor asociado envuelto en un optional con contenido, en el codigo se ve como std::optional<V> que trae el value del Entry encontrado

5. ¿Qué debe ocurrir con `remove(k)` si la clave no existe?

Si la clave no existe remove(k) no debe hacer nada raro ni lanzar error, simplemente debe devolver false indicando que no se elimino nada porque nunca se encontro esa clave

6. ¿Qué política usa la implementación cuando se intenta insertar una clave repetida?

En HashtableOA cuando se intenta insertar una clave repetida el put simplemente falla y devuelve false sin sobrescribir el valor anterior, ademas cuenta eso como una busqueda fallida en las estadisticas, o sea no permite duplicados ni actualiza el valor existente

7. ¿Por qué una interfaz `put`, `get`, `remove` permite separar el uso del diccionario de su implementación interna?

Porque el que usa el diccionario solo necesita saber que existen esas tres operaciones y que hacen, no le importa si por dentro hay chaining, direccionamiento abierto o cualquier otra tecnica, entonces se puede cambiar la implementacion interna sin romper el codigo que usa put get y remove

8. ¿Cómo se relaciona esta parte con el ADT diccionario de Deng?

Se relaciona directamente porque Dictionary.h define esa misma interfaz abstracta con put get y remove como metodos virtuales puros, siguiendo la idea de Deng de separar el contrato del ADT diccionario de su implementacion concreta, y despues HashtableOA y las demas tablas hash son solo una forma particular de cumplir ese contrato

Entrega en este bloque:

* Una tabla con operaciones `put`, `get`, `remove`, resultado esperado y evidencia observada.
* Un ejemplo `string` a `int` para conteo de frecuencias.
* Una explicación de cómo cambia el diseño si se desea que `put` actualice el valor de una clave ya existente.

#### Bloque 7 - Comparación de estrategias de colisión

Revisa:

* `Semana8/include/ChainedHashTable.h`
* `Semana8/include/LinearHashTable.h`
* `Semana8/include/QuadraticHashTable.h`
* `Semana8/include/DoubleHashTable.h`
* `Semana8/include/RobinHoodHashTable.h`
* `Semana8/demos/demo_collision_strategies.cpp`

Ejecuta:

```bash
./build-debug/Semana8/sem8_demo_collision_strategies
```

Compara al menos cinco estrategias:

1. Chaining.
2. Linear probing.
3. Quadratic probing.
4. Double hashing.
5. Robin Hood hashing.

Construye una tabla con estas columnas:

* Estrategia
* Representación interna
* Cómo resuelve colisiones
* Métrica más sensible
* Ventaja
* Debilidad
* Costo esperado
* Peor caso

Responde:

1. ¿Qué es clustering primario?

Un clustering primario es cuando varios elementos que colisionan van formando un bloque continuo de celdas ocupadas en la tabla, entonces mientras mas crece ese bloque mas probable es que la siguiente insercion tambien caiga ahi y lo alargue todavia mas

2. ¿Por qué linear probing tiende a formar bloques contiguos?

Porque linear probing cuando encuentra una celda ocupada simplemente pasa a la siguiente posicion consecutiva, entonces los elementos que colisionan terminan pegados unos con otros formando bloques largos que ademas atraen nuevas colisiones

3. ¿Qué intenta mejorar quadratic probing?

Un quadratic probing intenta mejorar eso saltando con pasos que crecen cuadraticamente en vez de ir de uno en uno, así evita que los elementos se peguen tanto y reduce el clustering primario

4. ¿Qué intenta mejorar double hashing?

Un double hashing intenta mejorar el problema usando una segunda funcion hash para calcular el salto entre sondeos, entonces el patron de sondeo depende de la clave misma y no es el mismo paso fijo para todas las claves, eso reparte mejor los elementos

5. ¿Qué intenta equilibrar Robin Hood hashing?

Robin Hood hashing intenta equilibrar la distancia que recorre cada elemento desde su posicion ideal, si un elemento nuevo esta mas lejos de su posicion ideal que el que ya esta ahi, se intercambian así ningun elemento queda con una distancia demasiado grande comparado con los demas

6. ¿Por qué chaining y open addressing no tienen el mismo comportamiento ante carga alta?

Porque en chaining la carga alta solo alarga las cubetas pero cada busqueda sigue siendo independiente entre cubetas, en cambio en open addressing la carga alta hace que cada vez sea mas dificil encontrar una celda libre y el rendimiento de todas las operaciones se degrada junto, no solo el de una posicion puntual

7. ¿Qué estrategia elegirías para una tabla pequeña de laboratorio?

Para una tabla pequeña de laboratorio elegiria linear probing porque es simple de implementar y entender y con pocos elementos el clustering no llega a ser un problema real

8. ¿Qué estrategia elegirías para una carga alta con muchas búsquedas?

Para carga alta con muchas busquedas elegiria Robin Hood hashing porque mantiene las distancias parejas entre elementos y evita que algunas busquedas sean mucho mas costosas que otras

9. ¿Qué estrategia se degrada más claramente en presencia de muchas eliminaciones?.

Open addressing en general se degrada mas claramente con muchas eliminaciones porque necesita tombstones que siguen ocupando espacio de sondeo, y entre las variantes de open addressing linear probing es la que mas sufre porque ya de por si tiende al clustering y las tumbas alargan aun mas esos bloques

Entrega en este bloque:

* Salida de la demo.
* Tabla comparativa completa.
* Conclusión técnica de máximo 15 líneas.

#### Bloque 8 - Funciones hash, hashing universal y distribución

Revisa:

* `Semana8/include/HashCode.h`
* `Semana8/include/UniversalHash.h`
* `Semana8/demos/demo_hash_functions.cpp`

Ejecuta:

```bash
./build-debug/Semana8/sem8_demo_hash_functions
```

Diseña tres conjuntos de claves:

1. Claves enteras consecutivas.
2. Claves enteras con patrón repetitivo.
3. Claves de texto con prefijos comunes.

Para cada conjunto, mide o reporta:

* cantidad de claves,
* capacidad de tabla,
* número de cubetas usadas,
* cubeta más cargada,
* colisiones observadas,
* comentario sobre la distribución.

Responde:

1. ¿Qué propiedad debe tener una buena función hash?

Una buena funcion hash debe distribuir las claves de forma pareja entre todas las posiciones de la tabla, o sea que claves distintas produzcan indices distintos la mayor parte del tiempo, y que claves parecidas no produzcan indices parecidos, ademas debe ser rapida de calcular y siempre dar el mismo resultado para la misma entrada

2. ¿Por qué una función hash determinista puede ser buena para datos comunes y mala para datos adversariales?

Porque una funcion determinista siempre da el mismo hash para la misma clave, entonces con datos comunes o aleatorios eso reparte bien porque las claves no siguen ningun patron especial, pero si alguien conoce la formula exacta puede construir a proposito un monton de claves que caigan todas en el mismo indice, ahi la tabla se degrada aunque la funcion en general sea buena

3. ¿Qué idea aporta hashing universal?

La idea de hashing universal es no usar una sola formula fija sino elegir al azar una funcion de una familia entera, con parametros a y b generados con una semilla aleatoria, entonces aunque alguien conozca el algoritmo no puede predecir cual funcion especifica se va a usar, y eso hace mucho mas dificil construir claves adversariales de antemano

4. ¿Por qué no se debe evaluar una función hash con un solo conjunto de claves?

Porque una funcion hash puede verse muy bien con un conjunto de claves y muy mal con otro, si solo se prueba con un conjunto no se puede saber si el buen resultado fue porque la funcion es realmente buena o porque esas claves en particular resultaron favorables, hay que probar con varios conjuntos incluyendo casos raros o adversariales para tener una evaluacion honesta

5. ¿Qué relación existe entre dispersión y costo esperado?.

Entre mejor sea la dispersion mas cerca esta el costo real del costo esperado O(1), si la dispersion es mala las claves se concentran en pocas posiciones y el costo real se acerca mas al peor caso O(n), o sea la dispersion es justamente lo que sostiene la promesa de O(1) esperado de una tabla hash

Entrega en este bloque:

* Tabla de distribución para los tres conjuntos de claves.
* Comparación entre `hashCode` y `UniversalHash` si la demo lo permite.
* Una conclusión sobre el papel de la función hash en el rendimiento real.

#### Bloque 9 - Rehashing, política de carga y costo amortizado

Revisa:

* `Semana8/include/RehashPolicy.h`
* `Semana8/include/HashStats.h`
* `Semana8/demos/demo_benchmark_load_factor.cpp`
* `Semana8/pruebas_internas/test_rehashing.cpp`

Ejecuta:

```bash
./build-debug/Semana8/sem8_demo_benchmark_load_factor
```

Responde:

1. ¿Qué condición de carga provoca crecimiento?

Crece cuando el factor de carga o sea activos entre capacidad supera el 70 por ciento, ahi shouldGrow devuelve true y la tabla duplica su capacidad

2. ¿Qué condición puede provocar limpieza por tombstones?

La limpieza por tombstones se dispara cuando activos mas tumbas entre capacidad supera el 82 por ciento, en ese caso shouldCleanOrGrow hace un rehash aunque los elementos activos no sean tantos, solo para sacar las tumbas acumuladas

3. ¿Qué condición puede provocar contracción?

La contraccion ocurre cuando el factor de carga baja de 12.5 por ciento y ademas la capacidad actual es mayor que la minima de 8 celdas, ahi shouldShrink devuelve true y la tabla se reduce a la mitad

4. ¿Por qué rehashing cuesta `O(n)` en el momento en que ocurre?

Porque rehashing implica recorrer todos los elementos activos de la tabla vieja y reinsertarlos uno por uno en la tabla nueva, entonces el costo de ese momento puntual es proporcional a n, el numero de elementos

5. ¿Por qué aun así se habla de costo amortizado?

Porque aunque cada rehash individual cueste O(n), esos rehashes no pasan seguido, pasan cada vez que la tabla duplica su tamaño, entonces si repartes ese costo entre todas las inserciones normales que si son O(1), el promedio por insercion sigue siendo O(1) aunque de vez en cuando una insercion puntual sea mas cara

6. ¿Qué relación hay entre capacidad, factor de carga y número de sondeos?

Entre mas capacidad haya para el mismo numero de elementos el factor de carga baja y hay menos sondeos en promedio, en cambio si la capacidad se queda chica para muchos elementos el factor de carga sube y cada operacion necesita mas sondeos porque hay mas colisiones y celdas ocupadas de por medio

7. ¿Qué evidencia muestra `HashStats` sobre rehashings?

HashStats guarda el contador de rehashes junto con metricas como totalProbes y maxProbeLength, entonces se puede ver cuantas veces se reconstruyo la tabla durante todo el experimento y relacionar eso con si los sondeos promedio se mantuvieron bajos o se dispararon antes de cada rehash

8. ¿Qué riesgo hay si se permite que el factor de carga sea demasiado alto?.

Si se permite un factor de carga demasiado alto las colisiones se vuelven mas frecuentes y las cubetas o los bloques de sondeo crecen demasiado, entonces el costo de insertar, buscar y eliminar deja de parecerse a O(1) esperado y se acerca cada vez mas al peor caso O(n), ademas se corre el riesgo de retrasar demasiado un rehash necesario

Entrega en este bloque:

* Tabla con capacidad, número de elementos, factor de carga, rehashes y máximo de sondeos.
* Explicación de costo amortizado.
* Interpretación de al menos una prueba de `test_rehashing.cpp`.

#### Bloque 10 - Aplicaciones de hashing

Revisa:

* `Semana8/include/Applications.h`
* `Semana8/demos/demo_aplicaciones.cpp`

Ejecuta:

```bash
./build-debug/Semana8/sem8_demo_aplicaciones
```

Elige dos aplicaciones y explícalas con trazado manual:

1. `hasDuplicates`.
2. `uniquePreservingOrder`.
3. `firstRepeated`.
4. `frequencyCount`.
5. `wordFrequencyFromText`.
6. `twoSum`.
7. `deduplicateLogs`.
8. `invertedIndex`.

Para cada aplicación elegida, responde:

uniquePreservingOrder:

1. ¿Cuál es el problema de entrada?

El problema de entrada es un vector de enteros que puede tener valores repetidos en cualquier posicion

2. ¿Cuál es la salida esperada?

La salida esperada es un nuevo vector con cada valor apareciendo solo una vez, respetando el orden en que aparecieron por primera vez en el vector original

3. ¿Qué se guarda en la tabla hash?

En la tabla hash se guardan las claves ya vistas, es un ChainedHashTable que funciona como conjunto, no guarda ningun valor asociado, solo si el elemento ya paso por ahi

4. ¿Qué operación domina el costo?

La operacion que domina el costo es add, porque se llama una vez por cada elemento del vector para revisar si ya existe y agregarlo si no

5. ¿Por qué el costo esperado puede ser lineal?

El costo esperado es lineal porque cada add cuesta O(1) esperado y se hace exactamente n veces, una por cada elemento del vector original, entonces el total es O(n)

6. ¿Qué caso podría degradar el rendimiento?

El rendimiento se degrada si muchos valores distintos colisionan en las mismas cubetas, ahi cada add deja de ser O(1) y se acerca a recorrer una lista larga cada vez

7. ¿Cómo resolverías el mismo problema con AVL o Red-Black Tree?

Con AVL o Red Black Tree harias lo mismo pero insertando cada valor en el arbol y revisando si ya existia antes de insertar, cada operacion seria O(log n) garantizado en vez de O(1) esperado, y ademas tendrias que guardar aparte el orden de aparicion porque el arbol ordena por valor no por orden de llegada

8. ¿Qué se gana y qué se pierde al usar hashing?.

Se gana velocidad esperada y simplicidad para solo checar existencia pero se pierde la garantia de peor caso ante datos adversariales, con un arbol si te interesara despues recorrer los valores unicos en orden numerico eso saldria gratis y con la tabla hash no

invertedIndex:

1. ¿Cuál es el problema de entrada?

El problema de entrada es una coleccion de documentos de texto, cada uno identificado por su posicion en la lista

2. ¿Cuál es la salida esperada?

La salida esperada es un diccionario que asocia cada palabra con la lista de ids de los documentos donde esa palabra aparece al menos una vez

3. ¿Qué se guarda en la tabla hash?

En la tabla hash principal se guarda cada palabra normalizada como clave y como valor la lista de ids de documentos donde aparece, ademas por cada documento se usa una tabla hash auxiliar seenInDoc que guarda las palabras ya contadas en ese documento para no repetir el mismo id dos veces

4. ¿Qué operación domina el costo?

La operacion que domina el costo es el par get mas put sobre la tabla principal, que se ejecuta por cada palabra única de cada documento además del add sobre seenInDoc para filtrar repetidos dentro del mismo documento

5. ¿Por qué el costo esperado puede ser lineal?

El costo esperado es lineal respecto al total de palabras en todos los documentos porque cada palabra se procesa con operaciones O(1) esperado sobre las tablas hash, entonces el total es O(total de palabras)

6. ¿Qué caso podría degradar el rendimiento?

El rendimiento se degrada si hay muchas palabras distintas que colisionan entre si en la tabla principal o si un documento tiene muchisimas palabras repetidas y la tabla seenInDoc de ese documento se llena de colisiones

7. ¿Cómo resolverías el mismo problema con AVL o Red-Black Tree?

Con AVL o Red Black Tree harias lo mismo pero guardando palabra y lista de ids en el arbol ordenado por palabra, cada get y put costarian O(log n) garantizado en vez de O(1) esperado, la ventaja extra es que podrias recorrer el indice completo en orden alfabetico directamente

8. ¿Qué se gana y qué se pierde al usar hashing?.

Se gana velocidad esperada para construir y consultar el indice pero se pierde la garantia de peor caso y el orden si despues quisieras mostrar el indice ordenado alfabeticamente con la tabla hash tendrias que sacar las claves y ordenarlas aparte, mientras que con un arbol eso ya viene incluido

Entrega en este bloque:

* Dos trazados manuales.
* Evidencia de ejecución.
* Comparación de costo esperado con tabla hash frente a costo garantizado con árbol balanceado.

#### Bloque 11 - Modificación controlada de código

Elige una de las siguientes modificaciones. Debes marcar tu cambio con comentario `MOD-A8` y mantener compilación limpia.

#### Opción A - Reporte uniforme de métricas

Crea una función auxiliar para imprimir métricas relevantes de una tabla hash.

```cpp
void printHashStats(const HashStats& stats);
```

La salida debe incluir como mínimo:

* colisiones,
* sondeos totales,
* máximo de sondeos,
* rehashings,
* tombstones si aplica.

#### Opción B - Experimento de colisiones reales

Crea una demo que busque claves que realmente colisionen bajo `hashCode(x) % capacity` y luego las inserte en `ChainedHashTable` o `LinearHashTable`.

#### Opción C - Caso adicional de aplicación

Agrega una aplicación pequeña basada en hashing, por ejemplo:

```cpp
std::vector<std::string> findRepeatedWords(const std::string& text);
```

Debe devolver palabras que aparecen más de una vez, sin usar `std::unordered_map` como estructura principal.

Responde:

1. ¿Qué archivo modificaste?
2. ¿Qué función agregaste?
3. ¿Qué invariante debe mantenerse?
4. ¿Qué prueba o demo evidencia el cambio?
5. ¿Qué costo tiene la función agregada?
6. ¿Por qué tu modificación no oculta el algoritmo central?.

Entrega en este bloque:

* Fragmento de código modificado.
* Evidencia de compilación.
* Evidencia de ejecución.
* Explicación de costo.

#### Bloque 12 - Comparación final con BST, AVL, Red-Black Tree y Treap

Revisa:

* `Semana5/include/BinarySearchTree.h`
* `Semana6/include/Treap.h`
* `Semana7/include/AVL.h`
* `Semana7/include/RedBlackTree.h`
* `Semana8/include/ChainedHashTable.h`
* `Semana8/include/LinearHashTable.h`
* `Semana8/include/HashtableOA.h`

Construye una matriz de decisión con estas columnas:

* Estructura
* Mantiene orden
* Búsqueda promedio
* Búsqueda peor caso
* Inserción
* Eliminación
* Memoria adicional
* Ventaja principal
* Riesgo principal
* Caso de uso recomendado

Incluye:

1. BST simple.
2. Treap.
3. AVL.
4. Red-Black Tree.
5. ChainedHashTable.
6. LinearHashTable.
7. HashtableOA.

Responde:

1. ¿Cuándo elegirías una tabla hash?
2. ¿Cuándo elegirías AVL?
3. ¿Cuándo elegirías Red-Black Tree?
4. ¿Cuándo elegirías Treap?
5. ¿Por qué una tabla hash no sirve directamente para consultas por rango?
6. ¿Por qué un árbol balanceado sí permite recorrer claves en orden?
7. ¿Qué significa que una estructura tenga costo esperado y otra tenga costo garantizado?
8. ¿Qué estructura preferirías para un índice de palabras sin orden?
9. ¿Qué estructura preferirías para un ranking ordenado por clave?
10. ¿Qué estructura preferirías si necesitas `lowerBound` y `upperBound`?.

Entrega en este bloque:

* Matriz de decisión.
* Conclusión final de máximo 20 líneas.
* Un ejemplo concreto donde hashing gana.
* Un ejemplo concreto donde AVL o Red-Black Tree gana.

#### Producto final esperado

El archivo `Actividad8-CC232.md` debe contener:

1. Respuestas completas por bloque.
2. Tablas solicitadas.
3. Evidencia de comandos ejecutados.
4. Fragmentos de código modificados si corresponde.
5. Salidas relevantes de demostraciones y pruebas.
6. Trazados manuales de colisiones, sondeos y tombstones.
7. Comparación final contra BST, Treap, AVL y Red-Black Tree.
8. Conclusión técnica personal.

Además, si modificaste código, entrega los archivos cambiados y menciona exactamente qué cambiaste.
