#pragma once

// struct MedidasTerreno {
//     int largura;
//     int altura;
// };

class Terreno {
private:
int areaTerreno;
int** MedidasTerreno; // dá pra fazer diferente?

public:
Terreno(int area) {
    gerarTerreno(area);
}

~Terreno() { // não deleta 100% das coisas
    delete[] MedidasTerreno;
}

void gerarTerreno(int area);
int obterLargura();
int obterProfundidade();
};