# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/po524/Documents/haloscope/V2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/po524/Documents/haloscope/V2/build

# Include any dependencies generated for this target.
include CMakeFiles/haloscopeSim.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/haloscopeSim.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/haloscopeSim.dir/flags.make

CMakeFiles/haloscopeSim.dir/V2.cc.o: CMakeFiles/haloscopeSim.dir/flags.make
CMakeFiles/haloscopeSim.dir/V2.cc.o: ../V2.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/po524/Documents/haloscope/V2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/haloscopeSim.dir/V2.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/haloscopeSim.dir/V2.cc.o -c /home/po524/Documents/haloscope/V2/V2.cc

CMakeFiles/haloscopeSim.dir/V2.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/haloscopeSim.dir/V2.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/po524/Documents/haloscope/V2/V2.cc > CMakeFiles/haloscopeSim.dir/V2.cc.i

CMakeFiles/haloscopeSim.dir/V2.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/haloscopeSim.dir/V2.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/po524/Documents/haloscope/V2/V2.cc -o CMakeFiles/haloscopeSim.dir/V2.cc.s

CMakeFiles/haloscopeSim.dir/src/ActionInitialization.cc.o: CMakeFiles/haloscopeSim.dir/flags.make
CMakeFiles/haloscopeSim.dir/src/ActionInitialization.cc.o: ../src/ActionInitialization.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/po524/Documents/haloscope/V2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/haloscopeSim.dir/src/ActionInitialization.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/haloscopeSim.dir/src/ActionInitialization.cc.o -c /home/po524/Documents/haloscope/V2/src/ActionInitialization.cc

CMakeFiles/haloscopeSim.dir/src/ActionInitialization.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/haloscopeSim.dir/src/ActionInitialization.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/po524/Documents/haloscope/V2/src/ActionInitialization.cc > CMakeFiles/haloscopeSim.dir/src/ActionInitialization.cc.i

CMakeFiles/haloscopeSim.dir/src/ActionInitialization.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/haloscopeSim.dir/src/ActionInitialization.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/po524/Documents/haloscope/V2/src/ActionInitialization.cc -o CMakeFiles/haloscopeSim.dir/src/ActionInitialization.cc.s

CMakeFiles/haloscopeSim.dir/src/DetectorConstruction.cc.o: CMakeFiles/haloscopeSim.dir/flags.make
CMakeFiles/haloscopeSim.dir/src/DetectorConstruction.cc.o: ../src/DetectorConstruction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/po524/Documents/haloscope/V2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/haloscopeSim.dir/src/DetectorConstruction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/haloscopeSim.dir/src/DetectorConstruction.cc.o -c /home/po524/Documents/haloscope/V2/src/DetectorConstruction.cc

CMakeFiles/haloscopeSim.dir/src/DetectorConstruction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/haloscopeSim.dir/src/DetectorConstruction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/po524/Documents/haloscope/V2/src/DetectorConstruction.cc > CMakeFiles/haloscopeSim.dir/src/DetectorConstruction.cc.i

CMakeFiles/haloscopeSim.dir/src/DetectorConstruction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/haloscopeSim.dir/src/DetectorConstruction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/po524/Documents/haloscope/V2/src/DetectorConstruction.cc -o CMakeFiles/haloscopeSim.dir/src/DetectorConstruction.cc.s

CMakeFiles/haloscopeSim.dir/src/EventAction.cc.o: CMakeFiles/haloscopeSim.dir/flags.make
CMakeFiles/haloscopeSim.dir/src/EventAction.cc.o: ../src/EventAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/po524/Documents/haloscope/V2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/haloscopeSim.dir/src/EventAction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/haloscopeSim.dir/src/EventAction.cc.o -c /home/po524/Documents/haloscope/V2/src/EventAction.cc

CMakeFiles/haloscopeSim.dir/src/EventAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/haloscopeSim.dir/src/EventAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/po524/Documents/haloscope/V2/src/EventAction.cc > CMakeFiles/haloscopeSim.dir/src/EventAction.cc.i

CMakeFiles/haloscopeSim.dir/src/EventAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/haloscopeSim.dir/src/EventAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/po524/Documents/haloscope/V2/src/EventAction.cc -o CMakeFiles/haloscopeSim.dir/src/EventAction.cc.s

CMakeFiles/haloscopeSim.dir/src/Hit.cc.o: CMakeFiles/haloscopeSim.dir/flags.make
CMakeFiles/haloscopeSim.dir/src/Hit.cc.o: ../src/Hit.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/po524/Documents/haloscope/V2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/haloscopeSim.dir/src/Hit.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/haloscopeSim.dir/src/Hit.cc.o -c /home/po524/Documents/haloscope/V2/src/Hit.cc

CMakeFiles/haloscopeSim.dir/src/Hit.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/haloscopeSim.dir/src/Hit.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/po524/Documents/haloscope/V2/src/Hit.cc > CMakeFiles/haloscopeSim.dir/src/Hit.cc.i

CMakeFiles/haloscopeSim.dir/src/Hit.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/haloscopeSim.dir/src/Hit.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/po524/Documents/haloscope/V2/src/Hit.cc -o CMakeFiles/haloscopeSim.dir/src/Hit.cc.s

CMakeFiles/haloscopeSim.dir/src/PrimaryGeneratorAction.cc.o: CMakeFiles/haloscopeSim.dir/flags.make
CMakeFiles/haloscopeSim.dir/src/PrimaryGeneratorAction.cc.o: ../src/PrimaryGeneratorAction.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/po524/Documents/haloscope/V2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/haloscopeSim.dir/src/PrimaryGeneratorAction.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/haloscopeSim.dir/src/PrimaryGeneratorAction.cc.o -c /home/po524/Documents/haloscope/V2/src/PrimaryGeneratorAction.cc

CMakeFiles/haloscopeSim.dir/src/PrimaryGeneratorAction.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/haloscopeSim.dir/src/PrimaryGeneratorAction.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/po524/Documents/haloscope/V2/src/PrimaryGeneratorAction.cc > CMakeFiles/haloscopeSim.dir/src/PrimaryGeneratorAction.cc.i

CMakeFiles/haloscopeSim.dir/src/PrimaryGeneratorAction.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/haloscopeSim.dir/src/PrimaryGeneratorAction.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/po524/Documents/haloscope/V2/src/PrimaryGeneratorAction.cc -o CMakeFiles/haloscopeSim.dir/src/PrimaryGeneratorAction.cc.s

CMakeFiles/haloscopeSim.dir/src/SD.cc.o: CMakeFiles/haloscopeSim.dir/flags.make
CMakeFiles/haloscopeSim.dir/src/SD.cc.o: ../src/SD.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/po524/Documents/haloscope/V2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/haloscopeSim.dir/src/SD.cc.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/haloscopeSim.dir/src/SD.cc.o -c /home/po524/Documents/haloscope/V2/src/SD.cc

CMakeFiles/haloscopeSim.dir/src/SD.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/haloscopeSim.dir/src/SD.cc.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/po524/Documents/haloscope/V2/src/SD.cc > CMakeFiles/haloscopeSim.dir/src/SD.cc.i

CMakeFiles/haloscopeSim.dir/src/SD.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/haloscopeSim.dir/src/SD.cc.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/po524/Documents/haloscope/V2/src/SD.cc -o CMakeFiles/haloscopeSim.dir/src/SD.cc.s

# Object files for target haloscopeSim
haloscopeSim_OBJECTS = \
"CMakeFiles/haloscopeSim.dir/V2.cc.o" \
"CMakeFiles/haloscopeSim.dir/src/ActionInitialization.cc.o" \
"CMakeFiles/haloscopeSim.dir/src/DetectorConstruction.cc.o" \
"CMakeFiles/haloscopeSim.dir/src/EventAction.cc.o" \
"CMakeFiles/haloscopeSim.dir/src/Hit.cc.o" \
"CMakeFiles/haloscopeSim.dir/src/PrimaryGeneratorAction.cc.o" \
"CMakeFiles/haloscopeSim.dir/src/SD.cc.o"

# External object files for target haloscopeSim
haloscopeSim_EXTERNAL_OBJECTS =

haloscopeSim: CMakeFiles/haloscopeSim.dir/V2.cc.o
haloscopeSim: CMakeFiles/haloscopeSim.dir/src/ActionInitialization.cc.o
haloscopeSim: CMakeFiles/haloscopeSim.dir/src/DetectorConstruction.cc.o
haloscopeSim: CMakeFiles/haloscopeSim.dir/src/EventAction.cc.o
haloscopeSim: CMakeFiles/haloscopeSim.dir/src/Hit.cc.o
haloscopeSim: CMakeFiles/haloscopeSim.dir/src/PrimaryGeneratorAction.cc.o
haloscopeSim: CMakeFiles/haloscopeSim.dir/src/SD.cc.o
haloscopeSim: CMakeFiles/haloscopeSim.dir/build.make
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4Tree.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4GMocren.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4visHepRep.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4RayTracer.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4VRML.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4OpenGL.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4gl2ps.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4interfaces.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4persistency.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4error_propagation.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4readout.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4physicslists.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4parmodels.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4FR.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4vis_management.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4modeling.so
haloscopeSim: /usr/lib/x86_64-linux-gnu/libXm.so
haloscopeSim: /usr/lib/x86_64-linux-gnu/libSM.so
haloscopeSim: /usr/lib/x86_64-linux-gnu/libICE.so
haloscopeSim: /usr/lib/x86_64-linux-gnu/libX11.so
haloscopeSim: /usr/lib/x86_64-linux-gnu/libXext.so
haloscopeSim: /usr/lib/x86_64-linux-gnu/libXt.so
haloscopeSim: /usr/lib/x86_64-linux-gnu/libXmu.so
haloscopeSim: /usr/lib/x86_64-linux-gnu/libGL.so
haloscopeSim: /usr/lib/x86_64-linux-gnu/libGLU.so
haloscopeSim: /opt/anaconda3/lib/libQt5OpenGL.so.5.9.5
haloscopeSim: /opt/anaconda3/lib/libQt5PrintSupport.so.5.9.5
haloscopeSim: /opt/anaconda3/lib/libQt5Widgets.so.5.9.5
haloscopeSim: /opt/anaconda3/lib/libQt5Gui.so.5.9.5
haloscopeSim: /opt/anaconda3/lib/libQt5Core.so.5.9.5
haloscopeSim: /usr/lib/x86_64-linux-gnu/libxerces-c.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4run.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4event.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4tracking.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4processes.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4analysis.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4zlib.so
haloscopeSim: /usr/lib/x86_64-linux-gnu/libexpat.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4digits_hits.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4track.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4particles.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4geometry.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4materials.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4graphics_reps.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4intercoms.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4global.so
haloscopeSim: /opt/geant4/geant4-10.4/lib/libG4clhep.so
haloscopeSim: CMakeFiles/haloscopeSim.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/po524/Documents/haloscope/V2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable haloscopeSim"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/haloscopeSim.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/haloscopeSim.dir/build: haloscopeSim

.PHONY : CMakeFiles/haloscopeSim.dir/build

CMakeFiles/haloscopeSim.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/haloscopeSim.dir/cmake_clean.cmake
.PHONY : CMakeFiles/haloscopeSim.dir/clean

CMakeFiles/haloscopeSim.dir/depend:
	cd /home/po524/Documents/haloscope/V2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/po524/Documents/haloscope/V2 /home/po524/Documents/haloscope/V2 /home/po524/Documents/haloscope/V2/build /home/po524/Documents/haloscope/V2/build /home/po524/Documents/haloscope/V2/build/CMakeFiles/haloscopeSim.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/haloscopeSim.dir/depend
