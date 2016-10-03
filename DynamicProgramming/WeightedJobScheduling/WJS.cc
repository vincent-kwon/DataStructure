/*
 * =====================================================================================
 *
 *       Filename:  WJS.cc
 *
 *    Description:  i
 *
 *        Version:  1.0
 *        Created:  08/02/2016 08:38:13 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 *
 *   (1,3)    (2,5)    (4,6)    (6,7)    (5,8)    (7,9)
 *     5        6        5        4        11       2
 *
 *    HINT: end timer increasing order
 * =====================================================================================
 */

#include <iostream>

using namespace std;

#define NUM 6
int v[NUM] = { 5, 6, 5, 4, 11, 2};
int s[NUM] = { 1, 2, 4, 6,  5, 7};
int e[NUM] = { 3, 5, 6, 7,  8, 9};
int m[NUM]  = { 0, };

int main() {
  
  for (int i = 0; i < NUM; i++) m[i] = v[i]; // length 1

  for (int i = 1; i < NUM; i++) { 
    for (int j = 0; j < i; j++) {
      if (e[j] <= s[i]) m[i] = max(m[i], m[j] + v[i]);
      cout << i << "," << j << " = " << m[i] << endl;
    }
  }
  
  return 0;
}

