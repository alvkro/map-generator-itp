#pragma once
#include <math.h>

class Terreno {
private:
int tamanho, w, h;
int** MedidasTerreno; // dá pra fazer diferente? (NAO)

public:
Terreno(int area) {
    w = sqrt(area);
    h = sqrt(area);
    tamanho = pow(2, area) + 1;
    gerarTerreno(area);
}

~Terreno() {
    for (int i = 0; i < w; i++) {
        delete[] MedidasTerreno[i];
    }
    delete[] MedidasTerreno[h];
}

Terreno operator()(int x, int y);
void gerarTerreno(int area);
int obterLargura();
int obterProfundidade();
int randomizador(int antiDeslocamento, int deslocamento);
void diamondSquare(int** terreno, int size, int ruido);
int quantidadeLinhas(int area);
int quantidadeColunas(int area);
int square_step(int size, int ruido);
int returnAltitude(int** terreno, int x, int y);
};