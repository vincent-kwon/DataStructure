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
