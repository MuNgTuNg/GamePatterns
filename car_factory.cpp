#include <iostream>
//i am not hugely fond of this code, i feel there are probably better ways of doing this.
// but i am probably wrong


//base classes to be modified////
class Tire
{
 protected:
  std::string _name;
  int _pressure;
 public:
  Tire(std::string name, int pressure) : _name(name), _pressure(pressure){};
  int getPressure(){return _pressure;}
};

class Body
{
 protected:
    std::string _name;
    int _strength;
 public: 
   Body(std::string name, int strength) : _name(name), _strength(strength){};
   int getStrength(){return _strength;}

};

//Polymorphic Tire & body derived class objects

//Tires
class SimpleTire : public Tire{
 public:
    SimpleTire() : Tire("simple tire", 75) {}

};
class LuxuryTire : public Tire{
 public:
    LuxuryTire() : Tire("Luxury tire", 100) {}

};

//Bodies
class SimpleBody : public Body{
 public:
    SimpleBody() : Body("simple Body", 75) {}

};
class LuxuryBody : public Body{
 public:
    LuxuryBody() : Body("Luxury Body", 100) {}

};

/////////////////////////////////


//central modular object, essentially a tuple/glorified return type
class Car
{
    Tire* _tire;
    Body* _body;
    std::string _name;

 public:
    Car(std::string name) : _name(name) {}
    void setTire(Tire*t) {_tire =t;} 
    void setBody(Body* b) {_body = b;}
 

    void print() { 
        std::cout<< _name <<"\n"<< "tire pressure: " << _tire->getPressure() << "\n"
         << "body: " << _body->getStrength() << "\n"; }

   
   ~Car() { 
        std::cout<<"Deleting Car\n";
        delete _tire;
        delete _body;
        _tire = nullptr;
        _body = nullptr;

    }
};





//abstract factory class
//multiple different factories in a heirarchy
class CarFactory
{
 private:
  Car* car;

 protected:
    virtual Tire* buildTires() = 0;
    virtual Body* buildBody() = 0;

public: 
    virtual Car* buildWholeCar() = 0;
    
};


/////////////////////////////////////////////////////////
//using a class system instead of a switch case. could combine with a switch case using a PickCarType(int) function 
class SimpleCarFactory : public CarFactory 
{
 public:
    Car* buildWholeCar(){
        Car* car = new Car("simple car");
        car->setTire(buildTires());
        car->setBody(buildBody());
        return car;
    }

    ~SimpleCarFactory(){ 
        std::cout<< "deleting SimpleCarFactory\n";
        }

 private:
    Tire* buildTires(){
        return new SimpleTire();
    }
    Body* buildBody(){
        return new SimpleBody();
    }
    
    

};

class LuxuryCarFactory : public CarFactory
{
 public:
    Car* buildWholeCar(){
        Car* car = new Car("luxury car");
        car->setTire(buildTires());
        car->setBody(buildBody());
        return car;
    }

     ~LuxuryCarFactory() { 
        std::cout<< "deleting LuxuryCarFactory\n";
    }

 private:
    Tire* buildTires(){
        return new LuxuryTire();
    }
    Body* buildBody(){
        return new LuxuryBody();
    }
    
   
    
};
/////////////////////////////////////////////////


void run() {
    CarFactory* cheapFactory = new SimpleCarFactory; 
    CarFactory* luxuryFactory = new LuxuryCarFactory;
    
    
    Car* cheapCar = cheapFactory->buildWholeCar();
    cheapCar->print();
    Car* luxCar = luxuryFactory->buildWholeCar();
    luxCar->print();
    
    
    delete cheapCar;
    delete luxCar;
    cheapCar = nullptr;
    luxCar = nullptr;

    delete cheapFactory; //not sure why destructor isnt being run
    delete luxuryFactory;//is it because there is nothing to delete?
    cheapFactory = nullptr;
    luxuryFactory = nullptr;
}




int main()
{
    run();
   

    return 0;
}