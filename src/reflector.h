#ifndef REFLECTOR_H
#define REFLECTOR_H

#include <string>

class Reflector
{
 public:
  Reflector(std::string reflector_table);
  char wire(char input);
  void print(void);

 private:
  char _reflector_table[27] = {0};
};

#endif
