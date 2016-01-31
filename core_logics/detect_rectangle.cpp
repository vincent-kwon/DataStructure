#include <iostream>
#include <algorithm>
#include <math.h>       /* sin */

using namespace std;

long long m[100][100][100] = {0, } ;

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
#if 0  
          // get sum to N depth from this row
          m[k][i][j] = m[k-1][i-1][j] + m[0][i][j]; // sum to N depth
#endif 

#if 1
          // If meet certain conditions, 1 
          if (m[0][i][j] > 0 && m[k-1][i-1][j] > 0)
            m[k][i][j] = 1; // sum to N depth
          else 
            m[k][i][j] = 0;
#endif

#if 0 // try diagonal

#endif
          cout << k << "," << i << "," << j << ":" << m[k][i][j] << endl;
        }  
      }
    }
  }

  return 0;
}
