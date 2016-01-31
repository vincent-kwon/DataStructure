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
int H;
int W;

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
  }
}
