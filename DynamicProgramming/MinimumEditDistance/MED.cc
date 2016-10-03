/*
 * =====================================================================================
 *
 *       Filename:  MED.cc
 *
 *    Description:  Given two string with add / delete / change
 *
 *        Version:  1.0
 *        Created:  08/01/2016 05:20:56 PM
 *       Revision:  none
 *       Compiler:  gcc
 *         source:  github.com/mission-peace/interview/wiki
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *            Key:  If diff, minimum of three + 1 !!! If same, out of picture (diagonal)
 *                  Why minimum of three? diagonal means change, 
 *                  long right-short, height means, one from right is removed is min to get here
 *                  long height-short, right means, one from height is removed is min to get here
 *       a b c d e f
 *     0 1 2 3 4 5 6
 *   a 1 0 1 2 3 4 5  
 *   g 2 1 1 2 3 4 5
 *   c 3 2 2 1 2 3 4
 *   e 4 3 3 2 2 2 3
 *   d 5 4 4 3 2 3 3
 *
 *   abcdef
 *   agced => 3, b->gd, delete d, f->d
 * =====================================================================================
 */

#include <iostream>

using namespace std;

#define LONG_MAX_NUM 6
#define SHORT_MAX_NUM 5

char sstr[SHORT_MAX_NUM] = {'a','g','c','e','d'};
char lstr[LONG_MAX_NUM]  = {'a','b','c','d','e','f'};

int mc[SHORT_MAX_NUM+1][LONG_MAX_NUM+1] = {0, };

int minThree(int a, int b, int c) {
  if (a <= b && a <= c) return a;
  if (b <= a && b <= c) return b;
  if (c <= a && c <= b) return c;
}

int main() {
  for (int i = 0; i < LONG_MAX_NUM+1; i++) {
    mc[0][i] = i;
  }

  for (int i = 0; i < SHORT_MAX_NUM+1; i++) {
    mc[i][0] = i;
  }

  for (int i = 1; i < SHORT_MAX_NUM+1; i++) {
    for (int j = 1; j < LONG_MAX_NUM+1; j++)  {
      if (sstr[i-1] == lstr[j-1]) mc[i][j] = mc[i-1][j-1];
      else mc[i][j] = 1+minThree(mc[i-1][j-1], mc[i][j-1], mc[i-1][j]);
    }
  }
  cout << "r: " << mc[SHORT_MAX_NUM][LONG_MAX_NUM] << endl;
  return 0;
}
