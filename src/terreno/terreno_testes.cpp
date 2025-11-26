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

TEST_CASE("Testa o retorno da altitude de uma célula de um terreno") {
  
}

TEST_CASE("Testa a confiabilidade do gerador de números") {
  Terreno terreno(3);
  CHECK(terreno.randomizador(-2, 2) >= -2);
  CHECK(terreno.randomizador(-1, 1) >= -1);
  CHECK(terreno.randomizador(-4, 4) >= -4);
}

TEST_CASE("Testa a funcionalidade da etapa quadrada do Diamond-Square") {
  Terreno terreno(2);

  // Sem o ruído
  terreno(0, 0) = 2;
  terreno(0, 3) = 7;
  terreno(3, 0) = 3;
  terreno(3, 3) = 5;
  CHECK(terreno.square_step(2, 0) == 2);
}

// Você precisará criar testes adicionais para cobrir os métodos privados da classe.
// Por exemplo, você pode criar testes para os métodos das etapas Square e Diamond
// Você pode torná-los públicos temporariamente para fins de teste ou usar técnicas como "friend testing".