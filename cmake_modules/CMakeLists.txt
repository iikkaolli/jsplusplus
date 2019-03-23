cmake_minimum_required(VERSION 3.6)

set(3RD_PARTY_DIR ${PROJECT_SOURCE_DIR}/3rdparty)
set(CATCH_INCLUDE_DIR ${3RD_PARTY_DIR}/Catch2/single_include
    CACHE INTERNAL "Path to include folder for Catch")

add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CATCH_INCLUDE_DIR})

