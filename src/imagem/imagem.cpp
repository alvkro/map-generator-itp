#include "imagem.h"
#include <string>
#include <fstream>
using namespace std;

int Imagem::obterAltura() {return altura;}

int Imagem::obterLargura() {return largura;}

void Imagem::criarImagem(int w, int h) { // ???
    largura = w;
    altura = h;

    dadosPixel = new Pixel*[h];
    for (int i = 0; i < h; i++){
        dadosPixel[i] = new Pixel[w]; 
    } 
}

bool Imagem::lerPPM(string arquivo) {
    ifstream arq(arquivo);
    if (!arq.is_open()) {
        return false;
    }

    string tipo;
    arq >> tipo;

    if (tipo != "P3") { // apenas arquivos P3 simples
        return false;
    }

    int w, h, maxVal;

    arq >> w >> h >> maxVal;

    criarImagem(w, h); // cria a matriz

    // Leitura simples dos pixels
    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            arq >> dadosPixel[y][x].r;
            arq >> dadosPixel[y][x].g;
            arq >> dadosPixel[y][x].b;
        }
    }

    return true;
}

Pixel& Imagem::operator()(int x, int y) {
    return dadosPixel[y][x];
}

bool Imagem::salvarPPM(const string& arquivo) {
    ofstream arq(arquivo);
    if (!arq.is_open()) {
        return false;
    }

    arq << "P3\n";
    arq << largura << " " << altura << "\n";
    arq << "255\n";

    for (int y = 0; y < altura; y++) {
        for (int x = 0; x < largura; x++) {
            Pixel& p = dadosPixel[y][x];
            arq << p.r << " " << p.g << " " << p.b << "\n";
        }
    }
    return true;
}