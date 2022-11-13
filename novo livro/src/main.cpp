
#include "../include/rock.hpp"
#include "../include/msgassert.hpp"
using namespace std;

int main()
{
    double A, S;
    Rock resp;

    do
    {
        cin >> A >> S; // Leitura do numero de amigos e de shows

        vector<double> notas(S, 0); // Vetor de notas

        if (A == 0 && S == 0) // Finaliza o programa caso o numero de amigos e de shows seja 0
        {
            break;
        }

        // Leitura dos dados de cada show
        // for (double i = 0; i < (A * S); i++) // loop para leitura das notas
        for (double i = 0; i < A; i++)
        {
            for (double j = 0; j < S; j++)

            {
                double X; // variavel que armazena a nota

                cin >> X; // leitura das shows

                // double aux = fmod(j, S); // variavel auxiliar para armazenar o resto da divisao de i por S

                notas[j] += X;
            }
        }
        // imprimeA(notas); // Imprime as notas

        resp = SSM(notas, 0, S); // Realiza o SSM e armazena o resultado na classe Rock retorno

        imprimeResposta(resp);  // Imprime a resposta
    } while (A != 0 && S != 0); // Enquanto não sao encontradas as condicoes de parada

    return (0);
}