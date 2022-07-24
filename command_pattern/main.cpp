#include "input.h"
#include "Entities.h"
int main()
{
    shb::Cat cat;
    shb::Dog dog;
    shb::Carrot* carrot = new shb::Carrot;
    shb::InputHandler inputHandler;
    
while(true){

    int i; 
    std::cout<< "Enter command: ";
    std::cin >> i;

    shb::Command* command = inputHandler.handleInput(i);
    if(command){
        command->execute(cat);
        command->execute(dog);
        command->execute(*carrot);
    }
    std::this_thread::sleep_for(std::chrono::seconds(1));
    system("clear");
    
   

}
    delete carrot;
    carrot = nullptr;
    return 0;
}
