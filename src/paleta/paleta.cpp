#include "paleta.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

int Paleta::obterTamanho() {return tamanho;}

void Paleta::ajustarCapacidade() {
    capacidade *= 2;
    Cores* NovoConjuntoDeCores = new Cores[capacidade];
    for (int i = 0; i < tamanho; i++) {
        *(NovoConjuntoDeCores + i) = ConjuntoDeCores[i]; // Aritmetica de ponteiros
    }
    delete[] ConjuntoDeCores;
    ConjuntoDeCores = NovoConjuntoDeCores; 
}

void Paleta::adicionarCor(Cores RGB) {
    if (tamanho < capacidade) {
        ConjuntoDeCores[tamanho] = RGB;
        tamanho++;
    }
    else if (tamanho > capacidade) {
        cout << "Alocando mais memória...\n";
        ajustarCapacidade();
    }
}

Cores Paleta::obterCor(int indice) {return ConjuntoDeCores[indice];} 
// Não é int porque o ConjuntoDeCores é type::Cores

int Paleta::ConvertToHex(string CodigoHex) {
        unsigned int valor;
        stringstream ss; // Classe que permite que um texto seja colocado dentro dele e possa ser interpretado como número (trabalha somente co mstrings)
        ss << hex << CodigoHex;
        ss >> valor;

        return valor;
}

void Paleta::OpBitwise(int valor) {
    int r = (valor >> 16) & 0xFF;
    int g = (valor >> 8) & 0xFF;
    int b = valor & 0xFF;

    adicionarCor({r, g, b});
}

void Paleta::SetColorHex(string hexadecimal) { // Estudar mais isso daí.
    ifstream arquivo(hexadecimal); // Lê o arquivo

    string CodigoHex;
    while (getline(arquivo, CodigoHex)) {
        if (CodigoHex[0] == '#') {
            CodigoHex.erase(CodigoHex.begin());
        }

        int valor = ConvertToHex(CodigoHex);

        OpBitwise(valor);

        // Operação bitwise, stream, canal de comunicação
    }
}
