#include <iostream>
#include <map>
#include <string>
#include <vector>
#include "../include/rock.hpp"
#include "../include/msgassert.hpp"
using namespace std;

int main()
{
  // inicializa a classe Rock
  Rock festival;
  Rock retorno;

  /*
    A representa a quantidade de amigos
    S representa a quantidade de shows
  */
  int amigos, shows;

  do
  {
    // Leitura do numero de amigos e de shows
    cin >> amigos >> shows;

    festival.Set_A(amigos);
    festival.Set_S(shows);

    // Finaliza o programa caso o numero de amigos e de shows seja 0
    if (festival.Get_A() == 0 && festival.Get_S() == 0)
    {
      break;
    }

    // Erros garantindo a integridade dos dados
    erroAssert(festival.Get_A() >= 1, "É necessário pelo menos um seguidor");
    erroAssert(festival.Get_S() >= 1, "É necessário pelo menos uma proposta");
    erroAssert(festival.Get_A() <= 50, "O número de seguidores não pode ser maior que 1000");
    erroAssert(festival.Get_S() <= 100000, "O número de propostas não pode ser maior que 10000");

    festival.InicializaNotas();

    // loop para leitura das notas
    for (int i = 0; i < festival.Get_A() * festival.Get_S(); i++)
    {
      // variavel que armazena a nota
      double X;

      // leitura das propostas
      cin >> X;

      // Insere as notas no vector
      festival.insereNotas(i % festival.Get_S(), X);
    }

    // Impressao das notas
    festival.imprimeNotas();
    cout << endl;

    // festival.SSM_INTERATIVO(0, festival.Get_S());
    retorno = festival.SSM(festival, 0, festival.Get_S());
    festival.imprimeDados(retorno);

    cout << endl;
    cout << endl;

    // Destroi o vector de notas e coloca o tamanho dele como 0
    festival.DestroiNotas();

  } while (festival.Get_A() != 0 && festival.Get_S() != 0);

  return (0);
}