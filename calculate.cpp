#include <iostream>
#include "Guesser.hpp"
#include "Chooser.hpp"
using namespace ariel;
using namespace std;


void calculateBullAndPgia()
{
    Chooser chooser;
    Guesser guesser;
    int BullCount=0;
    int PgiaCount=0;
    if(guesser->size == sizeof(chooser->key_chooser)/sizeof(*(chooser->key_chooser)))
    {
        for(int i=0;i<guesser->size;i++)
        {
            if(isExist[guesser->key_Guesser[i]] == true) // PGIA
            {
                if(chooser->key_chooser[i] == guesser->key_Guesser[i])
                BullCount++;
                else
                {
                PgiaCount++;
                }
            }
            
        }
    }
    

}


