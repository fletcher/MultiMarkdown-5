latex input:  mmd-tufte-handout-header  
Title:  Version 4.7 Release Notes  
Author: Fletcher T. Penney  
Version:  {{version.txt}}  
Revised:  2015-11-12  
Base Header Level:  2  
CSS:  {{css.txt}}  
MMD Footer: meta-links.txt  
latex mode: memoir  
latex input:  mmd-tufte-handout-begin-doc  
latex footer: mmd-tufte-footer  

## 5.0 ##

* The source repository for MultiMarkdown has been completely rebuit:
	* Use my [c-template] to provide the basic structure
	* Requires the [CMake] build system
	* Has the beginnings of documentation within the code to support
		[Doxygen]-generated developer documentation
* Other changes since 4.7.1:
	* Improvements from Matthias Lohr for the shell scripts
	* Additional documentation in code
	* Fix issue with whitespace after footnotes in ODF export
	* Improve accuracy of recognizing single line code blocks
	* Fix memory leaks
	* Fix `mmd2pdf` for certain installs of TeX on El Capitan
	* Improve POSIX compliance on shell scripts
	* Improve accuracy of strong/emph matching
	* Make reference label matching case insensitive
	* Fix error if no caption was included on table
	* Fix edge case slowdown when lots of HTML included
	* Fix error when quotes included in explicit link
	* Allow tables inside LaTeX footnotes
	* Improved window path separator support
	* And other improvements/fixes


### Why switch to CMake? ###

In early 2014, a user of MMD introduced me to the [CMake] build system. I 
looked at it briefly, but didn't do anything with it.  Later on, I looked
at it more in depth and created a parallel branch after 4.6.  This would allow
me to experiment with CMake without breaking anything else in the `master`
branch.

CMake isn't perfect by any means, but it does allow for some interesting
things:

*	Automatically generate GUI installers for OS X and Windows, as well as zip
	files for *nix.  I have not looked into using CMake to build `.deb`
	packages, but that might be possible as well.  My old system could generate
	GUI installers for Windows and OS X, but it was a complex process that
	required a lot of manual processing.  This is much more amenable to
	automation.
*	An improved organization structure for various tests, including [Valgrind]
	testing.  The old system was getting rather messy.
*	A templating system that better allows me to synchronize version, and
	other, information in code, documentation, and READMEs
*	Automatic generation of project files for Xcode, Visual Studio, and
	alternative build systems beyond `make`
*	An opportunity to reorganize my code directory hierarchy
*	The option to start adding unit test code to the source.  This probably
	won't happen, as it would be too much work.  But it is possible.


The biggest *problem* is that this means that anyone wishing to compile the
source will need to install CMake.  This isn't hard, but it is an extra step.

As a temporary measure, you can use the `make deprecated` command to use a 
simplified `make` recipe to compile a binary of MultiMarkdown for the current
machine.  I don't recommend this approach, but it should work in a pinch until
you can upgrade your machine to support cmake.

I welcome feedback on this decision, but please note -- "I don't like it" or
"bring back the old way" comments will be ignored.  Please send meaningful
criticism or suggestions.

Perhaps an approach if others want to contribute will be to do the reverse of
what I did before -- create a `make` branch that includes a modified Makefile
designed to be used without CMake?

Additionally, the old Makefile had grown over time to include some tricks that
users of various systems required.  I have tested the CMake system on OS X,
Ubuntu and Debian Linux, and MinGW on Ubuntu.  I welcome suggestions for
improvements to the CMake configuration.


[c-template]: https://github.com/fletcher/c-template
[CMake]: https://cmake.org/
[Doxygen]: http://www.doxygen.org/
[Valgrind]: http://valgrind.org/
