#include "../paleta/paleta.h"

class Imagem {
    public:
    int largura, altura;
    int** pixels;

    Imagem(int w, int h) {
        largura = w;
        altura = h;

        // Entender melhor  vvvvv
        pixels = new int*[w]; // guarda os endereços do vetor
        for (int i = 0; i < w; i++) {
            pixels[i] = new int[h]; // O ponteiro precisa apenas na declaração
        }
    }

    ~Imagem() { // Fazer um destrutor com uma maior qualidade
        for (int i = 0; i < largura; i++) {
            delete[] pixels[i];
        }
        delete[] pixels;
    }

    int obterAltura();
    int obterLargura();
};