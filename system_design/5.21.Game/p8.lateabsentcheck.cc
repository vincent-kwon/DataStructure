#include <iostream>

using namespace std;
int cache[100][100][100];
//you can late, absent, attend 
//probability you will not absent more than 1 time or three consecurity late
int validCount = 0;

long long int checkLateAbsent(int start, int end, int absent, string str, int abCount, int threeL) {
  int ret;

  if (start == end) {
    if (abCount >= absent || (threeL > 0)/*str.find("LLL") != string::npos)*/) {
      validCount++;
      cout << str << endl;
    }
    return 1;
  }

  //int& ret = cache[start][abCount][threeL];
  //if (ret != -1) return ret;

  string s2 = str + "L";

  int add = 0;

  if (str.find("LLL") == string::npos && s2.find("LLL") != string::npos) add = 1;

  ret = checkLateAbsent(start+1, end, absent, str + "A", abCount + 1, threeL) + 
  checkLateAbsent(start+1, end, absent, str + "L", abCount, threeL + add) + 
  checkLateAbsent(start+1, end, absent, str + "N", abCount, threeL); 

  return ret;
}

int main() {
  for (int k = 0; k < 100; k++) 
    for (int i = 0 ; i < 100 ; i++)
      for (int j = 0; j < 100 ; j++)
        cache[k][i][j] = -1;

  long long int ret = checkLateAbsent(0, 5,  2, "", 0, 0);
  cout << ret << "," << validCount << endl;
  return 0;
}
