#include <iostream>

using namespace std;

#define MAX_H 20
#define MAX_W 20

int m[MAX_H][MAX_W];
int test;
int w;
int h;

const int convertType[4][3][2] = {
  { {0,0}, {1,0}, {0,1}  },
  { {0,0}, {0,1}, {1,1}  }, 
  { {0,0}, {1,0}, {1,1}  },
  { {0,0}, {1,0}, {1,-1} }
};

bool set(int y, int x, int type, int delta) {
  bool ok = true;
  for (int i = 0; i < 3; ++i) {
    int ny = y + convertType[type][i][0];
    int nx = x + convertType[type][i][1];
    if (ny < 0 || ny >= h || nx < 0 || nx >= w)
      ok = false;
    else if ((m[ny][nx] += delta) > 1) // if m was already 1 + delta will make 2 and it is something wrong
      ok = false;
  }
  return ok;
}

int cover() {
  int y = -1;
  int x = -1;

  for (int i = 0 ; i < h ; i++) { 
    for (int j = 0 ; j < w; j++) {
      if (m[i][j] == 0) { // 0 means white 
        y = i;
        x = j;
        break;
      }
    }
    if (y != -1) break;
  }
  
  if (y == -1) return 1; // if all is filed

  int ret = 0;

  for (int type = 0; type < 4; type++) {
    if (set(y,x,type,1)) {
      ret += cover();
      //cout << "ret: " << ret << endl;
    }
    set(y,x,type,-1);
  }
  return ret;
}

int main() {
  cin >> test;

  while (test-- > 0) {
    cout << "h, w input " << endl;
    cin >> h;
    cin >> w;
    cout << h << " " << w << endl;
    cout << "0 is white: " << endl;
    for (int i = 0 ; i < h ; i++) 
      for (int j = 0 ; j < w; j++)
        cin >> m[i][j];   
    cout << "call cover: " << endl;    
    int ret = cover();
    cout << ret << endl; 
  }
  return 0;
}
