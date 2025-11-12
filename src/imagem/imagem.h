#include "../paleta/paleta.h"

class Imagem {
    public:
    int largura, altura;
    int** pixels;

    Imagem(int w, int h) {
        largura = w;
        altura = h;
        
        // pixels = new int*[h];
        // for (int i = 0; i < w; i++) {
        //     pixels[i] = new int[w];
        // }
    }

    ~Imagem() {
    }
};