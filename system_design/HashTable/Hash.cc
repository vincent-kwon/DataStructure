/*
 * =====================================================================================
 *
 *       Filename:  Hash.cc
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  01/28/2016 08:49:02 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Hobum (Vincent) Kwon (mn), hobum.kwon@gmail.com
 *        Company:  Samsung Electornics
 *
 * =====================================================================================
 */

#include <iostream>
#include <vector>
#include <map>
#include <pthread.h>
#include <unistd.h>
using namespace std;

template <typename T>
class Node {
 public:

  Node(T t) : value_(t) {
    //cout << "[Node] constructor " << value_ << endl;
  };

  Node(const Node& o) {
    value_ = o.value_;
    //cout << "[Node] copy const " << value_ << endl;
  }

  virtual ~Node() {
    //cout << "[Node] destructor " << value_ <<  endl;
  };

  void operator=(const Node& o) {
    value_ = o.value_;
    //cout << "[Node] assignment " << value_ << endl;
  };

  T get_value() { 
    //cout << "[Node] get_value: " << value_ << endl;
    return value_; 
  };

  int GetHash() {
    return static_cast<int>(value_);
  }
 private:
  T value_;
};

template <typename S>
class HashBuckets {
 public:
  HashBuckets() {
    v_.resize(HASH_SIZE);
  };

  HashBuckets(HashBuckets& o) {
    //cout << " copy const " << endl;
  }

  void add(Node<S> i) {
    int val = i.GetHash(); 
    int hashBucketVal = val % HASH_SIZE;
    bool found = false;

    if (v_[hashBucketVal].size() == 0) 
    {
      cout << "add " << i.get_value() << endl;
      v_[hashBucketVal].push_back(i);
    }
    else {
      typename vector<Node<S>>::iterator itor =  v_[hashBucketVal].begin();
      for (itor; itor != v_[hashBucketVal].end(); itor++) {
        Node<S> node = *itor;
        if (node.GetHash() == val) {
          found = true;
          cout << "No add(dup) " << i.get_value() << endl;
          break;
        }
      }
      if (found == false) {
        v_[hashBucketVal].push_back(i);
        cout << "add " << i.get_value() << endl;
      }  
    }
  };

  void remove(Node<S> i) {
    int val = i.GetHash(); 
    int hashBucketVal = val % HASH_SIZE;
    if (v_[hashBucketVal].size() != 0) 
    {
      typename vector<Node<S>>::iterator itor =  v_[hashBucketVal].begin();
      for (itor; itor != v_[hashBucketVal].end(); itor++) {
        Node<S> node = *itor;
        if (node.GetHash() == val) {
          v_[hashBucketVal].erase(itor);
          cout << "remove " << i.get_value() << endl;
          break;
        }
      }
    }
  };
 
  virtual ~HashBuckets() {
    cout << " destructor " << endl;
  };

  void operator=(HashBuckets& o) {
    cout << " assignment operator " << endl;
  };

 private:
  vector< vector<Node<S>> > v_;
  static const int HASH_SIZE = 100;
};

struct Test {
 pthread_mutex_t* pm;
 pthread_cond_t* sm;
};
void *run (void *arg) {
  Test* t = static_cast<Test *>(arg);
  pthread_mutex_t* pm = t->pm;
  pthread_cond_t* tm = t->sm;
  while (1) {
    pthread_mutex_lock(pm);
    cout << "I am loud " << pthread_self() << endl;
    pthread_cond_signal(tm);
    pthread_cond_wait(tm, pm);
    cout << "waked up " << pthread_self() <<  endl;
    pthread_mutex_unlock(pm);
    sleep(1);
  }
}

int i = 1000;


int main() {
  Node<int> t1(1);
  Node<int> t2(2);
  Node<int> t3(3);
  Node<int> t4(1);
  Node<int> t5(1);  
  Node<int> t6(1);
  HashBuckets<int> hash;
  hash.add(t1);
  hash.add(t2);
  hash.add(t3);
  hash.add(t4);
  hash.remove(t1);
  hash.add(t5);
  hash.add(t6);
  cout << "Hello" << endl;
  map<string, int> m;
  m["hell"] = 100;
  map<string, int>::iterator mitor = m.begin();
  std::pair<string, int>  p { "Good", 200 }; 
  if (m.find("hell") != m.end()) {
    cout << "Found Hell:" << m["hell"] << endl;
  }
  pthread_t curThread[10];
  pthread_mutex_t pm;
  pthread_cond_t sm;

  pthread_mutex_init(&pm, NULL);
  pthread_cond_init(&sm, NULL);
  
  Test t;
  t.pm = &pm;
  t.sm = &sm;

  for (int i = 0 ; i < 10 ; i++)
    pthread_create(&curThread[i], NULL, run, &t);

  for (int i = 0 ; i < 10 ; i++)
    pthread_join(curThread[0], NULL);
}
