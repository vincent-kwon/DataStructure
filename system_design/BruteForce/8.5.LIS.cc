#include <iostream>
#include <vector>

using namespace std;

#define INT_MIN (1<<31)
#define INT_MAX (((unsigned int)INT_MIN) - 1)

#define MAX(a,b) ((a)>=(b)?(a):(b))

int cache[100];

int jlis(int a[], int index, int len) {
  int& ret = cache[index];
  if (ret != -1) return cache[index];
  else {
    ret = 1;
    for (int i = index+1 ; i < len ; i++) {
      if (a[index] < a[i]) {
        ret = MAX(ret, jlis(a, i, len)+1);
      }
    }
    return ret;
  }
}

int cache2[101][101];
int A[100];
int B[100];
int n;
int m;

int jlis2(int indexA, int indexB) {
  int &ret = cache2[indexA+1][indexB+1];
  if (ret != -1) return ret;
  ret = 2; // at least 2 since a, b
  long long a = (indexA == -1 ? INT_MIN : A[indexA]);
  long long b = (indexB == -1 ? INT_MIN : B[indexB]);
  long long maxElement = MAX(a,b);

  for (int nextA = indexA + 1; nextA < n; ++nextA)
    if (maxElement < A[nextA])
      ret = MAX(ret, jlis2(nextA, indexB) + 1);
  for (int nextB = indexB + 1; nextB < m; ++nextB)
    if (maxElement < B[nextB])
      ret = MAX(ret, jlis2(indexB, nextB) + 1);

  return ret;
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    int len1, len2;
    cin >> len1;
    cin >> len2;

    int a1[100];
    int a2[100];

    int i1 = 0;
    int i2 = 0;

    while (i1 < len1) {
      cin >> a1[i1++];      
    }
    
    while (i2 < len2) {
      cin >> a2[i2++];
    }

    int max = INT_MIN;
    int common = 0;
    // len1 + len2 - common
    // just need to know common
    // Case 1. Special case
    /*
    for (int i = 0; i < len1; i++) 
      for (int j = 0; j < len2; j++)
        if (a1[i] == a2[j]) common++;
    max = len1 + len2 - common;
    cout << max << endl;
    */
    // Case 2. memoization
    for (int k = 0 ; k < 100; k++) {
      cache[k] = -1;
    }
    max = jlis(a1, 0, len1);
    cout << max << endl;
  }
  return 0;
}
