#include <iostream>


//sort of recursive

class IObject
{
 public:
   virtual int getValue() =0;
};

class IDecorator : public IObject
{
 public:
  virtual int getValue() =0;
  IDecorator(IObject* object) : _object(object) {}
 protected:
   IObject* _object;

};

class BaseCoffee : public IObject 
{
 public:
   BaseCoffee(int value) : _value(value) {} //concrete object gets instantiated with value, or has value tagged to it, doesnt matter
   int getValue() override { return _value; }
 private:
    int _value;


};

class Syrup : public IDecorator
{
 public:
   Syrup(IObject* object) : IDecorator(object) {}

   int getValue() override {
      return _object->getValue() + _value;
    }

 private:
   int _value = 25;
};

class NumberOfCoffee : public IDecorator
{
 public:
   NumberOfCoffee(int value, IObject* object) : IDecorator(object), _value(value) {}

   int getValue() override {
      return _object->getValue() * _value;
    }

 private:
   int _value;
};

int main(){

    //i dont think i like any of this. this is a confusing mess.
    BaseCoffee coffee(100);
    NumberOfCoffee numOfCoffee(3, &coffee);
    Syrup syrup(&numOfCoffee);
    Syrup syrup2(&syrup);
    std::cout<< syrup2.getValue();
    




}