#include <iostream>

using namespace std;

class Singleton {
 private:
  Singleton() { cout << "private constructor" << endl; }; // private so that it can not be called
  Singleton(const Singleton& other) {}; // copy constructor is private
  Singleton& operator=(Singleton const&) {};
  ~Singleton() {};
  static Singleton* instance;
 public:
  static Singleton* getInstance() { 
    if (instance == NULL) 
      instance = new Singleton();
    return instance; 
  };
  static void destroy() {
    delete instance;
  };
  void print() { cout << "Hello" << endl; };
};

// need global static pointer to ensure a single instance of the class
Singleton* Singleton::instance = nullptr;

int main() {
  Singleton* obj = Singleton::getInstance();
  obj->print();
  // Below is not working since it has private constructor only
  //Singleton* try1 = new Singleton(); 
}
