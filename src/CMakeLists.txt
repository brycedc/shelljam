set(INCLUDE_SHELLJAM ${INCLUDE_DIR}/shelljam)
set(INCLUDE_BUILD_DIR ${CMAKE_BINARY_DIR}/include)

# Sets all the src files to be included
set(SOURCES
    ShellJamMain.cpp 
    SpotifyAPI.cpp 
    CurlUtil.cpp 
)

set(HEADERS
    ${INCLUDE_SHELLJAM}/CurlUtil.hpp
    ${INCLUDE_SHELLJAM}/SpotifyAPI.hpp
    ${INCLUDE_BUILD_DIR}/shelljam/ProjectPath.hpp
)

add_executable(ShellJam ${SOURCES} ${HEADERS})

# Include headers and libraries
target_include_directories(ShellJam PUBLIC 
    ${INCLUDE_DIR}/ 
    ${CURL_INCLUDE_DIR}
    ${INCLUDE_BUILD_DIR}/
)

target_link_libraries(ShellJam ${CURL_LIBRARIES})