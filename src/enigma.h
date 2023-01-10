#ifndef ENIGMA_H
#define ENIGMA_H

#include <vector>
#include <string>
#include "rotor.h"
#include "reflector.h"
#include "lever.h"

class Enigma 
{
 public:

  std::vector<Rotor*> rotorSet; // ring only set to A for now (non-shift)
  std::vector<Lever*> leverSet;
  Reflector reflector{"YRUHQSLDPXNGOKMIEBFZCWVJAT"}; // default reflector: UKW-B

  Enigma();
  bool addRotor(std::string rotor_name, char init_pos, char notch_pos, std::string forward_table);
  bool setRotorPos(size_t rotor_idx, char pos);
  char pressKey(char key);
  void printStatus(void);

};


#endif // ENIGMA_H