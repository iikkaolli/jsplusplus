cmake_minimum_required(VERSION 3.6)
project(JSTest)

#add_subdirectory(${EXT_PROJECTS_DIR}/catch)
#include_directories(${CATCH_INCLUDE_DIR} ${JS_PUBLIC_INCLUDE_PATH} ${COMMON_INCLUDES})

file(GLOB JSTestSources "*.cpp")
add_executable(JSTest ${JSTestSources})
target_link_libraries(JSTest Catch)
target_link_libraries(JSTest js)

enable_testing()
add_test(NAME JSTest COMMAND JSTest)
