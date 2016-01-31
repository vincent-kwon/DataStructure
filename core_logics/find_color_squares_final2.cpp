#include <iostream>
#include <limits.h>

/*
 * Find maximum area rectangle by color
 */

using namespace std;

int g[10000][10000] = {0,};
int maxWidth = INT_MIN;
int points[10000][4]; 

bool isStartEdge(int cur_row, int cur_col, int max_row, int max_col) {
  // below 0 or below dead-end && right 0 or right dead-end 
  //cout << "isStart...." << cur_row << "," << cur_col << endl;
  if ( ((cur_row == 0) || (g[cur_row-1][cur_col] != g[cur_row][cur_col])) && 
       ((cur_col == 0) || (g[cur_row][cur_col-1] != g[cur_row][cur_col])) ) { 
    //cout << "Yes" << endl;
    return true;
  }
  else {
    //cout << "No" << endl;
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

int checkValue(int r, int c, bool* hasBlocker, int (*cb)[1000] )                      
{ 
  if (g[r][c] == 0) {
    *hasBlocker = true;
    return 0;
  }
                                                      
  if ( r == 0 || c == 0) {
    return 1;
  }
  else {
    int val1 = (cb)[r-1][c];
    int val2 = (cb)[r][c-1];
    int val3 = (cb)[r-1][c-1];  
    int min = minOfThree(val1, val2, val3);          
    return min + 1;
  }
} 

void checkAllSquares(int cur_row, int cur_col, int max_row, int max_col) {
  // from cur_row, cur_col, find square and if found, set it if bigger than maxWidth;
  int i,j,k,h;
  int cb[1000][1000] = {0, };
  int node[1001] = {0, }; // from 1 to 1001
  int size = 0;

  //cout << "checkAllSquare..." << endl;
  while (1) {
    int right;
    int down;
    bool hasBlocker = false;
  
    if ((cur_row + size) > max_row || (cur_col + size) > max_col) {
      return;
    }  

    // move one right, go down size - 1 times
    cb[cur_row][cur_col + size] = checkValue(cur_row, cur_col + size, &hasBlocker, cb);
    node[g[cur_row][cur_col+size]] = 1;

    for (i = 1 ; i <= size; i++) {
      cb[cur_row + i][cur_col + size] = checkValue(cur_row + i, cur_col + size, &hasBlocker, cb);
      node[g[cur_row+i][cur_col + size]];
    }

    // move one down, go right size - 1 times
    cb[cur_row + size][cur_col] = checkValue(cur_row + size, cur_col, &hasBlocker, cb);
    node[g[cur_row + size][cur_col]];
    for (i = 1 ; i <= size; i++) {
      cb[cur_row + size][cur_col + i] = checkValue(cur_row + size, cur_col + i, &hasBlocker, cb);
      node[g[cur_row + size][cur_col + i]] = 1;
    }
 
    cb[cur_row + size][cur_col + size] = checkValue(cur_row + size, cur_col + size, &hasBlocker, cb);
    node[g[cur_row + size][cur_col + size]] = 1;

    if (hasBlocker) {
      break;
    } 
    else {
      if ( ( (size+1) * (size+1) ) == ( cb[cur_row + size][cur_col + size] * cb[cur_row + size][cur_col + size]) ) { 
        bool allFit = true; 
         
        for (k = 1; k < 1001; k++) { 
          if (node[k] == 1)  {
            if (cur_row <= points[k][0] && 
                cur_col <= points[k][1] &&
                cur_row + size >= points[k][2] && 
                cur_col + size >= points[k][3]) {
              continue;
            } 
            else {
              cout << "Notfit " << points[k][0] << "," << points[k][1] << " with size " << size + 1<< endl;  
              allFit = false;
            }
          }
        }
        if (allFit) {
          cout << "Found Square by DP at " << cur_row << ", " << cur_col << " with size " << size + 1<< endl;  
          if (size + 1 > maxWidth)
            maxWidth = size + 1;
        }
      }
      size++;
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
      //cout << "node input: " << endl;
      cin >> x1;
      cin >> y1;
      cin >> x2;
      cin >> y2;

      index++; 
      //cout << "received...." << endl;
      points[index][0] = x1;
      points[index][1] = y1;
      points[index][2] = x2-1;
      points[index][3] = y2-1;
      
      // fill the area
      for (i = x1; i < x2; i++) {
        for (j = y1; j < y2; j++) {
          //cout << "set value at " << i << "," << j << " with " << index << endl;
          g[i][j] = index; // fill the area with the given number
        }
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
  return 0;
}
