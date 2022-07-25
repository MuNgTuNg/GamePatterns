#include <iostream>


//not a particularly memory safe program, use smart pointers in actual code

class Singleton
{
 public:
   static Singleton* getInstance();

 private:
   static Singleton* instance;
   Singleton() {}

};

 Singleton* Singleton::instance = nullptr;

 Singleton* Singleton::getInstance(){
    if(instance == nullptr){
      std::cout<<"creating new instance\n";
      instance = new Singleton();
    }
    std::cout<<"returning instance\n";
    return instance;
    
   }


int main()
{
  Singleton* singleton1 = Singleton::getInstance();
  Singleton* singleton2 = Singleton::getInstance();
  Singleton* singleton3 = Singleton::getInstance();
  Singleton* singleton4 = Singleton::getInstance();
  Singleton* singleton5 = Singleton::getInstance();
  Singleton* singleton6 = Singleton::getInstance();
  Singleton* singleton7 = Singleton::getInstance();

  delete singleton1;
  //delete singleton2; //double delete

  singleton2 = nullptr;
  singleton3 = nullptr;
  singleton4 = nullptr;
  singleton5 = nullptr;
  singleton6 = nullptr;
  singleton7 = nullptr;

 return 0;
}