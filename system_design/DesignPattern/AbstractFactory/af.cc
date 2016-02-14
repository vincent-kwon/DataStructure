#include <iostream>

using namespace std;

class Pizza {
 public:
  Pizza(string n, string d, string s) : name(n), dough(d), sauce(s) {};
  virtual void prepare() = 0; // This is abstract factory method !!!
  virtual void bake() = 0;
  virtual void cut() = 0;
  virtual void box() = 0;
 protected:
  string name;
  string dough;
  string sauce;
};

class NYCheesePizza : public Pizza {
 public:
  NYCheesePizza(string n, string d, string s) : Pizza(n, d, s) {
  }

  void prepare() {
    cout << name << "," << dough << "," << sauce << endl;
    cout << "NYCheese Prepare" << endl;
  };
  void bake() {
    cout << "NYCheese Bake" << endl;
  };
  void cut() {
    cout << "NYCheese Cut" << endl;
  };
  void box() {
    cout << "NYCheese Box" << endl;
  };
};

class ChicagoCheesePizza : public Pizza {
 public:
  ChicagoCheesePizza(string n, string d, string s) : Pizza(n, d, s) {
  }
  void prepare() {
    cout << name << "," << dough << "," << sauce << endl;
    cout << "CHCheese Prepare" << endl;
  };
  void bake() {
    cout << "CHCheese Bake" << endl;
  };
  void cut() {
    cout << "CHCheese Cut" << endl;
  };
  void box() {
    cout << "CHCheese Box" << endl;
  };
};

// This is factory method
class PizzaStore { // my pizza stores are different in states
  // want to have formalized way to create pizza to have equal qualities
 public:
  // beauty of this is reusing this implementation
  virtual Pizza* orderPizza(string type) {
    Pizza* pizza = createPizza(type);
    pizza->prepare();
    pizza->bake();
    pizza->cut();
    pizza->box();

    return pizza;
  };
 protected: 
  // encapsulate object creation code in sub class
  virtual Pizza*  createPizza(string type) = 0;

 private:

};

class NYPizzaStore : public PizzaStore {
 public:
  Pizza* createPizza(string item) {
    if (item == "cheese") {
      cout << "Cheese Pizza NY " << endl;
      return new NYCheesePizza("NYCheese", "thin", "tomato");
    } 
  }; 
};

class ChicagoStore : public PizzaStore {
 public:
  Pizza* createPizza(string item) {
    if (item == "cheese") {
      cout << "Cheese Pizza Chicago " << endl;
      return new ChicagoCheesePizza("ChcCheese", "thick", "white");
    } 
  }; 
};

int main() {
  PizzaStore* ps1 = new NYPizzaStore();
  Pizza* pz1 = ps1->orderPizza("cheese"); // factory to create Pizza
  PizzaStore* ps2 = new ChicagoStore();
  Pizza* pz2 = ps2->orderPizza("cheese");
}
