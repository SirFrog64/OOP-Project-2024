# Output file name
TARGET = game

# Source files
SOURCES = AttackButton.cpp Button.cpp BuyCarrierButton.cpp BuyDestroyerButton.cpp BuyFrigateButton.cpp BuyShipButton.cpp BuySubmarineButton.cpp Carrier.cpp Destroyer.cpp Fleet.cpp Frigate.cpp GameState.cpp OOP-Game.cpp Ship.cpp Submarine.cpp UIManager.cpp EndTurnButton.cpp

# Operating system detection
UNAME_S := $(shell uname -s)

# OS specific config for SFML libraries
ifeq ($(UNAME_S), Darwin)   # macOS
    SFML_LIBS = -L/opt/homebrew/lib -I/opt/homebrew/include -lsfml-graphics -lsfml-window -lsfml-system
else ifeq ($(UNAME_S), Linux)   # Linux
    SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system
else    # Add Windows case or others if needed
    SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system
endif

# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++14 -Wall

# Build executable and run executable
$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(SOURCES) $(SFML_LIBS) -o $(TARGET).out
	./$(TARGET).out 

# Clean workspace
clean:
	rm -f $(TARGET).out