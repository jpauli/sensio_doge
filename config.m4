dnl $Id$
dnl config.m4 for extension sensio_doge

dnl Comments in this file start with the string 'dnl'.
dnl Remove where necessary. This file will not work
dnl without editing.

dnl If your extension references something external, use with:

dnl PHP_ARG_WITH(sensio_doge, for sensio_doge support,
dnl Make sure that the comment is aligned:
dnl [  --with-sensio_doge             Include sensio_doge support])

dnl Otherwise use enable:

PHP_ARG_ENABLE(sensio_doge, whether to enable sensio_doge support,
dnl Make sure that the comment is aligned:
[  --enable-sensio_doge           Enable sensio_doge support])

if test "$PHP_SENSIO_DOGE" != "no"; then
  dnl Write more examples of tests here...

  dnl # --with-sensio_doge -> check with-path
  dnl SEARCH_PATH="/usr/local /usr"     # you might want to change this
  dnl SEARCH_FOR="/include/sensio_doge.h"  # you most likely want to change this
  dnl if test -r $PHP_SENSIO_DOGE/$SEARCH_FOR; then # path given as parameter
  dnl   SENSIO_DOGE_DIR=$PHP_SENSIO_DOGE
  dnl else # search default path list
  dnl   AC_MSG_CHECKING([for sensio_doge files in default path])
  dnl   for i in $SEARCH_PATH ; do
  dnl     if test -r $i/$SEARCH_FOR; then
  dnl       SENSIO_DOGE_DIR=$i
  dnl       AC_MSG_RESULT(found in $i)
  dnl     fi
  dnl   done
  dnl fi
  dnl
  dnl if test -z "$SENSIO_DOGE_DIR"; then
  dnl   AC_MSG_RESULT([not found])
  dnl   AC_MSG_ERROR([Please reinstall the sensio_doge distribution])
  dnl fi

  dnl # --with-sensio_doge -> add include path
  dnl PHP_ADD_INCLUDE($SENSIO_DOGE_DIR/include)

  dnl # --with-sensio_doge -> check for lib and symbol presence
  dnl LIBNAME=sensio_doge # you may want to change this
  dnl LIBSYMBOL=sensio_doge # you most likely want to change this 

  dnl PHP_CHECK_LIBRARY($LIBNAME,$LIBSYMBOL,
  dnl [
  dnl   PHP_ADD_LIBRARY_WITH_PATH($LIBNAME, $SENSIO_DOGE_DIR/lib, SENSIO_DOGE_SHARED_LIBADD)
  dnl   AC_DEFINE(HAVE_SENSIO_DOGELIB,1,[ ])
  dnl ],[
  dnl   AC_MSG_ERROR([wrong sensio_doge lib version or lib not found])
  dnl ],[
  dnl   -L$SENSIO_DOGE_DIR/lib -lm
  dnl ])
  dnl
  dnl PHP_SUBST(SENSIO_DOGE_SHARED_LIBADD)

  PHP_NEW_EXTENSION(sensio_doge, sensio_doge.c, $ext_shared)
fi
