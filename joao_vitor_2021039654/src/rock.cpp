#include "../include/rock.hpp"
using namespace std;

// Realiza a inserção da nota do show na posição em que ela pertence
void Rock::insereNotas(int pos, double nota)
{
    notas[pos] += nota;
}

// Inicializa o vetor de notas com a quantidade de shows e com 0 em todas as posições
void Rock::InicializaNotas()
{
    for (int i = 0; i < Get_S(); i++)
    {
        notas.emplace_back(0);
    }
}

// Realiza a impressao da resposta
void Rock::imprimeDados(Rock resp)
{
    cout << resp.primeiroindex + 1 << " " << resp.ultimoindex + 1 << endl;

    // cout << notas[resp.primeiroindex + 1] << " " << notas[resp.ultimoindex + 1] << endl;
    // cout << resp.ssm << endl;
}

Rock Rock::SSM(Rock festival, int ini, int fim)
{
    Rock sol; // A classe sol é a classe que armazena a resposta
    Rock esq; // A classe esq é a classe que armazena a resposta da parte esquerda
    Rock dir; // A classe dir é a classe que armazena a resposta da parte direita

    int meio = (ini + fim) / 2; // Calcula o meio do vetor

    if (ini == fim) // Condição de parada da recursão
    {
        sol.soma = festival.notas[ini]; // A soma recebe a nota do show
        sol.ssm = festival.notas[ini];  // O ssm recebe o maior valor entre 0 e a nota do show
        sol.suf = sol.ssm;              // O suf recebe o ssm
        sol.pref = sol.ssm;             // O pref recebe o ssm

        sol.primeiroindex = ini; // A variavel primeiroindex recebe a posição do show
        sol.ultimoindex = fim;   // A variavel ultimoindex recebe a posição do show

        return sol; // Retorna a classe sol
    }
    esq = SSM(festival, ini, meio);                               // Chama a função SSM para a parte esquerda
    dir = SSM(festival, meio + 1, fim);                           // Chama a função SSM para a parte direita
    sol.soma = esq.soma + dir.soma;                               // A soma recebe a soma da parte esquerda + a soma da parte direita
    sol.ssm = std::max({esq.ssm, dir.ssm, (esq.suf + dir.pref)}); // O ssm recebe o maior valor entre o ssm da parte esquerda, o ssm da parte direita e o suf da parte esquerda + o pref da parte direita
    sol.suf = std::max(dir.suf, dir.soma + esq.suf);              // O suf recebe o maior valor entre o suf da parte direita e a soma da parte direita + o suf da parte esquerda
    sol.pref = std::max(esq.pref, esq.soma + dir.pref);           // O pref recebe o maior valor entre o pref da parte esquerda e a soma da parte esquerda + o pref da parte direita

    if (sol.ssm == esq.ssm) // Caso o ssm seja igual ao ssm da parte esquerda
    {
        sol.primeiroindex = esq.primeiroindex; // A variavel primeiroindex recebe a variavel primeiroindex da parte esquerda
        sol.ultimoindex = esq.ultimoindex;     // A variavel ultimoindex recebe a variavel ultimoindex da parte esquerda
    }
    else if (sol.ssm == dir.ssm) // Caso o ssm seja igual ao ssm da parte direita
    {

        sol.primeiroindex = dir.primeiroindex; // A variavel primeiroindex recebe a variavel primeiroindex da parte direita
        sol.ultimoindex = dir.ultimoindex;     // A variavel ultimoindex recebe a variavel ultimoindex da parte direita
    }
    else if (sol.ssm == esq.suf + dir.pref) // Caso o ssm seja igual ao suf da parte esquerda + o pref da parte direita
    {
        // cout << "oi" << endl;
        sol.primeiroindex = esq.primeiroindex; // A variavel primeiroindex recebe a variavel ultimoindex da parte esquerda
        sol.ultimoindex = dir.ultimoindex;     // A variavel ultimoindex recebe a variavel primeiroindex da parte direita
    }

    return sol; // Retorna a classe sol
}

// Função que destroi o vetor de notas
void Rock::DestroiNotas()
{
    notas.resize(0);
}