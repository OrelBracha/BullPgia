#pragma once
#include "Guesser.hpp"
#include "calculate.hpp"
#include <unordered_set>
#include <math.h>
#include <iostream>


/**
 * ConstantGuesser is a guesser that always guesses the same string.
 */
class SmartGuesser: public bullpgia::Guesser {
	private:
		std::string lastGuess="";
		std::unordered_set<std::string> mySet;
		void anotherGuesser();
		void allPermutations();
		void createString(std::string str); 
		int indexOf=0;
		std::string temporary = "";
	public:
		std::string guess() override;
		void startNewGame(uint Length) override;
		void learn(std::string res) override;
};

//std::string numToGuess(int num, uint length);
