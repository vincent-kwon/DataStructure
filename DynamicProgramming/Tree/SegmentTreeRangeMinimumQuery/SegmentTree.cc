/*
 * =====================================================================================
 *
 *       Filename:  SegmentTree.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  08/02/2016 07:31:06 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 *
 *        0  1  2  3  4  5 
 *       -1  3  4  0  2  1
 *
 *       range of minimum better than O(n2) to build and memory space
 *
 *       Can it be better than this with n time to build logN time?
 *
 *       HINT: split the tree to half
 *             My overwrapping is important not targets
 *             1) partial overlap 2) total overlap 3) no overlap
 *             len = 4, segment tree 4 * 2 - 1 = 7
 *             len = 5, then next power of two 8 * 2 - 1 = 15
 *
 *             2i + 1, 2i + 2, (i - 1)/2 parent
 *
 *   
 *             low    high   pos   mid   linenum
 *              0      3      0     1      2
 *              2      3      2     2      1
 *
 *
 *
 *
 *
 *            qlow   qhigh    low    high   pos   mid lineNumber
 *              1      3       0      3      0     1   1    
 *              1      3       0      1      1     0   2
 *
 *
 * =====================================================================================
 */

#include <iostream>

using namespace std;
#define MAX_VAL 987654321
#define NUM 4 
int m[NUM] = { -1, 0, 3, 6 };
int t[NUM*2-1] = {0, };

int findClosestPowerOf2(int num) {
  // when a num is give find next power of 2 of given value;
  int i = 1;

  if (num == 1) return 1;

  int tmp = i * 2; // start from 2

  while (tmp < num) {
    tmp *= 2;
  }

  return tmp;
}

void constructTree(int input[], int segTree[], int low, int high, int pos) {
  if (low == high) {
    segTree[pos] = input[low]; 
    return;
  }

  int mid = (low + high) / 2;
  constructTree(input, segTree, low, mid, 2 * pos + 1);
  constructTree(input, segTree, mid+1, high, 2 * pos + 2);
  segTree[pos] = min(segTree[2*pos+1], segTree[2*pos+2]);
}

int rangeMinQuery(int segTree[], int qlow, int qhigh, int low, int high, int pos) {
  if (qlow <= low && qhigh >= high) // totally overlap by query
    return segTree[pos];

  if (qlow > high || qhigh < low) 
    return MAX_VAL;

  int mid = (low + high)/2;
  
  return min(rangeMinQuery(segTree, qlow, qhigh, low, mid, 2*pos+1),
             rangeMinQuery(segTree, qlow, qhigh, mid+1, high, 2*pos+2));
}

int main() {
  int x = findClosestPowerOf2(5);
  cout << x << endl;

  constructTree(m, t, 0, 3, 0); // last 0 means root

  for (int i= 0 ; i < NUM*2-1; i++)
    cout << t[i] << " ";

  cout << "" << endl;

  int min = rangeMinQuery(t, 0, 2, 0, 3, 0);

  cout << "r: " << min << endl;
  return 0;
}




