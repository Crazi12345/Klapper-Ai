# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tired_atlas/Desktop/Klapper-Ai/build-klapperBuild-Desktop-Debug

# Include any dependencies generated for this target.
include CMakeFiles/KlapperNetwork.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/KlapperNetwork.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/KlapperNetwork.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/KlapperNetwork.dir/flags.make

CMakeFiles/KlapperNetwork.dir/main.cpp.o: CMakeFiles/KlapperNetwork.dir/flags.make
CMakeFiles/KlapperNetwork.dir/main.cpp.o: /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/main.cpp
CMakeFiles/KlapperNetwork.dir/main.cpp.o: CMakeFiles/KlapperNetwork.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tired_atlas/Desktop/Klapper-Ai/build-klapperBuild-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/KlapperNetwork.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/KlapperNetwork.dir/main.cpp.o -MF CMakeFiles/KlapperNetwork.dir/main.cpp.o.d -o CMakeFiles/KlapperNetwork.dir/main.cpp.o -c /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/main.cpp

CMakeFiles/KlapperNetwork.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KlapperNetwork.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/main.cpp > CMakeFiles/KlapperNetwork.dir/main.cpp.i

CMakeFiles/KlapperNetwork.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KlapperNetwork.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/main.cpp -o CMakeFiles/KlapperNetwork.dir/main.cpp.s

CMakeFiles/KlapperNetwork.dir/node.cpp.o: CMakeFiles/KlapperNetwork.dir/flags.make
CMakeFiles/KlapperNetwork.dir/node.cpp.o: /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/node.cpp
CMakeFiles/KlapperNetwork.dir/node.cpp.o: CMakeFiles/KlapperNetwork.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tired_atlas/Desktop/Klapper-Ai/build-klapperBuild-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/KlapperNetwork.dir/node.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/KlapperNetwork.dir/node.cpp.o -MF CMakeFiles/KlapperNetwork.dir/node.cpp.o.d -o CMakeFiles/KlapperNetwork.dir/node.cpp.o -c /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/node.cpp

CMakeFiles/KlapperNetwork.dir/node.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KlapperNetwork.dir/node.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/node.cpp > CMakeFiles/KlapperNetwork.dir/node.cpp.i

CMakeFiles/KlapperNetwork.dir/node.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KlapperNetwork.dir/node.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/node.cpp -o CMakeFiles/KlapperNetwork.dir/node.cpp.s

CMakeFiles/KlapperNetwork.dir/networkhandler.cpp.o: CMakeFiles/KlapperNetwork.dir/flags.make
CMakeFiles/KlapperNetwork.dir/networkhandler.cpp.o: /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/networkhandler.cpp
CMakeFiles/KlapperNetwork.dir/networkhandler.cpp.o: CMakeFiles/KlapperNetwork.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tired_atlas/Desktop/Klapper-Ai/build-klapperBuild-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/KlapperNetwork.dir/networkhandler.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/KlapperNetwork.dir/networkhandler.cpp.o -MF CMakeFiles/KlapperNetwork.dir/networkhandler.cpp.o.d -o CMakeFiles/KlapperNetwork.dir/networkhandler.cpp.o -c /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/networkhandler.cpp

CMakeFiles/KlapperNetwork.dir/networkhandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KlapperNetwork.dir/networkhandler.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/networkhandler.cpp > CMakeFiles/KlapperNetwork.dir/networkhandler.cpp.i

CMakeFiles/KlapperNetwork.dir/networkhandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KlapperNetwork.dir/networkhandler.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/networkhandler.cpp -o CMakeFiles/KlapperNetwork.dir/networkhandler.cpp.s

CMakeFiles/KlapperNetwork.dir/backpropagation.cpp.o: CMakeFiles/KlapperNetwork.dir/flags.make
CMakeFiles/KlapperNetwork.dir/backpropagation.cpp.o: /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/backpropagation.cpp
CMakeFiles/KlapperNetwork.dir/backpropagation.cpp.o: CMakeFiles/KlapperNetwork.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tired_atlas/Desktop/Klapper-Ai/build-klapperBuild-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/KlapperNetwork.dir/backpropagation.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/KlapperNetwork.dir/backpropagation.cpp.o -MF CMakeFiles/KlapperNetwork.dir/backpropagation.cpp.o.d -o CMakeFiles/KlapperNetwork.dir/backpropagation.cpp.o -c /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/backpropagation.cpp

CMakeFiles/KlapperNetwork.dir/backpropagation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KlapperNetwork.dir/backpropagation.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/backpropagation.cpp > CMakeFiles/KlapperNetwork.dir/backpropagation.cpp.i

CMakeFiles/KlapperNetwork.dir/backpropagation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KlapperNetwork.dir/backpropagation.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/backpropagation.cpp -o CMakeFiles/KlapperNetwork.dir/backpropagation.cpp.s

CMakeFiles/KlapperNetwork.dir/persistence.cpp.o: CMakeFiles/KlapperNetwork.dir/flags.make
CMakeFiles/KlapperNetwork.dir/persistence.cpp.o: /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/persistence.cpp
CMakeFiles/KlapperNetwork.dir/persistence.cpp.o: CMakeFiles/KlapperNetwork.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tired_atlas/Desktop/Klapper-Ai/build-klapperBuild-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/KlapperNetwork.dir/persistence.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/KlapperNetwork.dir/persistence.cpp.o -MF CMakeFiles/KlapperNetwork.dir/persistence.cpp.o.d -o CMakeFiles/KlapperNetwork.dir/persistence.cpp.o -c /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/persistence.cpp

CMakeFiles/KlapperNetwork.dir/persistence.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KlapperNetwork.dir/persistence.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/persistence.cpp > CMakeFiles/KlapperNetwork.dir/persistence.cpp.i

CMakeFiles/KlapperNetwork.dir/persistence.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KlapperNetwork.dir/persistence.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/persistence.cpp -o CMakeFiles/KlapperNetwork.dir/persistence.cpp.s

CMakeFiles/KlapperNetwork.dir/traininghandler.cpp.o: CMakeFiles/KlapperNetwork.dir/flags.make
CMakeFiles/KlapperNetwork.dir/traininghandler.cpp.o: /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/traininghandler.cpp
CMakeFiles/KlapperNetwork.dir/traininghandler.cpp.o: CMakeFiles/KlapperNetwork.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tired_atlas/Desktop/Klapper-Ai/build-klapperBuild-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/KlapperNetwork.dir/traininghandler.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/KlapperNetwork.dir/traininghandler.cpp.o -MF CMakeFiles/KlapperNetwork.dir/traininghandler.cpp.o.d -o CMakeFiles/KlapperNetwork.dir/traininghandler.cpp.o -c /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/traininghandler.cpp

CMakeFiles/KlapperNetwork.dir/traininghandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KlapperNetwork.dir/traininghandler.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/traininghandler.cpp > CMakeFiles/KlapperNetwork.dir/traininghandler.cpp.i

CMakeFiles/KlapperNetwork.dir/traininghandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KlapperNetwork.dir/traininghandler.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/traininghandler.cpp -o CMakeFiles/KlapperNetwork.dir/traininghandler.cpp.s

CMakeFiles/KlapperNetwork.dir/commandline.cpp.o: CMakeFiles/KlapperNetwork.dir/flags.make
CMakeFiles/KlapperNetwork.dir/commandline.cpp.o: /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/commandline.cpp
CMakeFiles/KlapperNetwork.dir/commandline.cpp.o: CMakeFiles/KlapperNetwork.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/tired_atlas/Desktop/Klapper-Ai/build-klapperBuild-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/KlapperNetwork.dir/commandline.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/KlapperNetwork.dir/commandline.cpp.o -MF CMakeFiles/KlapperNetwork.dir/commandline.cpp.o.d -o CMakeFiles/KlapperNetwork.dir/commandline.cpp.o -c /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/commandline.cpp

CMakeFiles/KlapperNetwork.dir/commandline.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KlapperNetwork.dir/commandline.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/commandline.cpp > CMakeFiles/KlapperNetwork.dir/commandline.cpp.i

CMakeFiles/KlapperNetwork.dir/commandline.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KlapperNetwork.dir/commandline.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles/commandline.cpp -o CMakeFiles/KlapperNetwork.dir/commandline.cpp.s

# Object files for target KlapperNetwork
KlapperNetwork_OBJECTS = \
"CMakeFiles/KlapperNetwork.dir/main.cpp.o" \
"CMakeFiles/KlapperNetwork.dir/node.cpp.o" \
"CMakeFiles/KlapperNetwork.dir/networkhandler.cpp.o" \
"CMakeFiles/KlapperNetwork.dir/backpropagation.cpp.o" \
"CMakeFiles/KlapperNetwork.dir/persistence.cpp.o" \
"CMakeFiles/KlapperNetwork.dir/traininghandler.cpp.o" \
"CMakeFiles/KlapperNetwork.dir/commandline.cpp.o"

# External object files for target KlapperNetwork
KlapperNetwork_EXTERNAL_OBJECTS =

KlapperNetwork: CMakeFiles/KlapperNetwork.dir/main.cpp.o
KlapperNetwork: CMakeFiles/KlapperNetwork.dir/node.cpp.o
KlapperNetwork: CMakeFiles/KlapperNetwork.dir/networkhandler.cpp.o
KlapperNetwork: CMakeFiles/KlapperNetwork.dir/backpropagation.cpp.o
KlapperNetwork: CMakeFiles/KlapperNetwork.dir/persistence.cpp.o
KlapperNetwork: CMakeFiles/KlapperNetwork.dir/traininghandler.cpp.o
KlapperNetwork: CMakeFiles/KlapperNetwork.dir/commandline.cpp.o
KlapperNetwork: CMakeFiles/KlapperNetwork.dir/build.make
KlapperNetwork: CMakeFiles/KlapperNetwork.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/tired_atlas/Desktop/Klapper-Ai/build-klapperBuild-Desktop-Debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable KlapperNetwork"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/KlapperNetwork.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/KlapperNetwork.dir/build: KlapperNetwork
.PHONY : CMakeFiles/KlapperNetwork.dir/build

CMakeFiles/KlapperNetwork.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/KlapperNetwork.dir/cmake_clean.cmake
.PHONY : CMakeFiles/KlapperNetwork.dir/clean

CMakeFiles/KlapperNetwork.dir/depend:
	cd /home/tired_atlas/Desktop/Klapper-Ai/build-klapperBuild-Desktop-Debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles /home/tired_atlas/Desktop/Klapper-Ai/KlapperFiles /home/tired_atlas/Desktop/Klapper-Ai/build-klapperBuild-Desktop-Debug /home/tired_atlas/Desktop/Klapper-Ai/build-klapperBuild-Desktop-Debug /home/tired_atlas/Desktop/Klapper-Ai/build-klapperBuild-Desktop-Debug/CMakeFiles/KlapperNetwork.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/KlapperNetwork.dir/depend
