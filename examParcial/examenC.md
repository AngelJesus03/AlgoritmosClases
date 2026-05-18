Alumno: Angel Jesus Navarro Ruiz 20231506A
Versión C examen Parcial

## Pregunta 1:
a) 

El ADT es la definición de qué podemos hacer tal como agregar elementos (add), acceder por índice (get), eliminar duplicados (uniqueStable) sin decir nada de código.

La representación es la elección de estructura interna que elegiremos. Las opciones serían ArrayStack, RootishArrayStack y SLList.

La implementación sería el código completo y concreto para cada función. 

b) 

1)add

1.1) ArrayStack: O(1) con costo amortizado si se expande y llama a resize().

1.2)  RootishArrayStack: O(1) con costo amortizado

1.3) SLList: O(1) Con punteros

2)get

2.1) ArrayStack: O(1) acceso directo

2.2) RootishArrayStack: O(1) fórmula i2b

2.3) SLList: O(n) recorre desde la cabeza


3)contains

3.1) ArrayStack: O(n) practicamente hace una busqueda lineal

3.2) RootishArrayStack: O(n) busqueda lineal

3.3) SLList: O(n) busqueda lineal

4)removeOne

4.1) ArrayStack: O(n) busqueda

4.2) RootishArrayStack: O(n) busqueda

4.3) SLList: O(n) busqueda


c) 

El trade off para que RootishArrayStack desperdicie menos espacio a comparación de ArrayStack (O (n * 1/2) vs O(n)) es que introduce un template ArrayStack<T*> auxiliar para guardar los punteros a cada bloque y cada acceso requiere calcular en qué bloque vive el índice i mediante la fórmula i2b. En resumen es mejor en espacio, marginalmente más lento en acceso.

d) 

La operación más incómoda es get (y en general cualquier acceso por índice incluyendo removeOne y uniqueStable) debido a que SLList es una lista simplemente enlazada, para llegar al nodo i debe recorrer desde el inicio nodo a nodo.

e) 

void uniqueStable(){

    for (int i=0;i<size();i++)
        for(int j=i+1;j<size(); )
            if (get(j) == get(i)) removeOne(get(j));
            else j++;
}

La monotonicidad está garantizada porque i siempre crece en el externo, y en el interno en cada paso o j crece o size() decrece, así que siempre termina. La complejidad es O(n*2) porque el doble bucle

## Pregunta 2:

a)

sumRec(A, 4)

    sumRec(A, 3) 
        sumRec(A, 2) 
            sumRec(A, 1) 
                sumRec(A, 0) = 0 
            retorna 0 + A[0] = 0 + 2 = 2 
        retorna 2 + A[1] = 2 + 4 = 6 
    retorna 6 + A[2] = 6 + 6 = 12 
retorna 12 + A[3] = 12 + 8 = 20

b) 

Por inducción sobre n: el caso base n=0 retorna 0, que es la suma vacía y es correcto. Para el paso inductivo, asumimos que sumRec(A, n-1) retorna correctamente A[0] + ... + A[n-2] entonces sumRec(A, n) retorna sumRec(A, n-1) + A[n-1], que por hipótesis inductiva es A[0] + ... + A[n-2] + A[n-1], es decir la suma completa. Por lo tanto, por inducción, sumRec es correcta para todo n ≥ 0.

c) 
- Tiempo: Se hacen n+1 llamadas entonces tenemos O(n)
- Espacio memoria del arreglo: O(1) la función solo recibe un puntero al arreglo
- Espacio pila de llamada: O(n) ya que se apilan frames simultaneamente uno por cada llamada recursiva. 

d) 

Versión iterativa:

int sumaIterativa(const int A[], int n) {

    int suma = 0;
    for (int i = 0; i < n; i++) {
        suma = A[i] + suma;
    }
    return suma;
}

Invariante: en la iteración i, la variable suma contiene la suma de los primeros i elementos.

e) 

Pasar const le dice que esta función no modificará el arreglo, esto es importante porque nos asegura que ele arreglo no será alterado. Para correctitud es útil porque una función que solo lee datos es más fácil de razonar ya que no hay efectos secundarios sobre el arreglo.

f) 

Caso1: n=0 

Caso2: n=1

Caso3: n<0

Caso4: arreglo con un solo elemento

Caso5: Arreglo con elementos 0 [0,0,0,0,0]

Se debería probar con test o pruebas públicas para ver si pasan aquellos casos  borde demostrando así ser una solución robusta.

## Pregunta 3:

a) 

Bloque1: 0

Bloque2: 1 2

Bloque3: 3 4 5

Bloque4: 6 7 8 9

Bloque5: 10 11 12 13 14

b) 

i=0 es bloque 0 con 0 desplazamientos

i=1 es bloque 1 con 0 desplazamientos

i=2 es bloque 1 con 1 desplazamientos

i=5 es bloque 2 con 2 desplazamientos

i=9 es bloque 3 con 3 desplazamientos

i=14 es bloque 4 con 4 desplazamientos

c) 

Necesitamos aquella función porque no hay forma directa de saber en qué bloque está el índice i sin calcularlo ya que cada bloque tiene tamaños distintos y no sabriamos a qué bloque apuntar.

d) 

Cuando hay n elementos, el último bloque puede tener hasta r celdas vacías, así como r(r+1)/2=n , al despejar r tenemos (2n)*1/2 entonces el desperdicio a lo más es O(n *1/2)

e) 

Conservar el costo de get ya que sigue siendo O(1), en ArrayStack es acceso directo mientras que en RootishArrayStack hay que calcular el bloque con i2b y luego el desplazamiento, su complejidad sigue siendo O(1) pero con una constante mayor.

f) 

En RootishArrayStack cuando se llena, grow() solo crea un nuevo bloque vacío y agrega su puntero mas no copia nada. Eso es O(1) directo, sin necesidad de amortizar.
Cuando los elementos ocupan menos de (r-2)(r-1)/2, shrink() elimina el último bloque liberando su memoria. También O(1) por bloque eliminado.

## Pregunta 4:

a) 

La regla es simple:
Si i < front.size() entonces está en front y su posición se calcula: front.size() - 1 - i
Si i >= front.size() entonces está en back, en la posición i - front.size() 

Sabiendo eso calculamos:

i=0 está en la posición 2 (front) y su valor es 10

i=2 está en la posición 0 (front) y su valor es 30

i=3 está en la posición 0 (back) y su valor es 40

i=6 está en la posición 3 (back) y su valor es 70

b) 

add(1, 15) índice lógico 1 cae en front (1 < 3), posición física 3-1 = 1 dentro de front, se inserta ahí.

add(6, 55) front.size()=4. Índice lógico 6 cae en back (6 >= 4), posición física 6-4 = 2 dentro de back, se inserta ahí.

secuencia lógica: [10, 15, 20, 30, 40, 50, 55, 60, 70]

c) 

Guardándolo al revés, el elemento lógico 0 queda al final de front, donde ArrayStack opera en O(1). Si front guardara en orden normal, el elemento lógico 0 estaría al inicio del arreglo, y cualquier inserción o eliminación al inicio requeriría desplazar todos los elementos.

d) 

Una condición razonable es que ninguno de los dos arreglos tenga más de 2/3 del total de elementos.
Se dice que se viola cuando front queda vacío o tiene casi todos los elementos y balance() redistribuye tomando todos los elementos en orden lógico y reparte la primera mitad (front) de forma inversa y la segunda mitad (back) normal.

e) 

La clave del rebalanceo es que no ocurre en cada operación sino cuando la distribución se desbalancea mucho teniendo una complejidad O(n) pero al promediar muchas operaciones el costo amortizado por operación es O(1).

## Pregunta 5:

a) 

Una DLList cada elemento tiene su propio nodo con 2 punteros, así que para n elementos hay 2n punteros sin embargo SEList agrupa elementos por bloques donde cada bloque es un pequeño arrayDeque, la lista enlazada conecta bloques entre sí y dentro de cada bloque los elementos viven de forma contigua.

b) 

La invariante es que cada bloque debe tener entre b-1 y b+1 elementos, salvo quizás el primero y el último. Esto evita que haya bloques casi vacíos (desperdicio de espacio) o bloques desbordados.

c) 

Si el bloque está lleno, el algoritmo busca hacia adelante un bloque con espacio, allí pueden pasar tres casos:

Caso 1: Encuentra un bloque con espacio antes de b pasos. Hace el burbujeo empujando elementos de bloque en bloque hasta liberar hueco en el destino, y ahí inserta.

Caso 2: Recorre b bloques y todos están llenos. Llama a spread, que crea un bloque nuevo y redistribuye los elementos para dejar espacio.

Caso 3: Llega al final de la lista sin encontrar espacio. Crea un bloque nuevo al final y listo.

d) 

ArrayDeque guarda todos sus elementos en un único arreglo grande y al momento de insertar cerca del centro se tiene que desplazar fisicamente la mitad de elementos para hacerle lugar al nuevo sin embargo SEList solo se desplaza dentro de un bloque pequeño de tamaño b, comparando complejidades O(n) vs O(n*1/2) vemos que SEList es mucho mejor.

e) 

Aunque internamente la SEList usa bloques y una lista enlazada, hacia afuera ofrece exactamente las mismas operaciones que una lista normal pero internamente los elementos no están en un único arreglo sino repartidos en bloques. Por ejemplo: cuando pides el elemento 7, la estructura no sabe directamente dónde está ese elemento y lo que hace getLocation es recorrer los bloques sumando sus tamaños, el primer bloque tiene 3 elementos, el segundo tiene 3, el tercero tiene 3 entonces el elemento 7 está en el tercer bloque. Esa traducción ocurre de forma invisible cada vez que llamamos a get, set, add o remove.

f) 

La idea es mantener un vector en paralelo como referencia correcta. Se hacen muchas inserciones y eliminaciones aleatorias en ambas estructuras a la vez, y después de cada operación se verifica que el tamaño de la SEList coincida con el del vector. Al final se comparan todos los elementos en orden. Si en algún momento los tamaños difieren o algún elemento no coincide, hay un bug. Conviene probar con distintos valores de b porque con b=2 los bloques son muy pequeños y se ejercitan más seguido las operaciones de spread y gather, donde suelen esconderse los errores.

## Pregunta 6:

a)
1) Agregar elementos al frente repetidamente.
2) Llenar el arreglo hasta su capacidad exacta, eliminar un elemento del frente (lo que mueve j) y luego eliminar uno del fondo, verificando que el tamaño y el contenido sean correctos.

b) 

Para tamaño 1: insertar 42, llamar remove(0), verificar que size()==0. 

Para tamaño 2: insertar [10, 20], llamar remove(0), verificar que queda [20]; repetir con remove(1) y verificar que queda [10].

c) 

Pasar pruebas públicas solo garantiza correctitud en los casos que alguien pensó en escribir y al no abarcar todos los casos no puede comprobar correctitud total.

d) 

Invariante: verificar que n decrementó en 1, que todos los elementos restantes son accesibles via (j+i) % a.length con sus valores correctos, y que si 3*n < a.length se hizo resize.

e) 

ASan detecta accesos fuera de los límites del arreglo, como si el módulo falla y accede a  a[-1] o a[a.length]. Lo que no detecta son errores lógicos donde el índice es válido pero incorrecto: si por un bug en el módulo se lee a[2] en vez de a[5], ambas posiciones existen y ASan no ve nada malo, aunque el valor devuelto sea incorrecto.

## Pregunta 7:

a)
- apply(x): no hay precondición, size aumenta en 1
- undo(): el tamaño debe ser positivo y size disminuye en 1
- current(): el tamaño debe ser positivo retornando el estado actual sin modificar nada
- size(): no hay precondiciones y retorna el tamaño
- clear(): el tamaño queda en 0


b)
- Con arreglo dinámico, se guarda un arreglo de estados y un entero top que apunta al último. El invariante es que los estados válidos están en [0, top] y top == n-1. Donde apply es add(n, x), undo es remove(n-1) y current es get(n-1).

- Con lista enlazada, se guarda una lista donde la cabeza es el estado actual y cada nodo apunta al anterior. El invariante es que el primer nodo es siempre el estado más reciente y n refleja la cantidad de nodos en donde apply es push(x), undo es remove() como un pop() y current es peek().


c)

1)apply:

1.1) Arreglo dinámico: O(1) amortizado

1.2) Lista enlazada: O(1)

2)undo:

2.1) Arreglo dinámico: O(1)

2.2) Lista enlazada: O(1)

3)current:

3.1) Arreglo dinámico: O(1)

3.2) Lista enlazada: O(1)

4)clear:

4.1) Arreglo dinámico: O(1) liberando

4.2) Lista enlazada: O(n)

d) 

Cuando size()==0 no hay estado previo y llamar undo() viola la precondición. La forma más limpia es lanzar una excepción o retornar un booleano false. Lo que no debe hacerse es decrementar top o eliminar un nodo sin verificar primero, porque eso deja la estructura en un estado inconsistente.

e) 
1) 1000 apply y 1000 undo para verificar size()==0
2) 5 apply de igual valor para verificar size()==5 y que 5 undo sucesivos funcionen aunque los valores sean iguales.
3) llamar undo y current sobre una estructura vacía y verificar que lance una excepción sin romper nada.

f) 

Con get(i) la lista enlazada queda descartada porque llegar al iésimo nodo cuesta O(n). El arreglo dinámico es la elección natural ya que get(i) es simplemente a[i], O(1) directo. La única consideración extra es que clear() debe resetear bien el arreglo para no exponer estados antiguos por índice accidentalmente.


