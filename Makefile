# Makefile for PassGen project
SHELL 			= /bin/bash

PACKAGE 		= passgen
PACKAGEVERSION 	= "0.0.1"
BINDIR 			= ./bin
SRCDIR 			= ./source
LOCALEDIR 		= ./locale
INSTALLDIR 		= /usr/local/bin
GCC 			= gcc
OKMSG 			= "[PASSGEN TEST] OK"
ERRMSG 			= "[PASSGEN TEST] ERROR"

AUTHOR 			= "Yarkov Aleksey"
EMAIL 			= "yarkov_aleksei@mail.ru"
CHARSET			= "utf-8"
LOCALE 			= "ru_RU.UTF8"

.PHONY: all clean install uninstall test extract_lang generate_lang update_lang

$(PACKAGE): $(PACKAGE).o main.o
	@mkdir -p $(BINDIR)
	@$(GCC) -Werror -o $(BINDIR)/$(PACKAGE) $?
	@strip -s $(BINDIR)/$(PACKAGE)
	@echo "[$(PACKAGE)] - Project compiled"

$(PACKAGE).o: $(SRCDIR)/$(PACKAGE).c
	@$(GCC) -c $?

main.o: $(SRCDIR)/main.c
	@$(GCC) -c $?

all: $(PACKAGE)

clean:
	@rm -rf $(BINDIR)/$(PACKAGE) *.o *.*~
	@echo "[$(PACKAGE)] - Project cleaned"

install:
	@install $(BINDIR)/$(PACKAGE) $(INSTALLDIR)
	cp -i $(LOCALEDIR)/ru/LC_MESSAGES/$(PACKAGE).mo /usr/share/locale/ru/LC_MESSAGES
	@echo "[$(PACKAGE)] - installed to $$(which $(PACKAGE))"

uninstall:
	@rm -rf $(INSTALLDIR)/$(PACKAGE)
	@echo "[$(PACKAGE)] - uninstalled from $$(which $(PACKAGE))"

test: all
	@test $$($(BINDIR)/$(PACKAGE) -l20 -ds | wc -m) == '21' && echo $(OKMSG) || echo $(ERRMSG)

extract_lang:
	@xgettext \
	--no-wrap \
	--force-po \
	--copyright-holder=$(AUTHOR) \
	--msgid-bugs-address=$(EMAIL) \
	--default-domain=$(PACKAGE) \
	--package-name=$(PACKAGE) \
	--package-version=$(PACKAGEVERSION) \
	--output-dir=$(LOCALEDIR)/ru \
	--language=C \
	--from-code=$(CHARSET) \
	--keyword=_ \
	$(SRCDIR)/*.c
	@echo "Add translate to file $(LOCALEDIR)/ru/$(PACKAGE).po and run command 'make generate_lang'"

generate_lang:
	@msginit \
	--no-wrap \
	--input=$(LOCALEDIR)/ru/$(PACKAGE).po \
	--output-file=$(LOCALEDIR)/ru/LC_MESSAGES/$(PACKAGE).po \
	--locale=$(LOCALE)
	@msgfmt \
	$(LOCALEDIR)/ru/LC_MESSAGES/$(PACKAGE).po \
	--output-file=$(LOCALEDIR)/ru/LC_MESSAGES/$(PACKAGE).mo

update_lang:
	@msgmerge -N -U \
	--no-wrap \
	--suffix=.backup \
	--backup=numbered \
	$(LOCALEDIR)/ru/LC_MESSAGES/$(PACKAGE).po \
	$(LOCALEDIR)/ru/$(PACKAGE).po
