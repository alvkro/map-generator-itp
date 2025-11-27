#pragma once
#include <math.h>

class Terreno {
private:
int tamanho, w, h;
int** MedidasTerreno; // dá pra fazer diferente? (NAO)

public:
Terreno(int area) {
    tamanho = pow(2, area) + 1;
    w = tamanho;
    h = tamanho;
    gerarTerreno();
}

~Terreno() {
    for (int i = 0; i < w; i++) {
        delete[] MedidasTerreno[i];
    }
    delete[] MedidasTerreno[h];
}

Terreno operator()(int x, int y);
void gerarTerreno();
int obterLargura();
int obterProfundidade();
double randomizador(int antiDeslocamento, int deslocamento);
void diamondSquare(int size, int ruido);
int quantidadeLinhas(int area);
int quantidadeColunas(int area);
double square_step(int size, int ruido);
int returnAltitude(int** terreno, int x, int y);
double diamond_step(int size, int ruido);
};