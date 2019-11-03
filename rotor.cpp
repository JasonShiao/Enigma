
#include <iostream>
#include <ctype.h>
#include <cassert>
#include <string.h>

#include "rotor.h"

using namespace std;


Rotor::Rotor(string rotor_name, char init_pos, char notch_pos, string forward_table)
{

    try {
        if(toupper(init_pos) < 'A' && toupper(init_pos) > 'Z')
            throw 1;
        if(toupper(notch_pos) < 'A' && toupper(notch_pos) > 'Z')
            throw 1;
        if(forward_table.length() != 26)
            throw 1;

        this->_rotor_name.swap(rotor_name);
        this->_current_letter = toupper(init_pos);
        this->_notch_letter = toupper(notch_pos);
        for(auto i = 0; i < 26; i++){
            this->_forward_table[i] = forward_table[i];
            this->_backward_table[forward_table[i] - 'A'] = i + 'A';
        }

    }
    catch(int e)
    {
        cout << "An exception occurred. Invalid argument." << endl;
        throw;
    }

}

char Rotor::forward_wire(char input)
{
    input = toupper(input);

    try {
        if(input < 'A' || input > 'Z')
            throw 1;

        char local_pos, abs_pos;
        //cout << "Current pos: " << this->_current_letter << endl;
        local_pos = this->_forward_table[(input - 'A' + this->_current_letter - 'A')%26];
        abs_pos = ((local_pos - this->_current_letter) >= 0?(local_pos - this->_current_letter + 'A'):(local_pos + 26 - this->_current_letter + 'A'));
        return abs_pos;

    }
    catch (int e)
    {
        cout << "An exception occurred. Invalid input key." << endl;
        throw;
    }

}

char Rotor::backward_wire(char input)
{
    input = toupper(input);

    try {
        if(input < 'A' || input > 'Z')
            throw 1;

        char local_pos, abs_pos;
        local_pos = this->_backward_table[(input - 'A' + this->_current_letter - 'A')%26];
        abs_pos = ((local_pos - this->_current_letter) >= 0?(local_pos - this->_current_letter + 'A'):(local_pos + 26 - this->_current_letter + 'A'));
        return abs_pos;

    }
    catch (int e)
    {
        cout << "An exception occurred. Invalid input key." << endl;
        throw;
    }

}

void Rotor::ratchet_rotate()
{
    assert(this->_current_letter >= 'A' && this->_current_letter <= 'Z');

    if(this->_current_letter == 'Z') {
        this->_current_letter = 'A';
    } else {
        this->_current_letter++;
    }
}

void Rotor::notch_rotate()
{
    assert(this->_current_letter >= 'A' && this->_current_letter <= 'Z');

    if(this->_current_letter == this->_notch_letter) // lever engaged
    {
        if(this->_current_letter == 'Z') {
            this->_current_letter = 'A';
        } else {
            this->_current_letter++;
        }
    } else {
        // lever not engaged, no push force
    }

}

bool Rotor::set_current_letter(char letter)
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

char Rotor::get_current_letter()
{
    return this->_current_letter;
}

char Rotor::get_notch_letter()
{
    return this->_notch_letter;
}


void Rotor::print_rotor()
{
    cout << "------------------------------------------------------" << endl;
    cout << "| ";cout.width(21); cout << right << "Rotor Name: ";
    cout.width(30); cout << left << this->_rotor_name; cout << "|" << endl;
    cout << "| ";cout.width(21); cout << right << "Current Letter: ";
    cout.width(30); cout << left << this->_current_letter; cout << "|" << endl;
    cout << "| ";cout.width(21); cout << right << "Notch Pos: ";
    cout.width(30); cout << left << this->_notch_letter; cout << "|" << endl;
    cout << "| ";cout.width(21); cout << right << "Rotor internal wire: ";
    cout.width(30); cout << left << this->_forward_table; cout << "|" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << endl;
    return;
}
