#include <iostream>
#include <string>
#include <cassert>
// make a youtube channel struct. and then implement a operator overloading function to print the name and the subs.

struct YoutubeChannel
{
    int subscribers;
    std::string name;

    // constructor
    // YoutubeChannel(std::string _name, int subs) : name{_name}, subscribers { subs }
    YoutubeChannel(std::string _name, int subs){
        name = _name;
        subscribers = subs;
    }
};
// parameter of ostream(to access the cout)
std::ostream& operator<<(std::ostream &_cout, YoutubeChannel &_YoutubeChannel)
{
    _cout << "Name: " << _YoutubeChannel.name << std::endl;
    _cout << "Subscribers: " << _YoutubeChannel.subscribers << std::endl;
    return _cout;
}

int main()
{
    // This is where the constructor becomes useful. Initilized using the constructor.
    YoutubeChannel yt1 = YoutubeChannel("Yaq8bi", 999000);
    YoutubeChannel yt2 = YoutubeChannel("BeautyCode", 15000);

    std::cout << yt1 << yt2 << std::endl;
    // operator<<(std::cout, yt1);

    return 0;
}