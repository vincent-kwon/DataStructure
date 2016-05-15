#include <iostream>
#include <vector>

using namespace std;

#define INT_MIN (1<<31)
#define LONG_MIN (((long long)1)<<63)
#define INT_MAX (((unsigned int)INT_MIN) - 1)
#define LONG_MAX (((unsigned long long)LONG_MIN)-1)
#define MAX(a,b) ((a)>=(b)?(a):(b))

int cache2[101][101];
int A[100];
int B[100];
int n;
int m;

int jlis2(int indexA, int indexB) {
  int &ret = cache2[indexA+1][indexB+1];
  if (ret != -1) return ret;
  ret = 2; // at least 2 since a, b
  long long a = (indexA == -1 ? LONG_MIN : A[indexA]);
  long long b = (indexB == -1 ? LONG_MIN : B[indexB]);
  long long maxElement = MAX(a,b);

  for (int nextA = indexA + 1; nextA < n; ++nextA)
    if (maxElement < A[nextA])
      ret = MAX(ret, jlis2(nextA, indexB) + 1);

  for (int nextB = indexB + 1; nextB < m; ++nextB)
    if (maxElement < B[nextB])
      ret = MAX(ret, jlis2(indexA, nextB) + 1);

  return ret;
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    int len1, len2;
    cin >> len1;
    cin >> len2;

    int i1 = 0;
    int i2 = 0;

    n = len1;
    m = len2;

    while (i1 < len1) {
      cin >> A[i1++];      
    }
    
    while (i2 < len2) {
      cin >> B[i2++];
    }

    int max = INT_MIN;
    int common = 0;
    
    for (int k = 0 ; k < 101; k++) 
      for (int p = 0 ; p < 101; p++) 
        cache2[k][p] = -1;

    max = jlis2(-1, -1);
    cout << max - 2 << endl;
  }
  return 0;
}
