#include "SmartGuesser.hpp"
#include "calculate.hpp"
#include <unordered_set>
#include <math.h>
#include <iostream>
#include <bits/stdc++.h>

using std::string, std::to_string, std::unordered_set;


string SmartGuesser::guess() 
{

	return this->guessing;
}


void SmartGuesser::startNewGame(uint Length) {
	guessing="";
    mySet.clear();
	temporary="";
	indexOf=0;
   this->length=Length;
  for(int i=0;i<this->length;i++)
  guessing+='0';
  
}

void SmartGuesser::learn(string res) {
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
	
	char bulls= res.at(0);
	
	unordered_set<string> ErasedSet;
	for ( auto it = mySet.begin(); it != mySet.end(); it++){
        string response = bullpgia::calculateBullAndPgia(*it,guessing);
			
		if (response.at(0)!=bulls)
			ErasedSet.insert(*it);	
	}

	
	for ( auto it = ErasedSet.begin(); it != ErasedSet.end(); it++)
		mySet.erase(*it);
		
		this->guessing= *mySet.begin();
	}
}


void SmartGuesser::anotherGuesser(){
	for(int i=0;i<this->length;i++){
	
	guessing.replace(i,i+1,to_string(indexOf));
	
	}
}

void SmartGuesser::createString(string str) 
{ 
    
    sort(str.begin(), str.end()); 
  
   
    do { 
      mySet.insert(str);
	  
    } while (std::next_permutation(str.begin(), str.end())); 
} 


