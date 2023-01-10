add_library(enigma)

target_sources(enigma PRIVATE
  enigma.cpp
  lever.cpp
  reflector.cpp
  rotor.cpp
)

target_sources(enigma PRIVATE
  enigma.h
  lever.h
  reflector.h
  rotor.h
)

set_target_properties(enigma PROPERTIES PUBLIC_HEADER enigma.h)
