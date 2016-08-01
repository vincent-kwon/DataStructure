/*
 * =====================================================================================
 *
 *       Filename:  SumQuery.cc
 *
 *    Description:  
 *    	            Input: 
 *    	                   ---------(0,2) 
 *    	                   | 1 | 3 |
 *                         ---------(1,2)
 *                         | 4 | 2 |
 *                         ---------(2,2)
 *                         topX, topY, bottomX, bottomY 
 *                          
 *                         ex) (0,0,2,2)
 *
 *    	            Output: 
 *    	                   10  
 *    Performance:  
 *
 *        Version:  1.0
 *        Created:  07/29/2016 06:50:15 PM
 *        Finished: 07/29/2016 07:38:00 PM (48) 
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
#define MAX_NUM 3 
int m[MAX_NUM][MAX_NUM] = {
  { 1, 3, 2 },
  { 4, 2, 5 },
  { 8, 8, 2 }
};

int sum[MAX_NUM][MAX_NUM] = {0, };

int main() {
  int maxRow, maxCol, topRow, topCol, btmRow, btmCol;
  cin >> topRow;
  cin >> topCol;
  cin >> btmRow;
  cin >> btmCol;
 
  sum[0][0] = m[0][0];

  maxRow = btmRow;
  maxCol = btmCol;
  // col is 0
  for (int i = 1; i < maxRow; i++) {
    sum[i][0] = sum[i-1][0] + m[i][0];
  }

  // row is 0
  for (int i = 1; i < maxCol; i++) {
    sum[0][i] = sum[0][i-1] + m[0][i];
  }
  
  for (int i = 1; i < maxRow; i++) {
    for (int j = 1; j < maxCol; j++) {
      sum[i][j] = m[i][j] + sum[i-1][j] + sum[i][j-1] - sum[i-1][j-1];
      cout << i << "," << j << ":" << sum[i][j] << endl;
    }
  }
 
  int r = 0;
  if (topRow == 0 && topCol == 0) r = sum[btmRow-1][btmCol-1];
 
  else if (topRow == 0) r = sum[btmRow-1][btmCol-1] - sum[btmRow-1][topCol-1];
  
  else if (topCol == 0) r = sum[btmRow-1][btmCol-1] - sum[topRow-1][btmCol-1];

  else {
    int leftRectSum = sum[btmRow-1][topCol-1];
    int topRectSum = sum[topRow-1][btmCol-1];
    int btmRightSum = sum[btmRow-1][btmCol-1];
    int topLeftSum = sum[topRow-1][topCol-1];

    r = btmRightSum - leftRectSum - topRectSum + topLeftSum;
  }
  cout << "result: " << r << endl;

  return 0;
}

