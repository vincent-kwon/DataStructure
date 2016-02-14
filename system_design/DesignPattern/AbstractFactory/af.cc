#include <iostream>

using namespace std;

class Pizza {
 public:
  void prepare() {
  };
  void bake() {
  };
  void cut() {
  };
  void box() {
  };
 protected:
  string name;
};

class NYCheesePizza : public Pizza {
 public:
  void prepare() {
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

class PizzaStore { // my pizza stores are different in states
  // want to have formalized way to create pizza to have equal qualities
 public:
  // beauty of this is reusing this implementation
  virtual Pizza& orderPizza(string type) {
    Pizza& pizza = createPizza(type);
    pizza.prepare();
    pizza.bake();
    pizza.cut();
    pizza.box();

    return pizza;
  };
 protected: 
  // encapsulate object creation code in sub class
  virtual Pizza& createPizza(string type);

 private:

};

class NYPizzaStore : public PizzaStore {
 public:
  Pizza& createPizza(string item) {
    if (item == "cheese") {
      cout << "Cheese Pizza NY " << endl;
    } 
  }; 
};

int main() {
  NYPizzaStore nyPizzaStore;
  nyPizzaStore.orderPizza("cheese");
}
