#pragma once
#include <string>
using namespace std;


struct Cores {
    int r, g, b; //menos eficiente
};

class Paleta {  
    public:
    Cores* ConjuntoDeCores;
    int tamanho, capacidade;

    Paleta() {
        capacidade = 10;
        tamanho = 0; // tamanho inicial
        ConjuntoDeCores = new Cores[capacidade]; // Isso aqui é referente a QUANTAS cores diferentes a paleta vai ter!!!
    }

    Paleta(const string& nomeDoArquivo) {
        capacidade = 255;
        tamanho = 0; // tamanho inicial+

        ConjuntoDeCores = new Cores[capacidade];
        SetColorHex(nomeDoArquivo);
    }

    ~Paleta() {
        delete[] ConjuntoDeCores;
    }

    int obterTamanho();
    void ajustarCapacidade();
    void adicionarCor(Cores RGB); // Por que da erro se colocar Cores& RGB?
    Cores obterCor(int indice);
    void SetColorHex(string hexadecimal);
    int ConvertToHex(string CodigoHex);
    void OpBitwise(int valor);
};