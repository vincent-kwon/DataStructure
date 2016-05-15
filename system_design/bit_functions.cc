#include <iostream>

using namespace std;

#define INT_MIN (1<<31)
#define INT_MAX (((unsigned int)INT_MIN)-1)

#define ON_BIT(num,i) (num |= 1<<(i))
#define OFF_BIT(num,i) (num &= ~(1<<(i)))

void SET_BIT(int& num, int v, int i) {
  OFF_BIT(num, i);
  num |= (v << i);
}

int GET_BIT(int num, int i) {
  return ((num & (1<<i)) >> i);
}

void REVERSE_BIT(int &num, int i) {
  int tmp = GET_BIT(num, i);
  tmp = tmp ^ 1;
  SET_BIT(num, tmp, i);
}

int main() {
  int z = 0; 
  int x = 4;
  int y = 5; 
  ON_BIT(z,0);
  cout << "before ex-or : " << y << endl;
  REVERSE_BIT(y,0);
  cout << "after ex-or : " << y << endl;
  cout << GET_BIT(z,0) << endl;
  ON_BIT(z,1);
  cout << GET_BIT(z,1) << endl;
  ON_BIT(z,4);
  cout << GET_BIT(z,4) << endl;
  cout << "19 = " << z << endl;

 // cout << (x>>1) << endl;
 // cout << (x>>2) << endl;
  cout << GET_BIT(z,0) << endl;
  cout << GET_BIT(x,2) << endl;
  cout << GET_BIT(y,0) << endl;

  return 0;
}

