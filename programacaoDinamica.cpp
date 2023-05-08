#include <iostream>
#include "programacaoDinamica.h"

ProgramacaoDinamica::ProgramacaoDinamica (int **A, int **T, int tamanho)  
         : m_a(A), m_t(T), m_tamanho(tamanho)  {
    m_resultado = new int *[2]; //inicia as matrizes resultado e caminho
    m_caminho = new int *[2];
    for(int i = 0; i < 2; i++) {
        m_resultado[i] = new int[tamanho];
        m_caminho[i] = new int[tamanho];
    }
    this->iniciar();
    this->imprime();
}

void ProgramacaoDinamica::iniciar() {
    int posicao;
    m_resultado[0][0] = 0; //desconsidera a posiçao 0
    m_resultado[1][0] = 0;
    m_caminho[0][0] = 0;
    m_caminho[1][0] = 0;

    m_resultado[0][1] = m_a[0][0] + m_a[0][1]; //soma do valor para entrar na linha com primeira estação
    m_resultado[1][1] = m_a[1][0] + m_a[1][1];
    m_caminho[0][1] = 0;
    m_caminho[1][1] = 1;

    for (posicao = 2; posicao < m_tamanho - 1; posicao++) { //percorre todas as estações

        m_resultado[0][posicao] = compara(m_resultado[0][posicao -1] + m_a[0][posicao],
                                          m_resultado[1][posicao -1] + m_t[1][posicao -1] + m_a[0][posicao],
                                          posicao, 0); //retorna o menor dos 2 valores

        m_resultado[1][posicao] = compara(m_resultado[0][posicao -1] + m_t[0][posicao -1] + m_a[1][posicao],
                                          m_resultado[1][posicao -1] + m_a[1][posicao],
                                          posicao, 1); //retorna o menor dos 2 valores
    }

    m_resultado[0][m_tamanho - 1] = m_resultado[0][m_tamanho - 2] + m_a[0][m_tamanho - 1]; //soma o valor para sair da linha
    m_caminho[0][m_tamanho - 1] = 0;
    m_resultado[1][m_tamanho - 1] = m_resultado[1][m_tamanho - 2] + m_a[1][m_tamanho - 1];
    m_caminho[1][m_tamanho - 1] = 1;
}

int ProgramacaoDinamica::compara(int valor1, int valor2, int posicao, int linha) { //retorna o menor valor e preenche a matriz de caminhos
    if(valor1 < valor2) {
        m_caminho[linha][posicao] = 0;
        return valor1;
    } else {
        m_caminho[linha][posicao] = 1;
        return valor2;
    }
    return 0;
}

void ProgramacaoDinamica::imprime() { //imprime o resultado mostrando o tempo do percurso e o caminho percorrido
    int linha;
    std::cout << "Menor tempo: ";
    if(m_resultado[0][m_tamanho - 1] < m_resultado[1][m_tamanho - 1]){
        std::cout << m_resultado[0][m_tamanho - 1] << std::endl;
        linha = 0;
    }else {
        std::cout << m_resultado[1][m_tamanho - 1] << std::endl;
        linha = 1;
    }
    std::cout << "Caminho percorrido:";
    imprimeAux(linha, m_tamanho - 1);
    std::cout << std::endl;
}

void ProgramacaoDinamica::imprimeAux(int linha, int posicao) { //como o caminho foi achado de traz pra frente busca recursivamente o primeiro elemento do caminho e volta imprimindo
    if (posicao == 2) {
        std::cout << " " << m_caminho[linha][posicao];
    } else {
        imprimeAux(m_caminho[linha][posicao], posicao - 1);
        std::cout << " " << m_caminho[linha][posicao];
    }
}
