CC = g++ -std=c++11
LIBS = -lm 
SRC = src
OBJ = ./obj/
INC = ./include/
BIN = ./
OBJS = $(OBJ)/rock.o $(OBJ)/main.o
HDRS = $(INC)/rock.hpp $(INC)/msgassert.hpp
CFLAGS = -g -Wall -c -I$(INC)

EXE = $(BIN)/tp02

all: comp 

comp: $(BIN)/tp02

exe: $(EXE)
	$(EXE) tp02 

$(BIN)/tp02: $(OBJS)
	$(CC) -g -o $(BIN)/tp02 $(OBJS) $(LIBS)

$(OBJ)/main.o: $(HDRS) $(SRC)/main.cpp
	$(CC)  $(CFLAGS) -o $(OBJ)/main.o $(SRC)/main.cpp 

$(OBJ)/rock.o: $(HDRS) $(SRC)/rock.cpp
	$(CC) $(CFLAGS) -o $(OBJ)/rock.o $(SRC)/rock.cpp 

clean:
	rm -f $(EXE)* $(OBJS)* 	
	clear   