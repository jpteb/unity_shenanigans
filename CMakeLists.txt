cmake_minimum_required(VERSION 3.22)

# Setup compiler settings
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS ON)


# Define the build type
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE "Debug")
endif()

# Set the project name
set(CMAKE_PROJECT_NAME rtfm_unity)

set(CMAKE_C_COMPILER_FORCED TRUE)
set(CMAKE_CXX_COMPILER_FORCED TRUE)
set(CMAKE_C_COMPILER_ID GNU)
set(CMAKE_CXX_COMPILER_ID GNU)

# Some default GCC settings
set(CMAKE_C_COMPILER gcc)
set(CMAKE_ASM_COMPILER )
set(CMAKE_CXX_COMPILER g++)
set(CMAKE_LINKER g++)
set(CMAKE_OBJCOPY objcopy)
set(CMAKE_SIZE size)

# set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}")
# set(CMAKE_C_FLAGS
#     "${CMAKE_C_FLAGS} -Wall -Wextra -Wpedantic -fdata-sections -ffunction-sections"
# )
# if(CMAKE_BUILD_TYPE MATCHES Debug)
#   set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O0 -g3")
# endif()
# if(CMAKE_BUILD_TYPE MATCHES Release)
#   set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -O3 -g0")
# endif()


# Enable compile command to ease indexing with e.g. clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS TRUE)

# Core project settings
project(${CMAKE_PROJECT_NAME})
message("Build type: " ${CMAKE_BUILD_TYPE})

# Enable CMake support for ASM and C languages
enable_language(C ASM)

# Create an executable object type
add_executable(${CMAKE_PROJECT_NAME})

set(CMAKE_TEST_EXECUTABLE "${CMAKE_PROJECT_NAME}_tests")
add_executable(${CMAKE_TEST_EXECUTABLE})

# Add project symbols (macros)
target_compile_definitions(${CMAKE_TEST_EXECUTABLE} PRIVATE
    # Add user defined symbols
    UNITY_INCLUDE_CONFIG_H
)

# Add 3rd party libraries
add_subdirectory(libs/unity)

# Add include directories
target_include_directories(${CMAKE_PROJECT_NAME} PUBLIC
    ./inc/
)

# Add source
target_sources(${CMAKE_PROJECT_NAME} PUBLIC
    ./src/main.c
    ./src/some_func.c
)


target_include_directories(${CMAKE_TEST_EXECUTABLE} PRIVATE
    ./inc/
    ./tests/
)

target_sources(${CMAKE_TEST_EXECUTABLE} PRIVATE
    ./src/some_func.c
    ./tests/some_func_tests.c
    ./tests/unity_helper.c
)

target_link_libraries(${CMAKE_TEST_EXECUTABLE}
    unity
)

