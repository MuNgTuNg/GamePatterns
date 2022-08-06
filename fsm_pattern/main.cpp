#include <iostream>

// enum state{         //used in a switch instead of heirarchical solution
//     STATE_STANDING,
//     STATE_JUMPING,
//     STATE_FALLING,
//     STATE_CROUCHING
// }; 

enum input{
    PRESS_UP,
    PRESS_DOWN,
    RELEASE_UP,
    RELEASE_DOWN
};

enum imageIndex{
    IMAGE_STAND,
    IMAGE_CROUCH,
    IMAGE_JUMP,
    IMAGE_FALL
};




class Entity;

class EntityState{
 public:
    Entity* entity_;
    virtual void handleInput(int i) = 0;
    virtual void update() = 0;

    void setEntity(Entity* entity){
        entity_ = entity;
    }

    virtual void enter() = 0;
};



class Entity{
 public:

    Entity(EntityState* state) {
        transitionTo(state);
    }

    virtual void handleInput(int i){
        state_->handleInput(i);
    }

    void transitionTo(EntityState* state){
        if(state_!= nullptr){
            delete state_;
        }
        state_ = state;
        state_->setEntity(this);
    }

    void update(){
        state_->update();
    }

    EntityState* state_ = nullptr;

};



class DuckingState : public EntityState {
 public:
    DuckingState() :bombTimer(0) { enter(); }
    ~DuckingState() { exit(); }
    
    virtual void enter() {
        //setgraphics IMAGE_DUCKING
    }
    virtual void exit() {
        //cleanup
    }
    
    virtual void handleInput(int input) override;

    virtual void update() override {
        std::cout<<"Ducking!\n";
        ++bombTimer;
        if(bombTimer == MAX_CHARGE){
            //bombExplode();
        }
        
    }

    int bombTimer;
    int MAX_CHARGE = 100;
};

class StandingState : public EntityState {
 public:
    StandingState() { enter(); }
    ~StandingState() { exit(); }
    
    virtual void enter() {
        //setgraphics IMAGE_STANDING
    }
    virtual void exit(){
        //cleanup
    }

    virtual void handleInput(int input) override {
        if(input == PRESS_DOWN){
            entity_->transitionTo(new DuckingState());
        }
    }


    virtual void update() override {
        std::cout<<"Standing!\n";

    }
};

void DuckingState::handleInput(int input)  {
        if(input == RELEASE_DOWN){
            bombTimer = 0;
            entity_->transitionTo(new StandingState());
        }
    }



int main()
{
    Entity entity(new StandingState());

    while(1)
    {
        int i;
        std::cout<<"Input: ";
        std::cin >> i; 
        entity.handleInput(i);
        entity.update();
        std::cin.get();
        //system("clear");
    }

    //implement some sort of queue system also to queue commands
    return 0;

}