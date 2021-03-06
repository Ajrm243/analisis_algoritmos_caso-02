
# analisis_algoritmos_caso-02

  

## Caso 2 del curo de Análisis de Algoritmos I Semestre 2022 ITCR
## Adrian Ramirez Mattey | 2020239249
  

### Parte 0: makefile specs

El archivo makefile tiene las siguientes instrucciones:

```make
quicksort:
g++ -O0 quicksort.cpp -o quick
.\quick.exe
insertion:
g++ -O0 insertion.cpp -o insert
.\insert.exe
search:
g++ kmpsearch.cpp -o search
.\search.exe
```
El compilador usado es g++ para Windows: Mingw-32. Para ejecutar cada prueba se tiene que escribir en la consola `make {opcion}` donde `{opcion}` es 'quicksort', 'insertion' o 'search'.

### Parte I: Quicksort logarítmico, cuadrático y pivote fijo vs. pivote aleatorio
En la implementación del quicksort se hicieron las siguientes pruebas:
 
- Pivote fijo con generación aleatoria de arreglos (caso promedio)
- Pivote fijo con generación descendente de arreglos (peor caso)
- Pivote aleatorio con generación descendente de arreglos
- Pivote aleatorio con generación descendente de arreglos

Todas las operaciones se hicieron con colecciónes que van desde los 5 hasta los 9 mil elementos. Para medir las tasas de crecimiento se implementó la fórmula **(n1 - n0) / n0** y en los casos donde el n0 vale 0 se trunca a 1.

Ejemplo de resultados del primer caso:

```cpp
/*Quicksort | Pivote fijo | Aleatorio*/
t0: 1.00ms
t1: 1.00ms
t2: 2.00ms
t2: 2.00ms
t2: 3.00ms
tasa0: 0.00
tasa1: 1.00
tasa2: 0.00
tasa3: 0.50
```
De manera general, las tasas promedio tienden a hacerse más pequeñas muy rápido conforme vaya aumentando n. Lo cual confirma el ***O(logn)*** del algoritmo de Quicksort

Para el ***O(n^2)*** se utilizaron colecciones descendientes para el pivote fijo que utiliza el primer elemento de la colección. Los resultados a continuación:
```cpp
/*Quicksort | Pivote fijo | Descendiente*/
t0: 74.00ms
t1: 109.00ms
t2: 146.00ms
t2: 189.00ms
t2: 243.00ms
tasa0: 0.47
tasa1: 0.34
tasa2: 0.29
tasa3: 0.29
```
Como se puede observar llega a un punto donde la tasa de crecimiento deja de disminuir, esto es porque el quicksort con pivote fijo en el primer elemento está perdiendo tiempo al perder 1 subarray en sus operaciones.
A continuación los 2 resultados con colecciones aleatorias y descendentes pero con pivotes aleatorios:

```cpp
/*Quicksort | Pivote aleatorio | Aleatorio*/
t0: 1.00ms
t1: 1.00ms
t2: 2.00ms
t2: 2.00ms
t2: 3.00ms
tasa0: 0.00
tasa1: 1.00
tasa2: 0.00
tasa3: 0.50
```
```cpp
/*Quicksort | Pivote aleatorio | Descendiente*/
t0: 1.00ms
t1: 2.00ms
t2: 2.00ms
t2: 2.00ms
t2: 3.00ms
tasa0: 1.00
tasa1: 0.00
tasa2: 0.00
tasa3: 0.50
```
La comparación no es muy obvia en el caso de arreglos aleatorios, pero cuando las colecciones son en forma descendiente es mucho mejor el rendimiento con pivotes aleatorios ya que permite que se haga una división mejor de los sub-arrays para aprovechar el algoritmo.
### Parte II: Insertion Sort lineal y cuadrático
En la implementación del Insertion Sort se hicieron las siguientes pruebas:
- Insertion con listas aleatorias (caso promedio)
- Insertion con listas descendentes (peor caso)
- Insertion con listas ordenadas (mejor caso)

Para el insertion sort existen dos cotas en **O**: el promedio y peor caso que es cuadrático ***O(n^2)*** y el mejor caso que es lineal ***O(n)*** en las situaciones cuando el arreglo *ya* está ordenado. Se hicieron las pruebas de igual forma que con el quicksort. A continuación ejemplos de pruebas de Insertion cuadrático:
 ```cpp
/*Insertion | Lista Aleatoria | Prueba 1*/
t0: 14.00ms  
t1: 21.00ms  
t2: 29.00ms  
t3: 38.00ms  
t4: 47.00ms  
tasa0: 0.50  
tasa1: 0.38  
tasa2: 0.31  
tasa3: 0.24
/*Insertion | Lista Aleatoria | Prueba 2*/
t0: 14.00ms  
t1: 20.00ms  
t2: 33.00ms  
t3: 37.00ms  
t4: 47.00ms  
tasa0: 0.43  
tasa1: 0.65  
tasa2: 0.12  
tasa3: 0.27
```
Ambas pruebas dan resultados similares, y las pruebas consecuentes dieron en promedio los mismos tiempos de ejecución. Todas las pruebas se hicieron con incrementos de la colección de 1000 elementos. Cuando las listas son descendentes el algoritmo toma mucho más tiempo inclusive:
```cpp
/*Insertion | Lista Descendente | Prueba 1*/
t0: 28.00ms  
t1: 48.00ms  
t2: 69.00ms  
t3: 87.00ms  
t4: 93.00ms  
tasa0: 0.71  
tasa1: 0.44  
tasa2: 0.26  
tasa3: 0.07
/*Insertion | Lista Descendente | Prueba 2*/
t0: 27.00ms  
t1: 40.00ms  
t2: 59.00ms  
t3: 74.00ms  
t4: 92.00ms  
tasa0: 0.48  
tasa1: 0.47  
tasa2: 0.25  
tasa3: 0.24
```
El único caso que da resultados mejores es cuando la lista ya está ordenada, las pruebas dieron error porque en tiempo lineal la librería que se usó `ctime` no podía reportar tiempos tan cortos con las colecciones que se usaron, un ejemplo de estos:
```cpp
/*Prueba 1*/
t0: 2.0000000000ms  
t1: 0.0000000000ms  
t2: 0.0000000000ms  
t3: 0.0000000000ms  
t4: 0.0000000000ms  
tasa0: -1.0000000000  
tasa1: 0.0000000000  
tasa2: 0.0000000000  
tasa3: 0.0000000000
/*Prueba 2*/
t0: 1.0000000000ms  
t1: 0.0000000000ms  
t2: 0.0000000000ms  
t3: 0.0000000000ms  
t4: 0.0000000000ms  
tasa0: -1.0000000000  
tasa1: 0.0000000000  
tasa2: 0.0000000000  
tasa3: 0.0000000000
```
Se aumentó la precisión de los números en el momento de imprimir pero aún así no sirvió para observar los verdaderos tiempos. Pese a eso se concluye por intuición que los tiempos son lineales debido a que la lista ya está ordenada entonces solo se hacen los recorridos principales de la colección.
### Parte III: Free text search con KMP
Para la implementación de un algoritmo de búsqueda que soporte una carga de texto de 10 MB se utilizó una modificación del algoritmo KMP **(Knuth Morris Pratt)**. Este algoritmo es en el peor caso un ***O(n)*** y es importante porque si se utilizara el algoritmo ***Naive*** o "ingenuo" duraría mucho tiempo más, el caso promedio de este otro algoritmo es ***O(m(n-m+1))*** lo cuál es mucho peor que el utilizado.
