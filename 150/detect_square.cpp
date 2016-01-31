/*
 * =====================================================================================
 *
 *       Filename:  detect_square.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  07/21/2015 10:27:55 PM
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
#define MAX_ROW 5

int s[MAX_ROW][MAX_ROW] = {0, };

// Example of input
// {0,0,0,0,0},
// {1,1,2,2,0},
// {1,1,2,2,0},
// {1,1,3,3,0},
// {4,4,4,4,0}};
//
// [0][0,1,2,4,1,0,3,1]
// [1][2,1,4,3,1,2,3,2]
// [2][2,3,4,4,3,2,3,3]
// [3][0,4,4,5,4,0,4,3]  

int d[MAX_ROW][MAX_ROW]; 
int min(int a, int b, int c) {
  if (a <= b && a <= c)
    return a;
  if (b <= a && b <= c)
    return b;
  if (c <= a && c <= b)
    return c;
  if (c == a && a == b)
    return a;
}

int cur_max = 0;
int cur_max_r = -1;
int cur_max_c = -1;

int data[10000][8]; //x1, y1, x2, y2, s_r, s_c, e_r, e_c

bool verify_rect(int max_size, int r, int c, int N) {
  for (int i = 0; i < N ; i++) {

    if ((data[i][4] > r) || (data[i][6] < (r - max_size + 1)) &&
        (data[i][5] > c) || (data[i][7] < (c - max_size + 1)))
      continue;

    if ((data[i][4] >= (r - max_size + 1) && data[i][6] <= r) &&
        (data[i][5] >= (c - max_size + 1) && data[i][7] <= c)) {
      cout << (i+1) << " fits in: " << endl;
      continue;
    }
    else { 
      cout << (i+1) << "not fit in: " << endl;
      return false;
    }
  }     
  return true;
}

int main() {
  int i, j, k;
  int N;

  // get rectangle info N
  cin >> N;

  for (i = 0; i < N; i++) {
    cin >> data[i][0];
    cin >> data[i][1];
    cin >> data[i][2];
    cin >> data[i][3];

    data[i][4] = data[i][1];
    data[i][5] = data[i][0];
    data[i][6] = data[i][3] - 1;
    data[i][7] = data[i][2] - 1;

    for (j = data[i][4]; j <= data[i][6]; j++) {
      for (k = data[i][5]; k <= data[i][7]; k++) {
         s[j][k] = i + 1;
      }
    }
  }  
  
  for (i = 0 ; i < MAX_ROW; i++) {
    for (j = 0 ; j < MAX_ROW; j++) {
      if (i == 0 || j == 0) {
        if (s[i][j] > 0) { 
          d[i][j] = 1;
        }
        else { 
          d[i][j] = 0;
        }
        continue;
      }
      
      if (s[i][j] == 0) {
        d[i][j] = 0;
      }
      else {
        d[i][j] = min(d[i-1][j-1], d[i-1][j], d[i][j-1]) + 1;  
         
        if (d[i][j] > cur_max) {
          if (verify_rect(d[i][j], i, j, N)) {
            cur_max = d[i][j];
            cur_max_r = i;
            cur_max_c = j;
          }
        }
      }  
    }
  }

  cout<<"cur_max:" << cur_max <<endl;
  cout<< cur_max_r << "," << cur_max_c << endl;
}
