#pragma once
#include <iostream> 
#include <chrono>
#include <thread>

#define COMMAND_LINE
//#define WINDOWED

namespace shb{

    enum{
    BUTTON_X, //1
    BUTTON_Y, //2
    BUTTON_Z, //3
    BUTTON_W, //4
    BUTTON_UP, //5
    BUTTON_DWN, //6
    BUTTON_LFT, //7
    BUTTON_RGT //8
    }; 

class VirtualEntity{
 public:
    virtual void jump() =0;
    virtual void shoot() = 0;
    virtual void poo() = 0;
    virtual void cry() = 0;
    virtual void moveTo(int, int) =0;

};
class Entity : public VirtualEntity{
 public:
    virtual void jump(){}
    virtual void shoot(){}
    virtual void poo(){}
    virtual void cry(){}
    virtual void moveTo(int, int){}
    int x() { return x_; }
    int y() { return y_; }

    int x_, y_;
};



/////////////////////////////////////////////
//COMMANDS
////////////////////////////////////////////


class virtCommand 
{
 public:
    virtCommand(){}
    virtual ~virtCommand() {}
    virtual void execute(Entity&) = 0;
    virtual void execute() = 0;

};
class Command : virtCommand 
{
 public:
    Command() {}
    virtual ~Command() {}
    virtual void execute(Entity&){}
    virtual void execute() {}

};

class MoveUnitCmd : public Command
{
 public:
    MoveUnitCmd(Entity* unit, int x, int y) : unit_(unit), x_(x), y_(y){ }
  
    virtual void execute(){
        std::cout<< "moved " << typeid(*this).name() << "x: " << x_ << "Y: " << y_ << "\n";
        unit_->moveTo(x_,y_);
    }

 private:
   Entity* unit_;
   int x_;
   int y_;
};






class JumpCmd : public Command {
 public:
    JumpCmd() = default;
    virtual void execute(){}
    virtual void execute(Entity& entity){
        entity.jump();
    }
   
};

class ShootCmd : public Command {
 public:
    ShootCmd() = default;
    virtual void execute(){}
    virtual void execute(Entity& entity){
        entity.shoot();
    }
};

class CryCmd : public Command {
 public:
    CryCmd() = default;
    virtual void execute(){}
    virtual void execute(Entity& entity){
        entity.cry();
    }
};

class PooCmd : public Command {
 public:
    PooCmd() = default;
    virtual void execute(){}
    virtual void execute(Entity& entity){
        entity.poo();
    }
};


#ifdef WINDOWED
bool isPressed(int button){
    if(button){ //keyboard input needed from a windowed programme
        return true;
    }
    else{
        return false;
    }

}
#endif


Entity* getSelectedUnit(){
 //todo

}


class InputHandler {
 public:

    Entity* unit = getSelectedUnit();

    InputHandler() { bindInput();} //bind input at construction

    Command* handleInput(int i){ //hack input from cin
      
      
        #ifdef COMMAND_LINE
             if(i == BUTTON_X){
                return button_x;
            }
            else if(i == BUTTON_Y){
                return button_y;
            }
            else if(i == BUTTON_Z){
                return button_z;
            }
            else if(i == BUTTON_DWN){ //move unit up one
                int destY = unit->y() -1;
                return new MoveUnitCmd(unit, destY, unit->x());
            }
            else if(i == BUTTON_UP){ //move down
                int destY = unit->y() +1;
                return new MoveUnitCmd(unit, destY, unit->x());
            }
            else if(i == BUTTON_LFT){ //move unit left one
                int destX = unit->x() -1;
                return new MoveUnitCmd(unit, unit->y(), destX);
            }
            else if(i == BUTTON_RGT){ //move right
                int destX = unit->x() +1;
                return new MoveUnitCmd(unit, unit->y(), destX);
            }
           
            else{
                std::cout<<"Wrong input!\n";
    
                return nullptr;
            }
        #endif
    
    
        #ifdef WINDOWED
            if(isPressed(BUTTON_X)){  //need to implement when using opengl
                return button_x;
            }
            else if(isPressed(BUTTON_Y)){
                return button_y;
            }
            else if(isPressed(BUTTON_Z)){
                return button_z;
            }
            else if(isPressed(BUTTON_W)){
                return button_w;
            }
    
            return nullptr;
        #endif
        
    }
    

    void bindInput(){
        if(true){ //set conditions for binding commands
        button_x = &cry;
        button_y = &poo;
        button_z = &jump;
        button_w = &shoot;
        

        }
    }


    
 private:
    Command* button_x;  //list of buttons
    Command* button_y;
    Command* button_z;
    Command* button_w;
  

    JumpCmd jump;      //member variables for commands
    ShootCmd shoot;
    CryCmd cry;
    PooCmd poo;
   
};



}//namespace shb