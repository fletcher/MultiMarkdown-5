latex input:  mmd-tufte-handout-header  
Title:  Version 5.1 Release Notes  
Author: Fletcher T. Penney  
Version:  {{version.txt}}  
Revised:  2016-02-22  
Base Header Level:  2  
CSS:  {{css.txt}}  
MMD Footer: meta-links.txt  
latex mode: memoir  
latex input:  mmd-tufte-handout-begin-doc  
latex footer: mmd-tufte-footer  


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


[5.0.0]: https://github.com/fletcher/MultiMarkdown-5/releases/tag/5.0
[5.0.1]: https://github.com/fletcher/MultiMarkdown-5/releases/tag/5.0.1
[5.1.0]: https://github.com/fletcher/MultiMarkdown-5/releases/tag/5.1.0
