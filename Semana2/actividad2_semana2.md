## Actividad 2-CC232

### Integrantes
- RYDELL JONEL MOSQUERA HUAYHUA
- ANGEL JESUS NAVARRO RUIZ

#### Bloque 1
1. Expliquen con sus palabras qué significa que un arreglo use **memoria contigua**.

Significa que todos los elementos de la estructura se almacenan en un único bloque de memoria ininterrumpido. La disposición lógica de los elementos corresponde de forma exacta y directa a su disposición física secuencial en la memoria del sistema.

2. Expliquen por qué acceder a `A[i]` es una operación de costo `O(1)`.

El acceso a A[i] es O(1) porque, al estar alojado en memoria contigua, no se necesita recorrer secuencialmente los elementos previos para encontrar el dato buscado. La computadora encuentra la dirección exacta aplicando una fórmula: suma la dirección de inicio del bloque con el desplazamiento (m + i . s).

3. Expliquen la diferencia entre `size` y `capacity`.

* **Size**: Representa la cantidad real de elementos válidos que la secuencia contiene actualmente (plano lógico).
* **Capacity**: Indica el total de celdas o espacio de memoria reservado internamente, el cual puede ser mayor al tamaño para permitir crecimiento futuro (plano físico).

4. Expliquen por qué un arreglo dinámico no puede crecer "en el mismo sitio" y necesita reservar un bloque nuevo al hacer `resize()`.

La principal limitación del procedimiento de redimensionamiento radica en su costo temporal lineal O(n) por operación individual, ya que al estar basado en la rigidez de un bloque de memoria contigua, requiere reservar un espacio completamente nuevo, realizar una copia profunda de todos los elementos y liberar el arreglo anterior. Esta operación no solo genera picos de latencia, sino que también enfrenta desafíos de eficiencia espacial: si la capacidad es muy superior al tamaño real se produce un desperdicio de memoria (underflow), lo que obliga a ejecutar procesos de reducción (shrink) que son igualmente costosos. Además, en implementaciones más complejas como las colas circulares, el resize tiene la limitación de requerir una normalización del orden lógico de los elementos durante la copia, lo que añade una carga algorítmica adicional para mantener la integridad de la estructura.

5. Expliquen por qué duplicar capacidad permite defender costo amortizado `O(1)` para inserciones al final.

Duplicar la capacidad asegura que, tras pagar el costo O(n) de redimensionar, existan suficientes celdas libres para realizar muchas inserciones baratas O(1) antes del próximo redimensionamiento. Al distribuir el costo total de las expansiones entre todas las operaciones de una secuencia, el costo promedio resulta constante.

6. Comparen `ArrayStack` y `DengVector`: ¿qué comparten y qué cambia en interfaz o intención didáctica?

* **Comparten**: Ambos usan un arreglo dinámico de respaldo contiguo y estrategias de redimensionamiento.
* **Diferencias**: `ArrayStack` es una implementación minimalista orientada a la interfaz `List` básica. `DengVector` tiene una intención didáctica más profunda, enfocándose en el control del ciclo de vida (copia profunda, operadores de asignación) y ofreciendo un repertorio algorítmico más rico como búsqueda y deduplicación.

7. Expliquen qué mejora `FastArrayStack` respecto a `ArrayStack`.

`FastArrayStack` mejora el rendimiento práctico sustituyendo los bucles `for` explícitos por rutinas especializadas de bajo nivel como `std::copy` o `std::copy_backward`. Aunque no cambia la complejidad asintótica, acelera la ejecución empírica de forma significativa.

8. Expliquen cuál es la idea espacial central de `RootishArrayStack`.

Su idea central es minimizar el desperdicio de memoria. En lugar de un solo arreglo que duplica su tamaño (desperdiciando hasta $O(n)$), divide los elementos en múltiples bloques de tamaño creciente.

9. Expliquen por qué `RootishArrayStack` usa bloques de tamaños `1, 2, 3, ...`.

Se utilizan bloques con progresión aritmética para que la capacidad total crezca de forma controlada. Esto limita el desperdicio de espacio únicamente al último bloque, resultando en un desperdicio de solo $O(\sqrt{n})$ respecto al total de elementos.

10. Expliquen qué relación hay entre representación, costo temporal y desperdicio espacial en estas estructuras.

Existe un compromiso (*trade-off*) constante:
* La **representación** de arreglo simple da acceso rápido O(1) pero es rígida.
* Mantener la contigüidad ante cambios estructurales implica un alto **costo temporal** por desplazamientos.
* Para reducir la frecuencia de estos costos (redimensionamiento), se acepta un margen de **desperdicio espacial** (capacidad excedente).

#### Bloque 2
1. En `demo_array_basico.cpp`, ¿qué deja claro sobre arreglo, longitud y asignación?
Sobre el arreglo nos deja claro que es de tamaño fijo definido, la longitud (length) refleja cuantos elementos contiene y la asignación no copia, sino que hace una transferencia en donde b deja de tener sus valores iniciales y pasa a apuntar al mismo bloque de memoria que tenía a.

2. En `demo_arraystack_explicado.cpp`, ¿qué operación muestra mejor el costo por desplazamientos?
La operación que mejor muestra el costo por desplazamientos es add(1, 15), porque al insertar en una posición intermedia obliga a mover hacia la derecha todos los elementos desde el índice i hasta n-1 para abrir espacio — el propio demo lo explicita con el mensaje "se desplazan a la derecha los elementos desde i hasta n-1". Aunque remove(0) también desplaza, add en una posición media ilustra más claramente por qué el costo es O(n - i): mientras más al inicio se inserte, más elementos hay que mover, y en el peor caso — insertar en la posición 0 — se mueven los n elementos completos.

3. En `demo_fastarraystack.cpp`, ¿qué cambia en la implementación aunque no cambie la 
complejidad asintótica?
FastArrayStack cambia la implementación de movimiento de elementos usando std::copy_backward y std::copy en lugar de bucles for manuales, pero mantiene los mismos criterios de resize() y la misma complejidad asintótica.

4. En `demo_rootisharraystack_explicado.cpp`, ¿qué ejemplo explica mejor el mapeo de índice lógico a bloque y offset?
El ejemplo que mejor explica el mapeo es print_location(s, 2), porque a diferencia de locate(0) que es trivial y locate(5) que es el último elemento, el índice lógico 2 obliga a una traducción real: no vive en el bloque 2 sino en el bloque 1 offset 1, demostrando que bloque y offset no se leen directamente del índice sino que se calculan con la fórmula de la raíz cuadrada — que es precisamente la idea central de RootishArrayStack.

5. En `demo_deng_vector.cpp`, ¿qué observable permite defender el crecimiento de `capacity`?
El observable es la impresión de size y capacity en cada insert, que muestra que la capacidad no crece en cada inserción sino en saltos — típicamente duplicándose — mientras size crece de uno en uno. Eso evidencia directamente el costo amortizado O(1): la mayoría de inserciones son baratas y solo ocasionalmente se paga el costo de copiar todo el arreglo.

6. En `demo_stl_vector_contraste.cpp`, ¿qué similitud conceptual observan con `DengVector`?
Ambos muestran el mismo patrón: capacity crece en saltos que se duplican mientras size avanza de uno en uno, confirmando que DengVector reimplementa la misma estrategia de crecimiento amortizado de std::vector — no es una decisión arbitraria sino el estándar de la industria.

7. ¿Qué demo sirve mejor para defender **amortización** y cuál sirve mejor para defender **uso de espacio**?
La demo que mas sirve para defender amortización es demo_deng_vector.cpp porque imprime size y capacity en cada insert mostrando como la capacidad crece en saltos.
La demo que mejor sirve para defender uso de espacio es demo_rootisharraystack_explicado/cpp porque explica la idea de bloques de tamaño y muestra como el mapeo de índices reduce el desperdicio espacial.

#### Bloque 3
##### 1. ¿Qué operaciones mínimas valida la prueba pública para `ArrayStack`?
La prueba pública en test_public_week2.cpp valida la operaciones de inserción al final (add(x)), inserción por índice (add(i,x)), obtención del tamaño (size()), lectura por índice (get(i)) y eliminación por índice (remove(i))
##### 2. ¿Qué operaciones mínimas valida la prueba pública para `FastArrayStack`?
Para FastArrayStack, valida la inserción por índice usando el tamaño actual como posición(add(s.size(), x )) y add(i, x), la obtención del tamaño (size()), la lectura (get(i)) y la eliminación (remove(i))
##### 3. ¿Qué operaciones mínimas valida la prueba pública para `RootishArrayStack`?
La prueba pública para RootishArrayStack valida las operaciones de inserción al final (add(x)), inserción por índice (add(i,x)), obtención del tamaño (size()), lectura por índice (get(i)) y eliminación por índice (remove(i)). Además, dado su diseño basado en bloques, también verifica el correcto funcionamiento de la distribución de elementos en los bloques internos y el cálculo de la capacidad total.
##### 4. ¿Qué sí demuestra una prueba pública sobre una estructura?
Una prueba pública demuestra que la estructura cumple con su contrato/interfaz pública: que las operaciones básicas (inserción, eliminación, acceso, tamaño) funcionan correctamente para casos típicos y que la estructura se comporta según las especificaciones esperadas. Valida el comportamiento externo observable sin importar cómo esté implementada internamente.
##### 5. ¿Qué no demuestra una prueba pública?
Una prueba pública no demuestra aspectos internos como la correctitud de las invariantes de la estructura, el manejo eficiente de memoria, el cumplimiento de complejidades algorítmicas específicas (O(1), O(log n), etc.), ni el comportamiento en casos extremos o boundary conditions no cubiertos. Tampoco valida que la implementación sea correcta a nivel interno: puede haber fugas de memoria, errores en el manejo de estados intermedios, o violaciones de las pre/post-condiciones que no son visibles desde la interfaz pública. Las pruebas públicas solo verifican el comportamiento observable externo, no la calidad interna de la implementación.
##### 6. En `resize_stress_week2.cpp`, ¿qué comportamiento intenta estresar sobre crecimiento, reducción o estabilidad?
Esta prueba intenta estresar forzando ciclos masivos de redimensionamiento de memoria interna:
* **Crecimiento:** Se insertan secuencias largas de elementos (e.g., cientos o miles de inserciones consecutivas) para obligar a las estructuras a llamar a sus métodos de expansión subyacentes múltiples veces.
* **Reducción:** A continuación, se eliminan de forma masiva grandes bloques de elementos para desencadenar reducciones de capacidad o eliminación de bloques internos.
* **Estabilidad:** Verifica que, a pesar de estas agresivas reubicaciones de memoria, los datos restantes sigan siendo correctos y accesibles en sus índices correspondientes (por ejemplo, validando `v[i] == i + 700`).
##### 7. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes y complejidad?
Pasar pruebas es insuficiente porque estas son de naturaleza empírica y finita: solo aseguran que el estado de salida es el esperado para una entrada exacta. Un código muy ineficiente podría pasar estas pruebas si los datos son pocos. La explicación de **invariantes** demuestra matemáticamente el *por qué* la lógica siempre funciona sin importar la entrada, y el análisis de **complejidad** asegura que el diseño cumpla con los límites teóricos de escalabilidad, aspectos que una prueba funcional básica no puede validar intrínsecamente.
#### Bloque 4


##### 1. ¿Qué papel cumplen `_size`, `_capacity` y `_elem`?
* **`_elem`**: Es el puntero que apunta al arreglo interno (bloque contiguo) donde se almacenan físicamente los datos.
* **`_size`**: Registra el número real de elementos válidos contenidos en la secuencia (el tamaño lógico).
* **`_capacity`**: Indica cuántas celdas de memoria se han reservado físicamente en total. Esta separación de roles es lo que hace posible el crecimiento dinámico sin tener que reasignar memoria en cada inserción.

##### 2. ¿Cuándo debe ejecutarse `expand()`?
Debe ejecutarse cuando la capacidad actual se agota y existe riesgo de un *overflow*. En el código, esto ocurre explícitamente en el método `insert` cuando la estructura detecta que se ha quedado sin espacio (`_size == _capacity`), forzando la reserva de un bloque más grande (usualmente el doble).

##### 3. ¿Por qué `insert(r, e)` necesita desplazar elementos?
Un arreglo requiere obligatoriamente el uso de memoria contigua. Por lo tanto, al insertar un elemento en la posición o rango `r`, todos los elementos ya existentes que están a su derecha (el sufijo `[r, _size)`) deben desplazarse una posición hacia la derecha para hacerle un espacio físico al nuevo elemento sin sobrescribir información previa. 

##### 4. ¿Qué diferencia conceptual hay entre `remove(r)` y `remove(lo, hi)`?
* **`remove(lo, hi)`** es la operación estructural principal que elimina todo un intervalo, desplazando el sufijo restante una sola vez hacia la izquierda para cubrir el hueco.
* **`remove(r)`** se diseña como un **caso particular** de la eliminación por intervalo (eliminando desde `r` hasta `r + 1`). Esta conceptualización evita repetir innecesariamente múltiples desplazamientos si se pretendiera eliminar un intervalo quitando elemento por elemento.

##### 5. ¿Qué evidencia de copia profunda aparece en la demo?
La evidencia de la copia profunda (deep copy) se refleja en el control estricto de la memoria a través de métodos de clonación de la estructura. En `DengVector.h`, esto se materializa mediante el método `copyFrom()`, el cual se invoca explícitamente en el **constructor por copia** y en el **operador de asignación** (`operator=`). Esto asegura que el nuevo vector instancie su propia área de almacenamiento y copie los elementos, previniendo errores al modificar vectores que de otra forma compartirían el mismo bloque interno.

##### 6. ¿Por qué `traverse()` es una buena interfaz didáctica?
`traverse()` es didácticamente excelente porque materializa la idea abstracta de que el vector no es un simple receptáculo de datos, sino que soporta un procesamiento estructurado de toda la colección. Permite recorrer el vector y aplicar una misma acción, función o transformación a cada elemento de manera uniforme (mediante punteros a función u objetos función).

##### 7. ¿Qué ventaja tiene implementar un vector propio antes de depender de `std::vector`?
Implementar un vector propio tiene un inmenso valor formativo, ya que obliga a lidiar con problemas centrales del diseño algorítmico que los contenedores prefabricados como `std::vector` ocultan de la vista del programador. Enseña la diferencia práctica entre interfaz abstracta e implementación interna, expone la necesidad de gestionar manualmente la memoria dinámica (destructores, fugas), resalta la importancia de la copia profunda y obliga a razonar usando análisis amortizado para entender el costo real de las operaciones.

#### Bloque 5

##### 1. ¿Cómo se distribuyen los elementos entre bloques?
Los elementos no se almacenan en un único arreglo gigante, sino que se organizan en una lista de múltiples arreglos más pequeños (bloques) de tamaños progresivos. Específicamente, el bloque 0 tiene capacidad para 1 elemento, el bloque 1 para 2 elementos, el bloque 2 para 3, y en general, el bloque $b$ tiene capacidad para $b+1$ elementos.
##### 2. ¿Por qué con `r` bloques la capacidad total es `r(r+1)/2`?
Porque la capacidad total es simplemente la suma de las capacidades de todos los bloques creados hasta el momento. Dado que los bloques tienen capacidades que siguen la secuencia $1, 2, 3, \\dots, r$, esta suma corresponde a la progresión aritmética (o suma de Gauss), cuya fórmula matemática exacta es $\\frac{r(r+1)}{2}$.
##### 3. ¿Qué problema resuelve `i2b(i)`?
Resuelve el problema de traducción entre el mundo lógico y la memoria física. Dado un índice lógico global `i` (la posición aparente del elemento en la lista continua), determina matemáticamente a qué bloque físico `b` pertenece. Para lograrlo, despeja $b$ usando la ecuación cuadrática inversa de la capacidad, lo que se refleja en la fórmula matemática `(-3.0 + sqrt(9 + 8*i)) / 2.0`.
##### 4. ¿Qué información produce `locate(i)` en la versión explicada?
Basado en los objetivos didácticos del repositorio, `locate(i)` expone la dupla que detalla el mapeo interno: calcula y devuelve tanto el **bloque** (`b`) donde se encuentra el elemento, como el **offset** o índice local (`j`) que dicho elemento ocupa dentro de ese bloque en particular.
##### 5. ¿Qué se gana en espacio frente a `ArrayStack`?
Se gana una drástica reducción del espacio desperdiciado en memoria. Mientras que `ArrayStack` (que duplica su capacidad al crecer) puede llegar a desperdiciar un espacio proporcional al total de elementos ($O(n)$), `RootishArrayStack` solo desperdicia espacio en su último bloque. Esto acota el desperdicio al tamaño de ese último bloque, logrando una eficiencia donde el espacio extra es de orden $O(\\sqrt{n})$.
##### 6. ¿Qué se conserva igual respecto a la interfaz?
A pesar de su compleja representación interna, se conserva intacta la interfaz de una lista (ADT List). Hacia el usuario exterior, ofrece exactamente las mismas operaciones: `size()`, `get(i)`, `set(i, x)`, `add(i, x)` y `remove(i)`.
##### 7. ¿Qué parte les parece más difícil de defender oralmente: el mapeo, el análisis espacial o el costo amortizado de `grow/shrink`?
El **mapeo `i2b(i)`** suele ser la parte más difícil de explicar y defender oralmente. A diferencia del análisis espacial o amortizado (que pueden ilustrarse con analogías intuitivas como "solo sobra el último bloque" o "el costo duro se reparte entre muchas inserciones"), explicar el mapeo exige que el interlocutor visualice una deducción algebraica en el aire. Explicar oralmente cómo la inecuación cuadrática $\\frac{b(b+1)}{2} \\le i$ deriva en la aplicación de la fórmula resolvente de segundo grado con raíz cuadrada y el uso de un techo (`ceil`), resulta bastante abstracto sin el apoyo de una pizarra o notación matemática formal.

#### Bloque 6

##### 1. ¿Qué aporta `operator[]` a la idea de vector?

La sobrecarga del operator[] permite recuperar el estilo de acceso directo propio de los arreglos tradicionales sin renunciar a la encapsulación que ofrece el vector. Esta funcionalidad aporta una notación natural que mejora la claridad del código y acerca la implementación técnica al modelo mental intuitivo del programador, facilitando el uso de la estructura como una secuencia indexada de fácil acceso.

##### 2. ¿Qué supone `find(e)` sobre igualdad entre elementos?

La operación find(e) supone que el tipo de dato almacenado tiene definida una relación de igualdad que permite compararlo con el elemento buscado e. Dado que se realiza una búsqueda secuencial en vectores no ordenados, el algoritmo asume que puede verificar la identidad de cada elemento para devolver la coincidencia de mayor rango o un valor de -1 en caso de que no exista un elemento igual en la estructura.

##### 3. ¿Qué muestra `traverse()` sobre procesamiento uniforme de toda la estructura?

La función traverse() muestra que el vector está diseñado para el procesamiento uniforme al permitir tratar la colección como un todo y aplicar una misma transformación o acción sobre cada uno de sus elementos. Esta operación refleja una idea de alto nivel donde el vector deja de ser un simple contenedor pasivo para convertirse en una estructura que soporta operaciones globales mediante objetos función, manteniendo un costo lineal respecto al tamaño total.

##### 4. ¿Por qué esta lectura sirve como refuerzo natural de `DengVector` aunque no sea el centro exclusivo de la semana?

Esta lectura refuerza el concepto de DengVector porque profundiza en los fundamentos del vector como un Tipo de Dato Abstracto (ADT), tales como la gestión dinámica de memoria, la distinción entre tamaño y capacidad, y el análisis amortizado. Al comparar diversas listas basadas en arreglos, se clarifica que el diseño del vector basado en el rango y en estrategias como la duplicación de capacidad es una respuesta técnica para equilibrar la rigidez de la memoria física con la eficiencia necesaria en las operaciones modernas.

#### Bloque 7
Al pasar de usar un simple arreglo a diseñar una estructura dinámica basada en arreglos, la transición implica dejar de ver la memoria como un bloque estático para convertirla en un Tipo de Dato Abstracto (ADT) con lógica propia.Los cambios fundamentales se resumen en los siguientes puntos:

- Representación: La estructura evoluciona de un simple bloque indexado a una abstracción basada en el rango, donde se separa estrictamente la capacidad física (memoria reservada) del tamaño lógico (elementos válidos), permitiendo que la disposición física en memoria coincida con el orden secuencial para mantener el acceso directo.

- Correctitud: La validez de la estructura depende de garantizar la propiedad y liberación de la memoria mediante el uso de copias profundas (evitando que dos instancias compartan el mismo bloque interno) y el mantenimiento de invariantes lógicas que aseguran la integridad de los datos durante operaciones como la eliminación de duplicados.

- Costo amortizado: Aunque operaciones como el resize() tienen un costo individual lineal O(n), el uso de una política de duplicación de capacidad asegura que el costo total de los redimensionamientos en una secuencia larga de operaciones sea O(m), lo que resulta en un costo amortizado constante (O(1)) por operación

- Uso de espacio: Se introduce el concepto de factor de carga para equilibrar la eficiencia espacial; así, mediante el procedimiento shrink(), se combate el desperdicio de memoria (underflow) cuando la ocupación cae por debajo de un umbral, manteniendo un equilibrio entre rapidez y uso de recursos.

- Comparación de estructuras: El ArrayStack es la implementación base que ofrece eficiencia en el extremo final; el FastArrayStack optimiza el rendimiento práctico (acelerando la ejecución 2 o 3 veces) mediante rutinas de copia de bajo nivel sin cambiar la complejidad asintótica; por último, cabe señalar que RootishArrayStack no se menciona en las fuentes proporcionadas, por lo que no es posible establecer su comparación técnica basada exclusivamente en este material (aunque habitualmente se conoce por optimizar el desperdicio de espacio a un nivel sublineal).

#### Autoevaluación breve
- Qué podemos defender con seguridad:
- Qué todavía confundimos:
- Qué evidencia usaríamos en una sustentación: