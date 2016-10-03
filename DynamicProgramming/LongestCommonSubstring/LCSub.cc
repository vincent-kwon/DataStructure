/*
 * =====================================================================================
 *
 *       Filename:  LCSub.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/02/2016 04:02:50 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * abcdef
 * 3bcdf
 * = bcd
 *
 * HIT Matrix
 *   0 a b c d e f
 * 0
 * 3
 * b     1
 * c       2
 * d           0
 * f             
 *
 *   0 a b c d e f
 * 0 0 0 0 0 0 0 0 
 * 3 0 0 0 0 0 0 0
 * b 0 0 1 1 1 1 1 
 * c 0 0 1 2 2 2 2 
 * d 0 0 1 2 3 3 3 
 * f 0 0 1 2 3 3 3 
 *
 * if same, see diagonal continuous + 1 is bigger than not selecting this one (left, or top)
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

#define SHORT_LEN 5
#define LONG_LEN 6

int m[SHORT_LEN+1][LONG_LEN+1] = {0,};
int a[SHORT_LEN+1][LONG_LEN+1] = {0,};

string ss = "3bcdf";
string sl = "abcdef";

int main() {
  for (int i = 1; i < SHORT_LEN+1; i++) {
    for (int j = 1; j < LONG_LEN+1; j++) {
      if (ss[i-1] != sl[j-1]) {
        m[i][j] = max(m[i-1][j], m[i][j-1]);
        cout << i << "," << j << " = " << m[i][j] << endl;
      }
      else {
        a[i][j] = a[i-1][j-1] + 1; // add accum
        m[i][j] = max(m[i-1][j], m[i][j-1]);
        m[i][j] = max(m[i][j], a[i][j]);      
        cout << i << "," << j << " = " << m[i][j] << endl;
      }
    }
  }  
  cout << "r:" << m[SHORT_LEN][LONG_LEN] << endl;
  return 0;
}
