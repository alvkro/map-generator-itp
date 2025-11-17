#include "paleta.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int Paleta::obterTamanho() {return tamanho;}

void Paleta::adicionarCor(Cores RGB) {
    if (tamanho < capacidade) {
        ConjuntoDeCores[tamanho] = RGB;
        tamanho++;
    }
    else if (tamanho > capacidade) { // Alterar isso (colocar para alocar mais memória)
        cerr << "Indice inválido\n";
    }
}

Cores Paleta::obterCor(int indice) {return ConjuntoDeCores[indice];} 
// Não é int porque o ConjuntoDeCores é type::Cores

void Paleta::SetColorHex(string hexadecimal) { // Estudar mais isso daí.
    ifstream arquivo(hexadecimal); // Lê o arquivo

    string CodigoHex;
    while (getline(arquivo, CodigoHex)) {
        if (CodigoHex[0] == '#') {
            CodigoHex.erase(CodigoHex.begin());
        }

        unsigned int valor;
        stringstream ss; // Texto -> número
        ss << hex << CodigoHex;
        ss >> valor;

        int r = (valor >> 16) & 0xFF;
        int g = (valor >> 8) & 0xFF;
        int b = valor & 0xFF;

        adicionarCor({r, g, b});

        // Operação bitwise, stream, canal de comunicação
    }
}
