# Makefile for PassGen project
# Документация с примерами: http://linux.yaroslavl.ru/docs/prog/make_intro_ru.html

# Рабочая оболочка
SHELL 			= /bin/bash
# Имя бинарного файла
PACKAGE 		= passgen
# Описание пакета
DESCRIPTION		= "Console password generator"
# Описание пакета
DESCRIPTIONFILE	= "./description-pak"
# Версия релиза
PACKAGEVERSION 	= "0.0.1"
# Каталог для собранного бинарного файла
BINDIR 			= ./bin
# Каталог для deb пакета
DEBDIR			= ./deb
# Каталог с исходниками программы
SRCDIR 			= ./source
# Каталог для файлов локализации
LOCALEDIR 		= ./locale
# Каталог для установки файлов локализации
LOCALE_TARGET	= /usr/share/locale/ru/LC_MESSAGES
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
LICENSE			= "MIT"

HELP			= "Usage make:\n\
make 				- build binary file from source\n \
make clean 			- clean project folder from *.o, ./bin, etc.\n \
make test 			- run binary with test parameters\n \
make elang 			- extract localize phrases from source to *.po\n \
make glang 			- create localize *.mo file from *.po files\n \
make autodoc 		- generate README.md\n \
sudo make build 	- build deb package\n \
sudo make install 	- install binary to $(INSTALLDIR)\n \
sudo make uninstall - uninstall binary from $(INSTALLDIR)"

.PHONY: all build clean install uninstall test elang glang help autodoc

all: $(PACKAGE)
	@echo "[$(PACKAGE)] - Project compiled"

$(PACKAGE): $(PACKAGE).o main.o
	@mkdir -p $(BINDIR)
	@$(GCC) -Wall -o $(BINDIR)/$(PACKAGE) $?
	@strip -s $(BINDIR)/$(PACKAGE) # Удаляем отладочную информацию из бинарника
	@echo $(DESCRIPTION) > $(DESCRIPTIONFILE)

%.o: $(SRCDIR)/%.c
	@$(GCC) -c $?

# Запускаем сборку deb пакета
build: all
	@mkdir -p $(DEBDIR)
	@checkinstall \
	--default -D --nodoc \
	--pkgname=$(PACKAGE) \
	--pkgrelease=$(PACKAGEVERSION) \
	--pkgversion=$$(date +%Y%m%d) \
	--pkgsource=$(SRCDIR) \
	--pakdir=$(DEBDIR) \
	--maintainer=$(EMAIL) \
	--pkglicense=$(LICENSE) \
	--install=no \
	--gzman=yes \
	--deldoc=yes \
	--deldesc=no \
	--delspec=yes \
	--backup=no \
	--strip=yes

clean:
	@rm -rf $(BINDIR) $(DEBDIR) *.o *.*~ d*-pak README.md
	@echo "[$(PACKAGE)] - Project cleaned"

install: all
	@install $(BINDIR)/$(PACKAGE) $(INSTALLDIR)
	@cp $(LOCALE_MO) $(LOCALE_TARGET)
	@echo "[$(PACKAGE)] - installed to $$(which $(PACKAGE))"

uninstall:
	@rm -rf $(INSTALLDIR)/$(PACKAGE)
	@echo "[$(PACKAGE)] - uninstalled from $$(which $(PACKAGE))"

test: all
	@test $$($(BINDIR)/$(PACKAGE) -l20 -ds | wc -m) == '21' && echo "[PASSGEN TEST] single line: OK" || echo "[PASSGEN TEST] single line: ERROR"
	@test $$($(BINDIR)/$(PACKAGE) -l20 -ds -c5 | wc -l) == '5' && echo "[PASSGEN TEST] multi line: OK" || echo "[PASSGEN TEST] multi line: ERROR"

# Сканирует исходники на предмет использования gettext
# и создает файл локализации ./locale/ru/passgen.po
elang:
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
glang:
	@msginit \
	--no-wrap \
	--no-translator \
	--input=$(TMP_LOCALE_PO) \
	--output-file=$(LOCALE_PO) \
	--locale=$(LOCALE)
	@msgfmt \
	$(LOCALE_PO) \
	--output-file=$(LOCALE_MO)

help:
	@echo -e $(HELP)

# Генерируем вайл README.md и вставляем в него актуальную информацию
autodoc: all
	@cat ./.src/1 > ./README.md
	@./bin/passgen -h >> ./README.md
	@cat ./.src/2 >> ./README.md
	@echo -e $(HELP) >> ./README.md
	@echo "\`\`\`" >> ./README.md
