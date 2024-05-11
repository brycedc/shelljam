# Sets all the src files to be included
add_executable(ShellJam ShellJamMain.cpp SpotifyAPI.cpp CurlUtil.cpp)

# Include headers and libraries
target_include_directories(ShellJam PRIVATE ${INCLUDE_DIR}/shelljam ${INCLUDE_DIR}/nlohmann ${CURL_INCLUDE_DIR} ${CMAKE_CURRENT_BINARY_DIR}/include/shelljam)
target_link_libraries(ShellJam ${CURL_LIBRARIES})