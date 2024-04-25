#ifndef SPOTIFY_API_HPP
#define SPOTIFY_API_HPP

#include <string>
#include <curl/curl.h>

class SpotifyAPI {
    public:
        SpotifyAPI();
        ~SpotifyAPI() = default;

    private:
        std::string m_clientID;
        std::string m_clientSecret;
};

#endif