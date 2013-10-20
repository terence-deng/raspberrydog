#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([raspberrydog], [0.2], [deng.tooling@gmail.com])
AM_INIT_AUTOMAKE(raspberrydog, 0.2)
AC_CONFIG_SRCDIR([src/raspberrydog.c])

# Checks for programs.
AC_PROG_CC

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([unistd.h])

# Checks for typedefs, structures, and compiler characteristics.

# Checks for library functions.
AC_CHECK_LIB(wiringPi, wiringPiSetup,,AC_MSG_ERROR(Fail to find wiringPi library))

AC_OUTPUT(Makefile src/Makefile doc/Makefile examples/Makefile man/Makefile scripts/Makefile)
