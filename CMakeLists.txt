cmake_minimum_required(VERSION 3.28)
project(OptimalBinarySearchTree LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

file(GLOB SRC_FILES 
    source/*.cpp
)

file(GLOB HEADER_FILES 
    include/*.hpp
)

add_executable(main ${SRC_FILES} ${HEADER_FILES})

target_include_directories(main PRIVATE ${CMAKE_SOURCE_DIR}/include)
