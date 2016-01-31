#include <iostream>
#include <algorithm>
#include <math.h>       /* sin */

using namespace std;

int m[1000][1000] = { 0, };

int main() {
  int testnum;
  int rows, cols;
  int i, j, k, h;
  cin >> testnum;

  while (testnum-- > 0) {
    cin >> rows;
    cin >> cols;

    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        cin >> m[i][j];        
      }
    }
  }

  return 0;
}
