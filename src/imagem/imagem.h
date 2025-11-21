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
    Imagem() {
        largura = 10;
        altura = 10;

        dadosPixel = new Pixel*[altura]; 
        for (int i = 0; i < altura; i++) {
            dadosPixel[i] = new Pixel[largura];
        }
    }

    Imagem(int w, int h) {
        criarImagem(w, h);
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
    void criarImagem(int w, int h);
    bool salvarPPM(const string& arquivo);
};