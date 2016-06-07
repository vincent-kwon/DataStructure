#include <iostream>
#include <math.h>
// input 
// 10 3 // length, touse for yangja
// 3 3 3 1 2 3 2 2 2 1 // undr 1000 to minimize sum (diff * diff) 
// 9 3
// 1 744 755 4 897 902 890 6 777
// output
// minvalue
// 0
// 651
// example: 1 2 3 4 5 by 2 2 2 3 3 => 1 0 0 1 4 = 6
//            1 2 3 4 5 by 2 2 2 4 4 => 1 0 1 0 1 = 3

using namespace std;

int arr[100];
int qua[100];
int sel[10];
bool s[10] = {0, };
int len, num;
int c[10];

int targetArr[100];

int getQuant(int len) {
  int ret = 0;
  for (int i = 0; i < len; i++) {
    int tmp = arr[i] - qua[i]; // how to imple abs?????
    tmp *= tmp; // square
    ret += tmp;
  }
  return ret;
}

int combination(int start, int len, int remain, int num) {
  int ret;

  if (remain == 0) {
    for (int i = 0; i < len ; i++) 
      if (s[i] == true) cout << i << " ";
    cout << "" << endl;

    // at least n number must be assigned
    // total 5, num 3,
    // how many possibility?
    distribute(0, len, num, num);
    return 0;
  }

  for (int i = start ; i < len; i++) {
    if (s[i] != true) {
      s[i] = true;
      ret = combination(i+1, len, remain-1, num);
      s[i] = false;
    }
  }
  return 0;
}

int getVariationMin() {
  int index = 0; 

  for (int i = 0 ; i < min; i++) {
    for (int j = 0 ; j < c[i]; j++) {
      targetVal[index] = sel[i];
    }
  } 
  // read c

  // generate all possible combination

  // calculate quants for all possible values

  // return min of it
}


int checkQuant(int index, int min, int cur) {
  if (index == (num-1)) {
    c[index] = len - cur;

    // now ready for count : 1 1 3 => 2 3 4 4 4 
    return getVariationMin();
  }
  for (int i = min; (i+(num-index+1)+cur) < len ; i++) {
    c[index] = i;
    int r = checkQuant(index+1, min, cur + i);
  }
}

int main() {
  int test;
  cin >> test;

  while (test--) {
    int min;
    cin >> len;
    cin >> num;

    for (int i = 0 ; i < len; i++) 
      cin >> arr[i];
  
    // two way valuing
    int min = checkQuant(0, 1, 0); 
    
    // select all 
    cout << min << endl;
  }

  return 0;
}
