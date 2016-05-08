#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_M 100

using namespace std;

int M;
int test;
vector<vector<int> >g;

int main() {  
  cin >> test;

  g = vector<vector<int> >(MAX_M, vector<int>(MAX_M, 0));

  while (test-- > 0) {
    cin >> M;
    for (int i = 0 ; i < M ; i++)
      for (int j = 0; j < M; j++)
        cin >> g[i][j];
  }
  cout << g.size() << endl;
  return 0;
}
