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

    // cin >> amigos >> shows; // Leitura do numero de amigos e de shows
    amigos = 5;
    shows = 246;
    festival.Set_A(amigos); // seta o numero de amigos
    festival.Set_S(shows);  // seta o numero de shows

    if (festival.Get_A() == 0 && festival.Get_S() == 0 || amigos == 4) // Finaliza o programa caso o numero de amigos e de shows seja 0
    {
      break;
    }

    // Erros garantindo a integridade dos dados
    erroAssert(festival.Get_A() >= 1, "É necessário pelo menos um amigo");
    erroAssert(festival.Get_S() >= 1, "É necessário pelo menos uma shows");
    erroAssert(festival.Get_A() <= 50, "O número de amigos não pode ser maior que 1000");
    erroAssert(festival.Get_S() <= 100000, "O número de shows não pode ser maior que 10000");

    festival.InicializaNotas(); // inicializa o vector de notas com 0 em todas as posições
                                /*
                                    for (int i = 0; i < (festival.Get_A() * festival.Get_S()); i++) // loop para leitura das notas
                                    {
                                      double X; // variavel que armazena a nota
                            
                                      cin >> X; // leitura das shows
                            
                                      // if (i % festival.Get_S() == 11 || i % festival.Get_S() == 12) // Erro garantindo a integridade dos dados
                                      // {
                                      //   cout << X << "";
                                      // }
                                      // cout << endl;
                                      festival.insereNotas(i % festival.Get_S(), X); // Insere as notas no vector
                                    }
                                    */
    festival.notas = {-15.9, -0.3, -10.4, -3.3, 14.9, -6.1, -12.1, -10.3, 9.4, 17.4, 3.9, 5, -4.3, -29.3, -3.1, -18.8, 12.1, -2.8, -7, 11.1, 18, -16.3, 3.9, -14.4, -1.9, 1, -11.9, -2.7, 14, 5.7, -6.9, 0.3, -23.1, -28.4, -19.3, -5.4, -4.4, -2.6, 25.9, -0.7, -22.6, 1, -19.3, -5.5, -10.3, -8.1, 14.9, -9.4, -2.1, 29.7, 1.6, 34.3, -27.3, 23.2, 2.2, -2.5, -6.7, 10.1, 28.1, 12, 22.3, 6.2, 5.6, 11.6, -15.2, 15.1, -12.8, -0.3, -25.1, 2, 13.6, -15.7, -12.1, 11, -7.6, 3.1, -20.3, -2.5, 1.8, -7.7, -10, 6.4, 15, -8, 0.4, -6.8, 6.3, -12.7, 16.4, -11.3, 9.9, 27.3, 0.9, -18.9, -15.8, -11.4, 13.6, -26.7, -7.9, -25, -9.6, -0.8, 18, -37.1, -2.5, -5, 20.7, 8.4, 6.4, -34.1, 1.5, -10.4, 7.1, 18.6, 16.1, -6.1, -29.5, 12, -8, 15.3, -16, -19.6, 23, 5.2, 18, -4.1, 10.2, -9.2, 3.5, 26.5, -6.6, -18.5, -1.7, 7.6, -2.6, 5.5, -15.2, 32.5, 15.6, -24.8, -3.6, 25.5, -25.9, 26.1, -15.1, 28, 5.1, 2, 6.9, 1.7, 9.1, 3.3, 1.1, 23, -1.2, -14.3, -8.6, 5.6, -21.8, -3.3, -8.9, -2, 21.2, -10.8, 15.4, -3.6, -12.9, 10.6, 18.8, -0.8, -9.5, 11.3, -15.8, -1.2, -34.3, -10.5, -3.1, -12.3, 5.9, -7.5, -2.8, 5.4, 1.2, -22.1, 5.2, 4.4, -7.8, 8.3, -11, 21.5, -11.2, 3.8, -12.2, -15.9, 10.8, -20.2, 16.7, 29.2, -15.7, -1.4, -11.4, -1.7, -0.8, 6.6, 0.7, 8.3, 10.1, 4.3, 12, -4.1, 10.8, 14, -1.4, 14.3, -7.8, 14.8, 7.1, -12.8, -2.3, 19.3, -6.5, 12.1, -7.7, 30.5, 20, 0.1, 6.3, 1.5, -9.1, -9.3, -12.1, 10.2, -15, -5, -11.4, -1.3, 13.9, 3.4, -19.2, -34.8, 18.4, -11.7, -6.1, -14.9, 19.3, -0.9};
    // festival.imprimeNotas();
    retorno = festival.SSM(festival, 0, festival.Get_S()); // Realiza o SSM e armazena o resultado na classe Rock retorno
    cout << endl;
    // cout << endl;
    // cout << endl;
    festival.imprimeDados(retorno); // Imprime a resposta

    festival.DestroiNotas(); // Destroi o vector de notas e coloca o tamanho dele como 0
    amigos = 0;
    shows = 0;
  } while (festival.Get_A() != 0 && festival.Get_S() != 0); // Enquanto não sao encontradas as condicoes de parada

  return (0);
}