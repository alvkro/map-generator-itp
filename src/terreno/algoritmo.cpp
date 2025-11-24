#include "terreno.h"
#include <math.h>
#include <random>
using namespace std;

int Terreno::NumberGenerator(int antiDeslocamento, int deslocamento) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(antiDeslocamento, deslocamento);
    return dist(gen);
}

// Versão inicial (tirar esse comentário quando terminar)
void Terreno::DeslocPontoMedio(int array_x[10]) {
    int M = (array_x[0] + array_x[1])/2;
}