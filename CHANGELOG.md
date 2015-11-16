# MultiMarkdown Change Log #


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
