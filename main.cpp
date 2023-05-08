/*
    AED2 - Trabalho Pratico 2 - Prof. Thiago de Souza Rodrigues
    Alunos: Samuel Correa Lucas Pereira
    Solução das linhas de montagem utilizando programação dinamica 
*/

#include <iostream>
#include <chrono>
#include "programacaoDinamica.h"

int main (int argc, char* argv[]) {
    int **a;
    int **t;
    a = new int*[2];
    t = new int*[2];

    /*int a1Teste[8] = {2, 7, 9, 3, 4, 8, 4, 3};
    int a2Teste[8] = {4, 8, 5, 6, 4, 5, 7, 2};
    int t1Teste[8] = {0, 2, 3, 1, 3, 4, 0, 0};
    int t2Teste[8] = {0, 2, 1, 2, 2, 1, 0, 0};
    a [0] = a1Teste;
    a [1] = a2Teste;
    t [0] = t1Teste;
    t [1] = t2Teste;
    
    std :: cout << "Teste com exemplo do material teorico: " << std::endl;
    auto inicioTeste = std::chrono::high_resolution_clock::now();
    ProgramacaoDinamica teste(a, t, 8);
    auto resultadoTeste = std::chrono::high_resolution_clock::now() - inicioTeste;
    long long microsecondsTeste = std::chrono::duration_cast<std::chrono::microseconds>(resultadoTeste).count();
    std :: cout << "Tempo gasto: " << microsecondsTeste << std::endl <<  std::endl;*/

    int a1Questao1 [11] = {3, 5, 7, 10, 5, 9, 11, 9, 5, 2, 6};
    int a2Questao1 [11] = {2, 6, 3, 9, 11, 4, 9, 3, 12, 4, 5};
    int t1Questao1 [11] = {0, 3, 5, 4, 2, 7, 5, 8, 1, 0, 0};
    int t2Questao1 [11] = {0, 5, 3, 7, 5, 6, 2, 5, 2, 0, 0};

    a [0] = a1Questao1;
    a [1] = a2Questao1;
    t [0] = t1Questao1;
    t [1] = t2Questao1;

    std :: cout << "Resultado questão 1: " << std::endl;
    auto inicio1 = std::chrono::high_resolution_clock::now();
    ProgramacaoDinamica questao1(a, t, 11);
    auto resultado1 = std::chrono::high_resolution_clock::now() - inicio1;
    long long microseconds1 = std::chrono::duration_cast<std::chrono::microseconds>(resultado1).count();
    std :: cout << "Tempo gasto: " << microseconds1 << std::endl <<  std::endl;

    int a1Questao2 [10] = {5, 10, 6, 3, 8, 5, 3, 7, 12, 8};
    int a2Questao2 [10] = {7, 3, 5, 3, 7, 6, 4, 9, 10, 9};
    int t1Questao2 [10] = {0, 4, 2, 7, 2, 5, 8, 2, 0, 0};
    int t2Questao2 [10] = {0, 6, 1, 7, 3, 6, 4, 5, 0, 0};

    a [0] = a1Questao2;
    a [1] = a2Questao2;
    t [0] = t1Questao2;
    t [1] = t2Questao2;

    std :: cout << "Resultado questão 2: " << std::endl;
    auto inicio2 = std::chrono::high_resolution_clock::now();
    ProgramacaoDinamica questao2(a, t, 10);
    auto resultado2 = std::chrono::high_resolution_clock::now() - inicio2;
    long long microseconds2 = std::chrono::duration_cast<std::chrono::microseconds>(resultado2).count();
    std :: cout << "Tempo gasto: " << microseconds2 << std::endl;
}
