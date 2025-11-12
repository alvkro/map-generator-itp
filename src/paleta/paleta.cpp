#include "paleta.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

// TODO: Fazer um tratamento nas funções

int Paleta::obterTamanho() {return tamanho;}

void Paleta::adicionarCor(const Cores& RGB) {
    if (tamanho < capacidade) {
        ConjuntoDeCores[tamanho] = RGB;
        tamanho++;
    }
    else if (tamanho > capacidade) {
        cerr << "Indice inválido\n";
    }
}

Cores Paleta::obterCor(int indice) {return ConjuntoDeCores[indice];} // Não é int porque o ConjuntoDeCores é type::Cores

void HexToDec(const string& hexadecimal) {
    ifstream arquivo("cores.hex"); // Lê o arquivo

    string CodigoHex;
    while (getline(arquivo, CodigoHex)) {
        if (CodigoHex[0] == '#') {
            CodigoHex.erase(CodigoHex.begin());
        }
        /*Como transformar um arquivo de Hexadecimal para apenas decimal?*/
    }
}
