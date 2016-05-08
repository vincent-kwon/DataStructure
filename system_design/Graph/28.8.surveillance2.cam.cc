#include <iostream>
#include <vector>

using namespace std;

#define MAX_V 1000
int V;
int H;

vector<int> adj[MAX_V]; // vector array, interesting....
vector<bool> visited;
const int UNWATCHED = 0;
const int WATCHED = 1;
const int INSTALLED = 2;

int installed = 0;

int dfs(int here) 
{
  visited[here] = true; 
  int children[3] = { 0, 0, 0 }; // local array

  // The key is this. check all children and whether there exists children
  for (int i = 0; i < adj[here].size() ; i++) 
  {
    int there = adj[here][i];
    if (!visited[there]) 
      ++children[dfs(there)]; // dfs return value can be index
  }

  if (children[UNWATCHED]) {
    ++installed;
    return INSTALLED;
  }
  if (children[INSTALLED])
    return WATCHED;
  return UNWATCHED;
}

int main() 
{
  int test;
  cin >> test;
  while (test-- > 0)
  { 
    cin >> V;
    cin >> H;

    for (int i = 0 ; i < MAX_V; i++)
      adj[i].clear();

    for (int i = 0 ; i < H; i++) 
    {
      int first, second;
      cin >> first;
      cin >> second;
      adj[first].push_back(second);
      adj[second].push_back(first);
    }
    
    installed = 0;
    visited = vector<bool>(V, false);
    for (int u = 0; u < V; ++u)
    {
      if (!visited[u] && dfs(u) == UNWATCHED)
        ++installed;
    }
    cout << installed;
  }
  return 0;
}
