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

int Terreno::square_step(int size, int ruido) {
    // POR ENQUANTO ESTÁ SEM O RUÍDO, PARA FINS DE TESTE!!!!
    int step = tamanho - 1;
    for (int x = 0; x < size - 1; x += step) {  
            for (int y = 0; y < size - 1; y += step) {
                int avg = (MedidasTerreno[x][y] + MedidasTerreno[x][y + step] +  
                    MedidasTerreno[x + step][y] + MedidasTerreno[x + step][y + step])/4;
                
                    int midX = x + step/2;
                    int midY = y + step/2;

                    MedidasTerreno[midX][midY] = avg;
                    return MedidasTerreno[midX][midY];
            }
        }
}

// Versão inicial (tirar esse comentário quando terminar)
// REALIZAR TRATAMENTO DE ERROS PARA MATRIZES DE DIMENSÕES PARES!!
void Terreno::diamondSquare(int** terreno, int size, int ruido) {
    // Os quatro cantos:
    terreno[0][0] = randomizador(-ruido, ruido);
    terreno[0][tamanho - 1] = randomizador(-ruido, ruido);
    terreno[tamanho - 1][0] = randomizador(-ruido, ruido);
    terreno[tamanho - 1][tamanho - 1] = randomizador(-ruido, ruido);

    int step = tamanho - 1;

    while (step > 1) {
    square_step(size, ruido);

     // Diamond-step
    for (int x = step/2; x < size; x += step) {
        for (int y = step/2; y < size; y += step) {
            
        }
        // Diamond-step
        for (int x = step/2; x < size; x += step) {
            for (int y = step/2; y < size; y += step) {
                double corner1 = terreno[x - (step/2)][y - (step/2)];
                double corner2 = terreno[x - (step/2)][y + (step/2)];
                double corner3 = terreno[x + (step/2)][y - (step/2)];
                double corner4 = terreno[x + (step/2)][y + (step/2)];

                double mid = (corner1 + corner2 + corner3 + corner4)/4;
                double randomvalue = randomizador(-ruido, ruido);
                terreno[x][y] = mid + randomvalue;    
            }
        }
        step /= 2;
    }
}