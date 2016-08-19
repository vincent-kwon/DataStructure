/*
 * =====================================================================================
 *
 *       Filename:  kthElementFaster.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/16/2016 04:55:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */
#include <iostream>
#include <memory.h>
using namespace std;

const int M = 1000000000+100;
int bino[201][201];
int skip;

void calcBino() {
  memset(bino, 0, sizeof(bino));
  for (int i = 0; i <= 200; ++i) {
    bino[i][0] = bino[i][i] = 1;
    for (int j = 1; j < i; ++j) 
      bino[i][j] = min(M, bino[i-1][j-1] + bino[i-1][j]);
  }
}

void generate3(int n, int m, string s) {
  if (skip < 0) return;
  if (n == 0 && m == 0) {
    if (skip == 0) cout << s << endl;
    --skip;
    return;
  }

  if (bino[n+m][n] <= skip) {
    skip -= bino[n+m][n];
    return;
  }

  if (n > 0) generate3(n-1, m, s + "-");
  if (m > 0) generate3(n, m-1, s + "o");  
}

int main() {
  skip = 3;
  calcBino();
  generate3(2,2,"");
}
