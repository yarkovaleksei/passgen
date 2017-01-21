## Сборка и установка

```bash
$ git clone git@github.com:yarkovaleksei/passgen.git
$ cd passgen
$ make
$ sudo make install
```

*При установке программа спросит о перезаписи файла локализации, если он существует.*

**Введите 'y' и нажмите Enter.**

- - -
## Сборка deb пакета

```bash
$ sudo make build
```

- - -
## Использование

```bash
$ passgen -h # Вывод справочной информации
$ passgen # Используем только английские буквы в верхнем и нижнем регистре
JfwZqcfJDArKoZDxpBfadiNkw
$ passgen -l25 # Указываем длину пароля явно
KoZDxcfJDArpBfaJfwZqdiNkw
$ passgen -l25 -d # Добавляем цифры
lgqTBbVKplvL0z4EVuqcIQX4E
$ passgen -l25 -s # Добавляем знаки пунктуации, но не используем цифры
)Jm-\SMw/(Aza#&oty|nH@,J[
$ passgen -l25 -ds # Добавляем знаки пунктуации и цифры
(Fy_[-dS,8$Kfifw[&=V1Dzsh
$ passgen -l25 -ds -c5 # Генерируем список из 5 паролей, по одному на строку
(Fy_[-dS,8$Kfifw[&=V1Dzsh
)Jm-\SMw/(Aza#&oty|nH@,J[
KoZDxcfJDArpBfaJfwZqdiNkw
JfwZqcfJDArKoZDxpBfadiNkw
DxcfJDAf,8$Kfifw[&=V1Dzsh
```

- - -
## Указать явное использование русского языка

```bash
$ LANG=ru_RU ./bin/passgen -h
```

- - -
## Удаление

```bash
$ sudo make uninstall
```

**Если установили собранный deb пакет, то воспользуйтесь этой командой:**

```bash
$ dpkg -r passgen
```
