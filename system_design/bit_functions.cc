#include <iostream>
using namespace std;
#define INT_MIN (1<<31)
#define INT_MAX (((unsigned int)INT_MIN)-1)
#define min(a,b) ((a)<=(b)?(a):(b))
#define max(a,b) ((a)>=(b)?(a):(b))

#define ON_BIT(num,i) (num |= 1<<(i))
#define OFF_BIT(num,i) (num &= ~(1<<(i)))

void SET_BIT(int& num, int v, int i) {
  OFF_BIT(num, i);
  num |= (v << i);
}

int GET_BIT(int num, int i) {
  return ((num & (1<<i)) >> i);
}

int GET_BITS(int num, int start_index, int end_index) {
  int size = end_index - start_index + 1;
  int v = 1 << size;
  int mask = v - 1;
  mask = mask << start_index;
  return ((num & mask) >> start_index);  
}

int SET_BITS(int num, int start_index, int end_index, int value) {
  int size = end_index - start_index + 1;
  int v = 1 << size;
  int mask = v - 1;
  mask = mask << start_index;
  mask = ~mask;
  num = num & mask; //clear first
  value = value << start_index;
  num = num | value;
  return num; 
}

void REVERSE_BIT(int &num, int i) {
  int tmp = GET_BIT(num, i);
  tmp = tmp ^ 1;
  SET_BIT(num, tmp, i);
}

int main() {
  int nVal = 0;
  nVal = SET_BITS(nVal, 0, 4, 31);
  //SET_BIT(nVal, 1, 0);
  //SET_BIT(nVal, 1, 1);
  //SET_BIT(nVal, 1, 2);
  //SET_BIT(nVal, 1, 3);
  //SET_BIT(nVal, 1, 4);
  cout << "31: " << nVal <<endl;
  int rVal = GET_BITS(nVal, 0, 4);
  cout << "Must 31: " << rVal << endl;
  //cout << "should 7: " << rVal << endl;
  //cout << "Set bit 2-3: " << nVal << endl;
  int z = 0; 
  int x = 4;
  int y = 5; 
  ON_BIT(z,0);
  //cout << "before ex-or : " << y << endl;
  REVERSE_BIT(y,0);
  //cout << "after ex-or : " << y << endl;
  cout << GET_BIT(z,0) << endl;
  ON_BIT(z,1);
  cout << GET_BIT(z,1) << endl;
  ON_BIT(z,4);
  cout << GET_BIT(z,4) << endl;
  cout << "19 = " << z << endl;

  //cout << (x>>1) << endl;
  //cout << (x>>2) << endl;
  cout << GET_BIT(z,0) << endl;
  cout << GET_BIT(x,2) << endl;
  cout << GET_BIT(y,0) << endl;

  return 0;
}

