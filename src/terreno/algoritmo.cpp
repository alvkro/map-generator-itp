#include "terreno.h"
#include <math.h>
#include <random>
using namespace std;

// Deslocamento do Ponto Médio:

int Terreno::ruido(int antiDeslocamento, int deslocamento) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(antiDeslocamento, deslocamento);
    return dist(gen);
}

// Versão inicial (tirar esse comentário quando terminar)
bool Terreno::deslocPontoMedio(int arr[], int tamanho) {
        int esq = 0;
        int dir = tamanho - 1;
        int passo = dir - esq;

        while (passo > 1) {
            for (int i = 0; i < tamanho; i += passo) {
                int mid = (arr[i] + arr[passo + i])/2;
                int indexMeio = (i + tamanho + i) / 2;
                arr[indexMeio] = mid + ruido(-8, 8);
            }
            passo /= 2;
        }
    }

// end