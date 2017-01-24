AC_PREREQ([2.69])
AC_INIT([passgen], [1.0.0], [yarkov_aleksei@mail.ru], [passgen_v1.0.0], [https://github.com/yarkovaleksei/passgen])

PACKAGE_AUTHOR="Yarkov Aleksey"
PACKAGE_DESCRIPTION="Console password generator"
PACKAGE_LICENSE="MIT"
DEFS=" -DHAVE_CONFIG_H"
CURDATE=$(date "+%d %b %Y")

AC_SUBST(PACKAGE_AUTHOR)
AC_SUBST(PACKAGE_DESCRIPTION)
AC_SUBST(PACKAGE_LICENSE)
AC_SUBST(DEFS)
AC_SUBST(CURDATE)

AC_DEFINE(PACKAGE_AUTHOR, "Yarkov Aleksey", [Define to the package author name])
AC_DEFINE(PACKAGE_DESCRIPTION, "Console password generator", [Define to the package description])
AC_DEFINE(PACKAGE_LICENSE, "MIT", [Define to the package license])
AC_DEFINE(PACKAGE_LOCALE_DIR, "locale", [Define to the dirname with locale files])

AC_CONFIG_SRCDIR([source/main.c])
AC_CONFIG_HEADER([source/h/config.h:resource/in/config.h.in])

AC_PROG_CC

# Checks for programs.
#AC_PROG_INSTALL
AC_PROG_MAKE_SET

# Checks for libraries.
#AC_CHECK_LIB([crypt])

AC_CHECK_HEADERS([stdlib.h],
                    [locale.h],
                    [getopt.h],
                    [stdarg.h],
                    [unistd.h],
                    [stdio.h],
                    [string.h],
                    [time.h],
                    [libintl.h])

AC_CHECK_HEADER([crypt.h],
                [AC_DEFINE([HAVE_LIBLIBCRYPT], 1,
                    [Define to 1 if you have <crypt.h>.])],
                [AC_MSG_ERROR([Sorry, please install libcrypt-dev before compilation!])])

AC_CONFIG_FILES([Makefile:resource/in/Makefile.in man/passgen.1:resource/in/passgen.1.in])
AC_OUTPUT
