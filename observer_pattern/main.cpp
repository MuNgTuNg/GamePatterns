#include <vector>
#include <iostream>
#include <map>
#include <memory>
#include <chrono>

//use of raw pointers is less than ideal but i prefer to currently as it forces you to become more conciencious when allocating and 
//deallocating memory. That and i am a control freak and wish to overlook all aspects of the programme lol.


const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

///////////////////////////////
//ABSTRACTS

class IObservable;

class IObserver{
 public:
   virtual void notify() = 0;
   int index;

   const IObservable* observable;

};


class IObservable{
 public:
    virtual void notify() = 0;

    void addObserver(IObserver* observer){
        observers.push_back(observer);
        observer->index = observers.size();
    }
    void removeObserver(IObserver* observer){
        observers[(observer->index -1)] =nullptr; //think this is correct
        observers.erase(observers.begin() + (observer->index -1));
    }

    void notifyAll() {
        for(int i = 0; i <observers.size(); ++i){
            observers[i]->notify();
        }
    }

    void removeAll() {
        for(int i = 0; i <observers.size(); ++i){
            observers[i] = nullptr;
        }
        observers.erase(observers.begin(), observers.end());
    }

 private: 
    std::vector<IObserver*> observers{};


};



///////////////////////////////
//CONCRETE 
class WeatherStation : public IObservable {
    
  public:
    virtual void notify() { notifyAll();}
    void testTemperature() { 
        temperature = 1+(rand() % 100);
    }
    int getTemperature() const { return temperature; }
  private:
    int temperature;
};

class TempDisplay : public IObserver {
  public:

   void notify() {
    int tempForDisplay = weatherStation->getTemperature();
    std::cout<< "TempDisplay notified!\n";
    std::cout<<"Temperature at "<< currentDateTime() << " is: " << tempForDisplay << "\n\n"; 
   }
   


   TempDisplay(const WeatherStation* ws) : weatherStation(ws) { }
    ~TempDisplay() { weatherStation = nullptr; }

   
  private:
    const WeatherStation* weatherStation;
   


};


class TempAudio : public IObserver {
  public:

   void  notify() {
    int tempForAudio = weatherStation->getTemperature();
    std::cout<< "TempAudio notified!\n *plays audio file*\n\n";
   }

   TempAudio(const WeatherStation* ws) :weatherStation(ws){}
   ~TempAudio() { weatherStation = nullptr; }
  private:
   const WeatherStation* weatherStation;
};

class TempSpiritual : public IObserver {
  public:

   void notify() {
    std::cout<<"TempSpiritual notified!\nYou have become enlightened :)\n\n";
   }

   TempSpiritual(const WeatherStation* ws) :weatherStation(ws){}
   ~TempSpiritual() { weatherStation = nullptr; }
  private:
    const WeatherStation* weatherStation;

};


int main() 
{
    srand(time(0));
    WeatherStation weatherStation;

    TempAudio tempAudio(&weatherStation);
    TempSpiritual tempSpiritual(&weatherStation);
    TempDisplay tempDisplay(&weatherStation);
    
    weatherStation.addObserver(&tempAudio);
    weatherStation.addObserver(&tempSpiritual);
    weatherStation.addObserver(&tempDisplay);

   //weatherStation.removeAll();
    weatherStation.notify();
    
    return 0;
}