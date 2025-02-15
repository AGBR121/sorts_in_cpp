#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <chrono>
using namespace std;

vector<int> generarVectorAleatorio(int tamano, int min, int max) {
    vector<int> vec;
    srand(time(0));  

    for (int i = 0; i < tamano; ++i) {
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


int particion(vector<int>* vec, int inicio, int final) {
    
    int pivoteIndice = inicio + rand() % (final - inicio + 1);
    int pivote = (*vec)[pivoteIndice];
    
    swap((*vec)[pivoteIndice], (*vec)[final]);

    int i = (inicio - 1);  

    for (int j = inicio; j < final; ++j) {
        if ((*vec)[j] <= pivote) {
            ++i;
            swap((*vec)[i], (*vec)[j]);
        }
    }

    swap((*vec)[i + 1], (*vec)[final]); 

    return (i + 1); 
}

void quickSort(vector<int>* vec, int inicio, int final) {
    if (inicio < final) {
        
        int pivote = particion(vec, inicio, final);

        quickSort(vec, inicio, pivote - 1);  
        quickSort(vec, pivote + 1, final);   
    }
}

int main()
{
    vector<int> vect = generarVectorAleatorio(10, 0, 10);

    cout << "Vector sin organizar: ";
    imprimirVector(&vect);
    auto inicio = chrono::high_resolution_clock::now();
    quickSort(&vect,0,vect.size()-1);
    auto fin = chrono::high_resolution_clock::now();
    chrono::duration<int64_t, nano> duracion = fin - inicio;
    cout << "Vector organizado: ";
    imprimirVector(&vect);
    cout << "La función tardó " << duracion.count() << " nanosegundos." << std::endl;
    return 0;
}
