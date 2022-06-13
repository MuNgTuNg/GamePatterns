#pragma once
#include "input.h"
namespace shb{



class Cat : public Entity{
 public:
   
   //static moves
   void jump() override {
     std::cout<< "Cat jumps!\n";
   }
   void shoot() override {
    std::cout << "cat shoots!\n";
   }
   void poo() override{
    std::cout<<"dirty boy >:(\n";
   }
   void cry() override{
    std::cout<< typeid(*this).name() << "cries!\n";
   }

   //movement
   void moveTo(int x, int y) override{
    x_ = x;
    y_ = y;
   }

 private:
   int x_,y_;
};





class Dog : public Entity{
 public:
   void jump() override {
     std::cout<< "dog jumps!\n";
   }
   void shoot(){ std::cout<<"dog cannot shoot!\n";}

    void poo() override{
    std::cout<<"dirty boy >:(\n";
   }
   void cry() override{
    std::cout<< typeid(*this).name() << "cries!\n";
   }
};


class Carrot : public Entity{
 public:
   void jump() override {
     std::cout<< "carrot cant jump!\n";
   }
   void shoot(){ std::cout<<"carrot cant shoot\n";}

    void poo() override{
    std::cout<<"dirty boy >:(\n";
   }
   void cry() override{
    std::cout<< typeid(*this).name() << "cannot cry!\n";
   }
};





}