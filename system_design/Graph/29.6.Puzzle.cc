#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>

#define MAX_M 100

using namespace std;

int M;
int test;
vector<vector<int> >g;

class State {
 public: 
  State(vector<vector<int> > v);
  vector<State> getAdjacent();
  bool operator<(const State& rhs) const;
  bool operator==(const State& rhs) const;
 private:
  vector<vector<int> > v_;
  vector<State> s_;
};

typedef map<State, int> StateMap; // count purpose

State::State(vector<vector<int> > v) {
  v_ = v;
}

vector<State> State::getAdjacent() {
  if (s_.size() > 0) return s_;
  int z_row;
  int z_col;
  for (int i = 0 ; i < v_.size(); i++) {
    bool isFound = false;
    for (int j = 0 ; j < v_[i].size(); j++) {
      if (v_[i][j] == 0) {
        z_row = i;
        z_col = j;

        // now from this zero location create 4 variation in max
        // left
        int tmp;
        if (z_col != 0) {
          vector<vector<int> > v_copy = v_;
          tmp = v_copy[z_row][z_col];
          v_copy[z_row][z_col] = v_copy[z_row][z_col-1];
          v_copy[z_row][z_col-1] = tmp;
          s_.push_back(State(v_copy));   

          for (int i = 0 ; i < M ; i++) {
            for (int j = 0 ; j < M; j++) {
              cout << s_[s_.size()-1].v_[i][j] << " ";
            }
            cout << "" << endl;
          }
          cout << "- left end - " << endl;
        }   
        // right
        if (z_col != (v_.size()-1)) {
          vector<vector<int> > v_copy = v_;
          tmp = v_copy[z_row][z_col];
          v_copy[z_row][z_col] = v_copy[z_row][z_col+1];
          v_copy[z_row][z_col+1] = tmp;
          s_.push_back(State(v_copy));   

          for (int i = 0 ; i < M ; i++) {
            for (int j = 0 ; j < M; j++) {
              cout << s_[s_.size()-1].v_[i][j] << " ";
            }
            cout << "" << endl;
          }
          cout << "- right end - " << endl;
        }
        // up
        if (z_row != 0) {
          vector<vector<int> > v_copy = v_;
          tmp = v_copy[z_row][z_col];
          v_copy[z_row][z_col] = v_copy[z_row-1][z_col];
          v_copy[z_row-1][z_col] = tmp;
          s_.push_back(State(v_copy));   

          for (int i = 0 ; i < M ; i++) {
            for (int j = 0 ; j < M; j++) {
              cout << s_[s_.size()-1].v_[i][j] << " ";
            }
            cout << "" << endl;
          }
          cout << "- up end - " << endl;
        }
        // down
        if (z_row != (v_.size()-1)) {
          vector<vector<int> > v_copy = v_;
          tmp = v_copy[z_row][z_col];
          v_copy[z_row][z_col] = v_copy[z_row+1][z_col];
          v_copy[z_row+1][z_col] = tmp;
          s_.push_back(State(v_copy));   

          for (int i = 0 ; i < M ; i++) {
            for (int j = 0 ; j < M; j++) {
              cout << s_[s_.size()-1].v_[i][j] << " ";
            }
            cout << "" << endl;
          }
          cout << "- down end - " << endl;
        }

        isFound = true;
        break;
      } // if
    } // for
    if (isFound) break;
  }
  cout << "[adj] return " << endl;
  return s_;
}

bool State::operator<(const State& rhs) const {
  cout << "< called" << endl;
  return false;
}

bool State::operator==(const State& rhs) const {
  cout << "enter == " << endl;
  if (v_ == rhs.v_) {
    cout << " == return true " << endl;
    return true;
  }
  else { 
    cout << " == return false " << endl;
    return false;
  }
}

int bfs(State start, State finish) {
  if (start == finish) return 0;

  StateMap c;
  queue<State> q;
  q.push(start);
  c[start] = 0;
  while (!q.empty()) {
    State here = q.front();
    q.pop();
    int cost = c[here];
    vector<State> adjacent = here.getAdjacent();
    for (auto tmp_s : adjacent) 
    {
      
    }
/*
    for (int i = 0; i < adjacent.size(); i++) {
      if (c.count(adjacent[i]) == 0) {
        if (adjacent[i] == finish) return cost + 1;
        c[adjacent[i]] = cost + 1; 
        q.push(adjacent[i]);
      }
    }
*/
  }
  return -1;
}

int main() {  
  M = 4;
  vector<int> tmp = {7, 8, 4, 1, 2, 3, 0, 5, 6, 9, 10, 11, 12, 13, 14, 15};
  vector<vector<int> >s_v(vector<vector<int> >(M, vector<int>(M,0))); 
  for (int i = 0 ; i < M; i++) 
    for (int j = 0 ; j < M; j++)
      s_v[i][j] = tmp[i*4+j]; 
  vector<vector<int> >e_v(vector<vector<int> >(M, vector<int>(M,0))); 
  for (int i = 0 ; i < M; i++) 
    for (int j = 0 ; j < M; j++)
      e_v[i][j] = i * 4 + j; 
  State startState(s_v);
  State endState(e_v);

  // list all adjacent from e_v
  {
    queue<State> q;
    q.push(endState);
//    StateMap m;
    vector<State> m;
    m.push_back(endState);

    //m[endState] = 0;
    int aCount = 1;
    while (!q.empty()) {
      State here = q.front();
      q.pop();
      int cost = 1; // when pushed, value set
      cout << "cost return: " << cost << endl;
      vector<State> adjacent = here.getAdjacent();
      for (int i = 0; i < adjacent.size(); i++) {
        if (find(m.begin(), m.end(), adjacent[i]) == m.end()) {
          //if (adjacent[i] == finish) return cost + 1;
          m.push_back(adjacent[i]); // = cost + 1; 
          cout << i <<  ") add queue : " << endl;
          q.push(adjacent[i]);
          aCount++;
        }
        else 
          cout << i << ") not add , exist " << endl;
      }
      cout << "q.size = " << q.size() << endl;
    }
    cout << "All possible count: " << aCount << endl;
  }

  // get bfs
  //int r = bfs(startState, endState);
  return 0;
}
