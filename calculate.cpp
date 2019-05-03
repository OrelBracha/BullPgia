#include <iostream>
#include "calculate.hpp"
#include <string>
#include <cmath>
#define ZERO_TO_NINE 10


using namespace std;

namespace bullpgia
{

bool isExist(bool digits[ZERO_TO_NINE] , int num )
{
  if(digits[num] == true)
    return true ;
  else
    return false ;
}

int numOfChars(string str , char ch)
{
    int counter = 0 ;
    for (int i = 0; i < str.length() ; ++i)
    {
        if(str[i] == ch)
            counter++ ;
    }
    return counter ;
}


const string calculateBullAndPgia(const std::string choice, const std::string guess)
{
  int bull = 0 ;
  int pgia = 0 ;
  bool digits[ZERO_TO_NINE] ;
  for(int i = 0 ; i < choice.length() ; i++)
  {
    digits[(int) choice[i]] = true ;
  }


  for(int i = 0 ; i < choice.length() ; i++)
  {
    if(choice[i]== guess[i])
    {
      bull++ ;
    }
    else
    {
        pgia += min(numOfChars(choice , choice[i]) , numOfChars(guess , choice[i])) ;
    }
  }


  const string result =to_string(bull)+","+to_string(pgia)   ;
  cout<<result<<endl ;
  return result ;
}
}