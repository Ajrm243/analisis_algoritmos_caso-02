# analisis_algoritmos_caso-02

## Caso 2 del curo de Análisis de Algoritmos I Semestre 2022 ITCR

### Parte 0: makefile specs
El archivo makefile tiene las siguientes instrucciones:
```make
quicksort:
	g++ -O0 quicksort.cpp -o quick
	.\quick.exe
selection:
	g++ -O0 selection.cpp -o select
	.\select.exe
search:
	g++ kmpsearch.cpp -o search
	.\search.exe
```
El compilador usado es g++ para Windows: Mingw-32. Para ejecutar cada prueba se tiene que escribir en la consola `make {opcion}` donde `{opcion}` es  'quicksort', 'selection' o 'search'.

### Parte I: Quicksort logarítmico, cuadrático y pivote fijo vs. pivote aleatorio
En la implementación del quicksort se hicieron las siguientes pruebas:

 - Pivote fijo con generación aleatoria de arreglos (caso promedio)
 - Pivote fijo con generación descendente de arreglos (peor caso)
 - Pivote aleatorio con generación descendente de arreglos
 - Pivote aleatorio con generación descendente de arreglos

 Todas las operaciones se hicieron con colecciónes que van desde los 5 hasta los 9 mil elementos. Para medir las tasas de crecimiento se implementó la fórmula **(n1 - n0) / n0** y en los casos donde el n0 vale 0 se trunca a 1.
 Ejemplo de resultados del primer caso:
 ```cpp
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
/*Aleatorio | Aleatorio*/
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
/*Aleatorio | Descendiente*/
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