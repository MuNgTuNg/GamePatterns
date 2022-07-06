#include <iostream>
#include "rabbit.hpp"



int main(){


    Rabbit fatRabbit("Fatty",FAT_BINKY,FAT_CHEW,FAT_POO, BASE_FIGHT);
    fatRabbit.chew();
    fatRabbit.binky();
    fatRabbit.poo();
    fatRabbit.setFightPower(9);
    std::cout<< "\n";


    Rabbit badRabbit("Noughty",BAD_BINKY,BAD_CHEW,NO_POO, BAD_FIGHT);
    badRabbit.binky();
    badRabbit.chew();
    badRabbit.poo();
    badRabbit.setFightPower(20);
    badRabbit.fight(fatRabbit);
    std::cout<< "\n";


    Rabbit fatBadRabbit("FatBad",FAT_BINKY,NO_CHEW,FAT_POO,GOOD_FIGHT);
    fatBadRabbit.binky();
    fatBadRabbit.chew();
    fatBadRabbit.poo();
    fatBadRabbit.setFightPower(30);
    fatBadRabbit.fight(badRabbit);
    std::cout<< "\n";


    return 0;
}