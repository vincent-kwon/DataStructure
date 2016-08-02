/*
 * =====================================================================================
 *
 *       Filename:  cornercell.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/02/2016 05:13:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <iostream>
#include <list>
#include <set>

using namespace std;

#define N 5 
#define DFS 

int maze[5][5] = {
  {1, 1, 1, 1, 1,},
  {1, 1, 1, 1, 1,},
  {1, 1, 1, 1, 1,},
  {1, 1, 1, 1, 1,},
  {1, 1, 1, 1, 1,},
};

int cache[5][5][4];

enum FROM_DIR {
  FROM_LEFT,
  FROM_RIGHT,
  FROM_TOP,
  FROM_BOTTOM
};

int row[4][2] = { 
 { 0, 1 }, // from left to right, bottom
 { 0, -1 },   // from right to left, top
 { 1, 0 }, // from top to down, left
 { -1, 0 }, // from bottom to up, right
};

int col[4][2] = { 
 { 1, 0 }, // from left
 { -1, 0},   // from right
 { 0, -1 }, // from top
 { 0, 1 }, // from bottom
};

int fromDir[4][2] = {
  {FROM_LEFT, FROM_TOP},
  {FROM_RIGHT, FROM_BOTTOM},
  {FROM_TOP, FROM_RIGHT },
  {FROM_BOTTOM, FROM_LEFT }, 
};

bool isValid(set<pair<int, int> > visited, pair<int, int> pt) {
  return (pt.first >= 0) && (pt.first < N) &&
         (pt.second >= 0) && (pt.second < N) &&
         (visited.find(pt) == visited.end());
}

int minValue = 987654321;

void printPath(list<pair<int, int> > path, list<int> fromPath, list<int> turnCount) {
  auto fromIt = fromPath.begin();
  auto tc = turnCount.begin();

  for (auto it = path.begin(); it != path.end(); it++, fromIt++, tc++) {
    string dirStr;
    switch (*fromIt) {
      case FROM_LEFT: dirStr = "FROM LEFT";
                 break;
      case FROM_RIGHT: dirStr = "FROM RIGHT";
                 break;
      case FROM_TOP: dirStr = "FROM TOP";
                 break;
      case FROM_BOTTOM: dirStr = "FROM BOTTOM";
                 break;
    }
    cout << "DIR: " << dirStr <<" (" << it->first << " , " << it->second << ") -> " << *tc << endl;
  }
  cout << "MID" << endl;

  if (turnCount.back() < minValue) {
    cout << "New MIN: " << turnCount.back() << endl;
    minValue = turnCount.back();
  }
  
  cout << "MIN: " << minValue << endl;
}

int findPathInMazeUtil(std::pair<int,int> endPoint, list<pair<int, int> > &path,
                        set<pair<int, int> > &visited,
                        pair<int, int> &curr, int from_dir, 
                        list<int>& fromPath, list<int>& turnCount) {


#ifdef DFS
  int minResult = 987654321;
  int myCount = turnCount.back();
 
  if (cache[curr.first][curr.second][from_dir] != -1) {
    cout << "cached:" << curr.first << "," << curr.second << "," << from_dir << ": "  << cache[curr.first][curr.second][from_dir] << endl; 
    return cache[curr.first][curr.second][from_dir] + myCount;
  }

  if (curr.first == endPoint.first && curr.second == endPoint.second) 
  {
    printPath(path, fromPath, turnCount);
    return turnCount.back();
  }

  for (int i = 0; i < 2; ++i) {
    int n = maze[curr.first][curr.second];
    int x = curr.first  + row[from_dir][i] * n;
    int y = curr.second + col[from_dir][i] * n;
    pair<int, int> next = make_pair(x,y);

    if (isValid(visited, next)) {
      visited.insert(next);
      path.push_back(next);
      fromPath.push_back(fromDir[from_dir][i]);
      
      if (i == 0) turnCount.push_back(turnCount.back());
      else turnCount.push_back(turnCount.back()+1);
      
      int tmp = findPathInMazeUtil(endPoint, path, visited, next, fromDir[from_dir][i], fromPath, turnCount);
      minResult = min(minResult, tmp);
      path.pop_back(); 
      fromPath.pop_back();
      turnCount.pop_back();
      visited.erase(next);
    }
    else {
      if (n  == 0) {
      }
    }
  }

  cache[curr.first][curr.second][from_dir] = minResult - myCount; 
  return minResult;
#elif BFS
  // queue 
  // insert start
  // while (!queue.empty()) {
  //   pop front
  //
  // }
#endif
}

void findPathInMaze() {
  list<pair<int, int> > path;
  list<int> fromPath;
  list<int> turnCount; 
  set<pair<int, int> > visited;
  int x = N-1;
  int y = N-1;
  for (int i = 0 ; i < N; i++) 
    for (int j = 0; j < N; j++)
      for (int k = 0; k < 4; k++)
         cache[i][j][k] = -1;

  pair<int, int> pt = make_pair(x,y);
  visited.insert(pt);
  path.push_back(pt); // insert to path
  fromPath.push_back(FROM_LEFT);
  turnCount.push_back(0);
  std::pair<int, int> endPoint = make_pair(N/2, N/2);
  findPathInMazeUtil(endPoint, path, visited, pt, FROM_RIGHT, fromPath, turnCount); 
  path.pop_back();    // remove from path  
  fromPath.pop_back();
  turnCount.pop_back();
  visited.erase(pt); // for next corner
}

int main() {
  findPathInMaze();
}
