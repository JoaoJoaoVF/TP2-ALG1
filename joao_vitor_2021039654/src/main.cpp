
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

        // Erros garantindo a integridade dos dados
        erroAssert(A >= 1, "É necessário pelo menos um amigo");
        erroAssert(S >= 1, "É necessário pelo menos uma shows");
        erroAssert(A <= 50, "O número de amigos não pode ser maior que 1000");
        erroAssert(S <= 100000, "O número de shows não pode ser maior que 10000");

        // Leitura dos dados de cada show
        for (double i = 0; i < (A * S); i++) // loop para leitura das notas
        {
            double X; // variavel que armazena a nota

            cin >> X; // leitura das shows

            double aux = fmod(i, S); // variavel auxiliar para armazenar o resto da divisao de i por S

            notas[aux] += X; // soma das notas de cada show
        }

        resp = SSM(notas, 0, S - 1); // Realiza o SSM e armazena o resultado na classe Rock retorno

        imprimeResposta(resp); // Imprime a resposta

    } while (A != 0 && S != 0); // Enquanto não sao encontradas as condicoes de parada

    return (0);
}