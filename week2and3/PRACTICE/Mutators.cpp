#include <iostream>
#include <string>

class Human
{
    std::string first;
    std::string last;
public:
    void setFirstName(std::string _first){this->first = _first;} // _first'ti, objeye pass edilen argumant yoluyla getirip, O objenin(THIS) privatetaki first memberine, maindeki  pass edilen argumantin adiyorum.
    void setLastName(std::string _last){this->last = _last;}

    std::string printFullNameMethod(){ return first + " " + last;}//this is a method that returns the full name of the object.
};

int main(){

    Human h1;
    h1.setFirstName("Odinson");
    h1.setLastName("Thor");

    std::cout << h1.printFullNameMethod() << std::endl;

    return 0;
}