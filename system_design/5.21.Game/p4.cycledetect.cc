#include <iostream>

using namespace std;

#define NUM 5

int g[NUM][NUM] = {0, };

int find_array[NUM]; 
int find_index = -1;
int visited_array[NUM] = {0, };

int l[NUM][NUM] = {
  {1,0,2,1}, //1
  {2,1,3,2}, //2
  {3,0,4,1}, //3
  {4,1,4,2}, //4
  {3,2,3,4}
};

int m[NUM][NUM] = {
  {0, 0, 0, 0, 0},
  {1, 1, 0, 0, 0},
  {1, 2, 2, 0, 0},
  {3, 3, 2, 5, 0},
  {3, 4, 5, 5, 0}
};

void dfs(int i) {
  if (visited_array[i]) return;
  
  visited_array[i] = true;
  for (int j = 0 ; j < NUM ; j++) {
    if (g[i][j] != 0) {
      dfs(j);
    }
  }
  find_array[++find_index] = i;
}

bool checkTopology() {
  for (int i = 0 ; i < NUM; i++) {
    int y1 = l[i][0],
        x1 = l[i][1],
        y2 = l[i][2],
        x2 = l[i][3];
    for (int k = y1; k <= y2; k++) {
      for (int p = x1; p <= x2; p++) {
        if (m[k][p] != (i+1)) {
          // precedent
          g[i][m[k][p]-1] = 1;
        } 
      }
    }
  }
 
  for (int i = 0; i < NUM; i++) {
    for (int j = 0; j < NUM; j++) {
      cout << g[i][j] << " ";
    }
    cout << " " << endl;
  }
 
  // DFS until all visited
  for (int i = 0; i < NUM; i++) {
    dfs(i);
  }

  // reverse visited array
  for (int i = 0; i <= find_index; i++) 
    cout << "visit : " << find_array[i] << endl;

  for (int j = find_index; j >= 0; j--) {
    for (int k = j - 1; k >= 0; k--) {
      if (g[find_array[k]][find_array[j]] != 0) {
        cout << "found cycle at " << find_array[k] << " to " << find_array[j] << endl;
        return false;
      }
    }
  }
  // if any acycle found, return false
  // else return true;
  return true;
}

int main() {

  if (checkTopology()) cout << "No cycle" << endl;
  else cout << "Cycle" << endl;
  
  return 0;
}
