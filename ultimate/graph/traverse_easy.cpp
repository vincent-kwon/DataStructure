#include <stdio.h>
#include <iostream>

using namespace std;
/*
 * From given start point (r,c), and end point to a matrix filled with values,
 * find maximum sum of area must start from start point. End can't be bigger than
 * end point.
 *
 * 
 */
int M[300][300] = {0, };
int C[300] = {0, };
int V[300] = {0, };
int N;
int E;

void visit(int nextNode) {
  if (V[nextNode] == 0) {
    V[nextNode] = 1; // visited
    C[nextNode] = 1; // to white
    cout << " " << nextNode ;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (i == nextNode && M[i][j] == 1 && V[j] == 0) {
          visit(j);
        }
      }         
    }
    cout << " " << endl;
    V[nextNode] = 0;
  }
}

int main() {
  int test;
  int i,j,k;
  int start, end;

  scanf("%d", &test);
  while (test-- > 0) {
    scanf("%d %d", &N,&E);      
    for (j = 0; j < E; j++) {
      scanf("%d %d", &start, &end);
      M[start][end] = 1;
    }
  }

  // dfs for all nodes
  for (int i = 0 ; i < N ; i++) {
    // start from i, visit until all nodes are visited
    cout << "start at: " << i << endl;
    visit(i); 
  }
  return 1;
}
