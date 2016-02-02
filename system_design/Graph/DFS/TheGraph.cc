#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

class TheGraph {
 public:
  typedef enum {
    DFS = 0, 
    BSF = 1,
    DIK = 2
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
    prevEdgeArray = new int [s];
    prevValueArray = new int [s];
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
 
    if (prevEdgeArray) {
      delete prevEdgeArray;
    }

    if (prevValueArray) {
      delete prevValueArray;
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
      prevEdgeArray[i] = -1;
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
  
  int getNextClosest(vector<int>& v, int* prev, int *value) {
    int minDistance = INT_MAX;
    int nextNum;

    for (auto i : v) {
      Edge* tmp = eArray[i];
      while (tmp) {
        if (isVisitedArray[tmp->target] == NO_VISIT && tmp->weight < minDistance) {
          minDistance = tmp->weight;
          *value = tmp->weight;
          nextNum = tmp->target;
          *prev = i;
        }
        tmp = tmp->next;
      } 
    }
    return nextNum;
  }

  int backTrack(int start, int end) {
    int accum = 0;
    int next = end;
    cout << "node: " << next <<  " " << accum << endl;
    while (1) {
      int prev = prevEdgeArray[next];
      accum += prevValueArray[next];
      cout << "node: " << prev << " " << accum << endl;
      if (prev == start)
        return accum;
      else
        next = prev;
    }
    return -1; // if can't back track;
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
    else if (w == BSF) { // Kevin Bacon BFS
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
    else if (w == DIK) {
      vector<int> v;
      int accum = 0;
      isVisitedArray[start] = VISITED;
      prevEdgeArray[start] = -1;
      prevValueArray[start] = 0; 
      v.push_back(start);

      for (int i = 0; i < size_ ; i++) {
        int prev; 
        int value;
        int nextSmall = getNextClosest(v,&prev, &value);
        // cout << nextSmall << ", from " << prev << " by " << value << endl;
        if (nextSmall == end) {
          // go back to the start and return accum of weight
          //cout << "found target ... " << endl;
          prevEdgeArray[nextSmall] = prev;
          prevValueArray[nextSmall] = value;
          accum = backTrack(start, nextSmall);
          return accum;
        }
        else {
          isVisitedArray[nextSmall] = VISITED;
          prevEdgeArray[nextSmall] = prev;
          prevValueArray[nextSmall] = value;
          v.push_back(nextSmall);
        }
      }
      return min; // could not find
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
  int* prevEdgeArray;
  int* prevValueArray;
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
