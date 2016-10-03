/*
 * =====================================================================================
 *
 *       Filename:  LIS_brute.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/16/2016 07:05:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <list>

using namespace std;


int getLIS(vector<int> v) {
  // take index or not
  if (v.empty()) return 0;

  vector<int> biggerOnly;

  for (int i = 1 ; i < v.size(); i++) 
    if (v[0] <= v[i]) biggerOnly.push_back(v[i]);

  v.erase(v.begin());
 
  return max(1 + getLIS(biggerOnly),
      getLIS(v));
}

int main() {
  vector<int> v = { 1, 5, 2, 4, 7 };

  int r = getLIS(v);
  cout << r - 1 << endl;
  return 0;
}
