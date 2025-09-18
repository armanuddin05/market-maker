cmake_minimum_required(VERSION 3.14)
project(market-maker)

set(CMAKE_CXX_STANDARD 17)

# Just build everything
file(GLOB_RECURSE SOURCES "source/*.cpp")
add_executable(MarketMaker ${SOURCES})

# Simple include
target_include_directories(MarketMaker PRIVATE include)

# Done. No fancy stuff.
