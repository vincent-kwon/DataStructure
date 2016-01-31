/*
 * =====================================================================================
 *
 *       Filename:  MH_24_train_travel.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  10/13/2015 03:41:34 PM
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

int P[100001];
int A[100001];
int B[100001];
int C[100001];
int T[100001] = {0, };
int V[100001] = {0, };

int N,M;

int minCost = ~(1 << 31);

int getCost(int cur) {
  //check 
  if (V[cur] == 1) {
    return B[cur];
  } 
  else {
    if ((A[cur] * T[cur]) < (B[cur] * T[cur] + C[cur])) {
      //don't need to by
      return A[cur];
    } 
    else {
      //Need to buy
      V[cur] = 1;
      int toReturn = (B[cur] * T[cur] + C[cur]) - (A[cur] * (T[cur]? (T[cur] - 1) : 0));
      return toReturn;
    }
  }
}

int findMinCost() {
  int i;
  int cur = P[1];
  int totalCost = 0;

  for (i=1; i < N; i++) {
    T[i] = 0; //reset count
    V[i] = 0;
  }

  for (i=2; i <= M; i++) {
    int nextLoc = P[i];

    while (cur != nextLoc) {
      int nextCost;

      if (cur < nextLoc) {
        T[cur]++; 
        nextCost = getCost(cur);
        cur++;
      } 
      else {
        T[cur-1]++;
        nextCost = getCost(cur-1);
        cur--;
      }
      totalCost = totalCost + nextCost;
      //cout << cur << " ";
    } 
    //cout << "" << endl;
  }
  
  return totalCost;
}

int main() {
  int test;

  cin >> test;

  while (test-- > 0) {
    int i,j,k;

    cin >> N;
    cin >> M;

    for (i = 1; i <= M; i++) {
      cin >> P[i];
    }

    for (i = 1; i < N ; i++) {
      cin >> A[i];
      cin >> B[i];
      cin >> C[i];
    }

    int minValue = findMinCost();
    cout << "total min:" << minValue << endl;
  }
}
