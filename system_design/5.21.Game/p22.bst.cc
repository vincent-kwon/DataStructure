#include <iostream>

using namespace std;

#define NUM 6

class Node;

int a[] = {1, 100, 2, 200, 3, 300};

class Node {
 public:
  Node(int i) : value(i), left(NULL), right(NULL), parent(NULL) {
  }
  int value;
  Node* left;
  Node* right;
  Node* parent;
 private:
};

class Tree {
 public:
  Node* root;
  Tree() : root(NULL) {
  }
  void add(int i) {
    Node* n = new Node(i);
    Node* tmp = root;
    while (tmp) {
      if (i <= tmp->value) {
        if (tmp->left) {
          tmp = tmp->left;
          continue;
        }
        else {
          tmp->left = n;
          n->parent = tmp;
          return;
        }
      } 
      else {
        if (tmp->right) {
          tmp = tmp->right;
          continue;
        } 
        else {
          tmp->right = n;
          n->parent = tmp;
          return;
        }
      }
    }
    root = n;
  };
  bool find(int i) {
    bool ret = false;
    Node* tmp = root;
    while (tmp) {
      cout << tmp->value << "," << i << endl;
      if (i == tmp->value) return true;
      if (i <= tmp->value) tmp = tmp->left;
      else tmp = tmp->right;
    }
    return ret;
  }
};

int main() {
  Tree t;
  for (int i = 0; i < NUM; i++) {
    t.add(a[i]);
  }
  if (t.find(300)) {
    cout << "Found 300 " << endl;
  }
  if (t.find(1)) {
    cout << "Found 1 " << endl;
  }
  if (!t.find(7000)) {
    cout << "Not Found 7000 " << endl;
  }
  if (t.find(2)) {
    cout << "Found 2 " << endl;
  }
  return 0;
}
