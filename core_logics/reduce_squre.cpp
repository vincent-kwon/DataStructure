#include <iostream>
#include <limits.h>

/*
 * Coodinate is given
 * 
 * Condition
 * 
 * 1. can't proceed one if one remaining
 * 2. order is important top - 1 has 2, bottom + 2 has 1. if bottom is first removed, to remove top - 1 now need not 1 but 
 * 3. if removing + 2 happens, (x1, y1) will be (x1, y1 - 2) and height is now m - 2. 
 * 4. find min move possible
 */

using namespace std;

int main() {
  int testnum;
  int rows, cols;
  int i, j, k, h;
  int x1, y1, x2, y2;

  int node_num;

  cin >> testnum;

  while (testnum-- > 0) {
    cin >> rows;
    cin >> cols;
    cin >> node_num;
 
    int index = 0;

    while (node_num-- > 0) {
    }
  }
  return 0;
}
