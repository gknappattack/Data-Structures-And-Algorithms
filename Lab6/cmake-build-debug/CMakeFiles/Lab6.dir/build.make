# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/gregoryknapp/CLionProjects/Lab6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/gregoryknapp/CLionProjects/Lab6/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Lab6.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab6.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab6.dir/flags.make

CMakeFiles/Lab6.dir/main.cpp.o: CMakeFiles/Lab6.dir/flags.make
CMakeFiles/Lab6.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/gregoryknapp/CLionProjects/Lab6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab6.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Lab6.dir/main.cpp.o -c /Users/gregoryknapp/CLionProjects/Lab6/main.cpp

CMakeFiles/Lab6.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab6.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/gregoryknapp/CLionProjects/Lab6/main.cpp > CMakeFiles/Lab6.dir/main.cpp.i

CMakeFiles/Lab6.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab6.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/gregoryknapp/CLionProjects/Lab6/main.cpp -o CMakeFiles/Lab6.dir/main.cpp.s

# Object files for target Lab6
Lab6_OBJECTS = \
"CMakeFiles/Lab6.dir/main.cpp.o"

# External object files for target Lab6
Lab6_EXTERNAL_OBJECTS =

Lab6: CMakeFiles/Lab6.dir/main.cpp.o
Lab6: CMakeFiles/Lab6.dir/build.make
Lab6: CMakeFiles/Lab6.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/gregoryknapp/CLionProjects/Lab6/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab6"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Lab6.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab6.dir/build: Lab6

.PHONY : CMakeFiles/Lab6.dir/build

CMakeFiles/Lab6.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Lab6.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Lab6.dir/clean

CMakeFiles/Lab6.dir/depend:
	cd /Users/gregoryknapp/CLionProjects/Lab6/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/gregoryknapp/CLionProjects/Lab6 /Users/gregoryknapp/CLionProjects/Lab6 /Users/gregoryknapp/CLionProjects/Lab6/cmake-build-debug /Users/gregoryknapp/CLionProjects/Lab6/cmake-build-debug /Users/gregoryknapp/CLionProjects/Lab6/cmake-build-debug/CMakeFiles/Lab6.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab6.dir/depend

