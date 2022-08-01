#include <iostream>
#include <string>



//not sure if i've done this wrong but it seems extremely messy. I'm sure there's better ways of doing it

class IContent{
 public:
    IContent(std::string s, int num, char pic) : 
    m_String(s), 
    m_PageNum(num), 
    m_Pic(pic) 
    {}
    //templated method is not as clear
   // std::string getRef(std::string) {return m_String; }

    //read only
    const std::string& getStringRefConst() const { return m_String; }
    const int& getPageNumRefConst() const { return m_PageNum; }
    const char& getPictureRefConst() const { return m_Pic; }

    //return value by reference or pointer if we want to change it
    std::string& getStringRef() { return m_String; }
    int& getPageNumRef() { return m_PageNum; }
    char& getPictureRef() { return m_Pic; }

 private:
    std::string m_String;
    int m_PageNum;
    char m_Pic;
    
};

class Book : public IContent
{
 public:
    Book(std::string title, int pages, char picture) : IContent(title,pages,picture) {}
};

class IDisplay{
 public:

    IDisplay(IContent* iCont) : iContent(iCont) {}

    void displayAll() {
        displayText();
        displayNum();
        displayPicture();
        std::cout <<"\n";
    }
  
    //implemented by concrete classes
    virtual std::string displayText() = 0;
    virtual std::string displayNum() = 0;
    virtual std::string displayPicture() = 0;

    //im sure there's some sort of templated way of dealing with this that i wont do right now (seems like it's less clear, not appropriate)
   // template <typename T>
   // T getCopy() {return iContent->getRef(T);}

    std::string getStringCopy() {return iContent->getStringRef();}
    void changeString(const std::string& s) {iContent->getStringRef() = s;}
    std::string getStringReadOnly() const {return iContent->getStringRefConst();}

    int getPageNumCopy() {return iContent->getPageNumRef();}
    void changePageNum(const int& i) {iContent->getPageNumRef() = i;}
    int getPageNumReadOnly() const {return iContent->getPageNumRefConst();}

    char getPictureCopy() {return iContent->getPictureRef();}
    void changePictureCopy(const char& c) {iContent->getPictureRef() = c;}
    char getPictureReadOnly() const {return iContent->getPictureRefConst();}

    void operator<<(IDisplay*);
 private:
    IContent* iContent;
    

};

 std::ostream& operator<<(std::ostream& os, IDisplay& dis){
    os << dis.displayText()
       <<dis.displayNum()
       <<dis.displayPicture();
    os <<"\n";
    return os;
}

class PhoneDisplay : public IDisplay
{
 public:
    PhoneDisplay(IContent* iCont) : IDisplay(iCont) {} 

    std::string displayText() override{
        return "PhoneDisplay text output\n" + getStringReadOnly() + "\n";
    }
    std::string displayNum() override{
        return "PhoneDisplay Num output\n" + std::to_string(getPageNumReadOnly()) + "\n";
    }
    std::string displayPicture() override{
        return "PhoneDisplay picture output\n" + std::to_string(getPictureReadOnly()) + "\n";
    }

};
class TVDisplay : public IDisplay
{
 public:
        TVDisplay(IContent* iCont) : IDisplay(iCont) {}  

    std::string displayText() override{
        return "TVDisplay text output\n" + getStringReadOnly() + "\n";
    }
    std::string displayNum() override{
        return "TVDisplay Num output\n" + std::to_string(getPageNumReadOnly()) + "\n";
    }
    std::string displayPicture() override{
        return "TVDisplay picture output\n" + std::to_string(getPictureReadOnly()) + "\n";
    }
};


int main(){

    IContent bible("The Good Book", 100, 'f');
    TVDisplay tv(&bible);
    PhoneDisplay phone(&bible);
    //tv.displayAll();
   // phone.displayAll();
    std::cout << tv << phone;
    return 0;
}
