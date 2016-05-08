#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <memory>
#define MAX_M 100
#define INT_MIN (1<<31)
#define INT_MAX ((unsigned int)INT_MIN - 1)
#define MAX_STATE (1<<20)
#define MAX_HASH (MAX_STATE)

using namespace std;

int M;
int test;
vector<vector<int> >g;
int g_hash[MAX_STATE] = {0, }; 
int g_value[MAX_STATE] = {0, };;
 
enum DIRECTION {
  FROM_LEFT,
  FROM_RIGHT,
  FROM_TOP,
  FROM_BOTTOM,
  FROM_ZERO
};

class State {
 public: 
  State(vector<vector<int> > v, int distance, DIRECTION dri);
  vector<shared_ptr<State> > getAdjacent();
  bool operator==(const State& rhs) const;
  void print() const;
  int get_distance() { return distance_; }
  long long int get_hash() { return hashValue_; } 
 private:
  vector<vector<int> > v_;
  vector<shared_ptr<State> > s_;
  int distance_; 
  long long int hashValue_;
  DIRECTION dri_;
};

State::State(vector<vector<int> > v, int distance, DIRECTION dri) : v_(v), distance_(distance), dri_(dri) {
  int index = 0; 
  hashValue_ = 1;
  for (int i = 0; i < v_.size(); i++) {
    for (int j = 0; j < v_.size(); j++) {
      int mul = pow(10, index++);
      hashValue_ += mul * v_[i][j];
      cout << v_[i][j] << " " ;
  //cout << (1<<(v_[i][j]+1)) << endl;
  //hashValue_ += ((1<<(v_[i][j]+1))*v_[i][j]);
  //cout << v_[i][j] << ", " << hashValue_ << endl;
    }
  }
  hashValue_ %= MAX_HASH;
  cout << hashValue_ << endl;
  g_hash[hashValue_] = 1;
}

void State::print() const
{
  cout << "== State ==" << endl;
  for (int i = 0 ; i < M ; i++) {
    for (int j = 0 ; j < M; j++) {
       cout << v_[i][j] << " ";
    }
    cout << "" << endl;
  }
  cout << "== " << distance_ << " " << endl;
}

vector<shared_ptr<State> > State::getAdjacent() {
  if (s_.size() > 0) return s_;
  int z_row;
  int z_col;
  for (int i = 0 ; i < v_.size(); i++) {
    bool isFound = false;
    for (int j = 0 ; j < v_[i].size(); j++) {
      if (v_[i][j] == 0) {
        z_row = i;
        z_col = j;

        // left
        int tmp;
        if (dri_ != FROM_LEFT && z_col != 0) {
          vector<vector<int> > v_copy = v_;
          tmp = v_copy[z_row][z_col];
          v_copy[z_row][z_col] = v_copy[z_row][z_col-1];
          v_copy[z_row][z_col-1] = tmp;
          shared_ptr<State> new_state(new State(v_copy, distance_+1, FROM_RIGHT));
          s_.push_back(new_state);   
        }   
        // right
        if (dri_ != FROM_RIGHT && z_col != (v_.size()-1)) {
          vector<vector<int> > v_copy = v_;
          tmp = v_copy[z_row][z_col];
          v_copy[z_row][z_col] = v_copy[z_row][z_col+1];
          v_copy[z_row][z_col+1] = tmp;
          shared_ptr<State> new_state(new State(v_copy, distance_+1, FROM_LEFT));
          s_.push_back(new_state);   
        }
        // up
        if (dri_ != FROM_TOP && z_row != 0) {
          vector<vector<int> > v_copy = v_;
          tmp = v_copy[z_row][z_col];
          v_copy[z_row][z_col] = v_copy[z_row-1][z_col];
          v_copy[z_row-1][z_col] = tmp;
          shared_ptr<State> new_state(new State(v_copy,distance_+1, FROM_BOTTOM));
          s_.push_back(new_state);
        }
        // down
        if (dri_ != FROM_BOTTOM && z_row != (v_.size()-1)) {
          vector<vector<int> > v_copy = v_;
          tmp = v_copy[z_row][z_col];
          v_copy[z_row][z_col] = v_copy[z_row+1][z_col];
          v_copy[z_row+1][z_col] = tmp;
          shared_ptr<State> new_state(new State(v_copy, distance_+1, FROM_TOP));
          s_.push_back(new_state);
        }

        isFound = true;
        break;
      } // if
    } // for
    if (isFound) break;
  }
  return s_;
}

bool State::operator==(const State& rhs) const {
  if (v_ == rhs.v_) {
    return true;
  }
  else { 
    return false;
  }
}

int main() {  
  M = 3;
  vector<vector<int> >e_v(vector<vector<int> >(M, vector<int>(M,0))); 
  for (int i = 0 ; i < M; i++) 
    for (int j = 0 ; j < M; j++)
      e_v[i][j] = i*M + j; 

  shared_ptr<State> endState(new State(e_v, 0, FROM_ZERO));
  {
    queue<shared_ptr<State>> q;
    q.push(endState);
    int distance = 0; 
    int count = 0;
    shared_ptr<State>* stArray = new shared_ptr<State> [MAX_STATE];
    int cacheArray[MAX_STATE] = {0, };
    int y = 0; 
    stArray[y++] = endState;

    while (!q.empty()) {
      shared_ptr<State> here = q.front();
      cacheArray[here->get_hash()] = 1;
      //cout << here->get_hash() << "set " << endl;
      q.pop();
      count++;
      if (!(count%10000)) { 
         cout << count << ", q.size() " << q.size() << endl;
      }
      vector<shared_ptr<State> > adjacent = here->getAdjacent();
      for (int i = 0; i < adjacent.size(); i++) {
        bool foundInArray = false;
        // @20160507-vincent: Warning
        // as size of y is getting bigger (e.g. 108000), even linear search is not good
        // enough. This part is getting much slower as many more elements in the queue
        if (cacheArray[adjacent[i]->get_hash()] == 1) {
          //cout << "." ; 
          for (int x = 0; x < y; x++) {
            if (stArray[x]->get_hash() == adjacent[i]->get_hash()) {
              if (*stArray[x] == *adjacent[i]) {
                foundInArray = true;
                break;
              }
              else {
                cout << "Collision...exit" << stArray[x]->get_hash() <<  endl;
                exit(1);
              }
            }
          }
        }

        if (!foundInArray) {
          stArray[y++] = adjacent[i];
          q.push(adjacent[i]);
        }
      }
    }
  }

  return 0;
}
