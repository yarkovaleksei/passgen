# Password Generator

- - -
### Попытался освоить C на досуге и вот наваял такой консольный генератор паролей.

- - -
## Сборка и установка

```bash
$ git clone https://github.com/yarkovaleksei/passgen.git
$ cd passgen
$ make
$ sudo make install
```

- - -
## Сборка deb пакета

```bash
$ sudo make build
```

- - -
## Установка deb пакета

```bash
$ sudo dpkg -i ./deb/*.deb
```

- - -
## Использование

```bash
$ passgen -h
Консольный генератор паролей

Параметры по-умолчанию:
	Используемые символы: ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz
	Длина пароля:         25

Используемые ключи:
	-h, --help      Справочная информация
	-v, --version   Номер версии релиза
	-l, --length    Длина пароля. Если не указан, то
	                он будет установлен в 25. Если указать 0,
	                то программа запросит ввод с клавиатуры.
	-c, --count     Количество паролей за один раз.
	                Полезно, когда надо сгенерировать
	                файл с уникальными строками.
	-d, --digest    Добавляет цифры к паролю
	-s, --symbol    Добавляет знаки пунктуации к паролю

Примеры использования:
	$ passgen -l25      # Только английские буквы в верхнем и нижнем регистре
	$ passgen -l25 -d   # Добавляем цифры
	$ passgen -l25 -s   # Добавляем знаки пунктуации, но не используем цифры
	$ passgen -l25 -ds  # Добавляем знаки пунктуации и цифры
	$ passgen -l25 -c5  # Список из 5 паролей, по одному в строке
```

- - -
## Указать явное использование языка

*Поддерживается русская и английская локализация*

```bash
$ LANG=ru_RU ./bin/passgen -h
$ LANG=en_US ./bin/passgen -h
```

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
 make 				- build binary file from source
 make clean 			- clean project folder from *.o, ./bin, etc.
 make test 			- run binary with test parameters
 make elang 			- extract localize phrases from source to *.po
 make glang 			- create localize *.mo file from *.po files
 make autodoc 		- generate README.md
 sudo make build 	- build deb package
 sudo make install 	- install binary to /usr/local/bin
 sudo make uninstall - uninstall binary from /usr/local/bin
```
