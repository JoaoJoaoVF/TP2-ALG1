#include "../include/rock.hpp"
#include <algorithm>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void Rock::insereNotas(int pos, double nota)
{
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

void Rock::imprimeDados(Rock resp)
{
    vector<int>::iterator max;
    vector<int>::iterator min;
    max = max_element(resp.PosNotas.begin(), resp.PosNotas.end());
    min = min_element(resp.PosNotas.begin(), resp.PosNotas.end());
    cout << *min << " " << *max << endl;
}

Rock Rock::SSM(Rock festival, int ini, int fim) // alg do prof
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
        sol.PosNotas.emplace_back(ini + 1);
        return sol;
    }
    esq = SSM(festival, ini, meio);
    dir = SSM(festival, meio + 1, fim);
    sol.soma = esq.soma + dir.soma;
    sol.pref = max(esq.pref, esq.soma + dir.pref);
    sol.suf = max(dir.suf, dir.soma + esq.suf);
    sol.ssm = max(esq.ssm, max(dir.ssm, esq.suf + dir.pref));
    if (sol.ssm == esq.ssm)
    {
        sol.PosNotas = esq.PosNotas;
    }
    else if (sol.ssm == dir.ssm)
    {
        sol.PosNotas = dir.PosNotas;
    }
    else
    {
        sol.PosNotas = esq.PosNotas;
        sol.PosNotas.insert(sol.PosNotas.end(), dir.PosNotas.begin(), dir.PosNotas.end());
    }
    return sol;
}

void Rock::DestroiNotas()
{
    notas.resize(0);
}