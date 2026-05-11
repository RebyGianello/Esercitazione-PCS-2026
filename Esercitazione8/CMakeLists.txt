cmake_minimum_required(VERSION 3.20)
project(esercitazione8)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(grafi Main.cpp)

add_executable(testgrafi graphtest.cpp)
add_test(NAME grafitest COMMAND testgrafi)
enable_testing()