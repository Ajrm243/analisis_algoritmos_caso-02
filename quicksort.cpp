#include <iostream>
#include <string>
#include <time.h>

using namespace std;

#define ARR_SIZE(n) sizeof(n) / sizeof(*n)

int particionar(int arr[], int imin, int imax) {
    srand(time(NULL));
    int random = imin + rand() % (imax - imin); // para que el tiempo del random no influya en el conteo
    int pivot = imin;
    /*INTERCAMBIAR LOS ELEMENTOS DE ACUERDO CON SU VALOR VS PIVOTE*/
    int i = imin;   // i es el índice de inicio que retorna para luego "dividir" la colección en mitades
    int j = i+1;    // indice de fin
    // loop hace comparaciones hasta que salga del ciclo
    while (j <= imax) {
        if (arr[j] < arr[pivot]) {  // si el siguiente elemento es menor al pivote (inicia como el anterior)
            i++;    // aumente el indice de retorno
            swap(arr[i], arr[j]);
        }
        j++;    // aumente el indice final
    }
    swap(arr[i], arr[pivot]);   // pivote ordenado en su posicion final
    /*INTERCAMBIAR LOS ELEMENTOS DE ACUERDO CON SU VALOR VS PIVOTE*/
    return i;   // devuelve el índice de la partición
}

int particionarRandom(int arr[], int imin, int imax) {
    srand(time(NULL));
    int random = imin + rand() % (imax - imin);
    swap(arr[random], arr[imin]);
    return particionar(arr, imin, imax);
}

void quickSort(int arr[], int imin, int imax, int pivotType) {
    int k;
    if (imin >= imax) { return; } // condicion de parada
    switch (pivotType) {
    case 0:
        k = particionar(arr, imin, imax);
        break;
    case 1:
        k = particionarRandom(arr, imin, imax);
        break;
    default:
        k = particionar(arr, imin, imax);
        break;
    }
    
    quickSort(arr, imin, k-1, pivotType); // mitad izquierda
    quickSort(arr, k+1, imax, pivotType); // mitad derecha
}




int main () {
    
    return 0;
}