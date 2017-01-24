# Password Generator

- - -
### Попытался освоить C на досуге и вот наваял такой консольный генератор паролей.

- - -
## Сборка

```bash
$ git clone https://github.com/yarkovaleksei/passgen.git
$ cd passgen
$ ./configure
$ make
```

- - -
# Установка

*Самый простой вариант:*

```bash
$ sudo make install
```

Но [вот тут](https://habrahabr.ru/post/130868/) очень не советуют так делать, а советуют юзать **checkinstall**.

Вот такая команда именно его и задействует + соберет пакет в каталог **deb**.

```bash
$ sudo make build install=yes
```

Если указать `install=no` или просто опустить параметр `install`, то пакет будет собран в каталог **deb**, но установки не прозойдет.

- - -
## Установка deb пакета вручную

```bash
$ sudo dpkg -i ./deb/passgen*.deb
```

- - -
## Использование

```bash
$ passgen -h
Консольный генератор паролей

Параметры по-умолчанию:
	Длина пароля:                 25

Используемые ключи:
	-h, --help                       Справочная информация
	-v, --version                    Номер версии релиза
	-l, --length                     Длина пароля. Если не указан, то
	                                 он будет установлен в 25. Если указать 0,
	                                 то программа запросит ввод с клавиатуры.
	-c, --count                      Количество паролей за один вызов программы.
	                                 Полезно, когда надо сгенерировать
	                                 файл с уникальными строками.
	-P, --pattern                    Строка, содержащая возможные
	                                 символы для генерации пароля.
	                                 Если ключ указан, то ключи
	                                 -u, -d, -n, -s будут проигнорированы.
	-u, --letter-up                  Использовать английские буквы в верхнем регистре
	-d, --letter-down                Использовать английские буквы в нижнем регистре
	-n, --number                     Использовать цифры
	-s, --symbol                     Использовать символы и знаки препинания
	-e, --enable-space               Добавить пробел в шаблон пароля

Примеры использования:
	$ passgen -l0                    # Ввести длину пароля с клавиатуры
	$ passgen -l25 -d                # Использовать только английские буквы в нижнем регистре
	$ passgen -l25 -s                # Использовать только символы и знаки препинания
	$ passgen -l25 -dn               # Использовать только английские буквы в нижнем регистре и цифры
	$ passgen -l25 -du               # Использовать только английские буквы в нижнем и верхнем регистре
	$ passgen -l25 -P123abc          # Использовать только перечисленные символы: '123abc'
	$ passgen -l25 -P123abc -e       # Использовать только перечисленные символы: '123abc' и пробел
	$ passgen -l25 -c5               # Список из 5 паролей, по одному в строке
```

- - -
## Указать явное использование языка

*Поддерживается русская и английская локализация*

```bash
$ LANG=ru_RU passgen -h
$ LANG=en_US passgen -h
```

*Если нужная локализация не найдена, то будет использована английская*

- - -
## Удаление

```bash
$ sudo make uninstall
```

**Если установили собранный deb пакет, то воспользуйтесь этой командой:**

```bash
$ sudo dpkg -r passgen
```

- - -
## Справка по командам make

```bash
$ make help

```
