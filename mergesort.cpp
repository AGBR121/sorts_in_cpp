#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

vector<int> generarVectorAleatorio(int tamaño, int min, int max) {
    vector<int> vec;
    srand(time(0));  

    for (int i = 0; i < tamaño; ++i) {
        vec.push_back(min + rand() % (max - min + 1)); 
    }

    return vec;
}

void imprimirVector(vector<int>* vec) {
    for (int i =0; i<vec->size(); i++) {
        cout << (*vec)[i] << " ";
    }
    cout << endl;
}

void merge(vector<int>* vec, int inicio, int mitad, int final ){
    int tamano1 = mitad-inicio+1;
    int tamano2 = final-mitad;
    
    vector<int> left(tamano1), right(tamano2);
    
    for(int i=0; i<tamano1;i++){
        left[i] = vec->at(inicio+i);
    }
    for(int j=0; j<tamano2;j++){
        right[j] = vec->at(mitad+j+1);
    }
    int i=0, j=0, k=inicio;
    while (i < tamano1 && j < tamano2) {
        if (left[i] <= right[j]) {
            vec->at(k) = left[i];
            ++i;
        } else {
            vec->at(k) = right[j];
            ++j;
        }
        ++k;
    }
    while (i < tamano1) {
        vec->at(k) = left[i];
        ++i;
        ++k;
    }
    while (j < tamano2) {
        vec->at(k) = right[j];
        ++j;
        ++k;
    }
}

void mergeSort(vector<int>* vec, int inicio, int final){
    if(inicio<final){
    int medio = inicio + (final - inicio) / 2;
    
    mergeSort(vec, inicio, medio);

    mergeSort(vec, medio + 1, final);

    merge(vec, inicio, medio, final);
    }
}

int main()
{
    vector<int> vect = generarVectorAleatorio(10, 0, 10);

    cout << "Vector sin organizar: ";
    imprimirVector(&vect);
    auto inicio = chrono::high_resolution_clock::now();
    mergeSort(&vect,0,vect.size()-1);
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<int64_t, nano> duracion = fin - inicio;
    cout << "Vector organizado: ";
    imprimirVector(&vect);
    cout << "La función tardó " << duracion.count() << " nanosegundos." << endl;
    return 0;
}
