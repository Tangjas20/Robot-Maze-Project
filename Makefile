ifeq ($(OS),Windows_NT)
	CFLAGS = -Ios/windows -Los/windows/lib  -Iinclude -lmingw32 -lSDL2main -lSDL2
	BIN = bin/main.exe
	RM_BIN = del /q bin && rmdir bin
	CREATE_BIN_DIR = mkdir bin && copy os\\windows\\bin\\SDL2.dll bin\\
else
	CFLAGS = -Iinclude -lSDL2 -lm
	BIN = bin/main
	RM_BIN = rm -r bin
	CREATE_BIN_DIR = mkdir bin
endif

CC = gcc
BIN_DIR = bin
HEADERS = $(wildcard include/*.h)
SRC = src

all: $(BIN)

$(BIN): $(HEADERS) $(BIN_DIR)
	$(CC) $(SRC)/*.c -o $(BIN_DIR)/main $(CFLAGS)

$(BIN_DIR):
	$(CREATE_BIN_DIR)

clean:
	$(RM_BIN)
