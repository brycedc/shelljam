set(INCLUDE_SHELLJAM ${INCLUDE_DIR}/shelljam)
set(INCLUDE_BUILD_DIR ${CMAKE_BINARY_DIR}/include)

# Sets all the src files to be included
set(SOURCES
    SpotifyAPI.cpp 
    CurlUtil.cpp 
)

set(HEADERS
    ${INCLUDE_SHELLJAM}/CurlUtil.hpp
    ${INCLUDE_SHELLJAM}/SpotifyAPI.hpp
    ${INCLUDE_BUILD_DIR}/shelljam/ProjectPath.hpp
)

# Creates ShellJam Library
add_library(ShellJam ${SOURCES} ${HEADERS})
target_include_directories(ShellJam PUBLIC 
    ${INCLUDE_DIR}/ 
    ${CURL_INCLUDE_DIR}
    ${INCLUDE_BUILD_DIR}/
)
target_link_libraries(ShellJam ${CURL_LIBRARIES})

# Creates exectuable
add_executable(ShellJamExe ShellJamMain.cpp)
target_link_libraries(ShellJamExe ShellJam)