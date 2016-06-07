#include <iostream>

#define N_CREATE_COST_PER_LEN 10
#define S_CREATE_COST_PER_LEN 10
#define N_STAMP_COST 2
#define S_STAMP_COST 2
#define STR_LEN 13
#define INT_MIN (1<<31)
#define INT_MAX ((unsigned)INT_MIN - 1)
using namespace std;

char str[STR_LEN+1] = "NNN*SS*NN*SSS";

int getMin(char s[]) {
  int minToolLen = INT_MAX;
  bool noprev = true;  
  char prevChar;
  int same = 0;
  int ss[STR_LEN] = {0, };

  cout << s << endl;
  for (int i = 0; i < STR_LEN - 1; i++) {
    if (noprev) {
      same = 1;   
      noprev = false;
      prevChar = s[i];
    }
    else {
      if (s[i] == prevChar) {
        same++;
      }
      else {
        ss[i-1] = same;
        minToolLen = min(minToolLen, same);
        //cout << "min: " << minToolLen << endl;
        same = 1;
        prevChar = s[i];
      }
    }
  }
  ss[STR_LEN-1] = same;
  minToolLen = min(minToolLen, same);
  int ret = INT_MAX;
  for (int tool = 1; tool <= minToolLen; tool++) {
    int total;
    int stamp_count = 0;
    for (int i = 0; i < STR_LEN; i++) {
      if (ss[i] != 0) {
        stamp_count += ss[i] / tool;
        if (ss[i] % tool) stamp_count++;
      }       
    }
    cout << "stamp #: " << stamp_count << ", tool: " << tool << endl;
    total = stamp_count * N_STAMP_COST + tool * N_CREATE_COST_PER_LEN;
    ret = min(ret, total);
  }
  cout << "min : " << ret << endl;
  return ret;
}

int findMinStamping(int start, char s[]) {
  //cout << "Find: " << s << endl;
  int nextIndex = -1;
  
  for (int i = start; i < STR_LEN; i++) {
    if (s[i] == '*') {
      nextIndex = i;
      break;
    }    
  }
  
  if (nextIndex == -1) {
    // reach to end, lets get max
    //cout << "reach last " << endl;
    return getMin(s);
  } else {
    //cout << "NextIndex: " << nextIndex << endl;
    s[nextIndex] = 'N';
    int first  = findMinStamping(nextIndex+1, s);
    s[nextIndex] = 'S';
    int second = findMinStamping(nextIndex+1, s);
    s[nextIndex] = '*';
    return min(first, second);
  }
}

int main() {
  int r = findMinStamping(0, str);
  cout << r << endl;
  return 0;
}
