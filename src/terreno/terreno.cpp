#include "terreno.h"
#include "imagem/imagem.h" // problem
#include <math.h>
#include <iostream>
#include <random>
using namespace std;

int& Terreno::operator()(int x, int y) { // Sobrecarga de operadores
    return MedidasTerreno[x][y];
}

void Terreno::gerarTerreno() {;
    MedidasTerreno = new int*[tamanho];
    for (int i = 0; i < tamanho; i++){
        MedidasTerreno[i] = new int[tamanho];
        for (int j = 0; j < tamanho; j++) {
            MedidasTerreno[i][j] = 0;
        }
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

Imagem Terreno::paisagem(Paleta& cores) {
    Imagem img(tamanho, tamanho);

    int menorAltura = MedidasTerreno[0][0];
    int maiorAltura = MedidasTerreno[0][0];

    for (int x = 0; x < tamanho; x++) {
        for (int y = 0; y < tamanho; y++) {
            int val = MedidasTerreno[x][y];
            if (val > maiorAltura) {
                maiorAltura = val;
            } else if (val < menorAltura) {
                menorAltura = val;
            }
        }
    }

    if (maiorAltura == menorAltura) {
        maiorAltura++;
    }

    for (int x = 0; x < tamanho; x++) {
        for (int y = 0; y < tamanho; y++) {
            float posicao = (float)(MedidasTerreno[x][y] - menorAltura) / (maiorAltura - menorAltura);
            int indice = posicao * (cores.obterTamanho() - 1);

            auto cor = cores.obterCor(indice);

            if (x > 0 && y > 0) {
                if (MedidasTerreno[x][y] < MedidasTerreno[x-1][y-1]) {
                    cor.r = (int)(cor.r * 0.6);
                    cor.g = (int)(cor.g * 0.6);
                    cor.b = (int)(cor.b * 0.6);
                }
            }

            (img)(x, y).r = cor.r;
            (img)(x, y).g = cor.g;
            (img)(x, y).b = cor.b;
        }
    }

    return img;
}