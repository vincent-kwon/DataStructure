/*
 * =====================================================================================
 *
 *       Filename:  CoinChanging.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/01/2016 07:50:20 PM
 *       Finished:  
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 *
 *     coins = 7, 2, 3, 6
 *     Total = 13
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

#define VAL 13
#define NUM 4
#define MAX_VALUE 987654321

int num[NUM] = {7, 2, 3,6};
int m[VAL+1] = {0, };
int b[VAL+1] = {-1,};

int main() {

  for (int i = 0; i <= VAL; i++) {
    m[i] = MAX_VALUE;
    b[i] = -1;
  }

  m[0] = 0; // edge indexer

  for (int i = 0 ; i < NUM; i++) {
    for (int j = 1 ; j <= VAL; j++) {
      if (num[i] > j) continue; // can't affect
      int newMJ = m[j-num[i]]+1;
      if (newMJ < m[j]) {
        m[j] = newMJ;
        b[j] = i;
      }
    }
  }
  cout << "r: " << m[VAL] << endl;
  int index = VAL;

  while (index > 0) {
    cout << num[b[index]] << endl;
    index -= num[b[index]]; 
  }
  return 0;
}
