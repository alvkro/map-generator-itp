#include "terreno.h"
#include <math.h>
#include <random>
using namespace std;

// Deslocamento do Ponto Médio:

int Terreno::randomizador(int antiDeslocamento, int deslocamento) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(antiDeslocamento, deslocamento);
    return dist(gen);
}

// Versão inicial (tirar esse comentário quando terminar)
// REALIZAR TRATAMENTO DE ERROS PARA MATRIZES DE DIMENSÕES PARES!!
void Terreno::diamondSquare(int** terreno, int size, int ruido) {
    // Os quatro cantos:
    terreno[0][0] = randomizador(-ruido, ruido);
    terreno[0][tamanho - 1] = randomizador(-ruido, ruido);
    terreno[tamanho - 1][0] = randomizador(-ruido, ruido);
    terreno[tamanho - 1][tamanho - 1] = randomizador(-ruido, ruido);

    // Algoritmo:
    int step = tamanho - 1;
    // Calculo pra achar o meio: indexMid = (size - 1)/2;

    while (step > 1) {
        int midX = 0;
        int midY = 0;

        // Square-step:
        for (int x = 0; x < size - 1; x += step) {  
            for (int y = 0; y < size - 1; y += step) {
                int avg = (terreno[x][y] + terreno[x][y + step] +  
                    terreno[x + step][y] + terreno[x + step][y + step])/4;
                
                    int midX = x + step/2;
                    int midY = y + step/2;

                    terreno[midX][midY] = avg;
            }
        }
        // Diamond-step
        for (int x = 0; x < step - 1; x+= step) {
            for (int y = 0; y < size - 1; y += step) {
                int avg = (terreno[x][y] + terreno[x][y + step] + terreno[midX][midY])/3;
            }
        }
        step /= 2;
    }
}