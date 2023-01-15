#include <iostream>

#include "lever.h"

Lever::Lever(Rotor *first_rotor, Rotor *second_rotor)
{
  try {
    if(second_rotor == NULL) {
      throw 1;
    }

    if (first_rotor == NULL) { // first lever, only contact with the rachet of the first rotor
      this->_is_first_lever = true;
    } else {
      this->_is_first_lever = false;
    }
    this->_first_rotor = first_rotor;
    this->_second_rotor = second_rotor;
  }
  catch(int e) {
    std::cerr << "An exception occurred. second_rotor can't be empty or NULL." << std::endl;
    throw;
  }
}

/**
 * @brief Check if the lever is engaged with rotor (about to push the rotor)
 * @return true engaged
 *         false not engaged (idle)
 */
bool Lever::checkEngaged()
{
  bool engaged = false;
  try {
    if (_second_rotor == NULL || (_first_rotor == NULL && !_is_first_lever)) {
      throw 1;
    }

    if (_is_first_lever) {
      engaged = true;
    } else { // normal lever
      engaged = _first_rotor->getCurrentLetter() == _first_rotor->getNotchLetter();
    }
  }
  catch (int e) {
    std::cerr << "An exception occurred. Not initialized correctly." << std::endl;
    throw;
  }
  return engaged;
}

Rotor* Lever::getFirstRotor() {
  return _first_rotor;
}

Rotor* Lever::getSecondRotor() {
  return _second_rotor;
}
