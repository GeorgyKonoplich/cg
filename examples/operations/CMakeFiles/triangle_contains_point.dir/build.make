# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/cmake-gui

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/j0r1k/workspace/с++/cg-work/cg

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/j0r1k/workspace/с++/cg-work/cg

# Include any dependencies generated for this target.
include examples/operations/CMakeFiles/triangle_contains_point.dir/depend.make

# Include the progress variables for this target.
include examples/operations/CMakeFiles/triangle_contains_point.dir/progress.make

# Include the compile flags for this target's objects.
include examples/operations/CMakeFiles/triangle_contains_point.dir/flags.make

examples/operations/CMakeFiles/triangle_contains_point.dir/triangle_contains_point.cpp.o: examples/operations/CMakeFiles/triangle_contains_point.dir/flags.make
examples/operations/CMakeFiles/triangle_contains_point.dir/triangle_contains_point.cpp.o: examples/operations/triangle_contains_point.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/j0r1k/workspace/с++/cg-work/cg/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object examples/operations/CMakeFiles/triangle_contains_point.dir/triangle_contains_point.cpp.o"
	cd /home/j0r1k/workspace/с++/cg-work/cg/examples/operations && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/triangle_contains_point.dir/triangle_contains_point.cpp.o -c /home/j0r1k/workspace/с++/cg-work/cg/examples/operations/triangle_contains_point.cpp

examples/operations/CMakeFiles/triangle_contains_point.dir/triangle_contains_point.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/triangle_contains_point.dir/triangle_contains_point.cpp.i"
	cd /home/j0r1k/workspace/с++/cg-work/cg/examples/operations && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/j0r1k/workspace/с++/cg-work/cg/examples/operations/triangle_contains_point.cpp > CMakeFiles/triangle_contains_point.dir/triangle_contains_point.cpp.i

examples/operations/CMakeFiles/triangle_contains_point.dir/triangle_contains_point.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/triangle_contains_point.dir/triangle_contains_point.cpp.s"
	cd /home/j0r1k/workspace/с++/cg-work/cg/examples/operations && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/j0r1k/workspace/с++/cg-work/cg/examples/operations/triangle_contains_point.cpp -o CMakeFiles/triangle_contains_point.dir/triangle_contains_point.cpp.s

examples/operations/CMakeFiles/triangle_contains_point.dir/triangle_contains_point.cpp.o.requires:
.PHONY : examples/operations/CMakeFiles/triangle_contains_point.dir/triangle_contains_point.cpp.o.requires

examples/operations/CMakeFiles/triangle_contains_point.dir/triangle_contains_point.cpp.o.provides: examples/operations/CMakeFiles/triangle_contains_point.dir/triangle_contains_point.cpp.o.requires
	$(MAKE) -f examples/operations/CMakeFiles/triangle_contains_point.dir/build.make examples/operations/CMakeFiles/triangle_contains_point.dir/triangle_contains_point.cpp.o.provides.build
.PHONY : examples/operations/CMakeFiles/triangle_contains_point.dir/triangle_contains_point.cpp.o.provides

examples/operations/CMakeFiles/triangle_contains_point.dir/triangle_contains_point.cpp.o.provides.build: examples/operations/CMakeFiles/triangle_contains_point.dir/triangle_contains_point.cpp.o

# Object files for target triangle_contains_point
triangle_contains_point_OBJECTS = \
"CMakeFiles/triangle_contains_point.dir/triangle_contains_point.cpp.o"

# External object files for target triangle_contains_point
triangle_contains_point_EXTERNAL_OBJECTS =

examples/operations/triangle_contains_point: examples/operations/CMakeFiles/triangle_contains_point.dir/triangle_contains_point.cpp.o
examples/operations/triangle_contains_point: examples/operations/CMakeFiles/triangle_contains_point.dir/build.make
examples/operations/triangle_contains_point: src/libvisualization.a
examples/operations/triangle_contains_point: /usr/lib/x86_64-linux-gnu/libgmp.so
examples/operations/triangle_contains_point: /usr/lib/x86_64-linux-gnu/libQtOpenGL.so
examples/operations/triangle_contains_point: /usr/lib/x86_64-linux-gnu/libQtGui.so
examples/operations/triangle_contains_point: /usr/lib/x86_64-linux-gnu/libQtCore.so
examples/operations/triangle_contains_point: examples/operations/CMakeFiles/triangle_contains_point.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable triangle_contains_point"
	cd /home/j0r1k/workspace/с++/cg-work/cg/examples/operations && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/triangle_contains_point.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
examples/operations/CMakeFiles/triangle_contains_point.dir/build: examples/operations/triangle_contains_point
.PHONY : examples/operations/CMakeFiles/triangle_contains_point.dir/build

examples/operations/CMakeFiles/triangle_contains_point.dir/requires: examples/operations/CMakeFiles/triangle_contains_point.dir/triangle_contains_point.cpp.o.requires
.PHONY : examples/operations/CMakeFiles/triangle_contains_point.dir/requires

examples/operations/CMakeFiles/triangle_contains_point.dir/clean:
	cd /home/j0r1k/workspace/с++/cg-work/cg/examples/operations && $(CMAKE_COMMAND) -P CMakeFiles/triangle_contains_point.dir/cmake_clean.cmake
.PHONY : examples/operations/CMakeFiles/triangle_contains_point.dir/clean

examples/operations/CMakeFiles/triangle_contains_point.dir/depend:
	cd /home/j0r1k/workspace/с++/cg-work/cg && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/j0r1k/workspace/с++/cg-work/cg /home/j0r1k/workspace/с++/cg-work/cg/examples/operations /home/j0r1k/workspace/с++/cg-work/cg /home/j0r1k/workspace/с++/cg-work/cg/examples/operations /home/j0r1k/workspace/с++/cg-work/cg/examples/operations/CMakeFiles/triangle_contains_point.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : examples/operations/CMakeFiles/triangle_contains_point.dir/depend
