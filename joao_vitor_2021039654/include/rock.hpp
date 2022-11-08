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

    int A;                // identificador do numero de amigos
    int S;                // identificador do numero de shows
    vector<double> notas; // vector de notas
    double soma;          // variavel que armazena a soma
    double ssm;           // variavel que armazena o ssm
    double suf;           // variavel que armazena o suf
    double pref;          // variavel que armazena o pref
    double max(double a, double b);
    vector<int> PosNotas;
    vector<int> PosSuf;
    vector<int> PosPref;

public:
    void test();
    void Set_A(int a) { A = a; }     // seta o numero de amigos
    void Set_S(int s) { S = s; }     // seta o numero de shows
    const int &Get_A() { return A; } // retorna o numero de amigos
    const int &Get_S() { return S; } // retorna o numero de shows
    void insereNotas(int pos, double nota);
    void imprimeNotas();
    void InicializaNotas();
    void DestroiNotas();
    void imprimeDados(Rock resp);
    Rock SSM(Rock festival, int ini, int fim);

    void SSM_INTERATIVO(int ini, int fim);
};

#endif