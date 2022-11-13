#include "../include/rock.hpp"

void imprimeA(vector<double> &A)
{
    for (double i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void imprimeResposta(Rock sol)
{
    cout << sol.primeiroindice + 1 << " " << sol.ultimoindice + 1 << endl;
}

double max(double a, double b)
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

Rock SSM(vector<double> &A, double ini, double fim)
{
    Rock sol;
    Rock esq;
    Rock dir;

    if (ini == fim)
    {
        sol.soma = A[ini];
        sol.ssm = max(0, A[ini]);
        sol.pref = sol.ssm;
        sol.suf = sol.ssm;

        sol.primeiroindice = ini;
        sol.ultimoindice = ini;
        return sol;
    }
    double meio = floor((ini + fim) / 2);

    esq = SSM(A, ini, meio);
    dir = SSM(A, meio + 1, fim);

    sol.soma = esq.soma + dir.soma;                               // A soma recebe a soma da parte esquerda + a soma da parte direita
    sol.ssm = std::max({esq.ssm, dir.ssm, (esq.suf + dir.pref)}); // O ssm recebe o maior valor entre o ssm da parte esquerda, o ssm da parte direita e o suf da parte esquerda + o pref da parte direita
    sol.suf = std::max(dir.suf, dir.soma + esq.suf);              // O suf recebe o maior valor entre o suf da parte direita e a soma da parte direita + o suf da parte esquerda
    sol.pref = std::max(esq.pref, esq.soma + dir.pref);           // O pref recebe o maior valor entre o pref da parte esquerda e a soma da parte esquerda + o pref da parte direita
    /*

        if (esq.soma >= dir.soma && esq.soma >= sol.suf + sol.pref)
        {
            sol.ssm = esq.ssm;
            sol.primeiroindice = esq.primeiroindice;
            sol.ultimoindice = esq.ultimoindice;
        }
        else if (dir.soma >= esq.soma && dir.soma >= sol.suf + sol.pref)
        {
            sol.ssm = dir.ssm;
            sol.primeiroindice = dir.primeiroindice;
            sol.ultimoindice = dir.ultimoindice;
        }
        else // if (sol.suf + sol.pref >= esq.ssm && sol.suf + sol.pref >= dir.ssm)
        {
            sol.ssm = sol.suf + sol.pref;
            sol.primeiroindice = esq.ultimoindice;
            sol.ultimoindice = dir.primeiroindice;
        }
        // else
        // {
        //     cout << "Erro" << endl;
        // }
        // {
        //     sol.soma = sol.pref+;
        //     sol.primeiroindice = esq.ultimoindice;
        //     sol.ultimoindice = dir.primeiroindice;
        // }
    */
    if (sol.ssm == esq.ssm) // Caso o ssm seja igual ao ssm da parte esquerda
    {
        sol.primeiroindice = esq.primeiroindice; // A variavel primeiroindice recebe a variavel primeiroindice da parte esquerda
        sol.ultimoindice = esq.ultimoindice;     // A variavel ultimoindice recebe a variavel ultimoindice da parte esquerda
    }
    else if (sol.ssm == dir.ssm) // Caso o ssm seja igual ao ssm da parte direita
    {

        sol.primeiroindice = dir.primeiroindice; // A variavel primeiroindice recebe a variavel primeiroindice da parte direita
        sol.ultimoindice = dir.ultimoindice;     // A variavel ultimoindice recebe a variavel ultimoindice da parte direita
    }
    else if (sol.ssm == esq.suf + dir.pref) // Caso o ssm seja igual ao suf da parte esquerda + o pref da parte direita
    {
        // cout << "oi" << endl;
        sol.primeiroindice = esq.ultimoindice; // A variavel primeiroindice recebe a variavel ultimoindice da parte esquerda
        sol.ultimoindice = dir.primeiroindice; // A variavel ultimoindice recebe a variavel primeiroindice da parte direita
    }
    return sol;
}