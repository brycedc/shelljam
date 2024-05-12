# Set Headers
set(HEADERS ${INCLUDE_DIR}/shelljam/CurlUtil.hpp)

#Set sources
set(SOURCES CurlUtilTest.cpp)

# Creates test executable
add_executable(runUnitTests ${SOURCES} ${HEADERS})

# Sets up include and libraries needed by test executable
target_link_libraries(runUnitTests gtest)
target_include_directories(runUnitTests PRIVATE ${INCLUDE_DIR}/)

# Adds test to ctest
add_test(runUnitTests runUnitTests)