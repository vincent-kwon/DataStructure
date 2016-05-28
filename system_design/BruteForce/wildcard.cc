#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define INT_MIN (1<<31)
#define INT_MAX ((unsigned int)INT_MIN - 1)

bool checkFeasible(string s1, string s2) {
  //cout << "Enter: " <<  s1 << ", " << s2 << endl;

  int s1_index = 0; 
  int s2_index = 0;

  bool s1End = false;
  bool s2End = false;

  while (true) {
    if (s1_index == s1.size()) {
      if (s2_index == s2.size()) {
        return true;
      }
      else {
        return false;
      }
    } 

    if (s2_index == s2.size()) {
      for (s1_index; s1_index < s1.size(); s1_index++) {
        if (s1[s1_index] != '*') return false;
      }
      //in this case s1_index to end all must be only '*'
      return true;
    }

    //     |
    // h e *
    // h e l 
    if (s1[s1_index] == '*') {
      // all cases should be covered here
      for (int j = 0; j + s2_index <= s2.size(); j++) {
        bool b = checkFeasible(s1.substr(s1_index+1), s2.substr(j+s2_index));
        //cout << "b return " << b << ", j = " << j << " s2 I : " << s2_index << "," << s2.size() << endl;
        if (b) return true;
      }
      return false;
    }

    else if (s1[s1_index] == '?') {
      s1_index++;
      s2_index++;
    }

    else {
      if (s1[s1_index] != s2[s2_index]) {
        return false;
      }
      s1_index++;
      s2_index++;
    }
  }
  return false;
}

int main() {
  int test;
  
  cin >> test;

  while (test-- > 0) {
    int num;
    char str[256]; 
    cin >> str;
//  why this cause of loop ????  cout << str << endl;
    cin >> num;
    char subs[10][256];
    for (int i = 0; i < num ; i++) {
      cin >> subs[i];
      string s1(str);
      string s2(subs[i]);
      bool b = checkFeasible(s1, s2);
      if (b) cout << "Success: " << s1 << endl;
      else cout << "FAIL: " << s1 << endl;
    }
  }
  return 1;
}
