#include <iostream>

using namespace std;

const int MOD = 10*1000*1000;

int test;
int num;

int cache[101][101];

int poly(int n, int first) {
  if (n == first) return 1;
  int& ret = cache[n][first];
  if (ret != -1) return ret;
  ret = 0;
  for (int second = 1; second <= n-first; ++second) {
    int add = second + first - 1; // all possibility between first and second
    add *= poly(n - first, second); // now 
    add %= MOD;
    ret += add;
    ret %= MOD;
  }
  return ret;
}

int main() {
  cin >> test;

  while (test-- > 0) {
    cin >> num;

    unsigned int sum = 0;

    for (int i = 0; i < 101; i++)
      for (int j = 0 ; j < 101; j++)
        cache[i][j] = -1;

    for (int i = 1; i <= num; i++) {
      sum += poly(num, i);
    }
    cout << "sum: " << sum << endl;
  }
  return 0;
}
