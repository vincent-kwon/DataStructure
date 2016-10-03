/*
 * 7.27.2106
 *
 * 어떤 하드 디스크가 있다고 하자. 이게 디프레그멘트 되어있어서
 * 이걸 같은 숫자를 갖는 것들로 다시 정리를 하려고 한다.
 * 방식은 이렇다. 0 은 템포러리이다.
 * 1 부터 9 까지 있고, 하나의 숫자 10 개 이상 씩 묶어 있다
 *
 * 예를 들면 이렇다.
 *
 * 11111111112222222222223333333333333111111111122222222220000000000
 *
 * 할 수 있는 건 swap 이다. 
 *
 * 즉 move(loc0, loc1) loc0 에 있는 걸 loc1 copy 하고 loc0은 0 이된다
 *
 * 그런데 총 0의 갯수는 같아야 한다
 */

#include <iostream>
#include <map>

using namespace std;

#define MAX_BUFFER 10

int buffer[MAX_BUFFER] = {1,2,3,4,5,0,0,0,0,0};

map<int, std::pair<int,int>> info;

void printArray() 
{
  for (int i = 0 ; i < MAX_BUFFER; i++) {
    cout << buffer[i] << " ";
  }
  cout << "" << endl;
}

int moveValues(unsigned int from, unsigned int to, unsigned int size) {
  int bufferSize = sizeof(buffer)/sizeof(buffer[0]);

  if ((!buffer) || (bufferSize < size) || ((from+size-1) >= bufferSize) || ((to+size-1) >= bufferSize)) return -1;

  if (from == to) return 0;

  for (int i = from; i <= (from+size-1); i++) {
    int tmp = buffer[i];
    buffer[i] = 0;
    buffer[to+i] = tmp;
  }

  printArray();
}

int defragment() {

}

int main() {
  
  moveValues(0,5,5);
  return 0;
}
