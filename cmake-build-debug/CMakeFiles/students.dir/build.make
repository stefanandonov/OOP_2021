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
CMAKE_COMMAND = "/Users/stefanandonov/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/CLion.app/Contents/bin/cmake/mac/bin/cmake"

# The command to remove a file.
RM = "/Users/stefanandonov/Library/Application Support/JetBrains/Toolbox/apps/CLion/ch-0/202.7660.37/CLion.app/Contents/bin/cmake/mac/bin/cmake" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/stefanandonov/CLionProjects/OOP/OOP_MK

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/stefanandonov/CLionProjects/OOP/OOP_MK/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/students.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/students.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/students.dir/flags.make

CMakeFiles/students.dir/ex1/students.c.o: CMakeFiles/students.dir/flags.make
CMakeFiles/students.dir/ex1/students.c.o: ../ex1/students.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/stefanandonov/CLionProjects/OOP/OOP_MK/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/students.dir/ex1/students.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/students.dir/ex1/students.c.o   -c /Users/stefanandonov/CLionProjects/OOP/OOP_MK/ex1/students.c

CMakeFiles/students.dir/ex1/students.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/students.dir/ex1/students.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/stefanandonov/CLionProjects/OOP/OOP_MK/ex1/students.c > CMakeFiles/students.dir/ex1/students.c.i

CMakeFiles/students.dir/ex1/students.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/students.dir/ex1/students.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/stefanandonov/CLionProjects/OOP/OOP_MK/ex1/students.c -o CMakeFiles/students.dir/ex1/students.c.s

# Object files for target students
students_OBJECTS = \
"CMakeFiles/students.dir/ex1/students.c.o"

# External object files for target students
students_EXTERNAL_OBJECTS =

students: CMakeFiles/students.dir/ex1/students.c.o
students: CMakeFiles/students.dir/build.make
students: CMakeFiles/students.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/stefanandonov/CLionProjects/OOP/OOP_MK/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable students"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/students.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/students.dir/build: students

.PHONY : CMakeFiles/students.dir/build

CMakeFiles/students.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/students.dir/cmake_clean.cmake
.PHONY : CMakeFiles/students.dir/clean

CMakeFiles/students.dir/depend:
	cd /Users/stefanandonov/CLionProjects/OOP/OOP_MK/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/stefanandonov/CLionProjects/OOP/OOP_MK /Users/stefanandonov/CLionProjects/OOP/OOP_MK /Users/stefanandonov/CLionProjects/OOP/OOP_MK/cmake-build-debug /Users/stefanandonov/CLionProjects/OOP/OOP_MK/cmake-build-debug /Users/stefanandonov/CLionProjects/OOP/OOP_MK/cmake-build-debug/CMakeFiles/students.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/students.dir/depend

