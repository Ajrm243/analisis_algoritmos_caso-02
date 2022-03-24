#include <bits/stdc++.h>
#include <iostream>
#include <time.h>
#include <iomanip>
#include <limits>
#include <ctime>

#define ARR_SIZE(n) sizeof(n) / sizeof(*n)


using namespace std;

// arreglos de prueba, con aumentos proporcionales de mil
int arr0[5000];
int arr1[6000];
int arr2[7000];
int arr3[8000];
int arr4[9000];


void prepareArrays(int arr[], int n, bool asc, bool mix) {

    for (int i = 0; i < n; i++) {
        if (asc) {
            arr[i] = i + 1;
        } else {
            arr[i] = n - i;
        }
    }
    if (mix) {
        shuffle(arr, arr + n, default_random_engine(0));
    }
}

void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
        greater than key, to one position ahead
        of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    clock_t ini, fin;
    // pruebas
    long double tiemposLog[5];

    prepareArrays(arr0, ARR_SIZE(arr0), true, false);
    ini = clock();
    insertionSort(arr0, ARR_SIZE(arr0));
    fin = clock();
    tiemposLog[0] = (fin - ini);// / static_cast<double>(CLOCKS_PER_SEC);
    cout << "Insertion cuadratico:" << endl;
    cout << "t0: ";
    cout << setprecision(10) << fixed << tiemposLog[0] << "ms" << endl;

    prepareArrays(arr1, ARR_SIZE(arr1), true, false);
    ini = clock();
    insertionSort(arr1, ARR_SIZE(arr1));
    fin = clock();
    tiemposLog[1] = (fin - ini);// / static_cast<double>(CLOCKS_PER_SEC);
    cout << "t1: ";
    cout << setprecision(10) << fixed << tiemposLog[1] << "ms" << endl;

    prepareArrays(arr2, ARR_SIZE(arr2), true, false);
    ini = clock();
    insertionSort(arr2, ARR_SIZE(arr2));
    fin = clock();
    tiemposLog[2] = (fin - ini);// / static_cast<double>(CLOCKS_PER_SEC);
    cout << "t2: ";
    cout << setprecision(10) << fixed << tiemposLog[2] << "ms" << endl;

    prepareArrays(arr3, ARR_SIZE(arr3), true, false);
    ini = clock();
    insertionSort(arr3, ARR_SIZE(arr3));
    fin = clock();
    tiemposLog[3] = (fin - ini);// / static_cast<double>(CLOCKS_PER_SEC);
    cout << "t3: ";
    cout << setprecision(10) << fixed << tiemposLog[3] << "ms" << endl;

    prepareArrays(arr4, ARR_SIZE(arr4), true, false);
    ini = clock();
    insertionSort(arr4, ARR_SIZE(arr4));
    fin = clock();
    tiemposLog[4] = (fin - ini);// / static_cast<double>(CLOCKS_PER_SEC);
    cout << "t4: ";
    cout << setprecision(10) << fixed << tiemposLog[4] << "ms" << endl;

    double tasa0 = (tiemposLog[1] - tiemposLog[0]) / (tiemposLog[0] == 0 ? 1 : tiemposLog[0]);
    double tasa1 = (tiemposLog[2] - tiemposLog[1]) / (tiemposLog[1] == 0 ? 1 : tiemposLog[1]);
    double tasa2 = (tiemposLog[3] - tiemposLog[2]) / (tiemposLog[2] == 0 ? 1 : tiemposLog[2]);
    double tasa3 = (tiemposLog[4] - tiemposLog[3]) / (tiemposLog[3] == 0 ? 1 : tiemposLog[3]);

    cout << "tasa0: ";
    cout << setprecision(10) << fixed << tasa0 << endl;
    cout << "tasa1: ";
    cout << setprecision(10) << fixed << tasa1 << endl;
    cout << "tasa2: ";
    cout << setprecision(10) << fixed << tasa2 << endl;
    cout << "tasa3: ";
    cout << setprecision(10) << fixed << tasa3 << endl;
    return 0;
}