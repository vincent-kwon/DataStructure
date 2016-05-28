#include <iostream>
// 9:00 ~ 10:00
using namespace std;

//#define QUEUE_MAX 5
#define INT_MIN (1<<31)
#define INT_MAX ((unsigned)INT_MIN-1)

//if same +1, diff -3, adding D: first -3, from second -1
char str1[] = "aabbcc";
char str2[] = "bbcaab";

#define NODE_NUM 7
#define EDGE_NUM 9
int d[NODE_NUM];
bool v[NODE_NUM];

int g[NODE_NUM][NODE_NUM] = {
  {0, 5, 1, 0, 0, 0, 0},
  {5, 0, 0, 1, 0, 3, 3},
  {1, 0, 0, 2, 0, 0, 0},
  {0, 1, 2, 0, 5, 3, 0},
  {0, 0, 0, 5, 0, 0, 0},
  {0, 3, 0, 3, 0, 0, 2},
  {0, 3, 0, 0, 0, 2, 0} 
};

class Queue {
 public:
  const static int QUEUE_MAX = 5;
  Queue() {
    begin_ = -1;
    end_ = -1;
    size = 0;
  };

  int push(int i) {
    if (isFull()) return -1;
    if (begin_ == -1) begin_ = end_ = 0;
    else {
      end_++;
      if (end_ == QUEUE_MAX) end_ = 0;
    }
    a_[end_] = i; 
    size++;
    return 0;
  };

  int pop() {
    if (isEmpty()) return -1;
    int ret = a_[begin_++];
    if (begin_ == QUEUE_MAX) begin_ = 0;
    size--;
    return ret;
  };

  bool isFull() { 
    return size == QUEUE_MAX? true : false;
  };

  bool isEmpty() {
    return size == 0? true : false;
  };

 private:
  int a_[QUEUE_MAX];
  int begin_;
  int end_;
  int size;
};

Queue queue;

int dikstra() {
  
  for (int i = 0; i < NODE_NUM; i++) {
    d[i] = INT_MAX;
    v[i] = false;
  }
  
  d[0] = 0;
  queue.push(0);

  while (queue.isEmpty() == false) {
    int here = queue.pop();

    v[here] = true;

    int close_value = INT_MAX;
    int close_index = -1;

    for (int i = 0; i < NODE_NUM; i++) {
      if (g[here][i] > 0 && v[i] == false) {
        //cout << "here: " << here << ", i = " << i << ", d[here] = " << d[here] << "," << g[here][i] << ", d[i]=" << d[i] << endl;
        d[i] = min(d[i], d[here]+g[here][i]);
        //cout << "updaet d[" << i << "] = " << d[i] << endl;
        if (close_value >= d[i]) { 
          close_index = i;
          close_value = d[i]; 
        }
      }
    }

    if (close_index != -1) queue.push(close_index);
  }

  for (int i = 0; i < NODE_NUM; i++) {
    cout << "dist[" << i << "] = " << d[i] << endl;
  }
  return 0;
}

int main() {
  queue.push(1);
  queue.push(2);
  queue.push(3);
  queue.push(4);
  queue.push(5);

  if (queue.push(6) == -1) cout << "Push failed at 6 " << endl;
  if (queue.isFull()) cout << "Queue is full " << endl;
  int v = queue.pop(); //1
  cout << " 1 should pop " << v << endl;
  cout << queue.pop() << endl; 
  cout << queue.pop() << endl;
  cout << queue.pop() << endl;
  int v2 = queue.pop(); 
  cout << " 5 should pop " << v2 << endl;
  cout << " is empty? " << queue.isEmpty() << endl;
  cout << " Now Dikstra..... " << endl;
  int ret = dikstra(); 
  cout << ret << endl;
  return 0;
}
