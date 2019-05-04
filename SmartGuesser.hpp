#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"
#include <unordered_set>


namespace bullpgia
{
class SmartGuesser: public bullpgia::Guesser {
	private:
		bool digitExist = false;
		std::string choosedString = "";
    uint bull=0;
    uint pgia=0;
    int turns=0;
    bool appearOnce=true;
    int guesserhelper=0;


	public:
		SmartGuesser()
    {
    }
    ~SmartGuesser()
    {
    }
    std::string guess() override;
		void startNewGame(uint theLength) override;
		void learn(std::string response) override;
};
};
//std::string numToGuess(int num, uint length);