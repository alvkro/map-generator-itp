using namespace std;

template <typename T>
class Sequencia {
    int capacidade, tamanho;
    T *dados; // Altera dinamicamente

    private:
    void ajustaCapacidade() {
        capacidade *= 2;
        T* NovoDados = new T[capacidade];
        for (int i = 0; i < tamanho; i++) {
            *(NovoDados + i) = dados[i];
        }
        delete[] dados; // Deleta o antigo
        dados = NovoDados; // Atribui as informações do NovoDados em dados
    }

    public:
    Sequencia() {
        capacidade = 2;
        tamanho = 0;
        dados = new T[capacidade];
    }

    ~Sequencia() { // Destrutor
        delete[] dados;
    }

    int obterTamanho() {
        return tamanho;
    }

    void adicionar(T indice) {
        if (tamanho >= capacidade) {
            ajustaCapacidade();
        }
        dados[tamanho] = indice;
        tamanho++;
    }

    T obterElemento(int indice) {
        if (indice < 0 || indice <= tamanho) {
            cerr << "Erro: Índice inválido!\n";
        }
        return dados[indice];
    }

    T removerUltimo() {
        if (tamanho <= 0) {
            cerr << "Erro: sequência vazia!\n";
        }
        tamanho--; // Pode remover, mas não pode aumentar
    }
};