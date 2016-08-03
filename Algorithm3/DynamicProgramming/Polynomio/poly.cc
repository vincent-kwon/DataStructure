/*
 * =====================================================================================
 *
 *       Filename:  poly.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/04/2016 07:15:16 AM
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

#define NUM 92 

const int MOD = 10000000;

long long m[NUM+1][NUM+1] = {0, };

int getPoly(int num) {
  for (int n = 1; n <= num; n++) {
    for (int curTop = 1; curTop <= n; curTop++) {
      if (n >= curTop) {
        if (n == curTop) m[n][n] = 1; // if top has all nums, only one case
        else {
          long long sum = 0;
          for (int prevTop = 1; prevTop <= (n-curTop); prevTop++) {
            long long tmp =  ((curTop + prevTop - 1) * m[n-curTop][prevTop]) % MOD;
            sum += tmp;
            sum %= MOD;           
          }
          m[n][curTop] = sum;
        }
      }
    } 
  }  

  long long r = 0; 
  
  for (int top = 1; top <= num; top++) {
    r += m[num][top];
  }

  cout << "r:" << r % MOD  << endl;
  return 0;
}

int main() {
  int r = getPoly(NUM);
  return 0;
}


