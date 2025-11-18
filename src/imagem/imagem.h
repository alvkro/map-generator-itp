#include "../paleta/paleta.h"
// Depois estudar a parte de using...

struct Pixel {
    int r, g, b;
};

class Imagem {
    private:
    int largura, altura;
    Pixel** dadosPixel;

    public:
    Imagem(int w, int h) {
        largura = w;
        altura = h;

        dadosPixel = new Pixel*[h]; 
        for (int i = 0; i < h; i++) {
            dadosPixel[i] = new Pixel[w];
        }
    }

    Imagem(string arquivo) {
        lerPPM(arquivo);
    }

    ~Imagem() { 
        for (int i = 0; i < altura; i++) {
            delete[] dadosPixel[i];
        }
        delete[] dadosPixel;
    }

    Pixel& operator()(int x, int y); // Sobrecarga de operador!

    int obterAltura();
    int obterLargura();
    bool lerPPM(string arquivo);
};