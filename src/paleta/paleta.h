using namespace std;

struct Cores {
    int r, g, b;
};

class Paleta {
    private:
    Cores* ConjuntoDeCores;
    int tamanho, capacidade;
    
    public:
    Paleta() {
        capacidade = 255;
        tamanho = 0;
        ConjuntoDeCores = new Cores[capacidade];
    }

    ~Paleta() {
        delete[] ConjuntoDeCores;
    }

    int obterTamanho();
};