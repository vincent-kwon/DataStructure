/*
 * =====================================================================================
 *
 *       Filename:  CuttingRod.cc
 *
 *    Description:  Maximize Rod value
 *
 *        Version:  1.0
 *        Created:  08/02/2016 01:33:50 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * -------------
 *  rod | value
 * -------------
 *    1 | 2
 *    2 | 5
 *    3 | 7
 *    4 | 8
 *
 *    0 1 2 3 4  5
 * 1  0 2 4 6 8  10
 * 2  0 2 5 7 10 12
 * 3  0 2 5 7 10 12
 * 4  0 2 5 7 10 12
 *
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

#define ROD_LEN 5

#define NUM 4

int rod[NUM] = {1, 2, 3, 4};
int val[NUM] = {2, 5, 7, 8};
int m[NUM+1][ROD_LEN+1] = {0,};

int main() {

  for (int i = 1; i < NUM+1; i++) {
    for (int j = 1; j < ROD_LEN+1; j++) {
      if (rod[i-1] > j) {
        m[i][j] = m[i-1][j]; 
        cout << i << ", " << j << "=" <<  m[i][j] << endl;
      } 
      else {
        m[i][j] = max(m[i-1][j], m[i][j-rod[i-1]] + val[i-1]);
        cout << i << ", " << j << "=" <<  m[i][j] << endl;
      }
    }
  }
  
  cout << "r:" << m[NUM][ROD_LEN] << endl;
  return 0;
}

