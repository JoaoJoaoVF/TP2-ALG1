#ifndef ROCK
#define ROCK

#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <cmath>
using namespace std;

class Rock
{
public:
    double sum;        // variavel que armazena a sum
    double Direita;    // variavel que armazena a posicao da righteita
    double Esquerda;   // variavel que armazena a posicao da leftuerda
    double sumleft;    // variavel que armazena a sum dos elementos da leftuerda
    double sumright;   // variavel que armazena a sum dos elementos da righteita
    double firstindex; // variavel que armazena o primeiro index
    double lastindex;  // variavel que armazena o ultimo index
};
void InicializaA();               // inicializa o vector de A com 0 em todas as posições
void DestroiA(vector<double> &A); // destroi o vector de A
void imprimeDados(Rock resp);     // imprime os dados da classe Rock
void imprimeA(vector<double> &A); // imprime as A

void imprimeResposta(Rock resp);
Rock SSM(vector<double> &A, double low, double high);
Rock SSM2(vector<double> &A, double low, double mid, double high);
#endif