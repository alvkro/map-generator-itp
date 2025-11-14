#include "../paleta/paleta.h"

class Imagem {
    public:
    int largura, altura;
    int** Pixel;

    Imagem(int w, int h) {
        largura = w;
        altura = h;

        Pixel = new int*[h]; 
        for (int i = 0; i < h; i++) {
            Pixel[i] = new int[w];
        }
        // Orientação: pixels[y][x]
    }

    ~Imagem() { 
        for (int i = 0; i < altura; i++) {
            delete[] Pixel[i];
        }
        delete[] Pixel;
    }

    int obterAltura();
    int obterLargura();
};