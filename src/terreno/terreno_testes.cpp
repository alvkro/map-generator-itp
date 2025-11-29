#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../doctest.h"
#include "terreno.h"

// LEMBRAR: ORIENTAÇÃO Y POR X

TEST_CASE("Testa a criação de um terreno de uma única célula") {
  Terreno terreno(0); // 2^0 + 1 = 2
  CHECK(terreno.obterLargura() == 2);
  CHECK(terreno.obterProfundidade() == 2);
}

TEST_CASE("Testa a geração aleatória de altitudes") {
  Terreno terreno(2);
  CHECK(terreno.obterLargura() == 5);
  CHECK(terreno.obterProfundidade() == 5);
}


TEST_CASE("Testa a confiabilidade do gerador de números") {
  Terreno terreno(3);
  CHECK(terreno.randomizador(-2, 2) >= -2);
  CHECK(terreno.randomizador(-1, 1) >= -1);
  CHECK(terreno.randomizador(-4, 4) >= -4);
}

TEST_CASE("Testa a funcionalidade da etapa quadrada do Diamond-Square") {
    Terreno terreno(2);  // 2^2 + 1 = 5 X 5

    terreno(0, 0) = 2;
    terreno(0, 4) = 7;
    terreno(4, 0) = 3;
    terreno(4, 4) = 5;

    // step correto = tamanho - 1 = 4
    CHECK(terreno.square_step(4,0) == 4);
}

TEST_CASE("Testa a funcionalidade da etapa diamante do Diamond-Square") {
    Terreno terreno(2); 

    terreno(0, 0) = 10; terreno(0, 4) = 10;
    terreno(4, 0) = 10; terreno(4, 4) = 10;
    terreno(2, 2) = 10; 

    terreno(0, 2) = -1;
    terreno(2, 0) = -1;
    terreno(2, 4) = -1; 
    terreno(4, 2) = -1; 

    terreno.diamond_step(4, 0);
    
    CHECK(terreno(0, 2) == 10);
    CHECK(terreno(2, 0) == 10);
    CHECK(terreno(2, 4) == 10);
}

TEST_CASE("Agora, o teste do funcionamento do Diamond-Square por completo") {
  
}

// Você precisará criar testes adicionais para cobrir os métodos privados da classe.
// Por exemplo, você pode criar testes para os métodos das etapas Square e Diamond
// Você pode torná-los públicos temporariamente para fins de teste ou usar técnicas como "friend testing".