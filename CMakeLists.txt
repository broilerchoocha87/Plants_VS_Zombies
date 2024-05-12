cmake_minimum_required(VERSION 3.16)  # Adjust minimum version if needed
project(oop)  # Update project name

# Define source file locations (assuming all .cpp files are in src/)
set(SOURCE_FILES
  main.cpp
  Sun.cpp
  Game.cpp
  GameGrid.cpp
  levels.cpp
  bullets.cpp
  PlantFactory.cpp
  ZombieFactory.cpp
  Zombie.cpp
  Plants.cpp
  
)

# Create the executable
add_executable(oop ${SOURCE_FILES})  # Update executable name

# Link with SFML libraries (assuming they're downloaded using FetchContent)
target_link_libraries(oop PRIVATE sfml-graphics sfml-window sfml-system)

# Optional: Enable C++17 features (adjust as needed)
target_compile_features(oop PRIVATE cxx_std_17)

if(WIN32)
  # Optional: Copy OpenAL DLL (if using FetchContent)
  add_custom_command(
    TARGET oop
    COMMENT "Copy OpenAL DLL"
    PRE_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${SFML_SOURCE_DIR}/extlibs/bin/$<IF:$<EQUAL:${CMAKE_SIZEOF_VOID_P},8>,x64,x86>/openal32.dll $<TARGET_FILE_DIR:oop>
    VERBATIM)
endif()

install(TARGETS oop)  # Update target name for installation

