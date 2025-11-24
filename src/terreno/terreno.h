#pragma once
#include <math.h>

class Terreno {
private:
int tamanho;
int** MedidasTerreno; // dá pra fazer diferente?

public:
Terreno(int area) {
    tamanho = pow(2, area) + 1;
    gerarTerreno(area);
}

~Terreno() { // não deleta 100% das coisas
    delete[] MedidasTerreno;
}

void gerarTerreno(int area);
int obterLargura();
int obterProfundidade();
int ruido(int antiDeslocamento, int deslocamento);
bool deslocPontoMedio(int arr[], int tamanho);
};