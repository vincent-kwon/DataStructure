#include <iostream>
#include <exception>

using namespace std;

class MyException : public exception {
 public:
  virtual const char* what() const throw () {
    return "my exceptionioius";
  }
}


class Test {
 public:
  void get() {
    try {
     doIt();
    }
    catch (const invalid_argument& ex) {
      cout << ex.what() << endl;
    }
  };

  void doIt() throw MyException {
   throw ;
  };
};

int main() {
  cout << "enter" << endl;
  Test t;
  t.get();
  return 1;
}
