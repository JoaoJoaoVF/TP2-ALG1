
#include "../include/rock.hpp"
#include "../include/msgassert.hpp"
using namespace std;

int main()
{
    int A, S;
    Rock resp;
    /*
    while (cin >> A >> S)
    {
        InicializaNotas();
        for (int i = 0; i < A; i++)
        {
            double nota;
            cin >> nota;
            insereNotas(i, nota);
        }
        resp = SSM(notas, 0, A - 1);
        imprimeDados(resp);
        DestroiNotas(notas);
    }
     */
    do
    {
        cin >> A >> S; // Leitura do numero de amigos e de shows

        vector<double> notas(S, 0); // Vetor de notas

        if (A == 0 && S == 0) // Finaliza o programa caso o numero de amigos e de shows seja 0
        {
            break;
        }

        for (int i = 0; i < (A * S); i++) // loop para leitura das notas
        {
            double X; // variavel que armazena a nota

            cin >> X; // leitura das shows

            notas[i % S] += X;
        }

        // imprimeNotas(notas); // Imprime as notas

        resp = SSM(notas, 0, S); // Realiza o SSM e armazena o resultado na classe Rock retorno

        imprimeResposta(resp); // Imprime a resposta

    } while (A != 0 && S != 0); // Enquanto não sao encontradas as condicoes de parada

    return (0);
}