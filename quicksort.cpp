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
int arr0[5000];
int arr1[6000];
int arr2[7000];
int arr3[8000];
int arr4[9000];

void prepareArrays(int arr[], int n, bool desc) {

    for (int i = 0; i < n; i++) {
        if (desc) {
            arr[i] = n - i;
        } else {
            arr[i] = i + 1;
        }
    }

    if (!desc) {
        shuffle(arr, arr + n, default_random_engine(0));
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
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
    clock_t ini, fin;
    // pruebas
    double tiemposLog[5];

    prepareArrays(arr0, ARR_SIZE(arr0), true);
    ini = clock();
    quickSort(arr0, 0, ARR_SIZE(arr0) - 1, 1);
    fin = clock();
    tiemposLog[0] = (fin - ini);// / static_cast<double>(CLOCKS_PER_SEC);
    cout << "Pivote aleatorio | array descendente:" << endl;
    cout << "t0: ";
    cout << setprecision(2) << fixed << tiemposLog[0] << "ms" << endl;

    prepareArrays(arr1, ARR_SIZE(arr1), true);
    ini = clock();
    quickSort(arr1, 0, ARR_SIZE(arr1) - 1, 1);
    fin = clock();
    tiemposLog[1] = (fin - ini);// / static_cast<double>(CLOCKS_PER_SEC);
    cout << "t1: ";
    cout << setprecision(2) << fixed << tiemposLog[1] << "ms" << endl;

    prepareArrays(arr2, ARR_SIZE(arr2), true);
    ini = clock();
    quickSort(arr2, 0, ARR_SIZE(arr2) - 1, 1);
    fin = clock();
    tiemposLog[2] = (fin - ini);// / static_cast<double>(CLOCKS_PER_SEC);
    cout << "t2: ";
    cout << setprecision(2) << fixed << tiemposLog[2] << "ms" << endl;

    prepareArrays(arr3, ARR_SIZE(arr3), true);
    ini = clock();
    quickSort(arr3, 0, ARR_SIZE(arr3) - 1, 1);
    fin = clock();
    tiemposLog[3] = (fin - ini);// / static_cast<double>(CLOCKS_PER_SEC);
    cout << "t2: ";
    cout << setprecision(2) << fixed << tiemposLog[3] << "ms" << endl;

    prepareArrays(arr4, ARR_SIZE(arr4), true);
    ini = clock();
    quickSort(arr4, 0, ARR_SIZE(arr4) - 1, 1);
    fin = clock();
    tiemposLog[4] = (fin - ini);// / static_cast<double>(CLOCKS_PER_SEC);
    cout << "t2: ";
    cout << setprecision(2) << fixed << tiemposLog[4] << "ms" << endl;

    double tasa0 = (tiemposLog[1] - tiemposLog[0]) / (tiemposLog[0] == 0 ? 1 : tiemposLog[0]);
    double tasa1 = (tiemposLog[2] - tiemposLog[1]) / (tiemposLog[1] == 0 ? 1 : tiemposLog[1]);
    double tasa2 = (tiemposLog[3] - tiemposLog[2]) / (tiemposLog[2] == 0 ? 1 : tiemposLog[2]);
    double tasa3 = (tiemposLog[4] - tiemposLog[3]) / (tiemposLog[3] == 0 ? 1 : tiemposLog[3]);

    cout << "tasa0: ";
    cout << setprecision(2) << fixed << tasa0 << endl;
    cout << "tasa1: ";
    cout << setprecision(2) << fixed << tasa1 << endl;
    cout << "tasa2: ";
    cout << setprecision(2) << fixed << tasa2 << endl;
    cout << "tasa3: ";
    cout << setprecision(2) << fixed << tasa3 << endl;
    return 0;
}

/*
    *RESULTADOS
    Fijo | Aleatorio:
        Pivote fijo tiempo logaritmico:
        t0: 1.00ms
        t1: 1.00ms
        t2: 2.00ms
        t2: 2.00ms
        t2: 3.00ms
        tasa0: 0.00
        tasa1: 1.00
        tasa2: 0.00
        tasa3: 0.50
    Fijo | Descendente:
        Pivote fijo tiempo cuadratico:
        t0: 74.00ms  
        t1: 109.00ms
        t2: 146.00ms
        t2: 189.00ms
        t2: 243.00ms
        tasa0: 0.47 
        tasa1: 0.34
        tasa2: 0.29
        tasa3: 0.29
    Aleatorio | Aleatorio:
        Pivote aleatorio | array aleatorio:
        t0: 1.00ms
        t1: 1.00ms
        t2: 2.00ms
        t2: 2.00ms
        t2: 3.00ms
        tasa0: 0.00
        tasa1: 1.00
        tasa2: 0.00
        tasa3: 0.50
    Aleatorio | Descendiente:
        Pivote aleatorio | array descendente:
        t0: 1.00ms
        t1: 2.00ms
        t2: 2.00ms
        t2: 2.00ms
        t2: 3.00ms
        tasa0: 1.00
        tasa1: 0.00
        tasa2: 0.00
        tasa3: 0.50
*/