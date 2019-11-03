#include <iostream>
#include <array>
#include <vector>
#include <ctype.h>
#include <cassert>

#include "rotor.h"
#include "lever.h"
#include "reflector.h"

#define debug_switch 0

#if debug_switch
#define DEBUG(x) do { std::cerr << x; } while (0)
#else
#define DEBUG(x)
#endif

using namespace std;


class Enigma 
{
    public:

        vector<Rotor*> rotorSet; // ring only set to A for now (non-shift)
        vector<Lever*> leverSet;
        Reflector reflector;

        Enigma();
        bool add_rotor(string rotor_name, char init_pos, char notch_pos, string forward_table);
        bool set_rotor_pos(size_t rotor_idx, char pos);
        char press_key(char key);
        void print_status(void);

};

Enigma::Enigma(): reflector{("YRUHQSLDPXNGOKMIEBFZCWVJAT")}
{
    // default reflector: UKW-B
}

bool Enigma::add_rotor(string rotor_name, char init_pos, char notch_pos, string forward_table)
{
    // setting value check


    rotorSet.push_back(new Rotor(rotor_name, init_pos, notch_pos, forward_table));
    // Add a lever for the newly added rotor
    if(rotorSet.size() == 1){ // first rotor
        leverSet.push_back(new Lever(NULL, *(rotorSet.end()-1))); 
    } else {
        leverSet.push_back(new Lever(*(rotorSet.end()-2), *(rotorSet.end()-1)));
    }

    /* Everytime we change rotor setting/add rotor, we need to update status of all levers */
    for(auto it = leverSet.begin(); it != leverSet.end(); it++)
        (*it)->update();

    return true;
}

bool Enigma::set_rotor_pos(size_t rotor_idx, char pos)
{
    if(rotor_idx < rotorSet.size()){
        if(true != (rotorSet[rotor_idx])->set_current_letter(pos))
            return false;
    } else {
        return false;
    }

    /* Everytime we change rotor setting/add rotor, we need to update status of all levers */
    for(auto it = leverSet.begin(); it != leverSet.end(); it++)
        (*it)->update();

    return true;
}

char Enigma::press_key(char input_key)
{
        DEBUG("Input: " << input_key << endl);

        /* -------------- Mechanic parts ------------------ */
        // A Key is pressed
        for(auto lever_it = leverSet.begin(); lever_it != leverSet.end(); lever_it++)
        {
            (*lever_it)->press();
        }

        // Update status of levers after all rotors have been in a new state
        for(auto lever_it = leverSet.begin(); lever_it != leverSet.end(); lever_it++)
        {
            (*lever_it)->update();
        }

        /* -------------- Electricity/Signal Flow ------------------ */
        // Forward wiring
        for(auto rotor_it = rotorSet.begin(); rotor_it != rotorSet.end(); rotor_it++)
        {
            //cout << input_key << endl;
            input_key = (*rotor_it)->forward_wire(input_key);
        }
        DEBUG( "After rotors forward-wiring: " << input_key << endl);

        // Reflector
        input_key = reflector.wire(input_key);
        DEBUG( "After reflector: " << input_key << endl);

        // Backward wiring
        for(auto rotor_rit = rotorSet.rbegin(); rotor_rit != rotorSet.rend(); rotor_rit++)
        {
            //cout << input_key << endl;
            input_key = (*rotor_rit)->backward_wire(input_key);
        }
        DEBUG( "After rotors backward-wiring: " << input_key << endl);

        //cout << "Enigma Output before plugboard: " << input_key << endl << endl;

        // Plugboard
        // TODO:

        return input_key;
}


void Enigma::print_status(void)
{
    for(std::vector<Rotor*>::iterator it = rotorSet.begin() ; it != rotorSet.end(); ++it)
    {
        (*it)->print_rotor();
    }

    reflector.print();

}


int main()
{
    /*------------------- Initialization -------------------*/
    Enigma machine1;

    string testText("HelloWorld");
    string cipherText;
    string plainText;

    // Enigma I
    machine1.add_rotor("I", 'A', 'Q', "EKMFLGDQVZNTOWYHXUSPAIBRCJ");
    machine1.add_rotor("II", 'A', 'E', "AJDKSIRUXBLHWTMCQGZNPYFVOE");
    machine1.add_rotor("III", 'A', 'V', "BDFHJLCPRTXVZNYEIWGAKMUSQO");

    /* User adjust rotor settings */
        /* Everytime we change rotor setting, we need to update status of all levers */

    /*------------------- Demo/Testing -------------------*/
    cout << "test Text: " << testText << endl;
    // set the machine to the initial rotor state
    machine1.set_rotor_pos(0, 'A');
    machine1.set_rotor_pos(1, 'A');
    machine1.set_rotor_pos(2, 'A');
    // Encrypt
    for ( std::string::iterator it=testText.begin(); it!=testText.end(); ++it)
    {
        cipherText.append(1, machine1.press_key(*it));
    }
    cout << "Encrypted ciphertext: " << cipherText << endl;

    // reset the machine to the initial rotor state
    machine1.set_rotor_pos(0, 'A');
    machine1.set_rotor_pos(1, 'A');
    machine1.set_rotor_pos(2, 'A');
    // Decrypt
    for ( std::string::iterator it=cipherText.begin(); it!=cipherText.end(); ++it)
    {
        plainText.append(1, machine1.press_key(*it));
    }
    cout << "Decrypted Plaintext: "<< plainText << endl;


    machine1.print_status();

    return 0;
}
