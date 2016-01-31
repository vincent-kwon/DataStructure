/*
 * =====================================================================================
 *
 *       Filename:  find_squares.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/26/2015 11:12:06 PM
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

int getAllRectangles(int x, int y, vector< vector<int> >& v) {
  int count = 0;

  int color = v[x][y];

  for (int i = x ; i < v.size() ; i++) {
    for (int j = y ; j < v[i].size() ; j++) {
      if (v[i][j] == color) {
        count++;
      }
    }
  }

  return count;
}

int main() {

  int testNum; 
  cin >> testNum;

  while (testNum--) {
    int n, m;

    cin >> n;
    cin >> m;

    vector< vector<int> > v(n, vector<int>(m, 0));

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int input;
        char  charInput;

        //cout << i << "," << j << "," << m << "," << n << endl;
        cin >> charInput;
        input = charInput;
        v[i][j] = input;

        //cout << "what the fuck cin ?? " << input << endl;
      }
    }

    int countRect = 0;
    // iterate all matrix members
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int nextVal = v[i][j];
        countRect += getAllRectangles(i,j, v);
      }
    }

    cout << "count: " << countRect << endl;
  }
  return 0;
}
