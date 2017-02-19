/******************************************************************************
 ***** File Name : Matrix.cpp
 **** Created By : kyaz758
 *** Description :
 * Creation Date : 2017-02-15 14:58
 * Last Modified : 2017-02-17 17:11
 ******************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;
/*
template<typename Type>
Type MatrixChain(Type *p, int i, int j, Type **m)
{
    num += 1;
    if (i == j)
        return 0;
    Type min = MatrixChain(p,i,i) + MatrixChain(p,i+1,j) + p[i-1]*p[i]*p[j];
    for (int k=i+1; k<j; ++k)
    {
        Type t = MatrixChain(p,i,k) + MatrixChain(p,k+1,j) + p[i-1]*p[k]*p[j];
        if (min > t)
            min = t;
    }
    return min;
}

#define MSIZE 6
int num = 0;

template<typename Type>
Type MatrixChain(Type *p, int i, int j, Type **m)
{
    num += 1;
    if (i == j)
        return 0;
    if (m[i][j] > 0)
        return m[i][j];
    m[i][j] = MatrixChain(p,i,i,m) + MatrixChain(p,i+1,j,m) + p[i-1]*p[i]*p[j];
    for (int k=i+1; k<j; ++k)
    {
        Type t = MatrixChain(p,i,k,m) + MatrixChain(p,k+1,j,m) + p[i-1]*p[k]*p[j];
        if ( > t)
             = t;
    }
    return min;
}

void MatrixChainT(int n)
{
    for (int j=1; j<n; ++j)
    {
        for (int i=1; i<n; ++i)
        {
            //cout << i << " " << i+j << "  ";
            for (int k=i; k<=i+j&&i+j<=n; ++k)
            {
                cout << k << " "; 
            }
            cout << "    ";
        }
        cout << endl;
    }
}

int main()
{
    MatrixChainT(6);
    return 0;
}

#define MSIZE 6
int num = 0;

template<typename Type>
void MatrixChain(Type *p, int n, Type **m, int **a)
{
    for (int s=2; s<=n; ++s)
    {
        for (int i=1; i<=n-s+1; ++i)
        {
            int j = i+s-1;
            m[i][j] = m[i][i]+m[i+1][j]+p[i-1]*p[i]*p[j];
            for (int k=i; k<j; ++k)
            {
                Type t = m[i][k]+m[k][j]+p[i-1]*p[k]*p[j];
                if (m[i][j] > t)
                    m[i][j] = t;
            }
        }
        cout << endl;
    }
}

void Traceback(int **s, int i, int j)
{
    if (i != j)
    {
        Traceback(s, i, s[i][j]);
        Traceback(s, s[i][j]+1, j);
        cout << "A: " << i << " And " << s[i][j] << " + " ;
        cout << "A: " << s[i][j]+1 << " And " << j << endl;
    }
}
*/
#include <string.h>

int Max(int a, int b)
{
    return a>b?a:b;
}

void Print2Array(int **p, int n, int m)
{
    for (int i=0; i<n; ++i)
    {
        for (int j=0; j<m; ++j)
            cout << p[i][j];
        cout << endl;
    }
    cout << endl;
}

int LCSLengthEx(char *X, char *Y, int n, int m, int **c, int **s)
{
    for (int i=0; i<=n; ++i) c[0][i] = 0;
    for (int i=0; i<=m; ++i) c[i][0] = 0;
    for (int i=1; i<=m; ++i)
    {
        for (int j=1; j<=n; ++j)
        {
            if (X[i] == Y[j])
            {
                c[i][j] = c[i-1][j-1]+1;
                s[i][j] = 1;
            }
            else if (c[i-1][j] > c[i][j-1])
            {
                c[i][j] = c[i-1][j];
                s[i][j] = 2;
            }
            else
            {
                c[i][j] = c[i][j-1];
                s[i][j] = 3;
            }
        }
    }
    return c[m][n];
}

int LCSLength(char *X, char *Y, int i, int j, int **c, int **s)
{
    if (i==0 || j==0) 
        return 0;
    if (c[i][j] > 0) return c[i][j];
    if (i>0 && j>0) 
    {
        if (X[i] == Y[j])
        {
            c[i-1][j-1] = LCSLength(X, Y, i-1, j-1, c, s);
            s[i][j] = 1;
            return c[i-1][j-1] + 1;
        }
        else
        {
            /*
            c[i][j-1] = LCSLength(X, Y, i, j-1, c);
            c[i-1][j] = LCSLength(X, Y, i-1, j, c);
            return Max(c[i][j-1], c[i-1][j];
            */
            int max1 = LCSLength(X, Y, i, j-1, c, s);
            int max2 = LCSLength(X, Y, i-1, j, c, s);
            //c[i][j] = Max(max1, max2);
            if (max1 > max2)
            {
                s[i][j] = 2;
                c[i][j] = max1;
            }
            else
            {
                s[i][j] = 3;
                c[i][j] = max2;
            }
            return c[i][j];
        }
    }
    else
        return -1;
}

void TrackBack(char *X, int **s, int i, int j)
{
    if (i==0 || j==0)
        return ;
    /*
    while (s[i][j] != 0)
    {
        switch (s[i][j])
        {
            case 1:
                cout << X[i] << " ";
                i--;
                j--;
                break;
            case 2:
                i--;
                break;
            case 3:
                j--;
                break;
            default:
                break;
    }
    */
    switch (s[i][j])
    {
        case 1:
            cout << X[i] << " ";
            TrackBack(X, s, i-1, j-1);
        case 2:
            TrackBack(X, s, i, j-1);
        //case 3:
        default:
            TrackBack(X, s, i-1, j);
}

int main()
{
    char X[] = {"#ABCBDAB"};
    char Y[] = {"#BDCABA"};
    int xsize = strlen(X)-1;
    int ysize = strlen(Y)-1;
    int **m = Get2Array(xsize+1, ysize+1);
    Print2Array(**m);
    int maxlen = LCSLength(X, Y, xsize, ysize);
    return 0;
}




