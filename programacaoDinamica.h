#ifndef PROGRAMACAODINAMICA_H
#define PROGRAMACAODINAMICA_H

#include <vector>

class ProgramacaoDinamica {
    public:
        ProgramacaoDinamica (int **A, int **T, int tamanho);
    private:
        void iniciar();
        void imprime();
        void imprimeAux(int linha, int posicao);
        int compara(int valor1, int valor2, int posicao, int linha);
        int** m_a;
        int** m_t;
        int** m_resultado;
        int** m_caminho;
        int m_linhas;
        int m_tamanho;
};

#endif