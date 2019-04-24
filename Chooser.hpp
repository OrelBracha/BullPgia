#include "Guesser.hpp"
using namespace std;
#define NUM_OF_DIGITS 10

class Chooser:public Guesser   // Inheritance
{
   char[] key_chooser;
   bool[] isExist = new bool[NUM_OF_DIGITS];

   void generatePassword(char[] key_chooser);







}