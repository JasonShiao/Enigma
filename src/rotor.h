#ifndef ROTOR_H
#define ROTOR_H

#include <string>

class Rotor
{
 public:
  Rotor(std::string, char, char, std::string);
  char forwardWire(char input);
  char backwardWire(char input);
  void ratchetRotate();
  void notchRotate();

  bool setCurrentLetter(char letter);
  char getCurrentLetter();
  char getNotchLetter();
  void print();

 private:
  std::string _rotor_name = "";

  char _current_letter;
  char _notch_letter;
  // TODO: RingSetting (offset)

  char _forward_table[27] = {0};
  char _backward_table[27] = {0};
};

#endif
