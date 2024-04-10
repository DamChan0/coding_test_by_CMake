# 목적

하나의 폴더에서 여러가지 파일 혹은 폴더를 선택적으로 빌드해서 테스트 해볼 수 있는 시스템을 만들고 싶어서 만들었습니다. 
  ### 환경
  ubuntu 22.04, gcc > 9.0

# 사용법
폴더를 추가하고 싶으면 폴더 추가하시고 해당 폴더의 CMakeLists.txt를 다음과 같이 구성하시면됩니다. 
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
