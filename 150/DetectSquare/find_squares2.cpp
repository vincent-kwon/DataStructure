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
#include <limits.h>

using namespace std;

char v[200][200] = {0, };
int rightCons[200][200] = {0, };
int bottom[200][200] = {0, };

int getTotal(int i, int j, int n, int m) {
  int count = 0;
  int maxColumnLength = INT_MAX;
  int startRow = i;
  int endRow = startRow + bottom[i][j] - 1;

  for (startRow; startRow <= endRow; startRow++) {
    int thisColumnLength = rightCons[startRow][j];

    if (thisColumnLength > maxColumnLength) {
      thisColumnLength = maxColumnLength;
    }

    if (thisColumnLength < maxColumnLength) {
      maxColumnLength = thisColumnLength;
    }

    count += thisColumnLength;
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


    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        char  charInput;

        //cout << i << "," << j << "," << m << "," << n << endl;
        cin >> charInput;
        v[i][j] = charInput;
        //cout << "what the fuck cin ?? " << input << endl;
      }
    }

    int count = 0;
    int value;

    // fill rightCons array
    for (int i = 0; i < n; i++) {
      int startIndex = 0;
      int startValue = v[i][0];
      int currentIndex = 1;
    
      for (int j = 1; j < m; j++, currentIndex++) {
        if (v[i][j] == startValue) {
          continue;
        }
        else {
          // fill rightCons
          int endIndex = currentIndex - 1;
          value = 1;
          for (int k = endIndex ; k >= startIndex; k--, value++) {
            rightCons[i][k] = value;
          }

          // reset
          startIndex = currentIndex;
          startValue = v[i][j];
        }
      }

      // if end there needs one more filling for end
      int endIndex = currentIndex - 1;
      value = 1;
      for (int k = endIndex ; k >= startIndex; k--, value++) {
        rightCons[i][k] = value;
      }
    }

    // fill bottom array
    for (int j = 0; j < m; j++) {
      int startIndex = 0;
      int startValue = v[0][j];
      int currentIndex = 1;
    
      for (int i = 1; i < n; i++, currentIndex++) {
        if (v[i][j] == startValue) {
          continue;
        }
        else {
          // fill bottom
          int endIndex = currentIndex - 1;
          value = 1;
          for (int k = endIndex ; k >= startIndex; k--, value++) {
            bottom[k][j] = value;
          }

          // reset
          startIndex = currentIndex;
          startValue = v[i][j];
        }
      }

      // if end there needs one more filling for end
      int endIndex = currentIndex - 1;
      value = 1;
      for (int k = endIndex ; k >= startIndex; k--, value++) {
        bottom[k][j] = value;
      }
    }
    // for all members, 
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        count += getTotal(i,j,n,m);
      }
    }
    cout << "count: " << count << endl;
  }
  return 0;
}
