#include <iostream>
#include <limits.h>

/*
 * Find maximum area rectangle by color
 */

using namespace std;

long long g[10000][10000] = {0,};
int points[10000][4]; 
int maxWidth = INT_MIN;

bool isStartEdge(int cur_row, int cur_col, int max_row, int max_col) {
  // below 0 or below dead-end && right 0 or right dead-end
  if ( ((cur_row == 0) || (g[cur_row-1][cur_col] != g[cur_row][cur_col])) && 
       ((cur_col == 0) || (g[cur_row][cur_col-1] != g[cur_row][cur_col])) ) {
    return true;
  }
  else {
    return false;
  }
}

int minOfThree(int val1, int val2, int val3) {
  if (val1 <= val2 && val1 <= val3) 
    return val1;

  if (val2 <= val1 && val2 <= val3) 
    return val2;

  if (val3 <= val1 && val3 <= val2) 
    return val3;
}

void checkAllSquares(int cur_row, int cur_col, int max_row, int max_col) {
  // from cur_row, cur_col, find square and if found, set it if bigger than maxWidth;
  int i,j,k,h;
  long long cb[10000][10000] = {0, };

  int size = 0;
  while (1) {
    for (i = cur_row; i <= cur_row + size; i++) {
      for (j = cur_col; j <= cur_col + size; j++) {
        if (g[i][j] == 0) {
          continue;
        }
     
        //cb[i][j] = getMinOfThree(i,j, max_row, max_col) + 1;
        if (i == cur_row || j == cur_col) {
          cb[i][j] = 1;
        } 
        else {
          int val0 = cb[i][j-1];
          int val1 = cb[i-1][j];
          int val2 = cb[i-1][j-1];

          cb[i][j] = minOfThree(val0, val1, val2);
        } 
      }
    }
 
    int v = cb[i-1][j-1];
    v *= v;
    int toCompare = size * size;
  
    if (v == toCompare) {
      cout << "found Square : " << size << " at " << i-1 << "," << j-1 << endl;  
    }
  }
}

int main() {
  int testnum;
  int rows, cols;
  int i, j, k, h;
  int x1, y1, x2, y2;

  int node_num;

  cin >> testnum;

  while (testnum-- > 0) {
    cin >> rows;
    cin >> cols;
    cin >> node_num;
 
    int index = 0;

    while (node_num-- > 0) {
      cin >> x1;
      cin >> y1;
      cin >> x2;
      cin >> y2;

      index++ 

      points[index][0] = x1;
      points[index][1] = y1;
      points[index][2] = x2-1;
      points[index][3] = y2-1;
      
      // fill the area
      for (i = x1; i < x2; i++) {
        for (j = y1; j < y2; j++) {
          g[i][j] = index; // fill the area with the given number
        }
      }
      
      for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
          if (g[i][j] != 0 && isStartEdge(i,j,rows,cols)) {
            checkAllSquares(i,j,rows,cols); 
          }
        }
      } 
      cout << "Max: " << maxWidth << endl;
    }
  }
  return 0;
}
