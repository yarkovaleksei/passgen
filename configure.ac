AC_PREREQ([2.69])
AC_INIT([passgen], [1.0.0], [yarkov_aleksei@mail.ru], [passgen_v1.0.0], [https://github.com/yarkovaleksei/passgen])

PACKAGE_AUTHOR="Yarkov Aleksey"
PACKAGE_DESCRIPTION="Console password generator"
PACKAGE_LICENSE="MIT"
PACKAGE_EMAIL="yarkov_aleksei@mail.ru"
DEFS=" -DHAVE_CONFIG_H"
CURDATE=$(date "+%d %b %Y")

AC_SUBST(PACKAGE_AUTHOR)
AC_SUBST(PACKAGE_DESCRIPTION)
AC_SUBST(PACKAGE_LICENSE)
AC_SUBST(PACKAGE_EMAIL)
AC_SUBST(DEFS)
AC_SUBST(CURDATE)

AC_DEFINE(PACKAGE_AUTHOR, "Yarkov Aleksey", [Define to the package author name])
AC_DEFINE(PACKAGE_DESCRIPTION, "Console password generator", [Define to the package description])
AC_DEFINE(PACKAGE_LICENSE, "MIT", [Define to the package license])

AC_CONFIG_SRCDIR([source/main.c])
AC_CONFIG_HEADER([source/h/config.h:resource/config.h.in])

AC_PROG_CC

# Checks for programs.
#AC_PROG_INSTALL
AC_PROG_MAKE_SET

# Checks for libraries.
#AC_CHECK_LIB([crypt])

AC_CHECK_HEADERS([stdlib.h],
                    [locale.h],
                    [stdarg.h],
                    [unistd.h],
                    [stdio.h],
                    [string.h],
                    [time.h],
                    [libintl.h],
                    [ctype.h],
                    [errno.h],
                    [getopt.h])


AC_CONFIG_FILES([Makefile:resource/make/Makefile.in man/en_US/passgen.1:resource/man/en_US/passgen.1.in man/ru_RU/passgen.1:resource/man/ru_RU/passgen.1.in translate.sh:resource/translate.sh.in])

AC_OUTPUT
