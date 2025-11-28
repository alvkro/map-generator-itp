#include "terreno.h"
#include <math.h>
#include <random>
using namespace std;

int& Terreno::operator()(int x, int y) { // Sobrecarga de operadores
    return MedidasTerreno[x][y];
}

void Terreno::gerarTerreno() {;
    MedidasTerreno = new int*[tamanho];
    for (int i = 0; i < tamanho; i++){
        MedidasTerreno[i] = new int[tamanho];
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

int Terreno::returnAltitude(int x, int y) {
    return MedidasTerreno[x][y]; // valor correspondente ao terreno
}