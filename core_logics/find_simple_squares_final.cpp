#include <iostream>

using namespace std;

long long g[100][100] = {0,};

long long m[2][100][100] = {0,}; //0 <---

bool isSquareEdge(int cur_row, int cur_col, int max_row, int max_col) {
  // below 0 or below dead-end && right 0 or right dead-end
  if ( ((cur_row == max_row) || (g[cur_row+1][cur_col] == 0)) && 
       ((cur_col == max_col) || (g[cur_row][cur_col+1] == 0)) &&
       ((m[0][cur_row][cur_col] == m[1][cur_row][cur_col]))
     ) {
    return true;
  }
  else {
    return false;
  }
}


int main() {
  int testnum;
  int rows, cols;
  int i, j, k, h;

  cin >> testnum;

  while (testnum-- > 0) {
    cin >> rows;
    cin >> cols;

    for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
        cin >> g[i][j];        
      }
    }

    // all values are first 0 if not specified
    for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
        // handle columns 
        if (j == 0) {
          if (g[i][j] != 0) {
            m[0][i][j] = 1; //increase value
          }
        }
        else {
          // if the value is zero, do not assign value to m[] so it is automatically zero
          if (g[i][j] != 0) {
            m[0][i][j] = m[0][i][j-1] + 1;
          }
        }

        // handle rows
        if (i == 0) {
          if (g[i][j] != 0) {
            m[1][i][j] = 1;
          }
        }
        else {
          if (g[i][j] != 0) {
            m[1][i][j] = m[1][i-1][j] + 1; //increase value
          }
        }
        
        if (g[i][j] != 0 && isSquareEdge(i,j, rows-1, cols-1)) {
          cout << "Found square at " << i <<","<< j <<":width("<< m[0][i][j] << "),height(" << m[1][i][j] << ")" << endl;
        }
      }
    }
  }

  return 0;
}
