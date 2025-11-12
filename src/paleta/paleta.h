#include <string>
using namespace std;
#pragma once

struct Cores {
    int r, g, b;
};

class Paleta {  
    public:
    Cores* ConjuntoDeCores;
    int tamanho, capacidade;
    string arquivo;

    Paleta() {
        arquivo = "cores.hex";
        capacidade = 255;
        tamanho = 0; // tamanho inicial
        ConjuntoDeCores = new Cores[capacidade];
    }

    Paleta(const string& nomeDoArquivo) {
        arquivo = "cores.hex";
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