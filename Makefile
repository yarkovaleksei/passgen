# Makefile for PassGen project

BINNAME = passgen
BIN_DIR = ./bin
SRC_DIR = ./source
INSTALL_DIR = /usr/local/bin

.PHONY: all clean install uninstall

all: $(BINNAME)

$(BINNAME): $(BINNAME).o main.o
	mkdir -p $(BIN_DIR) && gcc -o $(BIN_DIR)/$(BINNAME) $(BINNAME).o main.o

$(BINNAME).o: $(SRC_DIR)/$(BINNAME).c
	gcc -c $(SRC_DIR)/$(BINNAME).c

main.o: $(SRC_DIR)/main.c
	gcc -c $(SRC_DIR)/main.c

clean:
	rm -rf *.o $(BIN_DIR)/$(BINNAME)

install:
	install $(BIN_DIR)/$(BINNAME) $(INSTALL_DIR)

uninstall:
	rm -rf $(INSTALL_DIR)/$(BINNAME)