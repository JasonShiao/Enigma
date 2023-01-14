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
The stepping of a rotor on the right will also cause the rotor on the left to step (e.g. III > II). <br />
But the first rotor (I) always steps so the stepping of the second (II) rotor doesn't affect the first rotor. <br />
Thus, the total number of states is not `26*26*26` but `26*25*26`. <br />
You can refer to this [video](https://youtu.be/hcVhQeZ5gI4) for a clearer understanding.

TODO: Plugboard

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
