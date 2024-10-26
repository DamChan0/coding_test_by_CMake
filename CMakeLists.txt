cmake_minimum_required(VERSION 3.5)
project(Solution)
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_C_FLAGS_DEBUG "-g")

# Set C and C++ compiler options
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 옵션들을 ON/OFF로 설정합니다.
option(BUILD_DFS "Build DFS directory" OFF)
option(BUILD_BFS "Build BFS directory" OFF)
option(BUILD_ETC "Build ETC directory" OFF)
option(BUILD_GREEDY "Build Greedy directory" OFF)
option(BUILD_HASH "Build Hash directory" OFF)
option(BUILD_DP "Build DP directory" OFF)
option(BUILD_IMPLEMENTATION "Build Implementation directory" ON)

# Add subdirectories based on the options
if(BUILD_DFS)
    add_subdirectory(dfs)
endif()

if(BUILD_BFS)
    add_subdirectory(bfs)
endif()

if(BUILD_ETC)
    add_subdirectory(etc)
endif()

if(BUILD_GREEDY)
    add_subdirectory(greedy)
endif()

if(BUILD_HASH)
    add_subdirectory(hash) # typo corrected from 'hesh' to 'hash'
endif()

if(BUILD_DP)
    add_subdirectory(dp)
endif()

if(BUILD_IMPLEMENTATION)
    add_subdirectory(implementation)
endif()
