#ifndef ROTOR_H
#define ROTOR_H

#include <string>

class Rotor
{
 public:
  Rotor(std::string rotor_name, char init_pos, char notch_pos, std::string forward_table_str);
  char forwardWire(char input);
  char backwardWire(char input);
  void rotate();

  bool setCurrentLetter(char letter);
  char getCurrentLetter();
  char getNotchLetter();
  void print();

 private:
  std::string _rotor_name{"Default rotor name"};

  char _current_letter;
  char _notch_letter;
  // TODO: RingSetting (offset)

  void getForwardTableString(char *table_str);
  int _forward_table[26] = {0};
  int _backward_table[26] = {0};
};

#endif
