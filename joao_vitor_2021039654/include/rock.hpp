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
    double soma;            // variavel que armazena a soma
    double Direita;         // variavel que armazena a posicao da soma_dir
    double Esquerda;        // variavel que armazena a posicao da soma_esq
    double soma_esq;        // variavel que armazena a soma dos elementos da soma_esq
    double soma_dir;        // variavel que armazena a soma dos elementos da soma_dir
    double primeiro_indice; // variavel que armazena o primeiro indice
    double ultimo_indice;   // variavel que armazena o ultimo indice
};

void imprimeResposta(Rock resp);                                              // Funcao que imprime a resposta
Rock SSM(vector<double> &notas, double ini, double fim);                      // Funcao que realiza o SSM
Rock SSM_Cruzado(vector<double> &notas, double ini, double meio, double fim); // Funcao que realiza o SSM dos elementos que cruzam o meio do vetor

#endif