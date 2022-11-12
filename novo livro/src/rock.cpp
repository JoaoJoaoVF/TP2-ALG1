#include "../include/rock.hpp"

void imprimeA(vector<double> &A)
{
    for (long unsigned int i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void imprimesolosta(Rock sol)
{
    cout << sol.primeiroindex + 1 << " " << sol.ultimoindex + 1 << endl;
}

Rock SSM2(vector<double> &A, int low, int mid, int high)
{
    Rock sol;
    sol.sumleft = -1000000000;
    sol.sumright = -1000000000;
    sol.sum = 0;

    for (int i = mid; i >= low; i--)
    {
        sol.sum += A[i];
        if (sol.sum > sol.sumleft)
        {
            sol.sumleft = sol.sum;
            sol.primeiroindex = i;
        }
    }

    sol.sum = 0;
    for (int j = mid + 1; j <= high; j++)
    {
        sol.sum += A[j];
        if (sol.sum > sol.sumright)
        {
            sol.sumright = sol.sum;
            sol.ultimoindex = j;
        }
    }

    sol.sum = sol.sumleft + sol.sumright;
    return sol;
}

Rock SSM(vector<double> &A, int low, int high)
{
    Rock sol;
    Rock left;
    Rock right;
    Rock cross;

    if (low == high)
    {
        sol.sum = A[low];
        sol.primeiroindex = low;
        sol.ultimoindex = low;
        return sol;
    }
    else
    {
        int mid = (low + high) / 2;

        left = SSM(A, low, mid);
        right = SSM(A, mid + 1, high);
        cross = SSM2(A, low, mid, high);

        if (left.sum >= right.sum && left.sum >= cross.sum)
        {
            sol.sum = left.sum;
            sol.primeiroindex = left.primeiroindex;
            sol.ultimoindex = left.ultimoindex;
        }
        else if (right.sum >= left.sum && right.sum >= cross.sum)
        {
            sol.sum = right.sum;
            sol.primeiroindex = right.primeiroindex;
            sol.ultimoindex = right.ultimoindex;
        }
        else
        {
            sol.sum = cross.sum;
            sol.primeiroindex = cross.primeiroindex;
            sol.ultimoindex = cross.ultimoindex;
        }
    }
    return sol;
}