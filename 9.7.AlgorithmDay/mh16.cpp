#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
  int testnum;

  cin >> testnum;

  while (testnum-- > 0)  {
    int n;
    string str;
    int strSize;
    int i;
 
    cin >> n;
    cin >> str;

    strSize = str.size();
    int jari = pow (10, n);
    vector<int> v;

    for (int num = 0 ; num < jari ; num++) {
    
      bool isSafe = true;

      for (i = 0 ; i < 6 ; i++) {
        int toDivide = i + 1;
 
        int modResult = num % toDivide;      

        if (str[i] == '1') {
          if (modResult == 0) {
            continue;
          } 
          else { 
            isSafe = false;
            break;
          }
        } 
        else if (str[i] == '0') {
          // % != 0
          if (modResult != 0) {
            continue;
          }
          else {
             isSafe = false;
             break;
          }
        }
        else {
          continue;
        }
      }

      if (isSafe) 
        v.push_back(num);
    }
    cout << "size: " << v.size() << endl;
   
  }
  return 0;
}
