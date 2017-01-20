# Makefile for PassGen project
SHELL 		= /bin/bash

BINNAME 	= passgen
BINDIR 		= ./bin
SRCDIR 		= ./source
INSTALLDIR 	= /usr/local/bin
GCC 		= gcc
OKMSG 		= "[PASSGEN TEST] OK"
ERRMSG 		= "[PASSGEN TEST] ERROR"

.PHONY: all clean install uninstall test

$(BINNAME): $(BINNAME).o main.o
	@mkdir -p $(BINDIR)
	@$(GCC) -Werror -o $(BINDIR)/$(BINNAME) $?
	@strip -s $(BINDIR)/$(BINNAME)
	@echo "[$(BINNAME)] - Project compiled"

$(BINNAME).o: $(SRCDIR)/$(BINNAME).c
	@$(GCC) -c $?

main.o: $(SRCDIR)/main.c
	@$(GCC) -c $?

all: $(BINNAME)

clean:
	@rm -rf $(BINDIR)/$(BINNAME) *.o *.*~
	@echo "[$(BINNAME)] - Project cleaned"

install:
	@install $(BINDIR)/$(BINNAME) $(INSTALLDIR)
	@echo "[$(BINNAME)] - installed to $$(which $(BINNAME))"

uninstall:
	@rm -rf $(INSTALLDIR)/$(BINNAME)
	@echo "[$(BINNAME)] - uninstalled from $$(which $(BINNAME))"

test: all
	@test $$($(BINDIR)/$(BINNAME) -l20 -ds | wc -m) == '21' && echo $(OKMSG) || echo $(ERRMSG)
