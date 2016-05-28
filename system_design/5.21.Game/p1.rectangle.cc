#include <iostream>

#define W 5
#define H 5

#define max(a,b) ((a)>=(b)?(a):(b))
#define min(a,b) ((a)<=(b)?(a):(b))

using namespace std;
int input[11][4] = {
  {0,0,0,0},
  {0,1,0,3},
  {1,1,1,2},
  {2,2,2,2},
  {4,2,4,4},
  {1,3,2,3},
  {3,3,3,3},
  {3,1,3,2},
  {4,1,4,1},
  {2,1,2,1},
  {0,4,3,4}
};

int m[5][5] = {
  {0,1,1,1,10},
  {0,2,2,5,10},
  {0,9,3,5,10},
  {0,7,7,6,10},
  {0,8,4,4,4}
};

bool fitIn(int y1, int x1, int y2, int x2, int num) {
  int r_y1 = input[num][0];
  int r_x1 = input[num][1];
  int r_y2 = input[num][2];
  int r_x2 = input[num][3];

  if (r_y1 >= y1 &&
      r_x1 >= x1 &&
      r_y2 <= y2 &&
      r_x2 <= x2)
    return true;
  else 
    return false;
}

enum RESULT {
  FAIL_ZERO,
  FAIL_FIT,
  SUCCESS
};

int checkRect(int y1, int x1, int y2, int x2) {
  bool rect[11] = {false, }; // rect from 1~9
  for (int i = y1; i <= y2; i++) {
    for (int j = x1; j <= x2; j++) {
      if (m[i][j] < 1) return FAIL_ZERO;

      int num = m[i][j];
      if (rect[num]) continue;
      else {
        // check it 
        if (fitIn(y1,x1,y2,x2,num) && ((y2-y1) == (x2-x1))) {
          rect[num] = true;
          continue;
        }
        else return FAIL_FIT;
      }
    }
  }
  return SUCCESS;
}

int main() {
  // Q0. how to represent the matrix? 0, 0, 1, 1 (which is 0,0,0,0) if end point y2,x2 is given, -1, -1 to makeindex
  // Q1. find max rectangle
  int ret = 1;
  for (int i = 0 ; i < H; i++) {
    for (int j = 0; j < W; j++) {
      bool shouldStop = false;
      for (int k = i; k < H; k++) {
        for (int m = j; m < W; m++) {
          cout << "(" << i << "," << j << "," << k << "," << m << ")" << endl;
          int tmp = checkRect(i,j,k,m);
          if (tmp == SUCCESS) {
            ret = max(ret, (k-i+1)*(m-j+1));
          } 
          else if (tmp == FAIL_ZERO) {
            // no more i,j is valid
            shouldStop = true;
            break;
          } else {
            continue;
          }
        }
      }
      
    }
  }
  cout << ret << endl;
  return 0;
  // Q2. find max square

  // condition: must not disjoint
}
