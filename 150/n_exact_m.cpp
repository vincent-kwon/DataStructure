/*
 * =====================================================================================
 *
 *       Filename:  n_exact_m.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/15/2015 11:13:21 PM
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

using namespace std;

void print_nums(int n, int m, vector<int> &v, int index) {
  if (m == index) {
    if (n == 0) {
      for (int i = 0 ; i < index ; i++) {
        cout << v[i] << " ";
      }
      cout << " " << endl;
    }
    return;
  }

  for (int i = 1; i <= n; i++) {
    v[index] = i;
    print_nums(n - i, m, v, index + 1);
  }
}

int main() {

  int n, m;

  vector<int> v;


  cin >> n;
  cin >> m;

  v.resize(m);
  print_nums(n, m, v, 0);

  return 0;
}
