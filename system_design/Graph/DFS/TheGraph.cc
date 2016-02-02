#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class TheGraph {
 public:
  typedef enum {
    DFS, BSF
  } WAY;

  typedef enum {
    NO_VISIT = 0,
    VISITING = 1,
    VISITED = 2
  } NODE_COLOR;

  TheGraph(int s) : size_(s) {
    eArray = new Edge* [s]; //new in constructor good or bad?
    pathMinArray = new int [s];
    isVisitedArray = new int [s];
    prepareSearch();
  };

  ~TheGraph() {
    for (int i = 0 ; i < size_; i++) {
      Edge* tmp = eArray[i];
      Edge* toDel;

      while (tmp) {
        toDel = tmp;
        tmp = tmp->next;
        delete toDel;
        cout << "." ;
      }
    }

    if (eArray) {
      delete eArray;
    }
   
    if (isVisitedArray) {
      delete isVisitedArray;
    }
 
    if (pathMinArray) {
      delete pathMinArray;
    }
  };
  
  TheGraph(const TheGraph& d) = delete;
  
  void operator=(TheGraph& d) = delete;

  void addEdge(int s, int e, int w) {
    Edge* newEdge = new Edge();
    newEdge->next = NULL;
    newEdge->weight = w;
    newEdge->target = e;

    if (eArray[s] == NULL) {
      eArray[s] = newEdge;
    }
    else {
      Edge* tmp = eArray[s];
      do {
        if (tmp->next == NULL) {
          tmp->next = newEdge;
          break;
        } 
        else {
          tmp = tmp->next;
        }
      } while (1);
    }
  };
  
  void prepareSearch() {
    for (int i = 0; i < size_; i++) {
      eArray[i] = NULL;
      pathMinArray[i] = INT_MAX;    
      isVisitedArray[i] = NO_VISIT;
    }
  };

  void printEdges(int i) {
    Edge* tmp = eArray[i];

    while (tmp) {
      cout << tmp->target << ", " ;
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
  
  int findShortest(int start, int end, TheGraph::WAY w, int accum, vector<int>& path) {
    int min = INT_MAX;
    if (w == DFS) {
      Edge* tmp = eArray[start];

      if (isVisitedArray[start] == VISITED) { 
        return accum + pathMinArray[start];
      }
      
      vector<int>::iterator itor = find(path.begin(), path.end(), start);
      if (itor != path.end()) {
        return INT_MAX;
      }
      else {
        path.push_back(start); 
      }
      
      isVisitedArray[start] = VISITING;

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

      isVisitedArray[start] = VISITING;
      pathMinArray[start] = min - accum;

      if (min != INT_MAX) {
        return min;
      }
      else {
        return INT_MAX;
      }
    }
    else { // Kevin Bacon BFS
      /*
       * 0. add queue
       * 1. pop queue as much as size of queue
       * 2. as poping add all its child to queue again unless it is target
       * 3. if all poped (as size), increase size of connect 
       */
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
            if (isVisitedArray[popedValue] == NO_VISIT) {
              isVisitedArray[popedValue] = VISITING;
              Edge* tmp = eArray[popedValue];
              while (tmp) {
                queue.push(tmp->target);
                tmp = tmp->next;
              }
              isVisitedArray[popedValue] = VISITED;
            }
          }
        }
      }      
      return min;  
    }
  };
 protected:
  struct Edge {
    Edge* next;
    int weight;
    int target;
  };
  Edge** eArray; 
  int* pathMinArray; 
  int* isVisitedArray;
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
  int val = dfs.findShortest(0, numNodes-1, TheGraph::BSF/*TheGraph::DFS*/, 0, v);
  cout << "Final: " << val << endl;
  return 1;
}
