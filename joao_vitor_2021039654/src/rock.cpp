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

// Retorna o maior valor entre dois numeros
double Rock::max(double a, double b)
{
    if (a > b) // Se a for maior que b
    {
        return a;
    }
    else // Se b for maior que a
    {
        return b;
    }
}

// Realiza a impressao da resposta
void Rock::imprimeDados(Rock resp)
{
    vector<int>::iterator max;                                     // iterador para o maior valor
    vector<int>::iterator min;                                     // iterador para o menor valor
    max = max_element(resp.PosNotas.begin(), resp.PosNotas.end()); // max recebe o iterador para o maior valor
    min = min_element(resp.PosNotas.begin(), resp.PosNotas.end()); // min recebe o iterador para o menor valor
    cout << *min << " " << *max << endl;                           // imprime o menor e o maior valor
}

// Função que verifica se existe empate
int Rock::encontraEmpate(Rock resp)
{
    int Empate = 0; // Valor que indica se existe empate

    auto it = find(notas.begin(), notas.end(), Empate); // it recebe o iterador que aponte se existe empate

    if (it != notas.end()) // caso exista empate

    {
        int index = it - notas.begin(); // index recebe a posição do iterador
        return index + 1;               // retorna a posição do iterador+
    }
    else // caso não exista empate
    {
        return -100001; // Retorna um valor que não é uma posição do vetor
    }
}
Rock Rock::SSM(Rock festival, int ini, int fim)
{
    Rock sol; // A classe sol é a classe que armazena a resposta
    Rock esq; // A classe esq é a classe que armazena a resposta da parte esquerda
    Rock dir; // A classe dir é a classe que armazena a resposta da parte direita

    int meio = (ini + fim) / 2; // Calcula o meio do vetor

    if (ini == fim) // Condição de parada da recursão
    {
        sol.soma = festival.notas[ini];        // A soma recebe a nota do show
        sol.ssm = max(0, festival.notas[ini]); // O ssm recebe o maior valor entre 0 e a nota do show
        sol.suf = sol.ssm;                     // O suf recebe o ssm
        sol.pref = sol.ssm;                    // O pref recebe o ssm
        sol.PosNotas.emplace_back(ini + 1);    // Insere a posição do show no vector de posições

        int possuiEmpate = festival.encontraEmpate(festival); // Verifica se existe empate
        if (possuiEmpate != -100001)                          // Caso exista empate
        {
            sol.PosNotas.emplace_back(possuiEmpate); // Insere a posição empate no vector de posições
        }

        return sol; // Retorna a classe sol
    }
    esq = SSM(festival, ini, meio);                           // Chama a função SSM para a parte esquerda
    dir = SSM(festival, meio + 1, fim);                       // Chama a função SSM para a parte direita
    sol.soma = esq.soma + dir.soma;                           // A soma recebe a soma da parte esquerda + a soma da parte direita
    sol.pref = max(esq.pref, esq.soma + dir.pref);            // O pref recebe o maior valor entre o pref da parte esquerda e a soma da parte esquerda + o pref da parte direita
    sol.suf = max(dir.suf, dir.soma + esq.suf);               // O suf recebe o maior valor entre o suf da parte direita e a soma da parte direita + o suf da parte esquerda
    sol.ssm = max(esq.ssm, max(dir.ssm, esq.suf + dir.pref)); // O ssm recebe o maior valor entre o ssm da parte esquerda, o ssm da parte direita e o suf da parte esquerda + o pref da parte direita

    if (sol.ssm == esq.ssm) // Caso o ssm seja igual ao ssm da parte esquerda
    {
        sol.PosNotas = esq.PosNotas;                                                                             // O vector de posições recebe o vector de posições da parte esquerda
        sol.PosNotas.insert(sol.PosNotas.end(), festival.PosNotasEmpate.begin(), festival.PosNotasEmpate.end()); // Insere no vector de posições o vector de posições de empate
    }
    else if (sol.ssm == dir.ssm) // Caso o ssm seja igual ao ssm da parte direita
    {
        sol.PosNotas = dir.PosNotas;                                                                             // O vector de posições recebe o vector de posições da parte direita
        sol.PosNotas.insert(sol.PosNotas.end(), festival.PosNotasEmpate.begin(), festival.PosNotasEmpate.end()); // Insere no vector de posições o vector de posições de empate
    }
    else // Caso o ssm seja igual ao suf da parte esquerda + o pref da parte direita
    {
        sol.PosNotas = esq.PosNotas;                                                                             // O vector de posições recebe o vector de posições da parte esquerda
        sol.PosNotas.insert(sol.PosNotas.end(), dir.PosNotas.begin(), dir.PosNotas.end());                       // Insere no vector de posições o vector de posições da parte direita
        sol.PosNotas.insert(sol.PosNotas.end(), festival.PosNotasEmpate.begin(), festival.PosNotasEmpate.end()); //  Insere no vector de posições o vector de posições de empate
    }

    return sol; // Retorna a classe sol
}

// Função que destroi o vetor de notas
void Rock::DestroiNotas()
{
    notas.resize(0);
}