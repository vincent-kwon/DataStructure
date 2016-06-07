#include <iostream>

using namespace std;

int countCache[100][100];
int n, triangle[100][100];
int cache2[100][100];

int path2(int y, int x) {
  if (y == n-1) return triangle[y][x];
  //memo
  int& ret = cache2[y][x];
  if (ret != -1) return ret;
  return ret = max(path2(y+1, x), path2(y+1, x+1))  + triangle[y][x];
}

int count(int y, int x) {
  if (y == n-1) return 1;
  
  int& ret = countCache[y][x];
  if (ret != -1) return ret;

  ret = 0;
  
  if (path2(y+1, x+1) >= path2(y+1, x)) ret += count(y+1, x+1);
  if (path2(y+1, x+1) <= path2(y+1, x)) ret += count(y+1, x);
}

int main() {
  triangle[0][0] = 6;
  triangle[1][0] = 1;
  triangle[1][1] = 2;
  triangle[2][0] = 3;
  triangle[2][1] = 7;
  triangle[2][2] = 4;
  
  n = 3;

  for (int i = 0 ; i < n ; i++)
    for (int j = 0; j < n; j++)
      cache2[i][j] = -1;

//  int r = path2(0,0);
  int r = count(0,0);
  cout << r << endl;

  return 0;
}
