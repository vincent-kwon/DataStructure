#include <iostream>
#include <vector>
#include <queue>

#define INF ((unsigned int)(1<<31) - 1)
#define min(a,b) ((a)<=(b))?(a):(b)

using namespace std;

const int MAX_N = 10;

int dikstra(int g[][MAX_N], int nodes, int begin, int end) {
  //cout << begin <<" ,  "<< end << endl;

  if (begin == end) return 0;

  bool visited[MAX_N] = {0, };

  int d[MAX_N] = {INF, };

  queue<int> q;

  for (int j = 0; j < nodes; j++) 
    d[j] = INF;

  int ret = 0;

  q.push(begin);

  d[begin] = 0;

  while (!q.empty()) {
    int here = q.front();
    int closest_value = INF;
    int closest_node = INF;

    q.pop();

    //cout << "here : " << here << endl;

    if (here == end) {
      //cout << "return : " << here << " => " << d[here] << endl;
      return d[here];
    }

    if (visited[here] == true) continue; 
    else visited[here] = true;
   
    for (int i = 0; i < nodes; i++) {
      if ((i != here) && (g[i][here] != -1) && (visited[i] == false)) {
        //cout << "before: d[" << i << "] = " << d[i] << " d[here] = " << d[here] << " g[i][here]:" << g[i][here]  << endl;
        d[i] = min(d[i], d[here]+g[i][here]);
        //cout << "after: d[" << i << "] = " << d[i] << endl;
        if (d[i] <= closest_value) {
          closest_value = d[i];
          closest_node = i;
        }
      }
    }

    // now closest should be pushed.
    q.push(closest_node);
  }
  
  return -1;
}

int main() {
  int test;
  cin >> test;
  while (test-- > 0) {
    int graph[MAX_N][MAX_N] = {0, };
    int nodes;
    int edges;
    int first;
    int second;
    int value;
    int beginNode;
    int endNode;

    cin >> nodes;
    cin >> edges;

    beginNode = 0;
    endNode = nodes - 1;

    for (int i = 0; i < nodes; i++)
      for (int j = 0; j < nodes; j++)
        graph[i][j] = -1;

    for (int i = 0; i < edges; i++) {
      cin >> first;
      cin >> second;
      cin >> value;
      graph[first][second] = value;
      graph[second][first] = value;
      //cout << "g:" << graph[first][second] << endl;
    }
    int ret = dikstra(graph, nodes, beginNode, endNode);
    cout << "dikstra returned: " << ret << endl;
  }  
  return 0;
}
