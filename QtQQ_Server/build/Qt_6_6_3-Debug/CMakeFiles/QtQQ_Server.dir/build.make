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

# Include any dependencies generated for this target.
include CMakeFiles/QtQQ_Server.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/QtQQ_Server.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/QtQQ_Server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/QtQQ_Server.dir/flags.make

QtQQ_Server_autogen/timestamp: /Users/wangrundong/Qt/6.6.3/macos/./libexec/moc
QtQQ_Server_autogen/timestamp: /Users/wangrundong/Qt/6.6.3/macos/./libexec/uic
QtQQ_Server_autogen/timestamp: CMakeFiles/QtQQ_Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target QtQQ_Server"
	/opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E cmake_autogen /Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/CMakeFiles/QtQQ_Server_autogen.dir/AutogenInfo.json Debug
	/opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E touch /Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/QtQQ_Server_autogen/timestamp

QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp: /Users/wangrundong/Documents/Projects/QtQQ_Server/resources.qrc
QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp: CMakeFiles/QtQQ_Server_autogen.dir/AutoRcc_resources_EWIEGA46WW_Info.json
QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp: /Users/wangrundong/Documents/Projects/QtQQ_Server/Resources/img/fly1.png
QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp: /Users/wangrundong/Qt/6.6.3/macos/./libexec/rcc
QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp: /Users/wangrundong/Qt/6.6.3/macos/./libexec/rcc
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Automatic RCC for resources.qrc"
	/opt/homebrew/Cellar/cmake/3.30.2/bin/cmake -E cmake_autorcc /Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/CMakeFiles/QtQQ_Server_autogen.dir/AutoRcc_resources_EWIEGA46WW_Info.json Debug

CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/mocs_compilation.cpp.o: CMakeFiles/QtQQ_Server.dir/flags.make
CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/mocs_compilation.cpp.o: QtQQ_Server_autogen/mocs_compilation.cpp
CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/mocs_compilation.cpp.o: CMakeFiles/QtQQ_Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/mocs_compilation.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/mocs_compilation.cpp.o -MF CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/mocs_compilation.cpp.o -c /Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/QtQQ_Server_autogen/mocs_compilation.cpp

CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/mocs_compilation.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/QtQQ_Server_autogen/mocs_compilation.cpp > CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/mocs_compilation.cpp.i

CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/mocs_compilation.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/QtQQ_Server_autogen/mocs_compilation.cpp -o CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/mocs_compilation.cpp.s

CMakeFiles/QtQQ_Server.dir/main.cpp.o: CMakeFiles/QtQQ_Server.dir/flags.make
CMakeFiles/QtQQ_Server.dir/main.cpp.o: /Users/wangrundong/Documents/Projects/QtQQ_Server/main.cpp
CMakeFiles/QtQQ_Server.dir/main.cpp.o: CMakeFiles/QtQQ_Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/QtQQ_Server.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/QtQQ_Server.dir/main.cpp.o -MF CMakeFiles/QtQQ_Server.dir/main.cpp.o.d -o CMakeFiles/QtQQ_Server.dir/main.cpp.o -c /Users/wangrundong/Documents/Projects/QtQQ_Server/main.cpp

CMakeFiles/QtQQ_Server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/QtQQ_Server.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangrundong/Documents/Projects/QtQQ_Server/main.cpp > CMakeFiles/QtQQ_Server.dir/main.cpp.i

CMakeFiles/QtQQ_Server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/QtQQ_Server.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangrundong/Documents/Projects/QtQQ_Server/main.cpp -o CMakeFiles/QtQQ_Server.dir/main.cpp.s

CMakeFiles/QtQQ_Server.dir/qtqqserver.cpp.o: CMakeFiles/QtQQ_Server.dir/flags.make
CMakeFiles/QtQQ_Server.dir/qtqqserver.cpp.o: /Users/wangrundong/Documents/Projects/QtQQ_Server/qtqqserver.cpp
CMakeFiles/QtQQ_Server.dir/qtqqserver.cpp.o: CMakeFiles/QtQQ_Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/QtQQ_Server.dir/qtqqserver.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/QtQQ_Server.dir/qtqqserver.cpp.o -MF CMakeFiles/QtQQ_Server.dir/qtqqserver.cpp.o.d -o CMakeFiles/QtQQ_Server.dir/qtqqserver.cpp.o -c /Users/wangrundong/Documents/Projects/QtQQ_Server/qtqqserver.cpp

CMakeFiles/QtQQ_Server.dir/qtqqserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/QtQQ_Server.dir/qtqqserver.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangrundong/Documents/Projects/QtQQ_Server/qtqqserver.cpp > CMakeFiles/QtQQ_Server.dir/qtqqserver.cpp.i

CMakeFiles/QtQQ_Server.dir/qtqqserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/QtQQ_Server.dir/qtqqserver.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangrundong/Documents/Projects/QtQQ_Server/qtqqserver.cpp -o CMakeFiles/QtQQ_Server.dir/qtqqserver.cpp.s

CMakeFiles/QtQQ_Server.dir/tcpserver.cpp.o: CMakeFiles/QtQQ_Server.dir/flags.make
CMakeFiles/QtQQ_Server.dir/tcpserver.cpp.o: /Users/wangrundong/Documents/Projects/QtQQ_Server/tcpserver.cpp
CMakeFiles/QtQQ_Server.dir/tcpserver.cpp.o: CMakeFiles/QtQQ_Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/QtQQ_Server.dir/tcpserver.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/QtQQ_Server.dir/tcpserver.cpp.o -MF CMakeFiles/QtQQ_Server.dir/tcpserver.cpp.o.d -o CMakeFiles/QtQQ_Server.dir/tcpserver.cpp.o -c /Users/wangrundong/Documents/Projects/QtQQ_Server/tcpserver.cpp

CMakeFiles/QtQQ_Server.dir/tcpserver.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/QtQQ_Server.dir/tcpserver.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangrundong/Documents/Projects/QtQQ_Server/tcpserver.cpp > CMakeFiles/QtQQ_Server.dir/tcpserver.cpp.i

CMakeFiles/QtQQ_Server.dir/tcpserver.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/QtQQ_Server.dir/tcpserver.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangrundong/Documents/Projects/QtQQ_Server/tcpserver.cpp -o CMakeFiles/QtQQ_Server.dir/tcpserver.cpp.s

CMakeFiles/QtQQ_Server.dir/tcpsocket.cpp.o: CMakeFiles/QtQQ_Server.dir/flags.make
CMakeFiles/QtQQ_Server.dir/tcpsocket.cpp.o: /Users/wangrundong/Documents/Projects/QtQQ_Server/tcpsocket.cpp
CMakeFiles/QtQQ_Server.dir/tcpsocket.cpp.o: CMakeFiles/QtQQ_Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/QtQQ_Server.dir/tcpsocket.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/QtQQ_Server.dir/tcpsocket.cpp.o -MF CMakeFiles/QtQQ_Server.dir/tcpsocket.cpp.o.d -o CMakeFiles/QtQQ_Server.dir/tcpsocket.cpp.o -c /Users/wangrundong/Documents/Projects/QtQQ_Server/tcpsocket.cpp

CMakeFiles/QtQQ_Server.dir/tcpsocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/QtQQ_Server.dir/tcpsocket.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangrundong/Documents/Projects/QtQQ_Server/tcpsocket.cpp > CMakeFiles/QtQQ_Server.dir/tcpsocket.cpp.i

CMakeFiles/QtQQ_Server.dir/tcpsocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/QtQQ_Server.dir/tcpsocket.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangrundong/Documents/Projects/QtQQ_Server/tcpsocket.cpp -o CMakeFiles/QtQQ_Server.dir/tcpsocket.cpp.s

CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp.o: CMakeFiles/QtQQ_Server.dir/flags.make
CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp.o: QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp
CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp.o: CMakeFiles/QtQQ_Server.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp.o -MF CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp.o.d -o CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp.o -c /Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp

CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp > CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp.i

CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp -o CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp.s

# Object files for target QtQQ_Server
QtQQ_Server_OBJECTS = \
"CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/QtQQ_Server.dir/main.cpp.o" \
"CMakeFiles/QtQQ_Server.dir/qtqqserver.cpp.o" \
"CMakeFiles/QtQQ_Server.dir/tcpserver.cpp.o" \
"CMakeFiles/QtQQ_Server.dir/tcpsocket.cpp.o" \
"CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp.o"

# External object files for target QtQQ_Server
QtQQ_Server_EXTERNAL_OBJECTS =

QtQQ_Server.app/Contents/MacOS/QtQQ_Server: CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/mocs_compilation.cpp.o
QtQQ_Server.app/Contents/MacOS/QtQQ_Server: CMakeFiles/QtQQ_Server.dir/main.cpp.o
QtQQ_Server.app/Contents/MacOS/QtQQ_Server: CMakeFiles/QtQQ_Server.dir/qtqqserver.cpp.o
QtQQ_Server.app/Contents/MacOS/QtQQ_Server: CMakeFiles/QtQQ_Server.dir/tcpserver.cpp.o
QtQQ_Server.app/Contents/MacOS/QtQQ_Server: CMakeFiles/QtQQ_Server.dir/tcpsocket.cpp.o
QtQQ_Server.app/Contents/MacOS/QtQQ_Server: CMakeFiles/QtQQ_Server.dir/QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp.o
QtQQ_Server.app/Contents/MacOS/QtQQ_Server: CMakeFiles/QtQQ_Server.dir/build.make
QtQQ_Server.app/Contents/MacOS/QtQQ_Server: /Users/wangrundong/Qt/6.6.3/macos/lib/QtWidgets.framework/Versions/A/QtWidgets
QtQQ_Server.app/Contents/MacOS/QtQQ_Server: /Users/wangrundong/Qt/6.6.3/macos/lib/QtNetwork.framework/Versions/A/QtNetwork
QtQQ_Server.app/Contents/MacOS/QtQQ_Server: /Users/wangrundong/Qt/6.6.3/macos/lib/QtSql.framework/Versions/A/QtSql
QtQQ_Server.app/Contents/MacOS/QtQQ_Server: /Users/wangrundong/Qt/6.6.3/macos/lib/QtGui.framework/Versions/A/QtGui
QtQQ_Server.app/Contents/MacOS/QtQQ_Server: /Users/wangrundong/Qt/6.6.3/macos/lib/QtCore.framework/Versions/A/QtCore
QtQQ_Server.app/Contents/MacOS/QtQQ_Server: CMakeFiles/QtQQ_Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Linking CXX executable QtQQ_Server.app/Contents/MacOS/QtQQ_Server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/QtQQ_Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/QtQQ_Server.dir/build: QtQQ_Server.app/Contents/MacOS/QtQQ_Server
.PHONY : CMakeFiles/QtQQ_Server.dir/build

CMakeFiles/QtQQ_Server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/QtQQ_Server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/QtQQ_Server.dir/clean

CMakeFiles/QtQQ_Server.dir/depend: QtQQ_Server_autogen/EWIEGA46WW/qrc_resources.cpp
CMakeFiles/QtQQ_Server.dir/depend: QtQQ_Server_autogen/timestamp
	cd /Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wangrundong/Documents/Projects/QtQQ_Server /Users/wangrundong/Documents/Projects/QtQQ_Server /Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug /Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug /Users/wangrundong/Documents/Projects/QtQQ_Server/build/Qt_6_6_3-Debug/CMakeFiles/QtQQ_Server.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/QtQQ_Server.dir/depend

