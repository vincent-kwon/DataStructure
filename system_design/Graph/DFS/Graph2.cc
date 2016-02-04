#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class TheGraph {
 protected:
  struct Edge {
    Edge* next;
    int weight;
    int target;
    int source;
  };

  struct Node {
    int value;
    Edge* edgeList;
    int isVisited;
    int minSum;
    Edge* prev;
  };
  Node** nodeList;

 public:
  typedef enum {
    DFS = 0, 
    BFS = 1,
    DIK = 2
  } WAY;

  typedef enum {
    NO_VISIT = 0,
    VISITING = 1,
    VISITED = 2
  } NODE_COLOR;

  TheGraph(int s) : size_(s) {
    nodeList = new Node* [s];
    for (int i = 0 ; i < size_ ; i++) {
      nodeList[i] = new Node();
      nodeList[i]->isVisited = NO_VISIT;
      nodeList[i]->edgeList = NULL;
      nodeList[i]->value = i;
      nodeList[i]->minSum = INT_MAX;
      nodeList[i]->prev = NULL;
    }
  };

  ~TheGraph() {
    for (int i = 0 ; i < size_; i++) {
      Node* node = nodeList[i];
      Edge* tmp = node->edgeList;
      Edge* toDel;

      while (tmp) {
        toDel = tmp;
        tmp = tmp->next;
        delete toDel;
        cout << "." ;
      }
      
      delete node;
    }

    delete nodeList;
  };
  
  TheGraph(const TheGraph& d) = delete;
  
  void operator=(TheGraph& d) = delete;

  void addEdge(int s, int e, int w) {
    Edge* newEdge = new Edge();
    newEdge->next = NULL;
    newEdge->weight = w;
    newEdge->target = e;
    newEdge->source = s;

    if (nodeList[s]->edgeList == NULL) {
      nodeList[s]->edgeList = newEdge;
    }
    else {
      Edge* tmp = nodeList[s]->edgeList;
      nodeList[s]->edgeList = newEdge;
      newEdge->next = tmp;
    }
  };
  
  void printEdges(int i) {
    Node* n = nodeList[i];
    Edge* tmp = n->edgeList;

    while (tmp) {
      cout << tmp->source << ", "<< tmp->target;
      tmp = tmp->next;
    }
    cout << " " << endl;
  };
  
  void printVector(vector<int>& path) {
    cout << "print: " << endl;
    for (auto& v : path) {
      cout << v << endl;
    }
  }
  
  int getNextClosest(vector<int>& v, int* prev, int *value) {
    int minDistance = INT_MAX;
    int nextNum;

    for (auto i : v) {
      Node* n = nodeList[i];
      Edge* tmp = n->edgeList;
      while (tmp) {
        if (nodeList[tmp->target]->isVisited == NO_VISIT && tmp->weight < minDistance) {
          minDistance = tmp->weight;
          nextNum = tmp->target;
          nodeList[nextNum]->prev = tmp; // save prev with this edge
        }
        tmp = tmp->next;
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
      Edge* tmp = nodeList[start]->edgeList; 

      while (tmp) {
        int val;
        if (tmp->target == end) {
          val = accum + tmp->weight;
        } 
        else {
          val = findShortest(tmp->target, end, w, accum + tmp->weight, path);
        }
        (min > val)? min = val : min;
        tmp = tmp->next;
      }

      path.pop_back();

      nodeList[start]->isVisited = VISITING;
      nodeList[start]->minSum = min - accum;

      if (min != INT_MAX) {
        return min;
      }
      else {
        return INT_MAX;
      }
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
              Edge* tmp = nodeList[popedValue]->edgeList;
              while (tmp) {
                queue.push(tmp->target);
                tmp = tmp->next;
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
        int nextSmall = getNextClosest(v,&prev, &value);
 
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
  int val = dfs.findShortest(0, numNodes-1, TheGraph::BFS, 0, v);
  cout << "Final: " << val << endl;
  return 1;
}
