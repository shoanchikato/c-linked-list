ASAN = address,undefined,bounds,alignment,null,shift,signed-integer-overflow,object-size,vla-bound,float-divide-by-zero,return

SRC = ./src/*.c
BIN = ./bin
OBJ = $(BIN)/liblinked_list.o
LIB = $(BIN)/liblinked_list.a
LIB_DIR = ./bin
LIB_NAME = linked_list

.PHONY: test
test: lib
	mkdir -p bin
	gcc -Wall -fsanitize=$(ASAN) -O1 -I./include -I./test -L$(LIB_DIR) -l$(LIB_NAME) -o ./bin/test ./test/*.c && ./bin/test

.PHONY: lib
lib:
	mkdir -p bin
	gcc -Wall -I./include -c -o $(OBJ) $(SRC) && ar rcs $(LIB) $(OBJ)

.PHONY: clean
clean:
	rm -rf bin