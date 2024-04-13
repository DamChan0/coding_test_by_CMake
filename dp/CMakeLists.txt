set(CMAKE_BUILD_TYPE Debug)

# Set the source files for the dfs target
set(dp
N.cpp)

# Add executable target for dfs in build directory
add_executable(solution ${dp})
set_target_properties(solution PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}../../)