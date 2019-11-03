#ifndef LEVER_H
#define LEVER_H

#include "rotor.h"

class Lever
{
public:

    Lever(Rotor *right_rotor, Rotor *left_rotor);
    void press();
    void update(); // update relative position with rotors (update notch status)


private:
    Rotor* _right_rotor = NULL; // notch-contact rotor (fast)
    Rotor* _left_rotor = NULL;  // ratchet-contact rotor (slow)
    bool _is_notch_engaged = false;         // fall into the notch
    bool _is_thin_lever = false;        // thin/right-most lever behaves different from others

};



#endif
