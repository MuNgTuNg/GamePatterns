#pragma once
#include <iostream> 
#include <chrono>
#include <thread>

#define COMMAND_LINE
//#define WINDOWED

namespace shb{

    enum{
    BUTTON_X,
    BUTTON_Y,
    BUTTON_Z,
    BUTTON_W,
    BUTTON_UP,
    BUTTON_DWN
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

    int x_, y_;
};



/////////////////////////////////////////////
//COMMANDS
////////////////////////////////////////////


class Command 
{
 public:
    Command() {}
    virtual ~Command() {}
    virtual void execute(Entity&) = 0;

};




// class MoveUnitCmd : public Command{
//  public:
     
//      MoveUnitCmd(Entity* unit, int x, int y) : unit_(unit), x_(x), y_(y){}

//      virtual void execute() override {
//         unit_->moveTo(x_,y_);
//      }

//      Entity* unit_;
//      int x_, y_;
// };





class JumpCmd : public Command {
 public:
    JumpCmd() = default;
    
    virtual void execute(Entity& entity){
        entity.jump();
    }
   
};

class ShootCmd : public Command {
 public:
    ShootCmd() = default;
    virtual void execute(Entity& entity){
        entity.shoot();
    }
};

class CryCmd : public Command {
 public:
    CryCmd() = default;
    virtual void execute(Entity& entity){
        entity.cry();
    }
};

class PooCmd : public Command {
 public:
    PooCmd() = default;
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
            else if(i == BUTTON_W){
                return button_w;
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