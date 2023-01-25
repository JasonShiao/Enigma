# Enigma I (Wehrmacht Enigma)
The result of cipher changes with different initial settings of rotors (and plugboard). <br />
As a result, even others acquire the cipher text and the same Enigma I machine, they couldn't decipher the text without initial settings.

A simple software implementation of Enigma I machine

### Components:
* Entry disk (Eintrittswalze, ETW): 
* Rotors: Each rotor performs mapping for each character
* Reflector (UKW): 
* Plug board (Steckerverbindungen): 
* Lever: Mechanic part used to push the rotors. Each rotor has a corresponding lever but only when the notch contacts with the lever can the rotor be pushed except for the first rotor.

### Double stepping:
Except for the first lever, each lever engages with rotors on both side simultaneously <br />
When the second rotor enters the notch position, the third lever will not only push the third rotor but also the second rotor in the next push. <br /> 
But the first rotor (I) always steps so the stepping of the second rotor doesn't affect the state if the first rotor. <br />
Thus, the total number of states is not `26*26*26` but `26*25*26`. <br />
You can refer to this [video](https://youtu.be/hcVhQeZ5gI4) for a clearer understanding.

### TODO: 
* Plugboard: Swap of letter at the beginning and the end
* Ring Setting (Ringstellung): The relative position of the ring wire to the alphabet ring on rotor

### References
* [Crypto Museum](https://www.cryptomuseum.com/crypto/enigma/wiring.htm)
* [Practical Cryptography](http://practicalcryptography.com/ciphers/enigma-cipher/)

## Build
```
cmake -S . -B build
cmake --build build --config RelWithDebInfo --target all -j 6 --
```

## Demo
Settings: 
* Rotor I, Rotor II, Rotor III
  * initial position: A, A, A
  * ring setting (offset): A, A, A (only fixed to A, A, A currently)
* Reflector: UKW-B (which is used in WWII)  
```
./build/enigma_example
```
test Input `HelloWorld` 
Output
```
MFNCZBBFZM
```

You can use other online Enigma simulators to verify the result, e.g. https://www.dcode.fr/enigma-machine-cipher
