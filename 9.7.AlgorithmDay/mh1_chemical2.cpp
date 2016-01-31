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

int m[3][100][100] = {0, };

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
      bool hasAnchor = false;   
      int len = 0;
 
      for (j = 0; j < n; j++) {
        cin >> m[0][i][j];

        int prevRow = i - 1;
        int prevCol = j - 1;
      
        if ((m[0][i][j] != 0) && (prevRow < 0 || m[0][prevRow][j] == 0) && (prevCol < 0 || m[0][i][prevCol] == 0)) {
          count++;
          Point p(count, i, j);
          v.push_back(p);
          m[2][i][j] = v.size() - 1;
          hasAnchor = true;
          len = 1;
        } 
        else if ((m[0][i][j] != 0) && (hasAnchor == true)) {
          continue; 
        }
        else if ((hasAnchor == true) && (m[0][i][j] == 0)) {
          v[v.size()-1].endCol = j - 1;
          len = 0;
          hasAnchor = false;
        }
        else if (( m[0][i][j] != 0) && (i > 0) && ( (j==0) || (m[0][i][j-1] == 0) ) ) {
          m[1][i][j] = m[1][i-1][j] + 1;
          int k = i - m[1][i][j];
          v[m[2][k][j]].endRow = i;
        }
      }

      if (hasAnchor) {
        v[v.size()-1].endCol = n - 1;
      }
    }

    sort(v.begin(), v.end(), ([](Point p1, Point p2) {
                                 if (p1.getRows() < p2.getRows())
                                   return true;
                                 else 
                                   return false;
                               })
    );
    cout << v.size() << " " ;
    for_each(v.begin(), v.end(), printElement);
    cout << "" << endl;
  } // end of while
} // end of main
