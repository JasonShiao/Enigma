#ifndef ROTOR_H
#define ROTOR_H

#include <string.h>

using namespace std;

class Rotor
{
    public:

        Rotor(string, char, char, string);
        char forward_wire(char input);
        char backward_wire(char input);
        void ratchet_rotate();
        void notch_rotate();

        bool set_current_letter(char letter);
        char get_current_letter();
        char get_notch_letter();
        void print_rotor();

    private:
        string _rotor_name = "";

        char _current_letter;
        char _notch_letter;
        // TODO: RingSetting (offset)

        char _forward_table[27] = {0};
        char _backward_table[27] = {0};
};


#endif
