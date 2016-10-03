#include <iostream>

using namespace std;
//vol, need
int a[6][2] = {
{4, 7},
{2, 10},
{6, 6},
{4, 7},
{2, 5},
{10,4}
};

#define MAX_CAP 11
#define MAX_NUM 6 

int cache[MAX_CAP][MAX_NUM];

#define INT_MIN (1<<31)

#define max(a,b) ((a)>(b)?a:b)

// max when 0 to index is called
int pack(int capacity, int index) {

  int& ret = cache[capacity][index]; 
  cout << "pack(" << capacity << "," << index << ") = " << ret << endl;

  if (ret != -1) {
    cout << "HIT: pack(" << capacity << "," << index << ") = " << ret << endl;
    return ret;
  }
  // first element
  if (index == 0) {
    if (capacity >= a[index][0]) ret = a[index][1]; // set 
    else ret = 0;
    
    cout << "End: pack(" << capacity << "," << index << ") = " << ret << endl;
    return ret;
  }

  ret = pack(capacity, index - 1);

  cout << "N pack(" << capacity << "," << index << ") = " << ret << endl;
  // max between selected or not selected
  if (capacity >= a[index][0]) {
    ret = max(ret, pack(capacity - a[index][0], index - 1) + a[index][1]);
    cout << "C pack(" << capacity << "," << index << ") = " << ret << endl;
  }
  return ret;  
}

int main() {
  int test;

  cin >> test;

  while (test-- > 0) {

    for (int i = 0; i < MAX_CAP; i++) 
      for (int j = 0; j < MAX_NUM; j++)
        cache[i][j] = -1;

    int ret = pack(10, 5);

    cout << ret << endl;
  }
  return 0;
}
