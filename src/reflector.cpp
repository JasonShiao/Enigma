#include <iostream>
#include <string>
#include <ctype.h>

#include "reflector.h"

Reflector::Reflector(std::string reflector_table)
{
  try {
    if(reflector_table.length() != 26) {
      throw 1;
    }

    for (auto i = 0; i < 26; i++) {
      this->_reflector_table[i] = reflector_table[i];
    }
  }
  catch (int e) {
    std::cerr << "An exception occurred. Invalid initialize table size." << std::endl;
    throw;
  }
}

char Reflector::wire(char input)
{
  try {
    if(toupper(input) < 'A' || toupper(input) > 'Z') {
      throw 1;
    }
    return this->_reflector_table[toupper(input) - 'A'];
  }
  catch (int e) {
    std::cerr << "An exception occurred. Invalid input key." << std::endl;
    throw;
  }

}

void Reflector::print(void)
{
  std::cout << "------------------------------------------------------" << std::endl;
  std::cout << "| ";std::cout.width(21); std::cout << std::right << "Reflector: ";
  std::cout.width(30); std::cout << std::left << _reflector_table; std::cout << "|" << std::endl;
  std::cout << "------------------------------------------------------" << std::endl;
  std::cout << std::endl;
}
