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

int Terreno::square_step(int step, int ruido) { // size vai receber tamanho...
    for (int x = 0; x < tamanho - 1; x += step) {  
            for (int y = 0; y < tamanho - 1; y += step) {
                int avg = (MedidasTerreno[x][y] + 
                    MedidasTerreno[x][y + step] +  
                    MedidasTerreno[x + step][y] + 
                    MedidasTerreno[x + step][y + step]) / 4.0;

                    avg += randomizador(-ruido, ruido);
                
                    int midX = x + step/2;
                    int midY = y + step/2;

                    MedidasTerreno[midX][midY] = avg;
            }
        }
    return MedidasTerreno[tamanho / 2][tamanho / 2];
}

int Terreno::diamond_step(int size, int ruido) {
    int step = size / 2;
    for (int x = step / 2; x < size; x += step) {
        for (int y = step / 2; y < size; y += step) {
            int corner1 = MedidasTerreno[x - (step/2)][y - (step/2)];
            int corner2 = MedidasTerreno[x - (step/2)][y + (step/2)];
            int corner3 = MedidasTerreno[x + (step/2)][y - (step/2)];
            int corner4 = MedidasTerreno[x + (step/2)][y + (step/2)];

            int mid = (corner1 + corner2 + corner3 + corner4)/4;
            int randomvalue = randomizador(-ruido, ruido);
            MedidasTerreno[x][y] = mid + randomvalue;  
        }
    }
}

// Versão inicial (tirar esse comentário quando terminar)
// REALIZAR TRATAMENTO DE ERROS PARA MATRIZES DE DIMENSÕES PARES!!
void Terreno::diamondSquare(int size, int ruido) {
    MedidasTerreno[0][0] = randomizador(-ruido, ruido);
    MedidasTerreno[0][tamanho - 1] = randomizador(-ruido, ruido);
    MedidasTerreno[tamanho - 1][0] = randomizador(-ruido, ruido);
    MedidasTerreno[tamanho - 1][tamanho - 1] = randomizador(-ruido, ruido);

    int step = tamanho - 1;

    while (step > 1) {
    square_step(size, ruido);
    diamond_step(size, ruido);
    step /= 2;
    }
}