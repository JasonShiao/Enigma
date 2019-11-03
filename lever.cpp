#include <iostream>

#include "lever.h"

using namespace std;

Lever::Lever(Rotor *right_rotor, Rotor *left_rotor)
{

    try {
        if(left_rotor == NULL)
            throw 1;

        if(right_rotor == NULL)
            this->_is_thin_lever = true;
        else{
            this->_is_thin_lever = false;
            if(right_rotor->get_current_letter() == right_rotor->get_notch_letter())
                this->_is_notch_engaged = true;
            else
                this->_is_notch_engaged = false;
        }

        this->_right_rotor = right_rotor;
        this->_left_rotor = left_rotor;

    }
    catch(int e)
    {
        cerr << "An exception occurred. left_rotor can't be empty or NULL." << endl;
        throw;
    }

}


void Lever::press()
{
    try {
        if(this->_left_rotor == NULL || (this->_right_rotor == NULL && !this->_is_thin_lever))
            throw 1;

        if(this->_is_thin_lever){
            (this->_left_rotor)->ratchet_rotate();
        } else {
            if(this->_is_notch_engaged){
                (this->_left_rotor)->ratchet_rotate();
                (this->_right_rotor)->notch_rotate();
            } else {
                // push nothing
            }
        }

    }
    catch(int e)
    {
        cerr << "An exception occurred. Not initialized correctly." << endl;
        throw;
    }

}

void Lever::update()
{

    try {
        if(this->_left_rotor == NULL || (this->_right_rotor == NULL && !this->_is_thin_lever))
            throw 1;

        if(!this->_is_thin_lever){ // normal lever
            if(this->_right_rotor->get_current_letter() == this->_right_rotor->get_notch_letter()){
                this->_is_notch_engaged = true;
            } else {
                this->_is_notch_engaged = false;
            }
        }
    }
    catch(int e)
    {
        cerr << "An exception occurred. Not initialized correctly." << endl;
        throw;
    }

}
