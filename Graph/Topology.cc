#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

using namespace std;

int test, num;
char str[200][20];
char alphabet[27] = "abcdefghijklmnopqrstuvwxyz";
int isSeen[26] = {0, };
int m[26][26] = {0, };

void makeEdge(char start, char end) {
  int startIndex = (int)start - 97;
  int endIndex = (int)end - 97;
  m[startIndex][endIndex] = 1;
  isSeen[startIndex] = 1;
  isSeen[endIndex] = 1; 
  //cout << "edge: " << (char)(startIndex+97) << "," << (char)(endIndex+97) << endl;
}

void dfs(int node, vector<char>& cv) {
  if (isSeen[node] == 2) return;
  isSeen[node] = 2; // now seen
  for (int i = 0; i < 26; i++) {
    if (m[node][i] == 1 && isSeen[i] == 1) {
      dfs(i, cv);
    }
  }
  cv.push_back(node);
  //cout << "push " << (char)(node+97) << endl;
}

vector<char> getTSR() {
  vector<char> cv;
  for (int i = 0; i < 26; i++) {
    if (isSeen[i] == 1) {
      dfs(i, cv);
    }
  }
  return cv;
}

int main() {
  cin >> test;
  while (test-- > 0) {
    cin >> num;
    for (int i = 0 ; i < num ; i++) {
      cin >> str[i];
      if (i > 0) {
        int before = i-1;
        int after = i;
        int len = min(strlen(str[before]), strlen(str[after]));
        for (int l = 0 ; l < len; l++) {
          if (str[before][l] != str[after][l]) {
            makeEdge(str[before][l], str[after][l]);
            break;
          }
          else continue;
        }
      }      
    }
    
    vector<char> rOrder = getTSR();
    
    for (int k = 0 ; k < rOrder.size()-1; k++) {
      for (int y = k+1; y < rOrder.size(); y++) {
        if (m[rOrder[k]][rOrder[y]] != 0) {
          cout << "Invalid !!!! " << endl;
          return 1;
        }
      }
    }
      
    // pick and set isAppeared true
    for (int k = rOrder.size()-1; k >= 0 ; k--) {
      cout << (char)(rOrder[k]+97);
    }
      
    // print rest of not appearered
    for (int k = 0; k < 26; k++) {
      if (isSeen[k] == 0) cout << alphabet[k];
    }
  }  
  return 0;
}
