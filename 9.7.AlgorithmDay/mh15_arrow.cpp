#include <iostream>
#include <algorithm>
#include <math.h>       /* sin */

#define PI 3.14159265

using namespace std;

typedef struct {
  int x1;
  int y1;
  int x2;
  int y2;
  double ratio;
  double yaxis;
} line_s;

bool isMeet(double x, double y, line_s p) {

  int smallX, bigX;
  int smallY, bigY;
 
  if (p.x1 < p.x2) {
    smallX = p.x1;
    bigX = p.x2;
  } 
  else {
    smallX = p.x2;
    bigX = p.x1;
  }

  if (p.y1 < p.y2) {
    smallY = p.y1;
    bigY = p.y2;
  }
  else {
    smallY = p.y2;
    bigY = p.y1;
  }
 
  if (!(x >= smallX && x <= bigX) || !(y >= smallY && y <= bigY)) {
    return false;
  }

  return true;
}

int main() {
  int testnum;

  cin >> testnum;

  while (testnum-- > 0) {
    int t;
    cin >> t;
    int tbk = t;

    line_s points[100];
    int index = 0;

    // | x1, y1, x2, y2 | <= 100
    while (t-- > 0) {

      cin >> points[index].x1;
      cin >> points[index].y1;
      cin >> points[index].x2;
      cin >> points[index].y2;

      cout << points[index].x1 << "," << points[index].y2 << endl;

      points[index].ratio = (points[index].y2 - points[index].y1)/(points[index].x2 - points[index].x1);
 
      points[index].yaxis = points[index].y2 - points[index].ratio * points[index].x2;

      cout << "ratio:" << points[index].ratio << "," << "yaxis: " << points[index].yaxis << endl;

      index++;
    }
 
    double ratioCompare = 1;
    double yaxisCompare = 0;

    for (int i = 0; i < tbk; i++) {
 
      double crossX = (points[i].yaxis - yaxisCompare)/(points[i].ratio - ratioCompare);
      double crossY = points[i].ratio * crossX + points[i].yaxis;
      cout << "[" << i << "] : crosses at " << crossX << ", " << crossY << endl; 
      
      if (isMeet(crossX, crossY, points[i]))
        cout << "In" << endl;
      else
        cout << "Out" << endl;       
    }

    int radius = 1;
    for (int i = 0 ; i < 360 ; i++ )  {
      double y = sin(i*PI/180);
      double x = cos(i*PI/180);
      cout << "for degree " << i << "(" << x << "," << y << ") " << endl;
    }
  }

  return 0;
}
