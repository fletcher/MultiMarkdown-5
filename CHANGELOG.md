# MultiMarkdown Change Log #


## [5.0.1] - 2015-12-01 ##

*	IMPORTANT: Fix major error in last Makefile! (Only in build branch for a few minutes)
*	ADDED: Improve empty list item detection in ODF output
*	CHANGED: Remove unused node creation utilities
*	CHANGED: Update documentation
*	CHANGED: Use 'const' char * in g_string_new
*	CODE: Improve doxygen support in libMultiMarkdown.h
*	CODE: Refactor markdown_to_string() to separate parsing input text and writing output text via the intermediate node tree.
*	CODE: Use node creation shortcuts for consistency and future flexibility
*	FIX: Add 32 bit flag to older MinGW toolchain
*	FIX: Add label for 32 bit builds
*	FIX: Don't run valgrind tests unless in 'make debug' mode
*	FIX: Don't static link when using 'make debug' for valgrind testing
*	FIX: Fix memory leaks in transclude_source()
*	NOTE: Add developer notes to the README information
*	NOTE: Additional doxygen support
*	NOTE: Autogenerate changelog since last commit to master
*	NOTE: Begin tracking release notes in 'CHANGELOG.md'
*	NOTE: Change empty listitem detection logic for ODF output
*	NOTE: Change whitespace for easier diffing
*	NOTE: Remove redundant developer note in README
*	NOTE: Use tab instead of leading spaces in CHANGELOG-UNRELEASED


## [5.0.0] - 2015-11-15 ##

* The source repository for MultiMarkdown has been completely rebuilt:
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



[5.0.0]: https://github.com/fletcher/MultiMarkdown-5/releases/tag/v5.0
[5.0.1]: https://github.com/fletcher/MultiMarkdown-5/releases/tag/v5.0.1
