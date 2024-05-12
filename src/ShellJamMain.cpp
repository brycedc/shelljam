#include "shelljam/ProjectPath.hpp"
#include "shelljam/SpotifyAPI.hpp"
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>

int main(int argc, char **argv) {

    SpotifyAPI spotifyAPI;

    // Reads the access token from ${PROJECT}/api/token.txt
    {
        std::string filePath{PROJECTPATH "/api/token.txt"};
        std::ifstream tokenFile(filePath);
        if (!tokenFile.is_open()) {
            std::cerr << "Failed to open token.txt\n";
            return EXIT_FAILURE;
        }

        // Passes the token value to the Spotify API
        std::string token{};
        std::getline(tokenFile, token);
        spotifyAPI.setAccessToken(token);
        tokenFile.close();
    }
    // Reads the client id from ${PROJECT}/api/clientId.txt
    {
        std::string filePath{PROJECTPATH "/api/clientId.txt"};
        std::ifstream clientIdFile(filePath);
        if (!clientIdFile.is_open()) {
            std::cerr << "Failed to open clientId.txt\n";
            return EXIT_FAILURE;
        }

        // Passes the token value to the Spotify API
        std::string clientId{};
        std::getline(clientIdFile, clientId);
        spotifyAPI.setClientId(clientId);
        clientIdFile.close();
    }

    {
        // Reads the clientid and saves it into the Spotify API
        std::string filePath{PROJECTPATH "/api/clientSecert.txt"};
        std::ifstream clientSecertFile(filePath);
        if (!clientSecertFile.is_open()) {
            std::cerr << "Failed to open clientSecert.txt\n";
            return EXIT_FAILURE;
        }

        // Passes the token value to the Spotify API
        std::string clientSecert{};
        std::getline(clientSecertFile, clientSecert);
        spotifyAPI.setClientSecert(clientSecert);
        clientSecertFile.close();
    }

    // Grabs an access token
    spotifyAPI.requestUserAuthorization();

    return EXIT_SUCCESS;
}