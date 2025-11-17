#include <string>
using namespace std;
#pragma once

struct Cores {
    int r, g, b; // unsigned char
};

class Paleta {  
    public:
    Cores* ConjuntoDeCores;
    int tamanho, capacidade;
    string arquivo;

    Paleta() {
        capacidade = 255;
        tamanho = 0; // tamanho inicial
        ConjuntoDeCores = new Cores[capacidade];
    }

    Paleta(const string& nomeDoArquivo) {
        capacidade = 255;
        tamanho = 0; // tamanho inicial
        ConjuntoDeCores = new Cores[capacidade];
        HexToDec(nomeDoArquivo);
    }

    ~Paleta() {
        delete[] ConjuntoDeCores;
    }

    int obterTamanho();
    void adicionarCor(Cores RGB); // Por que da erro se colocar Cores& RGB?
    Cores obterCor(int indice);
    void HexToDec(string hexadecimal);
};