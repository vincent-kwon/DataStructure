/*
 * =====================================================================================
 *
 *       Filename:  merge.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/08/2016 03:48:45 PM
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

void merge(int s, int e, int* a) {
  cout << "enter: " << s << "," << e << endl;
  if (s < e) {
    int midDiff = (e-s)/2;

    merge(s, s+midDiff, a);
    merge(s+midDiff+1, e, a);
  } else {
    return;
  }
}

int main() {
  int a[5];
  int *aptr = &a[0];

  for (int i = 0; i < 5 ; i++) {
    cin >> a[i] ; 
  }

  merge(0, 4, aptr); 
}
