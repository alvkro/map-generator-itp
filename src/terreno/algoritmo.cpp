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

void Terreno::diamond_step(int step, int ruido){
    for (int x = 0; x < tamanho; x += (step/2)){
        for (int y = ((x / (step/2)) % 2 == 0 ) ? (step/2) : 0; y < tamanho; y += step){
            double sum = 0.0;
            int count = 0;

            // RV = random value

            if (x - (step/2) >= 0){   // Pontos vizinhos para o Square Step
                sum += MedidasTerreno[x - (step/2)][y];  // Topo
                count++;
            }
            if (x + (step/2) < tamanho){
                sum += MedidasTerreno[x + (step/2)][y];  // Base
                count++;
            }
            if (y - (step/2) >= 0){
                sum += MedidasTerreno[x][y - (step/2)];  // Esquerda
                count++;
            }
            if (y + (step/2) < tamanho){
                sum += MedidasTerreno[x][y + (step/2)];  // Direita
                count++;
            }
            if (count > 0){
                double mid = sum / count;
                double rv = randomizador(-ruido, ruido);

                if (MedidasTerreno[x][y] == -1.0){
                    MedidasTerreno[x][y] = mid + rv;
                }
            }
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