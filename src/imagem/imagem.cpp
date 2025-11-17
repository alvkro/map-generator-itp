#include "imagem.h"
#include <string>
#include <fstream>
using namespace std;

int Imagem::obterAltura() {return altura;}

int Imagem::obterLargura() {return largura;};

void Imagem::lerPPM(string arquivo) {
    /* ... */
}

Pixel& Imagem::operator()(int x, int y) {
    return dadosPixel[x][y];
}