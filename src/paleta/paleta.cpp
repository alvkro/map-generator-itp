#include "paleta.h"
#include <iostream>
using namespace std;

// TODO: Fazer um tratamento nas funções

int Paleta::obterTamanho() {return tamanho;}

void Paleta::adicionarCor(const Cores& RGB) {
    if (tamanho < capacidade) {
        ConjuntoDeCores[tamanho] = RGB;
        tamanho++;
    }
    else if (tamanho > capacidade) {
        cerr << "indice inválido\n";
    }
}

Cores Paleta::obterCor(int indice) {return ConjuntoDeCores[indice];} // Não é int porque o ConjuntoDeCores é type::Cores

