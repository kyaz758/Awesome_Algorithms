/******************************************************************************
 ***** File Name : QuickSort.cpp
 **** Created By : kyaz758
 *** Description :
 * Creation Date : 2017-02-08 19:33
 * Last Modified : 2017-02-10 18:36
 ******************************************************************************/

#include <iostream>
#include <iomanip>
#include <cstdlib>
using std::cin;
using std::cout;
using std::endl;
using std::setw;

template<typename Type>
void Swap(Type a, Type b)
{
    Type c = 0;
    c = a;
    a = b;
    b = c;
}

template<typename Type>
void Array_Print(Type *ar, int n)
{
    for (int i=0; i<n; ++i)
    {
        cout << setw(3) << ar[i] << " ";
    }
    cout << endl;
}

template<typename Type>
int Partition(Type *ar, int left, int right)
{
    int i = left;
    int j = right;
    Type x = ar[left];
    while (i < j)
    {
        while (i<j && ar[j]>=x)  --j;
        if (i < j)
            ar[i] = ar[j];
        while (i<j && ar[i]<=x)  ++i;
        if (i < j)
            ar[j] = ar[i];
    }
    ar[i] = x;
    return i;
}

//随机划分法
/*
template<typename Type>
void RandPartition(Type *ar, int left, int right)
{
    srand(time());
    int pos = (rand()%(right-left+1)) + left;
    Swap(ar[left], ar[pos]);
    return Partition(ar, left, right);
}
*/

template<typename Type>
void Quick(Type *ar, int left, int right)
{
    if (left == right)
        return ;
    int mid = Partition(ar, left, right);
    Quick(ar, left, mid-1);
    Quick(ar, mid+1, right);
}

template<typename Type>
void QuickSort(Type *ar, int n)
{
    Quick(ar, 0, n-1);
}

//海量数据处理
template<typename Type>
Type SelectK(Type *ar, int left, int right, int k)
{
    if (left==right && k==1)
        return ar[left];
    int mid = Partition(ar, left, right); 
    int i = mid - left + 1;
    if (mid > k)
        return SelectK(ar, left, mid, k);
    else 
        return SelectK(ar, mid+1, right, k-i);
}

template<typename Type>
Type SelectKMin(Type *ar, int n, int k)
{ 
    return SelectK(ar, 0, n-1, k);
}

#define MAXINT 0x7fffffff
template<typename Type>
bool Cpair(Type *ar, int n, Type &d)
{
    bool res = false;
    if (n < 2)
    {
        d = MAXINT;
        res = false;
    }
    Type d1, d2;
    Type m = SelectKMin(ar, n, n/2);
    res = Cpair(ar, k, d1);
    res = Cpair(ar+k, k, d2);
    Type p = 
    Type q = 
    Type br[] = {d1, d2, q-p};
    d = SelectKMin(br, 3, 1);
        return true;
    }
}

template<typename Type>
bool Cpair1(Type *ar, int n, Type &d)
{
}

int main()
{
    int ar[] = {56, 78, 90, 12, 23, 100, 34, 45, 89, 18, 67};
    int n = sizeof(ar) / sizeof(ar[0]);
 
    return 0;
}
/*
//循环赛日程表

template<typename Type>
void Array_Print(Type *ar, int n)
{
    for (int i=0; i<n; ++i)
    {
        cout << setw(3) << ar[i] << " ";
    }
    cout << endl;
}

template<typename Type>
void Merge(Type *ds, Type *is, int left, int m, int right)
{
    int i = left, j = m+1;
    int k = left;
    while (i<=m && j<=right)
    {
        ds[k++] = is[i] < is[j] ? is[i++] : is[j++];
    }
    while (i <= m)
    {
        ds[k++] = is[i++];
    }
    while (j <= right)
    {
        ds[k++] = is[j++];
    }
}
/*
template<typename Type>
void Array_Copy(Type *ds, Type *ar, int left, int right)
{
    for (int i=left; i<=right; ++i)
    {
        ds[i] = ar[i];
    }
}

template<typename Type>
void MergePass(Type *ds, Type *is, int left, int right)
{
    if (left < right)
    {
        int mid = (right-left)/2 + left;
        MergePass(ds, is, left, mid);
        MergePass(ds, is, mid+1, right);
        Merge(ds, is, left, mid, right);
        Array_Copy(is, ds, left, right);
    }
}

template<typename Type>
void MergeSort(Type *ar, int n)
{
    Type *ds = new Type[n];
    MergePass(ds, ar, 0, n-1);
    delete []ds;
}

template<typename Type>
void MergePass(Type *ds, Type *ar, int s, int n)
{
    int i = 0;
    for ( ; i<n; i+=2*s)
    {
        Merge(ds, ar, i, i+s-1, i+2*s-1);
    }
    if (n-1-i > s)
    {
        Merge(ds, ar, i, i+s-1, n-1);
    }
    else
    {
        for ( ; i<n; ++i)
        {
            ds[i] = ar[i];
        }
    }
}

template<typename Type>
void MergeSort(Type *ar, int n)
{
    Type *ds = new Type[n];
    int s = 1;
    while (s < n)
    {
        MergePass(ds, ar, s, n);
        s+=s;
        MergePass(ar, ds, s, n);
        s+=s;
    }
}

int main()
{
    int ar[] = {23, 12, 45, 34, 56, 67, 78, 89, 90, 100};
    int n = sizeof(ar) / sizeof(ar[0]);
    MergeSort(ar, n);
    Array_Print(ar, n);
    return 0;
}
*/
