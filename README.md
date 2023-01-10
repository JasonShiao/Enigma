# Enigma I
A simple implementation of Enigma I machine

NOTE: Plugboard  hasn't been implemented yet

## Build
```
cmake -S . -B build
cmake --build build --config RelWithDebInfo --target all -j 6 --
./build/enigma_example
```

## Demo
Settings: 
* Rotor I, Rotor II, Rotor III
  * initial position: A, A, A
  * ring setting (offset): A, A, A (only fixed to A, A, A currently)
* Reflector: UKW-B (which is used in WWII)  

test Input `HelloWorld` 
Output
```
MFNCZBBFZM
```

You can use other online Enigma simulators to verify the result, e.g. https://www.dcode.fr/enigma-machine-cipher
