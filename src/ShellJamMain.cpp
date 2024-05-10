#include "shelljam/SpotifyAPI.hpp"
#include "shelljam/ProjectPath.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv) {

    // Reads the access token from ${PROJECT}/api/token.txt
    std::string filePath{PROJECTPATH "/api/token.txt"};
    std::ifstream tokenFile(filePath);
    if (!tokenFile.is_open()) {
        std::cerr << "Failed to open token.txt\n";
        return EXIT_FAILURE;
    }

    // Passes the token value to the Spotify API
    std::string token{};
    std::getline(tokenFile, token);
    SpotifyAPI::GetInstance().setAccessToken(token);
    tokenFile.close();

    // Test the Spotify API
    SpotifyAPI::GetInstance().skipToNext();

    return EXIT_SUCCESS;
}