#include <iostream> 
#include <time.h>
#include <random>
#include <stdlib.h>


//update pattern is fairly simple and a huge part of a game engine's architecture. it allows all classes to implement and encapsulate their own individual frame's worth of behaviour and 
//iterate however it could be defined


#define FAR_RIGHT 20
#define FAR_LEFT 10
#define TOP 50
#define BOTTOM 20
#define MAX_AGE rand() % 100


class Entity //haven't learned about entity component yet so update() will go straight on to entity class for now
{
 public:
    virtual void update() = 0;

    int getX() { return x; }
    int getY() { return y; }
    int getAge() { return age; }
    void printXY(){
    std::cout<< "coordinates: " << getX() << " " << getY() << "\n\n";
    }


    void checkIfDead() {
        if(++age >= MAX_AGE){
           if(isDead) { return; }
           std::cout<< name << " is dead\n\n";
           isDead = true;
        }
    }
    

 protected:
    int age = 0; //idk why i have added an age member but i have
    int x =FAR_RIGHT/2 + FAR_LEFT/2 , y =TOP/2 + BOTTOM/2;
    bool isDead = false;
    std::string name;


};



class Man : public Entity //man patrols the x axis
{
 public:
    void update() override{
        
        checkIfDead();
        if(isDead)
        {  
            return;
        }

        else
        {   
            std::cout<<"MAN UPDATE\n";

            if(isWalkingLeft){        //patrolling logic (from memory)
               --x == FAR_LEFT ? isWalkingLeft = false : isWalkingLeft;
               
            }else{
                ++x == FAR_RIGHT ? isWalkingLeft = true : isWalkingLeft;
               
            }
            printXY();

        }

        

    }

   Man() { name = "Man"; }

 private:
    bool isWalkingLeft = true;
    


};



class Woman : public Entity //woman patrols the y axis but ages indefinitely
{
 public:
    void update() override{

        if(canDie){
        checkIfDead(); //does not die (modular death value)
        }
        if(isDead){
            return;
        }

        else{
            std::cout<<"WOMAN UPDATE\n";
            if(isWalkingDown){        //patrolling logic (from memory)
               --y == BOTTOM ? isWalkingDown = false : isWalkingDown;
               
            }else{
                ++y == TOP ? isWalkingDown = true : isWalkingDown;
               
            }
            printXY();

        }
      }

    Woman() { name = "Woman"; }
 private: 
    bool isWalkingDown;
    bool canDie = false;


    
};


class Child : public Entity //child's purpose is to pollute output
{
    void update() override{
        //child also does not age or die
        std::cout<<"GOO GOO GA GA\n";
        std::cout<<"BRRRRRRRRRRRRRR\n";
        std::cout<<" brarsdfea\n";
    }
};

int main()
{
    srand(time(0));
    Entity* man = new Man();
    Entity* woman = new Woman();
    Entity* child = new Child();

    for(int i = 0; i <= 200; ++i ){  //essentially an extremely basic linear game loop
        //std::cout << "Move Number " << i <<":\n";
       // child->update();

        if(i % 10 == 0){  //weird behaviour going on 
            woman->update();
            std::cin.get();
        }

        if(i % 5 == 0){
            man->update();
            std::cin.get();
            
        }

       
    }


    return 0;
}