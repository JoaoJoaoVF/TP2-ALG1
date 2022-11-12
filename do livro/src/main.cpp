#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "../include/rock.hpp"
#include "../include/msgassert.hpp"
using namespace std;

int main()
{

  Rock festival; // inicializa a classe Rock que representa o festival
  Rock retorno;  // inicializa a classe Rock que armazena o retorno da funcao SSM

  /*
    A representa a quantidade de amigos
    S representa a quantidade de shows
  */
  int amigos, shows;

  do
  {

    cin >> amigos >> shows; // Leitura do numero de amigos e de shows

    festival.Set_A(amigos); // seta o numero de amigos
    festival.Set_S(shows);  // seta o numero de shows

    if (festival.Get_A() == 0 && festival.Get_S() == 0) // Finaliza o programa caso o numero de amigos e de shows seja 0
    {
      break;
    }

    // Erros garantindo a integridade dos dados
    erroAssert(festival.Get_A() >= 1, "É necessário pelo menos um amigo");
    erroAssert(festival.Get_S() >= 1, "É necessário pelo menos uma shows");
    erroAssert(festival.Get_A() <= 50, "O número de amigos não pode ser maior que 1000");
    erroAssert(festival.Get_S() <= 100000, "O número de shows não pode ser maior que 10000");

    festival.InicializaNotas(); // inicializa o vector de notas com 0 em todas as posições

    for (int i = 0; i < (festival.Get_A() * festival.Get_S()); i++) // loop para leitura das notas
    {
      double X; // variavel que armazena a nota

      cin >> X; // leitura das shows

      festival.insereNotas(i % festival.Get_S(), X); // Insere as notas no vector
    }

    retorno = festival.SSM(festival, 0, festival.Get_S()); // Realiza o SSM e armazena o resultado na classe Rock retorno
    festival.imprimeDados(retorno);                        // Imprime a resposta

    festival.DestroiNotas(); // Destroi o vector de notas e coloca o tamanho dele como 0

  } while (festival.Get_A() != 0 && festival.Get_S() != 0); // Enquanto não sao encontradas as condicoes de parada
  cout << endl;

  return (0);
}