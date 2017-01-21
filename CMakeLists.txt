cmake_minimum_required(VERSION 3.6)

set(PROJECT_NAME "JavaScriptPlusPlus")
set(PROJECT_VERSION 0.1.0)
project(${PROJECT_NAME} VERSION ${PROJECT_VERSION} LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)

add_subdirectory(cmake_modules)
add_subdirectory(docs)
add_subdirectory(modules)
add_subdirectory(applications)
