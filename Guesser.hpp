#pragma once
#include <iostream>
#include <string>
using namespace std;

namespace bullpgia
{


class Guesser
{
    public:
    uint length;
    //char[] key_Guesser;//
    virtual std::string guess();
    virtual void startNewGame(uint size);
    virtual void learn(std::string chars);


};


}