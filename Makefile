CXX = g++
CXXFLAGS = -std=c++11

SRCS = $(wildcard *.cpp)
INCS = $(wildcard *.h)
OBJS = $(subst .cpp, .o,$(SRCS))

OBJECTS = $(SOURCES:%.cpp=%.o)

TARGET = Enigma

#OBJS = $(patsubst %.cpp, %.o,$(SRCS))

.PHONY: all build clean debug release depend

all: $(TARGET)

#-include $(DEPS)

$(TARGET): $(SRCS) $(INCS)
	$(info ************  Making Enigma executable... ************)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)


#%.o: %.cpp
#	@$(CC) $(CXXFLAGS) $(INCLUDES) -o $@ $<

# g++ -std=c++11 -o enigma enigma.cpp lever.cpp rotor.cpp reflector.cpp
