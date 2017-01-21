# Makefile for PassGen project

# Рабочая оболочка
SHELL 			= $$(which bash)

# Имя бинарного файла
PACKAGE 		= passgen
# Версия релиза
PACKAGEVERSION 	= "0.0.1"
# Каталог для собранного бинарного файла
BINDIR 			= ./bin
# Каталог с исходниками программы
SRCDIR 			= ./source
# Каталог для файлов локализации
LOCALEDIR 		= ./locale
# Файл локализации
LOCALE_MO		= $(LOCALEDIR)/ru/LC_MESSAGES/$(PACKAGE).mo
# Исходник файла локализации
LOCALE_PO		= $(LOCALEDIR)/ru/LC_MESSAGES/$(PACKAGE).po
# Временный файл локализации
TMP_LOCALE_PO	= $(LOCALEDIR)/ru/$(PACKAGE).po
# Каталог, куда будет установлена программа
INSTALLDIR 		= /usr/local/bin
# Путь к компилятору
GCC 			= $$(which gcc)
# Текст сообщения об удачном тесте
OKMSG 			= "[PASSGEN TEST] OK"
# Текст сообщения о неудачном тесте
ERRMSG 			= "[PASSGEN TEST] ERROR"

AUTHOR 			= "Yarkov Aleksey"
EMAIL 			= "yarkov_aleksei@mail.ru"
CHARSET			= "UTF-8"
LOCALE 			= "ru_RU"

.PHONY: all clean install uninstall test extract_lang generate_lang

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
	cp -i $(LOCALE_MO) /usr/share/locale/ru/LC_MESSAGES
	@echo "[$(PACKAGE)] - installed to $$(which $(PACKAGE))"

uninstall:
	@rm -rf $(INSTALLDIR)/$(PACKAGE)
	@echo "[$(PACKAGE)] - uninstalled from $$(which $(PACKAGE))"

test: all
	@test $$($(BINDIR)/$(PACKAGE) -l20 -ds | wc -m) == '21' && echo "[PASSGEN TEST] single line: OK" || echo "[PASSGEN TEST] single line: ERROR"
	@test $$($(BINDIR)/$(PACKAGE) -l20 -ds -c5 | wc -l) == '5' && echo "[PASSGEN TEST] multi line: OK" || echo "[PASSGEN TEST] multi line: ERROR"

# Сканирует исходники на предмет использования gettext
# и создает файл локализации ./locale/ru/passgen.po
extract_lang:
	@xgettext \
	--no-wrap \
	--force-po \
	--copyright-holder=$(AUTHOR) \
	--msgid-bugs-address=$(EMAIL) \
	--default-domain=$(PACKAGE) \
	--package-name=$(PACKAGE) \
	--package-version=$(PACKAGEVERSION) \
	--output-dir=/tmp \
	--language=C \
	--from-code=$(CHARSET) \
	--keyword=_ \
	$(SRCDIR)/*.c $(SRCDIR)/**/*.h
	@msgmerge -N -U \
	--no-wrap \
	--suffix=.backup \
	--backup=numbered \
	$(TMP_LOCALE_PO) \
	/tmp/$(PACKAGE).po
	@echo "Add translate to file $(LOCALEDIR)/ru/$(PACKAGE).po and run command 'make generate_lang'"

# Создает файл локализации ./locale/ru/LC_MESSAGES/passgen.mo
generate_lang:
	@msginit \
	--no-wrap \
	--no-translator \
	--input=$(TMP_LOCALE_PO) \
	--output-file=$(LOCALE_PO) \
	--locale=$(LOCALE)
	@msgfmt \
	$(LOCALE_PO) \
	--output-file=$(LOCALE_MO)
