/*
 * =====================================================================================
 *
 *       Filename:  kthElementSlower.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/16/2016 04:42:42 PM
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

int skip = 3;

void generate2(int n, int m, string s) {
  if (skip < 0) return;
 
  if (n == 0 && m == 0) {
    if (skip == 0) cout << s << endl;
    --skip;
    return;
  }

  if (n > 0) generate2(n-1, m, s+"-");
  if (m > 0) generate2(n, m-1, s+"o");
}

int main() {
  generate2(2,2,"");
  return 0;
}
