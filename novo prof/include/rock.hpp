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
    double soma;       // variavel que armazena a soma
    int Direita;       // variavel que armazena a posicao da direita
    int Esquerda;      // variavel que armazena a posicao da esquerda
    int somaesq;       // variavel que armazena a soma dos elementos da esquerda
    int somadir;       // variavel que armazena a soma dos elementos da direita
    int primeiroindex; // variavel que armazena o primeiro index
    int ultimoindex;   // variavel que armazena o ultimo index
};
void insereNotas(int pos, double nota);           // insere as notas no vector
void InicializaNotas();                           // inicializa o vector de notas com 0 em todas as posições
void DestroiNotas(vector<double> &notas);         // destroi o vector de notas
void imprimeDados(Rock resp);                     // imprime os dados da classe Rock
Rock SSM(vector<double> notas, int ini, int fim); // funcao que calcula o SSM
void imprimeNotas(vector<double> &notas);         // imprime as notas

#endif