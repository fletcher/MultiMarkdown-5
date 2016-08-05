# MultiMarkdown Change Log #

## [5.4.0] - 2016-08-05

*	ADDED: Add email address to cpack settings (addresses #31)
*	ADDED: Move static library options to separate make target
*	CHANGED: Increase list of syntax structures that are evaluated for abbreviations (Thanks, David!)
*	CHANGED: Update README
*	FIXED: Avoids problem mentioned on github (#30), but doesn't actually solve it. Any help appreciated!
*	FIXED: Fix crash with empty table label


## [5.3.0] - 2016-06-08 ##

*	CHANGED: Update test suite
*	FIXED: Don't allow math spans inside strong/emph
*	FIXED: Fix additional edge case in emph/strong parser
*	FIXED: Fix slow parsing of complex strong/emph (Fixes #18)
*	FIXED: Improve accuracy and performance of strong/emph
*	FIXED: Improve performance


## [5.2.0] - 2016-03-16 ##

*	ADDED: Add additional test cases
*	ADDED: Add support for 'HTML FOOTER' metadata -- appended at very end of HTML documents (after footnotes)
*	CHANGED: Allow nested strong/emph spans (though effect of output is not defined for all formats)
*	CHANGED: Update Math test suite
*	CHANGED: Update documentation for 5.1.0
*	CHANGED: Update documentation for HTML Footer metadata
*	CHANGED: Update test suite
*	CHANGED: recursive support for CriticMarkup syntax (e.g. an addition can be included inside a substitution).
*	FIXED: Fix bug in handling of '$' delimited math
*	FIXED: Improve accuracy of strong/emph parsing;
*	FIXED: Remove debugging statement in recent CriticMarkup changes


## [5.1.0] - 2016-02-22 ##

*	ADDED: Add script to build drag and drop apps on OS X
*	ADDED: Beginning code for public header file support; ADDED: Beginning configuration for OS X Bundle/Framework targets
*	ADDED: Include support for Xcode libraries to be iOS compatible
*	CHANGED: Update copyright info for 2016
*	CHANGED: Update test suite
*	FIXED: Allow ATX Headers inside lists
*	FIXED: Allow 'naturally' aligned table cells like MMD 2 allowed
*	FIXED: Allow metadata variables inside links (e.g. [[%foo]][bar])
*	FIXED: Allow newline inside strong/emph (Fixes #10)
*	FIXED: Change handling of version.h file for deprecated make to keep it separate from cmake alternative
*	FIXED: Don't delete src/version.h
*	FIXED: Fix problem with strong/emph matching incorrectly
*	FIXED: Fix regression in list/heading fix that was overeager
*	FIXED: Include 'fake' version.h for make deprecate
*	FIXED: Include additional standard metadata keys in the list to *not* be included in HTML headers
*	FIXED: Remove unneeded install directive; FIXED: Fix public header install prefix (I think)
*	FIXED: Update MMD test suite for recent table alignment change
*	FIXED: fix 'make deprecate' so that it truly doesn't require cmake
*	FIXED: Improve tight vs loose list detection with unusual setext headers
*	NOTE: Fixed git clone instructions in documentation
*	NOTE: Update test suite


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



[5.0.0]: https://github.com/fletcher/MultiMarkdown-5/releases/tag/5.0
[5.0.1]: https://github.com/fletcher/MultiMarkdown-5/releases/tag/5.0.1
[5.1.0]: https://github.com/fletcher/MultiMarkdown-5/releases/tag/5.1.0
[5.2.0]: https://github.com/fletcher/MultiMarkdown-5/releases/tag/5.2.0
[5.3.0]: https://github.com/fletcher/MultiMarkdown-5/releases/tag/5.3.0
[5.4.0]: https://github.com/fletcher/MultiMarkdown-5/releases/tag/5.4.0
