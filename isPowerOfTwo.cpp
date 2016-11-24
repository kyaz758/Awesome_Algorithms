/******************************************************************************
 ***** File Name : Algorithm.cpp
 **** Created By : kyaz758
 *** Description :
 * Creation Date : 2016-11-24 22:25
 * Last Modified : 2016-11-24 22:44
 ******************************************************************************/

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/*
 * Before   O(N) = O(log2(N));
 * bool isPowerOfTwo( int n )
 * {
 *      if ( n < 0 ) 
 *          return false;
 *      while ( n & 1 )
 *      {
 *          n = n >> 1;
 *      }
 *      return n == 1;
 * }
 * 
 */ 

// After    O(N) = O(1); Awesome !!
bool isPowerOfTwo( int n )
{
    return n > 0 && !( n & n-1 );
}
int main()
{
    int n = 1;
    while (n != 0)
    {
        cin >> n;
        cout << isPowerOfTwo( n ) << endl;
    }
    return 0;
}
