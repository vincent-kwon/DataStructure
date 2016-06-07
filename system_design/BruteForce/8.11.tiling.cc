#include <iostream>

using namespace std;

int sum = 0;

int tiling(int width) {
  if (width < 0) return 0;
  else if (width == 0) return 1;
  else {
    int tmp = tiling(width-1);
    int tmp2 = tiling(width-2);
    return (tmp + tmp2);
  }
}

int main() {
  int num;
  cin >> num;
  int r = tiling(num);
  cout << r << endl;
  return 0;
}
