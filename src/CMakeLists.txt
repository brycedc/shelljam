# Sets all the src files to be included
add_executable(ShellJam ShellJamMain.cpp SpotifyAPI.cpp)

# Include headers and libraries
target_include_directories(ShellJam PRIVATE ${SHELLJAM_INCLUDE_DIR} ${CURL_INCLUDE_DIR})
target_link_libraries(ShellJam ${CURL_LIBRARIES})