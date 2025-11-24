#include "terreno.h"
#include <math.h>
#include <random>
using namespace std;

void Terreno::gerarTerreno(int area) {
    int w = sqrt(area);
    int h = sqrt(area);

    MedidasTerreno = new int*[h];
    for (int i = 0; i < h; i++){
        MedidasTerreno[i] = new int[w];
    } 
}

int Terreno::obterLargura() {
    return tamanho;
}
int Terreno::obterProfundidade() {
    return tamanho;
}