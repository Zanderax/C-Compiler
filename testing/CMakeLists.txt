cmake_minimum_required(VERSION 2.6)

set(CMAKE_CXX_STANDARD 11)

# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS},)

set( files
	../src/logger.cpp
	../src/file.cpp
	../src/lexer.cpp
	../src/parser.cpp
)

# Link runTests with our tests
add_executable( runTests.out tests.cpp ${files} )
target_link_libraries(runTests.out ${GTEST_LIBRARIES} pthread)
