#pragma once

#include "rabbit_behaviour.hpp"



class Rabbit
{
 public:
    //constructor can set these params, as could a function at runtime
    //or with setter functions
    Rabbit(
        const std::string& name,
        int binkyMode, 
        int chewMode, 
        int pooMode, 
        int fightMode);
    ~Rabbit();

    //abstracted method calls
    void chew() {
        chewBehaviour->execute();
    }
    void poo() {
        pooBehaviour->execute();
    }
    void binky() {
        binkyBehaviour->execute();
    }

    //slightly more complicated logic, adding a trait then 
    //doing something based on said trait
    void fight(Rabbit& opponent){
        
        fightBehaviour->execute(opponent.getFightPower(), fightPower);

    }
    void setFightPower(int i) {
        fightPower = i;
        fightBehaviour->addTrait(fightPower); //good fighting/bad fighting traits
    }
    int getFightPower() { return fightPower;}


 private:

    //interfaces for behaviours
    IBinkyBehaviour*    binkyBehaviour;
    IChewBehaviour*     chewBehaviour;
    IPooBehaviour*      pooBehaviour;
    IFightBehaviour*    fightBehaviour;
    

    //other members
    std::string _name;
    int fightPower;
    
    
};


Rabbit::Rabbit(const std::string& name, int binkyMode, int chewMode, int pooMode, int fightMode = BASE_FIGHT) : _name(name) {
     
    std::cout<<"I've just been born. My name is " << _name << "\n";

    //binkyMode
    switch(binkyMode){
        case FAT_BINKY:
          binkyBehaviour = new FatBinky();
          break;

        case BAD_BINKY:
          binkyBehaviour = new BadBinky();
          break;

        case NO_BINKY:
          binkyBehaviour = new NoBinky();
          break;
    }

    //chew mode
    switch(chewMode){
        case FAT_CHEW:
          chewBehaviour = new FatChew();
          break;

        case BAD_CHEW:
          chewBehaviour = new BadChew();
          break;

        case NO_CHEW:
          chewBehaviour = new NoChew();
          break;
    }

    //poo mode
    switch(pooMode){
        case FAT_POO:
          pooBehaviour = new FatPoo();
          break;

        case BAD_POO:
          pooBehaviour = new BadPoo();
          break;

        case NO_POO:
          pooBehaviour = new NoPoo();
          break;
    }

    switch(fightMode){
        case GOOD_FIGHT:
          fightBehaviour = new GoodFight();
          break;

        case BAD_FIGHT:
          fightBehaviour = new BadFight();
          break;

        case BASE_FIGHT:
        default:
          fightBehaviour = new BaseFight();
          break;
    }

}


Rabbit::~Rabbit() 
{
    delete binkyBehaviour;
    delete chewBehaviour;
    delete pooBehaviour;
    delete fightBehaviour;
    
    binkyBehaviour = nullptr;
    chewBehaviour = nullptr;
    pooBehaviour = nullptr;
    fightBehaviour = nullptr;
}