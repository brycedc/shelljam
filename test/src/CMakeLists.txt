# Set Headers
set(HEADERS)

#Set sources
set(SOURCES CurlUtilTest.cpp SpotifyAPITest.cpp)

# Moves the test executable to the test/src directory so make test works
SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/test/src")

# Creates test executable
add_executable(runUnitTests ${SOURCES} ${HEADERS})
# Sets up include and libraries needed by test executable
target_link_libraries(runUnitTests GTest::Main ShellJam)

# Adds test to ctest
add_test(runUnitTests runUnitTests)