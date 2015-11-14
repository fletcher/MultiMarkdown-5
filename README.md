## About ##

|            |                           |  
| ---------- | ------------------------- |  
| Title:     | MultiMarkdown        |  
| Author:    | Fletcher T. Penney       |  
| Date:      | 2015-11-12 |  
| Copyright: | Copyright © 2013-2015 Fletcher T. Penney.    |  
| Version:   | 5.0.0      |  


## Introduction ##

[Markdown] is a simple markup language used to convert plain text into HTML. 

[MultiMarkdown] is a derivative of Markdown that adds new syntax features, such as footnotes, tables, and metadata. Additionally, it offers mechanisms to convert plain text into LaTeX in addition to HTML. 


## Background ##

MultiMarkdown started as a Perl script, which was modified from the original Markdown.pl.

MultiMarkdown v3 (aka 'peg-multimarkdown') was based on John MacFarlane's [peg-markdown].  It used a parsing expression grammar (PEG), and was written in C in order to compile on almost any operating system.  Thanks to work by Daniel Jalkut, MMD v3 was built so that it didn't have any external library requirements.

MultiMarkdown v4 was basically a complete rewrite of v3.  It used the same basic PEG for parsing (Multi)Markdown text, but otherwise was almost completely rebuilt.

MultiMarkdown v5 is basically the same code as v4, but the project has been restructured:

*	It is designed with the CMake build system, rather than just
	a Makefile


## Download Binary ##



## Compile from Source ##

To compile MultiMarkdown, you will need to have [CMake] installed on your machine.

To download the source:

*	Obtain the source from the github page:

		git clone https://github.com/fletcher/MultiMarkdown-5.git

*	Configure the submodules with two helper scripts (This can be done manually on Windows systems by looking at the source):

		./link_git_modules
		./update_git_modules

*	Compile, and (optionally) test:

		make
		cd build
		make
		make test

Like all versions of MultiMarkdown since v3, there is one test that will fail (now helpfully called `markdown-should-fail`).  The other tests should pass.  The valgrind tests will not work on OS X, but should pass if valgrind is installed and used on Linux machines.

If you want to make an installer, after the above, use the `cpack` command inside the build directory.

For more information, checkout the `IMPORTANT` file.


## Usage ##

The [MultiMarkdown Composer User's Guide] has complete instructions on how to use MultiMarkdown.


## Developer's Notes ##

The [Documentation], created by doxygen, has information for developers:

	make documentation

You can then view `build/documentation/html/index.html` for some developer's notes.  There's not a lot there yet.  There is also a LaTeX version created if you want a PDF.  Just use latexmk in the latex directory.


# LyX Support #

Charles R. Cowan (<https://github.com/crcowan>) added support for conversion to [LyX](http://www.lyx.org/).  Support for this should be considered to be in alpha/beta, and is not guaranteed.  Issues related to LyX can be added to the MultiMarkdown [issues] page on github, but will need to be answered by Charles.  I am happy to include this code in the main MMD repo, but since I don't use LyX I can't support it myself.  If this arrangement becomes a problem, then LyX support can be removed and it can be kept as a separate fork.


# More Information #

To get more information about MultiMarkdown, check out the [website][MultiMarkdown] or [User's Guide].

## License ##

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



[Markdown]:	http://daringfireball.net/projects/markdown/
[MultiMarkdown]:	http://fletcherpenney.net/multimarkdown/
[MultiMarkdown User's Guide]:	http://fletcher.github.io/MultiMarkdown-5/

