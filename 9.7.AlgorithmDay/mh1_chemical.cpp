#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Point {
public:
  Point(int i, int x, int y) : id(i), startRow(x), startCol(y) {
  }
  virtual ~Point() {
  };

  int id;
  int startRow;
  int startCol;
  int endRow;
  int endCol;
  int getCols() {
    return (endCol - startCol + 1);
  };
  int getRows() {
    return (endRow - startRow + 1);
  };
};

int m[100][100] = {0, };

bool comp(Point p1, Point p2) {
  if (p1.getRows() < p2.getRows())
    return true;
  else 
    return false;
}

void printElement(Point &p) {
  cout << p.getRows() << " " << p.getCols() << " ";
}

int main() {
  int testnum;
  cin >> testnum;

  while (testnum-- > 0) {
    int n;
    int i, j;
    vector<Point> v;
    int count = 0; 
    cin >> n;
    
    for (i = 0; i < n; i++) {
      for (j = 0; j < n; j++) {
        cin >> m[i][j];

        int prevRow = i - 1;
        int prevCol = j - 1;

        if ((m[i][j] != 0) && (prevRow < 0 || m[prevRow][j] == 0) && (prevCol < 0 || m[i][prevCol] == 0)) {
          count++;
          Point p(count, i, j);
          v.push_back(p);
        }
      }
    }

    for (i = 0; i < v.size() ; i++) {
      int tempRow, tempCol;
      int row = tempRow = v[i].startRow;
      int col = tempCol = v[i].startCol;

      while ((tempCol < n) && (m[row][tempCol] != 0)) {
        tempCol++;
      }
      v[i].endCol = tempCol - 1;

      while ((tempRow < n) && (m[tempRow][col] != 0)) {
        tempRow++;
      }
      v[i].endRow = tempRow - 1;
    }
   
    sort(v.begin(), v.end(), comp);
    cout << v.size() << " " ;
    for_each(v.begin(), v.end(), printElement);
    cout << "" << endl;
  } // end of while
} // end of main
#if 0
      //if any starting point is found, construct Point
      //starting points meets following conditions:
      //if i or j = 0, consider new
      //if i's top = 0 or i is 0, j's left = 0 or j = 0
      //when new member found, count++ and it becomes ID;
      //width can be added when non-zero col comes 
      //height can be added when non-zero row comes + for 

      {

      int startValue = 0;
      int startIndex = -1;
      int countLen = 0;
 
      for (j = 0; j < n; j++) {
 
        if (m[0][i][j] != 0)  {
          // 1. check if it is anchor
          // 2. else if first col
          // 3. 
          //

          if (startValue == 0) {
            countLen = 1;
            startIndex = j;
            startValue = 1; // any non-zero
          } 
          else {
            countLen++;
          }
        } 
        else { // if current value is zero
          if (startValue != 0) {
            int endIndex = j - 1;
            //now save width of this rectangle
          }
        }
      } //end of j
    } // end of i
#endif
