# passgen

- - -
### Консольный генератор паролей на C

- - -
![](img.jpg)

- - -
1. [Сборка](#Сборка)
2. [Установка](#Установка)
3. [Установка собранного пакета вручную](#Установка-собранного-пакета-вручную)
4. [Использование](#Использование)
5. [Указать явное использование языка](#Указать-явное-использование-языка)
6. [Скорость](#Скорость)
7. [Справка по командам make](#Справка-по-командам-make)
8. [Локализация программы](#Локализация-программы)
9. [Добавить перевод](#Добавить-перевод)
10. [Поддерживаемые ОС](#Поддерживаемые-ОС)

- - -
## Сборка

```bash
$ git clone https://github.com/yarkovaleksei/passgen.git
$ cd passgen
$ ./configure
$ make
```

*Если файла ./configure нет, попробуйте запустить autoreconf*

```bash
$ autoreconf
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

В общем-то пакет не имеет проблем при любом способе установки и удаления, но мы же привыкли верить Хабрасообществу?

Поэтому вот такая команда задействует **checkinstall** + соберет пакет в каталог **build**.

```bash
$ sudo make build install=yes
```

Если указать `install=no` или просто опустить параметр `install`, то пакет будет собран в каталог **build**, но установки не прозойдет.

- - -
## Установка собранного пакета вручную

```bash
$ sudo dpkg -i ./build/passgen*.deb
```

- - -
## Использование

```bash
$ passgen -h
Консольный генератор паролей

Параметры по-умолчанию:
	Длина пароля по-умолчанию: 25      
	Максимальная длина пароля: 4096    
	Максимальное количество паролей: 1000000 
	Максимальная длина шаблона: 200     

Используемые ключи:
	-h, --help                       Справочная информация
	-v, --version                    Номер версии релиза

	-l, --length=LENGTH              Длина пароля. Если не указан, то
	                                 он будет установлен в значение по-умолчанию. Если указать 0,
	                                 то программа запросит ввод с клавиатуры.
	-c, --count=COUNT                Количество паролей за один вызов программы.
	                                 Полезно, когда надо сгенерировать
	                                 файл с уникальными строками.
	-P, --pattern=PATTERN            Строка, содержащая возможные
	                                 символы для генерации пароля.
	                                 Если ключ указан, то ключи
	                                 -u, -d, -n, -s будут проигнорированы.
	-u, --letter-up                  Использовать английские буквы в верхнем регистре
	-d, --letter-down                Использовать английские буквы в нижнем регистре
	-n, --number                     Использовать цифры
	-s, --symbol                     Использовать символы и знаки препинания
	-e, --enable-space               Добавить пробел в шаблон пароля

Примеры использования:
	passgen -l0 -u                 # Ввести длину пароля с клавиатуры и использовать только английские буквы в верхнем регистре
	passgen -l25 -d                # Использовать только английские буквы в нижнем регистре
	passgen -l25 -s                # Использовать только символы и знаки препинания
	passgen -l25 -dn               # Использовать только английские буквы в нижнем регистре и цифры
	passgen -l25 -du               # Использовать только английские буквы в нижнем и верхнем регистре
	passgen -l25 -P123abc          # Использовать только перечисленные символы: '123abc'
	passgen -l25 -P123abc -e       # Использовать только перечисленные символы: '123abc' и пробел
	passgen -l25 -c5               # Список из 5 паролей, по одному в строке

Об ошибках сообщайте по адресу <yarkov_aleksei@mail.ru>

Больше информации на странице проекта:
	https://github.com/yarkovaleksei/passgen
```

- - -
## Указать явное использование языка

**Поддерживается русская и английская локализация**

```bash
$ LANG=ru_RU passgen -h
$ LANG=en_US passgen -h
```

**Если нужная локализация не найдена, то будет использована английская.**

**man так же доступен на 2-х языках**


```bash
$ man -L ru_RU passgen
$ man -L en_US passgen
```

- - -
## Скорость

Учитывая то, что программа написана на C, можно сказать, что работает очень быстро.

Для сравнения вот однострочная команда на **Bash** и вызов **passgen** с аналогичными параметрами:

```bash
$ time strings /dev/urandom | grep -o '[[:alnum:]]' | head -n 30 | tr -d '\n'; echo
RHAoe9kbZDUDvSk2vgyiwLfFSjWS7S
real    0m0.062s
user    0m0.036s
sys     0m0.056s

$ time passgen -l30 -u -d -n
ht5Qga8GN25D3sjebAQN5MBbUSX2Ka

real    0m0.005s
user    0m0.000s
sys     0m0.004s
```

А теперь повторим опыт и вызовем команду 100 раз подряд:

```bash
$ time for i in {1..100};do strings /dev/urandom | grep -o '[[:alnum:]]' | head -n 30 | tr -d '\n' > /dev/null; done
real    0m8.881s
user    0m1.716s
sys     0m13.604s
$ time passgen -l30 -u -d -n -c100 > /dev/null
real    0m0.059s
user    0m0.004s
sys     0m0.048s
```

И даже миллион строк против 100 **passgen** сгенерировал быстрее в ~5 раз ))) (Выполнения **Bash** команды я так и не дождался и убил процесс)

```bash
$ time passgen -l30 -u -d -n -c1000000 > /dev/null
real    0m1.769s
user    0m1.692s
sys     0m0.072s
```

Как мы видим, генерация строки длиной 30 символов, состоящей из букв и цифр, у **passgen** заняла в разы меньше времени.

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
Usage make:
    make help                          - view this help information
    make                               - build binary from source
    make debug                         - build binary from source with '-DDEBUG=1' option and not 'strip -s' run
    make clean                         - clean project folder of *.o, ./bin, etc.
    make distclean                     - clean project folder of ./configure created files (./*.tmp, ./*.log, etc.)
    make check                         - run binary with test parameters
    make doc                           - generate README.md and manpage files
    sudo make build [install=<yes|no>] - build package. About 'install' options, see the README.md
    sudo make install                  - install binary
    sudo make uninstall                - uninstall binary
```
- - -
![](img.png)

- - -
## Локализация программы

**ВНИМАНИЕ!!! Только для тех, кто понимает что делает!**

В каталоге `./locale` лежат файлы локализации программы.

Если вы меняли что-то в исходниках программы, то чтобы обновить языковые файлы, надо выполнить команду:

```bash
$ ./translate.sh --extract
```

Далее следует отредактировать файлы, путь к которым появится на экране, и выполнить команду:

```bash
$ ./translate.sh --generate
```

Отлично! Теперь можно переустановить пакет с обновленными языковыми файлами.

## Добавить перевод

Чтобы добавить перевод надо создать в каталоге `./locale` папку с именем в формате [ll_CC](https://docs.moodle.org/dev/Table_of_locales) и выполнить команду:

```bash
$ ./translate.sh --extract
```

- - -
## Поддерживаемые ОС

*Программа тестировалась на ОС:*

1. Ubuntu Desktop 14.04

Если найдутся добрые люди, которые протестируют на других ОС и отпишутся по указанному адресу, то я буду очень признателен.
