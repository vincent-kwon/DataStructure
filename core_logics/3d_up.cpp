#include <iostream>
#include <algorithm>
#include <math.h>       /* sin */

using namespace std;

long long m[100][100][100];

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
        cin >> m[0][i][j];        
      }
    }

    for (i = 0; i < rows; i++) {
      for (j = 0; j < cols; j++) {
        for (k = 1 ; k < (i+1); k++) {
          // for example, m[2][3][0] = m[1][3][0] + m[i][j];  now + now - 1 to the k depth;
          m[k][i][j] = m[k-1][i-1][j] + m[0][i][j]; // one step
          cout << k << "," << i << "," << j << ":" << m[k][i][j] << endl;
        }  
      }
    }
  }

  return 0;
}
