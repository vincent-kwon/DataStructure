/*
 * =====================================================================================
 *
 *       Filename:  dungbi.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/15/2015 09:52:22 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

int multiple (int i, int k) {

  while (k-- > 1) {
    i *= i;
  }

  cout << i << endl;
 
  return i;
}

int multiple_recurse(int i, int k) {

  if ( k == 1 )
    return i;
  
  i *= multiple_recurse ( i, k - 1);

  return i;
}

int main() {
  int n , k ;

  cin >> n ;

  cin >> k ; 

  int total = 0;
  int total_r = 0;

  for ( int i = 1 ; i <= n ; i++ )  {
    total += multiple(i, k);    
    total_r += multiple_recurse(i, k);
  }

  cout << total << "," << total_r << endl;
  return 0;
}
