# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wangrundong/Documents/Projects/QtQQ_Server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug

# Utility rule file for QtQQ_Server_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/QtQQ_Server_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/QtQQ_Server_autogen.dir/progress.make

CMakeFiles/QtQQ_Server_autogen: QtQQ_Server_autogen/timestamp

QtQQ_Server_autogen/timestamp: /Users/wangrundong/Qt/6.6.3/macos/./libexec/moc
QtQQ_Server_autogen/timestamp: /Users/wangrundong/Qt/6.6.3/macos/./libexec/uic
QtQQ_Server_autogen/timestamp: CMakeFiles/QtQQ_Server_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target QtQQ_Server"
	/opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E cmake_autogen /Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/CMakeFiles/QtQQ_Server_autogen.dir/AutogenInfo.json Debug
	/opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E touch /Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/QtQQ_Server_autogen/timestamp

QtQQ_Server_autogen: CMakeFiles/QtQQ_Server_autogen
QtQQ_Server_autogen: QtQQ_Server_autogen/timestamp
QtQQ_Server_autogen: CMakeFiles/QtQQ_Server_autogen.dir/build.make
.PHONY : QtQQ_Server_autogen

# Rule to build all files generated by this target.
CMakeFiles/QtQQ_Server_autogen.dir/build: QtQQ_Server_autogen
.PHONY : CMakeFiles/QtQQ_Server_autogen.dir/build

CMakeFiles/QtQQ_Server_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QtQQ_Server_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QtQQ_Server_autogen.dir/clean

CMakeFiles/QtQQ_Server_autogen.dir/depend:
	cd /Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wangrundong/Documents/Projects/QtQQ_Server /Users/wangrundong/Documents/Projects/QtQQ_Server /Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug /Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug /Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/CMakeFiles/QtQQ_Server_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/QtQQ_Server_autogen.dir/depend

