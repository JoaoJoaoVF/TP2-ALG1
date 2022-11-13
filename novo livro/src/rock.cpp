#include "../include/rock.hpp"

void imprimeA(vector<double> &A)
{
    for (double i = 0; i < A.size(); i++)
    {
        cout << A[i] << " ";
    }
    cout << endl;
}

void imprimeResposta(Rock sol)
{
    cout << sol.firstindex + 1 << " " << sol.lastindex + 1 << endl;
}

Rock SSM2(vector<double> &A, double low, double mid, double high)
{
    Rock sol;
    sol.sumleft = -1000000000;
    sol.sumright = -1000000000;
    sol.sum = 0;

    for (double i = mid; i >= low; i--)
    {
        sol.sum += A[i];
        if (sol.sum >= sol.sumleft)
        {
            sol.sumleft = sol.sum;
            sol.firstindex = i;
        }
    }

    sol.sum = 0;
    for (double j = mid + 1; j <= high; j++)
    {
        sol.sum += A[j];
        if (sol.sum >= sol.sumright)
        {
            sol.sumright = sol.sum;
            sol.lastindex = j;
        }
    }

    sol.sum = sol.sumleft + sol.sumright;
    return sol;
}

Rock SSM(vector<double> &A, double low, double high)
{
    Rock sol;
    Rock left;
    Rock right;
    Rock cross;

    if (low == high)
    {
        sol.sum = A[low];
        sol.firstindex = low;
        sol.lastindex = low;
        return sol;
    }
    else
    {
        double mid = floor((low + high) / 2);

        left = SSM(A, low, mid);
        right = SSM(A, mid + 1, high);
        cross = SSM2(A, low, mid, high);

        if (left.sum >= right.sum && left.sum >= cross.sum)
        {
            sol.sum = left.sum;
            sol.firstindex = left.firstindex;
            sol.lastindex = left.lastindex;
        }
        else if (right.sum >= left.sum && right.sum >= cross.sum)
        {
            sol.sum = right.sum;
            sol.firstindex = right.firstindex;
            sol.lastindex = right.lastindex;
        }
        else
        {
            sol.sum = cross.sum;
            sol.firstindex = cross.firstindex;
            sol.lastindex = cross.lastindex;
        }
    }
    return sol;
}

void apagaNotas(vector<double> &A)
{
    A.clear();
}