#include <iostream>
//#include <array>
#include <ctype.h>
#include <cassert>
#include <list>

#include "enigma.h"

#define debug_switch 0

#if debug_switch
#define DEBUG(x) do { std::cerr << x; } while (0)
#else
#define DEBUG(x)
#endif


Enigma::Enigma()
{
    
}

bool Enigma::addRotor(std::string rotor_name, char init_pos, char notch_pos, std::string forward_table)
{
  // setting value check

  rotorSet.push_back(new Rotor(rotor_name, init_pos, notch_pos, forward_table));
  // Add a lever for the newly added rotor
  if (rotorSet.size() == 1) { // first rotor
    leverSet.push_back(new Lever(NULL, *(rotorSet.end()-1))); 
  } else {
    leverSet.push_back(new Lever(*(rotorSet.end()-2), *(rotorSet.end()-1)));
  }

  return true;
}

bool Enigma::setRotorPos(size_t rotor_idx, char pos)
{
  if(rotor_idx < rotorSet.size()){
    if(true != (rotorSet[rotor_idx])->setCurrentLetter(pos)) {
      return false;
    }
  } else {
    return false;
  }

  return true;
}

char Enigma::pressKey(char input_key)
{
  DEBUG("Input: " << input_key << std::endl);
  std::list<Rotor*> engaged_rotor_list;

  /* -------------- Mechanic parts ------------------ */
  // A Key is pressed
  for (auto lever_it = leverSet.begin(); lever_it != leverSet.end(); lever_it++) {
    if ((*lever_it)->checkEngaged()) {
      if ((*lever_it)->getFirstRotor() != NULL) {
        engaged_rotor_list.push_back((*lever_it)->getFirstRotor());
      }
      if ((*lever_it)->getSecondRotor() != NULL) {
        engaged_rotor_list.push_back((*lever_it)->getSecondRotor());
      }
    }
  }

  // Remove duplicate. Each rotor only rotate once in each press
  engaged_rotor_list.unique();

  // Rotate the engaged rotors
  for (auto rotor_it = engaged_rotor_list.begin(); rotor_it != engaged_rotor_list.end(); rotor_it++) {
    (*rotor_it)->rotate();
  }

  /* -------------- Electricity/Signal Flow ------------------ */
  // Forward wiring
  for (auto rotor_it = rotorSet.begin(); rotor_it != rotorSet.end(); rotor_it++) {
    //std::cout << input_key << std::endl;
    input_key = (*rotor_it)->forwardWire(input_key);
  }
  DEBUG( "After rotors forward-wiring: " << input_key << std::endl);

  // Reflector
  input_key = reflector.wire(input_key);
  DEBUG( "After reflector: " << input_key << std::endl);

  // Backward wiring
  for (auto rotor_rit = rotorSet.rbegin(); rotor_rit != rotorSet.rend(); rotor_rit++) {
    //std::cout << input_key << std::endl;
    input_key = (*rotor_rit)->backwardWire(input_key);
  }
  DEBUG( "After rotors backward-wiring: " << input_key << std::endl);

  //std::cout << "Enigma Output before plugboard: " << input_key << std::endl << std::endl;

  // Plugboard
  // TODO:

  return input_key;
}


void Enigma::printStatus(void)
{
  for (std::vector<Rotor*>::iterator it = rotorSet.begin() ; it != rotorSet.end(); ++it) {
    (*it)->print();
  }

  reflector.print();
}
