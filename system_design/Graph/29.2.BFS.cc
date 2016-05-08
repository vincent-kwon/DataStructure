#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX_NODE 5

vector<vector<int> > adj;

void bfs2(int start, vector<int>& distance, vector<int>& parent) 
{
  distance = vector<int>(adj.size(), -1);
  parent = vector<int>(adj.size(), -1);

  queue<int> q;
  distance[start] = 0;
  q.push(start);
  while (!q.empty()) {
    int here = q.front();
    q.pop();
    for (int i = 0; i < adj[here].size(); i++) 
    {
      int there = adj[here][i];
      if (distance[there] == -1) {
        q.push(there);
        distance[there] = distance[here] + 1;
        parent[there] = here;
        cout << "add new parent " << here  << " for  " << there << endl;
      }
    }
  }
}

vector<int> shortestPath(int v, const vector<int>& parent) {
  vector<int> path(1, v);
  while(parent[v] != v) {
    v = parent[v];
    path.push_back(v);
  }
  reverse(path.begin(), path.end());
  return path;
}

int main() 
{
  srand(time(NULL));
  adj = vector<vector<int> >(MAX_NODE,  vector<int>(MAX_NODE, 0));
  for (int i = 0 ; i < MAX_NODE; i++) 
  {
    for (int j = 0; j < MAX_NODE; j++)
    {
      if ((i != j) && (rand() % 2 == 0))
      {
        adj[i].push_back(j); 
        cout << i << "," << j << endl;
      }
    }
  }
  vector<int> distance;
  vector<int> parent;
  bfs2(0, distance, parent);
  for (int i = 0 ; i < MAX_NODE; i++) 
  {
    cout << i << "," << distance[i] << endl;
  }
  for (auto i : parent)
    cout << i << endl;
  //shortestPath(1, parent);
  //shortestPath(3, parent); 
  //shortestPath(4, parent);
  return 0;
}

