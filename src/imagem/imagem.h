#include "../paleta/paleta.h"

class Imagem {
    public:
    int largura, altura;
    int** pixels;

    Imagem(int w, int h) {
        largura = w;
        altura = h;

        pixels = new int*[h]; 
        for (int i = 0; i < h; i++) {
            pixels[i] = new int[w];
        }
        // Orientação: pixels[y][x]
    }

    ~Imagem() { 
        for (int i = 0; i < altura; i++) {
            delete[] pixels[i];
        }
        delete[] pixels;
    }

    int obterAltura();
    int obterLargura();
};