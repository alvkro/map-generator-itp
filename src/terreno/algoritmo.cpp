#include "terreno.h"
#include <math.h>
#include <random>
using namespace std;

// Deslocamento do Ponto Médio:

int Terreno::NumberGenerator(int antiDeslocamento, int deslocamento) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(antiDeslocamento, deslocamento);
    return dist(gen);
}

// Versão inicial (tirar esse comentário quando terminar)
void Terreno::DeslocPontoMedio(int arr[], int tamanho) {
        int inc = tamanho - 1;
        for (int i = 0; i < tamanho; i++) { 
            int M = (arr[i] + arr[inc])/2;
            M += NumberGenerator(-8, 8);
            arr[(i + inc) / 2] = M; // Midpoint Displacement
            arr[M] = M + NumberGenerator(-8, 8);
            inc--;
    }
}

// end