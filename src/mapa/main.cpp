 #include "paleta/paleta.h"
 #include "terreno/terreno.h"
 #include "imagem/imagem.h"
 #include <iostream>
 #include <string>
 using namespace std;

 int main() {
    int size_terreno;
    string arquivo_cores = "cores.hex"; // pequeno problema
    string nome_arquivo;

    cout << "Insira o tamanho do terreno: ";
    cin >> size_terreno; // usar 2^n + 1 (tá na pasta terreno)

    // cout << "Insira o nome do arquivo contendo a paleta de cores: ";
    // cin >> arquivo_cores;

    cout << "Digite o nome do arquivo que deseja usar: ";
    cin >> nome_arquivo;

    Terreno terreno(size_terreno);
    terreno.diamondSquare(terreno.obterLargura() - 1, 100);
    
    Paleta paleta(arquivo_cores);

    Imagem img = terreno.paisagem(paleta);

    terreno.diamondSquare(terreno.obterLargura() - 1, 100);

    img.salvarPPM(nome_arquivo);

    return 0;
}
