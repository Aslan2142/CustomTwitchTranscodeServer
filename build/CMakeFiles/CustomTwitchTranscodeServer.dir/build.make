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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/aslan/Development/C/QT/CustomTwitchTranscodeServer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/build

# Include any dependencies generated for this target.
include CMakeFiles/CustomTwitchTranscodeServer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/CustomTwitchTranscodeServer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/CustomTwitchTranscodeServer.dir/flags.make

CMakeFiles/CustomTwitchTranscodeServer.dir/CustomTwitchTranscodeServer_autogen/mocs_compilation.cpp.o: CMakeFiles/CustomTwitchTranscodeServer.dir/flags.make
CMakeFiles/CustomTwitchTranscodeServer.dir/CustomTwitchTranscodeServer_autogen/mocs_compilation.cpp.o: CustomTwitchTranscodeServer_autogen/mocs_compilation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aslan/Development/C/QT/CustomTwitchTranscodeServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/CustomTwitchTranscodeServer.dir/CustomTwitchTranscodeServer_autogen/mocs_compilation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CustomTwitchTranscodeServer.dir/CustomTwitchTranscodeServer_autogen/mocs_compilation.cpp.o -c /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/build/CustomTwitchTranscodeServer_autogen/mocs_compilation.cpp

CMakeFiles/CustomTwitchTranscodeServer.dir/CustomTwitchTranscodeServer_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CustomTwitchTranscodeServer.dir/CustomTwitchTranscodeServer_autogen/mocs_compilation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/build/CustomTwitchTranscodeServer_autogen/mocs_compilation.cpp > CMakeFiles/CustomTwitchTranscodeServer.dir/CustomTwitchTranscodeServer_autogen/mocs_compilation.cpp.i

CMakeFiles/CustomTwitchTranscodeServer.dir/CustomTwitchTranscodeServer_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CustomTwitchTranscodeServer.dir/CustomTwitchTranscodeServer_autogen/mocs_compilation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/build/CustomTwitchTranscodeServer_autogen/mocs_compilation.cpp -o CMakeFiles/CustomTwitchTranscodeServer.dir/CustomTwitchTranscodeServer_autogen/mocs_compilation.cpp.s

CMakeFiles/CustomTwitchTranscodeServer.dir/main.cpp.o: CMakeFiles/CustomTwitchTranscodeServer.dir/flags.make
CMakeFiles/CustomTwitchTranscodeServer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aslan/Development/C/QT/CustomTwitchTranscodeServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/CustomTwitchTranscodeServer.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CustomTwitchTranscodeServer.dir/main.cpp.o -c /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/main.cpp

CMakeFiles/CustomTwitchTranscodeServer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CustomTwitchTranscodeServer.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/main.cpp > CMakeFiles/CustomTwitchTranscodeServer.dir/main.cpp.i

CMakeFiles/CustomTwitchTranscodeServer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CustomTwitchTranscodeServer.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/main.cpp -o CMakeFiles/CustomTwitchTranscodeServer.dir/main.cpp.s

CMakeFiles/CustomTwitchTranscodeServer.dir/stream_downloader.cpp.o: CMakeFiles/CustomTwitchTranscodeServer.dir/flags.make
CMakeFiles/CustomTwitchTranscodeServer.dir/stream_downloader.cpp.o: ../stream_downloader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aslan/Development/C/QT/CustomTwitchTranscodeServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/CustomTwitchTranscodeServer.dir/stream_downloader.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CustomTwitchTranscodeServer.dir/stream_downloader.cpp.o -c /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/stream_downloader.cpp

CMakeFiles/CustomTwitchTranscodeServer.dir/stream_downloader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CustomTwitchTranscodeServer.dir/stream_downloader.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/stream_downloader.cpp > CMakeFiles/CustomTwitchTranscodeServer.dir/stream_downloader.cpp.i

CMakeFiles/CustomTwitchTranscodeServer.dir/stream_downloader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CustomTwitchTranscodeServer.dir/stream_downloader.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/stream_downloader.cpp -o CMakeFiles/CustomTwitchTranscodeServer.dir/stream_downloader.cpp.s

CMakeFiles/CustomTwitchTranscodeServer.dir/stream_server.cpp.o: CMakeFiles/CustomTwitchTranscodeServer.dir/flags.make
CMakeFiles/CustomTwitchTranscodeServer.dir/stream_server.cpp.o: ../stream_server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aslan/Development/C/QT/CustomTwitchTranscodeServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/CustomTwitchTranscodeServer.dir/stream_server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CustomTwitchTranscodeServer.dir/stream_server.cpp.o -c /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/stream_server.cpp

CMakeFiles/CustomTwitchTranscodeServer.dir/stream_server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CustomTwitchTranscodeServer.dir/stream_server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/stream_server.cpp > CMakeFiles/CustomTwitchTranscodeServer.dir/stream_server.cpp.i

CMakeFiles/CustomTwitchTranscodeServer.dir/stream_server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CustomTwitchTranscodeServer.dir/stream_server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/stream_server.cpp -o CMakeFiles/CustomTwitchTranscodeServer.dir/stream_server.cpp.s

CMakeFiles/CustomTwitchTranscodeServer.dir/client_socket.cpp.o: CMakeFiles/CustomTwitchTranscodeServer.dir/flags.make
CMakeFiles/CustomTwitchTranscodeServer.dir/client_socket.cpp.o: ../client_socket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aslan/Development/C/QT/CustomTwitchTranscodeServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/CustomTwitchTranscodeServer.dir/client_socket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CustomTwitchTranscodeServer.dir/client_socket.cpp.o -c /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/client_socket.cpp

CMakeFiles/CustomTwitchTranscodeServer.dir/client_socket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CustomTwitchTranscodeServer.dir/client_socket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/client_socket.cpp > CMakeFiles/CustomTwitchTranscodeServer.dir/client_socket.cpp.i

CMakeFiles/CustomTwitchTranscodeServer.dir/client_socket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CustomTwitchTranscodeServer.dir/client_socket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/client_socket.cpp -o CMakeFiles/CustomTwitchTranscodeServer.dir/client_socket.cpp.s

CMakeFiles/CustomTwitchTranscodeServer.dir/settings.cpp.o: CMakeFiles/CustomTwitchTranscodeServer.dir/flags.make
CMakeFiles/CustomTwitchTranscodeServer.dir/settings.cpp.o: ../settings.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/aslan/Development/C/QT/CustomTwitchTranscodeServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/CustomTwitchTranscodeServer.dir/settings.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/CustomTwitchTranscodeServer.dir/settings.cpp.o -c /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/settings.cpp

CMakeFiles/CustomTwitchTranscodeServer.dir/settings.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/CustomTwitchTranscodeServer.dir/settings.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/settings.cpp > CMakeFiles/CustomTwitchTranscodeServer.dir/settings.cpp.i

CMakeFiles/CustomTwitchTranscodeServer.dir/settings.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/CustomTwitchTranscodeServer.dir/settings.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/settings.cpp -o CMakeFiles/CustomTwitchTranscodeServer.dir/settings.cpp.s

# Object files for target CustomTwitchTranscodeServer
CustomTwitchTranscodeServer_OBJECTS = \
"CMakeFiles/CustomTwitchTranscodeServer.dir/CustomTwitchTranscodeServer_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/CustomTwitchTranscodeServer.dir/main.cpp.o" \
"CMakeFiles/CustomTwitchTranscodeServer.dir/stream_downloader.cpp.o" \
"CMakeFiles/CustomTwitchTranscodeServer.dir/stream_server.cpp.o" \
"CMakeFiles/CustomTwitchTranscodeServer.dir/client_socket.cpp.o" \
"CMakeFiles/CustomTwitchTranscodeServer.dir/settings.cpp.o"

# External object files for target CustomTwitchTranscodeServer
CustomTwitchTranscodeServer_EXTERNAL_OBJECTS =

CustomTwitchTranscodeServer: CMakeFiles/CustomTwitchTranscodeServer.dir/CustomTwitchTranscodeServer_autogen/mocs_compilation.cpp.o
CustomTwitchTranscodeServer: CMakeFiles/CustomTwitchTranscodeServer.dir/main.cpp.o
CustomTwitchTranscodeServer: CMakeFiles/CustomTwitchTranscodeServer.dir/stream_downloader.cpp.o
CustomTwitchTranscodeServer: CMakeFiles/CustomTwitchTranscodeServer.dir/stream_server.cpp.o
CustomTwitchTranscodeServer: CMakeFiles/CustomTwitchTranscodeServer.dir/client_socket.cpp.o
CustomTwitchTranscodeServer: CMakeFiles/CustomTwitchTranscodeServer.dir/settings.cpp.o
CustomTwitchTranscodeServer: CMakeFiles/CustomTwitchTranscodeServer.dir/build.make
CustomTwitchTranscodeServer: /usr/lib/libQt5Network.so.5.15.0
CustomTwitchTranscodeServer: /usr/lib/libQt5Core.so.5.15.0
CustomTwitchTranscodeServer: CMakeFiles/CustomTwitchTranscodeServer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/aslan/Development/C/QT/CustomTwitchTranscodeServer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable CustomTwitchTranscodeServer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/CustomTwitchTranscodeServer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/CustomTwitchTranscodeServer.dir/build: CustomTwitchTranscodeServer

.PHONY : CMakeFiles/CustomTwitchTranscodeServer.dir/build

CMakeFiles/CustomTwitchTranscodeServer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/CustomTwitchTranscodeServer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/CustomTwitchTranscodeServer.dir/clean

CMakeFiles/CustomTwitchTranscodeServer.dir/depend:
	cd /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/aslan/Development/C/QT/CustomTwitchTranscodeServer /home/aslan/Development/C/QT/CustomTwitchTranscodeServer /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/build /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/build /home/aslan/Development/C/QT/CustomTwitchTranscodeServer/build/CMakeFiles/CustomTwitchTranscodeServer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/CustomTwitchTranscodeServer.dir/depend

