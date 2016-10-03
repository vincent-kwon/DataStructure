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

#define N 9


int maze[N][N] = {
 { 3, 5, 4, 4, 7, 3, 4, 6, 3 },
 { 6, 7, 5, 6, 6, 2, 6, 6, 2 },
 { 3, 3, 4, 3, 2, 5, 4, 7, 2 },
 { 6, 5, 5, 1, 2, 3, 6, 5, 6 },
 { 3, 3, 4, 3, 0, 1, 4, 3, 4 },
 { 3, 5, 4, 3, 2, 2, 3, 3, 5 },
 { 3, 5, 4, 3, 2, 6, 4, 4, 3 },
 { 3, 5, 1, 3, 7, 5, 3, 6, 4 },
 { 6, 2, 4, 3, 4, 5, 4, 5, 1 },
};

int row[] =  { -1, 1,  0, 0 };
int col[] =  {  0, 0, -1, 1 };
int _row[] = {  0,   0, N-1, N-1 };
int _col[] = {  0, N-1,   0, N-1 };

bool isValid(set<pair<int, int> > visited, pair<int, int> pt) {
  return (pt.first >= 0) && (pt.first < N) &&
         (pt.second >= 0) && (pt.second < N) &&
         (visited.find(pt) == visited.end());
            
}

void printPath(list<pair<int, int> > path) {
  for (auto it = path.begin(); it != path.end(); it++) {
    cout << "(" << it->first << " , " << it->second << ") -> ";
  }

  cout << "MID" << endl;
}

void findPathInMazeUtil(list<pair<int, int> > &path,
                        set<pair<int, int> > &visited,
                        pair<int, int> &curr) {
  if (curr.first == N/2 && curr.second == N/2) 
  {
    printPath(path);
    return;
  }

  for (int i = 0; i < 4; ++i) {
    int n = maze[curr.first][curr.second];
    int x = curr.first + row[i] * n;
    int y = curr.second + col[i] * n;
    pair<int, int> next = make_pair(x,y);

    if (isValid(visited, next)) {
      visited.insert(next);
      path.push_back(next);
      findPathInMazeUtil(path, visited, next);
      path.pop_back(); 
      visited.erase(next);
    }
    else {
      if (n  == 0) {
        cout << "Not Valid Path: starting... " << endl;
        printPath(path);
        cout << "End path...." << endl;
      }
    }
  }
}

void findPathInMaze() {
  list<pair<int, int> > path;
  set<pair<int, int> > visited;

  for (int i = 0; i < 4; ++i) {
    int x = _row[i];
    int y = _col[i];

    pair<int, int> pt = make_pair(x,y);

    visited.insert(pt);
    path.push_back(pt); // insert to path
    findPathInMazeUtil(path, visited, pt); 
    path.pop_back();    // remove from path  
    visited.erase(pt); // for next corner
  }  
}

int main() {
  findPathInMaze();
}
