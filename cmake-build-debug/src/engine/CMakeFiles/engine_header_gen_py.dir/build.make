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
CMAKE_COMMAND = /home/jared/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.5662.56/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/jared/.local/share/JetBrains/Toolbox/apps/CLion/ch-0/193.5662.56/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jared/Physzy

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jared/Physzy/cmake-build-debug

# Utility rule file for engine_header_gen_py.

# Include the progress variables for this target.
include src/engine/CMakeFiles/engine_header_gen_py.dir/progress.make

src/engine/CMakeFiles/engine_header_gen_py: ../include/engine.h


../include/engine.h:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/jared/Physzy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating ../../../include/engine.h"
	cd /home/jared/Physzy/cmake-build-debug/src/engine && python /home/jared/Physzy/src/engine/../../scripts/header_gen.py

engine_header_gen_py: src/engine/CMakeFiles/engine_header_gen_py
engine_header_gen_py: ../include/engine.h
engine_header_gen_py: src/engine/CMakeFiles/engine_header_gen_py.dir/build.make

.PHONY : engine_header_gen_py

# Rule to build all files generated by this target.
src/engine/CMakeFiles/engine_header_gen_py.dir/build: engine_header_gen_py

.PHONY : src/engine/CMakeFiles/engine_header_gen_py.dir/build

src/engine/CMakeFiles/engine_header_gen_py.dir/clean:
	cd /home/jared/Physzy/cmake-build-debug/src/engine && $(CMAKE_COMMAND) -P CMakeFiles/engine_header_gen_py.dir/cmake_clean.cmake
.PHONY : src/engine/CMakeFiles/engine_header_gen_py.dir/clean

src/engine/CMakeFiles/engine_header_gen_py.dir/depend:
	cd /home/jared/Physzy/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jared/Physzy /home/jared/Physzy/src/engine /home/jared/Physzy/cmake-build-debug /home/jared/Physzy/cmake-build-debug/src/engine /home/jared/Physzy/cmake-build-debug/src/engine/CMakeFiles/engine_header_gen_py.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/engine/CMakeFiles/engine_header_gen_py.dir/depend
