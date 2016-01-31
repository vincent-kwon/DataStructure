#include <stdio.h>
#include <iostream>

using namespace std;
/*
 * From given start point (r,c), and end point to a matrix filled with values,
 * find maximum sum of area must start from start point. End can't be bigger than
 * end point.
 *
 * 
 */
int M[300][300];
int A[300][300];
int H;
int W;

int findMaxValue(int sr, int sc, int er, int ec) {
  int max = -99999999;
  int i,j,k;

  for (i = sr; i <= (er-1); i++) {
    int colAccum = 0;

    for (j = sc; j <= (ec-1); j++) {
      colAccum += M[i][j];
      A[i][j] = colAccum + ( (i>0) ? A[i-1][j] : 0 );
      if (A[i][j] > max) max = A[i][j];
    }
  }
  return max;
}

int main() {
  int test;
  int i,j,k;

  scanf("%d", &test);
  while (test-- > 0) {
    scanf("%d %d", &H,&W);      
    for (i = 0; i < H; i++) {
      for (j = 0; j < W; j++) {
        scanf("%d", &M[i][j]);
        cout << M[i][j] << endl;
      }
    }
    int maxValue = findMaxValue(0,0,H,W);
    cout << maxValue << endl;
  }
}
