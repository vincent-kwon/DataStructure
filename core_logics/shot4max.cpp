#include <iostream>
#include <algorithm>
#include <math.h>       /* sin */
#include <limits.h>

using namespace std;

int m[100][100];

int maxRow = INT_MIN;

int checkRowsForOne(int max_row, int max_col, int m[100][100]) {
  int i,j;
  int count = 0;
  
  for (i = 0; i < max_row; i++) {
    bool allOne = true;
    for (j = 0; j < max_col; j++) {
      if (m[i][j] == 0) {
        allOne = false;
      }
    }
    if (allOne) {
      count++;
    }
  }
  return count;
}


void checkForAll(int shot, int max_row, int max_col, int m[100][100]) {
  int i,j,k,h;
  cout << "check shot: " << shot << endl;
  for (i = 0; i < max_row; i++) {
    for (j = 0; j < max_col; j++) {
       cout << m[i][j] << "," ;
    }
    cout << "" << endl;
  }
  cout << "" << endl;
  cout << "" << endl;

  if (shot == 0) {
    int val = checkRowsForOne(max_row, max_col, m);

    if (val > maxRow) {
      maxRow = val;
    }
    return;
  }

  for (i = 0; i < max_col; i++) {
    int originalCol[100];

    for (k = 0 ; k < max_row ; k++) {
      if ( m[k][i] == 1 ) {
        m[k][i] = 0;
        originalCol[k] = 1;
      }
      else {
        m[k][i] = 1;
        originalCol[k] = 0;
      }
    }
    checkForAll(shot-1, max_row, max_col, m);
    for (k = 0 ; k < max_row ; k++) {
      m[k][i] = originalCol[k]; // restore
    }
  }
}

int main() {
  int testnum;
  int rows, cols;
  int i, j, k, h;
  int shot;

  cin >> testnum;

  while (testnum-- > 0) {
    cin >> rows;
    cin >> cols;
    cin >> shot;

    for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
        cin >> m[i][j];        
      }
    }

    checkForAll(shot, rows, cols, m);
    cout << "#" << maxRow << endl;
  }

  return 0;
}
