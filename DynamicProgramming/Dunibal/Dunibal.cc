/*
 * =====================================================================================
 *
 *       Filename:  Dunibal.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/06/2016 08:23:52 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int m[5][5] = {
  {0,1,1,1,0},
  {1,0,0,0,1},
  {1,0,0,0,0},
  {1,0,0,0,0},
  {0,1,0,0,0},
};

double d[5][5];

int rCount[5]; 

int N = 5;
int D = 2;
int S = 0;

int main() {
  queue<std::pair<int, double> > q[2];
  vector<int> v[N];

  int num = 0;
  int d = 0; 

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (m[i][j] == 1) {
        v[i].push_back(j);
      }
    }
  }

  q[num].push(make_pair(0,1));

  while (d < D) {
    int size = q[num].size();
    for (int i = 0; i < size; i++) {
      // pop element to nextNum
      std::pair<int, double> tmp = q[num].front();
      q[num].pop();
      // find out all route from nextNum to A
      for (int j = 0; j < v[tmp.first].size(); j++) {
        double dVal = (double) 1 / v[tmp.first].size();

        cout << "s:" << tmp.second << ", f:" << dVal << endl;
        std::pair<int, double> newNode = make_pair(v[tmp.first].at(j), tmp.second * dVal); //v[tmp.first][j];
        q[(num+1)%2].push(make_pair(v[tmp.first].at(j), tmp.second * dVal));
      }
      // for reachable node, 1 / A * prob(A) to new node
    }
    num = (num+1)%2;
    d++;
  } 

  int size = q[num].size();

  for (int i = 0; i < size; i++) {
    std::pair<int, double> tmp = q[num].front();
    q[num].pop();
    cout << tmp.first << ":" << tmp.second << endl;
  }
  // day 1 0 
  // day 2 1(1/3) 2(1/3)  3(1/3)
  // day 3 0(1/2) 0(1) 0(1) 4(1/2)
  //
  return 0;
}
