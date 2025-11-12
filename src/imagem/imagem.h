#include "../paleta/paleta.h"

class Imagem {
    public:
    int largura, altura;
    int** pixels;

    Imagem(int w, int h) {
        largura = w;
        altura = h;

        // Entender melhor  vvvvv
        pixels = new int*[w];
        for (int i = 0; i < w; i++) {
            pixels[i] = new int[h];
        }
    }

    ~Imagem() {
        delete[] pixels;
    }

    int obterAltura();
    int obterLargura();
};