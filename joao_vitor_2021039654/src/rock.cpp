#include "../include/rock.hpp"
using namespace std;

void test()
{

    std::cout << "Funciona!";
}

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
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
}

Rock Rock::SSM(int ini, int fim)
{
    Rock sol;
    Rock esq;
    Rock dir;

    if (ini == fim)
    {
        sol.soma = notas[ini];
        sol.ssm = max(0, notas[ini]);
        sol.suf = ssm;
        sol.pref = ssm;
        return sol;
    }
    esq = SSM(ini, (ini + fim) / 2);
    dir = SSM((ini + fim) / 2 + 1, fim);
    soma = esq.soma + dir.soma;
    pref = max(esq.pref, esq.soma + dir.pref);
    suf = max(dir.suf, dir.soma + esq.suf);
    return sol;
}

void Rock::imprimeDados(Rock resp)
{
    cout << resp.ssm << " " << resp.soma << endl;
}