/*
 * =====================================================================================
 *
 *       Filename:  fibo.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/04/2016 11:16:08 PM
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

int fibonacci(int n) {
  int* fb = new int[n];

  if (n <= 0) return 0;

  if (n == 1) return 1;
  
  if (n == 2) return 2;
  
  fb[1] = 1;
 
  fb[2] = 1;

  for (int i = 3; i <= n ; i++) {
    fb[i] = fb[i-1] + fb[i-2];
  }
  return fb[n];
}

int main() {
  int i;
  cin >> i; 
  cout << fibonacci(i) << endl;
}
