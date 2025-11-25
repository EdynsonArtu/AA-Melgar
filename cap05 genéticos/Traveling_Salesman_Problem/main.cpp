#include <iostream>
#include <vector>

#include "AlgoritmoGenetico.h"
#include "TSP.h"

using namespace std;

int main() {
    srand(time(nullptr));

    vector<vector<int>> matriz = {
        {0, 2, 9, 10, 7},
        {2, 0, 6, 4, 3},
        {9, 6, 0, 8, 9},
        {10, 4, 8, 0, 5},
        {7, 3, 9, 5, 0}
    };

    TSP tsp = TSP(matriz);
    AlgoritmoGenetico ag(1000, 0.05, matriz);
    int tamaño_poblacion = 50;
    Cromosoma mejor = ag.ejecutar(tamaño_poblacion);
    cout << "Mejor tour:"<<endl;
    mejor.imprimir();
    return 0;
}
