#include <iostream>
#include <vector>

using namespace std;

int cache[100][10001];
int numbers[10001];
int N, K;
int nums[100];
int accum[100][10001];
int ends[100];

// Need to update numbers to know exactly how many are marked
int findDPMin2(int current, int finish, vector<int> stack) {
  if (current == finish) {
    return accum[current-1][stack[current-1]];
  }
  int currentNum = nums[current];
  int startLeft = currentNum - K + 1;
  int endLeft = currentNum;
  int prevStart = -1;
  int prevEnd = -1;
  int prevAccum = 0;
  if (current > 0) {
    prevEnd = stack[current-1];
    prevStart = prevEnd-K+1;
    prevAccum = accum[current-1][prevEnd];
  }
  int r = 987654321;
  if (startLeft < prevStart) startLeft = prevStart; // do not care below
  for (int i = startLeft; i <= endLeft; i++) {
    int thisStart = i;
    int thisEnd = i + K - 1;
    int newAdd = 0;

    if (thisStart < 0 || thisEnd > 10000) continue;
     
    if (prevEnd < thisStart) {
      newAdd = K;
    }
    else {
      newAdd = thisEnd - prevEnd;
    }

    stack.push_back(thisEnd);
    accum[current][thisEnd] = prevAccum + newAdd; 
    cout << "N=" << current << ",E=" << thisEnd << ",A=" << accum[current][thisEnd] << endl;
    r = min(r, findDPMin2(current+1, finish, stack));
    stack.pop_back();
  }
  return r;
}

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
    }
    
    for (int j = 0; j < 100; j++) {
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
    vector<int> stack;
    int r2 = findDPMin2(0, N, stack);
    cout << "brute answer:" << r << endl;
    cout << "dp answer:" << r2 << endl;
  }
  return 0;
}
