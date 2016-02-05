#include <iostream>
#include <limits.h>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

template <typename T>
class TheTree {
 protected:
  template <typename S>
  struct Node {
    Node(S v) {
      value = v;
    }
    T value;
    Node<S>* left;
    Node<S>* right;
    Node<S>* parent;
  };
  Node<T>* root;

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

  typedef enum {
    PRE = 0,
    IN = 1,
    POST = 2,
  } ORDER;

  TheTree(int s) : size_(s) {
    root = NULL;
  };

  ~TheTree() {
  };
  
  TheTree(const TheTree& d) = delete;
  
  void operator=(TheTree& d) = delete;
  
  void addNode(T value) {
    Node<T>* tmp;
 
    if (root == NULL) {
      cout << "root" << endl;
      root = new Node<T>(value);
      return;
    } 

    tmp = root;

    while (tmp) {
      T t = tmp->value;
      if (value < t) {
        if (tmp->left) {
          tmp = tmp->left;
        } else {
          Node<T>* newNode = new Node<T>(value);
          cout << " add : " << value << endl;
          tmp->left = newNode;
          return;
        }
      } 
      else if (value == t) {
        // do not duplicate
        return; 
      }
      else if (value > t) {
        if (tmp->right) {
          tmp = tmp->right;
        } else {
          Node<T> *newNode = new Node<T>(value);
          cout << " add : " << value << endl;
          tmp->right = newNode;
        }
      }
    }
  };

  void deleteNode(Node<T>* n) {

  };

  Node<T>* findNode(T value) {
    Node<T>* tmp = root;
    while (tmp) {
      int t = tmp->value;
      if (value == t) {
        return tmp;
      } else if (value < t) {
        tmp = tmp->left;
      } else if (value > t) {
        tmp = tmp->right;
      }
    }
    return NULL;
  };

  int traverse(Node<T>* start, TheTree::WAY w, TheTree::ORDER o) {
    int min = INT_MAX;
    
    if (!start) return 0;

    if (w == DFS) {
      if (o == TheTree::PRE) {
        cout << start->value << endl;
      }
 
      traverse(start->left, w, o);

      if (o == TheTree::IN) {
        cout << start->value << endl;
      } 
     
      traverse(start->right, w, o);
      if (o == TheTree::POST) {
        cout << start->value << endl;
      }
    } 
    else if (w == BFS) {
      queue< Node<T>* > queue;
      
      queue.push(start);

      while (!queue.empty()) {
        int s = queue.size();

        for (int i = 0 ; i < s ; i++)  {
          Node<T>* n = queue.front();
          queue.pop();
          cout << "visit: " << n->value << endl;
          if (n->left) { queue.push(n->left); }
          if (n->right) { queue.push(n->right); }     
        }
      } 
    }
    return 0;
  };
  // 1. check balance
  bool isBalanced() {
   //if left and right diff is 1, balanced

  };

  // 2. check height
  int getMaxHeight() {

  };
 
  // 3. get common ancestor
  int getCommonAncestor(Node<T>* a, Node<T>* b) { 
    return 0;
  };

  // 4. level print
  void printSizeOfLevels() {

  };

  // 5. serial / deserial
  string serialize() {
    return;
  };

  void deserialize(string s) {
  };

  // 6. subtree, including equal 
  bool isSubtree(TheTree& t) {
    return true;
  };

  // 7. find closest num
  Node<T>* findClosestNumber(T t) { //only for int
    return NULL;
  };

  // 8. find consecutive num
  void printConsecutive() {

  };
 
  Node<T>* get_root() { return root; };

 private: 
  int size_;
};

int main() {
  int numNodes;
  int m[100];

  cin >> numNodes;
  TheTree<int> bst(numNodes);

  for (int i = 0; i < numNodes; i++) {
      cin >> m[i];
      bst.addNode(m[i]);
  }
  vector<int> v;
  int val = bst.traverse(bst.get_root(), TheTree<int>::BFS, static_cast<TheTree<int>::ORDER>(2));
  cout << "Final: " << val << endl;
  return 1;
}
