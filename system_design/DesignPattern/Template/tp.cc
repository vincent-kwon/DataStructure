#include <iostream>

using namespace std;

class SomeBeverage {
 public:
  virtual void tear() final { cout << "tear " << endl; };
  virtual void pourOn() final { cout << "pour on " << endl; };
  virtual void addSomething() = 0;
  virtual void brew() = 0;
};

class CoffeeBeverage : public SomeBeverage {
 public: 
  void addSomething() {
    cout << "[coffee] cream and sugar " << endl;
  };
  void brew() {
    cout << "[coffee] coffee brew " << endl;
  };
};

class TeaBeverage : public SomeBeverage {
  void addSomething() {
    cout << "[Tea] milk tea " << endl;
  };
  void brew() {
    cout << "[Tea] tea brew " << endl;
  };
};

int main() {
  SomeBeverage *s = new CoffeeBeverage();
  s->tear();
  s->pourOn();
  s->addSomething();
  s->brew();

  cout << "start tea " << endl;

  SomeBeverage *s1 = new TeaBeverage();
  s1->tear();
  s1->pourOn();
  s1->addSomething();
  s1->brew();
  return 0;
}
