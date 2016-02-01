#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>

using namespace std;

class DFSGraph {
 public:
  typedef enum {
    DFS, BSF
  } WAY;
  DFSGraph(int s) : size_(s) {
    eArray = new Edge* [s]; //new in constructor good or bad?
    pathMinArray = new int [s];
    isVisitedArray = new bool [s];

    for (int i = 0; i < s; i++) {
      eArray[i] = NULL;
      pathMinArray[i] = INT_MAX;    
      isVisitedArray[i] = false;
    }
  };
  ~DFSGraph() {
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
  DFSGraph(const DFSGraph& d) = delete;
  void operator=(DFSGraph& d) = delete;

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
  
  int findShortest(int start, int end, DFSGraph::WAY w, int accum, vector<int>& path) {
    if (w == DFS) {
      Edge* tmp = eArray[start];
      int min = INT_MAX;

      if (isVisitedArray[start] == true) { 
        if (pathMinArray[start] != INT_MAX) {
          path.push_back(start);
          cout << "Found : " << accum + pathMinArray[start] << "," << pathMinArray[start] << endl;
          printVector(path);
          cout << "Got " << endl;
          path.pop_back();
          return accum + pathMinArray[start];
        } 
        else {
          return INT_MAX;
        }
      }
      
      vector<int>::iterator itor = find(path.begin(), path.end(), start);
      if (itor != path.end()) {
        cout << "cycle " << endl;
        path.push_back(start);
        printVector(path);
        path.pop_back();
        isVisitedArray[start] = true;
        pathMinArray[start] = INT_MAX;
        return min;
      }
      else {
        path.push_back(start); 
      }
      
      while (tmp) {
        int val;
        //cout << start << " to " << tmp->target << " " << accum << endl;
        if (start == tmp->target) {
          tmp = tmp->next;
          continue;
        }
        else if (tmp->target == end) {
          val = accum + tmp->weight;
          cout << "found the target " << end << ": " << val << endl;
          if (min > val) { 
            path.push_back(tmp->target);
            printVector(path);
            path.pop_back();
          }
        } 
        else {
          val = findShortest(tmp->target, end, w, accum + tmp->weight, path);
        }
        (min > val)? min = val : min;
        tmp = tmp->next;
      }

      path.pop_back();

      isVisitedArray[start] = true;
      pathMinArray[start] = min - accum;

      if (min != INT_MAX) {
        return min;
      }
      else {
        return INT_MAX;
      }
    }
    else {
      return 0;
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
  bool* isVisitedArray;
private: 
  int size_;
};


int main() {
  int numNodes;
  int m[100][100];

  cin >> numNodes;
  DFSGraph dfs(numNodes);

  for (int i = 0; i < numNodes; i++) {
    for (int j = 0; j < numNodes; j++) {
      cin >> m[i][j];
      if (m[i][j] != 0)
        dfs.addEdge(i, j, m[i][j]);
    }
  }
  vector<int> v;
  int val = dfs.findShortest(0, numNodes-1, DFSGraph::DFS, 0, v);
  cout << "Final: " << val << endl;
  return 1;
}
