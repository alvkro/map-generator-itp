#pragma once
#include <math.h>
#include "imagem/imagem.h" // problem

class Terreno {
private:
int tamanho;
int** MedidasTerreno; // dá pra fazer diferente? (NAO)

public:
Terreno(int area) {
    tamanho = pow(2, area) + 1;
    gerarTerreno();
}

~Terreno() {
    for (int i = 0; i < tamanho; i++) {
        delete[] MedidasTerreno[i];
    }
    delete[] MedidasTerreno;
}

Imagem paisagem(Paleta& cores);
int& operator()(int x, int y);
void gerarTerreno();
int obterLargura();
int obterProfundidade();
int randomizador(int antiDeslocamento, int deslocamento);
void diamondSquare(int size, int ruido);
int quantidadeLinhas(int area);
int quantidadeColunas(int area);
int square_step(int step, int ruido);
int returnAltitude(int x, int y);
void diamond_step(int step, int ruido);
};