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
using namespace std;

class Rock
{
public:
    double sum;       // variavel que armazena a sum
    int righteita;       // variavel que armazena a posicao da righteita
    int leftuerda;      // variavel que armazena a posicao da leftuerda
    int sumleft;       // variavel que armazena a sum dos elementos da leftuerda
    int sumright;       // variavel que armazena a sum dos elementos da righteita
    int primeiroindex; // variavel que armazena o primeiro index
    int ultimoindex;   // variavel que armazena o ultimo index
};
void InicializaA();                   // inicializa o vector de A com 0 em todas as posições
void DestroiA(vector<double> &A); // destroi o vector de A
void imprimeDados(Rock resp);             // imprime os dados da classe Rock
void imprimeA(vector<double> &A); // imprime as A

void imprimeResposta(Rock resp);
Rock SSM(vector<double> &A, int low, int high);
Rock SSM2(vector<double> &A, int low, int mid, int high);
#endif