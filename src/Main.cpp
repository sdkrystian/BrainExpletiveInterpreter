#include <iostream>
#include <string>
#include "Parser\Parser.h"

void main()
{
   std::string input;
   std::cin >> input;
   brainexpletive::ExecuteBrainExpletive(input.c_str(), input.length());
   std::cout << std::endl;
   std::cin.ignore();
}