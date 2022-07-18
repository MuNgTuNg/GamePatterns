#include <vector>
#include <iostream>
#include <map>

class IObserver{
 public:
   virtual void notify() = 0;
   int index;

   const IObservable* observable;

};

class IObservable{
 public:
    

    void addObserver(IObserver* observer){
        observers.push_back(observer);
        observer->index = observers.size();
    }
    void removeObserver(IObserver* observer){
        observers.erase(observers.begin() + observer->index);
    }

    void notifyAll() {
        for(int i = 0; i <observers.size(); ++i){
            observers[i]->notify();
        }
    }

 private: 
    std::vector<IObserver*> observers{};


};


class WeatherStation{

};

class TempDisplay{


};