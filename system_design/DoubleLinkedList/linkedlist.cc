/*
 * =====================================================================================
 *
 *       Filename:  linkedlist.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/25/2016 09:36:56 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;

struct Node {
  double value;
  Node *P, *N;

  Node (double y) {
    value = y;
    N = P = NULL;
  }
};

class DoubleLinkedList {
 public:
  DoubleLinkedList() {
    front = back = NULL;
  } 
  ~DoubleLinkedList() {
    destroyList();
  }
  void appendNodeFront(double x);
  void appendNodeBack(double x);
  void disNodeForward();
  void disNodeReverse();
  void free() {
    destroyList();
  }
 private:
  Node *front;
  Node *back;
  void destroyList();
};

void DoubleLinkedList::appendNodeFront(double x) {

  Node *newNode = new Node(x);

  cout << " created : " << newNode;
  
  if (front == NULL) {
    front = back = newNode;
  } else { // at least one
    newNode->N = front;
    front->P = newNode;
    front = newNode;
  }
}

void DoubleLinkedList::appendNodeBack(double x) {
  Node *newNode = new Node(x);

  cout << " created : " << newNode;

  if (front == NULL) {
    front = back = newNode;
  } else { // at least one
    newNode->P = back;
    back->N = newNode;
    back = newNode;
  }
}

void DoubleLinkedList::disNodeForward() {
  Node* tmp = front;

  while (tmp) {
    cout << tmp->value << endl;
    tmp = tmp->N;
  }
}

void DoubleLinkedList::disNodeReverse() {
  Node* tmp = back;

  while (tmp) {
    cout << tmp->value << endl;
    tmp = tmp->P;
  }
}

void DoubleLinkedList::destroyList() {
  Node* tmp = back;

  while (tmp) {
    Node* toDel = tmp;
    tmp = tmp->P;
    toDel->N = NULL;
    toDel->P = NULL;
    cout << " to Del is " << toDel << endl;
    delete toDel;
  }
  
  front = back = NULL;
}

int main() {
  DoubleLinkedList dll;
  dll.appendNodeFront(1.0);
  dll.appendNodeFront(2.0);
  dll.appendNodeBack(3.0);
  cout << "go forward" << endl;
  dll.disNodeForward();
  cout << " go back: " << endl;
  dll.disNodeReverse();
  cout << " destroy: " << endl;
  dll.free();
  cout << " go forward " <<endl;
  dll.disNodeForward();
  cout << " -- end -- " << endl;
  return 1;
}
