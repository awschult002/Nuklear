# Install
CC = g++
BIN = demo

# Flags
CFLAGS += -s -Wall -Wextra -pedantic

SRC = main.cpp
OBJ = $(SRC:.cpp=.o)

ifeq ($(OS),Windows_NT)
	# Edit the line below to point to your SFML/GLAD folder on Windows
	SFML_DIR ?= 
	GLAD_DIR ?=

	BIN := $(BIN).exe
	LIBS = -lmingw32 -DSFML_STATIC -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32
else
	# Edit the line below to point to your SFML/GLAD folder on Linux/MacOS
	SFML_DIR ?= 
	GLAD_DIR ?=

	UNAME_S := $(shell uname -s)
	ifeq ($(UNAME_S),Darwin)
		LIBS = -lsfml-window -lsfml-system -pthread -framework OpenGL
	else
		LIBS = -DSFML_STATIC -lsfml-window-s -lsfml-system-s -pthread -ludev -lGL -lX11 -lXrandr
	endif
endif

ifeq ($(SFML_DIR),)
$(info Need to declare the location of the SFML Library)
else
ifeq ($(GLAD_DIR),)
$(info Need to declare the location of the glad files)
else

SFML_INC = -I $(SFML_DIR)/include
SFML_LIB = -L $(SFML_DIR)/lib
GLAD_INC = -I $(GLAD_DIR)/include
GLAD_SRC = $(GLAD_DIR)/src/glad.c

$(BIN):
	$(CC) $(GLAD_SRC) $(SRC) $(CFLAGS) $(GLAD_INC) $(SFML_INC) $(SFML_LIB) $(SFML_EXT) -o $(BIN) $(LIBS)
endif
endif
