
#include <iostream>
#include <ctype.h>
#include <cassert>
#include <string>

#include "rotor.h"

Rotor::Rotor(std::string rotor_name, char init_pos, char notch_pos, std::string forward_table)
{
  try {
    if (toupper(init_pos) < 'A' && toupper(init_pos) > 'Z') {
        throw 1;
    }
    if (toupper(notch_pos) < 'A' && toupper(notch_pos) > 'Z') {
        throw 1;
    }
    if (forward_table.length() != 26) {
        throw 1;
    }

    this->_rotor_name.swap(rotor_name);
    this->_current_letter = toupper(init_pos);
    this->_notch_letter = toupper(notch_pos);
    for (auto i = 0; i < 26; i++) {
      this->_forward_table[i] = forward_table[i];
      this->_backward_table[forward_table[i] - 'A'] = i + 'A';
    }
  }
  catch (int e) {
    std::cout << "An exception occurred. Invalid argument." << std::endl;
    throw;
  }
}

char Rotor::forwardWire(char input)
{
  input = toupper(input);

  try {
    if (input < 'A' || input > 'Z') {
      throw 1;
    }

    char local_pos, abs_pos;
    //std::cout << "Current pos: " << this->_current_letter << std::endl;
    local_pos = this->_forward_table[(input - 'A' + this->_current_letter - 'A')%26];
    abs_pos = ((local_pos - this->_current_letter) >= 0?(local_pos - this->_current_letter + 'A'):(local_pos + 26 - this->_current_letter + 'A'));
    return abs_pos;
  }
  catch (int e) {
    std::cout << "An exception occurred. Invalid input key." << std::endl;
    throw;
  }
}

char Rotor::backwardWire(char input)
{
  input = toupper(input);

  try {
    if (input < 'A' || input > 'Z') {
      throw 1;
    }

    char local_pos, abs_pos;
    local_pos = this->_backward_table[(input - 'A' + this->_current_letter - 'A')%26];
    abs_pos = ((local_pos - this->_current_letter) >= 0?(local_pos - this->_current_letter + 'A'):(local_pos + 26 - this->_current_letter + 'A'));
    return abs_pos;
  }
  catch (int e) {
    std::cout << "An exception occurred. Invalid input key." << std::endl;
    throw;
  }
}

void Rotor::ratchetRotate()
{
  assert(this->_current_letter >= 'A' && this->_current_letter <= 'Z');

  if(this->_current_letter == 'Z') {
    this->_current_letter = 'A';
  } else {
    this->_current_letter++;
  }
}

void Rotor::notchRotate()
{
  assert(this->_current_letter >= 'A' && this->_current_letter <= 'Z');

  if (this->_current_letter == this->_notch_letter) { // lever engaged
    if (this->_current_letter == 'Z') {
      this->_current_letter = 'A';
    } else {
      this->_current_letter++;
    }
  } else {
    // lever not engaged, no push force
  }
}

bool Rotor::setCurrentLetter(char letter)
{
  // validate letter
  letter = toupper(letter);

  if(letter >= 'A' && letter <= 'Z'){
    this->_current_letter = letter;
  } else {
    return false;
  }

  return true;
}

char Rotor::getCurrentLetter()
{
  return this->_current_letter;
}

char Rotor::getNotchLetter()
{
  return this->_notch_letter;
}


void Rotor::print()
{
  std::cout << "------------------------------------------------------" << std::endl;
  std::cout << "| ";std::cout.width(21); std::cout << std::right << "Rotor Name: ";
  std::cout.width(30); std::cout << std::left << this->_rotor_name; std::cout << "|" << std::endl;
  std::cout << "| ";std::cout.width(21); std::cout << std::right << "Current Letter: ";
  std::cout.width(30); std::cout << std::left << this->_current_letter; std::cout << "|" << std::endl;
  std::cout << "| ";std::cout.width(21); std::cout << std::right << "Notch Pos: ";
  std::cout.width(30); std::cout << std::left << this->_notch_letter; std::cout << "|" << std::endl;
  std::cout << "| ";std::cout.width(21); std::cout << std::right << "Rotor internal wire: ";
  std::cout.width(30); std::cout << std::left << this->_forward_table; std::cout << "|" << std::endl;
  std::cout << "------------------------------------------------------" << std::endl;
  std::cout << std::endl;
  return;
}
