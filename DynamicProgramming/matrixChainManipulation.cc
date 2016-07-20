#include <iostream>
#include <vector> 

using namespace std;

int MatrixChainOrder(int p[], int i, int j, int len, vector<char> v) 
{
  //cout << "(" << i << "," << j << ")" << endl;
  if (i == j) {
    v.push_back(p[i]);
    return 0;
  }

  int k;
  int min = 987654321;
 
  // (0,1), (2)
  //  
  for (k = i; k < j; k++) 
  {
    v.push_back('(');
    MatrixChainOrder(p, i, k, len,v); // 0,0 
    v.push_back(',');
    MatrixChainOrder(p, k+1, j, len,v); 
    v.push_back(')');
  }
}

int main() {
  int arr[] = {1,2,3,4};
  int n = sizeof(arr)/sizeof(arr[0]);
  vector<char> v;
  int min = MatrixChainOrder(arr, 0, n-1, n, v); // (1,4)
  cout << "Min: " << min << endl;
  return 1;
}
