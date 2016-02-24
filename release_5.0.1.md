latex input:  mmd-tufte-handout-header  
Title:  Version 5.0.1 Release Notes  
Author: Fletcher T. Penney  
Version:  {{version.txt}}  
Revised:  2015-12-01  
Base Header Level:  2  
CSS:  {{css.txt}}  
MMD Footer: meta-links.txt  
latex mode: memoir  
latex input:  mmd-tufte-handout-begin-doc  
latex footer: mmd-tufte-footer  


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



[5.0.0]: https://github.com/fletcher/MultiMarkdown-5/releases/tag/5.0
[5.0.1]: https://github.com/fletcher/MultiMarkdown-5/releases/tag/5.0.1
[5.1.0]: https://github.com/fletcher/MultiMarkdown-5/releases/tag/5.1.0
