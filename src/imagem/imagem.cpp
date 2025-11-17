#include "imagem.h"
#include <string>
#include <fstream>
using namespace std;

int Imagem::obterAltura() {return altura;}

int Imagem::obterLargura() {return largura;}

bool Imagem::lerPPM(string arquivo) {
        ifstream arquivo;
        if (!arquivo.is_open())
            return false;

        string tipo;
        arquivo >> tipo;

        if (tipo != "P3")
            return false;

        int w, h, maxVal;
        arquivo >> w >> h >> maxVal;

        criarImagem(w, h);

        for (int y = 0; y < h; y++) {
            for (int x = 0; x < w; x++) {
                arq >> dadosPixel[y][x].r
                    >> dadosPixel[y][x].g
                    >> dadosPixel[y][x].b;
            }
        }

        return true;
    }

Pixel& Imagem::operator()(int x, int y) {
    return dadosPixel[x][y];
}

//consertei