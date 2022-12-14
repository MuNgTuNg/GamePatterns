#include <iostream>

class IBookParser{
 public:
   virtual void getNumPages() = 0;
   virtual void exserpt() =0;
};

class BookParser : public IBookParser{
    friend class BookParserProxy;
 private:
    BookParser(std::string book) {
        std::cout << "Expensive operation\n";
        std::cout <<"Parser instantiated from proxy\n";
    }
    virtual void getNumPages() override {
        std::cout<<"getNumPages\n";
    }
    virtual void exserpt() override {
        std::cout<<"Cheap operation\n" << exserptString << "\n";

    }

    std::string exserptString = "hello i am an excerpt";
};

class BookParserProxy : public IBookParser{ //object essentially just delegates to other object, 
                                            //controls access to underlying object

 public:

    BookParserProxy(std::string s) : book(s) {
        std::cout<<"Proxy instantiated\n";
    }

    virtual void exserpt() override {
        if(bookParser == nullptr){
           std::cout<<"excerpt requires instantiation\n";
        }
        else{
            bookParser->exserpt();
        }
        
    }

    virtual void getNumPages() override {

        if(bookParser == nullptr) { 
            bookParser = new BookParser(book);
        }
        return bookParser->getNumPages();
    }

 private:
    std::string book;
    BookParser* bookParser = nullptr;
};

int main()
{
    std::string book = "This is a book";
    BookParserProxy bookParser(book); //controls instantiation of the underlying parser
    bookParser.exserpt();
    bookParser.getNumPages(); 
    bookParser.exserpt();


    return 0;
}