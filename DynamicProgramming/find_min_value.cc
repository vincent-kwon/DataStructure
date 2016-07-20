#include <iostream>
#include <vector>

using namespace std;

int cache[10001][10001];
int numbers[10001];
int N, K;
int nums[100];

int findBruteForce(int remain) {

  if (remain == 0) {
    int countAll = 0;
    for (int i = 0; i < 10001; i++) {
      if (numbers[i] == 0) { 
        countAll++;
        //cout << i << ", ";
      };
    }
    //cout << "countFinish: " << countAll << endl;
    return countAll;
  }

  int ret = 987654321;
  int nextNum = nums[N-remain];
  int minStart = nextNum - K + 1;
  //cout << nextNum << " ; count: " << count << "," << "start:" << minStart << "," << "end:" << minEnd << endl;

  vector<int> org;

  for (int i = 0; i < K; i++) {
    int tmpStart = minStart + i;
    int tmpEnd = tmpStart + K - 1;
    //cout << nextNum << " => (" << tmpStart << "," << tmpEnd << ")" << endl;
    for (int j = tmpStart; j <= tmpEnd; j++) {
      //cout << " org(" << j << ") = " << numbers[j] << endl;
      org.push_back(numbers[j]);
      numbers[j] = 0;
    }

    ret = min(ret, findBruteForce(remain - 1));

    for (int j = 0; j < org.size(); j++) {
      numbers[tmpStart + j] = org[j];
    }
    org.clear();
  }
  return ret;
}

int main() {
  int test;

  cin >> test;

  while (test-- > 0) {

    cin >> N;
    cin >> K;

    for (int j = 0 ; j < 10001; j++) {
      numbers[j] = -1;

      for (int k = 0; k < 10001; k++) { 
        cache[j][k] = -1;
      }
    }

    for (int i = 0 ; i < N; i++) {
      int tmp;
      cin >> tmp;
      nums[i] = tmp;  
    }

    int r = findBruteForce(N);
    cout << "answer:" << r << endl;
  }
  return 0;
}
