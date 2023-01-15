#ifndef LEVER_H
#define LEVER_H

#include "rotor.h"

class Lever
{
 public:
  Lever(Rotor *first_rotor, Rotor *second_rotor);
  bool checkEngaged();
  Rotor* getFirstRotor();
  Rotor* getSecondRotor();

 private:
  Rotor* _first_rotor = NULL;   // notch ring-contact rotor (NULL for the first lever)
  Rotor* _second_rotor = NULL;  // ratchet-contact rotor
  bool _is_first_lever = false; // first lever behaves slightly different from others
};

#endif
