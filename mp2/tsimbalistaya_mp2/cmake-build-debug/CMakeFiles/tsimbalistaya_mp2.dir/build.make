# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ulyanatsimbalistaya/Desktop/mp2/tsimbalistaya_mp2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ulyanatsimbalistaya/Desktop/mp2/tsimbalistaya_mp2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tsimbalistaya_mp2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tsimbalistaya_mp2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tsimbalistaya_mp2.dir/flags.make

CMakeFiles/tsimbalistaya_mp2.dir/main.cpp.o: CMakeFiles/tsimbalistaya_mp2.dir/flags.make
CMakeFiles/tsimbalistaya_mp2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/ulyanatsimbalistaya/Desktop/mp2/tsimbalistaya_mp2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tsimbalistaya_mp2.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tsimbalistaya_mp2.dir/main.cpp.o -c /Users/ulyanatsimbalistaya/Desktop/mp2/tsimbalistaya_mp2/main.cpp

CMakeFiles/tsimbalistaya_mp2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tsimbalistaya_mp2.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ulyanatsimbalistaya/Desktop/mp2/tsimbalistaya_mp2/main.cpp > CMakeFiles/tsimbalistaya_mp2.dir/main.cpp.i

CMakeFiles/tsimbalistaya_mp2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tsimbalistaya_mp2.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ulyanatsimbalistaya/Desktop/mp2/tsimbalistaya_mp2/main.cpp -o CMakeFiles/tsimbalistaya_mp2.dir/main.cpp.s

# Object files for target tsimbalistaya_mp2
tsimbalistaya_mp2_OBJECTS = \
"CMakeFiles/tsimbalistaya_mp2.dir/main.cpp.o"

# External object files for target tsimbalistaya_mp2
tsimbalistaya_mp2_EXTERNAL_OBJECTS =

tsimbalistaya_mp2: CMakeFiles/tsimbalistaya_mp2.dir/main.cpp.o
tsimbalistaya_mp2: CMakeFiles/tsimbalistaya_mp2.dir/build.make
tsimbalistaya_mp2: CMakeFiles/tsimbalistaya_mp2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/ulyanatsimbalistaya/Desktop/mp2/tsimbalistaya_mp2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable tsimbalistaya_mp2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tsimbalistaya_mp2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tsimbalistaya_mp2.dir/build: tsimbalistaya_mp2

.PHONY : CMakeFiles/tsimbalistaya_mp2.dir/build

CMakeFiles/tsimbalistaya_mp2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tsimbalistaya_mp2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tsimbalistaya_mp2.dir/clean

CMakeFiles/tsimbalistaya_mp2.dir/depend:
	cd /Users/ulyanatsimbalistaya/Desktop/mp2/tsimbalistaya_mp2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ulyanatsimbalistaya/Desktop/mp2/tsimbalistaya_mp2 /Users/ulyanatsimbalistaya/Desktop/mp2/tsimbalistaya_mp2 /Users/ulyanatsimbalistaya/Desktop/mp2/tsimbalistaya_mp2/cmake-build-debug /Users/ulyanatsimbalistaya/Desktop/mp2/tsimbalistaya_mp2/cmake-build-debug /Users/ulyanatsimbalistaya/Desktop/mp2/tsimbalistaya_mp2/cmake-build-debug/CMakeFiles/tsimbalistaya_mp2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tsimbalistaya_mp2.dir/depend

