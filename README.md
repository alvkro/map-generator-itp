# GERADOR DE MAPAS EM C++

O projeto foi criado para fins avaliativos da disciplina **Introdução a Técnicas de Programação**, ministrada por **André Maurício** (DIMAP/UFRN).

**Alunos responsáveis:** Álvaro Barbosa Filho e Matheus Lucheze Lopes.

A proposta inicial do projeto é desenvolver um gerador de mapas procedural, utilizando a linguagem **C++** e o algoritmo **Diamond-Square**, resultando na representação visual de um terreno topográfico.

<img width="513" height="513" alt="primeiroteste" src="https://github.com/user-attachments/assets/37820862-2829-4adf-9d4e-2867d8392b9b" />

---

## Etapa 1: Paleta
Inicialmente, foi criado um tipo de dado para armazenar as quantidades de vermelho, verde e azul (RGB). Logo depois, uma classe específica para criar combinações diferentes de RGB (Paleta), com dois construtores, um destrutor e métodos auxiliares.

### Construtor:
- O construtor define a capacidade e o tamanho inicial, variáveis essenciais para o gerenciamento da alocação dinâmica de memória.
- É alocado **um array** na memória para armazenar as cores da paleta.
- Um construtor alternativo permite a leitura de um arquivo `cores.hex`, carregando conjuntos de cores pré-definidos.

### Funções:
As principais funcionalidades desta etapa incluem:
- Gerenciamento dinâmico da capacidade de armazenamento da Paleta;
- Inserção de novas cores na estrutura;
- Conversão de hexadecimal para decimal, utilizando **operações bit a bit (bitwise)**.

---

## Etapa 2: Imagem
Responsável pela criação da representação visual do projeto, utilizando o formato **PPM (Portable Pixmap Format)** devido à sua simplicidade de implementação, facilidade de edição e tamanho reduzido. Novamente, foi criado um tipo de dado para armazenar os valores RGB e uma classe específica para a Imagem.

### Construtor:
No total, têm-se 3 construtores:
1. Responsável pela alocação da imagem em uma matriz com tamanho pré-estabelecido;
2. Recebe parâmetros de largura e altura para personalizar as dimensões da matriz (alocação dinâmica);
3. Recebe o nome de um arquivo PPM como parâmetro para leitura e carregamento.

### Funções:
As principais funções dessa etapa são:
- **Sobrecarga do operador `()`:** Permite acessar e modificar pixels utilizando a sintaxe de coordenadas `imagem(x, y)`, abstraindo a lógica da matriz;
- **Leitor de arquivo PPM:** Função utilizada no terceiro construtor mencionado;
- **Alocação Dinâmica:** Criação da matriz de pixels em tempo de execução;
- **Escrita de Arquivo:** Cria e salva o resultado em formato PPM seguindo o padrão oficial (cabeçalho P3, dimensões e valor máximo de cor).

---

## Etapa 3: Terreno
Esta etapa gerencia a lógica de geração procedural, criando uma matriz de altitudes que representa a topografia do mapa. A classe utiliza o algoritmo **Diamond-Square** para gerar relevos naturais.

### Construtor:
- Recebe um valor de "área" (expoente) para calcular o tamanho real da matriz seguindo a regra do algoritmo: `tamanho = 2^n + 1`.
- Realiza a **alocação dinâmica** de uma matriz bidimensional (ponteiros de ponteiros) para armazenar os valores de altitude.
- Inicializa a semente aleatória e prepara a grade para o processamento.

### Funções:
As principais funções que compõem o algoritmo são:
- **`diamondSquare` (Função Mestra):** Controla o fluxo do algoritmo, reduzindo progressivamente o tamanho do passo (`step`) e a magnitude do ruído aleatório a cada iteração, garantindo que o terreno tenha grandes montanhas e pequenos detalhes;
- **`square_step` (Etapa Quadrada):** Calcula o ponto central de cada quadrado da grade baseando-se na média dos seus quatro cantos diagonais, adicionando um deslocamento aleatório;
- **`diamond_step` (Etapa Diamante):** Calcula os pontos das arestas (formando uma cruz) baseando-se na média dos quatro vizinhos diretos (Norte, Sul, Leste, Oeste), lidando com verificações de borda para evitar acesso inválido à memória;
- **`randomizador`:** Utiliza o motor `std::mt19937` (Mersenne Twister) para gerar números pseudo-aleatórios com distribuição uniforme, garantindo maior qualidade estatística que o `rand()` comum;
- **Sobrecarga de Operador `()`:** Facilita o acesso e a escrita de dados na matriz de terreno através da sintaxe `terreno(x, y)`.

## Etapa 4: Mapa
- A etapa final do projeto, tem como objetivo juntar todas as etapas anteriores (`paleta`, `terreno` e `imagem`) para formar o mapa.
- Para tanto, é necessário uma última função que receba a paleta e faça um sombreamento.

### Função:
- A função `paisagem` tem como objetivo, a partir do mapa de altitudes gerado pelo algoritmo "Diamond-Square", colorir utilizando um gradiente em uma ordem específica (`cores.hex`);
- É realizado um cálculo (normatização) da matriz, ocorre da seguinte forma:
1. É armazenado a maior/menor altitude do terreno;
2. Ocorre um cálculo em porcentagem em relação à altura do mapa (50% da altitude, 75%...);
3. Acontece outro cálculo, no qual pega o índice relacionado ao tamanho da paleta, daí pinta aquele píxel;
- Para o sombreamento, ocorre uma verificação se a célula n - 1 é menor que a célula n, daí escurece 40% de cada atributo RGB;
- Finalizando no `main.cpp`, há a criação do terreno + a aplicação do algoritmo `Diamond-Square`, criação da paleta de cores, a
execução do método `paisagem` e, por fim, o salvamento do arquivo `.ppm`.
- Segue abaixo alguns exemplares da execução do programa:
<img width="513" height="513" alt="terreno512" src="https://github.com/user-attachments/assets/4a94fc22-e954-4b62-8bb3-70b39bd40eff" />
---

## Como Compilar e Executar

Para compilar o projeto, certifique-se de ter um compilador C++ instalado (como o g++). Utilize o terminal na pasta raiz do projeto:

```bash
# Compilação
g++ -I. imagem/imagem.cpp paleta/paleta.cpp terreno/algoritmo.cpp terreno/terreno.cpp mapa/main.cpp -o gerador

# Execução (Linux)
./gerador

# Execução (Windows)
gerador.exe
