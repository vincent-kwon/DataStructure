/*
 * =====================================================================================
 *
 *       Filename:  moveRect.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/19/2015 08:26:11 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <limits.h>
#include <iostream>

int shiftWindows(int r, int c, int max_row, int max_col, int k, int m[30][30], int size) {
  
}


int main() { 
  int test;

  while (test-- > 0) {
    int rows;
    int cols;
    int k;
    int m[30][30]; // 5 <= rows, cols <= 30
    int minValue;
    int bullCount = 0;

    cin >> rows ;
    cin >> cols ;
    cin >> k ;

    for (int i = 0; i < rows; i++ ) {
      for (int j = 0; j < cols; j++) {
        cin >> m[i][j];

        if (m[i][j] == 1) {
          bullCount++;
        }
      }
    }
   
    if (bullCount <= k) {
      cout << "#" << test << " " << 0;    
      continue;
    } 
    else {
      minValue = shiftWindows(0,0, rows, cols, k, m, rows*cols);
    }
  }
  return 0;
}
