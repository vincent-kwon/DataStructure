#include <iostream>
#include <math.h>
#include <stdlib.h>

char a[51];
char t[51];

using namespace std;

int dp[50][10][10];

int doubleTurn[3][4][2] =
{
 { {1,3}, {2,2},   {3,1},   {-3,-3} },
 { {2,3}, {3,2},   {-2,-3}, {-3,-2} }, 
 { {3,3}, {-1,-3}, {-2,-2}, {-3,-1} },
};

void move(int index, int gap) {
  int newValue;
  int value = a[index]-48;
  //cout << "to move: " << a[index] << " as value " << value << endl;
  if (gap > 0) {
    int t = 10 - value;
    if (gap > t) {
      newValue = gap - t;  // 
    } 
    else newValue = value + gap;
  }

  else {
    if (abs(gap) > value) {
      newValue = 10 - (abs(gap) - value);
    } else newValue = value - abs(gap);
  }
  a[index] = (char) (newValue + 48);
}

int getGap(int current, int goal) {
  int tmp; 
  
  if (goal > current) {
    tmp = goal - current; // 9 - 1 = 8 
  } 
  else {                        // 9,8,7 need to be changed
    tmp = current - goal;
    tmp = 10 - tmp; // 9 - 8 , 10 - 1 = 9 
  }
  
  if (tmp == 9 || tmp == 8 || tmp == 7) {
      tmp  = 10 - tmp;
      tmp *= -1;
  }
  return tmp;
}

void turn(int start, int end, int gap) {
  for (int i = start; i <= end; i++) {
    move(i, gap);
  }
}

int solve(int index) {  
  int curr = a[index];
  int next = a[index+1];
  int r;
  int m = dp[index][curr][next];
  int g = getGap(curr, t[index]); // g can be + or - 

  if (m != -1) return m;
  
  if (abs(g) == 0) {
    m = solve(index+1);     
    if (dp[index][curr][next] == -1 || dp[index][curr][next] > r)
      dp[index][curr][next] = r;
  }

  else if (abs(g) < 3) {
    int currentSmall = 987654321;
    for (int digitEnd = 0; digitEnd < 3; digitEnd++) {
      turn(index, index+digitEnd, g); // rotate
      int tmp = solve(index+1)+1;
      turn(index, index+digitEnd, -g); // back
      currentSmall = ((currentSmall>tmp)?tmp:currentSmall);
    }
    m = currentSmall;
  }

  else {
    for (int j = 0; j < 3; j++) { // 1번 째 디스크에 대한 회전
      for (int k = 0; k < 4; k++) {
        turn(index, index+j, doubleTurn[g-4][k][0]);
        for (int i = 0; i < 3; i++) {
          turn(index, index + i,  doubleTurn[g-4][k][1]);
          r = solve(index+1) + 2;
          if (r < m) m = r;
          turn(index, index + i, -doubleTurn[g-4][k][1]);
        }
        turn(index, index+j, doubleTurn[g-4][k][0]);
      }
    }
  }

  dp[index][curr][next] = m;
  return m;
}

int main() {
  int digit ;

  cin >> digit;
  cin >> a;
  cin >> t;
  cout << a << endl;
  cout << t << endl;


  // dp initialization
  int r = 0;
  
  move(0, -2);
  //solve(0);
  cout << a << endl;
  cout <<"1#" << r << endl;
  cout << "gap 0, 9 " << getGap(0, 9) << endl;
  cout << "gap 9, 0 " << getGap(9, 0) << endl;
  cout << "gap 1, 7 " << getGap(1, 7) << endl;
  return 0;
}
