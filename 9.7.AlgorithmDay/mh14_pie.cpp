#include <iostream>
#include <algorithm>
#include <math.h>       /* sin */

using namespace std;

int subsets(int top) {
  int count = 0;

  //for (int i = 1; i 
  
  return count;
}

int dividePie(int num, int men, int *arr, int len) {
  int count = 0;

  if (men == 0) {
    if (num == 0) {
      for (int i = 1; i <= len ; i++) { 
         cout << arr[i] << " " ;
      }
      cout << "" << endl;
      return 1;
    } 
    else {
      return 0;
    }
  }
  else {
    if (num == 0) { 
      return 0;
    } 
    else {
    }
  }
  // num > 0, men > 0
  for (int i = 1; i <= num; i++) {
    arr[men] = i;

    int result = dividePie(num - i, men - 1, arr, len); // avoid duplication
   
    if (result > 0) {
      count += result;
    }
  }
  return count;
}

int main() {
  int testnum;

  cin >> testnum;

  while (testnum-- > 0) {
    int num;
    int men;
    int arr[72] = {0, };

    cin >> num;
    cin >> men;

    int count = dividePie(num,men, arr, men);

    cout << count << endl;
  }
  int i = subsets(4);
  cout << i << endl;
  return 0;
}
