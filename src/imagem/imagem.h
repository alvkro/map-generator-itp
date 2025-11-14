#include "../paleta/paleta.h"
// Depois estudar a parte de using...

struct Pixel {
    int r, g, b;
};

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