/*
 * =====================================================================================
 *
 *       Filename:  histogram.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/01/2016 08:28:08 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * 
 * [10/3/2016 note]
 *
 * Histogram Articulate
 *
 * 0. If next one is bigger than current one, add. If same, don't need to put. If less pop until all bigger ones disappear
 *    When popping up, if small found, this this one, if same found, may not need to add (think more)
 * 1. Think carefully how to set table
 * 2. Best way is to respresent 0 means 0 to 1's height
 * 3. If it is point, then difficult to handle end point
 * 4. If height is same as pushed data, don't need to push again
 *
 *
 *
 * =====================================================================================
 */

#include <iostream>
#include <stack>

using namespace std;

#define ROW 4 
#define COL 6

int m[ROW][COL] = {
  { 1, 0, 0, 1, 1, 1 },
  { 1, 0, 1, 1, 0, 1 },
  { 0, 1, 1, 1, 1, 1 },
  { 0, 0, 1, 1, 1, 1 },
};

int rowSum[COL] = {0, }; 

int getAreaSize(stack<int>& st, int* rowSum, int i) {
  int nextVal = st.top();
  int width;
  int height = rowSum[nextVal];

  if (height == 0) return 0; 

  st.pop(); // pop current temporarily
  
  if (st.empty()) width = i - nextVal;
  else {
    int prevTop = st.top();
    if (rowSum[prevTop] == 0) width = i - prevTop - 1 ;
    else width = i - nextVal;
  }
  
  st.push(nextVal);
  int tmp = width * height;
  //cout << "getArea: i = " << i << ", st.top() = " << nextVal << ",(w:" << width << ",h:" << height <<  ") = " << tmp << endl;
  return tmp;
}

int getHistogramMax(int *rowSum) {
  stack<int> st;
  int maxValue = -987654321;

  st.push(0);

  for (int i = 1; i < COL; i++) {
    if (rowSum[st.top()] <= rowSum[i]) st.push(i);
    else {
      while (!st.empty() && rowSum[i] < rowSum[st.top()]) {
        int tmp = getAreaSize(st, rowSum, i);
        st.pop();
        maxValue = max(maxValue, tmp);
      }
      st.push(i);
    }
  }

  while (!st.empty()) {
    int tmp = getAreaSize(st, rowSum, COL);
    st.pop();
    maxValue = max(maxValue, tmp);
  }
  //cout << "Row Max : " << maxValue << endl;
  return maxValue;
}

int main() {
  int maxSum = -987654321;
  for (int i = 0; i < ROW; i++) {
    for (int j = 0; j < COL; j++) {
      if (m[i][j] != 0) rowSum[j] += m[i][j];
      else rowSum[j] = 0;
      //cout << rowSum[j] << " ";
    }
    //cout << "" << endl;
    int tmp = getHistogramMax(rowSum);
    maxSum = max(maxSum, tmp);
  }
  cout << "r: " << maxSum << endl;
  return 0;
}

