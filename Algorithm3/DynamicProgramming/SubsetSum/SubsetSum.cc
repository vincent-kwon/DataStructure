/*
 * =====================================================================================
 *
 *       Filename:  SubsetSum.cc
 *
 *    Description:  
 *
 *
 *        Version:  1.0
 *        Created:  07/30/2016 01:16:53 AM
 *       Finished:  07/30/2016 04:53:00 AM 
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *  
 *    0 1 2 3 4 5 6 7 8 9 10 11
 * 0  T F F F F F F F F F F  F
 * 1  T F T F F F F F F F F  F 
 * 2  T F T T F T F F F F F  F
 * 3  T F T T F T F T F T T  F
 * 4  T F T T F T F T T F T  T
 * 5  T F T T F T F T T F T  T
 *
 *
 * =====================================================================================
 */

#include <iostream>
using namespace std;


#define NUM 11
#define LEN 5

int set[LEN] = { 2, 3, 7, 8, 10 };

int m[LEN+1][NUM+1] = {0, };

int main() {

  for (int i = 0; i < (LEN+1); i++)
    m[i][0] = 1;
 
  for (int j = 1; j < (NUM+1); j++)
    m[0][j] = 0;

  int totalSum = 0;  
  for (int i = 1; i < LEN+1 ; i++) {
    for (int j = 1; j < NUM+1; j++) {
      if (j < set[i-1]) m[i][j] = m[i-1][j]; // if set[i-1] is smaller than j, can't influence
      else {
        if (m[i-1][j] == 1) m[i][j] = 1; // if already meet before this, just set 1
        else m[i][j] = m[i-1][j-set[i-1]]; // do select it
      }
      cout << m[i][j] << " ";
    } 
    cout << "" << endl;
  }
  
  return 0;
}

