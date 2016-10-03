/*
 * =====================================================================================
 *
 *       Filename:  LCS.cc
 *
 *    Description: Find longest common subsequence of two arrays
 *                 1 2 3 4 6 
 *                 1 3 2 3 6
 *          Input: two integer array
 *         Output: return of maximum common sub sequence  
 *
 *        Version:  1.0
 *        Created:  07/29/2016 08:13:30 PM
 *       Finished:  07/29/2016 09:08:00 PM 
 *            P/A:
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 *    0 a b c d a f
 *  0 0 0 0 0 0 0 0 
 *  a 0 1 1 1 1 1 1 
 *  c 0 1 1 2 2 2 2 
 *  b 0 1 2 2 2 2 2
 *  c 0 1 2 3 3 3 3
 *  f 0 1 2 3 3 3 4 
 * =====================================================================================
 */

#include <iostream>

using namespace std;

#define NUM_ARRAY 2
#define MAX_NUM 6

char m[NUM_ARRAY][MAX_NUM] = {
  {'a','b','c','d','a','f'},
  {'a','c','b','c','f'}
};

int a[MAX_NUM+1][MAX_NUM+1] = { 0, };

int main() {
  int rowLen = 5 + 1;
  int colLen = 6 + 1;

  for (int i = 1 ; i < rowLen; i++) {
    for (int j = 1; j < colLen; j++) {
      if (m[1][i-1] == m[0][j-1]) {
        a[i][j] = 1 + a[i-1][j-1];
      }
      else {
        a[i][j] = max(a[i-1][j], a[i][j-1]);
      }
    }
  }

  cout << "r:" << a[rowLen-1][colLen-1] << endl;

  int row =  rowLen - 1 ;
  int col = colLen - 1; 
  // print
  while (row >= 0 && col >= 0) {
    if (m[1][row-1] == m[0][col-1]) {
      cout << m[1][row-1] << " ";
      row -= 1;
      col -= 1;
    }
    else {
      if (a[row][col-1] == a[row][col]) {
        col -= 1;
      }
      else row -= 1;
    }
  }
  return 0;
}

