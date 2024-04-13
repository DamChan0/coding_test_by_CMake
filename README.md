# 목적

하나의 폴더에서 여러가지 파일 혹은 폴더를 선택적으로 빌드해서 테스트 해볼 수 있는 시스템을 만들고 싶어서 만들었습니다. 
  ### 환경
  ubuntu 22.04, gcc > 9.0

# 사용법
1. 폴더를 추가하고 싶으면 폴더 추가하시고 해당 폴더의 CMakeLists.txt를 다음과 같이 구성하시면됩니다. 
```cmake
# CMakeLists.txt in dfs directory
set(CMAKE_BUILD_TYPE Debug)

# Set the source files for the dfs target
set(${PROJECT NAME}
    targetNumber.cpp
)

# Add executable target for dfs in build directory
add_executable(solution ${PROJECT NAME})
set_target_properties(solution PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}../../)
```
맨 아래줄 추가하셔야 build 파일에 실행파일 만들어지고 그래야 launch.json으로 디버깅할 수 있습니다

2. Root CMakeLists.txt 수정 </br>
    add_subdirectory()에 폴더 이름을 추가하고 원하는 것만 빌드 할 수 있돌고 set 함수로 변수 선언과 초기화해서 사용하시면 됩니다.
```cmake
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
set(etc 0) # build bfs dir
set(greedy 0) # build bfs dir
set(dp 1) # build bfs dir

# Add subdirectory for dfs
if(dfs)
add_subdirectory(dfs)
elseif((bfs))
add_subdirectory(bfs)
elseif((etc))
add_subdirectory(etc)
elseif((greedy))
add_subdirectory(greedy)
elseif((dp))
add_subdirectory(dp)
endif()
...
..
..
#폴더 생성 할때 마다 계속 추가 카테고리가 없는 것들은 폴더 추가하지 않고 etc 폴더에 넣어서 계속 사용해도 무방함

```
