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
include CMakeFiles/tinyrender.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/tinyrender.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tinyrender.dir/flags.make

CMakeFiles/tinyrender.dir/src/examples/fluid1/main.cpp.o: CMakeFiles/tinyrender.dir/flags.make
CMakeFiles/tinyrender.dir/src/examples/fluid1/main.cpp.o: ../src/examples/fluid1/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jared/Physzy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tinyrender.dir/src/examples/fluid1/main.cpp.o"
	/opt/clang-dev/install/bin/clang++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/tinyrender.dir/src/examples/fluid1/main.cpp.o -c /home/jared/Physzy/src/examples/fluid1/main.cpp

CMakeFiles/tinyrender.dir/src/examples/fluid1/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tinyrender.dir/src/examples/fluid1/main.cpp.i"
	/opt/clang-dev/install/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jared/Physzy/src/examples/fluid1/main.cpp > CMakeFiles/tinyrender.dir/src/examples/fluid1/main.cpp.i

CMakeFiles/tinyrender.dir/src/examples/fluid1/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tinyrender.dir/src/examples/fluid1/main.cpp.s"
	/opt/clang-dev/install/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jared/Physzy/src/examples/fluid1/main.cpp -o CMakeFiles/tinyrender.dir/src/examples/fluid1/main.cpp.s

# Object files for target tinyrender
tinyrender_OBJECTS = \
"CMakeFiles/tinyrender.dir/src/examples/fluid1/main.cpp.o"

# External object files for target tinyrender
tinyrender_EXTERNAL_OBJECTS =

bin/tinyrender: CMakeFiles/tinyrender.dir/src/examples/fluid1/main.cpp.o
bin/tinyrender: CMakeFiles/tinyrender.dir/build.make
bin/tinyrender: /usr/lib/x86_64-linux-gnu/libGL.so
bin/tinyrender: /usr/lib/x86_64-linux-gnu/libGLU.so
bin/tinyrender: /usr/lib/x86_64-linux-gnu/libGLEW.so
bin/tinyrender: CMakeFiles/tinyrender.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jared/Physzy/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable bin/tinyrender"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tinyrender.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tinyrender.dir/build: bin/tinyrender

.PHONY : CMakeFiles/tinyrender.dir/build

CMakeFiles/tinyrender.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tinyrender.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tinyrender.dir/clean

CMakeFiles/tinyrender.dir/depend:
	cd /home/jared/Physzy/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jared/Physzy /home/jared/Physzy /home/jared/Physzy/cmake-build-debug /home/jared/Physzy/cmake-build-debug /home/jared/Physzy/cmake-build-debug/CMakeFiles/tinyrender.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tinyrender.dir/depend
