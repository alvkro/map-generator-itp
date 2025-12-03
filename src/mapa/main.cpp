 #include "paleta/paleta.h"
 #include "terreno/terreno.h"
 #include "imagem/imagem.h"
 #include <iostream>
 #include <string>
 using namespace std;
 
 int main() {
     int size_terreno = 9;
     string arquivo_cores = "cores.hex";
     string nome_arquivo = "terreno.ppm";
 
     // cout << "Insira o tamanho do terreno: ";
     // cin >> size_terreno; // usar 2^n + 1 (tá na pasta terreno)
 
     // cout << "Insira o nome do arquivo contendo a paleta de cores: ";
     // cin >> arquivo_cores;
  
     // cout << "Digite o nome do arquivo que deseja usar: ";
     // cin >> nome_arquivo;
 
     // Paleta:
     Paleta colors(arquivo_cores);
 
     // Terreno:
     Terreno land(size_terreno);
     land.diamondSquare(land.obterLargura() - 1, 10);
 
     Imagem img = land.paisagem(colors);
     img.salvarPPM(nome_arquivo);
 }

int main() {
    int size_terreno;
    string arquivo_cores;
    string nome_arquivo;

    cout << "Insira o tamanho do terreno: ";
    cin >> size_terreno; // usar 2^n + 1 (tá na pasta terreno)

    cout << "Insira o nome do arquivo contendo a paleta de cores: ";
    cin >> arquivo_cores;

    cout << "Digite o nome do arquivo que deseja usar: ";
    cin >> nome_arquivo;

    Terreno terreno(size_terreno);
    terreno.gerarTerreno();
    
    Paleta paleta(arquivo_cores);

    Imagem img = terreno.paisagem(paleta);

    if(img.salvarPPM(nome_arquivo))
        cout << "Imagem salva com sucesso em " << nome_arquivo << endl;
    else
        cout << "Erro ao salvar imagem." << endl;

    return 0;
}
