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

 // para compilar: g++ -I. imagem/imagem.cpp paleta/paleta.cpp terreno/algoritmo.cpp terreno/terreno.cpp mapa/main.cpp -o gerador