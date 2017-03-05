
#include <iostream>
using namespace std;

#define SIZE 5

template<typename Type>
Type Get2Array(int i, int j);


template<typename Type>
Type Knapsack(Type V[], Type W[], int i, int n, int c)
{
    if (i == n)
    {
        if (c >= W[i]) return V[i];
        else return 0;
    }
    else 
    {
        if (c < W[i])
            return Knapsack(V, W, i+1, n, c);
        else 
        {
            int max1 = Knapsack(V, W, i+1, n, c);
            int max2 = Knapsack(V, W, i+1, n, c-W[i]) + V[i];
            return max1>max2?max1:max2;
        }
    }
}

template<typename Type>
Type Max(const Type & a, const Type & b)
{
    return a>b?a:b;
}

template<typename Type>
Type Knapsack(Type V[], Type W[], int **m, int n, int c)
{
    for (int j=1; j<=c; ++j)
    {
        if (j < W[n]) m[n][j] = 0;
        else m[n][j] = V[n];
    }
    for (int i=n-1; i>=1; --i)
    {
        for (int j=1; j<=c; ++j)
        {
            if (j < W[i]) 
                m[i][j] = m[i+1][j];
            else 
            {
                m[i][j] = Max(m[i+1][j], m[i+1][j-W[i]]+V[i]);
            }
        }
    }
}

int main()
{
    int c = 10;
    int W[SIZE+1] = {0, 2, 2, 6, 5, 4};
    int V[SIZE+1] = {0, 6, 3, 5, 4, 6};
    int maxv = Knapsack(V, W, 1, SIZE, c);
    cout << maxv << endl;
    return 0;
}

void TrackBack(int **m, int n, int c, int X[], int W[])
{
    int i=1; 
    for (; i<n; ++i)
    {
        if (m[i][c] != m[i+1][c])
        {
            X[i] = 1;
            c -= W[i];
        }
    }
    if (m[i][c] != 0)
    {
        X[i] = 1;
    }
}

/*
if (wi >c)
{
    m(i+1, c);
}
else 
{
    Max(m(i+1, c-wi) + vi, m(i+1, c));
}
*/

