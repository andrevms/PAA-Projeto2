cmake_minimum_required(VERSION 3.10)

# set the project name
project(PAA-PROJETO2 VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(
    PAA-Projeto2
    utils/container.cpp utils/container.hpp
    algorithms/shortestPath.cpp algorithms/shortestPath.hpp
    algorithms/backtraking.cpp algorithms/backtraking.hpp
    algorithms/grasp.cpp algorithms/grasp.hpp

    testCases/shortestPathTest.cpp testCases/shortestPathTest.hpp
    main.cpp
)

target_include_directories(
    PAA-Projeto2
    PRIVATE utils/ algorithms/ testCases/
    )