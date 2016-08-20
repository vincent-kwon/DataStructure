#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <queue>

using namespace std;

#define NUM 5

int test;
int m[NUM][NUM] = 
  {
   { 0, 9, 3, 0, 0},
   { 9, 0, 5, 0, 1},
   { 3, 5, 0, 1, 4},
   { 0, 0, 1, 0, 1},
   { 0, 1, 4, 1, 0}
  };

int visited[NUM] = {0, };
int distance2[NUM] = {0, };

bool isEmpty() {
  for (int i = 0 ; i < NUM ; i++) {
    if (visited[i] != 2) return false; // whether queue is empty that means any should 0, 1 is not finished, 2 visited
  }
  return true;
}

void add(int here, vector<int> &v) {
  visited[here] = 2; 
  // recalculate adj values
  for (int i = 0; i < NUM; i++) {
    if (visited[i] != 2 && m[here][i] > 0) {
      int t  = distance2[here] + m[here][i];
      distance2[i] = min(distance2[i], t);
    }
  }
  v.push_back(here);
}

void dikstra(int start, int finish) {
  vector<int> v;

  for (int i = 0 ; i < NUM; i++) {
    distance2[i] = 987654321;
  }

  distance2[0] = 0;
  
  add(0, v);
  
  while (v.size() != NUM) {
    // find next small among adjacent
    int toVisit; 
    int currentMin = 987654321;
    for (int n = 0 ; n < v.size(); n++) {
      int i = v[n];
      for (int j = 0; j < NUM; j++) {
        if (visited[j] != 2 && m[i][j] > 0 && distance2[j] < currentMin) {
          toVisit = j; 
          currentMin = distance2[j];      
          cout << "N:" << toVisit << "," << currentMin << endl;
        }
      }
    }
    int here = toVisit;
    add(here, v);
    if (here == finish) {
      cout << "Found: " << distance2[finish] << endl;
      return;
    }
  }
 
  for (int i = 0 ; i < NUM; i++) {
    cout << i << ":" << distance2[i] << endl;
  }
}

int main() {
  dikstra(0,4);
  return 0;
}
