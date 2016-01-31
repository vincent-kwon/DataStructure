#ifndef LRU_CACHE_H_
#define LAU_CACHE_H_
//c include
//#include 

//c++ include
#include <iostream>
#include <cassert>

//namespace
using namespace std;

#define BASE_EXPORT __attribute__((visibility("default")))

namespace vc {
namespace algorithm {
  
// namespace macro
#define DISALLOW_COPY_AND_ASSIGN(TypeName) \
    TypeName(TypeName&) = delete; \
    void operator=(TypeName) = delete;

// namespace enum
enum SomeEnum {
  VALUE1 = 1 << 0,
  VALUE2 = 1 << 1,
  VALUE3 = 1 << 2,
  VALUEALL= VALUE1 | VALUE2 | VALUE3
};

// namespace struct
struct BASE_EXPORT Element {
  int key;
  int value;
};   

// namespace static const int

// namespace static function
//BASE_EXPORT bool GetLogValue() {
//  return true;
//}

class BASE_EXPORT LRUCache 
{
 public:
  LRUCache(int capacity) 
      : capacity_(capacity), // four space before colon
        sz_(0)
  {
    arr_ = new Element[capacity];
  }
  virtual ~LRUCache(); // release array;
  void Adjust(int index);
  int Get(int key);
  void Set(int key, int value);
  void Print();
  unsigned long get_error() { return last_error_; }; 
  int get_sz() { return sz_; };
  int get_capacity() { return capacity_; };
  const int kDaysInWeeks = 7;
  //static int StaticFunc() { return 0; };
  DISALLOW_COPY_AND_ASSIGN(LRUCache);
 
 private:
  unsigned long last_error_;
  Element *arr_;
  int sz_;
  int capacity_; 
};

LRUCache::~LRUCache() 
{
  cout << "Destructor..." << endl;
}

int LRUCache::Get(int key) 
{
  for (int i = 0; i < sz_ ; i++) 
  {
    if (arr_[i].key == key) 
    {
      int value = arr_[i].value;
      Adjust(i);
      return value;
    }
  }
  return 0;
}

void LRUCache::Set(int key, int value) 
{
  for (int i = 0 ; i < sz_; i++) 
  {
    if (arr_[i].key == key) 
    {
      arr_[i].value = value;
      Adjust(i); // existing element
      return;
    }
  }

  if (sz_ == capacity_) 
  {
    //delete least used element
    for (int i = 0; i < sz_ - 1; i++) {
      arr_[i] = arr_[i+1];
    }
  
   arr_[sz_-1].key = key;
   arr_[sz_-1].value = value;
  }
  else {
    arr_[sz_].key = key;
    arr_[sz_].value = value;
    sz_++;
  }
}

void LRUCache::Adjust(int index) 
{
  if (index == sz_ - 1) // already at the recently used 
    return;

  Element cur = arr_[index];
  for (int i = index; i < sz_-1; i++) 
  {
    arr_[i] = arr_[i+1];
  }
  arr_[sz_-1] = cur;
}

void LRUCache::Print() {
  for (int i = 0; i < sz_ ; i++) 
  {
    cout << arr_[i].key << ":" << arr_[i].value << endl;
  }
}

}  // algorithm ends
}  // vc ends
#endif 

int main() 
{
  vc::algorithm::LRUCache lru(5);
  lru.Set(1, 100);
  lru.Set(2, 200);
  lru.Set(3, 300);
  lru.Set(4, 400);
  lru.Set(5, 500);
  lru.Print();
  cout << lru.Get(3) << endl;
  cout << lru.Get(2) << endl;
  cout << lru.Get(1) << endl;
  lru.Set(6, 600);
  lru.Print();
}
