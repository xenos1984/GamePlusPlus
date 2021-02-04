AC_INIT([GamePlusPlus], [1.0.0], [https://github.com/xenos1984/GamePlusPlus/issues])

AC_CONFIG_AUX_DIR([config])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_HEADERS([config.h])

AM_INIT_AUTOMAKE([foreign])

: ${CXXFLAGS="-O3 -Wall -Wextra -Wpedantic"}

# Checks for programs.
AC_PROG_CXX
AC_PROG_LIBTOOL

# Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_SIZE_T

LT_INIT

AC_CONFIG_FILES([
	Makefile
	app/Makefile
	app/puzzler/Makefile
])
AC_OUTPUT
