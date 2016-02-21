#include <iostream>
#include <list>
#include <exception>
#include <stdexcept>

using namespace std;

class Enumerator {
 public:
  Enumerator(int i) 
  {
    cout << "Abstract enumerator" << endl;
  };
  
  virtual void moveNext() 
  {
    current_++;
  };

  virtual void* current() = 0;
 
 protected:
  int size_;
  int current_;
};

class EnumeratorCreator {
 public:
  virtual Enumerator* begin() = 0;

  virtual void* end()
  {
    return nullptr;
  }
};

class MenuItem 
{
 public:
  MenuItem(string name, string description, bool vegetarian, double price) 
  {
    name_ = name;
    description_ = description;
    vegetarian_ = vegetarian;
    price_ = price;
  };

  MenuItem() 
  {
    
  }

  MenuItem(const MenuItem& obj) 
  {
    name_ = obj.get_name();
    description_ = obj.get_description();
    vegetarian_ = obj.get_vegetarian();
    price_ = obj.get_price();
  }

  void operator=(MenuItem& obj) 
  {
    name_ = obj.get_name();
    description_ = obj.get_description();
    vegetarian_ = obj.get_vegetarian();
    price_ = obj.get_price();
  }

  string get_name() const { return name_; };
  
  string get_description() const { return description_; };

  bool get_vegetarian() const { return vegetarian_; };

  double get_price() const { return price_; };

  void set_name(string name) { name_ = name; };
  
  void set_description(string description) { description_ = description; };

  void set_vegetarian(bool vegetarian) { vegetarian_ = vegetarian; };

  void set_price(double price) { price_ = price; };
 
  void print() 
  {
    cout << name_ << "," << description_ << "," << vegetarian_ << "," << price_ << endl;
  };
 protected:
  string name_;
  string description_;
  bool vegetarian_;
  double price_;
};

class DinerEnumerator : public Enumerator 
{

 public:

  DinerEnumerator(MenuItem *menuItems, int size, int startIndex) : Enumerator(0)
  {
    cout << "Dinner Enumerator" << endl;
    menuItems_ = menuItems;
    size_ = size;
    current_ = startIndex;
  };

  virtual void* current() 
  {
    if (current_ < size_) 
    {
      return (void*) (menuItems_ + current_);
    }
    else 
    {
      return nullptr;
    }
  };

 protected:
  MenuItem *menuItems_;
 private:
};

class DinerMenu : public EnumeratorCreator 
{
 public:
  static const int MAX_ARRAY = 10; 
  friend class DinerEmulator;

  DinerMenu() 
  {
    menuIndex_ = 0; 
    MenuItem it1("Dinner[K]", "scramble", true, 2.99);
    MenuItem it2("Dinner[B]", "waffle", true, 2.32);    
    addItem(it1);
    addItem(it2);
  };

  void addItem(MenuItem& item) 
  {
    if (menuIndex_ < MAX_ARRAY) 
    {
      menuItems[menuIndex_] = item;
      menuItems[menuIndex_].print();
      menuIndex_++;
    }
    else 
    {
      throw std::out_of_range("array out of bound");
    }
  };

  virtual Enumerator* begin() 
  {
    return (new DinerEnumerator(&menuItems[0], menuIndex_, 0));
  }

  virtual void* end() 
  {
    return nullptr;
  }

 protected:
  MenuItem menuItems[MAX_ARRAY];
  int menuIndex_;
};

int main() 
{
  DinerMenu dm;
  Enumerator* en = dm.begin();
  for (; en->current() != dm.end(); en->moveNext()) {
    MenuItem* it = static_cast<MenuItem*>(en->current()); 
    cout << it->get_name() << endl;
  }
  return 0;
}
