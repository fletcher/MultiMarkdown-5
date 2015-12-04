cmake_minimum_required (VERSION 2.6)


# ==================
# Define Our Project
# ==================

set (My_Project_Title "MultiMarkdown")
set (My_Project_Description "MultiMarkdown - lightweight markup processor")
set (My_Project_Author "Fletcher T. Penney")
set (My_Project_Revised_Date "2015-12-01")
set (My_Project_Version_Major 5)
set (My_Project_Version_Minor 0)
set (My_Project_Version_Patch 1)

set (My_Project_Version "${My_Project_Version_Major}.${My_Project_Version_Minor}.${My_Project_Version_Patch}")

set (My_Project_Copyright_Date "2013-2015")
set (My_Project_Copyright "Copyright © ${My_Project_Copyright_Date} ${My_Project_Author}.")

project (${My_Project_Title})


# Search for included files here
include_directories( ${PROJECT_SOURCE_DIR}/src )
include_directories( ${PROJECT_SOURCE_DIR}/test )
include_directories(${PROJECT_BINARY_DIR})

string(TOUPPER ${My_Project_Title} My_Project_Title_Caps  )
string(REGEX REPLACE " " "_" My_Project_Title_Caps ${My_Project_Title_Caps} )


# =================
# Macro Definitions
# =================

MACRO(ADD_PUBLIC_HEADER target filename)
	# Add filename to public_header_files list, flag it as 
	# public header for libraries and OS X Frameworks

	# This will work for creating one library/framework with public headers
	# per project. If you need more than one, you will need to customize
	# the workflow as appropriate, since there is only one 
	# public_header_files list.

	SET_TARGET_PROPERTIES(${target} PROPERTIES PUBLIC_HEADER ${filename})

	LIST(APPEND public_header_files ${filename})

	SET_SOURCE_FILES_PROPERTIES(
		${filename}
		PROPERTIES
		MACOSX_PACKAGE_LOCATION
		PUBLIC_HEADER
	)

	# Set Xcode project to configure public header location to allow
	# use when this project is used in another workspace.
	# NOTE: You must manually add a "Headers" build phase and add
	# the desired public headers to that list for Xcode to use them.
	#
	# TODO: If anyone knows how to automate that in Cmake, I would be very
	# greatful!!

	SET_TARGET_PROPERTIES(${target} PROPERTIES
		XCODE_ATTRIBUTE_PUBLIC_HEADERS_FOLDER_PATH
		"include/$(TARGET_NAME)"
	)

	SET_TARGET_PROPERTIES(${target} PROPERTIES
		XCODE_ATTRIBUTE_PRIVATE_HEADERS_FOLDER_PATH
		"$(PUBLIC_HEADERS_FOLDER_PATH)/Private"
	)
	
	# Set Xcode target to include settings for OS X and iOS
	
	SET_TARGET_PROPERTIES(${target} PROPERTIES
		XCODE_ATTRIBUTE_SUPPORTED_PLATFORMS
		"macos iphonesimulator iphoneos"
	)

	SET_TARGET_PROPERTIES(${target} PROPERTIES
		XCODE_ATTRIBUTE_VALID_ARCHITECTURES
		"x86_64 i386 armv6 armv7 armv7s arm64"
	)

ENDMACRO(ADD_PUBLIC_HEADER)


# The target should be an OS X Bundle with a PList

MACRO(MAKE_TARGET_BUNDLE targetname)

	set_target_properties(
		${targetname}
		PROPERTIES
		MACOSX_BUNDLE_INFO_PLIST
		${PROJECT_SOURCE_DIR}/templates/plist.in
	)

ENDMACRO(MAKE_TARGET_BUNDLE)


MACRO(ADD_LINKED_FRAMEWORK frame)

	SET(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGES} -framework ${frame}")

ENDMACRO(ADD_LINKED_FRAMEWORK)


# ======================
# Process Template Files
# ======================

file(READ ${PROJECT_SOURCE_DIR}/LICENSE.txt My_Project_License)

string(REGEX REPLACE "\n" "\n\t" My_Project_License_Indent ${My_Project_License})

configure_file (
	"${PROJECT_SOURCE_DIR}/templates/template.c.in"
	"${PROJECT_BINARY_DIR}/template.c"
)

configure_file (
	"${PROJECT_SOURCE_DIR}/templates/template.h.in"
	"${PROJECT_BINARY_DIR}/template.h"
)

# Update the project README, to pull in new version #, etc.
configure_file (
	"${PROJECT_SOURCE_DIR}/templates/README.md.in"
	"${CMAKE_CURRENT_LIST_DIR}/README.md"
)

configure_file (
	"${PROJECT_SOURCE_DIR}/templates/version.h.in"
	"${PROJECT_BINARY_DIR}/version.h"
)

if (DEFINED VERSION_ONLY)
	return ()
endif ()


# ============
# Source Files
# ============

# Need to build parser.c via greg
add_custom_command (
	OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/parser.c
	COMMAND ${PROJECT_SOURCE_DIR}/submodules/greg/greg -o ${CMAKE_CURRENT_BINARY_DIR}/parser.c ${PROJECT_SOURCE_DIR}/src/parser.leg
)

# src_files are the primary files, and will be included in doxygen documentation
set(src_files
)

# Primary header files, also for doxygen documentation
set(header_files
	src/libMultiMarkdown.h
)

# Public headers, will be installed in 'include'
# Do not manually add files here, use the ADD_PUBLIC_HEADER() macro
set(public_header_files
)

# Utility source files will not be included in doxygen
set(src_utility_files
	src/GLibFacade.c
	src/beamer.c
	src/critic.c
	src/html.c
	src/latex.c
	src/lyx.c
	src/lyxbeamer.c
	src/memoir.c
	src/odf.c
	src/opml.c
	src/parse_utilities.c
	src/rng.c
	src/rtf.c
	src/text.c
	src/toc.c
	src/transclude.c
	src/writer.c

	${CMAKE_CURRENT_BINARY_DIR}/parser.c
)

set(header_utility_files
	src/GLibFacade.h
	${PROJECT_BINARY_DIR}/version.h
	src/beamer.h
	src/critic.h
	src/glib.h
	src/html.h
	src/latex.h
	src/lyx.h
	src/lyxbeamer.h
	src/memoir.h
	src/odf.h
	src/opml.h
	src/parser.h
	src/rtf.h
	src/text.h
	src/toc.h
	src/transclude.h
	src/writer.h
)

set(scripts
	scripts/mmd
	scripts/mmd2all
	scripts/mmd2opml
	scripts/mmd2rtf
	scripts/mmd2odf
	scripts/mmd2pdf
	scripts/mmd2tex
	scripts/markdown
)

# Generate doxygen configuration file
string(REPLACE ";" " " doxygen_src_files "${src_files} src/multimarkdown.c" )
string(REPLACE ";" " " doxygen_header_files "${header_files}" )

configure_file (
	"${PROJECT_SOURCE_DIR}/templates/doxygen.conf.in"
	"${PROJECT_BINARY_DIR}/doxygen.conf"
)


# ===========================================
# Build Test Suite with CuTest (unit testing)
# ===========================================

set(test_files
	test/CuTest.c
	test/CuTest.h
	${PROJECT_BINARY_DIR}/AllTests.c
)

if (DEFINED TEST)
	add_definitions(-DTEST)

	add_executable(run_tests
		${test_files}
		${src_files}
		${header_files}
		${src_utility_files}
		${header_utility_files}
	)

	# Process source files to look for tests to run
	add_custom_command (
		OUTPUT ${PROJECT_BINARY_DIR}/AllTests.c
		COMMAND sh ${PROJECT_SOURCE_DIR}/test/make-tests.sh ${PROJECT_SOURCE_DIR}/src/*.c > ${PROJECT_BINARY_DIR}/AllTests.c
	)

	enable_testing()

	add_test( test ${PROJECT_BINARY_DIR}/run_tests)

	# valgrind memory testing
	find_program (MEMORYCHECK_COMMAND valgrind)
	SET (MEMORYCHECK_COMMAND_OPTIONS --leak-check=full --error-exitcode=1)

	add_test( memory_test ${MEMORYCHECK_COMMAND} ${MEMORYCHECK_COMMAND_OPTIONS} ${PROJECT_BINARY_DIR}/run_tests)

endif()


# =======================
# Configure for Target OS
# =======================

# OS X Builds
if (APPLE)

	# Configure backwards-compatible support (if your project allows it)
	SET(CMAKE_OSX_DEPLOYMENT_TARGET "10.4" CACHE STRING "Deployment target for OSX" FORCE)

	# Compile for x86_64 and i386.  ppc no longer supported
	if(CMAKE_BUILD_TYPE MATCHES "Release")
		SET (CMAKE_OSX_ARCHITECTURES x86_64;i386)
		# set( CMAKE_OSX_ARCHITECTURES "$(ARCHS_STANDARD_32_64_BIT)")
	endif(CMAKE_BUILD_TYPE MATCHES "Release")

	# Use PackageMaker for installers?
	if (DEFINED ZIP)
		set (CPACK_GENERATOR ZIP)
	else (DEFINED ZIP)
		set (CPACK_GENERATOR PackageMaker)
	endif (DEFINED ZIP)

	# Xcode settings
	set (XCODE_ATTRIBUTE_ONLY_ACTIVE_ARCH "NO")
endif (APPLE)

# Windows Builds
if (WIN32)

	# We need strtok on Windows
	list (APPEND src_files src/strtok.c)
	list (APPEND header_files src/strtok.h)

	# Use bat files instead of shell scripts
	set(scripts
		scripts/mmd.bat
		scripts/mmd2odf.bat
		scripts/mmd2opml.bat
		scripts/mmd2rtf.bat
		scripts/mmd2tex.bat
		scripts/markdown.bat
	)

	# Use NSIS to generate installers?
	if (DEFINED ZIP)
		set (CPACK_GENERATOR ZIP)
	else (DEFINED ZIP)
		set (CPACK_GENERATOR NSIS)
	endif (DEFINED ZIP)

# Linux Builds (not cross-compiling for Windows)
elseif (${CMAKE_SYSTEM_NAME} MATCHES "Linux")

	# Create zip archive
	set (CPACK_GENERATOR ZIP)

	# Some libraries need to be linked on some Linux builds
	if (DEFINED TEST)
		# target_link_libraries(run_tests m)
	else (DEFINE TEST)
		# Statically link libraries -- might make the binary slightly more
		# compatible across Linux distributions, for example
		#
		# It will likely cause large numbers of errors on valgrind, 
		# so use "make debug" for valgrind testing
		#
		# You may wish to disable this.
		#
		
		set (CMAKE_FIND_LIBRARY_SUFFIXES ".a")
		set (BUILD_SHARED_LIBRARIES OFF)
		set (CMAKE_EXE_LINKER_FLAGS "-static")
	endif (DEFINED TEST)

endif (WIN32)


# ==============
# Define targets
# ==============

# Create a library?
add_library(libMultiMarkdown STATIC
	${src_files}
	${src_utility_files}
	${header_files}
	${header_utility_files}
)

# remove the extra "lib" from "liblibFOO"
SET_TARGET_PROPERTIES(libMultiMarkdown PROPERTIES PREFIX "")

ADD_PUBLIC_HEADER(libMultiMarkdown src/libMultiMarkdown.h)

# Create command-line app
add_executable(multimarkdown
	src/multimarkdown.c
	src/GLibFacade.c
	src/GLibFacade.h
	${header_files}
)

# Xcode settings for fat binaries
set_target_properties(libMultiMarkdown PROPERTIES XCODE_ATTRIBUTE_ONLY_ACTIVE_ARCH "NO")
set_target_properties(multimarkdown PROPERTIES XCODE_ATTRIBUTE_ONLY_ACTIVE_ARCH "NO")

# Link the library to the app
target_link_libraries(multimarkdown libMultiMarkdown)


# ==========================
# Build Installer with CPack
# ==========================

# Create HTML version of README

if (DEFINED IS_CROSSCOMPILING)
	# Need to use installed MMD when cross compiling
	add_custom_command(
		TARGET multimarkdown
		POST_BUILD
		COMMAND multimarkdown -f ${CMAKE_CURRENT_LIST_DIR}/README.md > ${CMAKE_CURRENT_BINARY_DIR}/README.html
	)
else ()
	# Use mmd binary we just built
	add_custom_command(
		TARGET multimarkdown
		POST_BUILD
		COMMAND $<TARGET_FILE:multimarkdown> -f ${CMAKE_CURRENT_LIST_DIR}/README.md > ${CMAKE_CURRENT_BINARY_DIR}/README.html
	)
endif()

set(CPACK_SET_DESTDIR true)
set(CPACK_INSTALL_PREFIX /usr/local)

install (TARGETS multimarkdown
	DESTINATION bin
	COMPONENT application
)

set (CPACK_COMPONENT_APPLICATION_DISPLAY_NAME "MultiMarkdown")
set (CPACK_COMPONENT_APPLICATION_DESCRIPTION 
   "Install the actual `multimarkdown` program.")


install (FILES ${scripts}
	DESTINATION bin
	COMPONENT scripts
	PERMISSIONS OWNER_WRITE OWNER_READ OWNER_EXECUTE GROUP_READ GROUP_EXECUTE WORLD_READ WORLD_EXECUTE
)

# install (FILES ${PROJECT_SOURCE_DIR}/LICENSE.txt ${CMAKE_CURRENT_BINARY_DIR}/README.html
# 	DESTINATION notes
# )

# Use something like this to install public header files (after adding them
# with the ADD_PUBLIC_HEADER() macro)

# install (FILES ${public_header_files} DESTINATION local/include/libMultiMarkdown) 

set (CPACK_COMPONENT_SCRIPTS_DISPLAY_NAME "Convenience scripts")
set (CPACK_COMPONENT_SCRIPTS_DESCRIPTION 
   "Install convenience scripts for common MultiMarkdown shortcuts, e.g. `mmd`, `mmd2tex`, etc.")

include (InstallRequiredSystemLibraries)

set (CPACK_COMPONENTS_ALL application scripts)


set (CPACK_COMPONENT_APPLICATION_GROUP "MultiMarkdown")
set (CPACK_COMPONENT_SCRIPTS_GROUP "MultiMarkdown")

set (CPACK_COMPONENT_GROUP_MULTIMARKDOWN_DESCRIPTION
   "The basic MultiMarkdown utility and convenience scripts.")

set (CPACK_PACKAGE_DESCRIPTION_SUMMARY "${My_Project_Description}")
set (CPACK_PACKAGE_VENDOR "${My_Project_Author}")
set (CPACK_PACKAGE_VERSION "${My_Project_Version_Major}.${My_Project_Version_Minor}.${My_Project_Version_Patch}")
set (CPACK_PACKAGE_VERSION_MAJOR "${My_Project_Version_Major}")
set (CPACK_PACKAGE_VERSION_MINOR "${My_Project_Version_Minor}")
set (CPACK_PACKAGE_VERSION_PATCH "My_Project_Version_Patch")

set (CPACK_PACKAGE_DESCRIPTION_FILE "${CMAKE_CURRENT_BINARY_DIR}/README.html")
set (CPACK_RESOURCE_FILE_README "${CMAKE_CURRENT_BINARY_DIR}/README.html")
set (CPACK_RESOURCE_FILE_LICENSE "${PROJECT_SOURCE_DIR}/LICENSE.txt")

set (ZIP_NAME "")

if (DEFINED ZIP)
	set (ZIP_NAME "Portable-")
endif (DEFINED ZIP)

if (APPLE)
	set (CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}-Mac-${IS_32_BIT}${ZIP_NAME}${CPACK_PACKAGE_VERSION}")
else (APPLE)
	set (CPACK_PACKAGE_FILE_NAME "${PROJECT_NAME}-${CMAKE_SYSTEM_NAME}-${IS_32_BIT}${ZIP_NAME}${CPACK_PACKAGE_VERSION}")
endif (APPLE)

install (TARGETS multimarkdown
	DESTINATION bin
	COMPONENT application
)

# Use some default install locations (if appropriate)
if (WIN32)
	set (CPACK_INSTALL_PREFIX "")
	set (CPACK_NSIS_MODIFY_PATH ON)
else (WIN32)
	set (CPACK_INSTALL_PREFIX /usr/local)
endif (WIN32)

set (CPACK_PACKAGE_INSTALL_DIRECTORY ${PROJECT})

include (CPack)


# ======================
# Integration Test Suite
# ======================

enable_testing()

function(ADD_MMD_TEST NAME FLAGS FOLDER EXTENSION)
	add_test ( ${NAME}
		${PROJECT_SOURCE_DIR}/submodules/MarkdownTest/MarkdownTest.pl
		--Script=${CMAKE_CURRENT_BINARY_DIR}/multimarkdown
		--testdir=${PROJECT_SOURCE_DIR}/submodules/MarkdownTest/${FOLDER}
		"--Flags=${FLAGS}"
		--ext=${EXTENSION}
	)

endfunction(ADD_MMD_TEST)


# Original Markdown tests

# This first test will fail with a single error on Lists, the same as peg-markdown
# https://github.com/jgm/peg-markdown

add_test( markdown-should-fail ${PROJECT_SOURCE_DIR}/submodules/MarkdownTest/MarkdownTest.pl --Script=${CMAKE_CURRENT_BINARY_DIR}/multimarkdown --Tidy --Flags="--compatibility" --testdir=${PROJECT_SOURCE_DIR}/submodules/MarkdownTest/Test)

add_test( markdown ${PROJECT_SOURCE_DIR}/submodules/MarkdownTest/MarkdownTest.pl --Script=${CMAKE_CURRENT_BINARY_DIR}/multimarkdown --Tidy --Flags="--compatibility" --testdir=${PROJECT_SOURCE_DIR}/submodules/MarkdownTest/Tests)


# Basic MultiMarkdown integration testing

ADD_MMD_TEST(mmd "-t html" MultiMarkdownTests html)
ADD_MMD_TEST(latex "-t latex" MultiMarkdownTests tex)
ADD_MMD_TEST(beamer "-t beamer" BeamerTests tex)
ADD_MMD_TEST(memoir "-t memoir" MemoirTests tex)
ADD_MMD_TEST(lyx "-t lyx" MultiMarkdownTests lyx)
ADD_MMD_TEST(lyx-beamer "-t lyx" BeamerTests lyx)
ADD_MMD_TEST(opml "-t opml" MultiMarkdownTests opml)
ADD_MMD_TEST(odf "-t odf" MultiMarkdownTests fodt)


# CriticMarkup tests

ADD_MMD_TEST(critic-accept "-a" CriticMarkup htmla)
ADD_MMD_TEST(critic-reject "-r" CriticMarkup htmlr)
ADD_MMD_TEST(critic-highlight "-r -a" CriticMarkup htmlh)


# XSLT tests -- obsolete - they won't pass

# add_test ( xslt-1  ${PROJECT_SOURCE_DIR}/submodules/MarkdownTest/MarkdownTest.pl --Script=/bin/cat --testdir=${PROJECT_SOURCE_DIR}/submodules/MarkdownTest/MultiMarkdownTests --TrailFlags=|\ ${PROJECT_SOURCE_DIR}/Support/bin/mmd2tex-xslt --ext=tex)
# add_test ( xslt-2  ${PROJECT_SOURCE_DIR}/submodules/MarkdownTest/MarkdownTest.pl --Script=/bin/cat --testdir=${PROJECT_SOURCE_DIR}/submodules/MarkdownTest/BeamerTests --TrailFlags=|\ ${PROJECT_SOURCE_DIR}/Support/bin/mmd2tex-xslt --ext=tex)
# add_test ( xslt-3  ${PROJECT_SOURCE_DIR}/submodules/MarkdownTest/MarkdownTest.pl --Script=/bin/cat --testdir=${PROJECT_SOURCE_DIR}/submodules/MarkdownTest/MemoirTests --TrailFlags=|\ ${PROJECT_SOURCE_DIR}/Support/bin/mmd2tex-xslt --ext=tex)


# valgrind memory testing
# Only in 'make debug' mode

if (DEFINED TEST)
	find_program ( MEMORYCHECK_COMMAND valgrind)
	set ( MEMORYCHECK_COMMAND_OPTIONS --leak-check=full --error-exitcode=1)

	file (GLOB TEST_FILES ${PROJECT_SOURCE_DIR}/submodules/MarkdownTest/Tests/*.text ${PROJECT_SOURCE_DIR}/submodules/MarkdownTest/MultiMarkdownTests/*.text)

	foreach (FORMAT html latex odf beamer memoir opml lyx) 
		add_test ( NAME valgrind-${FORMAT} COMMAND "${MEMORYCHECK_COMMAND}" ${MEMORYCHECK_COMMAND_OPTIONS} ${PROJECT_BINARY_DIR}/multimarkdown -t ${FORMAT} ${TEST_FILES} )
	endforeach()
endif (DEFINED TEST)
