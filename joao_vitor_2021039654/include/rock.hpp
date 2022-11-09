#ifndef ROCK
#define ROCK

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Rock
{
private:
    /* data */

    int A;                          // identificador do numero de amigos
    int S;                          // identificador do numero de shows
    vector<double> notas;           // vector de notas
    double soma;                    // variavel que armazena a soma
    double ssm;                     // variavel que armazena o ssm
    double suf;                     // variavel que armazena o suf
    double pref;                    // variavel que armazena o pref
    double max(double a, double b); // funcao que retorna o maior valor entre dois numeros
    vector<int> PosNotas;           // vector de posicoes das notas

public:
    void test();
    void Set_A(int a) { A = a; }               // seta o numero de amigos
    void Set_S(int s) { S = s; }               // seta o numero de shows
    const int &Get_A() { return A; }           // retorna o numero de amigos
    const int &Get_S() { return S; }           // retorna o numero de shows
    void insereNotas(int pos, double nota);    // insere as notas no vector
    void imprimeNotas();                       // imprime as notas
    void InicializaNotas();                    // inicializa o vector de notas com 0 em todas as posições
    void DestroiNotas();                       // destroi o vector de notas
    void imprimeDados(Rock resp);              // imprime os dados da classe Rock
    Rock SSM(Rock festival, int ini, int fim); // funcao que calcula o SSM
};

#endif