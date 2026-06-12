Alumno: Angel Navarro Ruiz 20231506A

### Actividad 4 - Semana 4

- Duración: 3 horas de clase.
- Modalidad: Trabajo individual.
- Tiempo de instalación: 15 minutos al inicio.
- Entrega: Un archivo llamado `Actividad4-CC232.md`.

#### Bloque 0 - Instalación y preparación

1. Deja lista tu carpeta de trabajo.
2. Verifica que puedes abrir `Semana4`, las lecturas y el archivo de entrega.
3. Crea el archivo `Actividad4-CC232.md`.
4. Anota tu nombre completo.
5. Compila y ejecuta al menos una demostración y una prueba pública de Semana 4.

#### Bloque 1 - Núcleo conceptual de la semana

Revisa:

- `Semana4/README.md`
- `Semana4/include/Stack.h`
- `Semana4/include/Queue.h`
- `Semana4/include/BaseConversion.h`
- `Semana4/include/Parentheses.h`
- `Semana4/include/ExpressionEvaluator.h`
- `Semana4/include/NQueens.h`
- `Semana4/include/Maze.h`
- `Semana4/include/BankSimulation.h`
- Capítulo 4 de Deng.

Responde:

1. Explica con tus palabras la diferencia entre acceso `LIFO` y acceso `FIFO`.

La diferencia entre LIFO y FIFO está en el orden en que se “atienden” los elementos: 
- LIFO (Last In, First Out) el último en entrar es el primero en salir, como cuando estás armando una torre de libros y 
el último que colocas arriba es el primero que retiras. 
- FIFO (First In, First Out) el primero en entrar es el primero en salir, como en una fila para comprar entradas donde la 
primera persona en llegar es la primera en ser atendida, manteniendo así el orden original.

2. Explica por qué `Stack` resuelve naturalmente problemas donde importa "lo último pendiente".

Una Stack encaja de forma natural en problemas donde importa “lo último pendiente” porque siempre te permite acceder 
primero a lo más reciente, que suele ser lo que necesitas resolver antes de volver a lo anterior, es como cuando estás 
editando un documento y vas haciendo cambios, por ejemplo:
Si cometes un error, lo lógico es usar “deshacer” para revertir el último cambio, no uno antiguo al azar, ya que ese es 
el que está más “activo” en tu contexto actual, y una pila modela exactamente ese comportamiento al guardar cada acción y 
permitirte retroceder paso a paso desde la más reciente hacia las anteriores.

3. Explica por qué `Queue` modela naturalmente procesos de espera y atención.

Una Queue modela naturalmente procesos de espera y atención porque respeta el orden de llegada, haciendo que cada 
elemento sea atendido en el mismo orden en que entró, lo cual refleja cómo funcionan muchas situaciones reales; por 
ejemplo, en una parada de buses, las personas se forman y el primero que llega es el primero en subir cuando llega el 
bus, evitando conflictos y manteniendo un flujo justo, ya que nadie puede “saltarse” a los demás, exactamente como en una 
cola FIFO donde el primero en entrar es el primero en salir.

4. Explica qué significa reemplazar recursión implícita por una estructura explícita.

Reemplazar la recursión implícita por una estructura explícita significa dejar de depender de la “memoria automática” del 
programa (la pila de llamadas) y empezar a manejar tú mismo qué cosas quedan pendientes usando, por ejemplo, una pila; es 
como cuando sigues una receta compleja: en lugar de confiar en que recordarás mentalmente cada paso pendiente 
(recursión), escribes en un papel los pasos que aún faltan y los vas resolviendo uno por uno, tachando el último que 
agregaste primero, de modo que ahora eres tú quien controla completamente el orden y el proceso en lugar de dejarlo 
oculto dentro del sistema.

5. Explica qué información mínima debe guardarse para que una pila permita reconstruir una solución parcial.

Para que una pila permita reconstruir una solución parcial, debe guardar la información mínima necesaria de cada paso 
pendiente, es decir, el estado suficiente para poder continuar o retroceder correctamente; por ejemplo, si estás 
resolviendo un laberinto, no basta con recordar que “entraste”, sino que necesitas guardar en la pila la posición actual 
y quizá las decisiones que aún no has probado (como direcciones disponibles), de modo que si llegas a un callejón sin 
salida, puedas volver exactamente al último punto donde aún quedaban opciones y continuar desde ahí sin perder el 
contexto.

6. Compara la conversión de base recursiva e iterativa: ¿qué comparten y qué cambia en el control del proceso?

En cada paso ambas calculan el mismo residuo n % base y dividen entre la base hasta que n==0. Lo que cambia es el modo en que se administra el orden de los dígitos: 
- la versión recursiva apila los residuos en el call stack (los dígitos más significativos quedan en los frames más profundos) 
- la iterativa apila explícitamente en Stack<char>. Ambas terminan con popAll para invertir el orden y formar la cadena.  El resultado es el mismo, lo que varía es quién controla la pila.

7. Explica por qué la verificación iterativa de paréntesis necesita almacenar aperturas pendientes.

Un cierre como ) solo es válido cuando se tiene un ( anterior sin cerrar. No se puede saber cuántas aperturas quedan pendientes ni cuál tipo era la más reciente, sin memoria de las aperturas pendientes. 
La pila guarda precisamente eso: los abridores en el orden en que llegaron, de modo que cuando aparece un cierre se consulta el tope y se verifica correspondencia inmediata.

8. Explica por qué el evaluador de expresiones necesita dos pilas y no una sola.

Los operandos y los operadores son de naturaleza distinta y tienen reglas distintas de extracción. Los operandos se toman de la pila Stack<double> de a dos (o uno en el caso de las factoriales) cuando se aplica un operador. Los operadores (Stack<char>) se retienen mientras su precedencia lo permita aplicar. Mezclar ambos en una sola pila requeriría discriminar tipos en tiempo de extracción y rompería la lógica de prioridad.

9. Explica por qué N-Reinas y laberinto son ejemplos naturales de backtracking.

Los dos recorren un espacio de decisiones en el que cada paso puede conducir a un callejón sin salida. No existe una fórmula directa para la solución, hay que probar, comprobar y si falla, deshacer y probar otra opción. La pila guarda el camino parcial construido hasta ese momento; cuando no hay más avance posible, se extrae el último estado y se prueba la siguiente alternativa desde ahí.

10. Explica por qué la simulación bancaria no se modela bien con pila, pero sí con colas.

Una pila sirve al último llegado, invirtiendo el orden de llegada, en un banco esto es inaceptable: hay que atender antes a los clientes que llevan más tiempo esperando, no después. 

La cola guarda el orden FIFO y representa la política real de “primero llegado, primero servido”. Al usar una pila se produciría la inanición de los clientes más antiguos.

11. Explica qué relación hay entre estructura auxiliar, estado parcial y correctitud.

La estructura auxiliar (pila o cola) almacena el estado parcial. Si la estructura mantiene la información correcta en el orden correcto, entonces el algoritmo puede reconstruir o continuar el cómputo desde cualquier punto. La corrección depende de que se guarde lo suficiente y no más: guardar de más hace perder memoria; guardar de menos impide reconstruir la solución.

12. Explica qué diferencia conceptual hay entre "resolver un problema" y "simular un proceso".

- Resolver un problema busca una respuesta definitiva: la cadena en la base pedida, si los paréntesis se balancean, el valor de la expresión. La solución es correcta o es incorrecta. 
- Simular un proceso es reproducir el comportamiento de un sistema en el tiempo: clientes que llegan, son atendidos y salen.

No hay una única "respuesta correcta", el objetivo es que el comportamiento emergente sea fiel al modelo real. La corrección es probabilística o estadística, no booleana.

#### Bloque 2 - Demostración y trazado guiado

Revisa:

- `Semana4/demos/demo_stack_queue.cpp`
- `Semana4/demos/demo_base_conversion.cpp`
- `Semana4/demos/demo_paren_rpn.cpp`
- `Semana4/demos/demo_nqueens.cpp`
- `Semana4/demos/demo_maze.cpp`
- `Semana4/demos/demo_bank.cpp`
- `Semana4/demos/demo_capitulo4_panorama.cpp`

Construye una tabla con cuatro columnas:

- Archivo
- Salida u observable importante
- Estructura o técnica central
- Qué concepto permite defender

Luego responde:

1. En `demo_stack_queue.cpp`, ¿qué parte de la salida deja más clara la diferencia entre tope y frente?

La parte que deja más clara la diferencia es cuando se imprime “Tope de la pila” frente a “Frente de la cola”, porque ahí se ve directamente cómo cada estructura “mira” sus elementos: 
- En la pila (stack), el tope corresponde al último valor insertado (9)
- Mientras que en la cola (queue), el frente corresponde al primer valor que entró (10)
Este contraste muestra claramente que la pila trabaja con el elemento más reciente, mientras la cola respeta el orden de llegada.

2. En `demo_base_conversion.cpp`, ¿qué observable permite afirmar que las versiones recursiva e iterativa producen la misma representación?

Lo que afirma ello es la misma representación es que las dos imprimen exactamente la misma cadena como resultado para el mismo número y base; es decir, si tanto la versión recursiva como la iterativa muestran, el mismo valor en base 8 para 12345, entonces queda claro que, aunque usan métodos distintos, están construyendo la misma salida final, lo que demuestra que son equivalentes en funcionamiento.

3. En `demo_paren_rpn.cpp`, ¿qué relación observas entre paréntesis balanceados, RPN y valor final?

La relación es que los paréntesis balanceados aseguran que la expresión sea válida, lo que permite convertirla correctamente a RPN, y a partir de esa RPN se puede calcular el valor final; es decir, si la estructura inicial está bien, tanto la conversión como el resultado serán correctos.

4. En `demo_nqueens.cpp`, ¿qué significan `solutions` y `checks`, y por qué no miden lo mismo?

- 'solutions' es el número de arreglos completos de N reinas sin conflictos que se han encontrado (2 para N=4). 
- 'checks' cuenta cuántas veces se ha ejecutado la comparación entre una candidata y las ya colocadas (84). 

No miden lo mismo porque muchas verificaciones se hacen para configuraciones que nunca llegan a ser solución; checks refleja el costo total de búsqueda, incluyendo los caminos descartados.

5. En `demo_maze.cpp`, ¿qué muestra la secuencia de coordenadas sobre el camino encontrado?

La secuencia (1,1)(1,2)(1,3)(2,3)(3,3) indica que el algoritmo recorrió la fila superior del interior (columnas 1->2->3), descendió a la fila 2 por la columna 3 (única libre, pues la central es muro) y alcanzó el destino. La trayectoria muestra que la pila fue construyendo el camino paso a paso, y que no hubo vuelta atrás en este laberinto particular.

6. En `demo_bank.cpp`, ¿qué representa cada lista impresa en cada instante `t`?

Cada línea t=k: [a,b,...] [c,...] [d,...] indica los tiempos de servicio que le quedan a cada cliente en cada ventanilla en el instante k. En cada paso, el primer número de cada par disminuye en uno (se atiende al cliente que está al frente). Cuando llega a cero se borra de la lista. El estado instantáneo de las tres colas constituye la lista completa en cada instante.

7. En `demo_capitulo4_panorama.cpp`, ¿qué salida resume mejor la idea de que una misma semana reúne estructuras y aplicaciones?

La salida de panorama retoma todos los temas: tope de pila, frente de cola, conversión de base, paréntesis, RPN, valor, soluciones de N-Reinas, longitud del camino y estadísticas bancarias. Y la línea que mejor resume la semana es aquella que imprime el valor 2012 junto a la RPN completa, pues combina las dos pilas, la prioridad de operadores y el resultado numérico en un solo observable.

#### Bloque 3 - Pruebas públicas, pruebas internas y correctitud

Revisa:

- `Semana4/pruebas_publicas/test_public_week4.cpp`
- `Semana4/pruebas_internas/test_internal_week4.cpp`

Responde:

1. ¿Qué operaciones mínimas valida la prueba pública para `Stack`?

Para Stack: vacío inicial, push de dos elementos, top devuelve el último, pop devuelve en orden LIFO, vacío final.

2. ¿Qué operaciones mínimas valida la prueba pública para `Queue`?

Para Queue: vacío inicial, enqueue de tres elementos, front devuelve el primero, dequeue en orden FIFO para los tres, vacío final.

3. ¿Qué valida la prueba pública sobre conversión de base?

Conversión de base: 
- toBaseRecursive(12345, 8) == "30071" y 
- toBaseIterative(12345, 8) == "30071".

4. ¿Qué valida la prueba pública sobre paréntesis balanceados?

Paréntesis:
- parenRecursive("a+(b*(c+d))") es true; 
- parenIterative("a+(b*[c-{d/e}])") es true; 
- parenIterative("([)]") es false.

5. ¿Qué valida la prueba pública sobre evaluación de expresiones y RPN?

Expresión (0!+1)*2^(3!+4)-(5!-67-(8+9)): RPN igual a "0 ! 1 + 2 3 ! 4 + ^ * 5 ! 67 - 8 9 + - -" y valor 2012.0.

6. ¿Qué valida la prueba pública sobre `NQueens`?

N-Reinas: 
- placeQueens(4).solutions == 2 
- placements.size() == 2.

7. ¿Qué valida la prueba pública sobre `Maze`?

Laberinto 5×5 con obstáculo central: camino no vacío, inicio en (1,1) y fin en (3,3).

8. ¿Qué valida la prueba pública sobre `bestWindow` en la simulación bancaria?

bestWindow: tres ventanillas con tamaños 2, 1, 0 -> selecciona la ventanilla 2 (índice 2, la vacía).

9. ¿Qué casos adicionales cubre la prueba interna y no aparecen de forma explícita en la pública?

La prueba interna agrega: conversión del cero en base 2 ("0"), conversión de 255 en base 16 ("FF"), cadena sin paréntesis (true recursivo), inicio con cierre ()()( es false), cruce de tipos {[(])} es false iterativo, expresiones 3+4*2, 5!+2^3 y -3+5 con sus RPN y valores, N-Reinas para n=1, laberinto sin salida (camino vacío), simulación completa con timeline.size()==8 y totalArrivals >= totalServed, e invalidación de base 1.

10. ¿Por qué pasar pruebas no reemplaza una explicación de invariantes, estado y complejidad?

Los tests comprueban casos concretos, pero no muestran que el invariante se cumple para todo posible input, ni que la complejidad es la esperada, ni que el estado intermedio siempre sea coherente. Para demostrar la corrección hay que indicar lo que garantiza la estructura en cada paso del bucle o de la recursión.

11. Da un ejemplo de un error conceptual que podría sobrevivir si solo se ejecutaran los casos mínimos.

Un error conceptual que podría vivir es una parenIterative implementada que solo contara aperturas y cierres sin verificar el tipo correspondiente pasaría los casos mínimos (que usan solo ()) pero fallaría silenciosamente con ([)]. La prueba pública no comprueba ese cruce con un único tipo de delimitador.

#### Bloque 4 - Comparación recursivo vs iterativo

Revisa:

- `Semana4/include/BaseConversion.h`
- `Semana4/include/Parentheses.h`
- `Semana4/demos/demo_base_conversion.cpp`
- `Semana4/demos/demo_paren_rpn.cpp`

Responde:

1. En conversión de base, ¿qué papel juegan el cociente, el residuo y la pila?

En cada paso se calcula n % base (residuo = dígito actual) y n / base (cociente = siguiente número a convertir). La pila acumula los residuos en orden inverso al deseado, popAll los extrae en el orden correcto para formar la cadena.

2. ¿Por qué los residuos se apilan antes de formar la cadena final?

El algoritmo de conversión va generando los dígitos del menos significativo al más significativo (al igual que la división manual). Los hemos de invertir para que la cadena final quede en orden convencional (más significativo primero). De forma natural, la pila hace esa inversión: el que entra primero, sale último.

3. ¿Qué cambia entre dejar que el call stack haga el trabajo y manejar una pila explícita?

Con una pila explícita el programador controla exactamente lo que se almacena, puede inspeccionarla, y evita el overhead de llamadas recursivas para números muy grandes. El resultado es el mismo, lo que cambia es el control y la visibilidad.

4. En `parenRecursive`, ¿qué idea intenta capturar `divideParentheses`?

divideParentheses busca el punto donde se cierra el primer bloque parentético: avanza desde lo+1 contando la profundidad (crc) hasta que vuelve a 1, es decir que el (inicial encontró su ) correspondiente. Esto separa la expresión en dos subexpresiones independientes que se comprueban de forma recursiva.

5. ¿Qué limitación conceptual tiene la versión recursiva mostrada frente a la iterativa cuando aparecen `[]` y `{}`?

La versión recursiva mostrada reconoce solo ( y ): 
trimParentheses ignora [, ], {, } y 
divideParentheses sólo cuenta ( y ). 
Si la expresión contiene [] o {}, la recursión los considera como no-paréntesis y puede dar resultados incorrectos. La versión iterativa utiliza un switch para gestionar de forma explícita los tres tipos.

6. En `parenIterative`, ¿por qué un cierre incorrecto puede detectarse apenas aparece?

En cuanto aparece un cierre, se toma el tope de la pila y se compara. Si no coincide (por ejemplo, el tope es [ y llegó )), el error se detecta en ese preciso carácter, sin necesidad de seguir procesando el resto de la cadena.

7. Compara ambas parejas de funciones: ¿en cuál caso la versión iterativa te parece más natural y en cuál la recursiva resulta más expresiva?

La versión iterativa se siente más natural en paréntesis con múltiples tipos de delimitadores, porque el switch hace explícito cada caso. En la conversión de base, la versión recursiva es más expresiva, ya que la estructura convertRecursive(stack, n/base, base) refleja directamente la definición matemática recursiva del algoritmo.

##### Experimento 1

Ejecuta pruebas propias con al menos cinco números y cuatro bases distintas para `toBaseRecursive` y `toBaseIterative`.

Registra en una tabla:

- Número
- Base
- Salida recursiva
- Salida iterativa
- ¿Coinciden?
- Comentario

##### Experimento 2

Construye una batería de al menos ocho expresiones para paréntesis, incluyendo:

- una vacía,
- una sin paréntesis,
- una correctamente anidada,
- una con desbalance,
- una con cruce incorrecto,
- una con varios tipos de delimitadores,
- una larga,
- una inventada por ti.

Para cada caso indica:

- resultado recursivo,
- resultado iterativo,
- si ambos coinciden,
- qué explica el caso.

#### Bloque 5 - Evaluación de expresiones y prioridad de operadores

Revisa:

- `Semana4/include/OperatorPriority.h`
- `Semana4/include/ExpressionEvaluator.h`
- `Semana4/demos/demo_paren_rpn.cpp`
- `Semana4/pruebas_publicas/test_public_week4.cpp`
- `Semana4/pruebas_internas/test_internal_week4.cpp`

Responde:

1. Explica qué información guarda `EvaluationResult`.

EvaluationResult tiene dos campos: 
- value (el resultado numérico double de la expresión) y 
- rpn (la cadena con la representación en notación polaca inversa, construida durante la evaluación).

2. Explica por qué primero se eliminan espacios.

Los espacios no son operadores ni operandos válidos en la tabla de prioridades. Si se dejaran, optr2rank lanzaría "operador desconocido" intentando clasificar un espacio. Eliminarlos primero simplifica el bucle principal, que no necesita lógica especial para evitarlos.

3. Explica cómo se detecta el signo menos unario.

isUnaryMinus comprueba que el carácter actual sea -, que el siguiente sea un dígito o punto, y que la posición anterior sea el inicio de la cadena, un ( o un operador binario. Estas condiciones distinguen -3 (signo) de 5-3 (resta).

4. Explica por qué el factorial se trata como operador unario y qué restricción impone el código.

El factorial ! se considera como un operador postfijo unario: se aplica a un solo operando (calcu('!', b)). La condición es que el operando debe ser un entero no negativo: el código redondea el double y comprueba que la diferencia con el original es menor a 1e-9, si no es entero lanza error.

5. Explica cómo la RPN se va construyendo durante la evaluación y no al final.

Si orderBetween devuelve '>', se ejecuta el operador del tope, y su símbolo se incluye en rpn con appendRpn. La RPN va acumulándose en el momento que se ejecuta cada operador, no al terminar. 
Los operandos, al leerlos, se añaden a rpn.

6. Explica qué significa la relación entre operador del tope y símbolo actual.

El relación '<' quiere decir que el operador actual tiene mayor prioridad que el tope: se apila sin ejecutar nada. El signo '>' significa que el límite tiene prioridad mayor o igual: se aplica el límite antes de continuar. 
La relación '=' tiene paréntesis: se eliminan ambos sin aplicar operación, ese algoritmo se basa en el método shunting-yard.

7. Explica por qué una expresión mal formada debe terminar en error y no en un valor arbitrario.

Si la expresión es incorrecta (por ejemplo, "3+"), cuando se llegue al '\0', el evaluador intentará aplicar el +, pero encontrará menos de dos operandos en la pila, arrojando "falta operandos para el operador binario". Continuar y devolver un valor arbitrario permitiría que errores silenciosos propagaran resultados incorrectos sin avisar al usuario.

8. ¿Qué ventaja conceptual tiene obtener a la vez el valor y la RPN?

Obteniendo valor y RPN simultáneamente se evita recorrer dos veces la expresión. 
La RPN es, además, evidencia directa de que el evaluador interpretó la precedencia correctamente: si la RPN es la esperada y el valor es correcto, ambos resultados se validan mutuamente.

##### Experimento 3

Propón y ejecuta al menos seis expresiones nuevas:

- dos válidas sin paréntesis,
- dos válidas con anidamiento,
- una con menos unario,
- una inválida.

Para cada una registra:

- expresión,
- RPN esperada,
- RPN obtenida,
- valor esperado u error esperado,
- valor obtenido o error observado,
- explicación breve.

##### Extensión opcional

Extiende el evaluador con un operador adicional elegido por ti.

La defensa debe incluir obligatoriamente:

- qué símbolo agregaste,
- su aridad,
- su prioridad,
- qué casos válidos probaste,
- qué caso inválido probaste,
- qué parte del código tuviste que modificar.

#### Bloque 6 - Backtracking explícito: N-Reinas y laberinto

Revisa:

- `Semana4/include/Queen.h`
- `Semana4/include/NQueens.h`
- `Semana4/include/Maze.h`
- `Semana4/demos/demo_nqueens.cpp`
- `Semana4/demos/demo_maze.cpp`
- `Semana4/pruebas_publicas/test_public_week4.cpp`
- `Semana4/pruebas_internas/test_internal_week4.cpp`

Responde:

1. En `Queen`, ¿qué significa que dos reinas entren en conflicto?

Dos reinas se “atacan” si están en una misma fila, en una misma columna, o en una misma diagonal. La reina funciona 
exactamente como en el ajedrez: puede moverse en cualquiera de esas direcciones, por lo que si dos reinas comparten 
alguna de ellas, una podría capturar a la otra.

2. En `NQueens`, ¿qué representa exactamente la pila `solution`?

Es la lista de reinas que ya pusimos para que no se ataquen entre ellas. Si vamos en el tablero de 4×4 y ya pusimos 
reinas en las filas 0 y 1, la pila tiene esas dos reinas guardadas. Si en la fila 2 no hay ninguna columna válida, 
cogemos la última reina de la pila y probamos otra columna para esa reina.

3. ¿Qué significa avanzar en columna dentro de una fila y cuándo toca retroceder?

En cada fila probamos una columna a la vez: 0, 1, 2, 3... Si la columna actual no entra en conflicto, ponemos la reina 
allí y pasamos a la siguiente fila. Si no funciona ninguna de las columnas de esa fila, "hacemos marcha atrás": sacamos 
la última reina de la pila y buscamos otra columna para esa reina.
Es como buscar las llaves de tu casa, abres un cajón y si no están en él, pasas al siguiente; si ya revisaste todos los 
cajones de un cuarto, sales y buscas en otro cuarto.

4. ¿Por qué `checks` es una métrica útil para analizar la búsqueda?

checks cuenta cada vez que el algoritmo pregunta “¿esta reina choca con alguna de las ya colocadas?”. Mide el trabajo 
total realizado, incluidos todos los intentos fallidos. Para n=4 hubo 84 comprobaciones pero solo 2 soluciones: la mayor 
parte del trabajo consistió en desechar caminos sin salida.

5. ¿Qué cambia cuando `collectPlacements` vale `false`?

El algoritmo también encuentra todas las soluciones y las cuenta, pero no las guarda en memoria. ​Es como saber cuántas 
veces has ganado un juego sin anotar cada partida, útil cuando solo te importa el número total, no los detalles de cada 
solución.

6. En `Maze`, ¿qué representa el estado `AVAILABLE`, `ROUTE`, `BACKTRACKED` y `WALL`?

Imagina que estamos fisicamente recorriendo un laberinto hecho de tiza:
DISPONIBLE: celda intacta, nunca pisada
ROUTE: casilla de tu ruta actual, marcada con tiza
BACKTRACKED: celda que has intentado y era un callejón sin salida, marcada con una X
WALL: pared, nunca tocarse

7. ¿Qué información codifican `incoming` y `outgoing`?

incoming es por donde entraste a esa celda (ejemplo: “vine del norte”). outgoing es hacia donde intentas salir (“voy a
probar hacia el este”). Juntos le indican al algoritmo su origen y las direcciones que ya han sido probadas, evitando 
repeticiones y regresos no deseados.

8. ¿Por qué el algoritmo del laberinto marca y desmarca estado en lugar de solo "moverse"?

Si no llevas un registro de las celdas visitadas, el algoritmo podría entrar en círculos infinitos: va de A a B, de B a 
A, de A a B... para siempre. Al marcar como ROUTE al entrar y como BACKTRACKED al retroceder, se asegura que no se vuelva 
a intentar ninguna celda descartada.

9. Compara N-Reinas y laberinto: ¿qué comparten como problemas de búsqueda y qué cambia en la representación del estado?

Prueban una y otra vez, y cuando se encuentran en un punto muerto, deshacen el último movimiento y prueban otra cosa. La 
diferencia es que en N-Reinas el «estado» es qué reinas están colocadas, y en el laberinto es en qué celda estás parado. 
En el N-Reinas buscas todas las soluciones, en el laberinto sólo buscas una.

##### Experimento 4

Ejecuta `placeQueens(n)` para al menos cuatro valores de `n`.

Registra en una tabla:

- `n`
- número de soluciones
- número de `checks`
- ¿crece rápido o lento?
- comentario

Luego responde:

1. ¿Qué patrón observas en el crecimiento de `checks`?
2. ¿Por qué contar verificaciones no es lo mismo que contar soluciones?
3. ¿Dónde aparece la "poda" en este código, aunque no haya una estructura formal con ese nombre?

##### Experimento 5

Diseña al menos tres laberintos propios:

- uno con camino claro,
- uno sin salida,
- uno donde el algoritmo deba retroceder varias veces.

Para cada laberinto registra:

- grilla usada,
- coordenadas de inicio y destino,
- longitud del camino o ausencia de camino,
- evidencia de retroceso,
- interpretación.

#### Bloque 7 - Simulación bancaria y experimentación con colas

Revisa:

- `Semana4/include/Queue.h`
- `Semana4/include/BankSimulation.h`
- `Semana4/demos/demo_bank.cpp`
- `Semana4/pruebas_publicas/test_public_week4.cpp`
- `Semana4/pruebas_internas/test_internal_week4.cpp`

Responde:

1. ¿Qué representa cada `Queue<Customer>` dentro del vector `windows`?

Es la cola de gente que espera en una ventanilla determinada. El primero de la fila es el que está siendo atendido ahora,
los demás aguardan detrás por orden de llegada. Es la fila del banco, literal.

2. ¿Qué criterio usa `bestWindow` y qué decisión toma cuando hay empate?

Mira cuántos están en cada fila y escoge la más corta. Si dos filas tienen el mismo número de personas, selecciona la de
número más bajo (ventanilla 0 antes que ventanilla 1, por ejemplo). Lo que hace cualquiera cuando entra al banco es
buscar la fila más corta.

3. ¿Qué significa que la simulación use una semilla (`seed`)?

Fija la semilla del "azar" para poder reproducirlo. Siempre llegan los mismos clientes en los mismos momentos con la
misma semilla. Es como barajar cartas con un método determinado: si utilizas el mismo método, las cartas siempre quedan
en el mismo orden.

4. ¿Qué relación debe cumplirse entre `totalArrivals` y `totalServed`, y por qué?

totalArrivals siempre es mayor o igual que totalServed. No puedes atender a quien no ha venido. Si la simulación termina
con gente en cola, esas personas llegaron pero no pudieron ser atendidas.

5. ¿Qué representa la línea de tiempo (`timeline`) en el resultado?

Es una foto del banco, en cada instante. En cada foto puede verse el tiempo que le resta a cada cliente en cada
ventanilla. Con todas las fotos juntas en orden tienes la película completa de la evolución del banco.

6. ¿Por qué esta aplicación necesita colas y no pilas?

Si tienes una pila, vas a atender al último que llegó, dejando esperando a los primeros indefinidamente. Eso no lo acepta 
nadie. La única política justa es que el que llegó primero sea el primero en salir y eso lo garantiza la cola.

7. ¿Qué simplificación del mundo real introduce este simulador?

Suponiendo que cada instante llega como mucho un cliente, que todos los trámites duran entre 1 y 98 unidades de tiempo 
con igual probabilidad, y que no existen clientes prioritarios ni ventanillas especializadas. En la realidad puede llegar 
un grupo a la vez, algunos trámites tardan mucho más que otros, y existen cajas rápidas.

8. ¿Qué cambiaría si la política ya no fuera "cola más corta" sino otra?

Con “cola más corta” las filas tienden a autoequilibrarse. Con una política aleatoria, algunas ventanillas estarían 
llenas y otras vacías. La cola más corta no es perfecta (no importa cuánto falte al cliente del frente), pero es simple y 
razonablemente buena.

##### Experimento 6

Ejecuta la simulación variando al menos tres parámetros:

- número de ventanillas,
- duración total,
- semilla.

Construye una tabla con:

- `nWin`
- `servTime`
- `seed`
- `totalArrivals`
- `totalServed`
- tamaño final de cada cola
- observación

Luego responde:

1. ¿Qué parámetro parece influir más en la congestión observable?
2. ¿Qué cambia cuando repites exactamente la misma semilla?
3. ¿Qué cambia cuando mantienes `nWin` y `servTime`, pero alteras la semilla?
4. ¿Qué evidencia usarías para defender que la cola más corta es una política razonable, aunque no necesariamente óptima?

#### Bloque 8 - Cierre comparativo y preparación de sustentación

Responde esta pregunta final:

**¿Qué cambia cuando pasamos de "usar pilas y colas como ADTs básicos" a "usarlas como mecanismos de control para resolver problemas"?**

Si los emplea como contenedores elementales solamente conserva y extrae datos. Cuando los empleas como mecanismos de control, la estructura decide qué hace el algoritmo a partir de ese momento.

- Con respecto a LIFO y FIFO: ya no son únicamente una propiedad de acceso, sino que se transforman en la lógica del problema. LIFO significa “lo más reciente primero, resuelve antes de retomar lo anterior”, que es exactamente lo que se necesita para la conversión de base, paréntesis y backtracking. FIFO significa “atiende en orden de llegada”, que es justo lo que necesita el banco.

- Recursión implícita vs estructura explícita: la recursión utiliza el call stack del sistema sin que tú lo veas. Al emplear una pila explícita, este proceso es visible y se puede controlar. El resultado es el mismo, lo que cambia es quién controla la memoria, y si puedes mirarla.

- En cuanto a la evaluación de expresiones, las dos pilas no sólo guardan operadores y operandos, sino que toman la decisión de cuándo aplicar cada operación en función de la precedencia. Sin ellas no podemos saber que en 3+4*2 el * debe ejecutarse antes que el +.

- Sobre backtracking: la pila no guarda datos cualesquiera, sino la trayectoria realizada hasta ahora. Hacer push es ir para adelante; hacer pop es ir para atrás. Si la pila no mantiene bien ese historial, el algoritmo no puede deshacer decisiones y la búsqueda falla.

- Sobre simulación: la cola no es un detalle de implementación, es la política de negocio. Si la cambiamos por una pila o una lista en modo aleatorio, el comportamiento observable del sistema cambiaría por completo.

- Sobre la correcta ejecución experimental: el hecho de pasar las pruebas asegura que los casos concretos funcionan, pero no asegura que el algoritmo sea correcto para cualquier posible entrada. Los experimentos aportan una evidencia más, pero no una garantía completa.

De los cinco problemas, el de conversión de base y paréntesis tienen una respuesta única y determinística, la pila solo ordena o verifica. La evaluación de expresiones usa dos pilas para resolver la precedencia. N-Reinas y laberinto son búsquedas en las que la pila es el espacio explorado. El banco es de simulación: no hay una respuesta correcta, sino un comportamiento que se pretende fiel a la realidad. En todos los casos la estructura escogida no es un detalle: es la expresión directa de la lógica del problema.

