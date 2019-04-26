#include "Guesser.hpp"
#include <string>
using namespace std;
#define NUM_OF_DIGITS 10

class Chooser   // Inheritance
{
   char[] key_chooser;
   bool[] isExist = new bool[NUM_OF_DIGITS];
   string choose (uint length);
   void generatePassword(char[] key_chooser);







}