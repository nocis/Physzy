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

# Include any dependencies generated for this target.
include src/engine/CMakeFiles/engine.dir/depend.make

# Include the progress variables for this target.
include src/engine/CMakeFiles/engine.dir/progress.make

# Include the compile flags for this target's objects.
include src/engine/CMakeFiles/engine.dir/flags.make

src/engine/CMakeFiles/engine.dir/math/foo.cpp.o: src/engine/CMakeFiles/engine.dir/flags.make
src/engine/CMakeFiles/engine.dir/math/foo.cpp.o: ../src/engine/math/foo.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jared/Physzy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/engine/CMakeFiles/engine.dir/math/foo.cpp.o"
	cd /home/jared/Physzy/cmake-build-debug/src/engine && /opt/clang-dev/install/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/engine.dir/math/foo.cpp.o -c /home/jared/Physzy/src/engine/math/foo.cpp

src/engine/CMakeFiles/engine.dir/math/foo.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/engine.dir/math/foo.cpp.i"
	cd /home/jared/Physzy/cmake-build-debug/src/engine && /opt/clang-dev/install/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jared/Physzy/src/engine/math/foo.cpp > CMakeFiles/engine.dir/math/foo.cpp.i

src/engine/CMakeFiles/engine.dir/math/foo.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/engine.dir/math/foo.cpp.s"
	cd /home/jared/Physzy/cmake-build-debug/src/engine && /opt/clang-dev/install/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jared/Physzy/src/engine/math/foo.cpp -o CMakeFiles/engine.dir/math/foo.cpp.s

# Object files for target engine
engine_OBJECTS = \
"CMakeFiles/engine.dir/math/foo.cpp.o"

# External object files for target engine
engine_EXTERNAL_OBJECTS =

lib/libengine.a: src/engine/CMakeFiles/engine.dir/math/foo.cpp.o
lib/libengine.a: src/engine/CMakeFiles/engine.dir/build.make
lib/libengine.a: src/engine/CMakeFiles/engine.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jared/Physzy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../lib/libengine.a"
	cd /home/jared/Physzy/cmake-build-debug/src/engine && $(CMAKE_COMMAND) -P CMakeFiles/engine.dir/cmake_clean_target.cmake
	cd /home/jared/Physzy/cmake-build-debug/src/engine && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/engine.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/engine/CMakeFiles/engine.dir/build: lib/libengine.a

.PHONY : src/engine/CMakeFiles/engine.dir/build

src/engine/CMakeFiles/engine.dir/clean:
	cd /home/jared/Physzy/cmake-build-debug/src/engine && $(CMAKE_COMMAND) -P CMakeFiles/engine.dir/cmake_clean.cmake
.PHONY : src/engine/CMakeFiles/engine.dir/clean

src/engine/CMakeFiles/engine.dir/depend:
	cd /home/jared/Physzy/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jared/Physzy /home/jared/Physzy/src/engine /home/jared/Physzy/cmake-build-debug /home/jared/Physzy/cmake-build-debug/src/engine /home/jared/Physzy/cmake-build-debug/src/engine/CMakeFiles/engine.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/engine/CMakeFiles/engine.dir/depend

