/*
 * =====================================================================================
 *
 *       Filename:  MH_23_cloud_predict.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/13/2015 03:14:51 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

char M[100][100];
int  O[100][100];

void showCloudAppear(int H, int W) {
  int i, j, k; 

  for (i = 0 ; i < H; i++) {
    int lastCloud = -1;

    for (j = 0; j < W; j++) {
      if (M[i][j] == 'c') {
        lastCloud = j;
        O[i][j] = 0;   
      }
      else {
        if (lastCloud == -1) {
          O[i][j] = -1;
        }
        else {
          O[i][j] = j - lastCloud;
        }
      }
    }
    for (j = 0; j < W; j++) {
      cout << O[i][j] << " ";
    }
    cout << "" << endl;
  }
}

int main() {
  int test;
  int H, W;

  cin >> test;

  while (test-- > 0) {
    int i,j,k;

    cin >> H;
    cin >> W;

    for (i = 0; i < H; i++) {
      for (j = 0; j < W; j++) {
        cin >> M[i][j];
      }
    }

    showCloudAppear(H,W);
  }
}
