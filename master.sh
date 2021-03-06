#!/bin/bash

set -e

# Очищаем папку проекта от лишнего
make clean && make distclean

# Запускаем создание конфигурационных файлов
autoreconf && ./configure

# Компилируем программу
make

# Если пакет установлен, то удаляем
test $(which passgen) != "" && sudo dpkg -r passgen

# Ставим свежий пакет
sudo make build install=yes

# Генерируем README.md
make doc

# Очищаем папку проекта от лишнего
make clean && make distclean

# Добавляем в индекс GIT, делаем коммит и отправляем все ветки на сервер
git add --all && git commit -a && git push --all origin
