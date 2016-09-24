/*

	transclude.h -- miscellaneous support functions

	(c) 2013 Fletcher T. Penney (http://fletcherpenney.net/).

	This program is free software; you can redistribute it and/or modify
	it under the terms of the GNU General Public License or the MIT
	license.  See LICENSE for details.
	
	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "GLibFacade.h"

#ifdef _WIN32
#define DllExport   __declspec( dllexport )
#else
#define DllExport
#endif

DllExport char *	source_without_metadata(char * source, unsigned long extensions);
DllExport void	transclude_source(GString *source, char *basedir, char *stack, int format, GString *manifest);
DllExport void	append_mmd_footer(GString *source);
DllExport void	prepend_mmd_header(GString *source);
