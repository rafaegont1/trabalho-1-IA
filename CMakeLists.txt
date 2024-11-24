# Set the cmake minimum version
cmake_minimum_required(VERSION 3.5)

# Define the project name
project(uninformed_search)

# Generate symbols for IDE indexer
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Default to C11
set(CMAKE_C_STANDARD 11)

# Include headers from the 'include' directory
include_directories(${CMAKE_SOURCE_DIR}/include)

# Create DFS executable
add_executable(dfs
    src/main.c
    src/util.c
    src/matrix.c
    src/data_struct/stack.c
)
target_compile_definitions(dfs PRIVATE DFS)

# Create BFS executable
add_executable(bfs
    src/main.c
    src/util.c
    src/matrix.c
    src/data_struct/queue.c
)
target_compile_definitions(bfs PRIVATE BFS)

# Add compilation flags (apply to both executables)
target_compile_options(dfs PRIVATE -Wall -Wextra)
target_compile_options(bfs PRIVATE -Wall -Wextra)

# If you want to ensure that the executables are built in debug/release mode
# you can add build type specific options:
# if(CMAKE_BUILD_TYPE STREQUAL "Debug")
#     target_compile_options(dfs PRIVATE -g)
#     target_compile_options(bfs PRIVATE -g)
# endif()
