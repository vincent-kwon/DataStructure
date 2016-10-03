/*
 * 어떤 자물쇠가 있다
 *
 * N 자리수 이다 
 *
 * 최대 세 자물쇠를 동시에 움직일 수 있다
 *
 * 최소 움직임으로 정답을 찾아야 한다
 *
 * 예를 들어
 *
 * 3456
 *
 * 6789 
 *
 * 면 2번이다 
 *
 * 돌릴 수 있는 최대는 +3, -3 이다
 *
 * N은 50 자리 까지 가능하다
 *
 * 어떻게 할 것인가?
 *
 *
 */
#include <iostream>
#include <math.h>
#include <stdlib.h>

#define ASCII_ZERO 48

char a[51];
char t[51];
int digit;

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
  int value = a[index]-ASCII_ZERO;

  if (gap > 0) {
    int t = 10 - value;
    if (gap > t) newValue = gap - t; 
    else newValue = value + gap;
  }
  else {
    if (abs(gap) > value) newValue = 10 - (abs(gap) - value);
    else newValue = value - abs(gap);
  }
  a[index] = (char) (newValue + ASCII_ZERO);
}

int getGap(int current, int goal) {
  int tmp; 
  
  if (goal == current) return 0;
  else if (goal > current) tmp = goal - current; // 9 - 1 = 8 
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
  for (int i = start; i < digit && i <= end; i++) move(i, gap);
}

int solve(int index) {  
  int curr = a[index];
  int next = a[index+1];
  int r;
  int m = dp[index][curr-ASCII_ZERO][next-ASCII_ZERO];
  int g = getGap(curr, t[index]); // g can be + or - 
  
  //cout << "solve: " << a << " , index : " << index << " , curr : " << (char) curr << " gap: " << g << endl;
  if (m != -1) return m;

  if (index == digit-1) {
     if (g == 0) return 0;
     else if (g == 7 || g == 8 || g == 9) return 2;
     else return 1;  
  }
  
  if (abs(g) == 0) m = solve(index+1);     

  else if (abs(g) <= 3) {
    m = 987654321;
    for (int digitEnd = 0; digitEnd < 3; digitEnd++) {
      turn(index, index+digitEnd, g); // rotate
      int tmp = solve(index+1)+1;
      turn(index, index+digitEnd, -g); // back
      m = ((m>tmp)? tmp : m);
    }
  }

  else {
    m = 987654321;
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

  dp[index][curr-ASCII_ZERO][next-ASCII_ZERO] = m;
  cout << "dp["<< index << "][" << curr-ASCII_ZERO << "][" << next-ASCII_ZERO << "] : " << m << endl;
  return m;
}

int main() {
  cin >> digit;
  cin >> a;
  cin >> t;

  for (int i = 0 ; i < 50; i++) 
    for (int j = 0 ; j < 10; j++)
      for (int k = 0; k < 10; k++)
        dp[i][j][k] = -1; 
  int r = 0;
  r = solve(0);
  cout <<"1#" << r << endl;
  return 0;
}
