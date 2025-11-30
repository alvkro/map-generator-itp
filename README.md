# GERADOR DE MAPAS EM C++
O projeto foi criado para fins avaliativos da matéria *Introdução à Técnicas de Programação*, ministrada por *André Maurício* (DIMAP/UFRN).
Alunos responsáveis: Álvaro Barbosa Filho e Matheus Lucheze Lopes.

A ideia inicial do projeto é ser um criador de mapas de maneira procedural, utilizando a linguagem *C++* e o algoritmo *Diamond-Square*, resultando em um terreno topográfico

## Etapa 1: Paleta
- Inicialmente, foi criado um tipo de dado para armazenar as quantidades de vermelho, verde e azul (RGB).
- Logo depois, uma classe específica para criar combinações diferentes de RGB (Paleta), com dois construtores e um destrutor e algumas funções.
  
### Construtor:
- O construtor é composto por variáveis como capacidade e tamanho, usadas futuramente para a alocação dinâmica de memória conforme a necessidade da aplicação.
- Além disso, é alocado uma array na memória para armazenar essa paleta de cores
- Há um outro construtor específico para ler um arquivo `cores.hex` com um conjunto de cores, que recebe como parâmetro o nome do arquivo.

### Funções:
As principais funções dessa etapa são:
- Ajuste de capacidade de armazenamento da Paleta via alocação dinâmica;
- Adição de cores para a Paleta;
- Conversão hexadecimal para decimal, utilizando *operação de bitwise*;

## Etapa 2: Imagem
- Responsável pela criação da imagem do projeto, feito em formato PPM (*Portable Pixmap Format*) devido a facilidade de edição e tamanho pequeno.
- Novamente, foi criado um tipo de dado para armazenar os valores *RGB* e uma classe específica para a Imagem.
  
### Construtor:
- No total têm-se 3 construtores, o primeiro foi responsável pela alocação da imagem em uma matriz com tamanho pré-estabelecido, o segundo recebe parâmetros de largura e altura
para personalizar as dimensões da matriz, e o terceiro recebe o nome do arquivo PPM como parâmetro, que é responsável em ler o arquivo.

### Funções:
As principais funções dessa etapa são:
- Sobrecarga do operador `()` com o objetivo de interpretar um argumento como coordenadas em uma matriz (x, y) -> [x][y];
- Leitor do arquivo PPM (função utilizada no terceiro construtor mencionado);
- Criador da matriz imagem, feito sob alocação dinâmica (função utilizada no segundo construtor);
- Cria e salva um arquivo em formato PPM seguindo os determinados padrões estabelecidos deste tipo de arquivo;

## Etapa 3: Terreno
- Com o objetivo de armazenar valores aleatórios e consistentes pela matriz, essa etapa é responsável por atribuir irregularidades no terreno, determinando se é alto ou baixo naquela determinada célula

// PARA CONCLUIR!!





