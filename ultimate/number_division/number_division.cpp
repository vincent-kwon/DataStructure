#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
/*
 * From given start point (r,c), and end point to a matrix filled with values,
 * find maximum sum of area must start from start point. End can't be bigger than
 * end point.
 *
 * 
 */
//int M[300][300];
int N;
int M;

void getNumberDivision(int N, int M, vector<int> result) {
 
  if (N == 0) {
    vector<int>::iterator itor = result.begin();
    for (itor; itor != result.end(); itor++) {
      cout << *itor << " ";
    }
    cout << "" << endl;
    return;
  }  

  if (N < 0) {
    return;  
  }
  
  if (N < M) {
    M = N;
  }

  for (int i = 1 ; i <= M; i++) {
    result.push_back(i);
    getNumberDivision(N - i, i, result); 
    result.pop_back();
  }
}

int main() {
  int test;
  int i,j,k;

  scanf("%d", &test);
  while (test-- > 0) {
    scanf("%d %d", &N,&M);     
    vector<int> r;
    getNumberDivision(N,M,r); 
  }
}
