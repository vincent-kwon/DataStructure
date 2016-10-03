#include <iostream>
#include <vector>

using namespace std;

int N;
int M[100][100];
int C[100][100][4]; 

enum DIR {
  LTOR,
  RTOL,
  DTOU,
  UTOD
};


int findMinByDFS(int s_r, int s_c, int d_r, int d_c, int dir) {
  
  return 0;
}

int findMinByBFS() {
  
  return 0;
}

int main() {
  cin >> N;
  
  for (int i = 0 ; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> M[i][j];
      for (int k = 0 ; k < 4; k++) 
        C[i][j][k] = -1;
    }
  }

  // DFS
  int r1, r2;

  r1 = findMinByDFS(0,0,4,4,LTOR);
  r2 = findMinByBFS();

  cout << r1 << endl;
  cout << r2 << endl;
  return 0;
}
