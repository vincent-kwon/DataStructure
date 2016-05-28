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
}

