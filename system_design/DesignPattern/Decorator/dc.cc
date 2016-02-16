#include <iostream>

using namespace std;

class Beverage {
 public:
  Beverage() { cout << "Beverage constructor" << endl; }; // private so that it can not be called
  Beverage(const Beverage& other) {}; // copy constructor is private
  Beverage& operator=(const Beverage &) { };
  virtual ~Beverage() {};
  virtual double cost() { return 0; } ; 
  void print() { cout << "Hello" << endl; };
  virtual void getDescription() {}; 
 protected:
  string description;
};

class CondimentDecorator : public Beverage {
  virtual string getDescription() = 0;
};

class Espresso : public Beverage {
 public:
  Espresso() {
    description = "espreso" ;
  };

  double cost() {
    return 1.99;
  }
};

class Mocha : public CondimentDecorator {
public:
  Mocha(Beverage* b) {
   beverage_ = b;
  };

  string getDescription() {
    return beverage_->getDescription() + ", mocha";
  };

  double cost() {
    return .20 + beverage_->cost();
  };

protected:
  Beverage* beverage_;
};


class Whip : public CondimentDecorator {
public:
  Whip(Beverage* b) {
   beverage_ = b;
  };

  string getDescription() {
    return beverage_->description + ", whip";
  };

  double cost() {
    return .5 + beverage_->cost();
  };

protected:
  Beverage* beverage_;
};
int main() {
  Beverage* v = new Espresso();
  cout << "EP: " << v->cost() << endl;
  Beverage* v2 = new Espresso();
  v2 = new Mocha(v2); 
  v2 = new Mocha(v2);
  v2 = new Whip(v2);
  cout << v2->cost() << endl;
  cout << v2->getDescription() << endl;
}
