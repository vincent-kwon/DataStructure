#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <list> 

using namespace std;

// TODO 
// shared pointer
// add exception 
// thread safe 
// encapsulation
// scalability
// deallocating resource
// template

class TheGraph {
 protected:
  class Edge {
   public: // TODO: visibility of Edge class
    int weight;
    int target;
    int source;
  };

  class Node {
   public:
    int value;
    list<Edge*> edgeList; // no need to allocate memory until it is needed so list is better
    int isVisited;
    int minSum;
    Edge* prev;
  };

  vector<Node*> nodeList; // need to access a node using index so vector is better

 public:
  enum WAY {
    DFS = 0, 
    BFS = 1,
    DIK = 2
  };

  enum NODE_COLOR {
    NO_VISIT = 0,
    VISITING = 1,
    VISITED = 2
  };

  TheGraph(int s) : size_(s) {
    for (int i = 0 ; i < size_ ; i++) {
      Node* n = new Node();
      n->isVisited = NO_VISIT;
      n->value = i;
      n->minSum = INT_MAX;
      n->prev = NULL;
      nodeList.push_back(n);
    }
  };

  ~TheGraph() {
    //for (auto itorNode = nodeList.begin(); itorNode != nodeList.end(); itorNode++) {
      //for (auto itorEdge = itorNode->edgeList.begin(); itorEdge != itorNode->edgeList.end(); itorEdge++) {
       // cout << "delete edge: " << itorEdge->weight << endl;
     // }
   // }
  };
  
  TheGraph(const TheGraph& d) = delete;
  
  void operator=(TheGraph& d) = delete;

  void addEdge(int s, int e, int w) {
    Edge* newEdge = new Edge();
    newEdge->weight = w;
    newEdge->target = e;
    newEdge->source = s;
    nodeList[s]->edgeList.push_back(newEdge);
  };
  
  void printEdges(int i) {
    Node* n = nodeList[i];
    for_each(n->edgeList.begin(), n->edgeList.end(),  [=] (Edge* e) -> int { cout << "edge:" << e->target << endl; return 0; });
  };
  
  void printVector(vector<int>& path) {
    cout << "print: " << endl;
    for (auto& v : path) { // *itor is returned by : list // why auto & not just auto ?  
      cout << v << endl;
    }
  };
  
  int getNextClosest(vector<int>& v, int end) {
    int minDistance = INT_MAX;
    int nextNum;

    for (auto i : v) {
      Node* n = nodeList[i];
      for (auto j : n->edgeList) {
        if (nodeList[j->target]->isVisited == NO_VISIT && j->weight <= minDistance) {
          if (j->weight < minDistance || (j->weight == minDistance && j->target == end)) {
            minDistance = j->weight;
            nextNum = j->target;
            nodeList[nextNum]->prev = j;
          }
        }
      }
    }
    return nextNum;
  }

  int backTrack(int start, int end) {
    int accum = 0;
    int next = end;
    cout << "end : " << next << endl;
    while (1) {
      Edge* e = nodeList[next]->prev;
      accum += e->weight;
      cout << "prev is " << e->source <<  ", accum = " << accum << endl;

      if (e->source == start)
        return accum;
      else
        next = e->source;
    }
    return -1; // if can't back track;
  }

  int findShortest(int start, int end, TheGraph::WAY w, int accum, vector<int>& path) {
    int min = INT_MAX;
    if (w == DFS) {
      Node* n = nodeList[start];
      if (n->isVisited == VISITED) {
        return accum + n->minSum;
      }
      
      vector<int>::iterator itor = find(path.begin(), path.end(), start);

      if (itor != path.end()) {
        return INT_MAX;
      }
      else {
        path.push_back(start); 
      }
      
      nodeList[start]->isVisited = VISITING;
     
      for (auto &e : nodeList[start]->edgeList) {
        int val;
        if (e->target == end) {
          val = accum + e->weight;
        }
        else {
          val = findShortest(e->target, end, w, accum + e->weight, path);
        }
        min = (val < min? val: min);
      }
 
      path.pop_back();

      nodeList[start]->isVisited = VISITED;
      nodeList[start]->minSum = min - accum;

      return min;
    }
    else if (w == BFS) { // Kevin Bacon BFS
      queue<int> queue;
      queue.push(start);
      int count = -1;

      while (!queue.empty()) {
        int size = queue.size();
        count++;
        for (int i = 0; i < size; i++) {
          int popedValue = queue.front();
          queue.pop(); 
          if (popedValue == end) {
            return count;
          } 
          else {
            if (nodeList[popedValue]->isVisited == NO_VISIT) {
              nodeList[popedValue]->isVisited = VISITING;
              for (auto &e : nodeList[popedValue]->edgeList) {
                queue.push(e->target);
              }
              nodeList[popedValue]->isVisited = VISITED;
            }
          }
        }
      } 
      return min;  
    }
    else if (w == DIK) {
      vector<int> v;
      int accum = 0;
      nodeList[start]->isVisited = VISITED;
      v.push_back(start);

      for (int i = 0; i < size_ ; i++) {
        int prev; 
        int value;
        int nextSmall = getNextClosest(v, end);
 
        cout << nextSmall << endl;

        if (nextSmall == end) {
          accum = backTrack(start, nextSmall);
          return accum;
        }
        else {
          nodeList[nextSmall]->isVisited = VISITED;
          v.push_back(nextSmall);
        }
      }
      return min; // could not find
    }
  };

 private: 
  int size_;
};


int main() {
  int numNodes;
  int m[100][100];

  cin >> numNodes;
  TheGraph dfs(numNodes);

  for (int i = 0; i < numNodes; i++) {
    for (int j = 0; j < numNodes; j++) {
      cin >> m[i][j];
      if (m[i][j] != 0)
        dfs.addEdge(i, j, m[i][j]);
    }
  }
  vector<int> v;
  int val = dfs.findShortest(0, numNodes-1, TheGraph::DIK, 0, v);
  cout << "Final: " << val << endl;
  return 1;
}
