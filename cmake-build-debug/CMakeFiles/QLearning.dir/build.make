# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/QLearning.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/QLearning.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/QLearning.dir/flags.make

CMakeFiles/QLearning.dir/main.c.obj: CMakeFiles/QLearning.dir/flags.make
CMakeFiles/QLearning.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/QLearning.dir/main.c.obj"
	C:\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\QLearning.dir\main.c.obj -c C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning\main.c

CMakeFiles/QLearning.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/QLearning.dir/main.c.i"
	C:\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning\main.c > CMakeFiles\QLearning.dir\main.c.i

CMakeFiles/QLearning.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/QLearning.dir/main.c.s"
	C:\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning\main.c -o CMakeFiles\QLearning.dir\main.c.s

CMakeFiles/QLearning.dir/qtable.c.obj: CMakeFiles/QLearning.dir/flags.make
CMakeFiles/QLearning.dir/qtable.c.obj: ../qtable.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/QLearning.dir/qtable.c.obj"
	C:\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\QLearning.dir\qtable.c.obj -c C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning\qtable.c

CMakeFiles/QLearning.dir/qtable.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/QLearning.dir/qtable.c.i"
	C:\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning\qtable.c > CMakeFiles\QLearning.dir\qtable.c.i

CMakeFiles/QLearning.dir/qtable.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/QLearning.dir/qtable.c.s"
	C:\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning\qtable.c -o CMakeFiles\QLearning.dir\qtable.c.s

CMakeFiles/QLearning.dir/miscellaneous.c.obj: CMakeFiles/QLearning.dir/flags.make
CMakeFiles/QLearning.dir/miscellaneous.c.obj: ../miscellaneous.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/QLearning.dir/miscellaneous.c.obj"
	C:\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\QLearning.dir\miscellaneous.c.obj -c C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning\miscellaneous.c

CMakeFiles/QLearning.dir/miscellaneous.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/QLearning.dir/miscellaneous.c.i"
	C:\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning\miscellaneous.c > CMakeFiles\QLearning.dir\miscellaneous.c.i

CMakeFiles/QLearning.dir/miscellaneous.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/QLearning.dir/miscellaneous.c.s"
	C:\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning\miscellaneous.c -o CMakeFiles\QLearning.dir\miscellaneous.c.s

CMakeFiles/QLearning.dir/simple_game.c.obj: CMakeFiles/QLearning.dir/flags.make
CMakeFiles/QLearning.dir/simple_game.c.obj: ../simple_game.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/QLearning.dir/simple_game.c.obj"
	C:\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\QLearning.dir\simple_game.c.obj -c C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning\simple_game.c

CMakeFiles/QLearning.dir/simple_game.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/QLearning.dir/simple_game.c.i"
	C:\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning\simple_game.c > CMakeFiles\QLearning.dir\simple_game.c.i

CMakeFiles/QLearning.dir/simple_game.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/QLearning.dir/simple_game.c.s"
	C:\MinGW64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning\simple_game.c -o CMakeFiles\QLearning.dir\simple_game.c.s

# Object files for target QLearning
QLearning_OBJECTS = \
"CMakeFiles/QLearning.dir/main.c.obj" \
"CMakeFiles/QLearning.dir/qtable.c.obj" \
"CMakeFiles/QLearning.dir/miscellaneous.c.obj" \
"CMakeFiles/QLearning.dir/simple_game.c.obj"

# External object files for target QLearning
QLearning_EXTERNAL_OBJECTS =

QLearning.exe: CMakeFiles/QLearning.dir/main.c.obj
QLearning.exe: CMakeFiles/QLearning.dir/qtable.c.obj
QLearning.exe: CMakeFiles/QLearning.dir/miscellaneous.c.obj
QLearning.exe: CMakeFiles/QLearning.dir/simple_game.c.obj
QLearning.exe: CMakeFiles/QLearning.dir/build.make
QLearning.exe: CMakeFiles/QLearning.dir/linklibs.rsp
QLearning.exe: CMakeFiles/QLearning.dir/objects1.rsp
QLearning.exe: CMakeFiles/QLearning.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable QLearning.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\QLearning.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/QLearning.dir/build: QLearning.exe
.PHONY : CMakeFiles/QLearning.dir/build

CMakeFiles/QLearning.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\QLearning.dir\cmake_clean.cmake
.PHONY : CMakeFiles/QLearning.dir/clean

CMakeFiles/QLearning.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning\cmake-build-debug C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning\cmake-build-debug C:\Users\giaco\Desktop\CSprojects\C_Projects\QLearning\cmake-build-debug\CMakeFiles\QLearning.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/QLearning.dir/depend

