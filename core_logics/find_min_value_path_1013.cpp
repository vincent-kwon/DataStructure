/*
 * =====================================================================================
 *
 *       Filename:  shortest_test_at_1050.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/13/2015 10:57:57 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>

using namespace std;

int M[100][100];

int MIN_TOTAL;
int count_try = 0;

typedef struct {
  int row;
  int col;
} loc_s;

typedef enum { SOUTH, WEST, NORTH, EAST, NONE} origin_e ;

void visitNodes(int N, int c_row, int c_col, vector<loc_s> path, int total, origin_e origin) {
  int i;
  count_try++;
  //cout << c_row << "," << c_col << ": " <<  path.size() <<  endl;

  if ((c_row == (N-1)) && (c_col == (N-1))) {
    if (total < MIN_TOTAL) {
      cout << "FOUND ::: " << total << ":" ;
      vector<loc_s>::iterator itor = path.begin();
  
      for (itor; itor != path.end(); itor++) {
        loc_s tmp = *itor;
        cout << tmp.row << "," << tmp.col << "=>";
      }
      MIN_TOTAL = total;
      cout << "" << endl;
    }
    return;
  }

  if (c_row < 0 || c_col < 0) {
    return;
  }

  if (c_row >= N || c_col >= N) {
    return;
  }

  // check cycle 
  vector<loc_s>::iterator itor = path.begin();
  
  for (itor; itor != path.end(); itor++) {
    loc_s tmp = *itor;
    if ((tmp.row == c_row) && (tmp.col == c_col)) {
      return;
    }
  }

  loc_s toPush;

  toPush.row = c_row;
  toPush.col = c_col;

  path.push_back(toPush);

  total += M[c_row][c_col];

  int toSkip = origin;

  //now start visiting for direction 
  for (i = 0; i < 4; i++) {
    switch(i) {
    case 0: //to north 
      if (origin != NORTH)
        visitNodes(N, c_row-1, c_col, path, total, SOUTH);
      break;
    case 1:
      if (origin != EAST)
        visitNodes(N, c_row, c_col+1, path, total, WEST);
      break;
    case 2:
      if (origin != SOUTH)
        visitNodes(N, c_row+1, c_col, path, total, NORTH);
      break;
    case 3:
      if (origin != WEST) 
        visitNodes(N, c_row, c_col-1, path, total, EAST);
      break;
    }
  }
  return;
}

int findShortestPath(int N) {
  // depth first 
  // use stack 
  vector<loc_s> path;
  visitNodes(N, 0, 0, path, 0, NONE);
  return MIN_TOTAL;
}

int main() {
  int test;
  int N;
  cin >> test;

  while (test-- > 0)  {
    int i,j,k;
    int shortResult;
    
    MIN_TOTAL=10000;

    cin >> N;

    cout << N << endl;

    for (i = 0 ; i < N ; i++) {
      for (j = 0 ; j < N; j++) {
        cin >> M[i][j];
      }  
    }

    cout << "start" << endl;

    shortResult = findShortestPath(N);

    cout << "#" << shortResult << "," << count_try << endl;    
  }
}


