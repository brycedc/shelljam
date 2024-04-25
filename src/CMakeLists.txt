# Sets all the src files to be included
set(SRC ShellJamMain.cpp)

add_executable(ShellJam ${SRC})

# Include headers and libraries
include_directories(${CURL_INCLUDE_DIR})
target_link_libraries(ShellJam ${CURL_LIBRARIES})