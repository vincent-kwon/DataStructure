/*
 * =====================================================================================
 *
 *       Filename:  OBS.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/02/2016 02:10:13 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 *   if 0 
 *       - 1 
 *            - 2 
 *                - 3 tree,
 *      val[0] + val[1]*2 + val[2]*3 + val[3]*4
 *
 *   0   1   2   3
 *   10  12  16  21
 *   4   2   6   3
 *
 *     10 12 16 21
 *  10 4  
 *  12    2
 *  16       6
 *  21          3 
 *
 *  [HINT] Magic of SUM
 * =====================================================================================
 */

#include <iostream>

using namespace std;

#define NUM 4

int num[NUM] = { 10, 12, 16, 21 };
int val[NUM] = {  4,  2,  6,  3 };
int m[NUM][NUM] = { 0, };

int getSum(int start, int end) {
  int r = 0;
  for (int i = start; i <= end; i++) {
    r += val[i];
  }
  return r;
}

int main() {
  for (int len = 0; len < NUM; len++) {
    for (int i = 0; i + len < NUM; i++) {
      int start = i;
      int end = i + len;
      int minValue = 987654321;
      if (start == end) {
        m[start][end] = val[start]; // len is zero
        cout << "i=" << start << ", len=" << len << ", min=" << val[start] << endl;
      }
      else {
        int tmp;
        for (int k = 0; k <= len; k++) {
          int sum = getSum(start, end);
          int left = 0, right = 0;
          if (len >= 1 && k > 0) {
            left = m[i][i+k-1]; 
          }
          if (len >= 1 && k < len) {
            right = m[i+k+1][i+len];
          }
          int tmp = sum + left + right;
          cout << "i=" << i << ", len=" << len << ", left= " << left << ", right=" << right << ",min=" << tmp << endl;
          minValue = min(minValue, tmp); 
        }
        m[start][end] = minValue;
      }
    }
  }
  cout << "r:" << m[0][NUM-1] << endl;
  return m[0][NUM-1];
}
