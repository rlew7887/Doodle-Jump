# output file name
TARGET = game

# source files
SOURCES = main.cpp Home.cpp Button.cpp Player.cpp Platform.cpp NormalPlat.cpp BrokenPlat.cpp gameOver.cpp Level1.cpp

# SOURCES (With test files) = Home.cpp Button.cpp Player.cpp Platform.cpp NormalPlat.cpp gameOver.cpp Level1.cpp HighScore.cpp PlayerTest.h HighScoreTest.h mainTest.cpp

UNAME_S := $(shell uname -s)

# OS specific config
ifeq ($(UNAME_S), Darwin)  # mac
    SFML_LIBS = -L/opt/homebrew/lib -I/opt/homebrew/include -lsfml-graphics -lsfml-window -lsfml-system
else ifeq ($(UNAME_S), Linux)  # linux
    SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system
endif


# build executable and run exectuable
$(TARGET): $(SOURCES)
	g++ -std=c++11 $(SOURCES) $(SFML_LIBS) -o $(TARGET).out
	./$(TARGET).out 

# clean workspace
clean:
	rm -f *.out *.o