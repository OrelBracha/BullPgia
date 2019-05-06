#include "SmartGuesser.hpp"
#include "calculate.hpp"
#include <unordered_set>
#include <math.h>
#include <iostream>
#include <bits/stdc++.h>

using std::string, std::to_string, std::unordered_set;

void SmartGuesser::startNewGame(uint Length) {
  for(int i=0;i<this->length;i++)
  lastGuess+='0';
	temporary="";
	indexOf=0;
   this->length=Length;
	lastGuess="";
    mySet.clear();

  
}

void SmartGuesser::createString(string str) 
{ 
    
    sort(str.begin(), str.end()); 
  
   
    do { 
      mySet.insert(str);
	  
    } while (std::next_permutation(str.begin(), str.end())); 
} 

void SmartGuesser::anotherGuesser()
{
	for(int i=0;i<this->length;i++)
	{
	
	lastGuess.replace(i,i+1,to_string(indexOf));
	
	}
}




string SmartGuesser::guess() 
{

	return this->lastGuess;
}




void SmartGuesser::learn(string res) 
{
  unordered_set<string> toRemove;
	//if number in mySet is not match to the res -> insert it to the remove list
	for ( auto it = mySet.begin(); it != mySet.end(); ++it ){
		if (res.compare(bullpgia::calculateBullAndPgia(*it, lastGuess))!=0)
			toRemove.insert(*it);
	}

	//removes from mySet be toRemve list
	for ( auto it = toRemove.begin(); it != toRemove.end(); ++it )
		mySet.erase(*it);	
}





