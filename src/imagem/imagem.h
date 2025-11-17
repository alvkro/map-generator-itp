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

        dadosPixel = new Pixel*[w]; 
        for (int i = 0; i < w; i++) {
            dadosPixel[i] = new Pixel;
        }
    }

    Imagem(string arquivo) {
        lerPPM(arquivo);
    }

    ~Imagem() { 
        for (int i = 0; i < largura; i++) {
            delete[] dadosPixel[i];
        }
        delete[] dadosPixel;
    }

    Pixel& operator()(int x, int y); // Sobrecarga de operador!

    int obterAltura();
    int obterLargura();
    void lerPPM(string arquivo);
};