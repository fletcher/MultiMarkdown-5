/**

	MultiMarkdown - lightweight markup processor

	@file libMultiMarkdown.h

	@brief MultiMarkdown library header

	libMultiMarkdown.h provides the key commands to convert raw MultiMarkdown
	text into a desired export format.

	For most simple uses, the main API commands provided here are sufficient.
	For more complex scenarios, however, you may need to handle file
	transclusion which requires knowledge about the location of the source
	file in order to appropriately handle relative links.  In this case, you
	may benefit from examining multimarkdown.c.

	@author	Fletcher T. Penney
	@bug	No known bugs

**/

/*

	Copyright © 2013-2015 Fletcher T. Penney.


	The `c-template` project is released under the MIT License.
	
	
	MMD 5 is released under the MIT License.
	
	
	CuTest is released under the zlib/libpng license. See CuTest.c for the text
	of the license.
	
	
	## The MIT License ##
	
	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:
	
	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.
	
	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
	THE SOFTWARE.

*/


/* Main API commands */

/// Convert source string to output string, based on provided `parser_extensions`
/// and requested `export_format`.
/// The returned `char *` will need to be freed after it is no longer needed.
char * markdown_to_string(const char * source, unsigned long extensions, int format);

/// Does the source string have metadata, using provided `parser_extensions`?
///
bool   has_metadata(const char *source, unsigned long extensions);

/// List all metadata keys, using provided `parser_extensions`.
/// The returned `char *` will need to be freed after it is no longer needed.
char * extract_metadata_keys(const char *source, unsigned long extensions);

/// Extract the value for the specified metadata key, using provided `parser_extensions`.
/// The returned `char *` will need to be freed after it is no longer needed.
char * extract_metadata_value(const char *source, unsigned long extensions, char *key);

/// Return the version string for this build of libMultiMarkdown
/// The returned `char *` will need to be freed after it is no longer needed.
char * mmd_version(void);


/* These are the basic extensions */
enum parser_extensions {
	EXT_COMPATIBILITY       = 1 << 0,    /* Markdown compatibility mode */
	EXT_COMPLETE            = 1 << 1,    /* Create complete document */
	EXT_SNIPPET             = 1 << 2,    /* Create snippet only */
	EXT_HEAD_CLOSED         = 1 << 3,    /* for use by parser */
	EXT_SMART               = 1 << 4,    /* Enable Smart quotes */
	EXT_NOTES               = 1 << 5,    /* Enable Footnotes */
	EXT_NO_LABELS           = 1 << 6,    /* Don't add anchors to headers, etc. */
	EXT_FILTER_STYLES       = 1 << 7,    /* Filter out style blocks */
	EXT_FILTER_HTML         = 1 << 8,    /* Filter out raw HTML */
	EXT_PROCESS_HTML        = 1 << 9,    /* Process Markdown inside HTML */
	EXT_NO_METADATA         = 1 << 10,   /* Don't parse Metadata */
	EXT_OBFUSCATE           = 1 << 11,   /* Mask email addresses */
	EXT_CRITIC              = 1 << 12,   /* Critic Markup Support */
	EXT_CRITIC_ACCEPT       = 1 << 13,   /* Accept all proposed changes */
	EXT_CRITIC_REJECT       = 1 << 14,   /* Reject all proposed changes */
	EXT_RANDOM_FOOT         = 1 << 15,   /* Use random numbers for footnote links */
	EXT_HEADINGSECTION      = 1 << 16,   /* Group blocks under parent heading */
	EXT_ESCAPED_LINE_BREAKS = 1 << 17,   /* Escaped line break */
	EXT_NO_STRONG           = 1 << 18,   /* Don't allow nested <strong>'s */
	EXT_NO_EMPH             = 1 << 19,   /* Don't allow nested <emph>'s */
	EXT_FAKE                = 1 << 31,   /* 31 is highest number allowed */
};

/* Define output formats we support -- first in list is default */
enum export_formats {
	ORIGINAL_FORMAT,                /* Transclusion happens, but no parsing */
	HTML_FORMAT,                    /* Well supported */
	TEXT_FORMAT,                    /* Not currently used, may exit host process */
	LATEX_FORMAT,
	MEMOIR_FORMAT,
	BEAMER_FORMAT,
	OPML_FORMAT,
	ODF_FORMAT,
	RTF_FORMAT,                     /* Not recommended for production code, may crash */
	CRITIC_ACCEPT_FORMAT,
	CRITIC_REJECT_FORMAT,
	CRITIC_HTML_HIGHLIGHT_FORMAT,
	LYX_FORMAT,                     /* Not actively developed */
	TOC_FORMAT,
};

/* These are the identifiers for node types */
enum keys {
	NO_TYPE,
	LIST,
	STR,
	APOSTROPHE,
	FOOTER,
	PARA,
	PLAIN,
	LINEBREAK,
	SPACE,
	HEADINGSECTION,
	H1, H2, H3, H4, H5, H6, H7,	/* Keep these in order */
	METADATA,
	METAKEY,
	METAVALUE,
	MATHSPAN,
	STRONG,
	EMPH,
	LINK,
	SOURCE,
	TITLE,
	REFNAME,
	AUTOLABEL,
	IMAGE,
	IMAGEBLOCK,
	NOTEREFERENCE,
	CODE,
	HTML,
	ELLIPSIS,
	ENDASH,
	EMDASH,
	SINGLEQUOTED,
	DOUBLEQUOTED,
	BLOCKQUOTE,
	BLOCKQUOTEMARKER,
	RAW,
	VERBATIM,
	VERBATIMTYPE,
	VERBATIMFENCE,
	DEFLIST,
	TERM,
	DEFINITION,
	HRULE,
	ORDEREDLIST,
	BULLETLIST,
	LISTITEM,
	HTMLBLOCK,
	TABLE,
	TABLECAPTION,
	TABLELABEL,
	TABLESEPARATOR,
	TABLECELL,
	CELLSPAN,
	TABLEROW,
	TABLEBODY,
	TABLEHEAD,
	LINKREFERENCE,
	NOTESOURCE,
	CITATIONSOURCE,
	SOURCEBRANCH,
	NOTELABEL,
	GLOSSARYLABEL,
	ATTRVALUE,
	ATTRKEY,
	GLOSSARYSOURCE,
	GLOSSARYSORTKEY,
	GLOSSARYTERM,
	CITATION,
	NOCITATION,
	CRITICADDITION,
	CRITICDELETION,
	CRITICSUBSTITUTION,
	CRITICHIGHLIGHT,
	CRITICCOMMENT,
	SUPERSCRIPT,
	SUBSCRIPT,
	VARIABLE,
	ABBREVIATION,
	ABBR,
	ABBRSTART,
	ABBRSTOP,
	TOC,
	KEY_COUNTER                      /* This *MUST* be the last item in the list */
};


/* This is the element used in the resulting parse tree */
struct node {
	short             key;           /* what type of element are we? */
	char              *str;          /* relevant string from source for element */
	struct link_data  *link_data;    /* store link info when relevant */
	struct node       *children;     /* child elements */
	struct node       *next;         /* next element */
};

typedef struct node node;


/* Define a structure to simplify handling of links */
struct link_data {
	char *label;                /* if this is a reference link */
	char *source;               /* source URL     */
	char *title;                /* title string   */
	node *attr;                 /* attribute tree */
};

typedef struct link_data link_data;
