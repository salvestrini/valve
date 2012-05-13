#
# configure.ac
#
# (C) 2012 Francesco Salvestrini <salvestrini AT gmail DOT com>
#

AC_INIT([valve],
        m4_esyscmd([build-aux/git-version-gen .tarball-version]),
        [salvestrini@gmail.com],
        [valve],
        [github.com/salvestrini/valve])

AC_PREREQ([2.68])

AC_CONFIG_HEADERS([src/config.h])
AC_CONFIG_SRCDIR([src/valve.cc])
AC_CONFIG_AUX_DIR([build-aux])
AC_CONFIG_MACRO_DIR([m4])

AC_CANONICAL_BUILD
AC_CANONICAL_HOST
AC_CANONICAL_TARGET

AM_INIT_AUTOMAKE([1.11.1 foreign std-options no-installman no-installinfo -Wall])

AC_PROG_SED
AC_PROG_GREP
AC_PROG_MKDIR_P
AC_PROG_LN_S

AC_PATH_PROG([SORT], [sort], [/bin/false])
AC_PATH_PROG([UNIQ], [uniq], [/bin/false])
AC_PATH_PROG([GIT],  [git],  [/bin/false])

AC_PATH_PROG([DIFF], [diff], [/bin/false])
AC_PATH_PROG([CUT],  [cut],  [/bin/false])
AC_PATH_PROG([HEAD], [head], [/bin/false])
AC_PATH_PROG([TAIL], [tail], [/bin/false])

AC_PROG_CXXCPP
AC_PROG_CXX
AC_PROG_CXX_C_O
AC_PROG_RANLIB

AC_PATH_PROG([FLEX],  [flex],  [/bin/false])
AC_PATH_PROG([BISON], [bison], [/bin/false])

# Checks
AC_CHECK_HEADERS([getopt.h],,[
    AC_MSG_ERROR([headee getopt.h seems missing])
])
AC_CHECK_FUNCS([getopt_long],,[
    AC_MSG_ERROR([library function gentopt_long seems missing])
])

AC_CONFIG_FILES([
    Makefile

    src/Makefile
    src/ptree/Makefile

    test/Makefile
])

AC_OUTPUT
