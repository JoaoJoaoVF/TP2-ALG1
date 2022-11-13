#include "../include/rock.hpp"

// Realiza a impressao dos indices da resposta
void imprimeResposta(Rock sol)
{
    cout << sol.primeiro_indice + 1 << " " << sol.ultimo_indice + 1 << endl;
}

// SSM dos elementos que cruzam o meio do vetor
Rock SSM_Cruzado(vector<double> &notas, double ini, double meio, double fim)
{
    Rock sol;
    sol.soma_esq = -1000000000000000000; // Inicializa a soma_esq com um valor proximo ao infinito
    sol.soma_dir = -1000000000000000000; // Inicializa a soma_dir com um valor proximo ao infinito
    sol.soma = 0;

    for (double i = meio; i >= ini; i--) // loop para encontrar a soma_esq
    {
        sol.soma += notas[i];

        if (sol.soma >= sol.soma_esq)
        {
            sol.soma_esq = sol.soma;
            sol.primeiro_indice = i;
        }
    }

    sol.soma = 0;

    for (double j = meio + 1; j <= fim; j++) // loop para encontrar a soma_dir
    {
        sol.soma += notas[j];

        if (sol.soma >= sol.soma_dir)
        {
            sol.soma_dir = sol.soma;
            sol.ultimo_indice = j;
        }
    }

    sol.soma = sol.soma_esq + sol.soma_dir; // soma das somas_esq e somas_dir

    return sol;
}

// SSM dos elementos do vetor
Rock SSM(vector<double> &notas, double ini, double fim)
{
    Rock sol;
    Rock esq;
    Rock dir;
    Rock cruzado;

    if (ini == fim) // condicao de parada
    {
        sol.soma = notas[ini];
        sol.primeiro_indice = ini;
        sol.ultimo_indice = ini;
        return sol;
    }
    else
    {
        double meio = floor((ini + fim) / 2);

        esq = SSM(notas, ini, meio);
        dir = SSM(notas, meio + 1, fim);
        cruzado = SSM_Cruzado(notas, ini, meio, fim);

        if (esq.soma >= dir.soma && esq.soma >= cruzado.soma) // caso o ssm esteja na posicao esquerda do vetor
        {
            sol.soma = esq.soma;
            sol.primeiro_indice = esq.primeiro_indice;
            sol.ultimo_indice = esq.ultimo_indice;
        }
        else if (dir.soma >= esq.soma && dir.soma >= cruzado.soma) // caso o SSM esteja na posicao direita do vetor
        {
            sol.soma = dir.soma;
            sol.primeiro_indice = dir.primeiro_indice;
            sol.ultimo_indice = dir.ultimo_indice;
        }
        else // caso o SSM esteja cruzando o meio do vetor
        {
            sol.soma = cruzado.soma;
            sol.primeiro_indice = cruzado.primeiro_indice;
            sol.ultimo_indice = cruzado.ultimo_indice;
        }
    }

    return sol;
}
