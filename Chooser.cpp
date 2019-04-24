#include <iostream>
#include <stdlib.h>
#include "Chooser.hpp"
using namespace std;

class Chooser
{




    void generatePassword()
    {
        string password = "";
       
        cout<<"Please enter password : "<< endl
        cin>> password >> endl ; 
        
        for(int i = 0 ; i<sizeof(password)/sizeof(*password) ; i++)
        {
            Chooser::key_chooser[i] = password[i] ;
            Chooser::isExist[ (int) password[i]] = true ;   
        }
    }

}