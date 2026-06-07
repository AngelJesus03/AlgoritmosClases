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

- Semana principal:
- Estructura usada:
- Estructura de la librería `cc232` relacionada:

#### Resumen de la solución

Explica la idea central de la solución sin copiar el enunciado del juez.  
Debe quedar claro qué problema se resuelve, qué estrategia se usa y por qué la estructura elegida es adecuada.

#### Invariante principal

Describe qué propiedad se mantiene después de cada operación importante.

Ejemplos:

- balance entre dos heaps;
- propiedad de BST;
- propiedad heap;
- tamaño de subárbol actualizado;
- suma acumulada correcta;
- intervalos disjuntos;
- orden estadístico correcto;
- eliminación diferida sin elementos obsoletos visibles.

#### Complejidad

- Tiempo por operación:
- Tiempo total:
- Espacio:
#### Archivos relevantes

Indica qué contiene cada carpeta o archivo importante.

- `include/`
- `src/`
- `tests/`
- `demos/`
- `docs/respuestas_obligatorias.md`
- `docs/bitacora.md`
- `resultados/`

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

#### Preguntas obligatorias

El estudiante debe responder lo que se pide en las preguntas obligatorias.  
No basta con describir el código de forma libre.

Debe responder explícitamente:

- las preguntas comunes;
- las preguntas específicas de su problema;
- la relación con Semanas 4-6;
- el invariante;
- la complejidad;
- los casos borde;
- la modificación grabada.

Si el estudiante omite estas preguntas y solo describe código, la evidencia se considera incompleta.

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

#### Respuestas obligatorias

Debe existir el archivo:

```text
docs/respuestas_obligatorias.md
```

Este archivo debe contener respuestas claras y numeradas a las preguntas comunes y específicas del problema asignado.

#### Declaración de autoría

Declaro que entiendo el código entregado, que puedo explicarlo, compilarlo, ejecutarlo y modificarlo sin ayuda externa durante la grabación.  
También declaro que el repositorio entregado corresponde al trabajo mostrado en el video y que no contiene builds, ejecutables ni archivos generados usados para aparentar funcionamiento.