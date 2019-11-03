#include <iostream>
#include <string.h>
#include <ctype.h>

#include "reflector.h"


Reflector::Reflector(string reflector_table)
{
    try {
        if(reflector_table.length() != 26)
            throw 1;

        for(auto i = 0; i < 26; i++){
            this->_reflector_table[i] = reflector_table[i];
        }
    }
    catch (int e)
    {
        cerr << "An exception occurred. Invalid initialize table size." << endl;
        throw;
    }

}


char Reflector::wire(char input)
{
    try {
        if(toupper(input) < 'A' || toupper(input) > 'Z')
            throw 1;

        return this->_reflector_table[toupper(input) - 'A'];
    }
    catch (int e)
    {
        cerr << "An exception occurred. Invalid input key." << endl;
        throw;
    }

}

void Reflector::print(void)
{
    cout << "------------------------------------------------------" << endl;
    cout << "| ";cout.width(21); cout << right << "Reflector: ";
    cout.width(30); cout << left << _reflector_table; cout << "|" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << endl;

}