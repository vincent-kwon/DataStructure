#include <iostream>

using namespace std;

/*
 * Why do we need this? fly can be 95% shared. 
   But 5% can't
   options:
   1. keep stay implementation in Duck and fix every variation like fakeduck 
      pros: code reuse
      cons: have to carefully override fly and quack in variations
   2. make quack, fly = 0 (pure virtual function)
      cons: no code reuse
   3. make quack, fly use implementation classes
 * 
 */


class FlyBehavior {
 public:
  virtual void fly() = 0;
};

class Duck {
 public:
  void common1() { cout << "[duck] common 1" << endl; };
  void common2() { cout << "[duck] common 2" << endl; };
  virtual void quack()   { cout << "[duck] quack" << endl;    };
  virtual void fly()     { fb->fly(); };
 protected:
  FlyBehavior *fb;

};

class CommonFly : public FlyBehavior {
 public:
  virtual void fly() { cout << "[CommonFly] " << endl; };
};

class NoFly : public FlyBehavior {
 public:
  virtual void fly() { cout << "[NoFly] " << endl; };
};

class BeijingDuck : public Duck {
 public:
  BeijingDuck() {
    fb = new CommonFly();
  };
  virtual void quack() { cout << "[Bduck] quak" << endl; }
  virtual void fly() { cout << "[Bduck] fly" << endl; }
};

class FakeDuck : public Duck {
 public:
  FakeDuck() {
    fb = new NoFly();
  };
  virtual void quack() { cout << "[Fduck] queek quak" << endl; }
  virtual void fly() { cout << "[Fduck] no fly" << endl; }
};


int main() {
 Duck *d = new BeijingDuck();
 Duck *d2 = new FakeDuck();
 d->common1();
 d->fly();
 d->quack();

 d2->fly();
 d2->quack();
 d2->Duck::fly();
 return 1;
}
