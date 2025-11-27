#include "terreno.h"
#include <math.h>
#include <random>
using namespace std;

Terreno Terreno::operator()(int x, int y) { // Sobrecarga de operadores
    return MedidasTerreno[y][x];
}

void Terreno::gerarTerreno() {;
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

int Terreno::quantidadeLinhas(int area) {
    return sqrt(area);
}

int Terreno::quantidadeColunas(int area) {
    return sqrt(area);
}

int Terreno::returnAltitude(int** terreno, int x, int y) {
    return terreno[x][y]; // valor correspondente ao terreno
}