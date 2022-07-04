#include <iostream>

//i do like this code. feels very streamlined Nd organised but also definitely has pitfalls



class Toy{
   public:
    virtual void prepare() = 0;
    virtual void build() = 0;
    virtual void paint() = 0;
    virtual void complete() = 0;
};


class Car : public Toy
{
    public:
     void prepare() { std::cout<<"preparing car\n";}
     void build() { std::cout<<"building car\n";}
     void paint() { std::cout<<"painting car\n";}
     void complete() { std::cout<<"car complete\n\n";}

};
class Dog : public Toy
{
    public:
     void prepare() { std::cout<<"preparing dog\n";}
     void build() { std::cout<<"building dog\n";}
     void paint() { std::cout<<"painting dog\n";}
     void complete() { std::cout<<"dog complete\n\n";}

};
class gun : public Toy
{
    public:
     void prepare() { std::cout<<"preparing gun\n";}
     void build() { std::cout<<"building gun\n";}
     void paint() { std::cout<<"painting gun\n";}
     void complete() { std::cout<<"gun complete\n\n";}

};

//only one type of factory for many toys
//concrete factory class, switch case is used instead of virtual functions
class ToyFactory{
 public:
    static Toy* buildToy(int i)
    {
        Toy* toy;

        switch(i){
            case 1:
             toy = new Car();
             break;
            case 2:
             toy = new Dog();
             break;
            case 3:
             toy = new gun();
             break;
            default:
             std::cout<<"try again";

        }
        
        toy->prepare();
        toy->build();
        toy->paint();
        toy->complete();
        return toy;

    }


};


int main()
{

    Toy* carToy = ToyFactory::buildToy(1);
    Toy* dogToy = ToyFactory::buildToy(2);
    Toy* gunToy = ToyFactory::buildToy(3);


    return 0;
}