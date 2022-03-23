#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>
#include <limits>
#include <ctime>
#include <chrono>

using namespace std;

#define ARR_SIZE(n) sizeof(n) / sizeof(*n)
// arreglos de prueba, con aumentos proporcionales de 5
int loga0[1000];
int loga1[2000];
int loga2[3000];

int cuad0[1000];
int cuad1[1000];
int cuad2[1000];

void prepareArrays() {
    for (int i = 0; i < 1000; i++) {
        loga0[i] = i+1;
    }
    for (int i = 0; i < 2000; i++) {
        loga1[i] = i+1;
    }
    for (int i = 0; i < 3000; i++) {
        loga2[i] = i+1;
    }

    for (int i = 0; i < 1000; i++) {
        cuad0[i] = 1000-i;
    }
    for (int i = 0; i < 2000; i++) {
        cuad1[i] = 2000-i;
    }
    for (int i = 0; i < 3000; i++) {
        cuad2[i] = 3000-i;
    }

    shuffle(loga0, loga0 + 1000, default_random_engine(0));
    shuffle(loga1, loga1 + 2000, default_random_engine(0));
    shuffle(loga2, loga2 + 3000, default_random_engine(0));

    cout << "done!" << endl;

}

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
    if (imin >= imax) {
        cout << "";
        return;
    } // condicion de parada
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

    prepareArrays();
    using std::chrono::high_resolution_clock;
    using std::chrono::duration_cast;
    using std::chrono::duration;
    using std::chrono::milliseconds;
    using std::chrono::nanoseconds;
    // primera prueba: quicksort de pivote fijo en tiempo logarítmico
    auto t1 = high_resolution_clock::now();
    quickSort(loga0,0,999,0);
    auto t2 = high_resolution_clock::now();

    //ns
    auto ns_int = duration_cast<milliseconds>(t2-t1);
    duration<double, std::milli> ns_double = t2 - t1;

    std::cout << setprecision(10) << ns_int.count() << "ns\n";
    std::cout << setprecision(10) << ns_double.count() << "ns\n";
    return 0;
}