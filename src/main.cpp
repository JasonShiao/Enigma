#include "enigma.h"
#include <string>
#include <iostream>

int main()
{
  /*------------------- Initialization -------------------*/
  Enigma enigma_mach;

  std::string testText("HelloWorld");
  std::string cipherText;
  std::string plainText;

  // Build Enigma I
  enigma_mach.addRotor("I", 'A', 'Q', "EKMFLGDQVZNTOWYHXUSPAIBRCJ");
  enigma_mach.addRotor("II", 'A', 'E', "AJDKSIRUXBLHWTMCQGZNPYFVOE");
  enigma_mach.addRotor("III", 'A', 'V', "BDFHJLCPRTXVZNYEIWGAKMUSQO");

  /* User adjust rotor settings */
  /* Everytime we change rotor setting, we need to update status of all levers */

  /*------------------- Demo/Testing -------------------*/
  std::cout << "test Text: " << testText << std::endl;
  // set the machine to the initial rotor state
  enigma_mach.setRotorPos(0, 'A');
  enigma_mach.setRotorPos(1, 'A');
  enigma_mach.setRotorPos(2, 'A');
  // Encrypt
  for ( std::string::iterator it=testText.begin(); it!=testText.end(); ++it)
  {
    cipherText.append(1, enigma_mach.pressKey(*it));
  }
  std::cout << "Encrypted ciphertext: " << cipherText << std::endl;

  // reset the machine to the initial rotor state
  enigma_mach.setRotorPos(0, 'A');
  enigma_mach.setRotorPos(1, 'A');
  enigma_mach.setRotorPos(2, 'A');
  
  // Decrypt
  for ( std::string::iterator it=cipherText.begin(); it!=cipherText.end(); ++it)
  {
    plainText.append(1, enigma_mach.pressKey(*it));
  }
  std::cout << "Decrypted Plaintext: "<< plainText << std::endl;


  enigma_mach.printStatus();

  return 0;
}
