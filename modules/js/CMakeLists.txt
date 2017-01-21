project(js)

file(GLOB JSSources "src/*.cpp")

add_library(js ${JSSources})

set(JS_PUBLIC_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
set(JS_PRIVATE_INCLUDE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_include_directories(js
	PUBLIC $<BUILD_INTERFACE:${JS_PUBLIC_INCLUDE_PATH}>
	PRIVATE $<BUILD_INTERFACE:${JS_PRIVATE_INCLUDE_PATH}>)

add_subdirectory(test)
