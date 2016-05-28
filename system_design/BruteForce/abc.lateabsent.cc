#include <iostream>

using namespace std;

#define MAX_N 20

int n, m;

double cache[MAX_N][2*MAX_N+1];

double attend(int days, string attended) {
 
  cout << "clibm: days:" << days << "; attended:" << attended << endl;

  if (days == m) { 
    cout << "days == m , actual attended (need attended>=n to count) : " << attended << ", n = " << n << endl;
    return attended >= n ? 1 : 0;
  }

  double& ret = cache[days][attended];
  if (ret != -1) return ret;

  cout << "enter: " << days << "," << attended << endl;; 
  return ret = 0.5 * attend(days+1, attended+1) + 0.5 * attend(days+1, attended+2);
}

int main() {
  for (int i = 0 ; i < MAX_N; i++)
    for (int j = 0 ; j< 2*MAX_N+1 ; j++)
      cache[i][j] = -1;

  cout << " days : " << endl; 
  cin >> m; // 2 : 1, 2
            //     2, 3, 3, 4
            //
  
  cout << " consecutive : " << endl;
  cin >> n; // 1 : 1, 2
  double r2 = attend(0,"");

  cout << r2 << endl;
}
