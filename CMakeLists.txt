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
set(CPP 0) # C++ 사용
set(C 0) # C 사용

# C++ 코드를 빌드합니다.
if(CPP)
    add_executable(solution bfs.cpp)

# C 코드를 빌드합니다.
elseif(C)
    add_executable(solution test.c)
endif()

# Enable compiler warnings as errors

# Add subdirectory for dfs
add_subdirectory(dfs)
