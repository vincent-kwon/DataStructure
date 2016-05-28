#include <iostream>

using namespace std;

#define MAX_N 20

int n, m;

double cache[MAX_N][2*MAX_N+1];

double climb(int days, int climbed) {
 
  cout << "clibm: days:" << days << "; climbed:" << climbed << endl;

  if (days == m) { 
    cout << "days == m , actual climbed (need climbed>=n to count) : " << climbed << ", n = " << n << endl;
    return climbed >= n ? 1 : 0;
  }

  double& ret = cache[days][climbed];
  if (ret != -1) {
    cout << "cached used: " << days << "," << climbed << endl;
    return ret;
  }

  cout << "enter: " << days << "," << climbed << endl;; 
  return ret = 0.5 * climb(days+1, climbed+1) + 0.5 * climb(days+1, climbed+2);
}

int main() {
  for (int i = 0 ; i < MAX_N; i++)
    for (int j = 0 ; j< 2*MAX_N+1 ; j++)
      cache[i][j] = -1;

  cout << " days : " << endl; 
  cin >> m; // 2 : 1, 2
            //     2, 3, 3, 4
            //
  
  cout << " km : " << endl;
  cin >> n; // 1 : 1, 2
  double r2 = climb(0,0);
  cout << r2 << endl;
}
