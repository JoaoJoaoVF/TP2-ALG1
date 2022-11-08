#include "../include/rock.hpp"
using namespace std;

void Rock::insereNotas(int pos, double nota)
{
    // cout << notas.size() << endl;
    notas[pos] += nota;
}

void Rock::imprimeNotas()
{
    for (int i = 0; i < notas.size(); i++)
    {
        cout << notas[i] << " ";
    }
}

void Rock::InicializaNotas()
{
    for (int i = 0; i < Get_S(); i++)
    {
        notas.emplace_back(0);
    }
}

void Rock::DestroiNotas()
{
    notas.resize(0);
}

// Algorith Max cross subarray
void Rock::SSM_INTERATIVO(int ini, int fim)
{
    int meio = (ini + fim) / 2;
    int i = meio;
    int j = meio + 1;
    double soma = 0;
    double somaEsq = 0;
    double somaDir = 0;
    double maior = 0;

    // Soma da esquerda
    for (i = meio; i >= ini; i--)
    {
        soma += notas[i];
        if (soma > somaEsq)
        {
            somaEsq = soma;
        }
    }

    // Soma da direita
    soma = 0;
    for (j = meio + 1; j <= fim; j++)
    {
        soma += notas[j];
        if (soma > somaDir)
        {
            somaDir = soma;
        }
    }

    // Maior soma
    maior = somaEsq + somaDir;

    // Impressao da maior soma
    cout << maior << " ";
}

double Rock::max(double a, double b)
{
    // cout << a << " " << b << endl;
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

// Rock Rock::SSM(Rock festival, int ini, int fim)
// {

//     if (ini == fim)
//     {
//         soma = festival.notas[ini];
//         ssm = max(0, festival.notas[ini]);
//         suf = ssm;
//         pref = ssm;
//         return sol;
//     }
//     esq = SSM(festival, ini, (ini + fim) / 2);
//     dir = SSM(festival, (ini + fim) / 2 + 1, fim);
//     soma = esq->soma + dir->soma;
//     pref = max(esq->pref, esq->soma + dir->pref);
//     suf = max(dir->suf, dir->soma + esq->suf);
//     return sol;
// }

void Rock::imprimeDados(Rock resp)
{
    cout << resp.ssm << endl;
}

// Algorith Max cross subarray recursive
Rock Rock::SSM(Rock festival, int ini, int fim)
{
    Rock sol;
    Rock esq;
    Rock dir;
    int meio = (ini + fim) / 2;
    if (ini == fim)
    {
        sol.soma = festival.notas[ini];
        sol.ssm = max(0, festival.notas[ini]);
        sol.suf = sol.ssm;
        sol.pref = sol.ssm;
        return sol;
    }
    esq = SSM(festival, ini, meio);
    dir = SSM(festival, meio + 1, fim);
    sol.soma = esq.soma + dir.soma;
    sol.pref = max(esq.pref, esq.soma + dir.pref);
    sol.suf = max(dir.suf, dir.soma + esq.suf);
    sol.ssm = max(esq.ssm, max(dir.ssm, esq.suf + dir.pref));
    return sol;
}