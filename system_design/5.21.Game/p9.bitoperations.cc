#include <iostream>

// PM 7:00 ~ 8:00
using namespace std;
//get,set, gets, sets, on, off

#define ON_BIT(num, i) num |= (1<<(i))
#define OFF_BIT(num, i) num = (num & ~(1<<(i)))

int GET_BITS(int num, int start, int end) {
  int size = end - start + 1;
  int mask = ((1 << size) - 1);
  int tmp = mask << start;
  return (num & tmp) >> start;
}

void SET_BITS(int& num, int start, int end, int value) {
  int size = end - start + 1;
  int mask = ((1 << size) - 1);
  int tmp = mask << start;
  num = num & ~tmp; // erase
  num = num | value << start;
}

//read N bits / write N bits encoding/decoding

int main() {
  int i = 0;
  SET_BITS(i,1,3,7);
  int value = GET_BITS(i,1,3);
  cout << value << endl;
  return 0;
}
