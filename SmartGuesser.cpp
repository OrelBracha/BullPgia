#include <iostream>
#include <string>
#include "SmartGuesser.hpp"
#include <math.h>
#include <algorithm>

using std::string, std::to_string, std::unordered_set;

string bullpgia::SmartGuesser::guess() {
        string answer = "";
		if(this->pgia<this->length)
		{
			for (int i=0;i<length;i++)
			{
				answer+= to_string(guesserhelper);
			}

		}
		else
		{
			if(appearOnce)
			{
				vec = getcombi(solution);
				appearOnce= false;
			}
		 answer = vec[guesserhelper];
		 guesserhelper = guesserhelper+1;
		}
		 turns++;
		 return answer;

}

bullpgia::SmartGuesser(){
        for (size_t i = 0; i < 10; i++) {
                for (size_t j = 0; j < length; j++) {
                        this->choosedString[i]+=to_string(i);
                }
        }
       
}

void bullpgia::SmartGuesser::startNewGame(uint length) 
{
        this->pgia = 0;
		this->bull = 0;
		this->turns = 0;
		this->digitExist = false;
		this->appearOnce = true;
		this->choosedString = "";
	    this->guesserhelper = 0;
		this->length = length;
		this->length=length;

};

void bullpgia::SmartGuesser::learn(string results)
{
        string delimiter = ",";
        string bull = results.substr(0, results.find(delimiter));
        string pgia = results.substr(results.find(delimiter)+1);

        int PgiaNum = stoi(pgia);
        int BullNum = stoi(bull);

        

}

