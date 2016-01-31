/*
 * =====================================================================================
 *
 *       Filename:  circular_n.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/15/2015 11:51:43 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <iostream>
#include <limits.h>

using namespace std;

int miro[4096][4096];

long long num_path(int m, int n) {
  if (miro[m][n] == 0) {
    return 0;
  }
  if (m == 0 && n == 0) {
    return 1; 
  }

  return (( m > 0 ) ? num_path (m - 1, n) : 0) + (( n > 0 ) ? num_path (m, n-1) : 0);
}

int main() {
  int r, c;
  cin >> r;
  cin >> c;


  for (int i = 0 ; i < r ; i++ ) {
    for (int j = 0 ; j < c ; j++ ) {
      cin >> miro[i][j];
      cout << miro[i][j] << endl;
    }
  }

  int count = num_path(r - 1, c - 1); 

  cout << count << endl;
  return 0;
}
