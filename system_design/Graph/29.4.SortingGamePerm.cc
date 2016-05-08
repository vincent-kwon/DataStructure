#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

map<vector<int>, int> toSort;
int gCount;

void precalc(int n) {
  vector<int> perm(n);
  gCount = 0;
  for (int i = 0; i < n; ++i) perm[i] = i;
  queue<vector<int> > q;
  gCount++;
  q.push(perm);
  toSort[perm] = 0;
  while (!q.empty()) {
    vector<int> here = q.front();
    q.pop();
    int cost = toSort[here];
    for(int i = 0; i < n; i++) {
      for(int j = i+2; j <= n; j++) {
        reverse(here.begin() + i, here.begin() + j);
        if(toSort.count(here) == 0) { // same as found
          toSort[here] = cost + 1;
          for_each(here.begin(), here.end(), [](int i) { cout << i << " "; });
          cout << " distance: " << toSort[here] << " "; 
          cout << "" << endl;
          gCount++;
          q.push(here);
        }
        reverse(here.begin() + i, here.begin() + j);
      }
    }
  }  
}

int main() {
  precalc(8);
  cout << gCount << endl;
  return 0;
}
