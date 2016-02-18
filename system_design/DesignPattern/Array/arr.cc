#include <iostream>
using namespace std;

int main() {
  int * i = new int;
 
  *i = 100;

  cout << *i << endl;

  int *iarr = new int [3];

  iarr[0] = 2;
  iarr[1] = 3;
 
  cout << iarr[0] << "," << iarr[1] << endl;
}
