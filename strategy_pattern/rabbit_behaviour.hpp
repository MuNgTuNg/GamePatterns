#pragma once
#include <iostream>
#include "rabbit.hpp"

enum{
    FAT_BINKY,
    FAT_CHEW,
    FAT_POO,
    BAD_BINKY,
    BAD_CHEW,
    BAD_POO,
    NO_POO,
    NO_CHEW,
    NO_BINKY,
    GOOD_FIGHT,
    BAD_FIGHT,
    BASE_FIGHT
};


class IFightBehaviour{
 public:
    virtual void addTrait(int &fightPower) = 0;
    virtual void execute(int opponentFightPower, int fightPower) = 0;
};
class BaseFight : public IFightBehaviour
{
     virtual void addTrait(int& fightPower){
        std::cout<<"Im neutral at fighting\n";
     }
     void execute(int opponentFightPower, int fightPower){
        if(opponentFightPower < fightPower ){
            std::cout<<"i have won this fight\n";
        }else {
            std::cout<<"i have been killed\n";
        }
    }
};
class GoodFight : public BaseFight{
 public:
    void addTrait(int& fightPower) override{
        std::cout<<"I am good at fighting\n";
        fightPower += 10;
    }
   

};
class BadFight : public BaseFight{
 public:
    void addTrait(int& fightPower) override{
        std::cout<<"I am bad at fighting\n";
        fightPower -= 10;
    }

};



class IBinkyBehaviour{
 public:
    virtual void execute() =0;

};
class FatBinky : public IBinkyBehaviour{
 public:
    void execute() override {
        std::cout<<"Fat Binky\n";
    }

};
class BadBinky : public IBinkyBehaviour{
 public:
    void execute() override {
        std::cout<<"Bad Binky\n";
    }
};
class NoBinky : public IBinkyBehaviour{
 public:
    void execute() override {
        std::cout<<"I cannot Binky\n";
    }
};



class IChewBehaviour{
 public:
    virtual void execute() =0;
};
class FatChew : public IChewBehaviour{
 public:
    void execute() override {
        std::cout<<"Fat Chew\n";
    }
};
class BadChew : public IChewBehaviour{
 public:
    void execute() override {
        std::cout<<"Bad Chew\n";
    }
};
class NoChew : public IChewBehaviour{
 public:
    void execute() override {
        std::cout<<"i cannot chew as i have no teeth\n";
    }
};




class IPooBehaviour{
 public:
    virtual void execute() =0;

};
class FatPoo : public IPooBehaviour{
 public:
    void execute() override {
        std::cout<<"Fat poo\n";
    }
};
class BadPoo : public IPooBehaviour{
 public:
    void execute() override {
        std::cout<<"Bad Poo\n";
    }
};
class NoPoo : public IPooBehaviour{
 public:
    void execute() override {
        std::cout<<"GI stasis, game over\n";
    }
};

