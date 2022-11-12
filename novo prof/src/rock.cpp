#include "../include/rock.hpp"

void imprimeNotas(vector<double> &notas)
{
    for (int i = 0; i < notas.size(); i++)
    {
        cout << notas[i] << " ";
    }
    cout << endl;
}