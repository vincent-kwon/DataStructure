#include <iostream>

using namespace std;

#define N 5 
int left[N];
int right[N]; 
#define INT_MIN (1<<31) 
#define INT_MAX (((unsigned int)(INT_MIN))-1)

int p[N+1] = {2, 3, 6, 4, 5};

int m[N][N];

int MatrixChainOrderDP() { // 1 << << n
 
  int i, j, k, L, q;
  int n = N;

  // length 1
  for (int i = 1 ; i < n; i++) // why not i is zero?
    m[i][i] = 0;

  // length 2 to N
  for (L = 2; L < n; L++) 
  {
    for (i = 1; i <= (n-L+1); i++) // for all valid i
    {
      j = i + L - 1; // j indicates end index
      m[i][j] = INT_MAX;
      for (k = i; k <= j-1; k++) // between i < k < j
      {
        q = m[i][k] + m[k+1][j] + p[i-1]*p[k]*p[j];
        if (q < m[i][j]) m[i][j] = q;
      }
    }
  }

  return m[1][n-1];
}

int main() 
{
  int r = MatrixChainOrderDP();
  cout << r << endl;
  return 0;
}
