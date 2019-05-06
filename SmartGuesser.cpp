#include "SmartGuesser.hpp"
#include "calculate.hpp"
#include <unordered_set>
#include <math.h>
#include <iostream>
#define NUM_OF_DIGITS 10

using std::string, std::to_string, std::unordered_set;
void SmartGuesser::allPermutations(){

    uint options = pow(NUM_OF_DIGITS,this->length);
    for(int i=0 ; i < options ; ++i)
    {
        string permutations = to_string(i);
        while(permutations.length()<this->length)
        {
            permutations=to_string(0)+permutations;
        }

        _set.insert(permutations);
    }
}

string SmartGuesser::guess()
{

	return this->Guess;
}


void SmartGuesser::startNewGame(uint Length) {
    _set.clear();
   this->length=Length;
   this->allPermutations();
   this->Guess = *_set.begin();
}

void SmartGuesser::learn(string answer) {
	char bulls= answer.at(0);
	unordered_set<string> outFromGroup;
	for ( auto it = _set.begin(); it != _set.end(); it++)
	{
        string result = bullpgia::calculateBullAndPgia(*it,Guess);

		if (result.at(0)!=bulls)
            outFromGroup.insert(*it);
	}

	//removes from myset
	for ( auto it = outFromGroup.begin(); it != outFromGroup.end(); it++)
    {
        _set.erase(*it);
    }

    outFromGroup.clear();
		this->Guess= *_set.begin();
}
