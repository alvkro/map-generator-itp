# Técnicas usadas:
Esse arquivo serve para explicar as principais tecnologias usadas e em que parte do projeto foi feita!

# Stringsteam: (conversor sob demanda)
- Usado em `imagem`, no qual serviu como solução na problemática de converter um número hexadecimal para uma base decimal. Basicamente é uma classe que serve de canal para entrada e saída de informações (semelhante a cin/cout na iostream), a diferença é que nessa classe trabalha-se apenas com string internas e converte o pedaço de texto de acordo com o tipo da variável, útil quando estamos trabalhando com manipuladores, no caso do projeto o manipulador hexadecimal.
```cpp
stringstream ss;
ss << "teste 123"; // Armazena a string
ss >> valor; // Converte para número (saída)
```
- Logo após, ele passa pelo manipulador `hex`, que manda a instrução que o valor comunicado pelo canal deve ser interpretado como hexadecimal, como após é armazenado na variável ss, daí, é armazenado como inteiro de acordo com o tipo de variável logo após o operaador `>>`.

Resumo:
1) Lê o texto "FFAA33"
2) Interpreta como base 16
3) Converte para inteiro
4) Armazena em valor.

# Operação de Bitwise:
- Operações bitwise são operações realizadas diretamente nos bits de um número.
- No projeto, elas permitem separar um inteiro no formato hexadecimal 0xRRGGBB nos três canais de cor.
- Utiliza-se o operador de deslocamento (>>) para posicionar os bits desejados na faixa mais baixa, seguido pelo uso da máscara - 0xFF com o operador AND (&) para extrair apenas os 8 bits correspondentes a cada canal (R, G e B).
/Completar com bitshift, operadores bitwise e máscara (0xFF).

