cmake_minimum_required(VERSION 3.0)
project(Solution)

# Set C and C++ compiler options
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Locate necessary libraries

# Add executable target
# 언어를 설정합니다.
set(dfs 0) # build dfs dir
set(bfs 0) # build bfs dir
set(etc 1) # build bfs dir
set(greedy 0) # build bfs dir

# Add subdirectory for dfs
if(dfs)
add_subdirectory(dfs)
elseif((bfs))
add_subdirectory(bfs)
elseif((etc))
add_subdirectory(etc)
elseif((greedy))
add_subdirectory(greedy)
endif()
