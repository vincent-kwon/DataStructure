/*
 * =====================================================================================
 *
 *       Filename:  Knapsack.cc
 *
 *    Description:  Return max from items (0 or 1 select)
 *
 *        Version:  1.0
 *        Created:  07/29/2016 10:18:41 PM
 *       Finished:  07/29/2016 11:05:00 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 *    if weight is 7
 *    0 1 2 3 4 5 6 7
 *  0 0 0 0 0 0 0 0 0
 *  1 0 1 1 1 1 1 1 1
 *  2 0 1 1 4 5 5 5 5
 *  3 0 1 1 4 5 6 6 9
 *  4 0 1 1 4 5 7 8 9
 *
 *
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

#define MAX_NUM 4

#define TOTAL 7

int wt[MAX_NUM]  = {1, 3, 4, 5};
int val[MAX_NUM] = {1, 4, 5, 7};

int M[MAX_NUM+1][TOTAL+1] = {0, };

int main() {
  for (int i = 1 ; i <= MAX_NUM; i++) {
    for (int j = 1 ; j <= TOTAL; j++) {
      if (wt[i-1] > j) M[i][j] = M[i-1][j]; // can't affect
      else {
        M[i][j] = max(M[i-1][j], val[i-1] + M[i-1][j-wt[i-1]]);
      }
      //cout << "M[" << i << "][" << j << "] = " << M[i][j] << endl;
    }
  }

  cout << "R: " << M[MAX_NUM][TOTAL] << endl;

  int row = MAX_NUM;
  int col = TOTAL;

  while (col > 0) {
    if (M[row][col] == M[row-1][col]) {
      row -= 1;
    }
    else {
      cout << row << endl;
      col -= wt[row-1];
      row -= 1;
    }
  }
  cout << "" << endl;
  return 0;
}

