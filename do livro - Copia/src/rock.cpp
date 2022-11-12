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

// Realiza a impressão das notas
void Rock::imprimeNotas()
{
    for (int i = 0; i < notas.size(); i++)
    {
        cout << notas[i] << " ";
    }
}

// Realiza a impressao da resposta
void Rock::imprimeDados(Rock resp)
{
    cout << resp.primeiroindex + 1 << " " << resp.ultimoindex + 1 << endl;
}

Rock Rock::SSMM(vector<double> notas, int ini, int meio, int fim)
{
    Rock cruzado; // Objeto que armazena o resultado do cruzamento

    cruzado.somaesq = -10000000; // Inicializa a soma com 0
    double sum = 0;              // Inicializa a soma com 0

    for (int i = meio; i >= ini; i--) // Percorre o vetor da direita para a esquerda
    {
        sum += notas[i];  // Soma o valor da posição i com a soma
        if (sum > cruzado.somaesq) // Se a soma for maior que a soma da esquerda
        {
            cruzado.somaesq = sum;     // A soma da esquerda recebe a soma
            cruzado.primeiroindex = i; // A posição da esquerda recebe a posição i
        }
    }

    cruzado.somadir = -10000000;          // Inicializa a soma com 0
    sum = 0;                              // Inicializa a soma com 0
    for (int j = meio + 1; j <= fim; j++) // Percorre o vetor da esquerda para a direita
    {
        sum += notas[j];  // Soma o valor da posição i com a soma
        if (sum > cruzado.somadir) // Se a soma for maior que a soma da direita
        {
            cruzado.somadir = sum;   // A soma da direita recebe a soma
            cruzado.ultimoindex = j; // A posição da direita recebe a posição i
        }
    }
    cruzado.soma = cruzado.somaesq + cruzado.somadir;
    return cruzado; // Retorna o cruzado
}

Rock Rock::SSM(vector<double> notas, int ini, int fim)
{
    Rock sol;     // A classe sol é a classe que armazena a resposta
    Rock esq;     // A classe esq é a classe que armazena a resposta da parte esquerda
    Rock dir;     // A classe dir é a classe que armazena a resposta da parte direita
    Rock cruzado; // A classe cruzado é a classe que armazena a resposta do cruzamento

    int meio = (ini + fim) / 2; // Calcula o meio do vetor

    if (ini == fim)
    {
        sol.primeiroindex = ini;
        sol.ultimoindex = fim;
        sol.soma = notas[ini]; // A soma recebe a nota do show

        return sol;
    }
    else
    {
        esq = SSM(notas, ini, meio); // Chama a função SSM para a parte esquerda

        dir = SSM(notas, meio + 1, fim); // Chama a função SSM para a parte direita

        cruzado = SSMM(notas, ini, meio, fim);

        if (esq.soma >= dir.soma && esq.soma >= cruzado.soma)
        {
            sol.soma = esq.soma;
            sol.primeiroindex = esq.primeiroindex;
            sol.ultimoindex = esq.ultimoindex;
        }
        else if (dir.soma >= esq.soma && dir.soma >= cruzado.soma)
        {
            sol.soma = dir.soma;
            sol.primeiroindex = dir.primeiroindex;
            sol.ultimoindex = dir.ultimoindex;
        }
        else
        {
            sol.soma = cruzado.soma;
            sol.primeiroindex = cruzado.primeiroindex;
            sol.ultimoindex = cruzado.ultimoindex;
        }
    }
    return sol; // Retorna a classe sol
}

// Função que destroi o vetor de notas
void Rock::DestroiNotas()
{
    notas.resize(0);
}
