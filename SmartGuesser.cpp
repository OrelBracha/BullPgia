#include "SmartGuesser.hpp"
#include "calculate.hpp"
#include <unordered_set>
#include <math.h>
#include <iostream>
#include <bits/stdc++.h>

using std::string, std::to_string, std::unordered_set;

void SmartGuesser::startNewGame(uint Length) {
 lastGuess="";
    mySet.clear();//clear our set if it already full
	temporary="";
	indexOf=0;
   this->length=Length;
  for(int i=0;i<this->length;i++)
  lastGuess+='0';

  
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
  	if(temporary.length()<this->length){
		int sum = (res.at(0)-'0');
		for(int i=0;i<sum;i++)
			temporary+=to_string(indexOf);
		indexOf++;
		if(indexOf>9)
			indexOf=0;
		anotherGuesser();
	}
	else
	{
		if(mySet.empty())
			createString(temporary);
	
	char bulls= res.at(0);//checks how many bulls we have
	unordered_set<string> toRemove;
	//if number in mySet is not match to the res -> insert it to the remove list
	for ( auto it = mySet.begin(); it != mySet.end(); ++it ){
		  string result = bullpgia::calculateBullAndPgia(*it,lastGuess);
			
		if (result.at(0)!=bulls)
			toRemove.insert(*it);
	}

	//removes from mySet be toRemve list
	for ( auto it = toRemove.begin(); it != toRemove.end(); ++it )
		mySet.erase(*it);	


		
		this->lastGuess= *mySet.begin();




}






}