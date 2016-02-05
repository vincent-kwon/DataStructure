/*
 * =====================================================================================
 *
 *       Filename:  hanoii.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  02/04/2016 11:34:13 PM
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

int hanoi(int numOfDisk, int start, int use, int end) {
  if (numOfDisk <= 0) return 0;
  int count = 0;

  count = hanoi(numOfDisk-1, start, end, use);
  count++;
  count += hanoi(numOfDisk-1, use, start, end);
  return count;
}


int main() {
  
  int i;
  cin >> i;
  cout << hanoi(i, 1, 2, 3) << endl;
}
