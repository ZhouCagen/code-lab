cmake_minimum_required(VERSION 3.20)

project(coreLog LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_library(coreLog
    src/LogLevel.cpp
)

target_include_directories(coreLog
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

add_executable(coreLogTest
    test/main.cpp
)

target_link_libraries(coreLogTest
    PRIVATE
        coreLog
)
