/*
 * =====================================================================================
 *
 *       Filename:  MCM.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/01/2016 06:00:14 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 *          0     1     2     3
 *        [2,3] [3,6] [6,4] [4,5]
 *
 *        AB BC CD DE
 *        ABC, BCD, CDE
 *        ABCD, BCDE
 *        ABCDE - A BCDE
 *              - AB CDE
 *              - ABC DE
 *              - ABCD E
 *
 *
 *        A B C D 
 *      A 0 x y z 
 *      B   0 x y  
 *      C     0 x 
 *      D       0 
 * =====================================================================================
 */

#include <iostream>

using namespace std;

#define MAX_NUM 4

int m_row[MAX_NUM] = {2, 3, 6, 4};
int m_col[MAX_NUM] = {3, 6, 4, 5};

int m[MAX_NUM-1][MAX_NUM] = {0,};

int main() {

  // length 1 , 0 done
  
  for (int len = 1; len < MAX_NUM; len++) // len
  {
    for (int p = 0; p + len < MAX_NUM; p++) // start 
    {
      int minVal = 987654321;
      for (int k = p; k < p+len; k++) 
      {
        //from p + k * k+1, til len
        int tmp = m[p][k] + m[k+1][p+len] + m_row[p] * m_row[k+1] * m_col[p+len];
        cout << "tmp: " << tmp << endl;
        minVal = min(minVal,tmp); 
      }
      m[p][p+len] = minVal;
    }
  }
  cout << "R:" << m[0][MAX_NUM-1] << endl;
  
  return 0;
}
