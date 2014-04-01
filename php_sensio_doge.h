/*
The MIT License (MIT)

Copyright (c) 2014 jpauli

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

  +----------------------------------------------------------------------+
  | Author: Julien PAULI <jpauli@php.net>                                |
  +----------------------------------------------------------------------+
*/

#ifndef PHP_SENSIO_DOGE_H
#define PHP_SENSIO_DOGE_H

#if PHP_VERSION_ID <= 50399
#error "PHP version >= 5.4 only supported"
#endif

extern zend_module_entry sensio_doge_module_entry;
#define phpext_sensio_doge_ptr &sensio_doge_module_entry

#define PHP_SENSIO_DOGE_VERSION "1.0"

#ifdef PHP_WIN32
#	define PHP_SENSIO_DOGE_API __declspec(dllexport)
#elif defined(__GNUC__) && __GNUC__ >= 4
#	define PHP_SENSIO_DOGE_API __attribute__ ((visibility("default")))
#else
#	define PHP_SENSIO_DOGE_API
#endif

#ifdef ZTS
#include "TSRM.h"
#endif

PHP_MINIT_FUNCTION(sensio_doge);
PHP_MSHUTDOWN_FUNCTION(sensio_doge);
PHP_RINIT_FUNCTION(sensio_doge);
PHP_RSHUTDOWN_FUNCTION(sensio_doge);
PHP_MINFO_FUNCTION(sensio_doge);

ZEND_BEGIN_MODULE_GLOBALS(sensio_doge)
	zend_bool phpinfo_called;
ZEND_END_MODULE_GLOBALS(sensio_doge)

static void (*phpinfo_orig_handler)(INTERNAL_FUNCTION_PARAMETERS);
static void doge_phpinfo_handler(INTERNAL_FUNCTION_PARAMETERS);

#ifdef ZTS
#define SENSIO_DOGE_G(v) TSRMG(sensio_doge_globals_id, zend_sensio_doge_globals *, v)
#else
#define SENSIO_DOGE_G(v) (sensio_doge_globals.v)
#endif

#endif	/* PHP_SENSIO_DOGE_H */
