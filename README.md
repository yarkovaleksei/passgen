# Password Generator

### Попытался освоить C на досуге и вот наваял такой консольный генератор паролей.

- - -
**Сборка и установка:**

```bash
$ cd path/to/dir/with/cloned/passgen
$ make
$ make install
```

- - -
**Использование:**

```bash
$ passgen -h # Вывод справочной информации
$ passgen -l25 # Используем только английские буквы в верхнем и нижнем регистре
KoZDxcfJDArpBfaJfwZqdiNkw
$ passgen -l25 -d # Добавляем цифры
lgqTBbVKplvL0z4EVuqcIQX4E
$ passgen -l25 -s # Добавляем знаки пунктуации, но не используем цифры
)Jm-\SMw/(Aza#&oty|nH@,J[
$ passgen -l25 -ds # Добавляем знаки пунктуации и цифры
(Fy_[-dS,8$Kfifw[&=V1Dzsh
```

- - -
**Удаление:**

```bash
$ cd path/to/dir/with/cloned/passgen
$ make uninstall
```
