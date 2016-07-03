#include <iostream>

using namespace std;

int N;
int M[100][100];

int findMinByDFS() {
  return 0;
}

int findMinByBFS() {
  return 0;
}

int main() {
  cin >> N;
  
  for (int i = 0 ; i < N; i++) 
    for (int j = 0; j < N; j++)
      cin >> M[i][j];

  // DFS
  int r1, r2;

  r1 = findMinByDFS();
  r2 = findMinByBFS();

  cout << r1 << endl;
  cout << r2 << endl;
  return 0;
}
