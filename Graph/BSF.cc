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
   { 0, 1, 1, 0, 0},
   { 1, 0, 1, 0, 1},
   { 1, 1, 0, 1, 0},
   { 0, 0, 1, 0, 0},
   { 0, 1, 0, 0, 0}
  };
int visited[NUM] = {0, };
int distance2[NUM] = {0, };

bool isEmpty() {
  for (int i = 0 ; i < NUM ; i++) {
    if (visited[i] != 2) return false; // whether queue is empty that means any should 0, 1 is not finished, 2 visited
  }
  return true;
}

void bfs(int start) {
  queue<int> q;
  distance2[0] = 0;
  q.push(0);
  
  while (!q.empty()) {
    //cout << q.size() << endl;
    int here = q.front();
    cout << "visited " << here << endl;
    q.pop();
    visited[here] = 2; 

    for (int i = 0; i < NUM ; i++) {
      if (m[here][i] == 1 && visited[i] == 0) { // not inter-visited, visited
        cout << " queue push : " << i << endl;
        q.push(i);
        visited[i] = 1;
        distance2[i] = distance2[here] + 1;
      }
    }
  }
 
  for (int i = 0 ; i < NUM; i++) {
    cout << i << ":" << distance2[i] << endl;
  }
}

int main() {
  bfs(0);
  return 0;
}
